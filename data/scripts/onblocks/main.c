#import "data/scripts/animation/main_spawns.c"
#include "data/scripts/assets.h"

void screenBouncing()
{//Simulate hitscreen effect when thrown or being hit by certain attacks (ALL THROWS/SLAMS AND BOWLING SKILLS, BARBON/ADAM)

	if(getglobalvar("screenEdge") == "all_types" || getglobalvar("screenEdge") == "lock+bouncing"){
		void self 	 = getlocalvar("self");
		void ani  	 = getentityproperty(self, "animationID");
		int limit	 = 20;
		float height = getentityproperty(self, "y");
		float xDir	 = getentityproperty(self, "xdir");
		void subType	= getentityproperty(self,"subtype");

		if(ani == openborconstant("ANI_FALL")){
			if(height >= limit && xDir > 2){
				spawn01("Flash", 0, 50, 0);
				spawn01("QuakeLow", 0, 0, 0);
				playsample(SAMPLE_STRONGPUNCH, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				tossentity(self, 2, -xDir/2, 0);
			}
		}


		if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9") || ani == openborconstant("ANI_BURN") || ani == openborconstant("ANI_SHOCK")){
			if(height >= limit){
				spawn01("Flash", 0, 50, 0);
				spawn01("QuakeLow", 0, 0, 0);
				playsample(SAMPLE_STRONGPUNCH, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				tossentity(self, 2, -xDir/2, 0);
			}
		}
	}
}

void screenJumping()
{//Make characters jump in the screen edge

	if(getglobalvar("screenEdge") == "all_types" || getglobalvar("screenEdge") == "jumping_only"){
		void self 	 = getlocalvar("self");
		void ani  	 = getentityproperty(self, "animationID");
		int iPIndex	 = getentityproperty(self, "playerindex");
		int x 		 = getentityproperty(self, "x");
		int z 		 = getentityproperty(self, "z");
		float pause	 = 30;
		float mult	 = 2;

		if(ani == openborconstant("ANI_JUMP")
		|| ani == openborconstant("ANI_RUNJUMP")
		|| ani == openborconstant("ANI_JUMPFORWARD")
		|| ani == openborconstant("ANI_FORWARDJUMP")){
			void rName 	 = getentityproperty(self, "defaultname");
			float jBase	 = getglobalvar("jBase");
			float jDif	 = getglobalvar("jDif");
			float jDifX  = getglobalvar("jDifX"); //USED TO CALCULATE THE CORRECT VALUE FOR JUMP SPEED IN X/Z AXIS
			float ju 	 = getglobalvar(rName+"Jump");
			float xVel;
			float yVel;

			ju 	 = jBase+(jDif*ju); //TRANSLATE JUMP VALUE
			yVel = ju;

			if(playerkeys(iPIndex, 0, "moveleft")){
				changeentityproperty(self, "direction", 0);
				xVel = -(ju-jDifX);
			}
			else
			if(playerkeys(iPIndex, 0, "moveright")){
				changeentityproperty(self, "direction", 1);
				xVel = (ju-jDifX);
			}
			else
			{
				xVel = 0;
			}

			if(playerkeys(iPIndex, 0, "moveup")){
				mult = 1;
			}

			if(playerkeys(iPIndex, 1, "jump")){
				playsample(SAMPLE_JUMPLAND, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				changeentityproperty(self, "animation", openborconstant("ANI_WALKOFF"));
				changeentityproperty(self, "aiflag", "frozen", 1);
				changeentityproperty(self, "freezetime", openborvariant("elapsed_time")+pause);
				tossentity(self, yVel, xVel*mult, 0);
			}
		}
	}
}

void edgeUnlock()
{//Unlock the screen edge (for enemies) according to defined animations, like SOR4

	if(getglobalvar("screenEdge") == "all_types" || getglobalvar("screenEdge") == "lock+bouncing" || getglobalvar("screenEdge") == "lock_only"){
		if(openborvariant("current_set") != 1){ //USED TO AVOID THE SURVIVAL MODE
			void self	= getlocalvar("self");
			void vType	= getentityproperty(self,"type");

			if(vType == openborconstant("TYPE_ENEMY")){
				void sType	= getentityproperty(self,"subtype");
				int idling	= getentityproperty(self, "aiflag", "idling");
				int walking	= getentityproperty(self, "aiflag", "walking");
				int running	= getentityproperty(self, "aiflag", "running");
				int rising	= getentityproperty(self, "aiflag", "rising");
				int subS	= getentityproperty(self, "subject_to_screen");

				if(sType != openborconstant("SUBTYPE_NOTGRAB")){
					if(idling || walking || running || rising){
						if(subS != -1){changeentityproperty(self, "subject_to_screen", -1);}
					}
				}
			}
		}
	}
}
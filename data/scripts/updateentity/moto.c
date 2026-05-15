#include "data/scripts/assets.h"
#import "data/scripts/updateentity/main.c"

void main()
{
	versusDamage();
	engine();
	motorBike();
}

void engine()
{//Script for engine sound in Bike Stage (EXPERIMENTAL)
	void self	= getlocalvar("self");
	void branch	= openborvariant("current_branch");
	void vType	= getentityproperty(self, "type");
	
	if(branch == "sor3_st7d"){ //FOR SAFE, CHECK CURRENT BRANCH TO NOT RUN IN ANY OTHER LEVEL
		if(vType == openborconstant("TYPE_PLAYER")){
			int iPIndex	  = getentityproperty(self, "playerindex");
			int leader 	  = getglobalvar("leader");
			int x		  = getentityproperty(self, "x");
			int y		  = getentityproperty(self, "y");
			int z		  = getentityproperty(self, "z");
			float bgSpeed = getglobalvar("bgSpeed");
			float time    = openborvariant("elapsed_time");
		
			if(iPIndex == leader){ //THIS ENTITY IS THE LEADER??
				setglobalvar("currentLeader", "self"); //TELL TO OTHER HEROES THAT THIS ENTITY IS THE LEADER, USED BY SCRIPT "LOCKANI"
				
				//FIRST TIME LOADING THE SCRIPT?? SET VARIABLES IF NULL
				if(getlocalvar("cicle") == NULL()){
					setlocalvar("cicle", 40); //ENGINE CICLE RATE FOR PLAY ENGINE SAMPLE
					setlocalvar("rpm", 100); //VALUE TO CALCULATE SAMPLE SPEED
				}
				
				//GET AND NAME ALL VARIABLES TO EASY USE
				float cicle  = getlocalvar("cicle");
				float rpm    = getlocalvar("rpm");
				int volume   = openborvariant("effectvol"); //ENGINE SAMPLE VOLUME
					
				if(bgSpeed > 0 && bgSpeed < 4000){ //FIRST GEAR
					setlocalvar("rpm", 30);
					setlocalvar("cicle", 32);
				}
				else
				if(bgSpeed >= 4000 && bgSpeed < 9000){ //SECOND GEAR
					setlocalvar("rpm", 60);
					setlocalvar("cicle", 28);
				}
				else
				if(bgSpeed >= 9000 && bgSpeed < 15000){ //THIRD GEAR
					setlocalvar("rpm", 100);
					setlocalvar("cicle", 24);
				}
				else
				if(bgSpeed >= 15000 && bgSpeed < 23000){ //FOURTH GEAR
					setlocalvar("rpm", 160);
					setlocalvar("cicle", 20);
				}
				else
				if(bgSpeed >= 23000 && bgSpeed < 36000){ //FIFTH GEAR
					setlocalvar("rpm", 240);
					setlocalvar("cicle", 16);
				}
				else
				if(bgSpeed >= 36000){
					setlocalvar("rpm", 240);
					setlocalvar("cicle", 12);
				}
				else
				{ //IS NOT MOVING?? DEFAULT VALUES
					setlocalvar("rpm", 100); //DEFAULT RPM FOR IDLE ENGINE SOUND
					setlocalvar("cicle", 40);
				}
				
				
				if(time%cicle == 0){ //RATE TO CALCULATE ENGINE RPM AND REPEAT SAMPLE IN THE SAME RATE LIKE A REAL ENGINE
					if(bgSpeed >= 100){ //IS MOVING??
						playsample(SAMPLE_BIKERUN, 0, volume, volume, bgSpeed/rpm, 0); //MOVING ENGINE SOUND
					}
					if(bgSpeed <= 0){ //IS STOPPED??
						playsample(SAMPLE_BIKEIDLE, 0, volume, volume, 100, 0); //IDLE ENGINE SOUND
					}
				}
				
				if(playerkeys(iPIndex, 2, "special")){ //THE BIKE IS STOPPPED AND THIS IS THE FIRST ACCELERATION??
					if(bgSpeed < 10){
						void gas;
						clearspawnentry();
						setspawnentry("name", "Gas");
						setspawnentry("coords", x-40, z-y+1, y+35);
						gas = spawn();
						tossentity(gas, 1, -1, 0);
						playsample(SAMPLE_BIKEIGNITE, 0, volume, volume, 100, 0); //PLAY IGNITE SAMPLE ONE TIME ONLY!!
					}
				}
			}else{
				setglobalvar("currentLeader", "other");
			}
		}
	}
}

void motorBike()
{//Adjust bike NPC properties in Bike Stage
	void self 	= getlocalvar("self");
	void branch = openborvariant("current_branch");
	void vType	= getentityproperty(self, "type");
	void sType	= getentityproperty(self, "subtype");
	
	if(branch == "sor3_st7d"){ //FOR SAFE, CHECK CURRENT BRANCH TO NOT RUN IN ANY OTHER LEVEL
		if(vType == openborconstant("TYPE_ENEMY") || vType == openborconstant("TYPE_NPC")){
			void vType 		= getentityproperty(self, "type");
			int pain 		= getentityproperty(self, "aiflag", "inpain");
			int dead 		= getentityproperty(self, "dead");
			float x 		= getentityproperty(self, "x");
			float xPos 		= openborvariant("xpos");
			float move 		= getglobalvar("move");
			float delay 	= getglobalvar("delay");
			float bgSpeed 	= getglobalvar("bgSpeed");
			
			if(pain == 0 && dead == 0){
				if(bgSpeed <= 0){updateframe(self, 0);}
				
				changeentityproperty(self, "speed", move);
				changeentityproperty(self, "jumpspeed", move);
				changeentityproperty(self, "edelay", 0, delay, 1, 9999, 0.001, 9999);
			}
			
			if(dead == 1){
				changeentityproperty(self, "subject_to_screen", 0);
				changeentityproperty(self, "edelay", 0, 0, 1, 9999, 0.001, 9999);
				changeentityproperty(self, "velocity", -bgSpeed/5000, 0, 0);
				if(x < xPos-30){killentity(self);}
			}
		}
	}
}
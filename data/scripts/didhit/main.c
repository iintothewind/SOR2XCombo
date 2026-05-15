#import "data/scripts/main.c"

void lockMp()
{//Lock mprate with defined conditions. Used for Counter, Super and Rage animations that never fill mp
	void self 	= getlocalvar("self");
	void target	= getlocalvar("damagetaker");
	void parent = getentityproperty(self,"parent");
	void vType 	= getentityproperty(self,"type");
	void sType	= getentityproperty(self,"subtype");
	void lockMpCfg = getglobalvar("lockMp");

  if(lockMpCfg != "off") {
		//USED BY PLAYER/ENEMY
		if(parent == NULL()){
			void vAniID = getentityproperty(self,"animationID");
			void type 	= getentityproperty(target,"type");
			int disable	= getentityproperty(self,"energycost", "disable", openborconstant(vAniID));
			int blocked = getlocalvar("blocked");
			int maxMp 	= getentityproperty(self,"maxmp");
			int mp 		= getentityproperty(self,"mp");
			int mpRate 	= getentityproperty(self,"mprate")*1;

			if(disable == 6){
				if(blocked == 0){
					if(mp < maxMp){
						if(type != openborconstant("TYPE_OBSTACLE")){
							changeentityproperty(self, "mp", mp-mpRate);
						}
					}
				}
			}
		}

		//USED BY NPC PARTNER
		if(parent != NULL()){
			if(vType == openborconstant("TYPE_NPC") && sType == openborconstant("SUBTYPE_FOLLOW")){
				void vAniID = getentityproperty(self,"animationID");
				void type 	= getentityproperty(target,"type");
				int disable	= getentityproperty(self,"energycost", "disable", openborconstant(vAniID));
				int blocked = getlocalvar("blocked");
				int maxMp 	= getentityproperty(self,"maxmp");
				int mp 		= getentityproperty(self,"mp");
				int mpRate 	= getentityproperty(self,"mprate");

				if(disable == 6){
					if(blocked == 0){
						if(mp < maxMp){
							if(type != openborconstant("TYPE_OBSTACLE")){
								changeentityproperty(self, "mp", mp-mpRate);
							}
						}
					}
				}
			}
			else
			{
				//USED BY PROJECTILES
				void type 	= getentityproperty(target,"type");
				int disable	= getentityvar(self,"disable");
				int blocked = getlocalvar("blocked");
				int maxMp 	= getentityproperty(parent,"maxmp");
				int mp 		= getentityproperty(parent,"mp");
				int mpRate 	= getentityproperty(parent,"mprate");

				if(disable == 6){
					if(blocked == 0){
						if(mp < maxMp){
							if(type != openborconstant("TYPE_OBSTACLE")){
								changeentityproperty(parent, "mp", mp-mpRate);
							}
						}
					}
				}
			}
		}
	}
}


void updateJuggleOtg()
{
	void self 	= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	if(type == openborconstant("TYPE_PLAYER")){
		int index = getentityproperty(self, "playerindex");
		void target	= getlocalvar("damagetaker");

    int juggleSystem = getglobalvar("juggleSystem");
		int jug 	= getentityproperty(target, "jugglepoints");
		if(juggleSystem != "unlimited" && jug != NULL()){
			setglobalvar("tjug"+index, jug);
		}

    int otgSystem = getglobalvar("otgSystem");
		int otg	= getentityvar(target, "otgpoints");
		if(otgSystem != "unlimited" && otg != NULL()){
			setglobalvar("totg"+index, otg);
		}
	}
}

void specialCost()
{//Lock mprate according to "Special Cost" global variable. Used for Special, Special2 and Aerial Special moves
 //Free or Lock "heal by hit" feature according to "Special Cost" global variable. Used for Special, Special2 and Aerial Special moves
	void self 	  = getlocalvar("self");
	void target	  = getlocalvar("damagetaker");
	// void specialC = getglobalvar("specialCost");
	void specialC = "sor2x_energy_only";
	void parent   = getentityproperty(self,"parent");
	void vType 	  = getentityproperty(self,"type");
	void sType	  = getentityproperty(self,"subtype");
	int dmg		  = getlocalvar("damage");
	int atkType	  = getlocalvar("attacktype");

	if(specialC != "sor4_recovery_(time)" && specialC != "sor4_recovery_(hits)" && specialC != "sor2_life_only" && specialC != "sor3_'ok'_bar"){

		//USED BY PLAYER/ENEMY
		if(parent == NULL()){
			void vAniID = getentityproperty(self,"animationID");
			void eType 	= getentityproperty(target,"type");
			int disable	= getentityproperty(self,"energycost", "disable", openborconstant(vAniID));
			int blocked = getlocalvar("blocked");
			int maxMp 	= getentityproperty(self,"maxmp");
			int mp 		= getentityproperty(self,"mp");
			int mpRate 	= getentityproperty(self,"mprate");

			if(disable == 5){
				if(blocked == 0){
					if(mp < maxMp){
						if(eType != openborconstant("TYPE_OBSTACLE")){
							changeentityproperty(self, "mp", mp-mpRate);
						}
					}
				}
			}
		}

		//USED BY NPC PARTNER
		if(parent != NULL()){
			if(vType == openborconstant("TYPE_NPC") && sType == openborconstant("SUBTYPE_FOLLOW")){
				void vAniID = getentityproperty(self,"animationID");
				void eType 	= getentityproperty(target,"type");
				int disable	= getentityproperty(self,"energycost", "disable", openborconstant(vAniID));
				int blocked = getlocalvar("blocked");
				int maxMp 	= getentityproperty(self,"maxmp");
				int mp 		= getentityproperty(self,"mp");
				int mpRate 	= getentityproperty(self,"mprate");

				if(disable == 5){
					if(blocked == 0){
						if(mp < maxMp){
							if(eType != openborconstant("TYPE_OBSTACLE")){
								changeentityproperty(self, "mp", mp-mpRate);
							}
						}
					}
				}
			}
			else
			{
			//USED BY PROJECTILES
				void eType 	= getentityproperty(target,"type");
				int disable	= getentityvar(self,"disable");
				int blocked = getlocalvar("blocked");
				int maxMp 	= getentityproperty(parent,"maxmp");
				int mp 		= getentityproperty(parent,"mp");
				int mpRate 	= getentityproperty(parent,"mprate");

				if(disable == 5){
					if(blocked == 0){
						if(mp < maxMp){
							if(eType != openborconstant("TYPE_OBSTACLE")){
								changeentityproperty(parent, "mp", mp-mpRate);
							}
						}
					}
				}
			}
		}
	}

	//USED BY "HEAL HIT" GLOBAL VARIABLE, TO RECOVER HEALTH BY EACH HIT INSTEAD OF RECOVERY BY TIME
	if(specialC == "sor4_recovery_(hits)"){
		void eType 	= getentityproperty(target,"type");

		if(eType != openborconstant("TYPE_OBSTACLE")){
			if(dmg > 0){ //USED GRABS AND OTHER "NO DAMAGE" ATKS
				if(atkType != openborconstant("ATK_NORMAL10")){ //USED FOR ROUTE MENU, DOORS, TOXIC GAS AND OTHER INVALID ATKS
					//USED BY PLAYER/ENEMY
					if(parent == NULL()){
						if(getglobalvar("addLife"+self) > 0){
							setglobalvar("healHit"+self, 1);
						}
					}

					//USED BY NPC PARTNER
					if(parent != NULL()){
						if(vType == openborconstant("TYPE_NPC") && sType == openborconstant("SUBTYPE_FOLLOW")){
							if(getglobalvar("addLife"+self) > 0){
								setglobalvar("healHit"+self, 1);
							}
						}else{ //USED BY PROJECTILES
							if(getglobalvar("addLife"+parent) > 0){
								setglobalvar("healHit"+parent, 1);
							}
						}
					}
				}
			}
		}
	}
}

void dropv(void ani, float xMult, float yVel, int changeDir, int dropFlag)
{//Same as native "dropv" command but with more configurations

	void self	= getlocalvar("self");
	void target	= getlocalvar("damagetaker");
	void sType	= getentityproperty(target,"subtype");
	void vAniID	= getentityproperty(self,"animationID");
	int tHealth	= getentityproperty(target,"health");
	int blocked	= getlocalvar("blocked");
	int drop	= getlocalvar("drop");
	int height	= getentityproperty(target,"y");
	int base	= getentityproperty(target,"base");
	float xVel	= getentityproperty(target,"xdir");

	if(tHealth >= 1){
		if(blocked == 0){
			if(drop == dropFlag){
				if(sType != openborconstant("SUBTYPE_NOTGRAB")){
					if(vAniID == openborconstant(ani)){
						if(changeDir == 1){xVel = -xVel;}
						if(height <= base){yVel = 0;}
						changeentityproperty(target, "velocity", xVel/xMult, 0, yVel);
					}
				}
			}
		}
	}
}

void sor4Juggle()
{//Used by SOR4 juggle system, who makes all main attacks to have a lower dropv height

	if(getglobalvar("juggleSystem") == "sor4"){
		void self	= getlocalvar("self");
		void target	= getlocalvar("damagetaker");
		void sType	= getentityproperty(target,"subtype");
		int health	= getentityproperty(target,"health");
		int dmg 	= getlocalvar("damage");
		int blocked	= getlocalvar("blocked");
		int drop	= getlocalvar("drop");
		int height	= getentityproperty(target,"y");
		int base	= getentityproperty(target,"base");
		float xVel	= getentityproperty(target,"xdir");
		float xMult	= 4;
		float yVel	= 1;

		if(health >= 1){
			if(dmg > 0){
				if(blocked == 0){
					if(drop == 0){
						if(sType != openborconstant("SUBTYPE_NOTGRAB")){
							if(height <= base){yVel = 0;}
							changeentityproperty(target, "velocity", xVel/xMult, 0, yVel);
						}
					}
				}
			}
		}
	}
}

void bowling()
{//Apply "projectile" property in Adam's kick (end combo) like SOR1, to throw enemies against others
	void self 	 = getlocalvar("self");
	void target  = getlocalvar("damagetaker");
	void atkType = getlocalvar("attacktype");
	void vType	 = getentityproperty(self,"type");
	void sType	 = getentityproperty(target,"subtype");
	int dead	 = getentityproperty(target,"dead");
	int blocked  = getlocalvar("blocked");

	if(dead == 0 && blocked == 0){
		if(atkType == openborconstant("ATK_NORMAL8")){
			if(sType != openborconstant("SUBTYPE_NOTGRAB")){
				if(vType == openborconstant("TYPE_PLAYER") || vType == openborconstant("TYPE_NPC")){
					changeentityproperty(target, "projectilehit", "type_enemy", "type_obstacle");
					changeentityproperty(target, "aiflag", "projectile", 1);
					changeentityproperty(target, "damage_on_landing", 1); //RESET PROJECTILE STATUS TO 0 WHEN FALL ON THE GROUND
				}
				else
				if(vType == openborconstant("TYPE_ENEMY")){
					changeentityproperty(target, "projectilehit", "type_player", "type_npc", "type_obstacle");
					changeentityproperty(target, "aiflag", "projectile", 1);
					changeentityproperty(target, "damage_on_landing", 1); //RESET PROJECTILE STATUS TO 0 WHEN FALL ON THE GROUND
				}
			}
		}
	}
}

void motorBike()
{//Push opponents if did hit
	void self	 = getlocalvar("self");
	void target  = getlocalvar("damagetaker");
	void atkType = getlocalvar("attacktype");
	void branch  = openborvariant("current_branch");
	void subType = getentityproperty(target, "subtype");
	int base	 = getentityproperty(self, "base");
	int Vy		 = getentityproperty(self, "y");
	int Vz		 = getentityproperty(self, "z");
	int Tz		 = getentityproperty(target, "z");
	int xVel	 = -2;
	int yVel	 = 0;
	int zVel	 = 2;

	if(Tz < Vz){zVel = -zVel;}

	if(branch == "sor3_st7d"){
		if(subType != openborconstant("SUBTYPE_NOTGRAB")){
			if(Vy <= base){
				if(atkType != openborconstant("ATK_NORMAL4")){
					tossentity(target, yVel, xVel, zVel);
				}
			}
		}
	}
}

void restoreOpponent()
{//Restore the last opponent when you are in a "falling" instance and hit other entities in mid-air
 //Used to avoid the opponent "change" when hit other entities in mid-air during a throw/slam, I don't know if it is an engine bug or not
	void self	= getlocalvar("self");
	void target	= getentityvar(self, "opponent");
	void ani	= getentityproperty(self, "animationID");

	//RESTORE THE LAST OPPONENT ENTITYVAR
	if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9")){
		changeentityproperty(self, "opponent", target);
	}
}

void mpCost(int cost)
{//Spend some mp
	void self = getlocalvar("self");
	int mp 	  = getentityproperty(self,"mp");

	if(mp >= cost) {
		changeentityproperty(self, "mp", mp-cost);
	} else {
		changeentityproperty(self, "mp", 0);
	}
}

void hpCost(int cost)
{//Spend some hp
	void self = getlocalvar("self");
	int hp	  = getentityproperty(self,"health");
	if(hp >= cost) {
		changeentityproperty(self, "health", hp-cost);
	}
}

void recoverGp() {
	void self = getlocalvar("self");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	changeentityproperty(self, "guardpoints", maxGp);
}

void gpCost(int cost)
{//Spend some gp
	void self = getlocalvar("self");
	float gp  = getentityproperty(self,"guardpoints");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	if(cost > 0) {
		if(gp >= cost) {
			changeentityproperty(self, "guardpoints", gp-cost);
		} else {
			changeentityproperty(self, "guardpoints", 0);
		}
	} else {
		if(gp - cost >= maxGp) {
			changeentityproperty(self, "guardpoints", maxGp);
		} else {
			changeentityproperty(self, "guardpoints", gp-cost);
		}
	}
}

void readKey(void key) {
	void self = getlocalvar("self");
	int pindex = getentityproperty(self,"playerindex");
	int facing = getentityproperty(self, "direction");

	if(key=="left" || key=="l") { return playerkeys(pindex, 0, "moveleft"); }
	else if(key=="right" || key=="r") { return playerkeys(pindex, 0, "moveright"); }
	else if(key=="up" || key=="u") { return playerkeys(pindex, 0, "moveup"); }
	else if(key=="down" || key=="d") { return playerkeys(pindex, 0, "movedown"); }
	else if(key=="attack" || key=="atk" || key=="a") { return playerkeys(pindex, 0, "attack"); }
	else if(key=="attack2" || key=="atk2" || key=="a2") { return playerkeys(pindex, 0, "attack2"); }
	else if(key=="attack3" || key=="atk3" || key=="a3") { return playerkeys(pindex, 0, "attack3"); }
	else if(key=="attack4" || key=="atk4" || key=="a4") { return playerkeys(pindex, 0, "attack4"); }
	else if(key=="jump" || key=="j") { return playerkeys(pindex, 0, "jump"); }
	else if(key=="special" || key=="sp" || key=="s") { return playerkeys(pindex, 0, "special"); }

	else if(key=="backward" || key=="back" || key=="b") {
		if(facing) { return playerkeys(pindex, 0, "moveleft"); }
		else { return playerkeys(pindex, 0, "moveright"); }
	}
	else if(key=="forward" || key=="fwd" || key=="f") {
		if(facing) { return playerkeys(pindex, 0, "moveright"); }
		else { return playerkeys(pindex, 0, "moveleft"); }
	}
	else { return 0; }
}

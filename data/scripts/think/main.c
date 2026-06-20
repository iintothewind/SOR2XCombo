#import "data/scripts/main.c"

void partnerMenu()
{//Changes options in Partner Menu
	void self 	 	= getlocalvar("self");

	if(!selfAlive()){return;}

	void pMode 	 	= getglobalvar("partnerMode");
	void pAggre	 	= getglobalvar("partnerAggression");
	void pFood 	 	= getglobalvar("partnerGetFood");
	void aimove   	= getentityproperty(self, "aimove");
	int maxHealth	= getentityproperty(self, "maxhealth");
	int health   	= getentityproperty(self, "health");
	int aggre   	= getentityproperty(self, "aggression");
	int life		= maxHealth/4;

	//PARTNER MODE
	if(pMode == "balanced" && aimove != openborconstant("AIMOVE1_NORMAL")){changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));}else
	if(pMode == "aggressive" && aimove != openborconstant("AIMOVE1_CHASE")){changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));}else
	if(pMode == "defensive" && aimove != openborconstant("AIMOVE1_AVOID")){changeentityproperty(self, "aimove", openborconstant("AIMOVE1_AVOID"));}

	//PARTNER AGGRESSION
	if(pAggre == "*" && aggre != -200){changeentityproperty(self, "aggression", -200);}else
	if(pAggre == "**" && aggre != -150){changeentityproperty(self, "aggression", -150);}else
	if(pAggre == "***" && aggre != -100){changeentityproperty(self, "aggression", -100);}else
	if(pAggre == "****" && aggre != -50){changeentityproperty(self, "aggression", -50);}else
	if(pAggre == "*****" && aggre != 0){changeentityproperty(self, "aggression", 0);}else
	if(pAggre == "******" && aggre != 200){changeentityproperty(self, "aggression", 200);}else
	if(pAggre == "*******" && aggre != 500){changeentityproperty(self, "aggression", 500);}else
	if(pAggre == "********" && aggre != 750){changeentityproperty(self, "aggression", 750);}else
	if(pAggre == "*********" && aggre != 999){changeentityproperty(self, "aggression", 999);}

	//PARTNER GET FOOD
	if(pFood == "never"){changeentityproperty(self, "detect", 0);}
	if(pFood == "75%_life"){if(health < life*3){changeentityproperty(self, "detect", 1);}else{changeentityproperty(self, "detect", 0);}}
	if(pFood == "50%_life"){if(health < life*2){changeentityproperty(self, "detect", 1);}else{changeentityproperty(self, "detect", 0);}}
	if(pFood == "25%_life"){if(health < life){changeentityproperty(self, "detect", 1);}else{changeentityproperty(self, "detect", 0);}}
}

void partnerAI()
{//Change some rules of A.I. gameplay
	void self 	 = getlocalvar("self");

	if(!selfAlive()){return;}

	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	void parent  = getentityproperty(self, "parent");
	void type	 = getentityproperty(self, "type");
	void ani	 = getentityproperty(self, "animationID");
	void enemy1;
	void enemy2;
	int hostile	 = getlocalvar("hostile");
	int health	 = getentityproperty(self, "health");
	int iPIndex	 = getentityproperty(parent, "playerindex");
	int vPIndex	 = getglobalvar("partnerIndex");
	int follow	 = getglobalvar("partnerFollow");
	float x  	 = getentityproperty(self, "x");
	float Px  	 = getentityproperty(parent, "x");
	float xPos 	 = openborvariant("xpos");
	float xDif 	 = 450; //DEFAULT PARTNER DISTANCE
	float xDist  = 20; //MINOR ADJUSTMENT FROM THE SCREEN EDGE
	float hRes   = openborvariant("hresolution");

	//PARTNER CALL BUTTON AND CUSTOM PARROW USED IN ONDRAW.C
	if(getglobalvar("extraButton") == "call_partner"){if(getglobalvar("partnerParrow") == "call"){xDif = 0;}}

	//CHANGE PARTNER PARENT WITH CALLER'S INDEX CHECK
	if(follow == "automatic" || follow == "manual" && getglobalvar("partnerParrow") == "call"){
		if(iPIndex != vPIndex){
			if(vPIndex == 0){
				if(player1 != NULL()){changeentityproperty(self, "parent", player1);setglobalvar("partnerIndex", 0);}else
				if(player2 != NULL()){changeentityproperty(self, "parent", player2);setglobalvar("partnerIndex", 1);}else
				if(player3 != NULL()){changeentityproperty(self, "parent", player3);setglobalvar("partnerIndex", 2);}else
				if(player4 != NULL()){changeentityproperty(self, "parent", player4);setglobalvar("partnerIndex", 3);}
			}
			if(vPIndex == 1){
				if(player2 != NULL()){changeentityproperty(self, "parent", player2);setglobalvar("partnerIndex", 1);}else
				if(player1 != NULL()){changeentityproperty(self, "parent", player1);setglobalvar("partnerIndex", 0);}else
				if(player3 != NULL()){changeentityproperty(self, "parent", player3);setglobalvar("partnerIndex", 2);}else
				if(player4 != NULL()){changeentityproperty(self, "parent", player4);setglobalvar("partnerIndex", 3);}
			}
			if(vPIndex == 2){
				if(player3 != NULL()){changeentityproperty(self, "parent", player3);setglobalvar("partnerIndex", 2);}else
				if(player1 != NULL()){changeentityproperty(self, "parent", player1);setglobalvar("partnerIndex", 0);}else
				if(player2 != NULL()){changeentityproperty(self, "parent", player2);setglobalvar("partnerIndex", 1);}else
				if(player4 != NULL()){changeentityproperty(self, "parent", player4);setglobalvar("partnerIndex", 3);}
			}
			if(vPIndex == 3){
				if(player4 != NULL()){changeentityproperty(self, "parent", player4);setglobalvar("partnerIndex", 3);}else
				if(player1 != NULL()){changeentityproperty(self, "parent", player1);setglobalvar("partnerIndex", 0);}else
				if(player2 != NULL()){changeentityproperty(self, "parent", player2);setglobalvar("partnerIndex", 1);}else
				if(player3 != NULL()){changeentityproperty(self, "parent", player3);setglobalvar("partnerIndex", 2);}
			}
		}

		//CHANGE HOSTILE TYPES WITH SOME CONDITIONS CHECK, USED TO MAINTAIN THE NPC INSIDE OF THE SCREEN EDGE AND NEAR TO THE CALLER'S
		if(x >= Px-xDif && x <= Px+xDif){ //INSIDE OF THE RANGE??
			if(hostile != 1){

				//PARTNER CALL BUTTON AND CUSTOM PARROW USED IN ONDRAW.C
				if(openborvariant("current_branch") == "sor3_st3b"){
					enemy1 = "type_obstacle";
					enemy2 = "type_npc";
				}else{
					enemy1 = "type_enemy";
					enemy2 = "type_npc";
				}
				changeentityproperty(self, "type", openborconstant("TYPE_NPC")); //SET TYPE
				changeentityproperty(self, "subtype", openborconstant("SUBTYPE_FOLLOW")); //SET SUBTYPE
				changeentityproperty(self, "hostile", enemy1, enemy2); //TURN ON HOSTILE AND GO TO FIGHT!!
				changeentityproperty(self, "nodrop", 0); //TURN NODROP OFF
				setlocalvar("hostile", 1);
			}
		}else{ //OUTSIDE OF THE RANGE??
			if(hostile != 2){
				changeentityproperty(self, "type", openborconstant("TYPE_NPC")); //SET TYPE
				changeentityproperty(self, "subtype", openborconstant("SUBTYPE_FOLLOW")); //SET SUBTYPE
				changeentityproperty(self, "hostile", "ground", "type_npc"); //TURN OFF HOSTILE AND RETURN BACK TO YOUR CALLER
				changeentityproperty(self, "nodrop", 0); //TURN NODROP OFF

				if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_WALK") || ani == openborconstant("ANI_BACKWALK") || ani == openborconstant("ANI_RUN")){
					if(type != openborconstant("TYPE_ENEMY")){ //CHECK IF ANY PLAYER IS IN THE SCREEN ACCORDING TO THE TYPE
						setidle(self, openborconstant("ANI_IDLE"));
					}
				}
				setlocalvar("hostile", 2);
			}
		}
	}
	else
	{
		//USED WHEN "FOLLOW CALLER" OPTION IS MANUAL AND "CALL" BUTTON IS NOT PRESSED
		if(parent != NULL()){
			changeentityproperty(self, "parent", NULL()); //CLEAR SPAWN PARENT
		}
		if(hostile != 1){

			//PARTNER CALL BUTTON AND CUSTOM PARROW USED IN ONDRAW.C
			if(openborvariant("current_branch") == "sor3_st3b"){
				enemy1 = "type_obstacle";
				enemy2 = "type_npc";
			}else{
				enemy1 = "type_enemy";
				enemy2 = "type_npc";
			}
			changeentityproperty(self, "type", openborconstant("TYPE_NPC")); //SET TYPE
			changeentityproperty(self, "subtype", openborconstant("SUBTYPE_FOLLOW")); //SET SUBTYPE
			changeentityproperty(self, "hostile", enemy1, enemy2); //TURN ON HOSTILE AND GO TO FIGHT!!
			changeentityproperty(self, "nodrop", 0); //TURN NODROP OFF
			setlocalvar("hostile", 1);
		}
	}

	//USED WHEN THERE ARE NO PLAYERS IN THE SCREEN, NPC WILL STOP FIGHTING
	if(player1 == NULL() && player2 == NULL() && player3 == NULL() && player4 == NULL()){ //DETECT ALIVE PLAYERS
		changeentityproperty(self, "type", openborconstant("TYPE_ENEMY")); //SET TYPE
		changeentityproperty(self, "subtype", openborconstant("SUBTYPE_NOTGRAB")); //SET SUBTYPE
		changeentityproperty(self, "hostile", "ground", "ground"); //TURN OFF HOSTILE AND RETURN BACK TO YOUR CALLER
		changeentityproperty(self, "nodrop", 1); //TURN NODROP ON
		changeentityproperty(self, "parent", NULL()); //SET SPAWN PARENT
		setglobalvar("partnerParrow", NULL()); //DISABLE PARTNER ARROW
	}

	//HOLD CAMERA SCROLL IF THE NPC PARTNER IS NEAR OF THE SCREEN EDGE, LIKE REAL MULTIPLAYER
	float screenSpeed = 0.5;

	//DIRECTION LEFT
	if(selfAlive()){
		if(openborvariant("current_branch") == "sor3_st3b"){ //BULLDOZER STAGE
			if(x >= xPos+hRes-xDist){
				changelevelproperty("scrollspeed", 0);
			}else{
				changelevelproperty("scrollspeed", screenSpeed);
			}
		}
		else //DIRECTION BOTH
		if(	openborvariant("current_branch") == "sor2_st1c"|| //BARBON BAR
			openborvariant("current_branch") == "sor3_st2c"|| //MONALISA BAR
			openborvariant("current_branch") == "sor3_st6a"|| //TOXIC GAS STAGE
			openborvariant("current_branch") == "sor3_st6f"|| //ROOFTOP JET
			openborvariant("current_branch") == "sor3_st7c"){ //MANSION SHIVA
			if(x >= xPos+hRes-xDist || x <= xPos+xDist){
				changelevelproperty("scrollspeed", 0);
			}else{
				changelevelproperty("scrollspeed", screenSpeed);
			}
		}
		else{ //DIRECTION RIGHT
			if(x <= xPos+xDist){ //ANY OTHER STAGE
				changelevelproperty("scrollspeed", 0);
			}else{
				changelevelproperty("scrollspeed", screenSpeed);
			}
		}
	}else{
		changelevelproperty("scrollspeed", screenSpeed);
	}
}

void partnerMap()
{//Manage partner map automatically according to players map
	void self 	 = getlocalvar("self");
	void name	 = getentityproperty(self, "defaultname");
	void name1 	 = getplayerproperty(0, "name");
	void name2 	 = getplayerproperty(1, "name");
	void name3 	 = getplayerproperty(2, "name");
	void name4 	 = getplayerproperty(3, "name");
	int map 	 = getentityproperty(self, "map");
	int map1 	 = getplayerproperty(0, "colourmap");
	int map2 	 = getplayerproperty(1, "colourmap");
	int map3 	 = getplayerproperty(2, "colourmap");
	int map4 	 = getplayerproperty(3, "colourmap");
	int map5 	 = getplayerproperty(getglobalvar("partnerIndex"), "colourmap");
	int mapFree;

	//DEFINE MAP
	if(name == name1+"_" && name == name2+"_" && name == name3+"_" && name == name4+"_"){ //NPC HAS SAME MAP AS ALL PLAYERS??
		if(map == map1 || map == map2 || map == map3 || map == map4){mapFree = map5;} //SET PARTNER MAP SAME AS CALLER MAP
	}
	else
	{
		if(name == name1+"_" && map == map1){if(map < 3){mapFree = map+1;}else{mapFree = 0;}} //PLAYER1
		if(name == name2+"_" && map == map2){if(map < 3){mapFree = map+1;}else{mapFree = 0;}} //PLAYER2
		if(name == name3+"_" && map == map3){if(map < 3){mapFree = map+1;}else{mapFree = 0;}} //PLAYER3
		if(name == name4+"_" && map == map4){if(map < 3){mapFree = map+1;}else{mapFree = 0;}} //PLAYER4
	}

	//CHANGE MAP
	if(map != mapFree){changeentityproperty(self, "map", mapFree);}
}

void partnerAni()
{//Manage partner animations automatically according to some opponents
	void self	= getlocalvar("self");

	if(!selfAlive()){return;}

	void target	= findtarget(self);
	void ani	= getentityproperty(self, "animationID");
	void tName	= getentityproperty(target, "defaultname");
	void branch	= openborvariant("current_branch");
	int minZ	= openborvariant("player_min_z");
	int x		= getentityproperty(self, "x");
	int z		= getentityproperty(self, "z");
	int Tx		= getentityproperty(target, "x");
	int Tz		= getentityproperty(target, "z");

	//USE DODGE AGAINST VEHICLES AND SOME OBJECTS
	if(	tName == "Barrel_Roll"	||
		tName == "Train"		||
		tName == "Bulldozer"	||
		tName == "Moto_Single"	||
		tName == "Moto_Jump"	||
		tName == "Moto_Repeat"	){

		int Dx 		= Tx - x;
		int Dz 		= Tz - z;
		int xDif	= 140;
		int zDif	= 30;
		int xMin	= -xDif;
		int xMax	= xDif;
		int zMin	= -zDif;
		int zMax	= zDif;

		if(Dx >= xMin && Dx <= xMax && Dz >= zMin && Dz <= zMax){
			if(	ani == openborconstant("ANI_IDLE")		||
				ani == openborconstant("ANI_WALK")		||
				ani == openborconstant("ANI_BACKWALK")	||
				ani == openborconstant("ANI_RUN")		||
				ani == openborconstant("ANI_BLOCK")		){
				executeanimation(self, openborconstant("ANI_DODGE"), 0);
			}
		}
	}

	//USE DODGE AGAINST DR. ZERO LASER
	if(branch == "sor3_st8d"){
		int Dz 	 = z - minZ;
		int zDif = 10;

		if(Dz < zDif){
			if(	ani == openborconstant("ANI_IDLE")		||
				ani == openborconstant("ANI_WALK")		||
				ani == openborconstant("ANI_BACKWALK")	||
				ani == openborconstant("ANI_RUN")		||
				ani == openborconstant("ANI_BLOCK")		){
				executeanimation(self, openborconstant("ANI_DODGE"), 0);
			}
		}
	}
}

void calcWalkSpeedRate(void target) {
	void difficult	= getglobalvar("difficult");
	if(difficult == "mania"){
		return isBoss(target)? 1.2 : 1.5;
	} else if(difficult == "hard"){
		return isBoss(target)? 1.15 : 1.35;
	}  else {
		return isBoss(target)? 1.1 : 1.2;
	}
}

void enemyAI()
{//Script to improve the enemy "aimoves"
	void self		= getlocalvar("self");

	if(!selfAlive()){return;}

	void target		= findtarget(self);
	float time		= openborvariant("elapsed_time");
	int aimove		= getentityproperty(self, "aimove");
	float xDir			= getentityproperty(self, "xdir");
	float zDir			= getentityproperty(self, "zdir");
	int walking			= getentityproperty(self, "aiflag", "walking");
	int vDir			= getentityproperty(self, "direction");
	void smarterEnemy	= getglobalvar("smarterEnemy");
	if(target != NULL()) {
		int targetVulnerable	= getentityproperty(target, "vulnerable");
		int targetInvincible	= getentityproperty(target, "invincible");
		int targetRising			= getentityproperty(target, "aiflag", "rising");
		int targetBlink			= getentityproperty(target, "blink");

		void animation 		= getentityproperty(target, "animationID");
		int selfDir = getentityproperty(self, "direction");
		int targetDir = getentityproperty(target, "direction");
		float limit		= 200;

		//DETECT IF THE OPPONENT IS NOT VULNERABLE, CHANGE AIMOVE TO "AVOID"
		if(!targetVulnerable
		   || (targetInvincible && selfDir != targetDir)
		   || (targetRising && selfDir != targetDir)
		   || (targetBlink && selfDir != targetDir)){
			if(aimove != openborconstant("AIMOVE1_AVOID")){
				changeentityproperty(self, "aimove", openborconstant("AIMOVE1_AVOID"));
				setlocalvar("aiChange"+self, time+limit);
			}
		}

		//DETECT IF THE OPPONENT IS Blocking, CHANGE AIMOVE TO "AVOID"
		if((animation == openborconstant("ANI_BLOCK") && selfDir != targetDir)
		||(animation == openborconstant("ANI_FOLLOW11") && selfDir != targetDir)){
			if(aimove != openborconstant("AIMOVE1_AVOID") && smarterEnemy == "on"){
				changeentityproperty(self, "aimove", openborconstant("AIMOVE1_AVOID"));
				setlocalvar("aiChange"+self, time+limit);
			}
		}
	}

	// keep walking speed normal according to players feedback
	// if(walking){
	// 	if(aimove == openborconstant("AIMOVE1_AVOID")){
	// 		float rate = calcWalkSpeedRate(self);
	// 		if(xDir != 0){changeentityproperty(self, "velocity", xDir*rate, NULL());}
	// 		if(zDir != 0){changeentityproperty(self, "velocity", NULL(), zDir*rate);}
	// 	}
	// }


	//RESET CURRENT AIMOVE TO "CHASE"
	if(getlocalvar("aiChange"+self) < time){
		if(aimove != openborconstant("AIMOVE1_CHASE")){
			changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
		}
	}
}

void smartDodge()
{//Create a logic to make enemies to use the "dodge" animation, same as the "block" logic
	void self = getlocalvar("self");

	if(!selfAlive()){return;}

	int blockValid = getentityproperty(self, "animvalid", openborconstant("ANI_BLOCK"));
	int dodgeValid = getentityproperty(self, "animvalid", openborconstant("ANI_DODGE"));
	int aimove		= getentityproperty(self, "aimove");
	void target = NULL();
	int targetAtk	= 0;
	if(dodgeValid == 1) {
		target	= findtarget(self, openborconstant("ANI_DODGE"));
		targetAtk	= getentityproperty(target, "aiflag", "attacking");
	}

	//DO A SERIES OF CONDITION CHECKS
	if(target != NULL() && targetAtk > 0){ //A OPPONENT EXISTS IN THE DEFINED RANGE AND IS ATTACKING ME??
		int vDir = getentityproperty(self, "direction");
		int tDir = getentityproperty(target, "direction");

		int targetRush	 = getentityproperty(target,"rush_count");

		if(vDir != tDir){ //THE OPPONENT IS FACING ME??
			void ani		= getentityproperty(self, "animationID");
			void type		= getentityproperty(self, "type");
			float time		= openborvariant("elapsed_time");
			float waitLow	= 300;
			float wait		= 400;
			float waitHigh	= 500;

			if(	ani == openborconstant("ANI_IDLE") ||
				ani == openborconstant("ANI_WALK") ||
				ani == openborconstant("ANI_BACKWALK")||
				ani == openborconstant("ANI_RUN")){ //I'M IN THE IDLE/WALK/BACKWALK/RUN ANIMATIONS??
				//CPU PARTNER WAIT TIME IS DEFINED BY THE PARTNER MODE OPTION
				if(type == openborconstant("TYPE_NPC")){

					//DEFINE THE WAIT TIME
					if(getglobalvar("partnerMode") == "agressive"){wait = waitHigh;}else
					if(getglobalvar("partnerMode") == "defensive"){wait = waitLow;}

					//PERFORM DODGE AND APPLY THE WAIT TIME
					if(targetRush > 1 || getlocalvar("nextDodge"+self) < time || getlocalvar("nextDodge"+self) == NULL()){ //IS THE "WAIT" TIME REACHED??
						executeanimation(self, openborconstant("ANI_DODGE"), 0); //FINALLY, I CAN PERFORM THE DODGE MOVE :)
						setlocalvar("nextDodge"+self, time+wait); //SAVE THE CURRENT TIME+DELAY TO WAIT A LITTLE UNTIL THE NEXT DODGE MOVE
					}
				}

				//ENEMY WAIT TIME IS DEFINED BY THE DIFFICULT OPTION
				if(type == openborconstant("TYPE_ENEMY")){

					//DEFINE THE WAIT TIME
					if(getglobalvar("difficult") == "normal"){wait = waitHigh;}else
					if(getglobalvar("difficult") == "mania"){wait = waitLow;}

          //USE BLOCK MORE OFTEN IF IT IS NOT AVOID TYPE AND IT HAS BLOCK
					if(aimove != openborconstant("AIMOVE1_AVOID") && blockValid == 1) { wait = wait * 5;}

					//PERFORM DODGE AND APPLY THE WAIT TIME
					if(targetRush > 9 || getlocalvar("nextDodge"+self) < time || getlocalvar("nextDodge"+self) == NULL()){ //IS THE "WAIT" TIME REACHED??
						executeanimation(self, openborconstant("ANI_DODGE"), 0); //FINALLY, I CAN PERFORM THE DODGE MOVE :)
						setlocalvar("nextDodge"+self, time+wait); //SAVE THE CURRENT TIME+DELAY TO WAIT A LITTLE UNTIL THE NEXT DODGE MOVE
					}
				}
			}
		}
	}
}

void rooFlee()
{//Script to change some properties when defined entity is dead (ROO FLEE WHEN YOUR TAMER IS DEAD)
	void self 	= getlocalvar("self");

	if(!selfAlive()){return;}

	void tamer	= getentityvar(self, "tamer");
	int detect	= getentityproperty(self, "detect");
	float x		= getentityproperty(self, "x");
	float xPos	= openborvariant("xpos");

	//CURRENT TAMER IS DEAD?? FLEE!!!
	if(tamer != NULL() && !entityAlive(tamer)){
		changeentityproperty(self, "hostile", "type_enemy", "type_enemy");
		changeentityproperty(self, "detect", 2);
		changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
	}

	//OUT OF THE SCREEN EDGE?? SUICIDE!!!
	if(detect == 2){
		if(x < xPos-50){
			killentity(self);
		}
	}
}

void monalisaCoop()
{//Script to make teamwork jumpattack, a main character controls some actions of a secondary character in defined conditions
	void self 	= getlocalvar("self");

	if(!selfAlive()){return;}

	void ani	= getentityproperty(self, "animationID");
	int dir		= getentityproperty(self, "direction");
	int base	= getentityproperty(self, "base");
	int x		= getentityproperty(self, "x");
	int y		= getentityproperty(self, "y");
	int z		= getentityproperty(self, "z");
	void sister	= getentityvar(self, "sister");

	if(sister != NULL()) {
		void tAni	= getentityproperty(sister, "animationID");
		int Tx		= getentityproperty(sister, "x");
		int Ty		= getentityproperty(sister, "y");
		int Tz		= getentityproperty(sister, "z");
		int difX	= Tx - x;
		int difZ	= Tz - z;

		if(dir == 0){difX = -difX;}

		if(entityAlive(sister)){
			if(difX < 48 && difX > 24 && y <= base && Ty == base && difZ < 6 && difZ > -6){ //CHECK SECONDARY CHARACTER POSITION
				if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_WALK")){ //CHECK MAIN CHARACTER ANIMATION
					if(tAni == openborconstant("ANI_IDLE") || tAni == openborconstant("ANI_WALK")){ //CHECK SECONDARY CHARACTER ANIMATION
						if(dir == 0){
							changeentityproperty(sister, "direction", 1); //CHANGE SECONDARY CHARACTER DIRECTION TO FACING MAIN CHARACTER
						}
						else
						if(dir == 1){
							changeentityproperty(sister, "direction", 0); //CHANGE SECONDARY CHARACTER DIRECTION TO FACING MAIN CHARACTER
						}
						changeentityproperty(self, "velocity", 0, 0, 0); //CHANGE VELOCITY OF THE MAIN CHARACTER TO 0
						executeanimation(self, openborconstant("ANI_FOLLOW1"), 1); //EXECUTE DEFINED MAIN CHARACTER ANIMATION
						executeanimation(sister, openborconstant("ANI_FOLLOW1"), 1); //EXECUTE SECONDARY CHARACTER ANIMATION
					}
				}
			}
		}
	}
}

void loadEnemyRushLimit() {
	int limit = 999;
	void enemyRushLimitCfg = getglobalvar("enemyRushLimit");
	if(enemyRushLimitCfg == "2") {
		limit = 2;
	} else if(enemyRushLimitCfg == "4") {
		limit = 4;
	} else if(enemyRushLimitCfg == "6") {
		limit = 6;
	} else if(enemyRushLimitCfg == "8") {
		limit = 8;
	} else if(enemyRushLimitCfg == "10") {
		limit = 10;
	} else if(enemyRushLimitCfg == "20") {
		limit = 20;
	} else if(enemyRushLimitCfg == "30") {
		limit = 30;
	} else if(enemyRushLimitCfg == "50") {
		limit = 50;
	}
	return limit;
}

void enemyRushControl() {
	void self 	= getlocalvar("self");

	if(self == NULL() || !entityAlive(self)){return;}

	int base	= getentityproperty(self, "base");
	int height		= getentityproperty(self, "y");
	int rush	 = getentityproperty(self,"rush_count");
	void animId  = getentityproperty(self,"animationID");
	int aimove		= getentityproperty(self, "aimove");
	int blockValid = getentityproperty(self, "animvalid", openborconstant("ANI_BLOCK"));
	int dodgeValid = getentityproperty(self, "animvalid", openborconstant("ANI_DODGE"));
	void grabbedTarget = getentityvar(self,"grabbed");
	void grabbingTarget = getentityproperty(self, "grabbing");
	int rushLimit = loadEnemyRushLimit();
	float time		= openborvariant("elapsed_time");
	float wait	= 500;

	if(getglobalvar("enemyRushLimit") != "unlimited") {
		if((getlocalvar("nextRushControl"+self) == NULL() || getlocalvar("nextRushControl"+self) < time) && rush >= rushLimit && base == height){
			if(animId != openborconstant("ANI_GRAB")
			&& animId != openborconstant("ANI_GRABBED")
			&& animId != openborconstant("ANI_GRABATTACK")
			&& animId != openborconstant("ANI_GRABATTACK2")
			&& animId != openborconstant("ANI_GRABUP")
			&& animId != openborconstant("ANI_GRABUP2")
			&& animId != openborconstant("ANI_GRABDOWN")
			&& animId != openborconstant("ANI_GRABDOWN2")
			&& animId != openborconstant("ANI_GRABFORWARD")
			&& animId != openborconstant("ANI_GRABFORWARD2")
			&& animId != openborconstant("ANI_GRABBACKWARD")
			&& animId != openborconstant("ANI_GRABBACKWARD2")
			&& grabbedTarget == NULL()
			&& grabbingTarget == NULL()) {
				setlocalvar("nextRushControl"+self, time+wait);
				if(dodgeValid) {
					executeanimation(self, openborconstant("ANI_DODGE"), 0);
				} else if(blockValid) {
					executeanimation(self, openborconstant("ANI_BLOCK"), 0);
				} else {
					executeanimation(self, openborconstant("ANI_IDLE"), 0);
				}
				changeentityproperty(self, "rush_count", 0);
			}
		}
	}
}


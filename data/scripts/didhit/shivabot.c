#import "data/scripts/main.c"
#import "data/scripts/didhit/main.c"

void main()
{
	lockMp();
	specialCost();
	customGrab();
	painLand();
	rageVel();
	updateJuggleOtg();
	restoreOpponent();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
	void self 		= getlocalvar("self");

	if(!selfAlive()){return;}

	void sType  	= getentityproperty(self,"type");
	int sX 		= getentityproperty(self,"x");
	int sY 		= getentityproperty(self,"y");
	int sZ 		= getentityproperty(self,"z");
	int sBase 	= getentityproperty(self,"base");
	void target 	= getlocalvar("damagetaker");
	void vAniID 	= getentityproperty(self,"animationID");
	void tAniID 	= getentityproperty(target,"animationID");
	int targetInvincible	= getentityproperty(target, "invincible");
	void iType  	= getentityproperty(target,"type");
	void iSubType	= getentityproperty(target,"subtype");
	int tX 		= getentityproperty(target,"x");
	int tY 		= getentityproperty(target,"y");
	int tZ 		= getentityproperty(target,"z");
	int tBase 	= getentityproperty(target,"base");
	int tDir		 = getentityproperty(target,"direction");
	int xOffset = 40;
	if(tDir == 0){xOffset = -xOffset;}
	int jgCost = 5;
	int mp			= getentityproperty(self,"mp");

	//AERIAL PILE
	if(vAniID == openborconstant("ANI_FOLLOW8")){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					if(tY > 1){ //NEED TO BE 1 TO WORK WITH JETS/ROCKETS
						performattack(self, openborconstant("ANI_GRABBACKWARD2"), 0);
					}
				}
			}
		}
	}

	if(vAniID == openborconstant("ANI_JUMPATTACK2") ){
		if(mp >= jgCost && tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					if(sY > sBase) {
						changeentityproperty(self,"position", sX, sZ, 0);
						changeentityproperty(self,"velocity", 0, 0, 0);
						changeentityproperty(self, "aiflag", "jumping", 0);
					}

					if(entityAlive(target)) {
						setidle(target);
						changeentityproperty(target,"position", tX, tZ, 0);
						changeentityproperty(target,"velocity", 0, 0, 0);
						executeanimation(target, openborconstant("ANI_PAIN"), 1);
						changeentityproperty(target,"takeaction", "common_pain");
						changeentityproperty(target,"damage_on_landing",0);
						changeentityproperty(target, "aiflag", "jumping", 0);
						changeentityproperty(target,"aiflag","falling",0);
						changeentityproperty(target,"aiflag","drop",0);
						changeentityproperty(target,"aiflag","projectile",0);
						changeentityproperty(target,"nograb",0);
					}

					mpCost(jgCost);
					performattack(self, openborconstant("ANI_GRABDOWN2"), 0);
				}
			}
		} else {
			performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
			changeentityproperty(self, "aiflag", "jumping", 1);
			changeentityproperty(self, "takeaction", "common_jump");
		}
	}

	if(vAniID == openborconstant("ANI_FREESPECIAL2") || vAniID == openborconstant("ANI_FREESPECIAL4")){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					if(sY > sBase) {
						changeentityproperty(self,"position", sX, sZ, 0);
						changeentityproperty(self,"velocity", 0, 0, 0);
						changeentityproperty(self, "aiflag", "jumping", 0);
					}

					if(entityAlive(target)) {
						setidle(target);
						changeentityproperty(target,"position", tX, tZ, 0);
						changeentityproperty(target,"velocity", 0, 0, 0);
						executeanimation(target, openborconstant("ANI_PAIN"), 1);
						changeentityproperty(target,"takeaction", "common_pain");
						changeentityproperty(target,"damage_on_landing",0);
						changeentityproperty(target, "aiflag", "jumping", 0);
						changeentityproperty(target,"aiflag","falling",0);
						changeentityproperty(target,"aiflag","drop",0);
						changeentityproperty(target,"aiflag","projectile",0);
						changeentityproperty(target,"nograb",0);
					}

					performattack(self, openborconstant("ANI_FOLLOW5"), 0);
				}
			}
		}
	}
}


void painLand()
{//Opponent forced do Land and change to Pain if hit in mid-air (KOF RYO/TAKUMA DESPERATION STYLE)
	void self 	= getlocalvar("self");

	if(!selfAlive()){return;}

	int sX 		= getentityproperty(self,"x");
	int sZ 		= getentityproperty(self,"z");
	void target = getlocalvar("damagetaker");
	int sDir		 = getentityproperty(self,"direction");
	void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	void eType	= getentityproperty(target,"type");
	void sType	= getentityproperty(target,"subtype");
	int frame	= getentityproperty(self,"animpos");
	int hits	 = getentityproperty(self,"animhits");
	int targetInvincible	= getentityproperty(target, "invincible");
	int Tx 		= getentityproperty(target,"x");
	int Ty 		= getentityproperty(target,"y");
	int Tz 		= getentityproperty(target,"z");
	int tBase 	= getentityproperty(target,"base");
	int tDir		 = getentityproperty(target,"direction");
	int xOffset = 40;

	if(sDir == 0){xOffset = -xOffset;}
	int isWall = checkwall(sX+xOffset, Tz);
	int isHole = checkhole(sX+xOffset, Tz);

	if(entityAlive(target) && targetInvincible == 0){
		if(vAniID == openborconstant("ANI_ATTACK2") && isWall == 0 && isHole == 0){
			setidle(target);
			changeentityproperty(target,"position", sX+xOffset, sZ, 0);
			changeentityproperty(target,"velocity", 0, 0, 0);
			executeanimation(target, openborconstant("ANI_PAIN"), 1);
			changeentityproperty(target,"takeaction", "common_pain");
			changeentityproperty(target,"damage_on_landing",0);
			changeentityproperty(target,"aiflag","falling",0);
			changeentityproperty(target,"aiflag","drop",0);
			changeentityproperty(target,"aiflag","projectile",0);
			changeentityproperty(target,"nograb",0);
		}
	}

	if(Ty > tBase && entityAlive(target) && targetInvincible == 0){
		if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")){
			if(vModel == "Shiva_" || vModel == "SOR3_Shiva"){
				if(vAniID == openborconstant("ANI_ATTACK1")){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, Ty);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_FALL"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}
			}
			if(vModel != "Shiva_"){
				if((vAniID == openborconstant("ANI_FREESPECIAL3") && frame < 6) || (vAniID == openborconstant("ANI_FREESPECIAL") && frame < 35 )){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, 0);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}
				if(vAniID == openborconstant("ANI_FOLLOW3") || vAniID == openborconstant("ANI_FREESPECIAL4") || vAniID == openborconstant("ANI_FREESPECIAL5")){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, 0);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}

				if(vAniID == openborconstant("ANI_RUNATTACK") || vAniID == openborconstant("ANI_FREESPECIAL5")){
					performattack(self, openborconstant("ANI_FOLLOW3"), 0);
				}
			}
			if(vModel == "Shiva_"){
				if((vAniID == openborconstant("ANI_SPECIAL2") && frame < 17) || (vAniID == openborconstant("ANI_FREESPECIAL") && frame < 35 )){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, 0);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}
				if(vAniID == openborconstant("ANI_RUNATTACK") || vAniID == openborconstant("ANI_FREESPECIAL2")){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, 0);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}

				if(vAniID == openborconstant("ANI_FOLLOW3") && frame < 3){
					setidle(target);
					changeentityproperty(target,"position", Tx, Tz, 0);
					changeentityproperty(target,"velocity", 0, 0, 0);
					executeanimation(target, openborconstant("ANI_PAIN"), 1);
					changeentityproperty(target,"takeaction", "common_pain");
					changeentityproperty(target,"damage_on_landing",0);
					changeentityproperty(target,"aiflag","falling",0);
					changeentityproperty(target,"aiflag","drop",0);
					changeentityproperty(target,"aiflag","projectile",0);
					changeentityproperty(target,"nograb",0);
				}

				if(vAniID == openborconstant("ANI_RUNATTACK")){
					performattack(self, openborconstant("ANI_FOLLOW3"), 0);
				}
			}
		}
	}
}

void rageVel()
{//Adjust velocity in Rage Run Hit
	void self 	= getlocalvar("self");
	void target = getlocalvar("damagetaker");
	void vAniID = getentityproperty(self,"animationID");
	void eType	= getentityproperty(target,"type");
	void sType	= getentityproperty(target,"subtype");
	int dir		= getentityproperty(self,"direction");
	int Px 		= getentityproperty(self,"x");
	int Tx 		= getentityproperty(target,"x");
	int Ty 		= getentityproperty(target,"y");
	int tBase 	= getentityproperty(target,"base");
	float xVel 	= getentityproperty(self,"xdir");
	float pMult	= 5;
	float eMult	= 3;
	float xDif	= 20;

	if(vAniID == openborconstant("ANI_FREESPECIAL")){
		if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")){
			if(Ty == tBase){
				changeentityproperty(self, "velocity", xVel/pMult, 0, 0);

				if(dir == 1){
					if(Tx >= Px+xDif){
						changeentityproperty(target, "velocity", 0, 0, 0);
					}else{
						changeentityproperty(target, "velocity", xVel/eMult, 0, 0);
					}
				}

				if(dir == 0){
					if(Tx <= Px-xDif){
						changeentityproperty(target, "velocity", 0, 0, 0);
					}else{
						changeentityproperty(target, "velocity", xVel/eMult, 0, 0);
					}
				}
			}
		}
	}
}
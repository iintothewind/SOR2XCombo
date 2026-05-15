#import "data/scripts/didhit/main.c"

void main()
{
	lockMp();
	specialCost();
	customGrab();
	painLand();
	rageVel();
	// bowling();
	updateJuggleOtg();
	restoreOpponent();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
	void self 		= getlocalvar("self");
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
	int dead	= getentityproperty(target,"dead");
	int tX 		= getentityproperty(target,"x");
	int tY 		= getentityproperty(target,"y");
	int tZ 		= getentityproperty(target,"z");
	int tBase 	= getentityproperty(target,"base");
	int jgCost = 5;
	int mp			= getentityproperty(self,"mp");

	//JUMP GRAB
	if(vAniID == openborconstant("ANI_JUMPATTACK2")){
		if(mp >= jgCost && tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && dead == 0 && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					if(sY > sBase) {
						changeentityproperty(self,"position", sX, sZ, 0);
						changeentityproperty(self,"velocity", 0, 0, 0);
						changeentityproperty(self, "aiflag", "jumping", 0);
					}

					if(tY > tBase && dead == 0) {
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
					// performattack(self, openborconstant("ANI_FOLLOW5"), 0);
				}
			}
		} else {
			performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
			changeentityproperty(self, "aiflag", "jumping", 1);
			changeentityproperty(self, "takeaction", "common_jump");
		}
	}
}


void painLand()
{//Opponent forced do Land and change to Pain if hit in mid-air (KOF RYO DESPERATION STYLE)
	void self 	= getlocalvar("self");
	void target = getlocalvar("damagetaker");
	void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	void eType	= getentityproperty(target,"type");
	void sType	= getentityproperty(target,"subtype");
	int frame	= getentityproperty(self,"animpos");
	int hits	 = getentityproperty(self,"animhits");
	int dead	= getentityproperty(target,"dead");
	int targetInvincible	= getentityproperty(target, "invincible");
	int Tx 		= getentityproperty(target,"x");
	int Ty 		= getentityproperty(target,"y");
	int Tz 		= getentityproperty(target,"z");
	int tBase 	= getentityproperty(target,"base");

	if(Ty > tBase && dead == 0 && targetInvincible == 0){
		if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")){
			if(vModel == "Adam"){
				if(vAniID == openborconstant("ANI_ATTACK1") && hits < 1){
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

			if((vAniID == openborconstant("ANI_SPECIAL2")
			|| vAniID == openborconstant("ANI_FREESPECIAL20")
			|| vAniID == openborconstant("ANI_FOLLOW22")) && frame < 8){
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


			if(vModel == "Adam_Sword"){
				if(vAniID == openborconstant("ANI_FREESPECIAL") && frame < 21){
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
			}

			if(vModel != "Adam_Sword"){
				if(vAniID == openborconstant("ANI_FREESPECIAL")
				|| vAniID == openborconstant("ANI_FREESPECIAL3")){
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

				if(vAniID == openborconstant("ANI_FOLLOW1") && frame < 20){
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

				if(vAniID == openborconstant("ANI_FOLLOW4") && frame < 2){
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
			}
		}
	}
}

void rageVel()
{//Adjust velocity in Rage Run Hit
	void self 	= getlocalvar("self");
	void target = getlocalvar("damagetaker");
	void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	void eType	= getentityproperty(target,"type");
	void sType	= getentityproperty(target,"subtype");
	int dir		= getentityproperty(self,"direction");
	int Px 		= getentityproperty(self,"x");
	int Tx 		= getentityproperty(target,"x");
	int Ty 		= getentityproperty(target,"y");
	int tBase 	= getentityproperty(target,"base");
	float xVel 	= getentityproperty(self,"xdir");
	float pMult	= 2.4;
	float eMult	= 1.6;
	float xDif	= 20;

	if(vModel != "Adam_Sword"){
		if(vAniID == openborconstant("ANI_FREESPECIAL3") || vAniID == openborconstant("ANI_FOLLOW1")) {
			if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")){
				if(Ty == tBase){
					changeentityproperty(self, "velocity", xVel/pMult, 0, 0);
					if(dir == 1){
						if(Tx > Px+xDif){
							changeentityproperty(target, "velocity", 0, 0, 0);
						}else{
							changeentityproperty(target, "velocity", xVel/eMult, 0, 0);
						}
					}

					if(dir == 0){
						if(Tx < Px-xDif){
							changeentityproperty(target, "velocity", 0, 0, 0);
						}else{
							changeentityproperty(target, "velocity", xVel/eMult, 0, 0);
						}
					}
				}
			}
		}
	}
}

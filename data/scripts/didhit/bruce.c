#import "data/scripts/didhit/main.c"
#import "data/scripts/animation/main_grabs.c"

void main()
{
	lockMp();
	specialCost();
	painLand();
	updateJuggleOtg();
	customGrab();
	restoreOpponent();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
	void self 		= getlocalvar("self");
	void sType  	= getentityproperty(self,"type");
	void vModel	= getentityproperty(self,"model");
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

	if(vModel == "Tamer"){
		if(vAniID == openborconstant("ANI_FREESPECIAL2")){
			if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && dead == 0 && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
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

						landGrab();
						// performattack(self, openborconstant("ANI_GRABDOWN2"), 0);
						performattack(self, openborconstant("ANI_GRABATTACK"), 0);
					}
				}
			}
		}
	}


	if(vAniID == openborconstant("ANI_FREESPECIAL3")){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && dead == 0 && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB") && sType != openborconstant("TYPE_PLAYER")){
					performattack(self, openborconstant("ANI_GRABATTACK"), 0);
				}
			}
		}
	}
}

void painLand()
{//Opponent forced do Land and change to Pain if hit in mid-air (KOF RYO DESPERATION STYLE)
	void self 	= getlocalvar("self");
	void vModel	= getentityproperty(self,"model");
	void target = getlocalvar("damagetaker");
	void eType	= getentityproperty(target,"type");
	void sType	= getentityproperty(target,"subtype");
	void vAniID = getentityproperty(self,"animationID");
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
			if((vAniID == openborconstant("ANI_GRABATTACK")
			|| vAniID == openborconstant("ANI_FOLLOW7")) && frame < 6){
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
			if(vAniID == openborconstant("ANI_FREESPECIAL3")){
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

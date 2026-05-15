#import "data/scripts/key/main.c"
#import "data/scripts/didhit/main.c"

void main()
{
	lockMp();
	specialCost();
	// bowling();
	updateJuggleOtg();
	customGrab();
	painLand();
	restoreOpponent();
	dropv("ANI_SPECIAL2", 9, 0.7, 0, 0);
	dropv("ANI_FREESPECIAL", 2, 0.4, 0, 0);
	dropv("ANI_FREESPECIAL2", 7, 0.7, 0, 0);

	//USED ONLY FOR THE "LEGACY HEADBUTT" ATTACK
	if(getglobalvar("juggleSystem") == "sor4"){dropv("ANI_GRABATTACK", 0.60, 2, 0, 1);}
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
				}
			}
		} else {
			performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
			changeentityproperty(self, "aiflag", "jumping", 1);
			changeentityproperty(self, "takeaction", "common_jump");
		}
	}

	if(vAniID == openborconstant("ANI_FREESPECIAL2") ){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && dead == 0 && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					if(sY > sBase) {
						changeentityproperty(self,"position", sX, sZ, 0);
						changeentityproperty(self,"velocity", 0, 0, 0);
						changeentityproperty(self, "aiflag", "jumping", 0);
					}

					if(dead == 0) {
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

			if(vModel == "Axel"){
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

			if(vModel != "Axel_Sword"){
				if(vAniID == openborconstant("ANI_SPECIAL2") && frame < 17){
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

				if(vAniID == openborconstant("ANI_FREESPECIAL") && frame < 3){
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

				if(vAniID == openborconstant("ANI_FREESPECIAL2") && frame < 3){
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

				if(vAniID == openborconstant("ANI_FREESPECIAL6")){
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
				if(vAniID == openborconstant("ANI_FREESPECIAL6")){performattack(self, openborconstant("ANI_FOLLOW3"), 0);}
			}

			if(vModel == "Axel_Sword"){
				if(vAniID == openborconstant("ANI_RUNATTACK")){
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

				if(vAniID == openborconstant("ANI_FOLLOW1") && frame < 3){
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
				if(vAniID == openborconstant("ANI_RUNATTACK")){performattack(self, openborconstant("ANI_FOLLOW1"), 0);}
			}
		}
	}
}
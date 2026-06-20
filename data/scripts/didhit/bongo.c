#import "data/scripts/main.c"
#import "data/scripts/didhit/main.c"

void main()
{
	lockMp();
	specialCost();
	customGrab();
	sor4Juggle();
	restoreOpponent();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
	void self 		= getlocalvar("self");

	if(!selfAlive()){return;}

	void target 	= getlocalvar("damagetaker");
	void vAniID 	= getentityproperty(self,"animationID");
	void tAniID 	= getentityproperty(target,"animationID");
	int targetInvincible	= getentityproperty(target, "invincible");
	void iType  	= getentityproperty(target,"type");
	void iSubType	= getentityproperty(target,"subtype");

	//PLAYER GRAB
	if(vAniID == openborconstant("ANI_FREESPECIAL")){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_ENEMY")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					performattack(self, openborconstant("ANI_FOLLOW1"), 0);
				}
			}
		}
	}

	//ENEMY GRAB
	if(vAniID == openborconstant("ANI_ATTACK5")){
		if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
			if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_NPC")){
				if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
					performattack(self, openborconstant("ANI_FOLLOW1"), 0);
				}
			}
		}
	}
}
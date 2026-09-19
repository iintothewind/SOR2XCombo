#import "data/scripts/main.c"
#import "data/scripts/didhit/main.c"
#import "data/scripts/animation/main_spawns.c"

void main()
{
    lockMp();
    specialCost();
    customGrab();
    painLand();
    sor4Juggle();
    restoreOpponent();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
    void self         = getlocalvar("self");

    if(!selfAlive()){return;}

    void sType      = getentityproperty(self,"type");
    int sX         = getentityproperty(self,"x");
    int sY         = getentityproperty(self,"y");
    int sZ         = getentityproperty(self,"z");
    int sBase     = getentityproperty(self,"base");
    void target     = getlocalvar("damagetaker");
    void vAniID     = getentityproperty(self,"animationID");
    void tAniID     = getentityproperty(target,"animationID");
    int targetInvincible    = getentityproperty(target, "invincible");
    void iType      = getentityproperty(target,"type");
    void iSubType    = getentityproperty(target,"subtype");
    int tX         = getentityproperty(target,"x");
    int tY         = getentityproperty(target,"y");
    int tZ         = getentityproperty(target,"z");
    int tBase     = getentityproperty(target,"base");
    int tDir         = getentityproperty(target,"direction");
    int xOffset = 40;
    if(tDir == 0){xOffset = -xOffset;}

    if(vAniID == openborconstant("ANI_FREESPECIAL4") ){
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

                    performattack(self, openborconstant("ANI_FOLLOW4"), 0);
                }
            }
        }
    }
}



void painLand()
{//Opponent forced do Land and change to Pain if hit in mid-air (KOF RYO DESPERATION STYLE)
    void self     = getlocalvar("self");

    if(!selfAlive()){return;}

    void target = getlocalvar("damagetaker");
    void eType    = getentityproperty(target,"type");
    void sType    = getentityproperty(target,"subtype");
    void vAniID = getentityproperty(self,"animationID");
    int frame    = getentityproperty(self,"animpos");
    int targetInvincible    = getentityproperty(target, "invincible");
    int Tx         = getentityproperty(target,"x");
    int Ty         = getentityproperty(target,"y");
    int Tz         = getentityproperty(target,"z");
    int tBase     = getentityproperty(target,"base");

    if(Ty > tBase && entityAlive(target) && targetInvincible == 0){
        if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")){
            if(vAniID == openborconstant("ANI_ATTACK1") || vAniID == openborconstant("ANI_FREESPECIAL")|| vAniID == openborconstant("ANI_FREESPECIAL4")){
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
            if(vAniID == openborconstant("ANI_FREESPECIAL")){performattack(self, openborconstant("ANI_FOLLOW1"), 0);}
        }
    }
}
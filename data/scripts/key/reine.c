#import "data/scripts/key/main.c"
#import "data/scripts/animation/main_grabs.c"

void main()
{
    if(getglobalvar("activeText") == 0){
        dodge();
        airRecovery();
        rageCancel();
        specialCancel();
        runCancel();
        counter();
        runAttack();
        whipGrab();
        extraButton();
        okBar();
        grabEscape();
        block();
        airCombo();
        onScreen();
    }
}

void rageCancel()
{
    void self      = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int maxMp     = getentityproperty(self,"maxMp");
    int mp         = getentityproperty(self,"mp");
    int costMp     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL"));
    float time     = openborvariant("elapsed_time");
    void target  = getentityproperty(self,"opponent");

    if(playerkeys(iPIndex, 0, "Movedown") && mp >= costMp && rush >= 1 && hits >= 1){
        if(playerkeys(iPIndex, 1, "special")){
            if(vAniID == openborconstant("ANI_ATTACK3")){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, time);
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, time);
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vAniID == openborconstant("ANI_SPECIAL2") && height == base){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, time);
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(target != NULL() && (vAniID == openborconstant("ANI_GRABATTACK")) && frame < 25){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, time);
                grabEnd();
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }


            if(target != NULL() && (vAniID == openborconstant("ANI_GRABFORWARD")) && frame < 4){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, time);
                grabEnd();
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }
        }
    }
}


void specialCancel()
{
    void self      = getlocalvar("self");
    void okBar     = getglobalvar("okBar"+self)*10;
    void target  = getentityproperty(self,"opponent");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int dir      = getentityproperty(self,"direction");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int tHeight     = getentityproperty(target,"y");
    int base     = getentityproperty(self,"base");
    int tBase     = getentityproperty(target,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int health     = getentityproperty(self,"health");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    int gp         = getentityproperty(self,"guardpoints");
    int gpCost    = maxGp/3;
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int cost2     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL6"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));

    if(playerkeys(iPIndex, 1, "attack")){
        float maxGp    = getentityproperty(self,"maxguardpoints");
        float gp         = getentityproperty(self,"guardpoints");
        float gpCost    = maxGp/3;

        if(vAniID == openborconstant("ANI_GRABATTACK")){
            if(gp >= gpCost && frame > 7 && frame < 31 && rush > 1 && hits > 1  && base == height){
                gpCost(gpCost);
                mpCost(-1);
                updateframe(self, 1);
            }
        }
    }


    if(playerkeys(iPIndex, 1, "special")){
        if(playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1){
            if((mPonly == 1 || mPonly == 0) && mp >= cost){
                if(vAniID == openborconstant("ANI_GRAB")){
                    mpCost(cost);
                    damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                }

                if(rush >= 1 && hits >= 1){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        mpCost(cost);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }

                    if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
                        mpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }
                }
            }
        }
        else if(playerkeys(iPIndex, 0, "MoveUp")){
            if((vAniID == openborconstant("ANI_IDLE") ||
                    vAniID == openborconstant("ANI_WALK") ||
                    vAniID == openborconstant("ANI_BACKWALK")||
                    vAniID == openborconstant("ANI_JUMPLAND")||
                    vAniID == openborconstant("ANI_RUN")) && mp >= cost && height == base){
                mpCost(cost2);
                changeentityproperty(self, "velocity", 0, 0, 0);
                performattack(self, openborconstant("ANI_FREESPECIAL6"), 0);
            }
            if((vAniID == openborconstant("ANI_ATTACK3") ||
                    vAniID == openborconstant("ANI_ATTACKBOTH") ||
                    vAniID == openborconstant("ANI_RUNATTACK")||
                    vAniID == openborconstant("ANI_SPECIAL2")) && rush >= 1 && hits >= 1 && mp >= cost && height == base){
                mpCost(cost2);
                changeentityproperty(self, "velocity", 0, 0, 0);
                performattack(self, openborconstant("ANI_FREESPECIAL6"), 0);
            }
        }
        else
        {
            if(rush >= 1 && hits >= 1){
                if((mPonly == 1 || mPonly == 0) && mp >= cost){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        mpCost(cost);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }

                    if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
                        mpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }
                }
            }
        }
    }
}

void runCancel()
{//Cancel defined moves with Running Attacks
    void self      = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int dir      = getentityproperty(self,"direction");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int maxMp     = getentityproperty(self,"maxMp");
    int mp         = getentityproperty(self,"mp");
    int costMp     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL2"));
    float time     = openborvariant("elapsed_time");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");

    if(vAniID == openborconstant("ANI_RUNATTACK") && rush >= 1 && hits >= 1 && height == base){
        if(playerkeys(iPIndex, 1, "Attack4")){
            performattack(self, openborconstant("ANI_ATTACK3"), 0);
        }
    }

    if(vAniID == openborconstant("ANI_ATTACK3")){
        if(getglobalvar("pressLeft"+iPIndex) > time || getglobalvar("pressRight"+iPIndex) > time){
            if(rush >= 1 && hits >= 1){
                //NORMAL RUNNING ATTACKS
                if(playerkeys(iPIndex, 1, "attack")){
                    setglobalvar("runCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_RUNATTACK"), 0);
                    setglobalvar("pressLeft"+iPIndex, NULL());
                    setglobalvar("pressRight"+iPIndex, NULL());
                }

                //SUPER RUNNING ATTACKS
                if(playerkeys(iPIndex, 1, "attack2") && mp >= costMp){
                    mpCost(costMp);
                    setglobalvar("runCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
                    setglobalvar("pressLeft"+iPIndex, NULL());
                    setglobalvar("pressRight"+iPIndex, NULL());
                }
            }
        }
    }
}

void airCombo()
{//Cancel defined moves with Offensive Jump Special (Special3)
    void self      = getlocalvar("self");
    void okBar     = getglobalvar("okBar"+self)*10;
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int dir         = getentityproperty(self,"direction");
    int health     = getentityproperty(self,"health");
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));
    int xDir        = getentityproperty(self,"xdir");
    int zDir        = getentityproperty(self,"zdir");
    int Vx            = 2;
    int Vy            = 2;
    float costRate = 0.5;

    if(dir == 0){Vx = -Vx;}

    if(playerkeys(iPIndex, 1, "special")){
        if((mPonly == 1 || mPonly == 0) && mp >= cost){
            if((vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")) && rush >= 1 && hits >= 1){
                mpCost(cost*costRate);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if((vAniID == openborconstant("ANI_JUMPATTACK") || vAniID == openborconstant("ANI_JUMPATTACK2") ||
                  vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")) && rush >= 1 && hits >= 1){
                mpCost(cost*costRate);
                tossentity(self, Vy, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if((vAniID == openborconstant("ANI_RUNATTACK")
       || vAniID == openborconstant("ANI_FOLLOW7"))
            && rush >= 1 && hits >= 1 && height > base){
                tossentity(self, Vy, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }
        }
    }

    if(playerkeys(iPIndex, 1, "Attack2")){
        if((vAniID == openborconstant("ANI_ATTACKBOTH")
         || vAniID == openborconstant("ANI_SPECIAL")
         || vAniID == openborconstant("ANI_ATTACK3")
         || vAniID == openborconstant("ANI_SPECIAL2")) && rush >= 1 && hits >= 1){
            tossentity(self, Vy+1, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if((vAniID == openborconstant("ANI_RUNATTACK")
            || vAniID == openborconstant("ANI_FOLLOW7")
            || vAniID == openborconstant("ANI_FOLLOW8"))
        && rush >= 1 && hits >= 1 && height > base){
            tossentity(self, Vy+1, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPATTACK3")
        && rush >= 1 && hits >= 1){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPATTACK")
        && rush >= 1 && hits >= 1){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK3"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

    }
}


void whipGrab()
{
    void self      = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int dir         = getentityproperty(self,"direction");
    void eButton = getglobalvar("extraButton");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    int gp         = getentityproperty(self,"guardpoints");
    int gpCost    = maxGp/3;

    if(playerkeys(iPIndex, 1, "attack4") && playerkeys(iPIndex, 0, "moveup")){
        if(    vAniID == openborconstant("ANI_IDLE")    ||
            vAniID == openborconstant("ANI_WALK")    ||
            vAniID == openborconstant("ANI_RUN")    ||
            vAniID == openborconstant("ANI_JUMPLAND")){
            if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK9")) == 1 && gp >= gpCost){
                gpCost(gpCost);
                setidle(self, openborconstant("ANI_IDLE"));
                changeentityproperty(self, "velocity", 0, 0, 0);
                performattack(self, openborconstant("ANI_ATTACK9"), 1);
            } else {
                changeentityproperty(self, "takeaction", "common_animation_normal");
                changeentityproperty(self, "combostep", 0);
                changeentityproperty(self, "aiflag", "running", 0);
                setidle(self, openborconstant("ANI_GUARDBREAK"), 1, 200);
            }
        }
    }
}

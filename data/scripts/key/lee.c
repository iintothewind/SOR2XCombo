#import "data/scripts/key/main.c"

void main()
{
    if(getglobalvar("activeText") == 0){
        // dodge();
        dodgeJump();
        airRecovery();
        rageCancel();
        upper();
        specialCancel();
        runCancel();
        airCombo();
        counter();
        runAttack();
        extraButton("ANI_ATTACK5");
        okBar();
        grabCancel();
        block();
        grabEscape();
        onScreen();
    }
}

void rageCancel()
{//Cancel defined moves with Rage Attacks
    void self      = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int maxMp     = getentityproperty(self,"maxMp");
    int mp         = getentityproperty(self,"mp");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int costMp     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL"));
    float time     = openborvariant("elapsed_time");

    if(playerkeys(iPIndex, 0, "Movedown") && mp >= costMp && rush >= 1 && hits >= 1 && height == base){
        if(playerkeys(iPIndex, 1, "special")){
            if(vAniID == openborconstant("ANI_ATTACK5") || vAniID == openborconstant("ANI_FOLLOW7")){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vAniID == openborconstant("ANI_RUNATTACK")){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }
        }
    }

    if(playerkeys(iPIndex, 0, "Moveup") && mp >= costMp && rush >= 1 && hits >= 1){
        if(playerkeys(iPIndex, 1, "special")){
            if(vAniID == openborconstant("ANI_ATTACK5") || vAniID == openborconstant("ANI_FOLLOW7")){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL4"), 0);
            }

            if(vAniID == openborconstant("ANI_RUNATTACK")){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL4"), 0);
            }
        }
    }
}


void specialCancel()
{//Cancel defined moves with Special Attacks
    void self      = getlocalvar("self");
    void okBar     = getglobalvar("okBar"+self)*10;
    void target  = getentityproperty(self,"opponent");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int dir      = getentityproperty(self,"direction");
    int frame    = getentityproperty(self,"animpos");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int health     = getentityproperty(self,"health");
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));
    int xDir        = getentityproperty(self,"xdir");
    int Vx            = 3;
    int Vy            = 1;

    if(dir == 0){Vx = -Vx;}

    if(playerkeys(iPIndex, 1, "special")){
        if(playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1){
            if(vAniID == openborconstant("ANI_GRAB")){
                damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                tossentity(target, Vy, Vx, 0);
                performattack(self, openborconstant("ANI_SPECIAL2"), 0);
            }

            if(rush >= 1 && hits >= 1){
                if(vAniID == openborconstant("ANI_ATTACK5") && height == base){
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FOLLOW20"), 0);
                }

                if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FOLLOW20"), 0);
                }

                if(vAniID == openborconstant("ANI_SPECIAL") && height == base){
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FOLLOW20"), 0);
                }

                if(vAniID == openborconstant("ANI_FOLLOW7") && height == base){
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FOLLOW20"), 0);
                }
            }
        }
    }

    if(playerkeys(iPIndex, 1, "attack4")){
        int maxGp    = getentityproperty(self,"maxguardpoints");
        int gp         = getentityproperty(self,"guardpoints");
        int gpCost    = maxGp/3;
        if(playerkeys(iPIndex, 0, "Moveup"))
        {
            if(rush >= 1 && hits >= 1 && gp >= gpCost){
                if(vAniID == openborconstant("ANI_GRAB")){
                    gpCost(cost);
                    damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
                }
                if(vAniID == openborconstant("ANI_ATTACK5")
                || vAniID == openborconstant("ANI_SPECIAL")
                || vAniID == openborconstant("ANI_SPECIAL2")){
                    gpCost(gpCost);
                    changeentityproperty(self, "velocity", 0, 0, 0);
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
                }

                if(vAniID == openborconstant("ANI_RUNATTACK") && height == base) {
                    gpCost(gpCost);
                    setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                    performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
                }
            }
        }
    }
}

void upper()
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
            if(getentityproperty(self, "animvalid", openborconstant("ANI_FREESPECIAL3")) == 1 && gp >= gpCost){
                gpCost(gpCost);
                setidle(self, openborconstant("ANI_IDLE"));
                changeentityproperty(self, "velocity", 0, 0, 0);
                performattack(self, openborconstant("ANI_FREESPECIAL3"), 1);
            } else {
                changeentityproperty(self, "takeaction", "common_animation_normal");
                changeentityproperty(self, "combostep", 0);
                changeentityproperty(self, "aiflag", "running", 0);
                setidle(self, openborconstant("ANI_GUARDBREAK"), 1, 200);
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
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL"));
    float time     = openborvariant("elapsed_time");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");

    if(vAniID == openborconstant("ANI_RUNATTACK") && rush >= 1 && hits >= 1 && height == base){
        if(playerkeys(iPIndex, 1, "Attack4")){
            performattack(self, openborconstant("ANI_ATTACK5"), 0);
        }
    }

    if(vAniID == openborconstant("ANI_ATTACK4")){

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
{
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
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL3"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_FREESPECIAL3"));
    int maxGp    = getentityproperty(self,"maxguardpoints");
    int gp         = getentityproperty(self,"guardpoints");
    int gpCost    = maxGp/3;
    int xDir        = getentityproperty(self,"xdir");
    int zDir        = getentityproperty(self,"zdir");
    int Vx            = 1.5;
    int Vy            = 2;
    float costRate = 0.75;

    if(dir == 0){Vx = -Vx;}

    if(playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "movedown")){
        if((vAniID == openborconstant("ANI_JUMP")
        || vAniID == openborconstant("ANI_FOLLOW1")
        || vAniID == openborconstant("ANI_WALKOFF")) && rush >= 1){
            mpCost(cost*costRate);
            performattack(self, openborconstant("ANI_FOLLOW8"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if((vAniID == openborconstant("ANI_JUMPATTACK")
        || vAniID == openborconstant("ANI_JUMPATTACK2")
        || vAniID == openborconstant("ANI_JUMPATTACK3")
        || vAniID == openborconstant("ANI_JUMPFORWARD")) && rush >= 1 && hits >= 1){
            mpCost(cost*costRate);
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FOLLOW8"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if((vAniID == openborconstant("ANI_SPECIAL2") || vAniID == openborconstant("ANI_FOLLOW7"))
        && rush >= 1 && hits >= 1 && height > base){
            mpCost(cost*costRate);
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FOLLOW8"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_FOLLOW8") && rush >= 1 && hits >= 1 && height > base){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FOLLOW21"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if((vAniID == openborconstant("ANI_FOLLOW21"))
        && rush >= 1 && hits >= 1 && height > base){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FOLLOW22"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }
    }

    if(playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "moveup")){
        if((vAniID == openborconstant("ANI_SPECIAL2")
         || vAniID == openborconstant("ANI_ATTACK5")
         || vAniID == openborconstant("ANI_FOLLOW7")
         || vAniID == openborconstant("ANI_FOLLOW8")
         || vAniID == openborconstant("ANI_FOLLOW21")
         || vAniID == openborconstant("ANI_JUMPATTACK")
         || vAniID == openborconstant("ANI_JUMPFORWARD")
         || vAniID == openborconstant("ANI_FOLLOW22"))
        && rush >= 1 && hits >= 1 && height > base){
            gpCost(gpCost);
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_GRABDOWN") && rush >= 1 && hits >= 1 && height > base && frame > 8){
            gpCost(gpCost);
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }
    }

    if(playerkeys(iPIndex, 1, "special") && (playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1)){

    }

    if(playerkeys(iPIndex, 1, "Attack2")){
        if((vAniID == openborconstant("ANI_ATTACKBOTH")
         || vAniID == openborconstant("ANI_RUNATTACK")
         || vAniID == openborconstant("ANI_ATTACK5")) && rush >= 1 && hits >= 1){
            tossentity(self, Vy, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_GRABUP") && rush >= 1 && hits >= 1 && height > base){
            tossentity(self, Vy, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }


        if((vAniID == openborconstant("ANI_SPECIAL2")
         || vAniID == openborconstant("ANI_FOLLOW7")
         || vAniID == openborconstant("ANI_FOLLOW8")
         || vAniID == openborconstant("ANI_FOLLOW21")
         || vAniID == openborconstant("ANI_FOLLOW22")
         || vAniID == openborconstant("ANI_FREESPECIAL3"))
        && rush >= 1 && hits >= 1 && height > base){
            tossentity(self, Vy, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPATTACK") && rush >= 1 && hits >= 1){
            tossentity(self, Vy+0.5, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPFORWARD") && rush >= 1 && hits >= 1){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }
    }
}

void grabCancel()
{//Cancel Grab Jump with throw or pile
    void self     = getlocalvar("self");
    void vAniID = getentityproperty(self,"animationID");
    int iPIndex = getlocalvar("player");
    int frame    = getentityproperty(self,"animpos");

    if(playerkeys(iPIndex, 1, "attack")){
        if(vAniID == openborconstant("ANI_GRABATTACK2") && frame > 0 && frame < 5){
            performattack(self, openborconstant("ANI_GRABUP"), 0);
        }
        if(playerkeys(iPIndex, 0, "movedown") && vAniID == openborconstant("ANI_GRABUP") && frame > 4 && frame < 9){
            performattack(self, openborconstant("ANI_JUMPATTACK2"), 0);
        }
    }
}
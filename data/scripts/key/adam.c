#import "data/scripts/key/main.c"

void main()
{
    if(getglobalvar("activeText") == 0){
        dodge();
        airRecovery();
        rageCancel();
        specialCancel();
        airCombo();
        runCancel();
        counter();
        runAttack();
        chargeAttack();
        extraButton();
        okBar();
        vault();
        grabEscape();
        block();
        onScreen();
    }
}

void rageCancel()
{//Cancel defined moves with Rage Attacks
    void self      = getlocalvar("self");
    void vModel    = getentityproperty(self,"model");
    void vAniID  = getentityproperty(self,"animationID");
    int iPIndex  = getlocalvar("player");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int maxMp     = getentityproperty(self,"maxMp");
    int mp         = getentityproperty(self,"mp");
    int costMp     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL"));
    int costMp2     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL3"));
    float time     = openborvariant("elapsed_time");

    if(playerkeys(iPIndex, 0, "Movedown") && mp >= costMp && rush >= 1 && hits >= 1){
        if(playerkeys(iPIndex, 1, "special")){
            if(vAniID == openborconstant("ANI_ATTACK3")){
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

            if(vAniID == openborconstant("ANI_SPECIAL2")
            || vAniID == openborconstant("ANI_FREESPECIAL20")){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vModel == "Adam_Sword" && vAniID == openborconstant("ANI_ATTACK1")){
                mpCost(costMp/3);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }
        }
    }

    if(playerkeys(iPIndex, 0, "MoveUp") && mp >= costMp && rush >= 1 && hits >= 1){
        if(playerkeys(iPIndex, 1, "special")){
            if(vAniID == openborconstant("ANI_ATTACK3")){
                mpCost(costMp2);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
            }

            if(vAniID == openborconstant("ANI_RUNATTACK")){
                mpCost(costMp2);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
            }

            if(vAniID == openborconstant("ANI_SPECIAL2")
            || vAniID == openborconstant("ANI_FREESPECIAL20")){
                mpCost(costMp2);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
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
    void model     = getentityproperty(self, "model");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int health     = getentityproperty(self,"health");
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));

    if(playerkeys(iPIndex, 1, "attack")){
        float maxGp    = getentityproperty(self,"maxguardpoints");
        float gp         = getentityproperty(self,"guardpoints");
        float gpCostAmt    = maxGp/3;

        if(vAniID == openborconstant("ANI_SPECIAL2")){
            if(gp >= gpCostAmt && frame > 8 && frame < 15 && rush > 1 && hits > 1 && base == height){
                    gpCost(gpCostAmt);
                    mpCost(-3);
                    performattack(self, openborconstant("ANI_FREESPECIAL20"), 0);
            }
        }

        if(vAniID == openborconstant("ANI_FREESPECIAL20")){
            if(gp >= gpCostAmt && frame > 5 && frame < 14 && rush > 1 && hits > 3  && base == height){
                    gpCost(gpCostAmt);
                    mpCost(-3);
                    updateframe(self, 0);
            }
        }

        if(vAniID == openborconstant("ANI_FREESPECIAL") && model == "Adam_Sword"){
            if(mp > 0 && frame > 21 && frame < 30 && rush > 1 && hits > 5  && base == height){
                mpCost(2);
                updateframe(self, 12);
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

                    if(vAniID == openborconstant("ANI_RUNATTACK")){
                        mpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }
                }
            }
        }
        else
        {
            if(rush >= 1 && hits >= 1){
                if((mPonly == 1 || mPonly == 0) && mp >= cost){
                    if(vAniID == openborconstant("ANI_RUNATTACK")){
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

void airCombo()
{//Cancel defined moves with Offensive Jump Special (Special3)
    void self      = getlocalvar("self");
    void okBar     = getglobalvar("okBar"+self)*10;
    void vAniID  = getentityproperty(self,"animationID");
    int frame    = getentityproperty(self,"animpos");
    int iPIndex  = getlocalvar("player");
    int height        = getentityproperty(self,"y");
    int base        = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int dir         = getentityproperty(self,"direction");
    int health     = getentityproperty(self,"health");
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));
    int xDir     = getentityproperty(self,"xdir");
    int zDir     = getentityproperty(self,"zdir");
    int Vx         = 1.7;
    int Vy         = 2.5;
    float costRate = 0.5;

    if(dir == 0){Vx = -Vx;}

    if(playerkeys(iPIndex, 1, "special") && height > base){
        if((mPonly == 1 || mPonly == 0) && mp >= cost){
            if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")){
                mpCost(cost*costRate);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK") || vAniID == openborconstant("ANI_JUMPATTACK2") ||
                vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")){
                mpCost(cost*costRate);
                tossentity(self, Vy-1, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }
        }
        else if((mPonly == 2 || mPonly == 0) && health > cost){
            if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")){
                hpCost(cost*costRate);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK") || vAniID == openborconstant("ANI_JUMPATTACK2") ||
                vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")){
                hpCost(cost*costRate);
                tossentity(self, Vy-1, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }
        }
        else if(okBar >= cost){
            if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")){
                setglobalvar("noRecover"+self, 1);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK") || vAniID == openborconstant("ANI_JUMPATTACK2") ||
                vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")){
                setglobalvar("noRecover"+self, 1);
                tossentity(self, Vy-1, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }
        }
    }

    if(playerkeys(iPIndex, 1, "Attack2")){
        if((vAniID == openborconstant("ANI_RUNATTACK")
         || vAniID == openborconstant("ANI_ATTACK2")
         || vAniID == openborconstant("ANI_FOLLOW7")
         || vAniID == openborconstant("ANI_SPECIAL")
         || vAniID == openborconstant("ANI_SPECIAL2")
         || vAniID == openborconstant("ANI_FREESPECIAL20")
         || vAniID == openborconstant("ANI_ATTACK3")) && rush >= 1 && hits >= 1){
            tossentity(self, Vy, Vx, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_FOLLOW8") && rush >= 1 && hits >= 1){
            tossentity(self, Vy-1, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPATTACK") && rush >= 1 && hits >= 1){
            tossentity(self, 2, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPFORWARD") && rush >= 1 && hits >= 1){
            tossentity(self, 2, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
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

void vault()
{//Choose action during or after vault
    void self     = getlocalvar("self");
    void target = getentityproperty(self,"grabbing");
    void vAniID = getentityproperty(self,"animationID");
    int iPIndex = getlocalvar("player");
    int frame    = getentityproperty(self,"animpos");
    int health    = getentityproperty(self,"health");
    int mp        = getentityproperty(self,"mp");
    int cost    = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL"));
    int mPonly    = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL"));

    if(vAniID == openborconstant("ANI_GRABATTACK2") && frame >= 6){
        if(playerkeys(iPIndex, 1, "attack")){
            performattack(self, openborconstant("ANI_GRABDOWN2"), 0);
        }
        else
        if(playerkeys(iPIndex, 1, "special")){
            if((mPonly == 1 || mPonly == 0) && mp >= cost){
                mpCost(cost);
                performattack(self, openborconstant("ANI_SPECIAL"), 0);
            }
            else if((mPonly == 2 || mPonly == 0) && health > cost){
                hpCost(cost);
                performattack(self, openborconstant("ANI_SPECIAL"), 0);
            }
        }
        else
        if(playerkeys(iPIndex, 1, "jump")){
            performattack(self, openborconstant("ANI_GRABUP2"), 0);
        }
        else
        if(playerkeys(iPIndex, 0, "moveleft") || playerkeys(iPIndex, 0, "moveright")){
            damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL"));
            setidle(self);
        }
    }
}
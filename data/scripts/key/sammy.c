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
    void target  = getentityproperty(self,"opponent");
    int dist     = 0;
    float time     = openborvariant("elapsed_time");

    if((playerkeys(iPIndex, 0, "Moveup") || playerkeys(iPIndex, 0, "Movedown")) && mp >= costMp && rush >= 1 && hits >= 1){
        if(playerkeys(iPIndex, 1, "special")){

            if(target != NULL() && (vAniID == openborconstant("ANI_GRABFORWARD") || vAniID == openborconstant("ANI_GRABFORWARD2")) && frame < 5){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, time);
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vAniID == openborconstant("ANI_ATTACK3")){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            if(vAniID == openborconstant("ANI_RUNATTACK") && height > base+dist){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }

            if(vAniID == openborconstant("ANI_SPECIAL2")){
                mpCost(costMp);
                changeentityproperty(self, "velocity", 0, 0, 0);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
            }

            // if(vAniID == openborconstant("ANI_FOLLOW8")){
            //     mpCost(costMp);
            //     changeentityproperty(self, "velocity", 0, 0, 0);
            //     setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
            //     performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            // }

            if(vAniID == openborconstant("ANI_JUMPATTACK") && height > base+dist){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK2") && height > base+dist){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK3") && height > base+dist){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }

            if(vAniID == openborconstant("ANI_JUMPFORWARD") && height > base+dist){
                mpCost(costMp);
                setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }

            if(vAniID == openborconstant("ANI_JUMP") && height > base+dist){
                mpCost(costMp);
                performattack(self, openborconstant("ANI_FOLLOW3"), 0);
            }
        }
    }
}

void specialCancel()
{//Cancel defined moves with Special Attacks
    void self      = getlocalvar("self");
    void okBar     = getglobalvar("okBar"+self)*10;
    void target  = getentityproperty(self,"opponent");
    int iPIndex  = getlocalvar("player");
    void vModel     = getentityproperty(self,"model");
    int frame    = getentityproperty(self,"animpos");
    void vAniID  = getentityproperty(self,"animationID");
    int dir      = getentityproperty(self,"direction");
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

        if(vAniID == openborconstant("ANI_GRABATTACK")){
            if(gp >= gpCostAmt && frame > 6 && frame < 23 && rush > 1 && hits > 5  && base == height){
                gpCost(gpCostAmt);
                mpCost(-1);
                updateframe(self, 2);
            }
        }

        if(vAniID == openborconstant("ANI_SPECIAL2") && vModel != "Sammy_Pipe"){
            if(mp > 0 && frame > 10 && frame < 31 && rush > 1 && hits > 8  && base == height){
                mpCost(2);
                updateframe(self, 1);
            }
        }

        if(vAniID == openborconstant("ANI_SPECIAL2") && vModel == "Sammy_Pipe"){
            if(mp > 0  && frame > 2 && frame < 10 && rush > 1 && hits > 2  && base == height){
                mpCost(2);
                performattack(self, openborconstant("ANI_FOLLOW20"), 0);
            }
        }

        if(vAniID == openborconstant("ANI_FOLLOW20") && vModel == "Sammy_Pipe"){
            if(mp > 0  && frame > 0 && frame < 39 && rush > 1 && hits > 4  && base == height){
                mpCost(2);
                updateframe(self, 0);
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

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        mpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }
                }
            }
            else if((mPonly == 2 || mPonly == 0) && health > cost){
                if(vAniID == openborconstant("ANI_GRAB")){
                    hpCost(cost);
                    damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                }

                if(rush >= 1 && hits >= 1){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        hpCost(cost);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        hpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }
                }
            }
            else if(okBar >= cost){
                if(vAniID == openborconstant("ANI_GRAB")){
                    setglobalvar("noRecover"+self, 1);
                    damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
                    performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                }

                if(rush >= 1 && hits >= 1){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        setglobalvar("noRecover"+self, 1);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL2"), 0);
                    }

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("noRecover"+self, 1);
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
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        mpCost(cost);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        mpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }
                }
                else if((mPonly == 2 || mPonly == 0) && health > cost){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        hpCost(cost);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        hpCost(cost);
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }
                }
                else if(okBar >= cost){
                    if(vAniID == openborconstant("ANI_ATTACK3")){
                        setglobalvar("noRecover"+self, 1);
                        setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                        performattack(self, openborconstant("ANI_SPECIAL"), 0);
                    }

                    if(vAniID == openborconstant("ANI_FREESPECIAL2")){
                        changeentityproperty(self, "velocity", 0, 0, 0);
                        setglobalvar("noRecover"+self, 1);
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
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    int rush     = getentityproperty(self,"rush_count");
    int hits     = getentityproperty(self,"animhits");
    int health     = getentityproperty(self,"health");
    int mp         = getentityproperty(self,"mp");
    int cost     = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL2"));
    int mPonly     = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL2"));
    int dir            = getentityproperty(self,"direction");
    int xDir     = getentityproperty(self,"xdir");
    int zDir     = getentityproperty(self,"zdir");
    int Vx         = 1.7;
    int Vy         = 3;
    float costRate = 0.5;

    if(dir == 0){Vx = -Vx;}

    // if(playerkeys(iPIndex, 1, "special")){
    if(playerkeys(iPIndex, 1, "special") && (playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1)){
        if((mPonly == 1 || mPonly == 0) && mp >= cost){
            if(vAniID == openborconstant("ANI_RUNATTACK") && rush >= 1 && hits >= 1 && height > base){
                mpCost(cost*costRate);
                tossentity(self, Vy, xDir/2, zDir);
                setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")){
                mpCost(cost*costRate);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }

            if(vAniID == openborconstant("ANI_JUMPATTACK") || vAniID == openborconstant("ANI_JUMPATTACK2") ||
                vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")){
                mpCost(cost*costRate);
                tossentity(self, Vy, xDir, zDir);
                performattack(self, openborconstant("ANI_FOLLOW8"), 0);
                changeentityproperty(self, "aiflag", "jumping", 1);
                changeentityproperty(self, "takeaction", "common_jump");
            }
        }
    }

    if(playerkeys(iPIndex, 1, "Attack2")){
        if((vAniID == openborconstant("ANI_RUNATTACK") ||vAniID == openborconstant("ANI_SPECIAL")||
            vAniID == openborconstant("ANI_SPECIAL2") ||vAniID == openborconstant("ANI_FREESPECIAL2") ||
              vAniID == openborconstant("ANI_ATTACK3") || vAniID == openborconstant("ANI_FOLLOW7")) && rush >= 1 && hits >= 1){
            tossentity(self, Vy, Vx*0.75, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPATTACK3") && rush >= 1 && hits >= 1){
            tossentity(self, Vy, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPFORWARD"), 0);
            changeentityproperty(self, "aiflag", "jumping", 1);
            changeentityproperty(self, "takeaction", "common_jump");
        }

        if(vAniID == openborconstant("ANI_JUMPFORWARD") && rush >= 1 && hits >= 1){
            tossentity(self, Vy-1, xDir, zDir);
            performattack(self, openborconstant("ANI_JUMPATTACK3"), 0);
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
    int costMp     = maxMp/3;
    float time     = openborvariant("elapsed_time");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");

    if(vAniID == openborconstant("ANI_RUNATTACK") && rush >= 1 && hits >= 1){
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

    if(vAniID == openborconstant("ANI_GRABATTACK2")){
        if(playerkeys(iPIndex, 1, "attack")){
            if(frame >= 1 && frame <= 3){
                performattack(self, openborconstant("ANI_GRABBACKWARD2"), 1);
            }
            if(frame >= 6){
                performattack(self, openborconstant("ANI_GRABDOWN2"), 0);
            }
        }
        else
        if(playerkeys(iPIndex, 1, "special")){
            if((mPonly == 1 || mPonly == 0) && mp >= cost){
                if(frame >= 6){
                    mpCost(cost);
                    performattack(self, openborconstant("ANI_SPECIAL"), 0);
                }
            }
            else if((mPonly == 2 || mPonly == 0) && health > cost){
                if(frame >= 6){
                    hpCost(cost);
                    performattack(self, openborconstant("ANI_SPECIAL"), 0);
                }
            }
        }
        else
        if(playerkeys(iPIndex, 1, "jump")){
            if(frame >= 6){
                performattack(self, openborconstant("ANI_GRABUP2"), 0);
            }
        }
        else
        if(playerkeys(iPIndex, 0, "moveleft") || playerkeys(iPIndex, 0, "moveright")){
            if(frame >= 6){
                damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL"));
                setidle(self);
            }
        }
    }
    else
    if(vAniID == openborconstant("ANI_GRABUP2")){
        if(playerkeys(iPIndex, 1, "attack")){
            if(frame >= 1 && frame <= 3){
                performattack(self, openborconstant("ANI_DUCKATTACK"), 0);
            }
        }
    }
}
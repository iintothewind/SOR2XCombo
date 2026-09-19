void jumpBack(int jetType)
{//Jump back to the ground when fall in any hole if current health is higher than 1/4 of max health, same as original SOR3
 //The "jetType" flag is used to identify characters that has a jetpack and are always flying, avoid some actions
    void self     = getlocalvar("self");
    void target     = getentityvar(self,"grabbed");
    void branch  = openborvariant("current_branch");
    void type      = getentityproperty(self,"type");
    void sType      = getentityproperty(self,"subtype");
    int mHealth     = getentityproperty(self, "maxhealth");
    int health     = getentityproperty(self, "health");
    int x         = getentityproperty(self, "x");
    int y         = getentityproperty(self, "y");
    int z         = getentityproperty(self, "z");
    int jumping     = getentityproperty(self, "aiflag", "jumping");
    int falling     = getentityproperty(self, "aiflag", "falling");
    int damage     = mHealth/4; //DAMAGE IS ALWAYS 1/4 OF MAX THE HEALTH
    int xDir      = getentityproperty(self, "xdir");
    int vDir      = getentityproperty(self, "direction");
    int dir;
    float hole     = checkhole(x, z, y);
    float yLimit = -100; //HEIGHT LIMIT WHEN FALLING IN ANY HOLE
    float xPos;
    float zPos;
    float xVel;
    float yVel;
    float zVel;

    if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC") && sType != openborconstant("SUBTYPE_NOTGRAB")){ //WORKS FOR PLAYERS AND NPCS ONLY

        //USED TO RESET THE VARIABLE IF THE PLAYER IS ON THE GROUND
        if(y >= 0 && getlocalvar("inhole"+self) != NULL()){setlocalvar("inhole"+self, NULL());}

        //USED TO MAKE THE PLAYER JUMP BACK TO THE GROUND, GET OFF OF THE HOLE
        if(y < yLimit && getlocalvar("inhole"+self) != 1){ //PLAYER IS FALLING ABOVE THE GROUND TOO MUCH?? CERTAINLY IS A HOLE :D
            if(health > damage){ //HAS ENOUGH HEALTH TO REMAIN ALIVE??

                //SOR2 STAGE 1A, MANHOLE 1, MANHOLE 2
                //SOR3 STAGE 3A, HOLE 1, HOLE 2
                xPos = x;
                zPos = z;
                xVel = 0;
                yVel = 5;
                zVel = -3;
                dir     = vDir;

                //SOR3 STAGE 3A, HOLE 3, LAST LARGE HOLE AT THE END OF THE LEVEL
                if(branch == "sor3_st3a" && x > 1700){
                    xPos = 1650;
                    zPos = 170;
                    xVel = -2;
                    zVel = 0;
                    dir     = 0;
                }

                //SOR3 STAGE 3C, THE ONLY HOLE AT THE LEFT SIDE OF THE LEVEL
                if(branch == "sor3_st3c"){
                    xPos = 150;
                    zPos = 170;
                    xVel = -2;
                    zVel = 0;
                    dir     = 0;
                }

                if(branch == "sor1_st07"){
                    xPos = 300;
                    zPos = 270;
                    xVel = -3;
                    zVel = 0;
                    dir     = 0;
                }

                //SET FLAG TO STOP PLAYER HEALTH RESTORATION, USED IN SPECIAL/SPECIAL2/SPECIAL3 MOVES (SPECIAL COST "LIFE" ONLY)
                if(getglobalvar("addLife"+self) != 0){setglobalvar("addLife"+self, 0);}

                //RUN ALL TASKS
                changeentityproperty(self, "health", health-damage); //SUBTRACT HEALTH
                changeentityproperty(self, "position", xPos, zPos, NULL()); //CHANGE POSITION
                changeentityproperty(self, "direction", dir); //CHANGE DIRECTION
                changeentityproperty(self, "animation", openborconstant("ANI_LAND")); //CHANGE ANIMATION
                tossentity(self, yVel, xVel, zVel); //TOSS THE PLAYER OFF OF THE HOLE
                setlocalvar("inhole"+self, 1); //CHANGE VARIABLE FLAG TO RUN ONCE
            }
        }

        //USED TO SLOW CHARACTER MOVEMENT WHEN A HOLE IS DETECTED, USED TO AVOID ENGINE BUG THAT FALL IN THE HOLE TOO LATE IF SPEED IS HIGH
        if(hole && y <= 0){ //A HOLE IS DETECTED ON THE GROUND??
            if(branch == "sor1_st07" || branch == "sor2_st1a" || branch == "sor3_st3a" || branch == "sor3_st3c"){ //IN THESE LEVELS??

                //CHANGE VELOCITY TO ZERO IF THE CHARACTER IS FALLING IN THE HOLE AT Z AXIS, OTHERWISE, DEFINE X VELOCITY
                if(xDir > 0){    xVel = 0.7;}else
                if(xDir < 0){    xVel = -0.7;}else
                if(xDir == 0){    xVel = 0;}

                //RUN ALL TASKS
                if(target != NULL()){ //USED TO UNBIND THE OPPONENT IF FALLING IN ANY HOLE, LIKE THE "GRABEND" SCRIPT
                    changeentityproperty(target,"damage_on_landing",0);
                    changeentityproperty(target,"aiflag","falling",0);
                    changeentityproperty(target,"aiflag","drop",0);
                    changeentityproperty(target,"aiflag","projectile",0);
                    changeentityproperty(target,"aiflag","frozen", 0); //USED TO AVOID GRAB INTERRUPTION WHEN THE NODROPEN IS OFF AND ANY PLAYER IS RESPAWNED
                    changeentityproperty(target,"takeaction", "common_animation_normal");
                    changeentityproperty(target, "velocity", xVel);
                    bindentity(target, NULL());
                    setidle(target);
                    setentityvar(self, "grabbed", NULL());
                }

                //IF IS NOT FALLING OR JUMPING, RESET TO IDLE STATUS
                if(falling != 1){if(jumping != 1){if(jetType != 1){setidle(self);}}}

                //CHANGE X VELOCITY
                changeentityproperty(self, "velocity", xVel);
            }
        }
    }
}

void safeLanding()
{//Cancel Player throw or slam fall if defined button is pressed (ALL PLAYABLE CHARACTERS)
    void self    = getlocalvar("self");
    void type     = getentityproperty(self,"type");
    void ani     = getentityproperty(self,"animationID");
    void name     = getentityproperty(self,"defaultname");
    int pIndex     = getentityproperty(self,"playerindex");
    int frame    = getentityproperty(self,"animpos");
    int health     = getentityproperty(self,"health");

    if(getglobalvar("activeText") == 0){
        if(playerkeys(pIndex, 0, "jump") && playerkeys(pIndex, 0, "moveup")){
            if(type == openborconstant("TYPE_PLAYER")){
                if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9")){
                    if(frame == 1){
                        if(health >= 1){
                            executeanimation(self, openborconstant("ANI_LAND"), 1);
                        }
                    }
                }

                //USED FOR JET CHARACTERS ONLY
                if(name == "Jet" || name == "Jet_"){
                    if(ani == openborconstant("ANI_FALL")){
                        if(frame == 1){
                            if(health >= 1){
                                executeanimation(self, openborconstant("ANI_LAND"), 1);
                            }
                        }
                    }
                }
            }
        }
    }
}

void windForce()
{//Simulates the "wind" force effect in the SOR3 stage3
    void self    = getlocalvar("self");
    void branch    = openborvariant("current_branch");
    int xDir     = getentityproperty(self, "xdir");
    float wind    = getglobalvar("windForce");
    float time    = openborvariant("elapsed_time");

    if(branch == "sor3_st3a"){
        if(wind != 0){
            changeentityproperty(self, "velocity", xDir+wind);
        }
    }
    else
    {
        if(wind != NULL()){setglobalvar("windForce", NULL());}
    }
}

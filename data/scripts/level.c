#import "data/scripts/levelspawn/main_musicstage.c"
#import "data/scripts/levelspawn/main_level.c"

void main()
{
    musicStage();
    changeLives();
    adjustCredits();
    resetScore();
    resetGas();
    resetLevel();
    resetOk();
    resetParry();
    resetArmor();
    noJoin();
    koVar();
    loadAllMp();
    loadPartner();
    loadMaxRush();
    initLifeCost();
}

void changeLives()
{//Change lives according to global variable "lives" check
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");

    if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2 || openborvariant("current_set") == 3){ //ARCADE/REBELLION MODES, CHANGE LIVES
        if(openborvariant("current_branch") == "route"){
            if(player1 != NULL()){
                if(getglobalvar("partnerIndex") == 0 && getglobalvar("currentPartner") != NULL()){
                    changeplayerproperty(0, "lives", getglobalvar("lives")-1);
                }else{
                    changeplayerproperty(0, "lives", getglobalvar("lives"));
                }
            }
            if(player2 != NULL()){
                if(getglobalvar("partnerIndex") == 1 && getglobalvar("currentPartner") != NULL()){
                    changeplayerproperty(1, "lives", getglobalvar("lives")-1);
                }else{
                    changeplayerproperty(1, "lives", getglobalvar("lives"));
                }
            }
            if(player3 != NULL()){
                if(getglobalvar("partnerIndex") == 2 && getglobalvar("currentPartner") != NULL()){
                    changeplayerproperty(2, "lives", getglobalvar("lives")-1);
                }else{
                    changeplayerproperty(2, "lives", getglobalvar("lives"));
                }
            }
            if(player4 != NULL()){
                if(getglobalvar("partnerIndex") == 3 && getglobalvar("currentPartner") != NULL()){
                    changeplayerproperty(3, "lives", getglobalvar("lives")-1);
                }else{
                    changeplayerproperty(3, "lives", getglobalvar("lives"));
                }
            }
        }
    }

    if((openborvariant("current_set") == 0 && getglobalvar("lives")== 1) || openborvariant("current_set") == 1 || openborvariant("current_set") == 3){
        if(player1 != NULL()){changeplayerproperty(0, "lives", 1);}
        if(player2 != NULL()){changeplayerproperty(1, "lives", 1);}
        if(player3 != NULL()){changeplayerproperty(2, "lives", 1);}
        if(player4 != NULL()){changeplayerproperty(3, "lives", 1);}
    }
}

void initLifeCost() {
    if(getglobalvar("lifeCost0") == NULL()) {
        setglobalvar("lifeCost0", 1);
    }
    if(getglobalvar("lifeCost1") == NULL()) {
        setglobalvar("lifeCost1", 1);
    }
    if(getglobalvar("lifeCost2") == NULL()) {
        setglobalvar("lifeCost2", 1);
    }
    if(getglobalvar("lifeCost3") == NULL()) {
        setglobalvar("lifeCost3", 1);
    }
}

void adjustCredits()
{//Adjust credits to avoid bug that add random credits in Survival and Syndicate modes
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    int cred1     = getplayerproperty(0, "credits");
    int cred2     = getplayerproperty(1, "credits");
    int cred3     = getplayerproperty(2, "credits");
    int cred4     = getplayerproperty(3, "credits");

    if((openborvariant("current_set") == 0 && getglobalvar("lives")== 1) || openborvariant("current_set") == 1){
        if(cred1 > 0){changeplayerproperty(0, "credits", 0);}
        if(cred2 > 0){changeplayerproperty(1, "credits", 0);}
        if(cred3 > 0){changeplayerproperty(2, "credits", 0);}
        if(cred4 > 0){changeplayerproperty(3, "credits", 0);}
    }
    if(openborvariant("current_set") == 3){
        if(cred1 > 0){changeplayerproperty(0, "credits", 99);}
        if(cred2 > 0){changeplayerproperty(1, "credits", 99);}
        if(cred3 > 0){changeplayerproperty(2, "credits", 99);}
        if(cred4 > 0){changeplayerproperty(3, "credits", 99);}
    }
}

void resetScore()
{//Reset score for all players to avoid "skipselect" bug that memorizes score even the game is finished and restarted

    if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2){
        if(openborvariant("current_branch") == "route"){
            changeplayerproperty(0, "score", 0);
            changeplayerproperty(1, "score", 0);
            changeplayerproperty(2, "score", 0);
            changeplayerproperty(3, "score", 0);
        }
    }

    if(openborvariant("current_set") == 1){
        if(openborvariant("current_branch") == "survival_a" || openborvariant("current_branch") == "survival_b" || openborvariant("current_branch") == "survival_c1"){
            changeplayerproperty(0, "score", 0);
            changeplayerproperty(1, "score", 0);
            changeplayerproperty(2, "score", 0);
            changeplayerproperty(3, "score", 0);
        }
    }
}

void resetGas()
{//Clear Toxic Gas Countdown and Door Locks to not affect other scripts (SOR3_ST6A/GAS COUNTDOWN)

    if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2){ //ARCADE/REBELLION MODES
        if(openborvariant("current_branch") == "sor3_st6f"){
            setglobalvar("lastXpos", NULL());
            setglobalvar("st6_lock1", NULL());
            setglobalvar("st6_lock2", NULL());
            setglobalvar("st6_lock3", NULL());
            setglobalvar("st6_lock4", NULL());
        }
    }
}

void resetLevel()
{//Reset necessary global variables when a level starts

    //RESET ALL "LEVEL SELECT" VARIABLES
    if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2){
        if(openborvariant("current_branch") != "route"){
            if(getglobalvar("levelName") != "sor2_st1a"){
                setglobalvar("levelName", "sor2_st1a");
            }

            if(getglobalvar("levelSelected") != NULL()){setglobalvar("levelSelected", NULL());}
        }
        else
        {
            levelMenu();
        }

    }

    //RESET "PLAYED TIME" VARIABLE TO START A NEW COUNT
    setglobalvar("playedCounter", openborvariant("elapsed_time"));
}

void resetOk()
{//Reset the "OK" bar for all players when a level starts
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    void partner = getglobalvar("currentPartner");

    setglobalvar("okBar"+player1, 0);
    setglobalvar("okBar"+player2, 0);
    setglobalvar("okBar"+player3, 0);
    setglobalvar("okBar"+player4, 0);
    setglobalvar("okBar"+partner, 0);
}

void resetParry()
{//Reset the parry global variable for all player when the level starts

    setglobalvar("parryDelay0", NULL());
    setglobalvar("parryDelay1", NULL());
    setglobalvar("parryDelay2", NULL());
    setglobalvar("parryDelay3", NULL());
}

void resetArmor()
{//Reset the super armor global variable for all player when the level starts
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    void partner = getglobalvar("currentPartner");

    //PLAYER 1
    if(getglobalvar("armorResist"+player1) != NULL()){
        changedrawmethod(player1, "enabled", 0);
        setglobalvar("armorResist"+player1, NULL());
    }

    //PLAYER 2
    if(getglobalvar("armorResist"+player2) != NULL()){
        changedrawmethod(player2, "enabled", 0);
        setglobalvar("armorResist"+player2, NULL());
    }

    //PLAYER 3
    if(getglobalvar("armorResist"+player3) != NULL()){
        changedrawmethod(player3, "enabled", 0);
        setglobalvar("armorResist"+player3, NULL());
    }

    //PLAYER 4
    if(getglobalvar("armorResist"+player4) != NULL()){
        changedrawmethod(player4, "enabled", 0);
        setglobalvar("armorResist"+player4, NULL());
    }

    //PARTNER
    if(getglobalvar("armorResist"+partner) != NULL()){
        changedrawmethod(partner, "enabled", 0);
        setglobalvar("armorResist"+partner, NULL());
    }
}

void noJoin()
{//Prevent players from joining during defined set

    if(openborvariant("current_set") == 1){changeopenborvariant("nojoin", 1);} //SURVIVAL MODE
}

void koVar()
{//Set all KO count global variables
    int ko0 = getglobalvar("ko0");
    int ko1 = getglobalvar("ko1");
    int ko2 = getglobalvar("ko2");
    int ko3 = getglobalvar("ko3");

    if(ko0 == NULL()){setglobalvar("ko0",0);}
    if(ko1 == NULL()){setglobalvar("ko1",0);}
    if(ko2 == NULL()){setglobalvar("ko2",0);}
    if(ko3 == NULL()){setglobalvar("ko3",0);}
}

void loadAllMp()
{//Load mp for all players saved by "saveAllMp" function

    if(getglobalvar("fullEnergy") == "never" || getglobalvar("fullEnergy") == "each_respawn"){
        loadMp(0);
        loadMp(1);
        loadMp(2);
        loadMp(3);
    }
}

void loadPartner()
{//Load and spawn defined CPU partner in game if he completed the last level alive
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    float x;
    float y;
    float z;
    int dir;

    if(player1 != NULL()){
        x     = getentityproperty(player1, "x");
        y     = getentityproperty(player1, "y");
        z     = getentityproperty(player1, "z");
        dir = getentityproperty(player1, "direction");
    }
    else
    if(player2 != NULL()){
        x     = getentityproperty(player2, "x");
        y     = getentityproperty(player2, "y");
        z     = getentityproperty(player2, "z");
        dir = getentityproperty(player2, "direction");
    }
    else
    if(player3 != NULL()){
        x     = getentityproperty(player3, "x");
        y     = getentityproperty(player3, "y");
        z     = getentityproperty(player3, "z");
        dir = getentityproperty(player3, "direction");
    }
    else
    if(player4 != NULL()){
        x     = getentityproperty(player4, "x");
        y     = getentityproperty(player4, "y");
        z     = getentityproperty(player4, "z");
        dir = getentityproperty(player4, "direction");
    }

    if(getglobalvar("partnerFull") == 1){
        // if(getglobalvar("fullEnergy") == "always" || getglobalvar("fullEnergy") == "each_new_stage"){
            setglobalvar("partnerMp", 120);
        // }
        setglobalvar("partnerHealth", 400);
        setglobalvar("partnerFull", 0);
    }

    if(getglobalvar("partnerAlive") == 1){ //CPU PARTNER COMPLETED THE LAST LEVEL ALIVE OR IS SPAWNED FROM SELECT SCREEN??
        void pName = getglobalvar("partnerName");
        void vSpawn;

        loadmodel(pName, 1);
        clearspawnentry(); //CLEAR CURRENT SPAWN ENTRY
        setspawnentry("name", pName); //ACQUIRE SPAWN ENTITY BY NAME
        vSpawn = spawn(); //SPAWN IN ENTITY
        changeentityproperty(vSpawn, "position", x, z, y+300);  //SET SPAWN POSITION
        changeentityproperty(vSpawn, "direction", dir);  //SET SPAWN DIRECTION
        changeentityproperty(vSpawn, "health", getglobalvar("partnerHealth"));  //SET SPAWN HEALTH
        changeentityproperty(vSpawn, "mp", getglobalvar("partnerMp"));  //SET SPAWN MP
        setglobalvar("currentPartner", vSpawn); //SET AS CURRENT SPAWNED PARTNER

        return vSpawn; //RETURN SPAWN
    }
}

void loadMaxRush()
{//Load saved max rush counter and apply when the level starts
    void player1 = getplayerproperty(0, "entity"); //IDENTIFY PLAYER 1
    void player2 = getplayerproperty(1, "entity"); //IDENTIFY PLAYER 2
    void player3 = getplayerproperty(2, "entity"); //IDENTIFY PLAYER 3
    void player4 = getplayerproperty(3, "entity"); //IDENTIFY PLAYER 4

    if(player1 != NULL()){ //IS PLAYER 1 PLAYING THE GAME??
        changeentityproperty(player1, "rush_tally", getglobalvar("maxRush1")); //CHANGE PLAYER 1 MAX RUSH COUNT WITH LOADED VALUE
    }
    if(player2 != NULL()){ //IS PLAYER 2 PLAYING THE GAME??
        changeentityproperty(player2, "rush_tally", getglobalvar("maxRush2")); //CHANGE PLAYER 2 MAX RUSH COUNT WITH LOADED VALUE
    }
    if(player3 != NULL()){ //IS PLAYER 3 PLAYING THE GAME??
        changeentityproperty(player3, "rush_tally", getglobalvar("maxRush3")); //CHANGE PLAYER 3 MAX RUSH COUNT WITH LOADED VALUE
    }
    if(player4 != NULL()){ //IS PLAYER 4 PLAYING THE GAME??
        changeentityproperty(player4, "rush_tally", getglobalvar("maxRush4")); //CHANGE PLAYER 4 MAX RUSH COUNT WITH LOADED VALUE
    }
}

void levelMenu()
{//Spawn level select menu entity if all requiriments are ok, otherwise it will be skipped

    if(getglobalvar("arcadeLock") == 0 && getglobalvar("levelSelect") == "on"){
        if(getglobalvar("activeText") != "Level"){
            void vSpawn;
            clearspawnentry();
            setspawnentry("name", "Level_Menu");
            setspawnentry("coords", 1, 1, 0);
            setspawnentry("flip", 1);
            vSpawn = spawn();
            changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
            changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
            changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ESC"));
            changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ESC"));
            changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ESC"));
            changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ESC"));
            setglobalvar("activeText", "Level");
        }
    }
}

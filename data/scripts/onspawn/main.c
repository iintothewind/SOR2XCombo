void onspawnEnemy(void vAlias, float iMHealth, float iHealth, float iSpeed, float iAggre, float iScore, float iMap)
{//Set attributes for each spawned character (FOR ENEMIES)
    void self        = getlocalvar("self");
    void difficult    = getglobalvar("difficult");
    void partner    = getglobalvar("partnerAlive");
    void getFood    = getglobalvar("getFood");
    void branch        = openborvariant("current_branch");
    int set            = openborvariant("current_set");
    int pCount        = openborvariant("count_players");

    //ADD CPU PARTNER TO THE TOTAL AMMOUNT OF PLAYERS
    if(partner > 0){pCount = pCount+partner;}

    //CALCULATE MAIN RULES
    int addHealth1    = iMHealth/2; //CALCULATE 50% OF THE MAX HEALTH
    int addHealth2    = iMHealth/2*(pCount-1); //CALCULATE 10% OF THE MAX HEALTH
    int addSpeed    = 0.2;
    int addAggre    = 200;
    int addScore    = iScore/2*(pCount-1); //CALCULATE 25% OF THE TOTAL SCORE

    //ADJUST DIFFICULT RULES
    if(difficult == "hard"){ //SPEED +0.2, AGGRESSION +200
        iSpeed   = iSpeed+addSpeed;
        iAggre   = iAggre+addAggre;
    }
    else
    if(difficult == "mania"){ //SPEED +0.4, AGGRESSION +400
        iSpeed   = iSpeed+addSpeed*2;
        iAggre      = iAggre+addAggre*2;
    }

    iMHealth = iMHealth+addHealth1*2;
    iHealth  = iMHealth;

    //ENEMIES NOW CAN DETECT AND GET YOUR FOOD
    if(getFood == "on"){changeentityproperty(self, "detect", 1);}

    //ADJUSTMENTS FOR ARCADE-REBELLION MODES
    if(set == 0 || set == 2){
        changeentityproperty(self, "hostile", "type_player", "type_npc"); //SET HOSTILE.
        changeentityproperty(self, "candamage", "type_player", "type_npc", "type_obstacle"); //SET CANDAMAGE.
    }

    //ADJUSTMENTS FOR SURVIVAL MODE
    if(set == 1){
        if(branch == "survival_a" || branch == "survival_b"){
            changeentityproperty(self, "subject_to_screen", 1); //SET SUBJECT_TO_SCREEN STATUS
        }else{
            changeentityproperty(self, "hostile", "type_player", "type_enemy"); //SET HOSTILE.
            changeentityproperty(self, "candamage", "type_player", "type_enemy", "type_obstacle"); //SET CANDAMAGE.
            changeentityproperty(self, "subject_to_screen", 1); //SET SUBJECT_TO_SCREEN STATUS.
        }
    }

    //ADJUST JUGGLES OPTION
    juggles();

    //ADD 10% MORE HEALTH AND POINTS BY EACH PLAYER IN GAME IF HAS MORE THAN 1 PLAYER (2/3/4 PLAYERS ONLY)
    if(pCount > 1){
        iMHealth = iMHealth+addHealth2;
        iHealth     = iMHealth;
        iScore   = iScore+addScore;
    }

    //APPLY ALL DEFINED VALUES
    changeentityproperty(self, "name", vAlias); //SET ALIAS.
    changeentityproperty(self, "maxhealth", iMHealth); //SET MAXHEALTH.
    changeentityproperty(self, "health", iHealth); //SET HEALTH.
    changeentityproperty(self, "speed", iSpeed); //SET SPEED.
    changeentityproperty(self, "aggression", iAggre); //SET AGGRESSION.
    changeentityproperty(self, "score", iScore); //SET SCORE.
    changeentityproperty(self, "map", iMap); //SET MAP.
}

void onspawnBoss(void vAlias, float iMHealth, float iHealth, float iAggre, float iScore, float iMap)
{//Set attributes for each spawned character (FOR BOSSES)
    void self        = getlocalvar("self");
    void difficult    = getglobalvar("difficult");
    void partner    = getglobalvar("partnerAlive");
    void getFood    = getglobalvar("getFood");
    void branch        = openborvariant("current_branch");
    int set            = openborvariant("current_set");
    int pCount        = openborvariant("count_players");

    //ADD CPU PARTNER TO THE TOTAL AMMOUNT OF PLAYERS
    if(partner > 0){pCount = pCount+partner;}

    //CALCULATE HEALTH RULES
    int addHealth1    = iMHealth/4; //CALCULATE 25% OF THE MAX HEALTH
    int addHealth2    = iMHealth/5*(pCount-1); //CALCULATE 10% OF THE MAX HEALTH
    int addAggre    = 300;

    //ADJUST DIFFICULT RULES
    if(difficult == "hard"){ //AGGRESSION +300
        iAggre      = iAggre+addAggre;
    }
    else
    if(difficult == "mania"){ //AGGRESSION +600
        iAggre      = iAggre+addAggre*2;
    }

    iMHealth = iMHealth+addHealth1*2;
    iHealth  = iMHealth;

    //ENEMIES NOW CAN DETECT AND GET YOUR FOOD
    if(getFood == "on"){changeentityproperty(self, "detect", 1);}

    //ADJUSTMENTS FOR ARCADE-REBELLION MODES
    if(set == 0 || set == 2){
        changeentityproperty(self, "hostile", "type_player", "type_npc"); //SET HOSTILE.
        changeentityproperty(self, "candamage", "type_player", "type_npc", "type_obstacle"); //SET CANDAMAGE.
    }

    //ADJUSTMENTS FOR SURVIVAL MODE
    if(set == 1){
        if(branch == "survival_a" || branch == "survival_b"){
            changeentityproperty(self, "subject_to_screen", 1); //SET SUBJECT_TO_SCREEN STATUS
        }else{
            changeentityproperty(self, "hostile", "type_player", "type_enemy"); //SET HOSTILE.
            changeentityproperty(self, "candamage", "type_player", "type_enemy", "type_obstacle"); //SET CANDAMAGE.
            changeentityproperty(self, "subject_to_screen", 1); //SET SUBJECT_TO_SCREEN STATUS.
        }

        //HALVES ALL BOSSES HEALTH IN SURVIVAL MODE, NORMAL ENEMIES REMAINS THE SAME
        iMHealth = iMHealth/2;
        iHealth     = iMHealth;
    }

    //ADJUST RAGE ATTACK OPTION
    rageATK();

    //ADJUST JUGGLES OPTION
    juggles();

    //ADD 10% MORE HEALTH BY EACH PLAYER IN GAME IF HAS MORE THAN 1 PLAYER (2/3/4 PLAYERS ONLY)
    if(pCount > 1){
        iMHealth = iMHealth+addHealth2;
        iHealth     = iMHealth;
    }

    //APPLY ALL DEFINED VALUES
    changeentityproperty(self, "name", vAlias); //SET ALIAS.
    changeentityproperty(self, "maxhealth", iMHealth); //SET MAXHEALTH.
    changeentityproperty(self, "health", iHealth); //SET HEALTH.
    changeentityproperty(self, "aggression", iAggre); //SET AGGRESSION.
    changeentityproperty(self, "score", iScore); //SET SCORE.
    changeentityproperty(self, "map", iMap); //SET MAP.
}


void spawnAlias(void vName, void vAlias, float fX, float fY, float fZ, void ani, int boss, int level)
{//Custom "spawn01" for for Vehelits, spawn and define custom alias
    void vSpawn;
    void self    = getlocalvar("self");
    int iDir    = getentityproperty(self, "direction");

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("boss", boss != NULL()? boss:0);
    setspawnentry("map", level != NULL()? level:4);

    if(iDir == 0){fX = -fX;}

    fX = fX + getentityproperty(self, "x");
    fY = fY + getentityproperty(self, "y");
    fZ = fZ + getentityproperty(self, "z");

    vSpawn = spawn();

    changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
    changeentityproperty(vSpawn, "direction", iDir); //SET DIRECTION.
    changeentityproperty(vSpawn, "name", vAlias); //SET ALIAS.
    changeentityproperty(vSpawn, "parent", self); //SET CALLER AS PARENT.
    if(ani != NULL()){changeentityproperty(vSpawn, "animation", ani);} //SET ANIMATION.

    return vSpawn;
}

void spawnX(void name1, void name2, void name3, void name4, float dx, float dy, float dz)
{//Spawns random entity next to caller (4 ENTITIES, ITENS, WEAPONS)
    void self     = getlocalvar("self");
    void vSpawn;
    void vName = getentityproperty(self,"defaultname");
    int  iDir    = getentityproperty(self,"direction");
    int  iR     = rand()%100;

    if(iR >= 0 && iR < 25){
        vName = name1;
    }
    else
    if(iR >= 25 && iR < 50){
        vName = name2;
    }
    else
    if(iR >= 50 && iR < 75){
        vName = name3;
    }
    else
    if(iR >= 75 && iR <= 100){
        vName = name4;
    }

    clearspawnentry();
    setspawnentry("name", vName);

    vSpawn = spawn();

    bindentity(vSpawn, self, dx, dz, dy, iDir);

    return vSpawn;
}

void spawnVar(void vName, void varName, float fX, float fY, float fZ, int bossFlag, int map, int dir, void anim)
{//Spawn and mark an entity with a defined entityvar name for further use (SOR3 ST6 PANEL/MONALISA SISTER/YAMATO BROTHERS/BRUCE/ARM)
    void vSpawn;
    void self        = getlocalvar("self");
    int  direction    = getentityproperty(self, "direction");

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("boss", bossFlag);
    setspawnentry("map", map);

    //SET CUSTOM DIRECTION
    if(dir != NULL()){direction = dir;}else{if(direction == 0){fX = -fX;}}

    fX = fX + getentityproperty(self, "x");
    fY = fY + getentityproperty(self, "y");
    fZ = fZ + getentityproperty(self, "z");

    vSpawn = spawn();

    changeentityproperty(vSpawn, "position", fX, fZ, fY);
    changeentityproperty(vSpawn, "direction", direction);

    //SET CUSTOM VARIABLE
    if(varName != NULL()){setentityvar(self, varName, vSpawn);}

    //SET CUSTOM ANIMATION
    if(anim != NULL()){changeentityproperty(vSpawn, "animation", anim);}

    return vSpawn;
}

void enemyX(void vName, float dx, float dy, float dz, int iDir, int boss, int map, int randomBossNum)
{//Spawns random enemy next to caller (DEFAULT, FOR SUB-BOSSES OR BOSSES)
    void self = getlocalvar("self");
    void vSpawn;

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("boss", boss);
    setspawnentry("map", map);

    vSpawn = spawn();

    if(randomBossNum != NULL()){setentityvar(vSpawn, "randomBossNum", randomBossNum);}

    bindentity(vSpawn, self, dx, dz, dy, iDir);

    return vSpawn;
}

void enemyXAlias(void vName, void vAlias, float dx, float dy, float dz, int iDir, int boss, int map)
{//Spawns random enemy next to caller (DEFAULT, FOR SUB-BOSSES OR BOSSES)
    void self = getlocalvar("self");
    void vSpawn;

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("boss", boss);
    setspawnentry("map", map);

    vSpawn = spawn();

    changeentityproperty(vSpawn, "name", vAlias); //SET ALIAS.

    bindentity(vSpawn, self, dx, dz, dy, iDir);

    return vSpawn;
}

void enemyX2(void name1, void name2, float dx, float dy, float dz)
{//Spawns random enemy next to caller (2 ENTITIES, GALSIA/DONOVAN OR SLUM/VICE)
    void self     = getlocalvar("self");
    void vName;
    void vSpawn;
    int iDir    = getentityproperty(self,"direction");
    int level    = getentityproperty(self,"map");
    int iR;
    int map;

    //RANDOM NAME
    iR = rand()%100;

    if(iR >= 0 && iR < 50){
        vName = name1;
    }
    else
    if(iR >= 50 && iR <= 100){
        vName = name2;
    }

    //RANDOM LEVEL
    iR = rand()%100;

    if(level == 0){
        map = 0;
    }
    else
    if(level == 1){
        if(iR >= 0 && iR < 50){
            map = 0;
        }
        else
        if(iR >= 50 && iR <= 100){
            map = 1;
        }
    }
    else
    if(level == 2){
        if(iR >= 0 && iR < 50){
            map = 1;
        }
        else
        if(iR >= 50 && iR <= 100){
            map = 2;
        }
    }
    else
    if(level == 3){
        if(iR >= 0 && iR < 33){
            map = 1;
        }
        else
        if(iR >= 33 && iR < 67){
            map = 2;
        }
        else
        if(iR >= 67 && iR <= 100){
            map = 3;
        }
    }
    else
    if(level == 4){
        if(iR >= 0 && iR < 33){
            map = 2;
        }
        else
        if(iR >= 33 && iR < 67){
            map = 3;
        }
        else
        if(iR >= 67 && iR <= 100){
            map = 4;
        }
    }

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("map", map);

    vSpawn = spawn();

    bindentity(vSpawn, self, dx, dz, dy, iDir);

    return vSpawn;
}

void enemyX3(void name1, void name2, void name3, float dx, float dy, float dz)
{//Spawns random enemy next to caller (3 ENTITIES, ENEMIES)
    void self     = getlocalvar("self");
    void vName;
    void vSpawn;
    int iDir    = getentityproperty(self,"direction");
    int level    = getentityproperty(self,"map");
    int iR;
    int map;

    //RANDOM NAME
    iR = rand()%100;

    if(iR >= 0 && iR < 33){
        vName = name1;
    }
    else
    if(iR >= 33 && iR < 67){
        vName = name2;
    }
    else
    if(iR >= 67 && iR <= 100){
        vName = name3;
    }

    //RANDOM LEVEL
    iR = rand()%100;

    if(level == 0){
        map = 0;
    }
    else
    if(level == 1){
        if(iR >= 0 && iR < 50){
            map = 0;
        }
        else
        if(iR >= 50 && iR <= 100){
            map = 1;
        }
    }
    else
    if(level == 2){
        if(iR >= 0 && iR < 50){
            map = 1;
        }
        else
        if(iR >= 50 && iR <= 100){
            map = 2;
        }
    }
    else
    if(level == 3){
        if(iR >= 0 && iR < 33){
            map = 1;
        }
        else
        if(iR >= 33 && iR < 67){
            map = 2;
        }
        else
        if(iR >= 67 && iR <= 100){
            map = 3;
        }
    }
    else
    if(level == 4){
        if(iR >= 0 && iR < 33){
            map = 2;
        }
        else
        if(iR >= 33 && iR < 67){
            map = 3;
        }
        else
        if(iR >= 67 && iR <= 100){
            map = 4;
        }
    }

    clearspawnentry();
    setspawnentry("name", vName);
    setspawnentry("map", map);

    vSpawn = spawn();

    bindentity(vSpawn, self, dx, dz, dy, iDir);

    return vSpawn;
}

void randomX2(void name1, void name2)
{//Spawn random Enemy (2 ENEMIES)
    void partner = getglobalvar("partnerAlive"); //GET CURRENT PARTNER STATUS, ALIVE OR DEAD.
    int pCount     = openborvariant("count_players");

    if(partner > 0){pCount = pCount+partner;}

    if(pCount < 3){
        enemyX2(name1, name2, 0, 0, 0);
    }
    else
    {
        enemyX2(name1, name2, 0, 0, 0);
        enemyX2(name1, name2, -20, 0, 20);
    }
}

void randomX3(void name1, void name2, void name3)
{//Spawn random Enemy (3 ENEMIES)
    void partner = getglobalvar("partnerAlive"); //GET CURRENT PARTNER STATUS, ALIVE OR DEAD.
    int pCount     = openborvariant("count_players");

    if(partner > 0){pCount = pCount+partner;}

    if(pCount < 3){
        enemyX3(name1, name2, name3, 0, 0, 0);
    }
    else
    {
        enemyX3(name1, name2, name3, 0, 0, 0);
        enemyX3(name1, name2, name3, -20, 0, 20);
    }
}

void rageATK()
{//Enable/Disable Rage attacks with global variable check
    void self     = getlocalvar("self");
    void type     = getentityproperty(self, "type");
    int valid     = getentityproperty(self, "animvalid", openborconstant("ANI_FREESPECIAL"));
    int disable     = getentityproperty(self, "energycost", "disable", openborconstant("ANI_FREESPECIAL"));

    //CHECK IF THE ENTITY HAS THE "FREESPECIAL" ANIMATION AND IF IT'S USED FOR "RAGE" MOVES ACCORDING TO THE "DISABLE" FLAG
    if(valid == 1 && disable == 6){
        //PLAYERS AND CPU PARTNERS
        if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
            changeentityproperty(self, "energycost", "disable", openborconstant("ANI_FREESPECIAL"), 6);
        }

        //BOSSES
        if(type == openborconstant("TYPE_ENEMY")){
            changeentityproperty(self, "energycost", "disable", openborconstant("ANI_FREESPECIAL"), 0);
        }
    }
}

void juggles()
{//Enable/Disable Juggles with global variable check
    void self     = getlocalvar("self");
    void juggles = getglobalvar("juggleSystem");
    int disabled = 1;

    if(juggles == "unlimited"){
        changeentityproperty(self, "maxjugglepoints", 999);
        changeentityproperty(self, "jugglepoints", 999);
    }else if(juggles == "100"){
        changeentityproperty(self, "maxjugglepoints", 100);
        changeentityproperty(self, "jugglepoints", 100);
    }else if(juggles == "80"){
        changeentityproperty(self, "maxjugglepoints", 80);
        changeentityproperty(self, "jugglepoints", 80);
    }else if(juggles == "60"){
        changeentityproperty(self, "maxjugglepoints", 60);
        changeentityproperty(self, "jugglepoints", 60);
    }else if(juggles == "50"){
        changeentityproperty(self, "maxjugglepoints", 50);
        changeentityproperty(self, "jugglepoints", 50);
    }else if(juggles == "40"){
        changeentityproperty(self, "maxjugglepoints", 40);
        changeentityproperty(self, "jugglepoints", 40);
    }else if(juggles == "30"){
        changeentityproperty(self, "maxjugglepoints", 30);
        changeentityproperty(self, "jugglepoints", 30);
    }else if(juggles == "20"){
        changeentityproperty(self, "maxjugglepoints", 20);
        changeentityproperty(self, "jugglepoints", 20);
    } else {
        changeentityproperty(self, "maxjugglepoints", disabled);
        changeentityproperty(self, "jugglepoints", disabled);
    }
}

void specialCost()
{//Change Special/Special2 attacks cost form with global variable check
    void self        = getlocalvar("self");
    // void specialC = getglobalvar("specialCost");
    void specialC = "sor2x_energy_only";
    void subTtype = getentityproperty(self, "subtype");
    int specialValid     = getentityproperty(self, "animvalid", openborconstant("ANI_SPECIAL"));
    int special2Valid     = getentityproperty(self, "animvalid", openborconstant("ANI_SPECIAL2"));
    int freespecial4Valid     = getentityproperty(self, "animvalid", openborconstant("ANI_FREESPECIAL4"));
    int mPonly1      = getentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL"));
    int mPonly2      = getentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL2"));

    if(specialValid == 1 && mPonly1 != NULL()){
        if(specialC == "sor4_recovery_(time)" || specialC == "sor4_recovery_(hits)" || specialC == "sor2_life_only"){ //SPECIAL COST FORM IS RECOVERY OR LIFE ONLY??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL"), 2);
        }
        else
        if(specialC == "sor2x_energy_only"){ //SPECIAL COST FORM IS ENERGY ONLY??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL"), 1);
        }
        else
        if(specialC == "sor2x_energy+life"){ //SPECIAL COST FORM IS ENERGY+LIFE??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL"), 0);
        }
    }

    if(special2Valid == 1 && mPonly2 != NULL()){
        if(specialC == "sor4_recovery_(time)" || specialC == "sor4_recovery_(hits)" || specialC == "sor2_life_only"){ //SPECIAL COST FORM IS RECOVERY OR LIFE ONLY??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL2"), 2);
        }
        else
        if(specialC == "sor2x_energy_only"){ //SPECIAL COST FORM IS ENERGY ONLY??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL2"), 1);
        }
        else
        if(specialC == "sor2x_energy+life"){ //SPECIAL COST FORM IS ENERGY+LIFE??
            changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_SPECIAL2"), 0);
        }
    }

    if(subTtype == openborconstant("SUBTYPE_FOLLOW")){ //IS THE ENTITY AN NPC PARTNER?? USE FREESPECIAL4 AS SPECIAL2 FOR ALL NPC
        if(freespecial4Valid == 1 && mPonly1 != NULL()){
            if(specialC == "sor4_recovery_(time)" || specialC == "sor4_recovery_(hits)" || specialC == "sor2_life_only"){ //SPECIAL COST FORM IS RECOVERY OR LIFE ONLY??
                changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_FREESPECIAL4"), 2);
            }
            else
            if(specialC == "sor2x_energy_only"){ //SPECIAL COST FORM IS ENERGY ONLY??
                changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_FREESPECIAL4"), 1);
            }
            else
            if(specialC == "sor2x_energy+life"){ //SPECIAL COST FORM IS ENERGY+LIFE??
                changeentityproperty(self, "energycost", "mponly", openborconstant("ANI_FREESPECIAL4"), 0);
            }
        }
    }
}

void quickRespawn()
{//Enable/Disable quick respawn by changing the "nodieblink" property, work with global variable check
    void self    = getlocalvar("self");
    void quick    = getglobalvar("quickRespawn"); //Get quick respawn option.

    if(quick == "on"){
        changeentityproperty(self, "nodieblink", 2);
    }
    else
    if(quick == "off"){ //death 1 heroes: blink after DEATH anim (not 0, which expects FALL)
        changeentityproperty(self, "nodieblink", 1);
    }
    changeentityproperty(self, "blink", 0);
}
#import "data/scripts/main.c"
#include "data/scripts/assets.h"
#import "data/scripts/animation/main_spawns.c"

void addMp()
{//Add mp if take damage
    void self     = getlocalvar("self");
    int dmg     = getlocalvar("damage");
    int atkType    = getlocalvar("attacktype");
    int mp         = getentityproperty(self,"mp");
    int mpRate     = getentityproperty(self,"mpRate");

    if(dmg > 0){ //USED GRABS AND OTHER "NO DAMAGE" ATKS
        if(atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){ //AVOID ATK_10 (USED FOR ROUTE MENU AND DOORS) AND TIMEOVER DAMAGE
            changeentityproperty(self, "mp", mp+mpRate);
        }
    }
}

void healStop()
{//Set flag to stop player health restoration, used in SPECIAL/SPECIAL2/SPECIAL3 moves (SPECIAL COST "LIFE" ONLY)
    void self = getlocalvar("self");
    void type = getentityproperty(self,"type");
    int dmg   = getlocalvar("damage");

    if(dmg > 0){
        if(getglobalvar("addLife"+self) != 0){
            if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
                setglobalvar("addLife"+self, 0);
            }
        }
    }
}

void superArmor()
{//Activate/deactivate "superArmor" global variable
    void self = getlocalvar("self");
    void type     = getentityproperty(self,"type");
    int atkType    = getlocalvar("attacktype");
    int damage     = getlocalvar("damage");
    int drop    = getlocalvar("drop");
    int pain    = getentityproperty(self,"aiflag","inpain");
    int fall    = getentityproperty(self,"aiflag","falling");
    int dead    = getentityproperty(self,"dead");
    int noPain    = getentityproperty(self,"nopain");
    int hp     = getentityproperty(self,"health");
    int maxHp    = getentityproperty(self, "maxhealth");
    int gp        = getentityproperty(self,"guardpoints");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    int costGp    = maxGp/2;

    if(openborvariant("current_branch") != "sor3_st7d"){
        if(atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){ //AVOID ATK_10 (USED FOR ROUTE MENU AND DOORS) AND TIMEOVER DAMAGE
            if(damage > 0 && gp >=costGp && hp >= maxHp/3 && drop == 0 && pain == 0 && fall == 0 && dead == 0 && noPain == 1){
                float time    = openborvariant("elapsed_time");

                // if(type == openborconstant("TYPE_PLAYER")){spawnText("Moves", "SUPER_ARMOR");}
                setglobalvar("armorResist"+self, time);
                changeentityproperty(self, "guardpoints", gp-costGp);
                playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
            }
        }
    }
}

void loadRecoverRate() {
    float rate = 0.2;
    void lastChance = getglobalvar("lastChance");
    if(lastChance == "33%") {
        rate = 0.33;
    } else if(lastChance == "25%") {
        rate = 0.25;
    } else if(lastChance == "20%") {
        rate = 0.2;
    } else if(lastChance == "10%") {
        rate = 0.1;
    }
    return rate;
}

void lastChance() {
    void self = getlocalvar("self");
    int height     = getentityproperty(self,"y");
    int base     = getentityproperty(self,"base");
    void attacker = getlocalvar("attacker");
    void type     = getentityproperty(self,"type");
    int atkType    = getlocalvar("attacktype");
    int power    = 1;
    int dead    = getentityproperty(self,"dead");
    int fall    = getentityproperty(self,"aiflag","falling");
    float hp     = getentityproperty(self,"health");
    float maxHp    = getentityproperty(self, "maxhealth");
    float gp        = getentityproperty(self,"guardpoints");
    float maxGp    = getentityproperty(self,"maxguardpoints");
    void grabbed = getentityvar(self,"grabbed");
    void grabbing = getentityproperty(self, "grabbing");
    void lastChance = getglobalvar("lastChance");

    if(attacker != NULL()){power = getentityproperty(attacker, "offense");}
    int damage = getlocalvar("damage") * power;

    if(lastChance != "off" && dead == 0 && fall == 0 && height == base
    && grabbed == NULL() && grabbing == NULL()
    && (type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC"))
    && atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){
        float recoverRate = loadRecoverRate();
        int lethal = (hp <= 0) || (damage >= hp);

        if(lethal && hp < maxHp*0.1 && gp >= maxGp*0.5){
            changeentityproperty(self, "guardpoints", 1);
            changeentityproperty(self, "health", maxHp*recoverRate);
            playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
        } else if(lethal && hp < maxHp*recoverRate && gp >= maxGp){
            changeentityproperty(self, "guardpoints", 1);
            changeentityproperty(self, "health", maxHp*recoverRate);
            playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
        }
    }
}

// Only for enemies in Dojo
void escapeDeath() {
    void self = getlocalvar("self");
    void target = getentityproperty(self,"opponent");
    void type     = getentityproperty(self,"type");
    int base     = getentityproperty(self,"base");
    int height     = getentityproperty(self,"y");
    void grabbed = getentityvar(self,"grabbed");
    void grabbing = getentityproperty(self, "grabbing");
    int atkType    = getlocalvar("attacktype");
    int damage     = getlocalvar("damage");
    int dead    = getentityproperty(self,"dead");
    int fall    = getentityproperty(self,"aiflag","falling");
    int hp     = getentityproperty(self,"health");
    int maxHp    = getentityproperty(self, "maxhealth");
    int gp        = getentityproperty(self,"guardpoints");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    void ani = getentityproperty(self,"animationID");
    int set     = openborvariant("current_set");

    if(set == 3
    && type == openborconstant("TYPE_ENEMY")
    && height == base
    && dead == 0
    && fall == 0
    && atkType != openborconstant("ATK_NORMAL10")
    && atkType != openborconstant("ATK_TIMEOVER")){
        if(hp <= maxHp/3*2 || damage>= maxHp/10){
            changeentityproperty(self, "health", maxHp);
            playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
        }
    }
}

void braveEffect() {
    void self = getlocalvar("self");
    void target = getentityproperty(self,"opponent");
    void type     = getentityproperty(self,"type");
    int base     = getentityproperty(self,"base");
    int height     = getentityproperty(self,"y");
    void grabbed = getentityvar(self,"grabbed");
    void grabbing = getentityproperty(self, "grabbing");
    int atkType    = getlocalvar("attacktype");
    int damage     = getlocalvar("damage");
    int dead    = getentityproperty(self,"dead");
    int fall    = getentityproperty(self,"aiflag","falling");
    int hp     = getentityproperty(self,"health");
    int maxHp    = getentityproperty(self, "maxhealth");
    int selfMp         = getentityproperty(self, "mp");
    int selfMaxMp     = getentityproperty(self, "maxmp");
    int gp        = getentityproperty(self,"guardpoints");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    void ani = getentityproperty(self,"animationID");
    int set     = openborvariant("current_set");

    if(type == openborconstant("TYPE_ENEMY")
    && height == base
    && dead == 0
    && fall == 0
    && atkType != openborconstant("ATK_NORMAL10")
    && atkType != openborconstant("ATK_TIMEOVER")){
        if(findEnemy("Bruce") != NULL() && findLevelBoss() == NULL() && (hp <= maxHp/3*2 || damage>= maxHp/10)){
            changeentityproperty(self, "health", maxHp);
            changeentityproperty(self, "mp", maxGp);
            playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
        }
    }
}

void escapeCount()
{//Changes escapecount property ramdomly with chance according to difficult
    void self         = getlocalvar("self");
    void difficult     = getglobalvar("difficult");
    int escapeC        = getentityproperty(self, "escapecount");
    int escapeH        = getentityproperty(self, "escapehits");

    if(escapeH > 0){
        void type      = getentityproperty(self, "type");
        int dif        = 1;
        int chance     = 0;
        int iR         = rnd(100)-1;

        if(type == openborconstant("TYPE_ENEMY")){
            //100% CHANCE
            if(difficult == "normal"){
                chance = 100;
            }else if(difficult == "hard"){
                chance = 75;
            }else if(difficult == "mania"){
                chance = 50;
            }
        }
        if(iR < chance){changeentityproperty(self, "escapecount", escapeC-dif);}
    }
}

void customHitflash()
{//Script for a second hitflash if damaged with defined attack (FOR ROBOTS AND OTHER ENTITIES WITH NO BLOOD)
 //It is necessary if the entity uses "noatflash" but need to spawn special hitflashes like burn or shock, and not only "flash"
 //CAUTION: ANY NEW ENTITY NEED TO HAVE THE DROP SET ACCORDING TO THIS TABLE IF USES ANY SPECIAL HITFLASH
    void self = getlocalvar("self");
    int drop  = getlocalvar("drop");

    if(drop == 2){spawnToss("Burn", 0, 50, 1, 0, 0, 0);}
    if(drop == 3){spawnToss("Shock", 0, 50, 1, 0, 0, 0);}
    if(drop == 4){spawnToss("Impact", 0, 50, 1, 0, 0, 0);}
    if(drop == 5){spawnToss("Destruction", 0, 50, 1, 0, 0, 0);}
}

void smokeSpeed(int y1, int y2)
{//Spawn smoke with "speedLV" check if dying (BREAK)
    void self     = getlocalvar("self");
    int dmg     = getlocalvar("damage");
    int speedLV    = getentityvar(self, "speedLV");
    int x        = getentityproperty(self, "x");
    int y         = getentityproperty(self, "y");
    int z        = getentityproperty(self, "z");
    float hole     = checkhole(x, z, y);

    if(dmg > 0 && hole != 1){
        if(speedLV == 2){ //SPAWN SMOKE IF TAKE DAMAGE TO SHOW MALFUNCTION
            spawnToss("Smoke", 0, y1, -1, 0, 1, 0);
        }

        if(speedLV == 3){ //SPAWN MORE SMOKES IF TAKE DAMAGE TO SHOW MORE MALFUNCTION!!!
            spawnToss("Smoke", 0, y1, -1, 0, 1, 0);
            spawnToss("Smoke", 0, y2, -1, 0, 1, 0);
        }
    }
}

void smokeHealth(int y1, int y2)
{//Spawn smoke with "Health" check if dying (ST6 COMPUTER)
    void self     = getlocalvar("self");
    int mHealth = getentityproperty(self, "maxhealth"); //Max health
    int cHealth = getentityproperty(self, "health"); //Current health

    if(cHealth <= mHealth/2 && cHealth >= mHealth/4){ //HEALTH LESS THAN 50% AND MORE THAN 25%
        spawnToss("Smoke", 0, y1, 1, 0, 1, 0); //SPAWN SMOKE IF TAKE DAMAGE TO SHOW MALFUNCTION
    }

    if(cHealth < mHealth/4 && cHealth >= 1){ //HEALTH LESS THAN 25% AND MORE THAN 1
        spawnToss("Smoke", 0, y1, 1, 0, 1, 0); //SPAWN MORE SMOKES IF TAKE DAMAGE TO SHOW MORE MALFUNCTION!!!
        spawnToss("Smoke", 0, y2, 1, 0, 1, 0); //SPAWN MORE SMOKES IF TAKE DAMAGE TO SHOW MORE MALFUNCTION!!!
    }
}

void aniHealth(void ani1, void ani2)
{//Change animation according to current health (WALLS/COMPUTER)
    void self      = getlocalvar("self");
    void ani    = getentityproperty(self, "animationID"); //Current animation
    int mHealth = getentityproperty(self, "maxhealth"); //Max health
    int cHealth = getentityproperty(self, "health"); //Current health

    if(ani == openborconstant("ANI_IDLE")){
        if(cHealth <= mHealth/2 && cHealth >= mHealth/4){ //HEALTH LESS THAN 50% AND MORE THAN 25%
            changeentityproperty(self, "animation", openborconstant(ani1));
        }
    }

    if(ani == openborconstant("ANI_FOLLOW1")){
        if(cHealth < mHealth/4 && cHealth >= 1){ //HEALTH LESS THAN 25% AND MORE THAN 1
            changeentityproperty(self, "animation", openborconstant(ani2));
        }
    }
}

void hitDmg()
{//Script to show each hit damage
    void self      = getlocalvar("self");
    void target    = getlocalvar("attacker");
    int atkType    = getlocalvar("attacktype");
    int power    = getentityproperty(target, "offense");
    int gp         = getentityproperty(self, "guardpoints");
    int nopain    = getentityproperty(self, "nopain");
    int dir     = getentityproperty(self, "direction");
    int damage    = getlocalvar("damage")*power;


    if(getglobalvar("showDamage") == "combos+hits"){
        if(nopain == 1){damage = damage/2;}

        //AVOID ATK_10 (USED FOR ROUTE MENU AND DOORS) AND TIMEOVER DAMAGE
        if(damage > 0 && gp > 0 && atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){
            void vSpawn1;
            void vSpawn2;
            void vSpawn3;
            void alg1;
            void alg2;
            void alg3;
            int facing    = 1;
            int Px        = -18;
            int Py        = 70;
            int Pdif    = 8;
            int Vx         = 0.2;
            int Vy         = 1;
            int num1;
            int num2;
            int num3;

            //CALCULATE EACH ALGARISM
            //1 DIGIT DAMAGE
            if(damage < 10){
                num1 = "null";
                num2 = "null";
                num3 = damage;
            }
            else //2 DIGITS DAMAGE
            if(damage >= 10 && damage < 100){
                num1 = "null";
                num2 = damage/10;

                if(num2 < 0){num2 = 0;}else
                if(num2 >= 0 && num2 < 1){num2 = 0;}else
                if(num2 >= 1 && num2 < 2){num2 = 1;}else
                if(num2 >= 2 && num2 < 3){num2 = 2;}else
                if(num2 >= 3 && num2 < 4){num2 = 3;}else
                if(num2 >= 4 && num2 < 5){num2 = 4;}else
                if(num2 >= 5 && num2 < 6){num2 = 5;}else
                if(num2 >= 6 && num2 < 7){num2 = 6;}else
                if(num2 >= 7 && num2 < 8){num2 = 7;}else
                if(num2 >= 8 && num2 < 9){num2 = 8;}else
                if(num2 >= 9 && num2 < 10){num2 = 9;}

                num3 = (damage)-(num2*10);
            }
            else //3 DIGITS DAMAGE
            {
                num1 = damage/100;

                if(num1 < 0){num1 = 0;}else
                if(num1 >= 0 && num1 < 1){num1 = 0;}else
                if(num1 >= 1 && num1 < 2){num1 = 1;}else
                if(num1 >= 2 && num1 < 3){num1 = 2;}else
                if(num1 >= 3 && num1 < 4){num1 = 3;}else
                if(num1 >= 4 && num1 < 5){num1 = 4;}else
                if(num1 >= 5 && num1 < 6){num1 = 5;}else
                if(num1 >= 6 && num1 < 7){num1 = 6;}else
                if(num1 >= 7 && num1 < 8){num1 = 7;}else
                if(num1 >= 8 && num1 < 9){num1 = 8;}else
                if(num1 >= 9 && num1 < 10){num1 = 9;}

                num2 = (damage-(num1*100))/10;

                if(num2 < 0){num2 = 0;}else
                if(num2 >= 0 && num2 < 1){num2 = 0;}else
                if(num2 >= 1 && num2 < 2){num2 = 1;}else
                if(num2 >= 2 && num2 < 3){num2 = 2;}else
                if(num2 >= 3 && num2 < 4){num2 = 3;}else
                if(num2 >= 4 && num2 < 5){num2 = 4;}else
                if(num2 >= 5 && num2 < 6){num2 = 5;}else
                if(num2 >= 6 && num2 < 7){num2 = 6;}else
                if(num2 >= 7 && num2 < 8){num2 = 7;}else
                if(num2 >= 8 && num2 < 9){num2 = 8;}else
                if(num2 >= 9 && num2 < 10){num2 = 9;}

                num3 = damage-((num1*100)+(num2*10));
            }

            //TRANSLATE EACH ALGARISM TO STRINGS
            //FIRST DIGIT
            if(num1 < 0){alg1 = "0";}else
            if(num1 >= 0 && num1 < 1){alg1 = "0";}else
            if(num1 >= 1 && num1 < 2){alg1 = "1";}else
            if(num1 >= 2 && num1 < 3){alg1 = "2";}else
            if(num1 >= 3 && num1 < 4){alg1 = "3";}else
            if(num1 >= 4 && num1 < 5){alg1 = "4";}else
            if(num1 >= 5 && num1 < 6){alg1 = "5";}else
            if(num1 >= 6 && num1 < 7){alg1 = "6";}else
            if(num1 >= 7 && num1 < 8){alg1 = "7";}else
            if(num1 >= 8 && num1 < 9){alg1 = "8";}else
            if(num1 >= 9 && num1 < 10){alg1 = "9";}else
            {alg1 = "null";}

            //SECOND DIGIT
            if(num2 < 0){alg2 = "0";}else
            if(num2 >= 0 && num2 < 1){alg2 = "0";}else
            if(num2 >= 1 && num2 < 2){alg2 = "1";}else
            if(num2 >= 2 && num2 < 3){alg2 = "2";}else
            if(num2 >= 3 && num2 < 4){alg2 = "3";}else
            if(num2 >= 4 && num2 < 5){alg2 = "4";}else
            if(num2 >= 5 && num2 < 6){alg2 = "5";}else
            if(num2 >= 6 && num2 < 7){alg2 = "6";}else
            if(num2 >= 7 && num2 < 8){alg2 = "7";}else
            if(num2 >= 8 && num2 < 9){alg2 = "8";}else
            if(num2 >= 9 && num2 < 10){alg2 = "9";}else
            {alg2 = "null";}

            //THIRD DIGIT
            if(num3 < 0){alg3 = "0";}else
            if(num3 >= 0 && num3 < 1){alg3 = "0";}else
            if(num3 >= 1 && num3 < 2){alg3 = "1";}else
            if(num3 >= 2 && num3 < 3){alg3 = "2";}else
            if(num3 >= 3 && num3 < 4){alg3 = "3";}else
            if(num3 >= 4 && num3 < 5){alg3 = "4";}else
            if(num3 >= 5 && num3 < 6){alg3 = "5";}else
            if(num3 >= 6 && num3 < 7){alg3 = "6";}else
            if(num3 >= 7 && num3 < 8){alg3 = "7";}else
            if(num3 >= 8 && num3 < 9){alg3 = "8";}else
            if(num3 >= 9 && num3 < 10){alg3 = "9";}else
            {alg3 = "null";}

            if(dir == 0){
                Px     = -Px;
                Vx   = -Vx;
                Pdif = -Pdif;
            }

            //SPAWN, TOSS ENTITIES AND DEFINE PROPERTIES
            if(alg1 != "null"){vSpawn1 = spawnFacing(alg1,Px,Py,0,facing);tossentity(vSpawn1, Vy, 0, 0);}
            if(alg2 != "null"){vSpawn2 = spawnFacing(alg2,Px+Pdif,Py,0,facing);tossentity(vSpawn2, Vy, 0, 0);}
            if(alg3 != "null"){vSpawn3 = spawnFacing(alg3,Px+Pdif*2,Py,0,facing);tossentity(vSpawn3, Vy, 0, 0);}
        }
    }
}

void comboDmg()
{//Register total damage dealt during a rush
    void self    = getlocalvar("self");
    void target    = getlocalvar("attacker");
    void parent = getentityproperty(target,"parent");
    int damage    = getlocalvar("damage");
    int atkType    = getlocalvar("attacktype");

    if(damage > 0){
        if(atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){ //AVOID ATK_10 (USED FOR ROUTE MENU AND DOORS) AND TIMEOVER DAMAGE
            void vType    = getentityproperty(target,"type");
            void sType    = getentityproperty(target,"subtype");
            void pType    = getentityproperty(parent,"type");
            int nopain    = getentityproperty(self,"nopain");

            if(vType == openborconstant("TYPE_PLAYER")){
                void name     = getentityproperty(target,"defaultname");
                int pIndex    = getentityproperty(target,"playerindex");
                int rush    = getentityproperty(target,"rush_count");
                int power    = getglobalvar(name+"Power");
                int newDmg    = damage*power;
                int oldDmg    = getglobalvar("dmg"+pIndex);

                if(nopain == 1){newDmg = newDmg/2;}
                if(rush <= 0){setglobalvar("dmg"+pIndex, newDmg);}else{setglobalvar("dmg"+pIndex, oldDmg+newDmg);}
            }
            else
            if(vType != openborconstant("TYPE_PLAYER") && sType != openborconstant("SUBTYPE_FOLLOW") && pType == openborconstant("TYPE_PLAYER")){
                void name     = getentityproperty(parent,"defaultname");
                int pIndex    = getentityproperty(parent,"playerindex");
                int rush    = getentityproperty(parent,"rush_count");
                int power    = getglobalvar(name+"Power");
                int newDmg    = damage*power;
                int oldDmg    = getglobalvar("dmg"+pIndex);

                if(nopain == 1){newDmg = newDmg/2;}
                if(rush <= 0){setglobalvar("dmg"+pIndex, newDmg);}else{setglobalvar("dmg"+pIndex, oldDmg+newDmg);}
            }
        }
    }
}

// player lost 100,000 score every time when player dies
void deathPunish() {
    void self     = getlocalvar("self");
    void type        = getentityproperty(self, "type");
    int health    = getentityproperty(self,"health");

    if(type == openborconstant("TYPE_PLAYER") && health <= 0) {
        int pIndex    = getentityproperty(self,"playerindex");
        int score = getplayerproperty(pIndex, "score");
        int lifeScore = 100000; //DEFINED LIFESCORE TARGET TO PUNISH
        if(score > lifeScore) {
            changeplayerproperty(pIndex, "score", score - lifeScore);
        }

        int deathCount = getglobalvar("lifeCost"+pIndex);
        if(deathCount != NULL()) {
            setglobalvar("lifeCost"+pIndex, deathCount+1);
        } else {
            setglobalvar("lifeCost"+pIndex, 1);
        }
    }
}

void koCount()
{//Count each enemy killed, chaning player variable according to playerindex
    void self     = getlocalvar("self");
    void target    = getlocalvar("attacker");
    void parent    = getentityproperty(target,"parent");
    void branch    = openborvariant("current_branch");
    int health    = getentityproperty(self,"health");
    int add        = 1;
    int pIndex;

    if(health <= 0){ //SELF IS DEAD??
        void vType    = getentityproperty(self,"type");
        void eType    = getentityproperty(target,"type");
        void sType    = getentityproperty(target,"subtype");
        void pType    = getentityproperty(parent,"type");

        if(vType == openborconstant("TYPE_ENEMY")){
            if(branch == "survival_b"){
                setglobalvar("count_enemies", getglobalvar("count_enemies")-add); //USED BY SPAWNTIME SCRIPT IN SURVIVAL GROUP MODE
            }

            if(isBoss(self)) {
                if(parent == NULL()){
                    if(eType == openborconstant("TYPE_PLAYER")){ // count num of boss killed only
                        pIndex    = getentityproperty(target,"playerindex");
                        setglobalvar("ko"+pIndex, getglobalvar("ko"+pIndex)+add);
                        playsample(SAMPLE_KO, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                    }
                }

                if(parent != NULL()){
                    if(pType == openborconstant("TYPE_PLAYER")){
                        pIndex = getentityproperty(parent,"playerindex");
                        setglobalvar("ko"+pIndex, getglobalvar("ko"+pIndex)+add);
                        playsample(SAMPLE_KO, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                    }
                }
            }
        }
    }
}

void quickIdle(void model, void ani) {
    if(model != NULL() && ani != NULL()) {
        void self     = getlocalvar("self");
        int health    = getentityproperty(self,"health");
        void attacker    = getlocalvar("attacker");

        if(health <= 0) {
            void selfType    = getentityproperty(self,"type");
            void attackerType    = getentityproperty(attacker,"type");
            void attackerModel    = getentityproperty(attacker,"model");
            void attackerAni = getentityproperty(attacker,"animationID");
            int attackerFrame    = getentityproperty(attacker,"animpos");
            int attackerHits     = getentityproperty(attacker,"animhits");
            int attackerBase     = getentityproperty(attacker,"base");
            int attackerX         = getentityproperty(attacker,"x");
            int attackerY         = getentityproperty(attacker,"y");
            int attackerZ         = getentityproperty(attacker,"z");
            if(selfType == openborconstant("TYPE_ENEMY") && attackerType == openborconstant("TYPE_PLAYER") && attackerModel == model && attackerAni == openborconstant(ani)) {
                if(attackerY == attackerBase) {
                    setidle(attacker);
                } else {
                    changeentityproperty(attacker, "takeaction", "common_jump");
                    changeentityproperty(attacker, "aiflag", "jumping", 1);
                }
            }
        }
    }
}

void quickIdles() {
    quickIdle("Axel", "ANI_SPECIAL2");
    quickIdle("Axel", "ANI_FREESPECIAL20");
    quickIdle("Adam", "ANI_SPECIAL2");
    quickIdle("Adam", "ANI_FREESPECIAL20");
    quickIdle("Bison", "ANI_SPECIAL2");
    quickIdle("Bison", "ANI_FREESPECIAL20");
    quickIdle("Chunli", "ANI_SPECIAL2");
    quickIdle("Chunli", "ANI_FREESPECIAL20");
    quickIdle("Sammy", "ANI_SPECIAL2");
    quickIdle("Sammy", "ANI_FOLLOW20");
}

void savePause()
{//Register the last "pausetime" when take any hit
    void self         = getlocalvar("self");
    float pause        = getlocalvar("pauseadd");
    float time        = openborvariant("elapsed_time");
    float adjust    = 0.1;

    setglobalvar("pauseAdd"+self, time+pause-adjust);
}

void edgeLock()
{//Lock the screen edge (for enemies) if take any damage, like SOR4

    if(getglobalvar("screenEdge") == "all_types" || getglobalvar("screenEdge") == "lock+bouncing" || getglobalvar("screenEdge") == "lock_only"){
        if(openborvariant("current_set") != 1){ //USED TO AVOID THE SURVIVAL MODE
            void self    = getlocalvar("self");
            void vtype    = getentityproperty(self,"type");
            void sType    = getentityproperty(self,"subtype");
            int subS    = getentityproperty(self, "subject_to_screen");
            int health    = getentityproperty(self, "health");

            if(vtype == openborconstant("TYPE_ENEMY")){
                if(sType != openborconstant("SUBTYPE_NOTGRAB")){
                    if(health > 0){
                        if(subS != 1){changeentityproperty(self, "subject_to_screen", 1);}
                    }
                }
            }
        }
    }
}

void otg()
{//Deduct the OTG points when take any damage during fall animations at the ground
    void self        = getlocalvar("self");
    void ani        = getentityproperty(self, "animationID");
    int otgPoints    = getentityvar(self, "otgpoints");
    int dead        = getentityproperty(self, "dead");
    int frame        = getentityproperty(self, "animpos");
    int add            = 1;
    int min            = 0;

    if(getglobalvar("otgSystem") != "unlimited"){
        if(dead != 1){
            if(ani == openborconstant("ANI_FALL") || ani == openborconstant("ANI_BURN") || ani == openborconstant("ANI_SHOCK")){
                if(frame >= 1){
                    if(otgPoints > min){
                        setentityvar(self, "otgpoints", otgPoints-add);
                    }
                }
            }
            else
            if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9")){
                if(frame >= 2){
                    if(otgPoints > min){
                        setentityvar(self, "otgpoints", otgPoints-add);
                    }
                }
            }
        }
    }
}

void registerOpponent()
{//Register the last opponent when you are in a "falling" instance
 //Used to avoid the opponent "change" when hit other entities in mid-air during a throw/slam, I don't know if it is an engine bug or not
    void self    = getlocalvar("self");
    void target    = getentityproperty(self, "opponent");
    int atkType    = getlocalvar("attacktype");

    //SAVE THE LAST OPPONENT ENTITYVAR
    if(atkType == openborconstant("ATK_NORMAL8") || atkType == openborconstant("ATK_NORMAL9")){
        setentityvar(self, "opponent", target);
    }
}
#import "data/scripts/main.c"

void autoLife(int iHealth, int sample)
{//Recover defined health for all players automatically
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    void partner = getglobalvar("currentPartner");
    int iHealth1 = getentityproperty(player1, "health");
    int iHealth2 = getentityproperty(player2, "health");
    int iHealth3 = getentityproperty(player3, "health");
    int iHealth4 = getentityproperty(player4, "health");
    int iHealth5 = getentityproperty(partner, "health");

    if(iHealth1 > 0){changeentityproperty(player1, "health", iHealth1+iHealth);}
    if(iHealth2 > 0){changeentityproperty(player2, "health", iHealth2+iHealth);}
    if(iHealth3 > 0){changeentityproperty(player3, "health", iHealth3+iHealth);}
    if(iHealth4 > 0){changeentityproperty(player4, "health", iHealth4+iHealth);}
    if(iHealth5 > 0){changeentityproperty(partner, "health", iHealth5+iHealth);}
    if(sample == 1){playsample(openborconstant("SAMPLE_GO"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);}
}

void autoMp(int iMp)
{//Recover defined mp for all players automatically
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    void partner = getglobalvar("currentPartner");
    int iMp1      = getentityproperty(player1, "mp");
    int iMp2      = getentityproperty(player2, "mp");
    int iMp3      = getentityproperty(player3, "mp");
    int iMp4      = getentityproperty(player4, "mp");
    int iMp5      = getentityproperty(partner, "mp");

    if(player1 != NULL()){changeentityproperty(player1, "mp", iMp1+iMp);}
    if(player2 != NULL()){changeentityproperty(player2, "mp", iMp2+iMp);}
    if(player3 != NULL()){changeentityproperty(player3, "mp", iMp3+iMp);}
    if(player4 != NULL()){changeentityproperty(player4, "mp", iMp4+iMp);}
    if(partner != NULL()){changeentityproperty(partner, "mp", iMp5+iMp);}
}

void loadMp(int player)
{//Load last saved mp after death
    void self = getplayerproperty(player, "entity");
    int iMp   = getglobalvar("saveMp"+player);

    if(self != NULL()){
        if(iMp != NULL()){
            changeentityproperty(self, "mp", iMp);
            setglobalvar("saveMp"+player, NULL());
        }
        if(iMp == NULL()){
            if(getglobalvar("fullEnergy") == "never"){
                changeentityproperty(self, "mp", 0);
            }
        }
    }
}

void saveMp(int player)
{//Save current mp when dies
    void self = getplayerproperty(player, "entity");
    int iMp   = getentityproperty(self, "mp");

    setglobalvar("saveMp"+player, iMp);
}

void flipDir()
{//Flip players spawn direction
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    int iDir1      = getentityproperty(player1, "direction");
    int iDir2      = getentityproperty(player2, "direction");
    int iDir3      = getentityproperty(player3, "direction");
    int iDir4      = getentityproperty(player4, "direction");

    if(iDir1 == 0){
        changeentityproperty(player1, "direction", 1);
    }else{
        changeentityproperty(player1, "direction", 0);
    }

    if(iDir2 == 0){
        changeentityproperty(player2, "direction", 1);
    }else{
        changeentityproperty(player2, "direction", 0);
    }

    if(iDir3 == 0){
        changeentityproperty(player3, "direction", 1);
    }else{
        changeentityproperty(player3, "direction", 0);
    }

    if(iDir4 == 0){
        changeentityproperty(player4, "direction", 1);
    }else{
        changeentityproperty(player4, "direction", 0);
    }
}

void spawnX(void name1, void name2, void name3, void name4, float dx, float dy, float dz)
{//Spawns random entity next to caller (4 ENTITIES, ITENS, WEAPONS)
    void vSpawn;
    void vRName;
    int  iR     = rnd(100);
    int  iDir = iR%2;
    float xR     = rand()%240+240;
    float xPos    = openborvariant("xpos");

    dx = xPos+xR;

    if(iR >= 0     && iR < 25){    vRName = name1;}else
    if(iR >= 25 && iR < 50){    vRName = name2;}else
    if(iR >= 50 && iR < 75){    vRName = name3;}else
    if(iR >= 75 && iR <= 100){    vRName = name4;}

    clearspawnentry();
    setspawnentry("name", vRName);

    vSpawn = spawn();

    changeentityproperty(vSpawn, "position", dx, dz, dy);
    changeentityproperty(vSpawn, "direction", iDir);

    return vSpawn;
}
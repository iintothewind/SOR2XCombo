#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self             = getlocalvar("self");
    void vName             = getentityproperty(self,"defaultname");
    void vAlias = NULL();
    void baseName        = "Electra_";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*5;
    float baseSpeed        = getglobalvar("sBase")*2;
    float baseAggre        = getglobalvar("aBase");
    float baseScore        = getglobalvar("pBase")*7;
    float iMHealth;
    float iHealth;
    float iSpeed;
    float iAggre;
    float iScore;
    float iMap;

    if(vName == "Reine_Wait"){ //SPECIFIC FOR THE BAR IN SOR2 STAGE 1
        iMHealth    = baseHealth*4;
        iHealth     = iMHealth;
        iSpeed         = baseSpeed;
        iAggre         = baseAggre;
        iScore         = baseScore;
        iMap        = 0;
    }
    else
    {
        if(level <= 1){
            iMHealth    = baseHealth;
            iHealth     = baseHealth;
            iSpeed         = baseSpeed;
            iAggre         = baseAggre;
            iScore         = baseScore;
            iMap        = level;
        }
        else
        if(level == 2){
            iMHealth    = baseHealth*1.25;
            iHealth     = baseHealth*1.25;
            iSpeed         = baseSpeed;
            iAggre         = baseAggre;
            iScore         = baseScore*1.25;
            iMap        = level;
        }
        else
        if(level == 3){
            iMHealth    = baseHealth*1.5;
            iHealth     = baseHealth*1.5;
            iSpeed         = baseSpeed;
            iAggre         = baseAggre;
            iScore         = baseScore*1.5;
            iMap        = level;
        }
        else
        {
            iMHealth    = baseHealth*2;
            iHealth     = baseHealth*2;
            iSpeed         = baseSpeed;
            iAggre         = baseAggre;
            iScore         = baseScore*2;
            iMap        = level;
        }
    }

    int iR = rand()%8+8;

    if(iR == 1){    vAlias = "Electra";}else
    if(iR == 2){    vAlias = "Whip";}else
    if(iR == 3){    vAlias = "Nora";}else
    if(iR == 4){    vAlias = "Ivy";}else
    if(iR == 5){    vAlias = "Caska";}else
    if(iR == 6){    vAlias = "Enola";}else
    if(iR == 7){    vAlias = "Eldy";}else
    if(iR == 8){    vAlias = "Zora";}else
    if(iR == 9){    vAlias = "Bloody";}else
    if(iR == 10){    vAlias = "Reine";}else
    if(iR == 11){    vAlias = "Dallala";}else
    if(iR == 12){    vAlias = "Vine";}else
    if(iR == 13){    vAlias = "Thundra";}else
    if(iR == 14){    vAlias = "Lorena";}else
    if(iR == 15){    vAlias = "Gloria";}else
    {vAlias = "Electra";}

    onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
    applyAtt(baseName, 1);
}
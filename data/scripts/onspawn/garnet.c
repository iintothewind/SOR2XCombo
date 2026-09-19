#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vAlias = NULL();
    void baseName        = "Garnet";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*2;
    float baseSpeed        = getglobalvar("sBase")*2;
    float baseAggre        = getglobalvar("aBase");
    float baseScore        = getglobalvar("pBase");
    float iMHealth;
    float iHealth;
    float iSpeed;
    float iAggre;
    float iScore;
    float iMap;

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

    int iR = rand()%4+4;

    if(iR == 1){    vAlias = "Garnet";}else
    if(iR == 2){    vAlias = "Soozie";}else
    if(iR == 3){    vAlias = "Rubby";}else
    if(iR == 4){    vAlias = "Grace";}else
    if(iR == 5){    vAlias = "Diamond";}else
    if(iR == 6){    vAlias = "Emma";}else
    {vAlias = "Garnet";}

    onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
    applyAtt(baseName, 0);
}
#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vAlias = NULL();
    void baseName        = "Roo";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*10;
    float baseAggre        = getglobalvar("aBase");
    float baseScore        = getglobalvar("pBase")*10;
    float iMHealth;
    float iHealth;
    float iAggre;
    float iScore;
    float iMap;

    if(level <= 1){
        iMHealth    = baseHealth;
        iHealth     = baseHealth;
        iAggre         = baseAggre;
        iScore         = baseScore;
        iMap        = level;
    }
    else
    if(level == 2){
        iMHealth    = baseHealth*1.25;
        iHealth     = baseHealth*1.25;
        iAggre         = baseAggre;
        iScore         = baseScore;
        iMap        = level;
    }
    else
    if(level == 3){
        iMHealth    = baseHealth*1.5;
        iHealth     = baseHealth*1.5;
        iAggre         = baseAggre;
        iScore         = baseScore*1.5;
        iMap        = level;
    }
    else
    {
        iMHealth    = baseHealth*2;
        iHealth     = baseHealth*2;
        iAggre         = baseAggre;
        iScore         = baseScore*2;
        iMap        = level;
    }

    if(level == 4){vAlias = "Pikachu";}else
    if(level == 3){vAlias = "Micky";}else
    if(level == 2){vAlias = "Sonic";}else
    if(level == 1){vAlias = "Vicky";}else
    {vAlias = "Roo";}

    onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);
    applyAtt(baseName, 1);
}
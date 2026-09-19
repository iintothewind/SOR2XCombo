#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vAlias = NULL();
    void baseName        = "Harakiri";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*12;
    float baseAggre        = getglobalvar("aBase")/2;
    float baseScore        = getglobalvar("pBase")*25;
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

    if(level == 4){vAlias = "Sauske";}else
    if(level == 3){vAlias = "Yasuke";}else
    if(level == 2){vAlias = "Bushido";}else
    if(level == 1){vAlias = "Sanada";}else
    {vAlias = "Harakiri";}

    onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);
    applyAtt(baseName, 1);
}
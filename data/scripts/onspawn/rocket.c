#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vName              = getentityproperty(self,"defaultname");
    void vAlias = NULL();
    void baseName        = "Jet_";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*10;
    float baseSpeed        = getglobalvar("sBase")*2;
    float baseAggre        = getglobalvar("aBase")/2;
    float baseScore        = getglobalvar("pBase")*10;
    float iMHealth;
    float iHealth;
    float iSpeed;
    float iAggre;
    float iScore;
    float iMap;

    if(vName == "RocketB"){
        vAlias        = "Jet";

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

        onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);
        applyAtt(baseName, 1);
    }
    else
    if(vName == "Rocket_Enemy"){
        if(level >= 0){
            vAlias        = "Rocket";
            iMHealth    = baseHealth/3;
            iHealth     = iMHealth;
            iSpeed         = baseSpeed;
            iAggre         = baseAggre;
            iScore         = baseScore/3;
            iMap        = level;
        }

        onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
        applyAtt(baseName, 0);
    }
}
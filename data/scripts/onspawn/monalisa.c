#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vAlias = NULL();
    void sister = NULL();
    void baseName        = "Monalisa";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*10;
    float baseAggre        = getglobalvar("aBase")/2;
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

    if(level == 4){vAlias = "Mona";sister = "MonalisaB";} else
    if(level == 3){vAlias = "Lisa";} else
    if(level == 2){vAlias = "Mona";sister = "MonalisaC";} else
    if(level == 1){vAlias = "Lisa";}else
    {vAlias = "Mona";sister = "Monalisa_Wait2";}
    onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);
    applyAtt(baseName, 1);

    if(sister != NULL()){
        //SPAWN SISTER AND SET BOSS FLAG ON HERE
        if(openborvariant("current_branch") == "sor3_st2c"){
            spawnVar(sister, "sister", 10, 0, 1, 1, 1);
        }
        else
        if(openborvariant("current_branch") == "sor3_st8b"){
            spawnVar(sister, "sister", 10, 0, 1, 0, 3);
        }
        else {
            spawnVar(sister, "sister", 10, 0, 1, 0, 3);
        }
    }
}
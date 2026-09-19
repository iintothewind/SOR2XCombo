#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self              = getlocalvar("self");
    void vAlias = NULL();
    void baseName        = "Bruce";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*3;
    float baseSpeed        = getglobalvar("sBase")*2;
    float baseAggre        = getglobalvar("aBase");
    float baseScore        = getglobalvar("pBase")*3;
    void model     = getentityproperty(self, "model");
    float iMHealth;
    float iHealth;
    float iSpeed;
    float iAggre;
    float iScore;
    float iMap;

    if(model == "Tamer") {
        baseScore        = getglobalvar("pBase")*5;
        baseHealth    = hBase*5;
        iMHealth    = baseHealth*2;
        iHealth     = baseHealth*1.5;
        iSpeed         = baseSpeed*1.2;
        iAggre         = baseAggre*2;
        iScore         = baseScore*2;
        iMap        = level;
    }
    else
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

    if(model == "Tamer"){vAlias = "Master";}else
    if(level == 4){vAlias = "Joker";}else
    if(level == 3){vAlias = "Stalker";}else
    if(level == 2){vAlias = "Predator";}else
    if(level == 1){vAlias = "Hunter";}else
    {vAlias = "Bruce";}


    onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
    applyAtt(baseName, 0);

    if(model == "Tamer") {
        spawnVar("RooB", "Pikachu", 20, 0, -1, 0, 5);
    }
}
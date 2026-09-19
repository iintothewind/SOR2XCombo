#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
    void self             = getlocalvar("self");
    void vAlias = NULL();
    void baseName        = "Kusanagi";
    int level            = getentityproperty(self,"map");
    float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
    float baseHealth    = hBase*3;
    float baseSpeed        = getglobalvar("sBase")*2;
    float baseAggre        = getglobalvar("aBase");
    float baseScore        = getglobalvar("pBase")*2;
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

    int iR = rand()%10+10;

    if(iR == 1){    vAlias = "Kusanagi";}else
    if(iR == 2){    vAlias = "Ryouhin";}else
    if(iR == 3){    vAlias = "Ranzou";}else
    if(iR == 4){    vAlias = "Izayoi";}else
    if(iR == 5){    vAlias = "Setsura";}else
    if(iR == 6){    vAlias = "Unsai";}else
    if(iR == 7){    vAlias = "Tenzen";}else
    if(iR == 8){    vAlias = "Kanzou";}else
    if(iR == 9){    vAlias = "Jay";}else
    if(iR == 10){    vAlias = "Huwa";}else
    if(iR == 11){    vAlias = "Hanzou";}else
    if(iR == 12){    vAlias = "Yagasira";}else
    if(iR == 13){    vAlias = "Genyosai";}else
    if(iR == 14){    vAlias = "Buoh";}else
    if(iR == 15){    vAlias = "Mutsu";}else
    if(iR == 16){    vAlias = "Mifune";}else
    if(iR == 17){    vAlias = "Kosugi";}else
    if(iR == 18){    vAlias = "Chiba";}else
    {vAlias = "Kusanagi";}

    onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
    applyAtt(baseName, 0);
}
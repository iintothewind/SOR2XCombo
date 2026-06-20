#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self 			= getlocalvar("self");
	void vAlias = NULL();
	void baseName		= "Bongo";
	int level			= getentityproperty(self,"map");
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*3;
	float baseSpeed		= getglobalvar("sBase")*2;
	float baseAggre		= getglobalvar("aBase");
	float baseScore		= getglobalvar("pBase")*3;
	float iMHealth;
	float iHealth;
	float iSpeed;
	float iAggre;
	float iScore;
	float iMap;

	if(level <= 1){
		iMHealth	= baseHealth;
		iHealth 	= baseHealth;
		iSpeed 		= baseSpeed;
		iAggre 		= baseAggre;
		iScore 		= baseScore;
		iMap		= level;
	}
	else
	if(level == 2){
		iMHealth	= baseHealth*1.25;
		iHealth 	= baseHealth*1.25;
		iSpeed 		= baseSpeed;
		iAggre 		= baseAggre;
		iScore 		= baseScore*1.25;
		iMap		= level;
	}
	else
	if(level == 3){
		iMHealth	= baseHealth*1.5;
		iHealth 	= baseHealth*1.5;
		iSpeed 		= baseSpeed;
		iAggre 		= baseAggre;
		iScore 		= baseScore*1.5;
		iMap		= level;
	}
	else
	{
		iMHealth	= baseHealth*2;
		iHealth 	= baseHealth*2;
		iSpeed 		= baseSpeed;
		iAggre 		= baseAggre;
		iScore 		= baseScore*2;
		iMap		= level;
	}

	int iR = rand()%7+7;

	if(iR == 1){	vAlias = "BigBen";}else
	if(iR == 2){	vAlias = "Balloon";}else
	if(iR == 3){	vAlias = "Bongo";}else
	if(iR == 4){	vAlias = "Golba";}else
	if(iR == 5){	vAlias = "Dante";}else
	if(iR == 6){	vAlias = "Titan";}else
	if(iR == 7){	vAlias = "BigGo";}else
	if(iR == 8){	vAlias = "Heart";}else
	if(iR == 9){	vAlias = "Gourmand";}else
	if(iR == 10){	vAlias = "Buffet";}else
	if(iR == 11){	vAlias = "Anry";}else
	if(iR == 12){	vAlias = "Dwight";}else
	if(iR == 13){	vAlias = "Ike";}else
	{vAlias = "Bongo";}

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
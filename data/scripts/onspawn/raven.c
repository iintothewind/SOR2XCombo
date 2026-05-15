#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self 			= getlocalvar("self");
	void vAlias = NULL();
	void baseName		= "Raven";
	int level			= getentityproperty(self,"map");
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*3;
	float baseSpeed		= getglobalvar("sBase")*2;
	float baseAggre		= getglobalvar("aBase");
	float baseScore		= getglobalvar("pBase")*2;
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

	if(iR == 1){	vAlias = "Raven";}else
	if(iR == 2){	vAlias = "Eagle";}else
	if(iR == 3){	vAlias = "Condor";}else
	if(iR == 4){	vAlias = "Falcon";}else
	if(iR == 5){	vAlias = "Sparrow";}else
	if(iR == 6){	vAlias = "Thrush";}else
	if(iR == 7){	vAlias = "Phoenix";}else
	if(iR == 8){	vAlias = "Galuda";}else
	if(iR == 9){	vAlias = "Pheasant";}else
	if(iR == 10){	vAlias = "Bantam";}else
	if(iR == 11){	vAlias = "Ibis";}else
	if(iR == 12){	vAlias = "Raptor";}else
	{vAlias = "Raven";}

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
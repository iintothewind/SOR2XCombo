#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self			= getlocalvar("self");
	void vAlias = NULL();
	void baseName		= "Galsia";
	int level			= getentityproperty(self,"map");
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*2;
	float baseSpeed		= getglobalvar("sBase")*2;
	float baseAggre		= getglobalvar("aBase");
	float baseScore		= getglobalvar("pBase");
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

	int iR = rand()%6+6;

	if(iR == 1){	vAlias = "Galsia";}else
	if(iR == 2){	vAlias = "Joseph";}else
	if(iR == 3){	vAlias = "Surger";}else
	if(iR == 4){	vAlias = "B.T.";}else
	if(iR == 5){	vAlias = "Brash";}else
	if(iR == 6){	vAlias = "Jonathan";}else
	if(iR == 7){	vAlias = "Garam";}else
	if(iR == 8){	vAlias = "Talk";}else
	if(iR == 9){	vAlias = "Garcia";}else
	if(iR == 10){	vAlias = "Carlos";}else
	if(iR == 11){	vAlias = "Julio";}else
	{vAlias = "Galsia";}

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
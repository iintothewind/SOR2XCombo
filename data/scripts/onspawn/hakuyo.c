#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self 			= getlocalvar("self");
	void vAlias = NULL();
	void baseName		= "Hakuyo";
	int level			= getentityproperty(self,"map");
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*3;
	float addHealth		= baseHealth/4;
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

	if(iR == 1){	vAlias = "Hakuyo";}else
	if(iR == 2){	vAlias = "Kahoh";}else
	if(iR == 3){	vAlias = "Rakan";}else
	if(iR == 4){	vAlias = "Kongoh";}else
	if(iR == 5){	vAlias = "Ashurah";}else
	if(iR == 6){	vAlias = "Ryokurou";}else
	if(iR == 7){	vAlias = "Suzaku";}else
	if(iR == 8){	vAlias = "KoKaku";}else
	if(iR == 9){	vAlias = "KoShu";}else
	if(iR == 10){	vAlias = "Byatcko";}else
	if(iR == 11){	vAlias = "Hakuro";}else
	if(iR == 12){	vAlias = "Seiryu";}else
	if(iR == 13){	vAlias = "Suicho";}else
	{vAlias = "Hakuyo";}

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
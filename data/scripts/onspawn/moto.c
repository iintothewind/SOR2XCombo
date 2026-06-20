#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self 			= getlocalvar("self");
	void vName 			= getentityproperty(self,"defaultname");
	void vAlias = NULL();
	void baseName		= "Fog";
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*3;
	float baseSpeed		= getglobalvar("sBase")*4;
	float baseAggre		= getglobalvar("aBase");
	float baseScore		= getglobalvar("pBase");
	float iMHealth;
	float iHealth;
	float iSpeed;
	float iAggre;
	float iScore;
	float iMap;

	if(vName == "Moto_Single" || vName == "Moto_Jump" || vName == "Moto_Repeat"){
		iMHealth	= 1;
		iHealth 	= iMHealth;
		iSpeed 		= baseSpeed;
		iAggre 		= baseAggre;
		iScore 		= baseScore*10;
	}
	else
	if(vName == "Moto_Stage"){
		iMHealth = baseHealth*4;
		iHealth  = iMHealth;
		iSpeed 	 = baseSpeed;
		iAggre 	 = baseAggre;
		iScore 	 = baseScore*100;
	}

	//RANDOM PALETTES
	int iR1 = rand()%50+50;

	if(iR1 >= 0 && iR1 < 20){
		iMap = 0;
	}
	else
	if(iR1 >= 20 && iR1 < 40){
		iMap = 1;
	}
	else
	if(iR1 >= 40 && iR1 < 60){
		iMap = 2;
	}
	else
	if(iR1 >= 60 && iR1 < 80){
		iMap = 3;
	}
	else
	if(iR1 >= 80 && iR1 <= 100){
		iMap = 4;
	}

	//RANDOM NAMES
	int iR2 = rand()%9+9;

	if(iR2 == 1){	vAlias = "Fog";}else
	if(iR2 == 2){	vAlias = "Gale";}else
	if(iR2 == 3){	vAlias = "Frost";}else
	if(iR2 == 4){	vAlias = "Storm";}else
	if(iR2 == 5){	vAlias = "Tempest";}else
	if(iR2 == 6){	vAlias = "Hail";}else
	if(iR2 == 7){	vAlias = "Mist";}else
	if(iR2 == 8){	vAlias = "Calm";}else
	if(iR2 == 9){	vAlias = "Dew";}else
	if(iR2 == 10){	vAlias = "Gust";}else
	if(iR2 == 11){	vAlias = "Typhoon";}else
	if(iR2 == 12){	vAlias = "Tornado";}else
	if(iR2 == 13){	vAlias = "Blade";}else
	if(iR2 == 14){	vAlias = "Wanter";}else
	if(iR2 == 15){	vAlias = "Cyclone";}else
	if(iR2 == 16){	vAlias = "Wings";}else
	{vAlias = "Fog";}

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
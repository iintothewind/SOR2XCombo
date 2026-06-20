#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self 			= getlocalvar("self");
	void vName 			= getentityproperty(self,"defaultname");
	void vAlias = NULL();
	void baseName		= "Fog";
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

	if(vName == "Fog_Grenadier"){ //SPECIFIC FOR ALL FOG GRENADIERS
		iMHealth	= baseHealth;
		iHealth 	= iMHealth;
		iSpeed 		= 0;
		iAggre 		= 200;
		iScore 		= 0;
		iMap		= 0;
	}
	else
	{
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
	}

	int iR = rand()%9+9;

	if(iR == 1){	vAlias = "Fog";}else
	if(iR == 2){	vAlias = "Gale";}else
	if(iR == 3){	vAlias = "Frost";}else
	if(iR == 4){	vAlias = "Storm";}else
	if(iR == 5){	vAlias = "Tempest";}else
	if(iR == 6){	vAlias = "Hail";}else
	if(iR == 7){	vAlias = "Mist";}else
	if(iR == 8){	vAlias = "Calm";}else
	if(iR == 9){	vAlias = "Dew";}else
	if(iR == 10){	vAlias = "Gust";}else
	if(iR == 11){	vAlias = "Typhoon";}else
	if(iR == 12){	vAlias = "Tornado";}else
	if(iR == 13){	vAlias = "Blade";}else
	if(iR == 14){	vAlias = "Wanter";}else
	if(iR == 15){	vAlias = "Cyclone";}else
	if(iR == 16){	vAlias = "Wings";}else
	{vAlias = "Fog";}

	if(vName != "Fog_Grenadier"){
		onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
		applyAtt(baseName, 0);
	}else{
		changeentityproperty(self, "name", vAlias); //Set alias.
		changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
		changeentityproperty(self, "health", iHealth); //Set health.
		changeentityproperty(self, "speed", iSpeed); //Set speed.
		changeentityproperty(self, "aggression", iAggre); //Set aggression.
		changeentityproperty(self, "score", iScore); //Set score.
		changeentityproperty(self, "map", iMap); //Set map.
		changeentityproperty(self, "hostile", "type_player", "type_npc"); //SET HOSTILE.
		changeentityproperty(self, "candamage", "type_player", "type_enemy", "type_npc", "type_obstacle"); //SET CANDAMAGE.
	}
}
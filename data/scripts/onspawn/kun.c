#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self			= getlocalvar("self");
	void vAlias = "PunchBag.Kun";
	void baseName		= "Kun";
	int level			= getentityproperty(self,"map");
	float hBase = getglobalvar("hBase")*loadEnemyLifeRate();
	float baseHealth	= hBase*99;
	float baseSpeed		= getglobalvar("sBase")*2;
	float baseAggre		= getglobalvar("aBase");
	float baseScore		= getglobalvar("pBase");
	float iMHealth = baseHealth;
	float iHealth = baseHealth/2;
	float iSpeed = baseSpeed;
	float iAggre = baseAggre;
	float iScore = baseScore;
	float iMap = level;

	onspawnEnemy(vAlias, iMHealth, iHealth, iSpeed, iAggre, iScore, iMap);
	applyAtt(baseName, 0);
}
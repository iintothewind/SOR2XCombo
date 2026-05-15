#import "data/scripts/onspawn/main.c"

void main()
{
	void self 		 	= getlocalvar("self");
	void vAlias = NULL();
	float hBase = getglobalvar("hBase");
	float baseHealth	= hBase*4;
	float baseAggre		= 200;
	float baseScore		= getglobalvar("pBase")*5;
	float baseMap		= 0;
	float iMHealth;
	float iHealth;
	float iAggre;
	float iScore;
	float iMap;

	vAlias		= "Dr._Zero";
	iMHealth	= baseHealth;
	iHealth 	= iMHealth;
	iAggre 		= baseAggre;
	iScore 		= baseScore;
	iMap		= baseMap;

	onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);
}
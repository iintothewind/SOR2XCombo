#import "data/scripts/onspawn/main.c"

void main()
{
	void self 		 	= getlocalvar("self");
	void vAlias = NULL();
	float hBase = getglobalvar("hBase");
	float baseHealth	= hBase*3;
	float baseAggre		= getglobalvar("aBase")/2;
	float baseScore		= getglobalvar("pBase")*5;
	float baseMap		= 0;
	float iMHealth;
	float iHealth;
	float iAggre;
	float iScore;
	float iMap;

	vAlias		= "Vehelits";
	iMHealth	= baseHealth;
	iHealth 	= iMHealth;
	iAggre 		= baseAggre;
	iScore 		= baseScore;
	iMap		= baseMap;

	onspawnBoss(vAlias, iMHealth, iHealth, iAggre, iScore, iMap);

	void entity		= "Vehelits_Tail";
	void newAlias	= "Tail";
	int tailStart 	= 19;
	int tailAdd	 	= 1;
	int layerStart	= -190;
	int layerAdd	= 10;
	int tail  		= tailStart;
	int layer 		= layerStart;

	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);tail = tail-tailAdd;layer = layer+layerAdd;
	spawnAlias(entity, newAlias+tail, 0, 0, layer);
}
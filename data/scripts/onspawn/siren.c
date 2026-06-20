#import "data/scripts/animation/main_spawns.c"

void main()
{
	void self	= getlocalvar("self");
	void vSpawn	= spawn01("St7_Siren", -97, 0, -152);

	changeentityproperty(self, "parent", vSpawn);
}
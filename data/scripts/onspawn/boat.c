#import "data/scripts/onspawn/main.c"

void main()
{
	void self	= getlocalvar("self");
	void alias	= getentityproperty(self, "name");
	
	if(alias == "Boat_Last"){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));}
}
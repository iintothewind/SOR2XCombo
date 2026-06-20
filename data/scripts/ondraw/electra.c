#import "data/scripts/ondraw/main.c"
#import "data/scripts/main.c"

void main()
{
	void self = getlocalvar("self");
	void type = getentityproperty(self, "type");

	if(type == openborconstant("TYPE_PLAYER")){
		jumpVel();
		parrow();
	}

	if(type == openborconstant("TYPE_NPC")){
		parrowPartner();
		drawLife();
	}

	debugMode();
	grabIdle("ANI_GRABATTACK", 0);
}
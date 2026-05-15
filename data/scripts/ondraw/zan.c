#import "data/scripts/ondraw/main.c"
#import "data/scripts/main.c"

void main()
{
	void self = getlocalvar("self");
	void type = getentityproperty(self, "type");

	if(type == openborconstant("TYPE_PLAYER")){
		jumpVel();
		parrow();
		motorBike("Zan_Bike");
	}

	if(type == openborconstant("TYPE_NPC")){
		parrowPartner();
		drawLife();
		motorBike("Zan_Bike_");
	}

	debugMode();
	superArmor();
	grabIdle("ANI_GRABATTACK", 0);
	checkText("ANI_FREESPECIAL", "RAGE");
	checkText("ANI_FREESPECIAL2", "SUPER");
}
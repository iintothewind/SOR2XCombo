#import "data/scripts/ondraw/main.c"
#import "data/scripts/main.c"

void main()
{
	void self = getlocalvar("self");
	void type = getentityproperty(self, "type");

	if(type == openborconstant("TYPE_PLAYER")){
		jumpVel();
		parrow();
		motorBike("Axel_Bike");
	}

	if(type == openborconstant("TYPE_NPC")){
		parrowPartner();
		drawLife();
		motorBike("Axel_Bike_");
	}

	debugMode();
	checkText("ANI_FREESPECIAL", "RAGE");
	checkText("ANI_FREESPECIAL2", "SUPER");
}
#import "data/scripts/ondraw/main.c"
#import "data/scripts/main.c"

void main()
{
	void self = getlocalvar("self");
	void type = getentityproperty(self, "type");

	if(type == openborconstant("TYPE_PLAYER")){
		jumpVel();
		parrow();
		motorBike("Sammy_Bike");
	}

	if(type == openborconstant("TYPE_NPC")){
		parrowPartner();
		drawLife();
		motorBike("Sammy_Bike_");
	}

	debugMode();
	superArmor();
	grabIdle("ANI_GRABATTACK", 1);
	grabIdle("ANI_GRABDOWN2", 1);
	checkText("ANI_FREESPECIAL", "RAGE");
	checkText("ANI_FOLLOW3", "RAGE");
	checkText("ANI_FREESPECIAL2", "SUPER");
}
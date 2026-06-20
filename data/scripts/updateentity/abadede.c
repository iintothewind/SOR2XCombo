#import "data/scripts/updateentity/main.c"

void main()
{
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	void type = getentityproperty(self, "type");

	if(ani == openborconstant("ANI_FREESPECIAL") ||
	   ani == openborconstant("ANI_FREESPECIAL3") ||
	   ani == openborconstant("ANI_FOLLOW1") ||
		 ani == openborconstant("ANI_FOLLOW7")||
		 ani == openborconstant("ANI_DODGE")){
		if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_ENEMY")){
			afterImage("AbadedeS", 1);
		}
	}
}
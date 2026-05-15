#import "data/scripts/updateentity/main.c"

void main()
{
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	cancelGrab();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	void type = getentityproperty(self, "type");

	if(ani == openborconstant("ANI_FREESPECIAL")||ani == openborconstant("ANI_FOLLOW7")||ani == openborconstant("ANI_DODGE")){
		afterImage("NeoxS", 1);
	}
}

void cancelGrab()
{//Cancel special moves with back attack if grabbed from back (ENEMIES ONLY, MCBRIDE/BEAR "BACK" ATTACKS)
	void self 	= getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self,"animpos");
	void target = getentityproperty(self, "opponent");
	int dead	= getentityproperty(target,"dead");
	int health = getentityproperty(target,"health");

	if(ani == openborconstant("ANI_FOLLOW1") && frame > 5
	&& target != NULL() && dead == 0 && health > 0) {
		performattack(self, openborconstant("ANI_FOLLOW3"), 1);
	}
}
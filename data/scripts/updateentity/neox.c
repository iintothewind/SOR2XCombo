#import "data/scripts/main.c"
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

	if(!selfAlive()){return;}

	if(ani == openborconstant("ANI_FREESPECIAL")||ani == openborconstant("ANI_FOLLOW7")||ani == openborconstant("ANI_DODGE")){
		afterImage("NeoxS", 1);
	}
}

void cancelGrab()
{//Cancel special moves with back attack if grabbed from back (ENEMIES ONLY, MCBRIDE/BEAR "BACK" ATTACKS)
	void self 	= getlocalvar("self");

	if(!selfAlive()){return;}

	void ani  = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self,"animpos");
	void target = getentityproperty(self, "opponent");

	if(ani == openborconstant("ANI_FOLLOW1") && frame > 5
	&& entityAlive(target)) {
		performattack(self, openborconstant("ANI_FOLLOW3"), 1);
	}
}

#import "data/scripts/main.c"
#import "data/scripts/updateentity/main.c"

void main()
{
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	energyRecover();
	dojoEnergyRecover();
	adjustLives();
  screen(1);
	// cancelGrab();
	freeGrabbed();
}

void cancelGrab()
{//Cancel special moves with back attack if grabbed from back (ENEMIES ONLY, MCBRIDE/BEAR "BACK" ATTACKS)
	void self 	= getlocalvar("self");

	if(!selfAlive()){return;}

	void ani  = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self,"animpos");
	void target = getentityproperty(self, "opponent");

	if(ani == openborconstant("ANI_FREESPECIAL9")
	&& frame > 2
	&& entityAlive(target)) {
		performattack(self, openborconstant("ANI_FOLLOW3"), 1);
	}
}
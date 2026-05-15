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
	void ani  = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self,"animpos");
	void target = getentityproperty(self, "opponent");
	int dead	= getentityproperty(target,"dead");
	int health = getentityproperty(target,"health");

	if(ani == openborconstant("ANI_FREESPECIAL9")
	&& frame > 2
	&& target != NULL() && dead == 0 && health > 0) {
		performattack(self, openborconstant("ANI_FOLLOW3"), 1);
	}
}
#import "data/scripts/updateentity/main.c"

void main()
{
  airGrabCheck2();
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	energyRecover();
	dojoEnergyRecover();
	adjustLives();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self 	= getlocalvar("self");
	void type 	= getentityproperty(self, "type");
	void ani 	= getentityproperty(self, "animationID");
	void model 	= getentityproperty(self, "model");

  // if(model == "Kage") {
    // if(ani == openborconstant("ANI_SPECIAL2")) {
    //   afterImage("ChunliS", 1);
    // }
  // }
  // if(model != "Kage") {
    // if(ani == openborconstant("ANI_FOLLOW21")
    // || ani == openborconstant("ANI_FOLLOW22")){
    //   afterImage("ChunliS", 1);
    // }
  // }

	if(ani == openborconstant("ANI_GRABATTACK")
  || ani == openborconstant("ANI_GRABBACKWARD2")
  || ani == openborconstant("ANI_GRABUP")
  || ani == openborconstant("ANI_GRABDOWN2")
  || ani == openborconstant("ANI_RUNATTACK")
  || ani == openborconstant("ANI_RISEATTACK")
  || ani == openborconstant("ANI_FREESPECIAL")
  || ani == openborconstant("ANI_FREESPECIAL2")
  || ani == openborconstant("ANI_FOLLOW1")
  || ani == openborconstant("ANI_FOLLOW3")
  || ani == openborconstant("ANI_FOLLOW7")
  || ani == openborconstant("ANI_FOLLOW10")
  || ani == openborconstant("ANI_DODGE")){
    afterImage("KageS", 1);
	}

	if(ani == openborconstant("ANI_GRABDOWN")){
    afterImage("KageS", 1);
	}
}
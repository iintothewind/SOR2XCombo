#import "data/scripts/updateentity/main.c"

void main()
{
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
    void self     = getlocalvar("self");
    void type     = getentityproperty(self, "type");
    void ani     = getentityproperty(self, "animationID");
    void model     = getentityproperty(self, "model");

  if(model == "Chunli") {
    if(ani == openborconstant("ANI_SPECIAL2")) {
      afterImage("ChunliS", 1);
    }
  }
  if(model != "Chunli") {
    if(ani == openborconstant("ANI_FOLLOW21")
    || ani == openborconstant("ANI_FOLLOW22")){
      afterImage("ChunliS", 1);
    }
  }
    if(ani == openborconstant("ANI_FREESPECIAL")
  || ani == openborconstant("ANI_FREESPECIAL2")
  || ani == openborconstant("ANI_FREESPECIAL3")
  || ani == openborconstant("ANI_FREESPECIAL20")
  || ani == openborconstant("ANI_GRABATTACK")
  || ani == openborconstant("ANI_GRABATTACK2")
  || ani == openborconstant("ANI_RUNATTACK")
  || ani == openborconstant("ANI_RISEATTACK")
  || ani == openborconstant("ANI_FOLLOW1")
  || ani == openborconstant("ANI_FOLLOW2")
  || ani == openborconstant("ANI_FOLLOW7")
  || ani == openborconstant("ANI_FOLLOW10")
  || ani == openborconstant("ANI_DODGE")){
    afterImage("ChunliS", 1);
    }
}
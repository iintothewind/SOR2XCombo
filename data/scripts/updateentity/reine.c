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
    void self     = getlocalvar("self");
    void type     = getentityproperty(self, "type");
    void ani     = getentityproperty(self, "animationID");
    void model     = getentityproperty(self, "model");

  if(model == "Electra_") {
        if(ani == openborconstant("ANI_ATTACK7")
        || ani == openborconstant("ANI_ATTACK8")
        || ani == openborconstant("ANI_ATTACK9")
        || ani == openborconstant("ANI_GRABATTACK")
        || ani == openborconstant("ANI_RUNATTACK")
        || ani == openborconstant("ANI_SPECIAL")
        || ani == openborconstant("ANI_SPECIAL2")
        || ani == openborconstant("ANI_FREESPECIAL")
        || ani == openborconstant("ANI_FREESPECIAL2")){
            afterImage("Reines", 1);
        }
  }

  if(model != "Electra_") {
        if(ani == openborconstant("ANI_FREESPECIAL")
        || ani == openborconstant("ANI_FREESPECIAL2")
        || ani == openborconstant("ANI_FREESPECIAL3")
        || ani == openborconstant("ANI_FREESPECIAL4")
        || ani == openborconstant("ANI_FREESPECIAL5")
        || ani == openborconstant("ANI_FREESPECIAL7")){
            afterImage("Reines", 1);
        }
    }

}
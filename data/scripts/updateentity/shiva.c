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
    void self = getlocalvar("self");
    void vModel    = getentityproperty(self,"model");
    void ani  = getentityproperty(self, "animationID");
    void type = getentityproperty(self, "type");

    if(ani == openborconstant("ANI_FREESPECIAL")
    || ani == openborconstant("ANI_FREESPECIAL5")
    || ani == openborconstant("ANI_FREESPECIAL6")
    || ani == openborconstant("ANI_RISEATTACK")
    || ani == openborconstant("ANI_RUNATTACK")
    || ani == openborconstant("ANI_FOLLOW1")
    || ani == openborconstant("ANI_FOLLOW3")
    || ani == openborconstant("ANI_FOLLOW7")
    || ani == openborconstant("ANI_FOLLOW10")
    || ani == openborconstant("ANI_DODGE")){
        afterImage("ShivaS", 1);
    }

    if(vModel != "Shiva") {
        if(ani == openborconstant("ANI_DODGE")
        || ani == openborconstant("ANI_FREESPECIAL4")){
            afterImage("ShivaS", 1);
        }
    }

    if(vModel == "Shiva_Double") {
        if(ani == openborconstant("ANI_ATTACK9")){
            afterImage("ShivaS", 1);
        }
    }
}
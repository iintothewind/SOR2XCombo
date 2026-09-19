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
    void ani     = getentityproperty(self, "animationID");
    void model     = getentityproperty(self, "model");

    if(ani == openborconstant("ANI_FREESPECIAL")
    || ani == openborconstant("ANI_FREESPECIAL2")
    || ani == openborconstant("ANI_FREESPECIAL3")
    || ani == openborconstant("ANI_FOLLOW1")
    || ani == openborconstant("ANI_FOLLOW4")
    || ani == openborconstant("ANI_FOLLOW7")
    || ani == openborconstant("ANI_FOLLOW10")
    || ani == openborconstant("ANI_DODGE")){
        if(model != "Blaze_Knife" && model != "Blaze_Sword"){afterImage("BlazeS", 1);}
        if(model == "Blaze_Knife"){afterImage("BlazeSW", 1);}
    }
}
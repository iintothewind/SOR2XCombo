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

    if(ani == openborconstant("ANI_FREESPECIAL") ||
       ani == openborconstant("ANI_FOLLOW10") ||
       ani == openborconstant("ANI_DODGE")){
        if(model == "Zan"){afterImage("ZanS", 1);}
        if(model != "Zan"){afterImage("ZanSW", 1);}
    }

    if(getglobalvar("graphicEffects") == "sor2x"){
        if(ani == openborconstant("ANI_FREESPECIAL2")||
           ani == openborconstant("ANI_FOLLOW7")||
             ani == openborconstant("ANI_JUMPATTACK") ||
           ani == openborconstant("ANI_RISEATTACK")){
           afterImage("ZanS", 1);
        }
    }
}
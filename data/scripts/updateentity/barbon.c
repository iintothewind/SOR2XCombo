#import "data/scripts/updateentity/main.c"

void main()
{
    afterEffect();
    blinkEffect();
    otg();
    versusDamage();
    runMove();
    freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
    void self = getlocalvar("self");
    void ani  = getentityproperty(self, "animationID");
    void type = getentityproperty(self, "type");

    if(ani == openborconstant("ANI_FREESPECIAL")||ani == openborconstant("ANI_FREESPECIAL4")){
        afterImage("BarbonS", 1);
    }

    if(getglobalvar("graphicEffects") == "sor2x"){
        if(ani == openborconstant("ANI_FOLLOW7")||ani == openborconstant("ANI_DODGE")){
            afterImage("BarbonS", 1);
        }
    }
}
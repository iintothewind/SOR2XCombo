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
    void self  = getlocalvar("self");
    void ani   = getentityproperty(self, "animationID");

        if(ani == openborconstant("ANI_SPECIAL")
        || ani == openborconstant("ANI_SPECIAL2")
        || ani == openborconstant("ANI_FREESPECIAL2")
        || ani == openborconstant("ANI_FREESPECIAL9")){
            afterImage("RooS", 1);
        }

    if(getglobalvar("graphicEffects") == "sor2x"){
        if(ani == openborconstant("ANI_RISEATTACK") || ani == openborconstant("ANI_FOLLOW10") || ani == openborconstant("ANI_DODGE")){
            afterImage("RooS", 0);
        }
    }
}
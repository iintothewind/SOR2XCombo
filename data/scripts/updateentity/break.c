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
    void self     = getlocalvar("self");
    void ani     = getentityproperty(self, "animationID");
    void type      = getentityproperty(self, "type");

    if(ani == openborconstant("ANI_FREESPECIAL")
    || ani == openborconstant("ANI_FREESPECIAL2")
    || ani == openborconstant("ANI_FREESPECIAL6")
    || ani == openborconstant("ANI_FOLLOW3")
    || ani == openborconstant("ANI_FOLLOW7")
    || ani == openborconstant("ANI_FOLLOW10")
    || ani == openborconstant("ANI_RISEATTACK")
    || ani == openborconstant("ANI_DODGE")){
        if(type == openborconstant("TYPE_ENEMY")){afterImage("BreakS", 1);}
    }
}
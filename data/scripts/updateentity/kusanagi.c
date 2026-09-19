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
    void model = getentityproperty(self, "model");

    if(ani == openborconstant("ANI_FREESPECIAL4") ||
       ani == openborconstant("ANI_FREESPECIAL5")){

        if(model != "Kusanagi_KunaiP" && model != "Kusanagi_KunaiB"){
            afterImage("KusanagiS", 1);
        }
    }

    if(ani == openborconstant("ANI_FOLLOW10") || ani == openborconstant("ANI_DODGE")){
        if(model == "Kusanagi_KunaiP" || model == "Kusanagi_KunaiB"){afterImage("KusanagiSW1", 0, "legacy");}else
        if(model == "Kusanagi_SwordP" || model == "Kusanagi_SwordB"){afterImage("KusanagiSW2", 0, "legacy");}else
        {afterImage("KusanagiS", 0, "legacy");}
    }
}
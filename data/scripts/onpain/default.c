#import "data/scripts/main.c"

void main()
{//Check defined conditions before use "spawnText" script
    void self = getlocalvar("self");
    void type = getentityproperty(self,"type");
    void ani  = getentityproperty(self, "animationID");

    if(type == openborconstant("TYPE_PLAYER")){
        if(ani == openborconstant("ANI_GUARDBREAK")){
            // spawnText("Moves", "GUARD_BREAK");
        }
    }
}
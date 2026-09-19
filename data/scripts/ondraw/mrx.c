#import "data/scripts/ondraw/main.c"

void main()
{
    parrow();
    debugMode();
    laugh();
}

void laugh()
{//Mrx laugh while seated when player dies
    void self         = getlocalvar("self");
    void target1     = getplayerproperty(0, "entity");
    void target2     = getplayerproperty(1, "entity");
    void target3     = getplayerproperty(2, "entity");
    void target4     = getplayerproperty(3, "entity");
    void vAniID        = getentityproperty(self, "animationID");
    int dead1        = getentityproperty(target1,"dead");
    int dead2        = getentityproperty(target2,"dead");
    int dead3        = getentityproperty(target3,"dead");
    int dead4        = getentityproperty(target4,"dead");

    if(vAniID == openborconstant("ANI_FOLLOW22")){
        if(dead1 == 1 || dead2 == 1 || dead3 == 1 || dead4 == 1){
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW23"));
        }
    }
}
#import "data/scripts/ondraw/main.c"
#import "data/scripts/main.c"

void main()
{
    jumpVel();
    parrow();
    debugMode();
    cheering();
    subScreen();
    superArmor();
    checkText("ANI_FREESPECIAL", "RAGE");
    checkText("ANI_FREESPECIAL2", "SUPER");
}

void cheering()
{//Yamato cheering when player dies
    void self        = getlocalvar("self");
    void target1    = getplayerproperty(0, "entity");
    void target2    = getplayerproperty(1, "entity");
    void target3    = getplayerproperty(2, "entity");
    void target4    = getplayerproperty(3, "entity");
    void vAniID        = getentityproperty(self, "animationID");
    int dead1        = getentityproperty(target1,"dead");
    int dead2        = getentityproperty(target2,"dead");
    int dead3        = getentityproperty(target3,"dead");
    int dead4        = getentityproperty(target4,"dead");

    if(vAniID == openborconstant("ANI_FOLLOW23")){
        if(dead1 == 1 || dead2 == 1 || dead3 == 1 || dead4 == 1){
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW24"));
        }
    }
}

void subScreen()
{//Adjust subject to screen property according to defined animation

    if(openborvariant("in_level")){
        void self        = getlocalvar("self");
        void type        = getentityproperty(self, "type");
        void ani        = getentityproperty(self, "animationID");
        int set            = openborvariant("current_set");
        int subScreen    = getentityproperty(self, "subject_to_screen");
        int x            = getentityproperty(self, "x");
        int z            = getentityproperty(self, "z");
        int dist        = 200;
        float xPos        = openborvariant("xpos");
        float L            = x-xPos;
        float W            = checkwall(x+dist, z);

        if(type == openborconstant("TYPE_PLAYER")){
            if(ani == openborconstant("ANI_FREESPECIAL3") || ani == openborconstant("ANI_FREESPECIAL4")){
                if(L < dist && W){// NEAR FROM THE LEFT EDGE OF THE SCREEN AND THERE IS A WALL NEAR AT RIGHT SIDE?
                    if(subScreen != 1){changeentityproperty(self, "subject_to_screen", 1);}
                }
                else
                {
                    if(subScreen != 0){changeentityproperty(self, "subject_to_screen", 0);}
                }
            }
            else
            {
                if(subScreen != 1){changeentityproperty(self, "subject_to_screen", 1);}
            }
        }

        if(type == openborconstant("TYPE_ENEMY")){
            if(ani == openborconstant("ANI_FREESPECIAL3") || ani == openborconstant("ANI_FREESPECIAL4")){
                if(subScreen != 0){changeentityproperty(self, "subject_to_screen", 0);}
            }
            else
            {
                if(subScreen != 1){
                    if(set == 1){changeentityproperty(self, "subject_to_screen", 1);} //USED FOR SURVIVAL MODE ONLY
                }
            }
        }
    }
}
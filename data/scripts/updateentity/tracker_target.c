#import "data/scripts/main.c"
#import "data/scripts/updateentity/main.c"

void main()
{
    afterEffect();
    targetLock();
}

void afterEffect()
{//Apply after image effects
    
    if(getglobalvar("graphicEffects") == "sor2x"){afterImage("Tracker_TargetS", 0);}
}

void targetLock()
{//Find nearest target, change parent position and apply some effects
    void self    = getlocalvar("self");
    void target    = findtarget(self);
    void parent    = getentityproperty(self, "parent");
    void vAni    = getentityproperty(self, "animationID");
    void pAni    = getentityproperty(parent, "animationID");
    int frame     = getentityproperty(self, "animpos");
    int x         = getentityproperty(self, "x");
    int z         = getentityproperty(self, "z");
    int Tx        = getentityproperty(target, "x");
    int Tz        = getentityproperty(target, "z");
    int dist    = 100;
    int zFix    = 5;
    int dir;
    float xPos    = openborvariant("xpos");
    float minZ    = openborvariant("player_min_z");
    float maxZ    = openborvariant("player_max_z");
    float Px;
    float cycle    = getglobalvar("cycle"+self);
    float time    = openborvariant("elapsed_time");
    float endC    = 359;
    float rate    = 2;
    float iR    = rand()%5+5;
    float hRes   = openborvariant("hresolution")/2;
    
    //START AND RENEW VARIABLES
    if(cycle == NULL()){setglobalvar("cycle"+self, 1);}
    if(cycle >= endC){setglobalvar("cycle"+self, 1);}
    
    //ROTATE THE SPRITE ACCORDING TO CYCLE VALUE, MOVE ENTITY ACCORDING TO TARGET
    if(time%rate == 0){
        cycle = getglobalvar("cycle"+self);
        changedrawmethod(self, "enabled", 1);
        changedrawmethod(self, "rotate", cycle);
        setglobalvar("cycle"+self, cycle+1);
        changeentityproperty(self, "position", Tx, Tz, NULL());
    }
    
    //CHASING THE TARGET
    if(vAni == openborconstant("ANI_IDLE")){
        if(getlocalvar("limit"+self) == NULL()){
            if(iR >= 0 && iR < 2){    setlocalvar("limit"+self, 4);}else
            if(iR >= 2 && iR < 6){    setlocalvar("limit"+self, 8);}else
            if(iR >= 6 && iR < 8){    setlocalvar("limit"+self, 12);}else
            if(iR >= 8 && iR <= 10){setlocalvar("limit"+self, 16);}
        }
        
        if(frame >= getlocalvar("limit"+self)){
            if(x > xPos+hRes){Px = x-dist;dir = 1;}else{Px = x+dist;dir = 0;}
            if(z <= minZ){z = minZ+zFix;}
            if(z >= maxZ){z = maxZ-zFix;}
            
            if(getlocalvar("aimed"+self) == NULL()){
                setlocalvar("aimX", Px);
                setlocalvar("aimZ", z);
                setlocalvar("aimD", dir);
                setlocalvar("aimed"+self, 1);
            }
            changeentityproperty(self, "speed", 0);
            changeentityproperty(self, "velocity", 0, 0, 0);
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
        }
    }
    
    //STOP CHASING THE TARGET AND SHOOT
    if(vAni == openborconstant("ANI_FOLLOW1")){ 
        if(pAni != openborconstant("ANI_FOLLOW4") && entityAlive(parent)){
            performattack(parent, openborconstant("ANI_FOLLOW4"), 1);
            changeentityproperty(parent, "position", getlocalvar("aimX"), getlocalvar("aimZ"), 0);
            changeentityproperty(parent, "direction", getlocalvar("aimD"));
            setglobalvar("cycle"+self, NULL());
            setlocalvar("aimed"+self, NULL());
            killentity(self);
        }
    }
}
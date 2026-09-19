void main()
{//Change animation according to global variables
    void self = getlocalvar("self");
    void anim = getentityproperty(self, "animationID");
    int locks = getglobalvar("st6_locks");
    
    if(anim == openborconstant("ANI_IDLE")){
        if(locks == 1){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));}else
        if(locks == 2){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));}else
        if(locks >= 3){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));}
    }
}
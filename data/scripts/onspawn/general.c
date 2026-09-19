#import "data/scripts/animation/main_spawns.c"

void main()
{//Manage all "General" variables during "onspawn" event
    void self    = getlocalvar("self");
    int health    = getglobalvar("generalHealth");
    int locks    = getglobalvar("st6_locks");
    
    //CHECK IF THE GENERAL IS ALREADY DEAD
    if(getglobalvar("generalDied") == 1){damageentity(self, self, getentityproperty(self, "maxhealth"), 0);}

    //UPDATE THE LAST REGISTERED HEALTH VALUE WHEN THE TOXIC GAS IS ENABLED
    if(getglobalvar("gasEnable") == 1){changeentityproperty(self, "health", health);}
    
    //CHANGE "CANDAMAGE"
    if(locks >= 2){changeentityproperty(self, "candamage", "ground", "ground", "ground");}
}
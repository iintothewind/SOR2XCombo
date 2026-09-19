#include "data/scripts/assets.h"

void main()
{//Play sample and change bounce variable with defined height
    void self = getlocalvar("self");
    int base  = getentityproperty(self, "base"); //GET CURRENT BASE VALUE
    int y      = getentityproperty(self, "y"); //GET CURRENT Y POSITION
    int dist  = 5; //DEFINE THE DISTANCE FROM THE GROUND THAT ACTIVATE/DEACTIVATE THE SAMPLE
    
    if(getlocalvar("bounce") != 1){ //CREATE AND GET A VARIABLE NAMED "BOUNCE". THIS IS USED TO THE SCRIPT EXECUTE ONCE
        if(y <= base+dist){ //CHECK CURRENT DISTANCE FROM ANY BASE. IT IS USED TO CHECK NOT ONLY THE GROUND, BUT PLATFORMS TOO
            changeentityproperty(self, "aiflag", "drop", 1); //ENABLE ENTITY DROP STATE, SO IT CAN USE DUST TOO IF HAVE ONE
            playsample(SAMPLE_IRON5, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY LOADED SAMPLE
            setlocalvar("bounce", 1); //CHANGE VARIABLE "BOUNCE" TO 1, AND THE SCRIPT WILL NOT BE REPEATED
        }
    }
    else
    if(getlocalvar("bounce") == 1){ //GET VARIABLE "BOUNCE". IF CHANGED TO 1, THE SCRIPT WILL BE RE-ENABLED TO BE USED AGAIN
        if(y > base+dist){ //CHECK CURRENT DISTANCE FROM ANY BASE. IF MORE THAN DIST, THE SCRIPT WILL BE RE-ENABLED
            changeentityproperty(self, "aiflag", "drop", 0); //DISABLE ENTITY DROP STATE
            setlocalvar("bounce", 0); //CHANGE VARIABLE "BOUNCE" TO 1, AND THE SCRIPT WILL BE RE-ENABLED TO BE USED AGAIN
        }
    }
}
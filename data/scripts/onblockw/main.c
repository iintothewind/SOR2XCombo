#import "data/scripts/animation/main_spawns.c"
#include "data/scripts/assets.h"

void wallBouncing()
{//Simulate hitwall effect when thrown or being hit by certain attacks (ALL THROWS/SLAMS AND BOWLING SKILLS, BARBON/ADAM)

    if(getglobalvar("walls") == "all_types" || getglobalvar("walls") == "bouncing_only"){
        void self      = getlocalvar("self");
        void ani       = getentityproperty(self, "animationID");
        int limit     = 20;
        float height = getentityproperty(self, "y");
        float xDir     = getentityproperty(self, "xdir");

        if(ani == openborconstant("ANI_FALL") || ani == openborconstant("ANI_BURN") || ani == openborconstant("ANI_SHOCK")){
            if(height >= limit && xDir > 2){
                spawn01("Flash", 0, 50, 0);
                spawn01("QuakeLow", 0, 0, 0);
                playsample(SAMPLE_STRONGPUNCH, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                tossentity(self, 2, -xDir/2, 0);
            }
        }

        if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9")){
            if(height >= limit){
                spawn01("Flash", 0, 50, 0);
                spawn01("QuakeLow", 0, 0, 0);
                playsample(SAMPLE_STRONGPUNCH, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                tossentity(self, 2, -xDir/2, 0);
            }
        }
    }
}

void wallJumping()
{//Make characters jump in walls

    if(getglobalvar("walls") == "all_types" || getglobalvar("walls") == "jumping_only"){
        void self      = getlocalvar("self");
        void ani       = getentityproperty(self, "animationID");
        int iPIndex     = getentityproperty(self, "playerindex");
        int x          = getentityproperty(self, "x");
        int z          = getentityproperty(self, "z");
        float pause     = 30;
        float mult     = 2;

        if(ani == openborconstant("ANI_JUMP")
        || ani == openborconstant("ANI_RUNJUMP")
        || ani == openborconstant("ANI_JUMPFORWARD")
        || ani == openborconstant("ANI_FORWARDJUMP")){
            void rName      = getentityproperty(self, "defaultname");
            float jBase     = getglobalvar("jBase");
            float jDif     = getglobalvar("jDif");
            float jDifX  = getglobalvar("jDifX"); //USED TO CALCULATE THE CORRECT VALUE FOR JUMP SPEED IN X/Z AXIS
            float ju      = getglobalvar(rName+"Jump");
            float xVel;
            float yVel;

            ju      = jBase+(jDif*ju); //TRANSLATE JUMP VALUE
            yVel = ju;

            if(playerkeys(iPIndex, 0, "moveleft")){
                changeentityproperty(self, "direction", 0);
                xVel = -(ju-jDifX);
            }
            else
            if(playerkeys(iPIndex, 0, "moveright")){
                changeentityproperty(self, "direction", 1);
                xVel = (ju-jDifX);
            }
            else
            {
                xVel = 0;
            }

            if(playerkeys(iPIndex, 0, "moveup")){
                mult = 1;
            }

            if(playerkeys(iPIndex, 1, "jump")){
                playsample(SAMPLE_JUMPLAND, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                changeentityproperty(self, "animation", openborconstant("ANI_WALKOFF"));
                changeentityproperty(self, "aiflag", "frozen", 1);
                changeentityproperty(self, "freezetime", openborvariant("elapsed_time")+pause);
                tossentity(self, yVel, xVel*mult, 0);
            }
        }
    }
}
void main()
{//Change animation with time count (ROBOT ARM IN ST8D)
    void self      = getlocalvar("self");
    void ani       = getentityproperty(self, "animationID");
    void atk;
    int mHealth    = getentityproperty(self, "maxhealth");
    int health    = getentityproperty(self, "health");
    float clock    = openborvariant("elapsed_time");
    float start    = getlocalvar("startClock");
    float add    = 1600;
    
    if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
        
        //SAVE START CLOCK AT 99 SECONDS IF NULL
        if(start == NULL()){setlocalvar("startClock", clock+add);}
        
        if(health <= mHealth/2){ //HEALTH IS LESS THAN 50%??
            atk = "ANI_ATTACK3";
        }else{ //HEALTH IS MORE THAN 50%??
            atk = "ANI_ATTACK2";
        }
        
        if(start != NULL()){ //START CLOCK IS NOT NULL??
            if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_ATTACK1")){ //IS IN CHASE ANIMATION??
                if(clock >= start){ //TIME ENDED AT 8 SECONDS
                    performattack(self, openborconstant(atk), 1); //ATTACK
                    setlocalvar("startClock", clock+add); //RESET CLOCK COUNT AGAIN
                }
            }
        }
    }else{
        setlocalvar("startClock", clock+add); //SAVE START CLOCK AT 99 SECONDS IF NULL
    }

    //USED TO DRAW A DOT IN THE GROUND
    if(health > 0){
        int x = getentityproperty(self, "x");
        int y = getentityproperty(self, "y");
        int z = getentityproperty(self, "z");
        int t = openborvariant("elapsed_time")/5;

        if(t%2 == 0){drawbox(x-2, z-6, 2, 2, z, rgbcolor(0x00, 0xFF, 0x00), 0);}
    }
}
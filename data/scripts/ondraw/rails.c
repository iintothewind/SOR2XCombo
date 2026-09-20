#import "data/scripts/animation/main_spawns.c"

void main()
{//Spawn entity at Random location relative to xPos
    void self    = getlocalvar("self");
    void vName    = getentityproperty(self, "defaultname");
    void ani    = getentityproperty(self, "animationID");
    void vSpawn;
    int frame    = getentityproperty(self, "animpos");
    float xPos    = openborvariant("xpos");
    float xR    = rand()%100; //Random spawn from left/right
    float zR    = rand()%100; //Random spawn from up/down
    float hRes    = openborvariant("hresolution");
    float vx    = 3;
    float xDist    = 450;
    float dx;
    
    if(vName == "St4_RailsX2"){

        //DEFINE ZPOS AND WARNING ANIMATION
        if(ani == openborconstant("ANI_IDLE")){

            //INCREASE DELAY BETWEEN EACH TRAIN ACCORDING TO THE GAME DIFFICULT
            if(frame <= 0){
                if(getglobalvar("difficult") == "normal"){changeentityproperty(self, "edelay", 1, 6, 1, 9999, 1, 9999);}else
                if(getglobalvar("difficult") == "hard"){changeentityproperty(self, "edelay", 1, 3, 1, 9999, 1, 9999);}
            }

            if(frame >= 3){
                changeentityproperty(self, "edelay", 1, 1, 1, 9999, 1, 9999); //RESET THE DELAY TO DEFAULT FOR OTHER ANIMATIONS

                if(zR >= 0 && zR < 50){
                    setlocalvar("dz", 233);
                    changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //UPPER RAIL WARNING
                }else{
                    setlocalvar("dz", 265);
                    changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2")); //LOWER RAIL WARNING
                }
            }
        }
        
        //UPPER RAIL WARNING
        if(ani == openborconstant("ANI_FOLLOW1")){
            if(frame >= 7){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));}
        }
        
        //LOWER RAIL WARNING
        if(ani == openborconstant("ANI_FOLLOW2")){
            if(frame >= 7){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));}
        }
        
        //DEFINE XPOS AND SPAWN TRAIN
        if(ani == openborconstant("ANI_FOLLOW3")){
            if(frame >= 3){
                if(xR >= 0 && xR < 50){
                    dx = xPos-xDist;
                    vx = vx;
                }else{
                    dx = xPos+hRes+xDist;
                    vx = -vx;
                }
                vSpawn = spawn01("Train", 0, 0, 0);
                changeentityproperty(vSpawn, "position", dx, getlocalvar("dz"), 0);
                changeentityproperty(vSpawn, "velocity", vx, 0, 0);
                changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
            }
        }
    }
    
    if(vName == "St4_RailsX1"){
        
        //DEFINE ZPOS AND WARNING ANIMATION
        if(ani == openborconstant("ANI_IDLE")){

            //INCREASE DELAY BETWEEN EACH TRAIN ACCORDING TO THE GAME DIFFICULT
            if(frame <= 0){
                if(getglobalvar("difficult") == "normal"){changeentityproperty(self, "edelay", 1, 6, 1, 9999, 1, 9999);}else
                if(getglobalvar("difficult") == "hard"){changeentityproperty(self, "edelay", 1, 3, 1, 9999, 1, 9999);}
            }
            
            if(frame >= 3){
                setlocalvar("dz", 265);
                changeentityproperty(self, "edelay", 1, 1, 1, 9999, 1, 9999); //RESET THE DELAY TO DEFAULT FOR OTHER ANIMATIONS
                changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //RAIL WARNING
            }
        }
        
        //RAIL WARNING
        if(ani == openborconstant("ANI_FOLLOW1")){
            if(frame >= 7){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));}
        }
        
        //DEFINE XPOS AND SPAWN TRAIN
        if(ani == openborconstant("ANI_FOLLOW2")){
            if(frame >= 3){
                if(xR >= 0 && xR < 50){
                    dx = xPos-xDist;
                    vx = vx;
                }else{
                    dx = xPos+hRes+xDist;
                    vx = -vx;
                }
                vSpawn = spawn01("Train", 0, 0, 0);
                changeentityproperty(vSpawn, "position", dx, getlocalvar("dz"), 0);
                changeentityproperty(vSpawn, "velocity", vx, 0, 0);
                changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
            }
        }
    }
}
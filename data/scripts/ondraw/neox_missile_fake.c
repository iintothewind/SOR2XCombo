#import "data/scripts/ondraw/main.c"

void main()
{
    frameVel();
    warningArrow();
}

void frameVel()
{//Update frame with velocity check
    void self = getlocalvar("self");
    void ani  = getentityproperty(self, "animationID");
    int frame = getentityproperty(self, "animpos");
    int dir   = getentityproperty(self, "direction");
    int xVel  = getentityproperty(self, "xdir");
    int zVel  = getentityproperty(self, "zdir");
    
    if(ani == openborconstant("ANI_IDLE")){
        if(dir == 0){xVel = -xVel;}
        
        //LEFT-RIGHT DIRECTION
        if(xVel > 0.5){
            if(frame != 0 && frame != 1 && frame != 2 && frame != 3){updateframe(self, 2);}
        }
        
        //DIAGONAL DIRECTION
        if(xVel <= 0.5 && xVel >= 0.2){
            
            //DIAGONAL DOWN
            if(zVel > 0){
                if(frame != 4 && frame != 5 && frame != 6 && frame != 7){updateframe(self, 6);}
            }
            
            //DIAGONAL UP
            if(zVel < 0){
                if(frame != 8 && frame != 9 && frame != 10 && frame != 11){updateframe(self, 10);}
            }
        }
        
        //UP-DOWN DIRECTION
        if(xVel < 0.2){
            
            //DOWN
            if(zVel > 0){
                if(frame != 12 && frame != 13 && frame != 14 && frame != 15){updateframe(self, 14);}
            }
            
            //UP
            if(zVel < 0){
                if(frame != 16 && frame != 17 && frame != 18 && frame != 19){updateframe(self, 18);}
            }
        }
    }
}

void warningArrow()
{//Draw "Warning" arrow to destroy the missile
    void self  = getlocalvar("self");
    void ani   = getentityproperty(self, "animationID");
    int dir       = getentityproperty(self, "direction");
    int x        = getentityproperty(self, "x");
    int y        = getentityproperty(self, "y");
    int z        = getentityproperty(self, "z");
    int xDif   = 23;
    int yDif   = 45;
    float xPos = openborvariant("xpos");
    float yPos = openborvariant("ypos");
    
    if(dir == 0){xDif = 5;}
    
    x = x-xPos-xDif;
    y = z-yPos-y-yDif;
    
    if(ani == openborconstant("ANI_IDLE")){
        changedrawmethod(NULL(), "enabled", 0);
        drawsprite(getglobalvar("arrowDown"), x, y, z);
    }
}
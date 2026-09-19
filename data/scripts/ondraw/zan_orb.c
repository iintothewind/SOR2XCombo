#import "data/scripts/ondraw/main.c"

void main()
{
    frameVel();
    subTarget();
}

void frameVel()
{//Update frame with velocity check
    void self = getlocalvar("self");
    void ani  = getentityproperty(self, "animationID");

    if(ani == openborconstant("ANI_IDLE")){
        int dir   = getentityproperty(self, "direction");
        int xVel  = getentityproperty(self, "xdir");
        int zVel  = getentityproperty(self, "zdir");
        int frame = getentityproperty(self, "animpos");

        if(dir == 0){xVel = -xVel;}

        //LEFT-RIGHT DIRECTION
        if(xVel > 0.5){
            if(frame != 0 && frame != 1 && frame != 2 && frame != 3){updateframe(self, 2);}
        }

        //DIAGONAL DIRECTION
        if(xVel <= 0.5 && xVel >= 0.25){

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
        if(xVel < 0.25){

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
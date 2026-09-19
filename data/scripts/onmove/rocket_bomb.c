void main()
{//Adjust position according to XPOS/YPOS and Animation/Height check
    void self    = getlocalvar("self");
    int height    = getentityproperty(self,"y");
    int limit    = 300;
    
    if(height > limit){
        void ani        = getentityproperty(self,"animationID");
        float xPos        = openborvariant("xpos");
        float yPos        = openborvariant("ypos");
        float minZ        = openborvariant("player_min_z");
        float maxZ        = openborvariant("player_max_z");
        float zDist        = 30; //DEFAULT Z POSITION
        float xDist1    = 80; //DEFAULT LEFT X POSITION
        float xDist2    = 240; //DEFAULT MID X POSITION
        float xDist3    = 400; //DEFAULT RIGHT X POSITION
        
        if(yPos <= 0 ){
            if(ani == openborconstant("ANI_IDLE")){changeentityproperty(self, "position", xPos+xDist1, minZ+zDist);}
            if(ani == openborconstant("ANI_FOLLOW1")){changeentityproperty(self, "position", xPos+xDist2, minZ+zDist);}
            if(ani == openborconstant("ANI_FOLLOW2")){changeentityproperty(self, "position", xPos+xDist3, minZ+zDist);}
        }
        
        if(yPos > 0){
            if(ani == openborconstant("ANI_IDLE")){changeentityproperty(self, "position", xPos+xDist1, maxZ-zDist);}
            if(ani == openborconstant("ANI_FOLLOW1")){changeentityproperty(self, "position", xPos+xDist2, maxZ-zDist);}
            if(ani == openborconstant("ANI_FOLLOW2")){changeentityproperty(self, "position", xPos+xDist3, maxZ-zDist);}
        }
    }
}
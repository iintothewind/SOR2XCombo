void drawDamage()
{//Draw damage total ammount of damage during a rush
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    
    if(openborvariant("in_options") != 1){
        dmgFunction(player1);
        dmgFunction(player2);
        dmgFunction(player3);
        dmgFunction(player4);
    }
}

void dmgFunction(void player)
{//Script used to reduce code size
    
    if(player != NULL()){
        int pIndex    = getentityproperty(player, "playerindex");
        int rush     = getentityproperty(player, "rush_count");
        int dmg      = getglobalvar("dmg"+pIndex);
        int xPos1     = 2;
        int xPos2     = 30;
        int xDif    = 120;
        int xAdd    = xDif*pIndex;
        int yPos       = 65;
        int trigger = 2;
        int font    = 0;
        int layer    = 1001;
        
        if(getglobalvar("debugMode") != 0){trigger = 1;}
        if(dmg == NULL()){setglobalvar("dmg"+pIndex, 0);}
        
        if(rush >= trigger){
            drawstring(xPos1+xAdd, yPos, font, "DMG", layer);
            drawstring(xPos2+xAdd, yPos, font, dmg, layer);
        }
    }
}
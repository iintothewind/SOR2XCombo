void drawKO()
{//Draw K.O. counter
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");

    if(openborvariant("in_options") != 1){
        koFunction(player1);
        koFunction(player2);
        koFunction(player3);
        koFunction(player4);
    }
}

void koFunction(void player)
{//Script used to reduce code size
    if(player != NULL()){
        int pIndex    = getentityproperty(player, "playerindex");
        int rush     = getentityproperty(player, "rush_count");
        int ko       = getglobalvar("ko"+pIndex);
        int xPos1    = 2;
        int xPos2    = 30;
        int xDif    = 120;
        int xAdd    = xDif*pIndex;
        int yPos    = 56;
        int font    = 2;
        int layer    = 1001;

        if(getglobalvar("activeText") != "Level" && getglobalvar("activeText") != "Survival"){
            if(rush >= 2 || openborvariant("game_paused")){
                drawstring(xPos1+xAdd, yPos, font, "K.O.", layer);
                drawstring(xPos2+xAdd, yPos, font, ko, layer);
            }
        }
    }
}
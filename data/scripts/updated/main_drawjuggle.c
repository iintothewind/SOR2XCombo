void drawJuggle()
{//Draw damage total ammount of damage during a rush
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	if(openborvariant("in_options") != 1){
		displayJuggle(player1);
		displayJuggle(player2);
		displayJuggle(player3);
		displayJuggle(player4);
	}
}

void displayJuggle(void player)
{//Script used to reduce code size
	if(player != NULL()){
		int pIndex	= getentityproperty(player, "playerindex");
		int rush 	= getentityproperty(player, "rush_count");
    int juggleSystem = getglobalvar("juggleSystem");
		int jug 	= getglobalvar("tjug"+pIndex);
		int xPos1 	= 62;
		int xPos2 	= 90;
		int xDif	= 120;
		int xAdd	= xDif*pIndex;
		int yPos   	= 56;
		int font	= 2;
		int layer	= 1001;

		if(juggleSystem != "unlimited" && jug != NULL() && rush > 1){
			drawstring(xPos1+xAdd, yPos, font, "JUG", layer);
			drawstring(xPos2+xAdd, yPos, font, jug, layer);
		}
	}
}
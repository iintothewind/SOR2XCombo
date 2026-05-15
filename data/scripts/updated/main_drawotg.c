void drawOtg()
{
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	if(openborvariant("in_options") != 1){
		displayOtg(player1);
		displayOtg(player2);
		displayOtg(player3);
		displayOtg(player4);
	}
}

void displayOtg(void player)
{
	if(player != NULL()){
		int pIndex	= getentityproperty(player, "playerindex");
		int rush 	= getentityproperty(player, "rush_count");
    int otgSystem = getglobalvar("otgSystem");
		int otg 	= getglobalvar("totg"+pIndex);
		int xPos1 	= 62;
		int xPos2 	= 90;
		int xDif	= 120;
		int xAdd	= xDif*pIndex;
		int yPos   	= 65;
		int font	= 0;
		int layer	= 1001;

		if(otgSystem != "unlimited" && otg != NULL() && rush > 1){
			drawstring(xPos1+xAdd, yPos, font, "OTG", layer);
			drawstring(xPos2+xAdd, yPos, font, otg, layer);
		}
	}
}
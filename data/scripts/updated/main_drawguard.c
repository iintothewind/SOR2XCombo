void drawGuard()
{//Draw guard bar
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	if(openborvariant("pause") == 0){
		guardFunction(player1);
		guardFunction(player2);
		guardFunction(player3);
		guardFunction(player4);
	}
}

void guardFunction(void player)
{//Script used to reduce code size

	if(player != NULL()){
		int pIndex 	= getentityproperty(player, "playerindex");
		int lives 	= getplayerproperty(pIndex, "lives");

		if(lives >= 1){
			float maxGuard	= getentityproperty(player, "maxguardpoints");
			float gp		= getentityproperty(player, "guardpoints");
			int guardP		= getentityproperty(player, "guardpoints");
			int widthLR		= 1; //LEFT-RIGHT BORDERS WIDTH
			int heightLR	= 5; //LEFT-RIGHT BORDERS HEIGHT
			int heightUD	= 1; //UP-DOWN BORDERS HEIGHT
			int xPos		= 2;
			int xSize		= 87;
			int xDif		= 120;
			int xAdd		= xDif*pIndex;
			int yPos		= 21;
			int yDif		= 4;
			int layer		= 50000;
			float color;
			guardP			= (guardP*xSize)/(maxGuard);

			if(guardP >= 1){
				if(getglobalvar("graphicEffects") == "original"){
					color = rgbcolor(0xFF,0xAA,0x00);
				}

				if(getglobalvar("graphicEffects") == "sor2x"){
					color = gp > maxGuard/2 ? (gp > maxGuard*0.75 ? rgbcolor(0x00,0xFF,0x00) : rgbcolor(0x00,0x7C,0x00)) : (gp > maxGuard*0.25 ? rgbcolor(0x7C,0x00,0x00) : rgbcolor(0xFF,0x00,0x00));
					drawbox(xPos+xAdd, yPos, widthLR, heightLR, layer, color); //START LINE
					drawbox(xPos+xAdd+guardP, yPos, widthLR, heightLR, layer, color); //END LINE
				}

				drawbox(xPos+xAdd, yPos, guardP+1, heightUD, layer, color); //TOP LINE
				drawbox(xPos+xAdd, yPos+yDif, guardP+1, heightUD, layer, color); //BOTTOM LINE
			}
		}
	}
}
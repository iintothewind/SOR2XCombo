void drawOverlay()
{//Draw image for overlay effect in lifebar
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	
	if(openborvariant("pause") == 0){
		overlayFunction(player1, 0);
		overlayFunction(player2, 1);
		overlayFunction(player3, 2);
		overlayFunction(player4, 3);
	}
}

void overlayFunction(void player, int pIndex)
{//Script used to reduce code size

	//USED FOR PLAYERS ALREADY IN-GAME
	if(player != NULL()){
		int lives = getplayerproperty(pIndex, "lives");
		
		if(lives >= 1){
			void target	= getentityproperty(player, "opponent");
			int noLife	= getentityproperty(target, "nolife");
			int xPos	= 1;
			int xDif	= 120;
			int xAdd	= xDif*pIndex;
			int yPos1	= 1;
			int yPos2	= 29;
			int yAdd	= 20;
			int layer1	= 10000;
			int layer2	= 60000;
			int mode;

			if(getglobalvar("graphicEffects") == "sor2x"){		mode = 1;}else
			if(getglobalvar("graphicEffects") == "original"){	mode = 2;}
			
			setdrawmethod(NULL(),0,256,256,0,0,0,0);
			drawsprite(getglobalvar("charIcon"+mode), xPos+xAdd, yPos1, layer1); //PLAYER CHARACTER ICON OVERLAY
			setdrawmethod(NULL(),1,256,256,0,0,0,2);
			drawsprite(getglobalvar("lifebarP"+mode), xPos+xAdd, yPos1+yAdd, layer2); //PLAYER LIFEBAR OVERLAY
			
			if(target != NULL()){
				if(noLife != 1){
					setdrawmethod(NULL(),0,256,256,0,0,0,0);
					drawsprite(getglobalvar("charIcon"+mode), xPos+xAdd, yPos2, layer1); //OPPONENT CHARACTER ICON OVERLAY
					setdrawmethod(NULL(),1,256,256,0,0,0,2);
					drawsprite(getglobalvar("lifebarE"+mode), xPos+xAdd, yPos2+yAdd, layer2); //OPPONENT LIFEBAR OVERLAY
				}
			}
		}
	}
	else //USED FOR PLAYERS JOINING IN A GAME
	if(getplayerproperty(pIndex, "joining") == 1){
		int xPos	= 1;
		int xDif	= 120;
		int xAdd	= xDif*pIndex;
		int yPos1	= 1;
		int layer1	= 10000;
		int mode;

		if(getglobalvar("graphicEffects") == "sor2x"){		mode = 1;}else
		if(getglobalvar("graphicEffects") == "original"){	mode = 2;}

		setdrawmethod(NULL(),0,256,256,0,0,0,0);
		drawsprite(getglobalvar("charIcon"+mode), xPos+xAdd, yPos1, layer1); //PLAYER CHARACTER ICON OVERLAY
	}
}
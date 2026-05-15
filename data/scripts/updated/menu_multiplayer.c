void menuMultiplayer()
{//Draw a Menu in/out game

//HIGHLIGHT OPTIONS:
//1 - VERSUS DAMAGE				(UPDATED.C, MAIN.C, KEY.C, ONDRAW.C, THINK.C)
//2 - MULTIHIT "GLITCH"			(UPDATED.C, KEYALL.C)
	
	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 70;			//BASE Y POSITION FOR ALL MENU CONTENT, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 2;
	int yAdd   = 11;
	int layer  = 1000000003;
	
	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 1){	font1 = 1;}else 	//IS VERSUS DAMAGE HIGHLIGHTED??
	if(getglobalvar("highlight") == 2){	font2 = 2;} 		//IS MULTIHIT "GLITCH" HIGHLIGHTED??
	
	//DRAW MENU
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") == "multiplayer"){
			
			str  = "versus_damage:";align = xPos1-strwidth(str, font0);
			drawstring(align, yPos, font1, str, layer);
			drawstring(xPos2, yPos, font1, getglobalvar("versusDamage"), layer);
			
			str	 = "multihit_glitch:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font2, str, layer);
			drawstring(xPos2, yPos, font2, getglobalvar("multiHit"), layer);
		}
	}
}
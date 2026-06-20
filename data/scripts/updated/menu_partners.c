void menuPartners()
{//Draw a CPU Partner Menu in game

//HIGHLIGHT OPTIONS:
//1  - PARTNER MODE				(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//2  - PARTNER AGGRESSION		(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//3  - PARTNER GET FOOD			(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//4  - PARTNER FOLLOW			(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//5  - PARTNER RESPAWN			(UPDATED.C, MAIN.C, KEY.C, ONDEATH.C)
//6  - PARTNER SPAWN/KILL		(UPDATED.C, MAIN.C, KEY.C, LEVEL.C, ENDLEVEL.C, ONSPAWN.C, ONDEATH.C, ONDRAW.C, THINK.C)

	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 70;			//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 0;
	int font3  = 0;
	int font4  = 0;
	int font5  = 0;
	int font6  = 0;
	int yAdd   = 11;
	int layer  = 1000000003;
	
	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 1){	font1 = 1;}else 	//IS PARTNER MODE HIGHLIGHTED??
	if(getglobalvar("highlight") == 2){	font2 = 1;}else 	//IS PARTNER AGGRESSION HIGHLIGHTED??
	if(getglobalvar("highlight") == 3){	font3 = 1;}else 	//IS PARTNER GET FOOD HIGHLIGHTED??
	if(getglobalvar("highlight") == 4){	font4 = 1;}else 	//IS PARTNER FOLLOW HIGHLIGHTED??
	if(getglobalvar("highlight") == 5){	font5 = 1;}else 	//IS PARTNER RESPAWN HIGHLIGHTED??
	if(getglobalvar("highlight") == 6){	font6 = 1;} 		//IS PARTNER SPAWN/KILL HIGHLIGHTED??
	
	//BLOCKED SPAWN IN SURVIVAL MODE
	if(openborvariant("current_set") == 1 || openborvariant("in_level") != 1){font6 = 2;}
	
	//SCRIPT TO SHOW "NO LIVES!!" MESSAGE WHEN THE PLAYER DON'T HAS ENOUGH LIVES TO SPAWN THE CPU PARTNER
	void spawnKill;
	int delay = 200;

	if(getglobalvar("blockedPartner") != 0){
		if(openborvariant("elapsed_time") < getglobalvar("blockedPartner")+delay){
			spawnKill = "no_lives!!";
		}else{
			setglobalvar("blockedPartner", 0);
		}
	}else{
		spawnKill = getglobalvar("partnerSpawn")+"_<_"+getglobalvar("selectPartner")+">";
	}
	
	//DRAW MENU
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") == "partners"){
			
			str  = "fighting_mode:";align = xPos1-strwidth(str, font0);
			drawstring(align, yPos, font1, str, layer);
			drawstring(xPos2, yPos, font1, getglobalvar("partnerMode"), layer);
			
			str  = "aggression:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font2, str, layer);
			drawstring(xPos2, yPos, font2, getglobalvar("partnerAggression"), layer);
			
			str  = "get_food:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font3, str, layer);
			drawstring(xPos2, yPos, font3, getglobalvar("partnerGetFood"), layer);
			
			str  = "follow_caller:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font4, str, layer);
			drawstring(xPos2, yPos, font4, getglobalvar("partnerFollow"), layer);
			
			str  = "respawn:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font5, str, layer);
			drawstring(xPos2, yPos, font5, getglobalvar("partnerRespawn"), layer);
			
			str  = "spawn/kill...";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font6, str, layer);
			drawstring(xPos2, yPos, font6, spawnKill, layer);
		}
	}
}
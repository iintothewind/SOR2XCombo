void main()
{
	if(getlocalvar("reset") == NULL()){ //USED TO RESET HIGHLIGHT TO ZERO
		setglobalvar("highlight", 0);
		setlocalvar("reset", 1);
	}
	menuSurvival();
}

void menuSurvival()
{//Draw Survival menu before start Survival mode

//HIGHLIGHT OPTIONS:
//0 - SURVIVAL MODE				(MAIN.C, KEY.C, ONDRAW.C)
//1 - LIFE RESTORE				(MAIN.C, KEY.C, ONDRAW.C)
//2 - GROUP SIZE				(MAIN.C, KEY.C, ONDRAW.C)
//3 - GROUP RATE				(MAIN.C, KEY.C, ONDRAW.C)
//4 - BOSS RATE					(MAIN.C, KEY.C, ONDRAW.C)
//5 - START						(MAIN.C, KEY.C, ONDRAW.C)

	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 100;			//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 0;
	int font3  = 0;
	int font4  = 0;
	int yAdd   = 11;
	int layer  = 1000000003;
	float hRes = openborvariant("hresolution");

	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 0){	font0 = 1;}else 	//IS SURVIVAL MODE HIGHLIGHTED??
	if(getglobalvar("highlight") == 1){	font1 = 1;}else 	//IS LIFE RESTORE HIGHLIGHTED??
	if(getglobalvar("highlight") == 2){	font2 = 1;}else 	//IS GROUP SIZE HIGHLIGHTED??
	if(getglobalvar("highlight") == 3){	font3 = 1;}else 	//IS GROUP RATE HIGHLIGHTED??
	if(getglobalvar("highlight") == 4){	font4 = 1;} 		//IS BOSS RATE HIGHLIGHTED??

	//BLOCK GROUP ADJUSTS IF SINGLE MODE IS SELECTED
	if(getglobalvar("survivalMode") == "single"){
		font2 = 2;
		font3 = 2;
		font4 = 2;
	}

	//BLOCK LIFE RESTORE ADJUST IF GROUP MODE IS SELECTED
	if(getglobalvar("survivalMode") == "group"){font1 = 2;}

	//BLOCK ALL ADJUSTS IF BATTLE ROYALE MODE IS SELECTED
	if(getglobalvar("survivalMode") == "battle_royale"){
		font1 = 2;
		font2 = 2;
		font3 = 2;
		font4 = 2;
	}

	//DRAW MENU
	if(getglobalvar("activeText") == "Survival"){ //SURVIVAL MENU STARTED
		drawstring((hRes-strwidth("survival_menu", font0))/2, yPos-yAdd*2, 2, "survival_menu", layer);

		str  = "survival_mode:";align = xPos1-strwidth(str, font0);
		drawstring(align, yPos, font0, str, layer);
		drawstring(xPos2, yPos, font0, getglobalvar("survivalMode"), layer);

		str  = "life_restore:";align = xPos1-strwidth(str, font0);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font1, str, layer);
		drawstring(xPos2, yPos, font1, getglobalvar("survivaLifeRestore")+"_each_wave", layer);

		str  = "group_max_size:";align = xPos1-strwidth(str, font0);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font2, str, layer);
		drawstring(xPos2, yPos, font2, getglobalvar("survivalGroupSize")+"_enemies", layer);

		str  = "group_spawn_rate:";align = xPos1-strwidth(str, font0);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font3, str, layer);
		drawstring(xPos2, yPos, font3, "each_"+getglobalvar("survivalGroupRate")+"_seconds", layer);

		str  = "boss_spawn_rate:";align = xPos1-strwidth(str, font0);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font4, str, layer);
		drawstring(xPos2, yPos, font4, "each_"+getglobalvar("survivalBossRate")+"_k.o.", layer);

		drawstring((hRes-strwidth("(press_start_to_begin,_or_jump_to_exit)", font0))/2, yPos+yAdd*6, 2, "(press_start_to_begin,_or_jump_to_exit)", layer);
	}

	//DEFINE BRANCH ACCORDING TO SURVIVAL MODE
	if(getglobalvar("survivalMode") == "single"){			setlocalvar("branch", "survival_a");}else
	if(getglobalvar("survivalMode") == "group"){			setlocalvar("branch", "survival_b");}else
	if(getglobalvar("survivalMode") == "battle_royale"){	setlocalvar("branch", "survival_c1");}

	//BEGIN GAME WHEN ANY BUTTON IS PRESSED
	if(getglobalvar("survivalStart") == 0){
		changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
		changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ESC"));
		setglobalvar("activeText", "Survival");
	}
	else
	if(getglobalvar("survivalStart") == 1){
		changeplayerproperty(0, "disablekeys", 0);
		changeplayerproperty(1, "disablekeys", 0);
		changeplayerproperty(2, "disablekeys", 0);
		changeplayerproperty(3, "disablekeys", 0);
		jumptobranch(getlocalvar("branch"), 1);
		setglobalvar("activeText", 0);
	}
}
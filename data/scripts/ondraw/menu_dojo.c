void main()
{
	if(getlocalvar("reset") == NULL()){ //USED TO RESET HIGHLIGHT TO ZERO
		setlocalvar("reset", 1);
	}
  if(getglobalvar("dojoStage") == NULL()) {
    setglobalvar("dojoStage", "Dojo");
  }
  if(getglobalvar("dojoOpponent") == NULL()) {
    setglobalvar("dojoOpponent", "Kun");
  }
	if(getglobalvar("dojoEnergyRate") == NULL()) {
		setglobalvar("dojoEnergyRate", 0);
	}
	menuDojo();
}

void menuDojo()
{
	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 100;			//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 0;
	int yAdd   = 11;
	int layer  = 1000000003;
	float hRes = openborvariant("hresolution");

	if(getglobalvar("highlight") == 0){	font0 = 1;}
	else if(getglobalvar("highlight") == 1){	font1 = 1;}
	else if(getglobalvar("highlight") == 2){	font2 = 1;}

	//DRAW MENU
	if(getglobalvar("activeText") == "Dojo"){
		drawstring((hRes-strwidth("dojo_menu", font0))/2, yPos-yAdd*2, 2, "dojo_menu", layer);

		str  = "select_stage:";align = xPos1-strwidth(str, font0);
		drawstring(align, yPos, font0, str, layer);
		drawstring(xPos2, yPos, font0, getglobalvar("dojoStage"), layer);

		str  = "select_opponent:";align = xPos1-strwidth(str, font1);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font1, str, layer);
		drawstring(xPos2, yPos, font1, getglobalvar("dojoOpponent"), layer);

		str  = "energy_rate:";align = xPos1-strwidth(str, font2);
		yPos = yPos+yAdd;
		drawstring(align, yPos, font2, str, layer);
		drawstring(xPos2, yPos, font2, getglobalvar("dojoEnergyRate"), layer);


		drawstring((hRes-strwidth("(press_start_to_begin,_or_jump_to_exit)", font0))/2, yPos+yAdd*6, 2, "(press_start_to_begin,_or_jump_to_exit)", layer);
	}

	if(getglobalvar("dojoStage") != NULL()) {
		setlocalvar("branch", getglobalvar("dojoStage"));
	}

	//BEGIN GAME WHEN ANY BUTTON IS PRESSED
	if(getglobalvar("dojoStart") == 0){
		changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
		changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ESC"));
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ESC"));
		setglobalvar("activeText", "Dojo");
	}
	else
	if(getglobalvar("dojoStart") == 1 && getglobalvar("dojoOpponent") != NULL()){
		changeplayerproperty(0, "disablekeys", 0);
		changeplayerproperty(1, "disablekeys", 0);
		changeplayerproperty(2, "disablekeys", 0);
		changeplayerproperty(3, "disablekeys", 0);
		jumptobranch(getlocalvar("branch"), 1);
		setglobalvar("activeText", 0);
	}
}
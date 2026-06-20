void menuControls()
{//Draw a Menu in/out game

//HIGHLIGHT OPTIONS:
//1	- BLOCK TYPE				(UPDATED.C, KEYALL.C)
//2	- RUN TYPE					(UPDATED.C, KEYALL.C)
//3	- DODGE TYPE				(UPDATED.C, KEYALL.C)
//4	- JUMP TYPE					(UPDATED.C, KEYALL.C)
//5	- EXTRA BUTTON				(UPDATED.C, KEYALL.C)
//6	- SCREENSHOTS				(UPDATED.C, KEYALL.C)
//7	- ARCADE LOCK				(UPDATED.C, KEYALL.C)
//8	- COMMAND LIST				(UPDATED.C, KEYALL.C)
//9	- TOUCH LAYOUT				(UPDATED.C, KEYALL.C)

	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 70;			//BASE Y POSITION FOR ALL MENU CONTENT, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 0;
	int font3  = 0;
	int font4  = 0;
	int font5  = 0;
	int font6  = 0;
	int font7  = 0;
	int font8  = 0;
	int font9  = 0;
	int yAdd   = 11;
	int layer  = 1000000003;
	
	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 1){	font1 = 1;}else 	//IS BLOCK TYPE HIGHLIGHTED??
	if(getglobalvar("highlight") == 2){	font2 = 1;}else 	//IS RUN TYPE HIGHLIGHTED??
	if(getglobalvar("highlight") == 3){	font3 = 1;}else 	//IS DODGE TYPE HIGHLIGHTED??
	if(getglobalvar("highlight") == 4){	font4 = 1;}else 	//IS JUMP TYPE HIGHLIGHTED??
	if(getglobalvar("highlight") == 5){	font5 = 1;}else 	//IS EXTRA BUTTON HIGHLIGHTED??
	if(getglobalvar("highlight") == 6){	font6 = 1;}else 	//IS SCREENSHOTS HIGHLIGHTED??
	if(getglobalvar("highlight") == 7){	font7 = 1;}else 	//IS ARCADE LOCK HIGHLIGHTED??
	if(getglobalvar("highlight") == 8){	font8 = 1;}else 	//IS COMMAND LIST HIGHLIGHTED??
	if(getglobalvar("highlight") == 9){	font9 = 1;}			//IS TOUCH LAYOUT HIGHLIGHTED??
	
	//DRAW MENU
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") == "controls"){

			str  = "block_type:";align = xPos1-strwidth(str, font0);
			drawstring(align, yPos, font1, str, layer);
			drawstring(xPos2, yPos, font1, getglobalvar("blockType"), layer);

			str  = "run_type:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font2, str, layer);
			drawstring(xPos2, yPos, font2, getglobalvar("runType"), layer);

			str  = "dodge_type:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font3, str, layer);
			drawstring(xPos2, yPos, font3, getglobalvar("dodgeType"), layer);
			
			str  = "jump_type:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font4, str, layer);
			drawstring(xPos2, yPos, font4, getglobalvar("jumpType"), layer);
			
			str  = "extra_button:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font5, str, layer);
			drawstring(xPos2, yPos, font5, getglobalvar("extraButton"), layer);
			
			str  = "screenshots:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font6, str, layer);
			drawstring(xPos2, yPos, font6, getglobalvar("screenshots"), layer);

			str  = "arcade_lock:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font7, str, layer);
			drawstring(xPos2, yPos, font7, getglobalvar("arcadeLockToggle"), layer);
			
			str  = "command_list:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font8, str, layer);
			drawstring(xPos2, yPos, font8, "open_>_>", layer);
			
			str  = "touch_layout:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font9, str, layer);
			drawstring(xPos2, yPos, font9, getglobalvar("touchLayout")+"_(restart)", layer);
			
			yPos = yPos+yAdd;
			
			if(getglobalvar("highlight") == 9 && getglobalvar("touchLayout") != "custom"){ //IS TOUCH LAYOUT HIGHLIGHTED??
				setdrawmethod(NULL(),0,256,256,0,0,0,0);
				drawsprite(getglobalvar(getglobalvar("touchLayout")), xPos2, yPos, layer);
			}
		}
	}
}
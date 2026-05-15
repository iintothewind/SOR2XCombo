void menuCommands()
{//Draw a Menu in/out game

	void self 	= getlocalvar("self");
	float hRes  = openborvariant("hresolution");
	int xPos1 	= 10; 			//BASE X POSITION, FIRST COLUMN
	int xDif 	= 130;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2 	= xPos1+xDif;	//BASE X POSITION, SECOND COLUMN
	int yPos1 	= 4;			//BASE Y POSITION FOR ALL MENU CONTENT OUT GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int title 	= 40;			//BASE Y DISTANCE FROM THE TITLE TO THE COMMANDS
	int lastY 	= 260;			//BASE Y DISTANCE FROM THE COMMANDS TO THE LAST LINE "PAGE/BACK"
	int addY  	= 16;			//BASE ADDED DISTANCE IN EACH LINE
	int font0 	= 7;			//FONT TITLE
	int font1 	= 1;			//FONT LEFT COLUMN
	int font2 	= 8;			//FONT RIGHT COLUMN
	int font3 	= 2;			//FONT EXIT
	int layer1 	= 1000000001;
	int layer2 	= 1000000003;

	//DIRECTIONS LEGEND
	//UP 	= :
	//DOWN 	= ;
	//LEFT 	= <
	//RIGHT	= >

	//DRAW MENU
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") == "commands_1"){
			setdrawmethod(NULL(),0,256,256,0,0,0,0);
			drawsprite(getglobalvar("back4"), 0, 0, layer1);
			drawstring((hRes-strwidth("COMMAND LIST", font0))/2, yPos1, font0, "COMMAND LIST", layer2);
			yPos1 = yPos1+title;
			drawstring(xPos1, yPos1, font1, "RUN", layer2);
			drawstring(xPos2, yPos1, font2, "PRESS > >", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "BLOCK", layer2);
			drawstring(xPos2, yPos1, font2, "HOLD bLOCK BUTTON", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "PARRY", layer2);
			drawstring(xPos2, yPos1, font2, "PRESS bLOCK OR > BUTTONS (ALT. MODE ON) BEFORE ANY ATTACK IMPACT", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "DODGE", layer2);
			drawstring(xPos2, yPos1, font2, "HOLD IN ANY DIRECTION THEN PRESS dODGE (SOR2X) OR : : / ; ; (SOR3)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "SAFE LANDING", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN THROWN, HOLD : + dOWN", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "AERIAL RECOVERY", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN KNOCKED OUT, HOLD : + jUMP (COST GUARD BAR)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "FAST RISING", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN FALLEN, HOLD : + aTTACK", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "BACK ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "HOLD : OR ; THEN PRESS ExTRA BUTTON", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "CHARGE ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "(OPTIONAL HOLD > or < ) PRESS ExTRA BUTTON", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "JUMPING ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN JUMPING PRESS aTTACK", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "RUNNING ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN RUNNING PRESS aTTACK", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "GRAB ENEMIES", layer2);
			drawstring(xPos2, yPos1, font2, "MOVE CLOSE TO THE ENEMY, OR PRESS eNERGY WHEN RUNNING ", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos2, yPos1, font2, "(GRAB RUN SPECIAL SUPPORT CHARACTERS ONLY)", layer2);
			drawstring((hRes-strwidth("<_________>", font3))/2, lastY, font3, "<_________>", layer2);
			drawstring((hRes-strwidth("1/2", font3))/2, lastY, font3, "1/2", layer2);
		}

		if(getglobalvar("subMenu") == "commands_2"){
			setdrawmethod(NULL(),0,256,256,0,0,0,0);
			drawsprite(getglobalvar("back4"), 0, 0, layer1);
			drawstring((hRes-strwidth("COMMAND LIST", font0))/2, yPos1, font0, "COMMAND LIST", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "GRAB ESCAPE", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN GRABBED BY THE ENEMY, PRESS aTTACK (COST 1/4 GUARD BAR)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "GET ITEM/WEAPON", layer2);
			drawstring(xPos2, yPos1, font2, "MOVE CLOSE TO THE ITEM/WEAPON AND PRESS aTTACK", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "THROW WEAPONS", layer2);
			drawstring(xPos2, yPos1, font2, "HOLD : OR ; THEN PRESS ExTRA BUTTON", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "SPECIAL ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN IDLE/WALKING/JUMPING, PRESS sPECIAL (COST LIFE/OKBAR/ENERGY)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "COUNTER ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN BLOCKING PRESS > or < (RECOVER ENERGY BASED ON SKILL LEVEL)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "SUPER ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "WHEN RUNNING PRESS eNERGY (COST ENERGY)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "RAGE ATTACKS", layer2);
			drawstring(xPos2, yPos1, font2, "PRESS ; > + eNERGY OR HOLD ; THEN PRESS sPECIAL IN COMBO(COST ENERGY)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "AIR COMBOS", layer2);
			drawstring(xPos2, yPos1, font2, "PRESS eNERGY IN ANY COMBO TO PERFORM QUICK JUMP ATTACK,", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos2, yPos1, font2, "OR PRESS sPECIAL IN THE AIR TO PERFORM AIR SPECIAL", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "LAST CHANCE", layer2);
			drawstring(xPos2, yPos1, font2, "(PASSIVE)RECOVER SMALL AMOUNT OF LIFE WHEN DYING(COST ALL GUARD BAR)", layer2);
			yPos1 = yPos1+addY;
			drawstring(xPos1, yPos1, font1, "SUPER ARMOR", layer2);
			drawstring(xPos2, yPos1, font2, "(PASSIVE)RESIST ONE HIT(COST 1/2 GUARD BAR)", layer2);

			drawstring((hRes-strwidth("<_________>", font3))/2, lastY, font3, "<_________>", layer2);
			drawstring((hRes-strwidth("2/2", font3))/2, lastY, font3, "2/2", layer2);
		}
	}
}
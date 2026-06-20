void main()
{//Draw image preview of the selected route before player's confirmation after countdown reachs the limit
	void self   = getlocalvar("self");
	float hRes  = openborvariant("hresolution");
	int font0  	= 0;
	int font1  	= 1;
	int font2  	= 2;
	int font3  	= 7;
	int layer0 	= 1000000001;
	int layer1 	= 1000000003;
	int layer2 	= 1001;
	int xPos1 	= 225;
	int xDif  	= 5;
	int xPos2  	= xPos1+xDif;
	int yPos1	= 66;		//DEFAULT Y POSITION FOR TEXTS
	int yPos2	= 180;		//DEFAULT Y POSITION FOR TEXTS
	int yDif	= 11;		//DIFFERENCE BETWEEN TEXT LINES
	int xLab	= 0;		//DEFAULT X POSITION FOR LEVEL LABEL
	int yLab	= 40;		//DEFAULT Y POSITION FOR LEVEL LABEL
	int xPrev;				//DEFAULT X POSITION FOR LEVEL PREVIEW
	int yPrev;				//DEFAULT Y POSITION FOR LEVEL PREVIEW

	if(getglobalvar("activeText") == 0){ //CHECK IF EXTRA MENU IS ALREADY ON
		if(getglobalvar("preview") != NULL() && getglobalvar("label") != NULL()){ //IS ANY IMAGE PREVIEW SAVED IN THE PREVIEW GLOBAL VARIABLE??
			changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
			changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
			changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			setglobalvar("activeText", "Route"); //SET ACTIVE TEXT TO ROUTE MENU
		}else{
			drawstring((hRes-strwidth("SELECT_ROUTE", font3))/2+1, yPos1, font3, "SELECT_ROUTE", layer2);
		}
	}

	if(getglobalvar("activeText") == "Route"){ //CHECK IF ROUTE MENU IS ALREADY ON

		//DETECT CURRENT NAME TO CHANGE X/Y POSITIONS OF NEXT LEVEL PREVIEW
		if(getglobalvar("pName") == "Route_Left" || getglobalvar("pName") == "Route_Down"){
			xPrev = 0;
			yPrev = 235;
		}
		else
		if(getglobalvar("pName") == "Route_Right" || getglobalvar("pName") == "Route_Up"){
			xPrev = 420;
			yPrev = 235;
		}else{
			xPrev = 210;
			yPrev = 235;
		}

		//DRAW BACKGROUND
		setdrawmethod(NULL(),1,256,256,0,0,0,6); //GLOBAL DRAWMETHOD SETTINGS
		drawsprite(getglobalvar("back2"), 0, 0, layer0);

		//DRAW NEXT LEVEL LABEL
		drawsprite(getglobalvar("label"), xLab, yLab, layer1); //DRAW LEVEL LABEL

		//DRAW NEXT LEVEL PREVIEW
		setdrawmethod(NULL(),1,32,32,0,0,0,0); //GLOBAL DRAWMETHOD SETTINGS
		drawsprite(getglobalvar("preview"), xPrev, yPrev, layer1); //DRAW LEVEL THUMBNAIL

		//DRAW NEXT ROUTE CONTENT AND CONFIRMATION
		drawstring(xPos1-strwidth("route:", font0), yPos2, font0, "route:", layer1); //DRAW TEXT "ROUTE"
		drawstring(xPos2, yPos2, font2, getglobalvar("branch"), layer1); //DRAW TEXT "BRANCH NAME"
		yPos2 = yPos2+yDif;
		drawstring((hRes-strwidth("<___________>", font1))/2, yPos2, font1, "<___________>", layer1);
		drawstring((hRes-strwidth(getglobalvar("routeConfirm"), font1))/2, yPos2, font1, getglobalvar("routeConfirm"), layer1);
		yPos2 = yPos2+yDif*4;
		drawstring((hRes-strwidth("(press_attack_button_to_confirm)", font2))/2, yPos2, font2, "(press_attack_button_to_confirm)", layer1);
	}
}
void menuExtra()
{//Draw a Menu in/out game

//HIGHLIGHT OPTIONS:
//0	- EXTRA MENU TYPE	(UPDATED.C, KEYALL.C)

	float hRes  = openborvariant("hresolution");
	int yLine  	= 50;		//BASE Y LINE POSITION FOR ALL MENU CONTENT, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int yAdd  	= 11;		//SPACE BETWEEN LINES
	int yLast  	= yAdd*19;	//POSITION OF THE LAST LINE
	int font0 	= 0;
	int font1 	= 2;
	int layer0 	= 100000000;
	int layer1 	= 1000000001;
	int layer2 	= 1000000003;
	
	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 0){font0 = 1;} //IS GAMEPLAY HIGHLIGHTED??
	
	//DRAW MENU OUT-GAME
	if(openborvariant("current_scene") == "data/scenes/howto.txt"){
		if(getglobalvar("subMenu") != "commands_1" && getglobalvar("subMenu") != "commands_2"){
			drawstring((hRes-strwidth("extra_menu", font1))/2, yLine-yAdd*2, font1, "extra_menu", layer2);
			drawstring((hRes-strwidth("<_______________________________>", font0))/2, yLine, font0, "<_______________________________>", layer2);
			drawstring((hRes-strwidth(getglobalvar("subMenu"), font0))/2, yLine, font0, getglobalvar("subMenu"), layer2);
			drawstring((hRes-strwidth("(press_select_to_restore_defaults)", font1))/2, yLine+yLast, font1, "(press_select_to_restore_defaults)", layer2);
			changeplayerproperty(0, "disablekeys", 0);
			changeplayerproperty(1, "disablekeys", 0);
			changeplayerproperty(2, "disablekeys", 0);
			changeplayerproperty(3, "disablekeys", 0);
		}else{
			changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ANYBUTTON")+openborconstant("FLAG_ESC"));
			changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ANYBUTTON")+openborconstant("FLAG_ESC"));
			changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ANYBUTTON")+openborconstant("FLAG_ESC"));
			changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ANYBUTTON")+openborconstant("FLAG_ESC"));
		}
	}
	
	//DRAW MENU IN-GAME
	if(getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") != "commands_1" && getglobalvar("subMenu") != "commands_2"){
			setdrawmethod(NULL(),1,256,256,0,0,0,2);
			drawsprite(getglobalvar("back1"), 0, 0, layer1);
			drawstring((hRes-strwidth("extra_menu", font1))/2, yLine-yAdd*2, font1, "extra_menu", layer2);
			drawstring((hRes-strwidth("<_______________________________>", font0))/2, yLine, font0, "<_______________________________>", layer2);
			drawstring((hRes-strwidth(getglobalvar("subMenu"), font0))/2, yLine, font0, getglobalvar("subMenu"), layer2);
		}
	}
	
	//USED ONLY TO DRAW A BACKGROUND AT OPTIONS SCREEN IN-GAME
	if(openborvariant("in_options")){
		setdrawmethod(NULL(),1,256,256,0,0,0,2);
		drawsprite(getglobalvar("back1"), 0, 0, layer0);
	}
}
void debugMode()
{//Enable/Disable debug mode for test purposes (PLAYER 1 ONLY)
	int debug = getglobalvar("debugMode");

	if(debug == 1 || debug == 2){ //IS DEBUG MODE 1 OR 2 ACTIVATED??
		if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){
			int font  = 0;
			int xPos  = 1;
			int yPos  = 210;
			int yAdd  = 10;
			int layer = 1001;

			if(	openborvariant("current_branch") == "sor3_st6a" || openborvariant("current_branch") == "sor3_st6b" ||
				openborvariant("current_branch") == "sor3_st6c" || openborvariant("current_branch") == "sor3_st6d" ||
				openborvariant("current_branch") == "sor3_st6e"){
				yPos = yPos-yAdd;
			}
			if(openborvariant("current_branch") == "sor3_st7d" ){yPos = yPos-20;}
			if(openborvariant("current_branch") == "survival_b"){yPos = yPos-30;}

			drawstring(xPos, yPos+yAdd, font, "DEBUG_MODE_"+getglobalvar("debugMode"), layer);
			yPos = yPos+yAdd;
			drawstring(xPos, yPos+yAdd, font, "ENEMIES_"+openborvariant("count_enemies"), layer);
			yPos = yPos+yAdd;
			drawstring(xPos, yPos+yAdd, font, "XPOS_"+openborvariant("xpos"), layer);
			yPos = yPos+yAdd;
			drawstring(xPos, yPos+yAdd, font, "FPS_"+getglobalvar("getFps"), layer);
			yPos = yPos+yAdd;
			drawstring(xPos, yPos+yAdd, font, "USED_RAM_"+openborvariant("usedram"), layer);
		}
	}
}
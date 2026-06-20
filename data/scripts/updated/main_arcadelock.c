void arcadeLock()
{//Lock/Unlock some options for use the game in Arcade machines (PLAYER 1 ONLY)
	float hRes  = openborvariant("hresolution");
	int font  	= 2;
	int layer 	= 1000000003;
	int yPos	= 262;
	int yDif	= 11;
	
	if(getglobalvar("arcadeLock") == 1){ //IS ARCADE LOCK ENABLED??
		if(openborvariant("in_menuscreen")){ //IN MENU SCREEN??
			if(!openborvariant("in_control_options")){ //NOT IN CONTROL OPTIONS SCREEN??
				if(openborvariant("nopause") != 1){
					changeplayerproperty(0, "disablekeys", openborconstant("FLAG_MOVEUP")+openborconstant("FLAG_MOVEDOWN")+openborconstant("FLAG_MOVELEFT")+openborconstant("FLAG_MOVERIGHT"));
					changeplayerproperty(1, "disablekeys", openborconstant("FLAG_MOVEUP")+openborconstant("FLAG_MOVEDOWN")+openborconstant("FLAG_MOVELEFT")+openborconstant("FLAG_MOVERIGHT"));
					changeplayerproperty(2, "disablekeys", openborconstant("FLAG_MOVEUP")+openborconstant("FLAG_MOVEDOWN")+openborconstant("FLAG_MOVELEFT")+openborconstant("FLAG_MOVERIGHT"));
					changeplayerproperty(3, "disablekeys", openborconstant("FLAG_MOVEUP")+openborconstant("FLAG_MOVEDOWN")+openborconstant("FLAG_MOVELEFT")+openborconstant("FLAG_MOVERIGHT"));
					changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
				}
			}
			drawstring((hRes-strwidth("(ARCADE_LOCK_ON)", font))/2, yPos, font, "(ARCADE_LOCK_ON)", layer);
		}
		
		if(openborvariant("in_control_options") || openborvariant("in_new_game")){ //IN IN CONTROL OPTIONS OR NEW GAME SCREENS??
			if(openborvariant("nopause") != 0){
				changeplayerproperty(0, "disablekeys", 0);
				changeplayerproperty(1, "disablekeys", 0);
				changeplayerproperty(2, "disablekeys", 0);
				changeplayerproperty(3, "disablekeys", 0);
				changeopenborvariant("nopause", 0); //LOCK PAUSE COMMAND
			}
			drawstring((hRes-strwidth("(ARCADE_LOCK_ON)", font))/2, yPos, font, "(ARCADE_LOCK_ON)", layer);
		}
		
		if(openborvariant("in_level")){
			if(openborvariant("game_paused")){
				if(openborvariant("nopause") != 1){
					changeplayerproperty(0, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(1, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(2, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(3, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
				}
				drawstring((hRes-strwidth("(ARCADE_LOCK_ON)", font))/2, yPos-yDif, font, "(ARCADE_LOCK_ON)", layer);
			}else{
				if(openborvariant("nopause") != 0){
					changeplayerproperty(0, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(1, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(2, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeplayerproperty(3, "disablekeys", openborconstant("FLAG_SCREENSHOT"));
					changeopenborvariant("nopause", 0); //LOCK PAUSE COMMAND
				}
			}
		}
	}
	else 
	if(getglobalvar("arcadeLock") == 0){ //IS ARCADE LOCK DISABLED??
		if(openborvariant("in_menuscreen")){ //IN MENU SCREEN??
			if(openborvariant("nopause") != 0){
				changeplayerproperty(0, "disablekeys", 0);
				changeplayerproperty(1, "disablekeys", 0);
				changeplayerproperty(2, "disablekeys", 0);
				changeplayerproperty(3, "disablekeys", 0);
				changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
			}
		}
	}
}
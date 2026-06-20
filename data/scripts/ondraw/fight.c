void main()
{//Draw "Round" number and "Fight" words before level starts
	void self	= getlocalvar("self");
	void ani	= getentityproperty(self, "animationID");
	void branch	= openborvariant("current_branch");
	int xDif	= 6;
	int xRound	= 9;
	int xFight	= 306;
	int yDif	= 109;
	int layer	= 1000000003;
	int font	= 7;
	int level	= openborvariant("current_level");
	int frame	= getentityproperty(self, "animpos");
	int x		= getentityproperty(self, "x");
	int y		= getentityproperty(self, "y");
	int z		= getentityproperty(self, "z");

	if(openborvariant("current_set") == 1){ //SURVIVAL MODE, DRAW ONLY "FIGHT" WORD
		if(branch == "survival_a" || branch == "survival_b"){ //SINGLE AND GROUP MODES, DRAW ONLY "FIGHT" WORD
			if(ani == openborconstant("ANI_IDLE")){
				setglobalvar("activeText", "Fight");
				changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
				changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
				changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
			}

			if(ani == openborconstant("ANI_FOLLOW1")){
				if(frame <= 2){
					setglobalvar("activeText", "Fight");
					changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
					changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
					changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				}
				else
				if(frame >= 3){
					setglobalvar("activeText", 0);
					changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
					changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
					changeplayerproperty(0, "disablekeys", 0);
					changeplayerproperty(1, "disablekeys", 0);
					changeplayerproperty(2, "disablekeys", 0);
					changeplayerproperty(3, "disablekeys", 0);
				}
			}
			drawstring(x+xDif, z-y+yDif, font, "fight!", layer);
		}
		else
		{ //BATTLE ROYALE MODE, DRAW "ROUND NUMBER" AND "FIGHT" WORDS
			if(ani == openborconstant("ANI_IDLE")){
				setglobalvar("activeText", "Fight");
				changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
				changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
				changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
			}

			if(ani == openborconstant("ANI_FOLLOW2")){
				if(frame <= 4){
					setglobalvar("activeText", "Fight");
					changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
					changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
					changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
					changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				}
				else
				if(frame >= 5){
					setglobalvar("activeText", 0);
					changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
					changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
					changeplayerproperty(0, "disablekeys", 0);
					changeplayerproperty(1, "disablekeys", 0);
					changeplayerproperty(2, "disablekeys", 0);
					changeplayerproperty(3, "disablekeys", 0);
				}
			}

			if(level < 13){xRound = 3;}

			drawstring(x-xRound, z-y+yDif, font, "round_"+(level-xDif), layer);
			drawstring(x-xFight, z-y+yDif, font, "fight!", layer);
		}
	}


	if(openborvariant("current_set") == 3){
		if(ani == openborconstant("ANI_IDLE")){
			setglobalvar("activeText", "Fight");
			changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
			changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
			changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
		}

		if(ani == openborconstant("ANI_FOLLOW1")){
			if(frame <= 2){
				setglobalvar("activeText", "Fight");
				changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
				changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
				changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
			}
			else
			if(frame >= 3){
				setglobalvar("activeText", 0);
				changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
				changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
				changeplayerproperty(0, "disablekeys", 0);
				changeplayerproperty(1, "disablekeys", 0);
				changeplayerproperty(2, "disablekeys", 0);
				changeplayerproperty(3, "disablekeys", 0);
			}
		}
		drawstring(x+xDif, z-y+yDif, font, "fight!", layer);
	}
}
void menuRoute(int player)
{//Change Route menu confirmation between yes or no
	int confirm   = getglobalvar("routeConfirm");
	int hasplayed = getplayerproperty(player, "hasplayed");
	
	if(getglobalvar("activeText") == "Route" && hasplayed == 1){ //CHECK IF ROUTE MENU IS ALREADY ON
		
		//CHANGE OPTIONS
		if(playerkeys(player, 1, "moveleft") || playerkeys(player, 1, "moveright")){
			if(confirm == "no"){
				setglobalvar("routeConfirm", "yes");
			}else{
				setglobalvar("routeConfirm", "no");
			}
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
		}
		
		//CONFIRM ROUTE
		if(playerkeys(player, 1, "anybutton")){
			if(confirm == "yes"){
				playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
				jumptobranch(getglobalvar("branch"), 1); //JUMP TO SELECTED ROUTE
				setglobalvar("preview", NULL());
				setglobalvar("routeConfirm", "no");
				setglobalvar("activeText", 0);
			}else{
				playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
				changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
				changeplayerproperty(0, "disablekeys", 0);
				changeplayerproperty(1, "disablekeys", 0);
				changeplayerproperty(2, "disablekeys", 0);
				changeplayerproperty(3, "disablekeys", 0);
				setglobalvar("preview", NULL());
				setglobalvar("activeText", 0);
			}
		}
	}
}
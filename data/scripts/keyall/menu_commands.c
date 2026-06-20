void menuCommands(int player)
{//Change Controls Menu variables if defined key is pressed

	int highlight = getglobalvar("highlight");
	int hasplayed = getplayerproperty(player, "hasplayed");
	int delay	  = 50;
	
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
		if(getglobalvar("subMenu") == "commands_1"){
			if(playerkeys(getglobalvar("player"), 1, "moveright")){ //PRESSED ANY MOVE KEY??
				if(openborvariant("elapsed_time") > getglobalvar("subMenuDelay")+delay){
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					setglobalvar("subMenu", "commands_2"); //SET SUBMENU TO "COMMANDS_2" TO BACK TO CHANGE PAGE
				}
			}

			if(playerkeys(getglobalvar("player"), 1, "moveleft")){ //PRESSED ANY MOVE KEY??
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				setglobalvar("subMenu", "controls"); //SET SUBMENU TO "CONTROLS" TO BACK TO EXTRA MENU
			}
		}
		
		if(getglobalvar("subMenu") == "commands_2"){
			if(playerkeys(getglobalvar("player"), 1, "moveleft")){ //PRESSED ANY MOVE KEY??
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				setglobalvar("subMenu", "commands_1"); //SET SUBMENU TO "COMMANDS_1" TO BACK TO CHANGE PAGE
			}
		}
	}
}
#import "data/scripts/keyall/main_savecfg.c"

void arcadeLock(int player)
{//Lock/Unlock Options Menu/Extra Menu for use the game in Arcade machines

	if(playerkeys(player, 1, "screenshot")){ //SCREENSHOT KEY IS PRESSED?
		if(openborvariant("in_menuscreen")){ //IN MENU SCREEN?
			if(!openborvariant("in_control_options")){ //NOT IN CONTROL OPTIONS SCREEN?
				if(getglobalvar("arcadeLockToggle") == "toggleable"){ //ARCADE LOCK IS TOGGEABLE AT THE EXTRA MENU??
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
					if(getglobalvar("arcadeLock") == 0){setglobalvar("arcadeLock", 1);}else
					if(getglobalvar("arcadeLock") == 1){setglobalvar("arcadeLock", 0);}
					saveCfg();
				}
			}
		}
	}
}

void turboKey(int player)
{//Script to increase cursor repeat rate and speed, like a turbo key
	float time	= openborvariant("elapsed_time");
	float delay	= 50; //TURBO KEY INITIAL DELAY

	//ANY DIRECTIONAL BUTTON IS HELD??
	if(playerkeys(player, 0, "moveright")||playerkeys(player, 0, "moveleft")||playerkeys(player, 0, "moveup")||playerkeys(player, 0, "movedown")){

		//SET BUTTON START TIME TO CALCULATE INITIAL DELAY
		if(getglobalvar("heldStart"+player) == NULL()){setglobalvar("heldStart"+player, time+delay);}
	}
	else //NO DIRECTIONAL BUTTON IS HELD??
	{
		setglobalvar("heldStart"+player, NULL()); //RESET BUTTON START TIME
		setglobalvar("heldRepeat"+player, NULL()); //RESET BUTTON REPEAT TIME
	}
}


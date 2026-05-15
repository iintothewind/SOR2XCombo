void debugMode(int player)
{//Turn debug mode on/off for test purposes (PLAYER 1 ONLY)

	if(player == 0){	
		if(playerkeys(player, 1, "esc") && getglobalvar("arcadeLock") == 0){ //ESC KEY IS PRESSED?
			if(openborvariant("in_level")){ //IN ANY LEVEL?
				if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //NOT PAUSED AND NOT IN OPTIONS?
					if(getglobalvar("activeText") == 0 && getglobalvar("debugMode") == 0){ //IS DEBUG MODE TURNED OFF??
						changeopenborvariant("slowmotion", 1); //ACTIVATE SLOW MOTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
						setglobalvar("debugMode", 1); //ACTIVATE DEBUG MODE TYPE 1
					}
					else 
					if(getglobalvar("activeText") == 0 && getglobalvar("debugMode") == 1){ //IS IN DEBUG MODE TYPE 1??
						changeopenborvariant("slowmotion", 0); //DEACTIVATE SLOW MOTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
						setglobalvar("debugMode", 2); //ACTIVATE DEBUG MODE TYPE 2
					}
					else 
					if(getglobalvar("activeText") == 0 && getglobalvar("debugMode") == 2){ //IS IN DEBUG MODE TYPE 2??
						changeopenborvariant("slowmotion", 0); //ACTIVATE SLOW MOTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
						setglobalvar("activeText", 0); //DEACTIVATE DEBUG MODE TYPE 2
						setglobalvar("debugMode", 0); //DEACTIVATE DEBUG MODE
					}
				}
			}
		}
	}
}
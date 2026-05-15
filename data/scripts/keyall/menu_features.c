#import "data/scripts/keyall/main_savecfg.c"
#import "data/scripts/keyall/main_playlist.c"
#import "data/scripts/levelspawn/main_musicmisc.c"

void menuFeatures(int player)
{//Change Features Menu variables if defined key is pressed

//HIGHLIGHT OPTIONS:
//1	- LEVEL TIME				(UPDATED.C, KEYALL.C)
//2	- PLAYED TIME				(UPDATED.C, KEYALL.C)
//3	- PLAYER ARROW				(UPDATED.C, KEYALL.C)
//4	- SHOW DAMAGE				(UPDATED.C, KEYALL.C)
//5	- GRAPHIC EFFECTS			(UPDATED.C, KEYALL.C)
//6	- MUSIC STYLE				(UPDATED.C, KEYALL.C)
//7	- BGM TEST					(UPDATED.C, KEYALL.C)
//8	- LEVEL SELECT				(UPDATED.C, KEYALL.C)

	int highlight = getglobalvar("highlight");
	int hasplayed = getplayerproperty(player, "hasplayed");
	int max		  = 8;
	int min		  = 0;
	int add		  = 1;
	int firstBgm  = 0;
	int lastBgm	  = 49;

	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
		if(getglobalvar("subMenu") == "features"){

			//HIGHLIGHT OPTIONS WHEN MOVE DOWN
			if(playerkeys(player, 1, "movedown")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//BLOCK LEVEL SELECT OPTION IF THE GAME IS NOT CLEARED 3 OR MORE TIMES
				if(getsaveinfo(0, "times_completed") < 3){
					if(highlight >= min && highlight < max-add){setglobalvar("highlight", highlight+1);bgmTest();}
					if(highlight == max-add){setglobalvar("highlight", min);bgmTest();}
				}else{
					if(highlight >= min && highlight < max){setglobalvar("highlight", highlight+1);bgmTest();}
					if(highlight == max){setglobalvar("highlight", min);bgmTest();}
				}

			}

			//HIGHLIGHT OPTIONS WHEN MOVE UP
			if(playerkeys(player, 1, "moveup")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//BLOCK LEVEL SELECT OPTION IF THE GAME IS NOT CLEARED 3 OR MORE TIMES
				if(getsaveinfo(0, "times_completed") < 3){
					if(highlight > min && highlight <= max-add){setglobalvar("highlight", highlight-1);bgmTest();}
					if(highlight == min){setglobalvar("highlight", max-add);bgmTest();}
				}else{
					if(highlight > min && highlight <= max){setglobalvar("highlight", highlight-1);bgmTest();}
					if(highlight == min){setglobalvar("highlight", max);bgmTest();}
				}
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE RIGHT
			if(playerkeys(player, 1, "moveright")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS LEVEL TIME HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("levelTime") == "timeline"){setglobalvar("levelTime", "numeric");}else
					if(getglobalvar("levelTime") == "numeric"){setglobalvar("levelTime", "both");}else
					if(getglobalvar("levelTime") == "both"){setglobalvar("levelTime", "off");}else
					if(getglobalvar("levelTime") == "off"){setglobalvar("levelTime", "timeline");}
				}

				//IS PLAYED TIME HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("playedTime") == "on"){setglobalvar("playedTime", "off");}else
					if(getglobalvar("playedTime") == "off"){setglobalvar("playedTime", "on");}
				}

				//IS PLAYER ARROW HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("playerArrow") == "off"){setglobalvar("playerArrow", "on");}else
					if(getglobalvar("playerArrow") == "on"){setglobalvar("playerArrow", "off");}
				}

				//IS SHOW DAMAGE HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("showDamage") == "combos_only"){setglobalvar("showDamage", "combos+hits");}else
					if(getglobalvar("showDamage") == "combos+hits"){setglobalvar("showDamage", "combos_only");}
				}

				//IS GRAPHIC EFFECTS HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("graphicEffects") == "sor2x"){setglobalvar("graphicEffects", "original");}else
					if(getglobalvar("graphicEffects") == "original"){setglobalvar("graphicEffects", "sor2x");}
				}

				//IS MUSIC STYLE HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("musicStyle") == "remake"){setglobalvar("musicStyle", "custom");}else
					if(getglobalvar("musicStyle") == "custom"){setglobalvar("musicStyle", "remake");}
					musicReplay();
					playList();
				}

				//IS BGM TEST HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("bgmTest") >= firstBgm && getglobalvar("bgmTest") < lastBgm){setglobalvar("bgmTest", getglobalvar("bgmTest")+1);}else
					if(getglobalvar("bgmTest") == lastBgm){setglobalvar("bgmTest", firstBgm);}
					bgmTest();
				}

				//IS LEVEL SELECT HIGHLIGHTED??
				if(getglobalvar("highlight") == 8){
					if(getglobalvar("levelSelect") == "off"){setglobalvar("levelSelect", "on");}else
					if(getglobalvar("levelSelect") == "on"){setglobalvar("levelSelect", "off");}
				}
				saveCfg();
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
			if(playerkeys(player, 1, "moveleft")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS LEVEL TIME HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("levelTime") == "timeline"){setglobalvar("levelTime", "off");}else
					if(getglobalvar("levelTime") == "off"){setglobalvar("levelTime", "both");}else
					if(getglobalvar("levelTime") == "both"){setglobalvar("levelTime", "numeric");}else
					if(getglobalvar("levelTime") == "numeric"){setglobalvar("levelTime", "timeline");}
				}

				//IS PLAYED TIME HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("playedTime") == "on"){setglobalvar("playedTime", "off");}else
					if(getglobalvar("playedTime") == "off"){setglobalvar("playedTime", "on");}
				}

				//IS PLAYER ARROW HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("playerArrow") == "off"){setglobalvar("playerArrow", "on");}else
					if(getglobalvar("playerArrow") == "on"){setglobalvar("playerArrow", "off");}
				}

				//IS SHOW DAMAGE HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("showDamage") == "combos_only"){setglobalvar("showDamage", "combos+hits");}else
					if(getglobalvar("showDamage") == "combos+hits"){setglobalvar("showDamage", "combos_only");}
				}

				//IS GRAPHIC EFFECTS HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("graphicEffects") == "sor2x"){setglobalvar("graphicEffects", "original");}else
					if(getglobalvar("graphicEffects") == "original"){setglobalvar("graphicEffects", "sor2x");}
				}

				//IS MUSIC STYLE HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("musicStyle") == "custom"){setglobalvar("musicStyle", "remake");}else
					if(getglobalvar("musicStyle") == "remake"){setglobalvar("musicStyle", "custom");}
					musicReplay();
					playList();
				}

				//IS BGM TEST HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("bgmTest") > firstBgm && getglobalvar("bgmTest") <= lastBgm){setglobalvar("bgmTest", getglobalvar("bgmTest")-1);}else
					if(getglobalvar("bgmTest") == firstBgm){setglobalvar("bgmTest", lastBgm);}
					bgmTest();
				}

				//IS LEVEL SELECT HIGHLIGHTED??
				if(getglobalvar("highlight") == 8){
					if(getglobalvar("levelSelect") == "off"){setglobalvar("levelSelect", "on");}else
					if(getglobalvar("levelSelect") == "on"){setglobalvar("levelSelect", "off");}
				}
				saveCfg();
			}
		}
	}
}
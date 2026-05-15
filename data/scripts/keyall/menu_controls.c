#import "data/scripts/keyall/main_savecfg.c"
#import "data/scripts/keyall/main_touch.c"

void menuControls(int player)
{//Change Controls Menu variables if defined key is pressed

//HIGHLIGHT OPTIONS:
//1	- BLOCK TYPE				(UPDATED.C, KEYALL.C)
//2	- RUN TYPE					(UPDATED.C, KEYALL.C)
//3	- DODGE TYPE				(UPDATED.C, KEYALL.C)
//4	- JUMP TYPE					(UPDATED.C, KEYALL.C)
//5	- EXTRA BUTTON				(UPDATED.C, KEYALL.C)
//6	- SCREENSHOTS				(UPDATED.C, KEYALL.C)
//7	- ARCADE LOCK				(UPDATED.C, KEYALL.C)
//8	- COMMAND LIST				(UPDATED.C, KEYALL.C)
//9	- TOUCH LAYOUT				(UPDATED.C, KEYALL.C)

	int highlight = getglobalvar("highlight");
	int hasplayed = getplayerproperty(player, "hasplayed");
	int max		  = 9;
	int min		  = 0;
	int add		  = 1;

	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
		if(getglobalvar("subMenu") == "controls"){

			//HIGHLIGHT OPTIONS WHEN MOVE DOWN
			if(playerkeys(player, 1, "movedown")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				if(highlight >= min && highlight < max){setglobalvar("highlight", highlight+add);}
				if(highlight == max){setglobalvar("highlight", min);}
			}

			//HIGHLIGHT OPTIONS WHEN MOVE UP
			if(playerkeys(player, 1, "moveup")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				if(highlight > min && highlight <= max){setglobalvar("highlight", highlight-add);}
				if(highlight == min){setglobalvar("highlight", max);}
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE RIGHT
			if(playerkeys(player, 1, "moveright")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS BLOCK TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("blockType") == "hold"){setglobalvar("blockType", "off");}else
					if(getglobalvar("blockType") == "off"){setglobalvar("blockType", "hold");}
				}

				//IS RUN TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("runType") == "sor2x"){setglobalvar("runType", "sor3");}else
					if(getglobalvar("runType") == "sor3"){setglobalvar("runType", "off");}else
					if(getglobalvar("runType") == "off"){setglobalvar("runType", "sor2x");}
				}

				//IS DODGE TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("dodgeType") == "sor2x"){setglobalvar("dodgeType", "sor3");}else
					if(getglobalvar("dodgeType") == "sor3"){setglobalvar("dodgeType", "sor2x");}
				}

				//IS JUMP TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("jumpType") == "sor2x"){setglobalvar("jumpType", "sor1");}else
					if(getglobalvar("jumpType") == "sor1"){setglobalvar("jumpType", "sor2");}else
					if(getglobalvar("jumpType") == "sor2"){setglobalvar("jumpType", "sor3");}else
					if(getglobalvar("jumpType") == "sor3"){setglobalvar("jumpType", "sor2x+sor1");}else
					if(getglobalvar("jumpType") == "sor2x+sor1"){setglobalvar("jumpType", "sor2x+sor3");}else
					if(getglobalvar("jumpType") == "sor2x+sor3"){setglobalvar("jumpType", "sor1+sor3");}else
					if(getglobalvar("jumpType") == "sor1+sor3"){setglobalvar("jumpType", "all_types");}else
					if(getglobalvar("jumpType") == "all_types"){setglobalvar("jumpType", "sor2x");}
				}

				//IS EXTRA BUTTON HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("extraButton") == "charge_attack"){setglobalvar("extraButton", "back_attack");}else
					if(getglobalvar("extraButton") == "back_attack"){setglobalvar("extraButton", "call_partner");}else
					if(getglobalvar("extraButton") == "call_partner"){setglobalvar("extraButton", "charge_attack");}
				}

				//IS SCREENSHOTS HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("screenshots") == "off"){setglobalvar("screenshots", "on");}else
					if(getglobalvar("screenshots") == "on"){setglobalvar("screenshots", "off");}
				}

				//IS ARCADE LOCK HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("arcadeLockToggle") == "toggleable"){setglobalvar("arcadeLockToggle", "off");}else
					if(getglobalvar("arcadeLockToggle") == "off"){setglobalvar("arcadeLockToggle", "toggleable");}
				}

				//IS COMMAND LIST HIGHLIGHTED??
				if(getglobalvar("highlight") == 8){
					setglobalvar("subMenu", "commands_1"); //SET COMMAND LIST ON
					setglobalvar("subMenuDelay", openborvariant("elapsed_time")); //USED TO NOT CHANGE PAGE TWICE
				}

				//IS TOUCH LAYOUT HIGHLIGHTED??
				if(getglobalvar("highlight") == 9){
					if(getglobalvar("touchLayout") == "type_1"){setglobalvar("touchLayout", "type_2");}else
					if(getglobalvar("touchLayout") == "type_2"){setglobalvar("touchLayout", "type_3");}else
					if(getglobalvar("touchLayout") == "type_3"){setglobalvar("touchLayout", "type_4");}else
					if(getglobalvar("touchLayout") == "type_4"){setglobalvar("touchLayout", "type_5");}else
					if(getglobalvar("touchLayout") == "type_5"){setglobalvar("touchLayout", "custom");}else
					if(getglobalvar("touchLayout") == "custom"){setglobalvar("touchLayout", "type_1");}
					defineTouch();
				}
				saveCfg();
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
			if(playerkeys(player, 1, "moveleft")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS BLOCK TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("blockType") == "hold"){setglobalvar("blockType", "off");}else
					if(getglobalvar("blockType") == "off"){setglobalvar("blockType", "hold");}
				}

				//IS RUN TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("runType") == "sor2x"){setglobalvar("runType", "off");}else
					if(getglobalvar("runType") == "off"){setglobalvar("runType", "sor3");}else
					if(getglobalvar("runType") == "sor3"){setglobalvar("runType", "sor2x");}
				}

				//IS DODGE TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("dodgeType") == "sor2x"){setglobalvar("dodgeType", "sor3");}else
					if(getglobalvar("dodgeType") == "sor3"){setglobalvar("dodgeType", "sor2x");}
				}

				//IS JUMP TYPE HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("jumpType") == "sor2x"){setglobalvar("jumpType", "all_types");}else
					if(getglobalvar("jumpType") == "all_types"){setglobalvar("jumpType", "sor1+sor3");}else
					if(getglobalvar("jumpType") == "sor1+sor3"){setglobalvar("jumpType", "sor2x+sor3");}else
					if(getglobalvar("jumpType") == "sor2x+sor3"){setglobalvar("jumpType", "sor2x+sor1");}else
					if(getglobalvar("jumpType") == "sor2x+sor1"){setglobalvar("jumpType", "sor3");}else
					if(getglobalvar("jumpType") == "sor3"){setglobalvar("jumpType", "sor2");}else
					if(getglobalvar("jumpType") == "sor2"){setglobalvar("jumpType", "sor1");}else
					if(getglobalvar("jumpType") == "sor1"){setglobalvar("jumpType", "sor2x");}
				}

				//IS EXTRA BUTTON HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("extraButton") == "charge_attack"){setglobalvar("extraButton", "call_partner");}else
					if(getglobalvar("extraButton") == "call_partner"){setglobalvar("extraButton", "back_attack");}else
					if(getglobalvar("extraButton") == "back_attack"){setglobalvar("extraButton", "charge_attack");}
				}

				//IS SCREENSHOTS HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("screenshots") == "off"){setglobalvar("screenshots", "on");}else
					if(getglobalvar("screenshots") == "on"){setglobalvar("screenshots", "off");}
				}

				//IS ARCADE LOCK HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("arcadeLockToggle") == "toggleable"){setglobalvar("arcadeLockToggle", "off");}else
					if(getglobalvar("arcadeLockToggle") == "off"){setglobalvar("arcadeLockToggle", "toggleable");}
				}

				//IS TOUCH LAYOUT HIGHLIGHTED??
				if(getglobalvar("highlight") == 9){
					if(getglobalvar("touchLayout") == "type_1"){setglobalvar("touchLayout", "custom");}else
					if(getglobalvar("touchLayout") == "custom"){setglobalvar("touchLayout", "type_5");}else
					if(getglobalvar("touchLayout") == "type_5"){setglobalvar("touchLayout", "type_4");}else
					if(getglobalvar("touchLayout") == "type_4"){setglobalvar("touchLayout", "type_3");}else
					if(getglobalvar("touchLayout") == "type_3"){setglobalvar("touchLayout", "type_2");}else
					if(getglobalvar("touchLayout") == "type_2"){setglobalvar("touchLayout", "type_1");}
					defineTouch();
				}
				saveCfg();
			}
		}
	}
}
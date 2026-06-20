#include "data/scripts/keys.h"
#include "data/scripts/assets.h"

void menuLevel(int player)
{//Change level according to global variable "levelName" check
	int hasplayed = getplayerproperty(player, "hasplayed");

	if(getglobalvar("activeText") == "Level" && hasplayed == 1){ //LEVEL SELECT MENU STARTED
		int column = getglobalvar("levelCol"); //DEFAULT COLUMN VALUE
		int line   = getglobalvar("levelLine"); //DEFAULT LINE VALUE
		float time = openborvariant("elapsed_time"); //CURRENT TIME

		//USED FOR NORMAL KEY
		if(playerkeys(player, 1, "moveright")){ //SELECT DESIRED OPTION
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
			if(column >= 0 && column < 7){setglobalvar("levelCol", column+1);}
			if(column == 7){setglobalvar("levelCol", 0);}
		}

		if(playerkeys(player, 1, "moveleft")){ //SELECT DESIRED OPTION
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
			if(column > 0 && column <= 7){setglobalvar("levelCol", column-1);}
			if(column == 0){setglobalvar("levelCol", 7);}
		}

		if(playerkeys(player, 1, "moveup")){ //SELECT DESIRED OPTION
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
			if(line == 0){setglobalvar("levelLine", 18);}
			if(line == 2){setglobalvar("levelLine", 0);}
			if(line == 13){setglobalvar("levelLine", 10);}
			if(line > 2 && line <= 10){setglobalvar("levelLine", line-1);}
			if(line > 13 && line <= 18){setglobalvar("levelLine", line-1);}
		}

		if(playerkeys(player, 1, "movedown")){ //SELECT DESIRED OPTION
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
			if(line == 0){setglobalvar("levelLine", 2);}
			if(line == 10){setglobalvar("levelLine", 13);}
			if(line == 18){setglobalvar("levelLine", 0);}
			if(line >= 2 && line < 10){setglobalvar("levelLine", line+1);}
			if(line >= 13 && line < 18){setglobalvar("levelLine", line+1);}
		}

		//USED TO TRANSLATE LEVELS

		//STAGE 1
		if(getglobalvar("levelCol") == 0){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st01");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st1a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st1b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st1c");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st1a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st1b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st1c");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 2
		if(getglobalvar("levelCol") == 1){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st02");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st2a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st2b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st2c");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st2a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st2b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st2c");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 3
		if(getglobalvar("levelCol") == 2){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st03");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st3a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st3b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st3c");}else
			if(getglobalvar("levelLine") == 5){	setglobalvar("levelName", "sor2_st3d");}else
			if(getglobalvar("levelLine") == 6){	setglobalvar("levelName", "sor2_st3e");}else
			if(getglobalvar("levelLine") == 7){	setglobalvar("levelName", "sor2_st3f");}else
			if(getglobalvar("levelLine") == 8){	setglobalvar("levelName", "sor2_st3g");}else
			if(getglobalvar("levelLine") == 9){	setglobalvar("levelName", "sor2_st3h");}else
			if(getglobalvar("levelLine") == 10){setglobalvar("levelName", "sor2_st3i");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st3a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st3b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st3c");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 4
		if(getglobalvar("levelCol") == 3){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st04");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st4a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st4b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st4c");}else
			if(getglobalvar("levelLine") == 5){	setglobalvar("levelName", "sor2_st4d");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st4a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st4b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st4c");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 5
		if(getglobalvar("levelCol") == 4){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st05");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st5a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st5b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st5c");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st5a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st5b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st5c");}else
			if(getglobalvar("levelLine") == 16){setglobalvar("levelName", "sor3_st5d");}else
			if(getglobalvar("levelLine") == 17){setglobalvar("levelName", "sor3_st5e");}else
			if(getglobalvar("levelLine") == 18){setglobalvar("levelName", "sor3_st6g");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 6
		if(getglobalvar("levelCol") == 5){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st06");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st6a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st6b");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st6a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st6b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st6c");}else
			if(getglobalvar("levelLine") == 16){setglobalvar("levelName", "sor3_st6d");}else
			if(getglobalvar("levelLine") == 17){setglobalvar("levelName", "sor3_st6e");}else
			if(getglobalvar("levelLine") == 18){setglobalvar("levelName", "sor3_st6f");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 7
		if(getglobalvar("levelCol") == 6){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st07");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st7a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st7b");}else
			if(getglobalvar("levelLine") == 4){	setglobalvar("levelName", "sor2_st7c");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st7a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st7b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st7c");}else
			if(getglobalvar("levelLine") == 16){setglobalvar("levelName", "sor3_st7d");}else
			if(getglobalvar("levelLine") == 17){setglobalvar("levelName", "sor3_st7e");}else
			{setglobalvar("levelName", "route");}
		}else

		//STAGE 8
		if(getglobalvar("levelCol") == 7){
			if(getglobalvar("levelLine") == 0){	setglobalvar("levelName", "sor1_st08");}else
			if(getglobalvar("levelLine") == 2){	setglobalvar("levelName", "sor2_st8a");}else
			if(getglobalvar("levelLine") == 3){	setglobalvar("levelName", "sor2_st8b");}else
			if(getglobalvar("levelLine") == 13){setglobalvar("levelName", "sor3_st8a");}else
			if(getglobalvar("levelLine") == 14){setglobalvar("levelName", "sor3_st8b");}else
			if(getglobalvar("levelLine") == 15){setglobalvar("levelName", "sor3_st8c");}else
			if(getglobalvar("levelLine") == 16){setglobalvar("levelName", "sor3_st8d");}else
			if(getglobalvar("levelLine") == 17){setglobalvar("levelName", "sor3_st8e");}else
			{setglobalvar("levelName", "route");}
		}

		//USED TO EXIT WITHOUT SELECT ANY CHARACTER
		if(playerkeys(player, 1, "jump")){
			gotomainmenu(3);
		}

		else

		//USED FOR "JUMP TO BRANCH"
		if(playerkeys(player, 1, "anybutton")){ //ANY BUTTON IS PRESSED??
			if(getglobalvar("levelName") != "route"){ //ANY VALID LEVEL IS SELECTED??
				// if(openborvariant("current_set") == 2 && getglobalvar("levelName") == "sor3_st7d"){ //AVOID BIKE STAGE IN REBELLION MODE
				if(getglobalvar("levelName") == "sor3_st7d"){ //AVOID BIKE STAGE IN REBELLION MODE
					playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					changeplayerproperty(0, "disablekeys", 0);
					changeplayerproperty(1, "disablekeys", 0);
					changeplayerproperty(2, "disablekeys", 0);
					changeplayerproperty(3, "disablekeys", 0);
					jumptobranch("sor3_st7e", 1);
					setglobalvar("levelSelected", 1);
					setglobalvar("activeText", 0);
				}else{ //JUMP TO DEFINED BRANCH
					playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					changeplayerproperty(0, "disablekeys", 0);
					changeplayerproperty(1, "disablekeys", 0);
					changeplayerproperty(2, "disablekeys", 0);
					changeplayerproperty(3, "disablekeys", 0);
					jumptobranch(getglobalvar("levelName"), 1);
					setglobalvar("levelSelected", 1);
					setglobalvar("activeText", 0);
				}
			}else{ //PLAY "INVALID" STAGE SOUND
				playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
			}
		}
	}
}
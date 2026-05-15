#include "data/scripts/keys.h"

void menuSelect(int player)
{//Change player preview model according to global variable "previewModel"+player check

	if(openborvariant("in_selectscreen")){ //LEVEL SELECT MENU STARTED
		if(getglobalvar("previewEntity"+player) != NULL()){
			void ani = getentityproperty(getglobalvar("previewEntity"+player), "animationID");

			//USED TO EXIT WITHOUT SELECT ANY CHARACTER
			if(playerkeys(player, 1, "jump")){gotomainmenu(11);}

			//THE CURRENT HIGHLIGHTED CHARACTER IS NOT CONFIRMED YET?? EXECUTE ALL TASKS BELOW
			if(ani != openborconstant("ANI_PICK")){
				float time	= openborvariant("elapsed_time"); //CURRENT TIME
				int column 	= getglobalvar("previewCol"+player); //DEFAULT COLUMN VALUE
				int line	= getglobalvar("previewLine"+player); //DEFAULT LINE VALUE
				int maxCols;
				int maxLines;
				int add		= 1;

				//ARCADE - SURVIVAL
				if(openborvariant("current_set") != 2){
					maxCols	 = 1;
					maxLines = 6;

					//USED FOR LEFT-RIGHT KEYS
					if(playerkeys(player, 1, "moveright")){ //SELECT DESIRED OPTION
						if(getglobalvar("heldStart"+player) != NULL()){playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);}
						if(column >= 0 && column < maxCols){setglobalvar("previewCol"+player, column+add);}
						if(column == maxCols){setglobalvar("previewCol"+player, 0);}
					}

					if(playerkeys(player, 1, "moveleft")){ //SELECT DESIRED OPTION
						if(getglobalvar("heldStart"+player) != NULL()){playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);}
						if(column > 0 && column <= maxCols){setglobalvar("previewCol"+player, column-add);}
						if(column == 0){setglobalvar("previewCol"+player, maxCols);}
					}

					//USED FOR UP-DOWN KEYS
					if(playerkeys(player, 1, "moveup")){ //SELECT DESIRED OPTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
						// if(getsaveinfo(0, "times_completed") <= 0){add = add*2;} //USED ONLY WHEN ADAM AND ZAN ARE LOCKED
						if(line > 0 && line <= maxLines){setglobalvar("previewLine"+player, line-add);}
						if(line == 0){setglobalvar("previewLine"+player, maxLines);}
					}

					if(playerkeys(player, 1, "movedown")){ //SELECT DESIRED OPTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
						// if(getsaveinfo(0, "times_completed") <= 0){add = add*2;} //USED ONLY WHEN ADAM AND ZAN ARE LOCKED
						if(line >= 0 && line < maxLines){setglobalvar("previewLine"+player, line+add);}
						if(line == maxLines){setglobalvar("previewLine"+player, 0);}
					}
				}

				//REBELLION
				if(openborvariant("current_set") == 2){
					maxCols	 = 9;
					maxLines = 3;

					//USED FOR LEFT-RIGHT KEYS
					if(playerkeys(player, 1, "moveright")){ //SELECT DESIRED OPTION
						if(getglobalvar("heldStart"+player) != NULL()){playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);}
						if(line == maxLines){maxCols = 8;} //REDUCE MAX COLUMNS IN THE LAST LINE
						if(column >= 0 && column < maxCols){setglobalvar("previewCol"+player, column+add);}
						if(column == maxCols){setglobalvar("previewCol"+player, 0);}
					}

					if(playerkeys(player, 1, "moveleft")){ //SELECT DESIRED OPTION
						if(getglobalvar("heldStart"+player) != NULL()){playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);}
						if(line == maxLines){maxCols = 8;} //REDUCE MAX COLUMNS IN THE LAST LINE
						if(column > 0 && column <= maxCols){setglobalvar("previewCol"+player, column-add);}
						if(column == 0){setglobalvar("previewCol"+player, maxCols);}
					}

					//USED FOR UP-DOWN KEYS
					if(playerkeys(player, 1, "moveup")){ //SELECT DESIRED OPTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
						if(column == maxCols){maxLines = 2;} //REDUCE MAX LINES IN THE LAST COLUMN
						if(line > 0 && line <= maxLines){setglobalvar("previewLine"+player, line-add);}
						if(line == 0){setglobalvar("previewLine"+player, maxLines);}
					}

					if(playerkeys(player, 1, "movedown")){ //SELECT DESIRED OPTION
						playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
						if(column == maxCols){maxLines = 2;} //REDUCE MAX LINES IN THE LAST COLUMN
						if(line >= 0 && line < maxLines){setglobalvar("previewLine"+player, line+add);}
						if(line == maxLines){setglobalvar("previewLine"+player, 0);}
					}
				}
				changeModel(player);
			}
		}
	}
}

void changeModel(int player)
{//Change model preview according to player changes

	if(getglobalvar("previewEntity"+player) != NULL()){
		void ani = getentityproperty(getglobalvar("previewEntity"+player), "animationID");

		if(ani != openborconstant("ANI_PICK")){ //THE CURRENT HIGHLIGHTED CHARACTER IS NOT CONFIRMED YET?? EXECUTE ALL TASKS BELOW

			//USED TO TRANSLATE MODELS - ARCADE/SURVIVAL
			if(openborvariant("current_set") != 2){
				if(getglobalvar("previewCol"+player) == 0){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Axel");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Adam");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Max");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Shiva_");}else
					if(getglobalvar("previewLine"+player) == 4){setglobalvar("previewModel"+player, "Electra_");}else
					if(getglobalvar("previewLine"+player) == 5){setglobalvar("previewModel"+player, "Kage");}else
					if(getglobalvar("previewLine"+player) == 6){setglobalvar("previewModel"+player, "Lee");}
				}else

				if(getglobalvar("previewCol"+player) == 1){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Blaze");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Zan");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Sammy");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Shiva");}else
					if(getglobalvar("previewLine"+player) == 4){setglobalvar("previewModel"+player, "Bison");}else
					if(getglobalvar("previewLine"+player) == 5){setglobalvar("previewModel"+player, "Chunli");}else
					if(getglobalvar("previewLine"+player) == 6){setglobalvar("previewModel"+player, "Lee");}
				}
			}

			//USED TO TRANSLATE MODELS - REBELLION
			if(openborvariant("current_set") == 2){
				if(getglobalvar("previewCol"+player) == 0){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Galsia");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Slum");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Roo");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Break");}
				}else

				if(getglobalvar("previewCol"+player) == 1){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Donovan");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Vice");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Barbon");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Yamato");}
				}else

				if(getglobalvar("previewCol"+player) == 2){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Signal");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Garnet");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Jet");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Robot_X");}
				}else

				if(getglobalvar("previewCol"+player) == 3){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Fog");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Macleod");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Zamza");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Jet_");}
				}else

				if(getglobalvar("previewCol"+player) == 4){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Hakuyo");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Tiger");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Abadede");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Shiva_");}
				}else

				if(getglobalvar("previewCol"+player) == 5){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Kusanagi");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "P-1");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "R._Bear");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Neo._X");}
				}else

				if(getglobalvar("previewCol"+player) == 6){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Raven");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Bongo");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Particle");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Harakiri");}
				}else

				if(getglobalvar("previewCol"+player) == 7){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Big-Ben");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Electra");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Shiva");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Tracker");}
				}else

				if(getglobalvar("previewCol"+player) == 8){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Electra_");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Ash");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Mr._X");}else
					if(getglobalvar("previewLine"+player) == 3){setglobalvar("previewModel"+player, "Ringmaster");}
				}else

				if(getglobalvar("previewCol"+player) == 9){
					if(getglobalvar("previewLine"+player) == 0){setglobalvar("previewModel"+player, "Jack");}else
					if(getglobalvar("previewLine"+player) == 1){setglobalvar("previewModel"+player, "Bruce");}else
					if(getglobalvar("previewLine"+player) == 2){setglobalvar("previewModel"+player, "Monalisa");}
				}
			}

			//CHANGE CURRENT MODEL PREVIEW ACCORDING TO THE HIGHLIGHTED CHARACTER WHEN ANY DIRECTION IS PRESSED
			if(playerkeys(player, 1, "moveleft")
			|| playerkeys(player, 1, "moveright")
			|| playerkeys(player, 1, "moveup")
		  || playerkeys(player, 1, "movedown")){

				changeentityproperty(getglobalvar("previewEntity"+player), "model", getglobalvar("previewModel"+player), 1);
				changeentityproperty(getglobalvar("previewEntity"+player), "animation", openborconstant("ANI_SELECT"));
			}
		}
	}
}
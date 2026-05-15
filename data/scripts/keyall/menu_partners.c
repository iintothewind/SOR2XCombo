#import "data/scripts/keyall/main_savecfg.c"
#include "data/scripts/assets.h"

void menuPartners(int player)
{//Adjust CPU partner mode and aggression

//HIGHLIGHT OPTIONS:
//1 - PARTNER MODE				(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//2 - PARTNER AGGRESSION		(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//3 - PARTNER VERSUS DAMAGE		(UPDATED.C, MAIN.C, KEY.C, ONDRAW.C, THINK.C)
//4 - PARTNER GET FOOD			(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//5 - PARTNER FOLLOW			(UPDATED.C, MAIN.C, KEY.C, THINK.C)
//6 - PARTNER RESPAWN			(UPDATED.C, MAIN.C, KEY.C, ONDEATH.C)
//7 - PARTNER SPAWN/KILL		(UPDATED.C, MAIN.C, KEY.C, LEVEL.C, ENDLEVEL.C, ONSPAWN.C, ONDEATH.C, ONDRAW.C, THINK.C)

	void self	  = getplayerproperty(player, "entity");
	int highlight = getglobalvar("highlight");
	int hasplayed = getplayerproperty(player, "hasplayed");
	int lives 	  = getplayerproperty(player, "lives");
	int dir 	  = getentityproperty(self, "direction");
	int max		  = 6;
	int min		  = 0;
	int add		  = 1;
	float x 	  = getentityproperty(self, "x");
	float y		  = getentityproperty(self, "y");
	float z		  = getentityproperty(self, "z");

	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
		if(getglobalvar("subMenu") == "partners"){

			//PARTNER IS NOT ALIVE?? OR PARTNER IS ALREADY ALIVE??
			if(getglobalvar("partnerAlive") == 0){setglobalvar("partnerSpawn", "spawn");}else //CHANGE OPTION FROM KILL TO SPAWN
			if(getglobalvar("partnerAlive") == 1){setglobalvar("partnerSpawn", "kill");}//CHANGE OPTION FROM SPAWN TO KILL

			//HIGHLIGHT OPTIONS WHEN MOVE DOWN
			if(playerkeys(player, 1, "movedown")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//BLOCK SPAWN OPTION IF IN SURVIVAL MODE OR NOT IN ANY LEVEL
				if(openborvariant("current_set") == 1 || openborvariant("in_level") != 1){
					if(highlight >= min && highlight < max-add){setglobalvar("highlight", highlight+1);}
					if(highlight == max-add){setglobalvar("highlight", min);}
				}else{
					if(highlight >= min && highlight < max){setglobalvar("highlight", highlight+1);}
					if(highlight == max){setglobalvar("highlight", min);}
				}
			}

			//HIGHLIGHT OPTIONS WHEN MOVE UP
			if(playerkeys(player, 1, "moveup")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//BLOCK SPAWN OPTION IF IN SURVIVAL MODE OR NOT IN ANY LEVEL
				if(openborvariant("current_set") == 1 || openborvariant("in_level") != 1){
					if(highlight > min && highlight <= max-add){setglobalvar("highlight", highlight-1);}
					if(highlight == min){setglobalvar("highlight", max-add);}
				}else{
					if(highlight > min && highlight <= max){setglobalvar("highlight", highlight-1);}
					if(highlight == min){setglobalvar("highlight", max);}
				}
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE RIGHT
			if(playerkeys(player, 1, "moveright")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS PARTNER MODE HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("partnerMode") == "balanced"){setglobalvar("partnerMode", "aggressive");}else
					if(getglobalvar("partnerMode") == "aggressive"){setglobalvar("partnerMode", "defensive");}else
					if(getglobalvar("partnerMode") == "defensive"){setglobalvar("partnerMode", "balanced");}
				}

				//IS PARTNER AGGRESSION HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("partnerAggression") == "*"){setglobalvar("partnerAggression", "**");}else
					if(getglobalvar("partnerAggression") == "**"){setglobalvar("partnerAggression", "***");}else
					if(getglobalvar("partnerAggression") == "***"){setglobalvar("partnerAggression", "****");}else
					if(getglobalvar("partnerAggression") == "****"){setglobalvar("partnerAggression", "*****");}else
					if(getglobalvar("partnerAggression") == "*****"){setglobalvar("partnerAggression", "******");}else
					if(getglobalvar("partnerAggression") == "******"){setglobalvar("partnerAggression", "*******");}else
					if(getglobalvar("partnerAggression") == "*******"){setglobalvar("partnerAggression", "********");}else
					if(getglobalvar("partnerAggression") == "********"){setglobalvar("partnerAggression", "*********");}else
					if(getglobalvar("partnerAggression") == "*********"){setglobalvar("partnerAggression", "*");}
				}

				//IS PARTNER GET FOOD HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("partnerGetFood") == "never"){setglobalvar("partnerGetFood", "75%_life");}else
					if(getglobalvar("partnerGetFood") == "75%_life"){setglobalvar("partnerGetFood", "50%_life");}else
					if(getglobalvar("partnerGetFood") == "50%_life"){setglobalvar("partnerGetFood", "25%_life");}else
					if(getglobalvar("partnerGetFood") == "25%_life"){setglobalvar("partnerGetFood", "never");}
				}

				//IS PARTNER FOLLOW HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("partnerFollow") == "automatic"){setglobalvar("partnerFollow", "manual");}else
					if(getglobalvar("partnerFollow") == "manual"){setglobalvar("partnerFollow", "automatic");}
				}

				//IS PARTNER RESPAWN HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("partnerRespawn") == "automatic"){setglobalvar("partnerRespawn", "manual");}else
					if(getglobalvar("partnerRespawn") == "manual"){setglobalvar("partnerRespawn", "automatic");}
				}

				//IS PARTNER NAME HIGHLIGHTED??
				if(getglobalvar("highlight") == 6 && getglobalvar("partnerSpawn") != "kill"){
					if(getglobalvar("selectPartner") == "Axel_"){setglobalvar("selectPartner", "Blaze_");}else
					if(getglobalvar("selectPartner") == "Blaze_"){setglobalvar("selectPartner", "Max_");}else
					if(getglobalvar("selectPartner") == "Max_"){setglobalvar("selectPartner", "Sammy_");}else
					if(getglobalvar("selectPartner") == "Sammy_"){
						// if(getsaveinfo(0, "times_completed") >= 1){ //CHECK IF ADAM IS UNLOCKED
							setglobalvar("selectPartner", "Adam_");
						// }else{
						// 	setglobalvar("selectPartner", "Axel_");
						// }
					}
					else
					if(getglobalvar("selectPartner") == "Adam_"){setglobalvar("selectPartner", "Zan_");}else
					if(getglobalvar("selectPartner") == "Zan_"){setglobalvar("selectPartner", "SOR2_Shiva");}else
					if(getglobalvar("selectPartner") == "SOR2_Shiva"){setglobalvar("selectPartner", "SOR3_Shiva");}else
					if(getglobalvar("selectPartner") == "SOR3_Shiva"){setglobalvar("selectPartner", "SOR2_Electra");}else
					if(getglobalvar("selectPartner") == "SOR2_Electra"){setglobalvar("selectPartner", "Bison_");}else
					if(getglobalvar("selectPartner") == "Bison_"){setglobalvar("selectPartner", "Chunli_");}else
					if(getglobalvar("selectPartner") == "Chunli_"){setglobalvar("selectPartner", "Kage_");}else
					if(getglobalvar("selectPartner") == "Kage_"){setglobalvar("selectPartner", "Yamato_");}else
					if(getglobalvar("selectPartner") == "Yamato_"){setglobalvar("selectPartner", "Axel_");}
				}
				saveCfg();
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
			if(playerkeys(player, 1, "moveleft")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS PARTNER MODE HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("partnerMode") == "balanced"){setglobalvar("partnerMode", "defensive");}else
					if(getglobalvar("partnerMode") == "defensive"){setglobalvar("partnerMode", "aggressive");}else
					if(getglobalvar("partnerMode") == "aggressive"){setglobalvar("partnerMode", "balanced");}
				}

				//IS PARTNER AGGRESSION HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("partnerAggression") == "*"){setglobalvar("partnerAggression", "*********");}else
					if(getglobalvar("partnerAggression") == "*********"){setglobalvar("partnerAggression", "********");}else
					if(getglobalvar("partnerAggression") == "********"){setglobalvar("partnerAggression", "*******");}else
					if(getglobalvar("partnerAggression") == "*******"){setglobalvar("partnerAggression", "******");}else
					if(getglobalvar("partnerAggression") == "******"){setglobalvar("partnerAggression", "*****");}else
					if(getglobalvar("partnerAggression") == "*****"){setglobalvar("partnerAggression", "****");}else
					if(getglobalvar("partnerAggression") == "****"){setglobalvar("partnerAggression", "***");}else
					if(getglobalvar("partnerAggression") == "***"){setglobalvar("partnerAggression", "**");}else
					if(getglobalvar("partnerAggression") == "**"){setglobalvar("partnerAggression", "*");}
				}

				//IS PARTNER GET FOOD HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("partnerGetFood") == "never"){setglobalvar("partnerGetFood", "25%_life");}else
					if(getglobalvar("partnerGetFood") == "25%_life"){setglobalvar("partnerGetFood", "50%_life");}else
					if(getglobalvar("partnerGetFood") == "50%_life"){setglobalvar("partnerGetFood", "75%_life");}else
					if(getglobalvar("partnerGetFood") == "75%_life"){setglobalvar("partnerGetFood", "never");}
				}

				//IS PARTNER FOLLOW HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("partnerFollow") == "automatic"){setglobalvar("partnerFollow", "manual");}else
					if(getglobalvar("partnerFollow") == "manual"){setglobalvar("partnerFollow", "automatic");}
				}

				//IS PARTNER RESPAWN HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("partnerRespawn") == "automatic"){setglobalvar("partnerRespawn", "manual");}else
					if(getglobalvar("partnerRespawn") == "manual"){setglobalvar("partnerRespawn", "automatic");}
				}

				//IS PARTNER NAME HIGHLIGHTED??
				if(getglobalvar("highlight") == 6 && getglobalvar("partnerSpawn") != "kill"){
					if(getglobalvar("selectPartner") == "Axel_"){
						// if(getsaveinfo(0, "times_completed") >= 1){ //CHECK IF ZAN IS UNLOCKED
							setglobalvar("selectPartner", "Yamato_");
						// }
						// else
						// {
						// 	setglobalvar("selectPartner", "Sammy_");
						// }
					}
					else
					if(getglobalvar("selectPartner") == "Yamato_"){setglobalvar("selectPartner", "Kage_");}else
					if(getglobalvar("selectPartner") == "Kage_"){setglobalvar("selectPartner", "Chunli_");}else
					if(getglobalvar("selectPartner") == "Chunli_"){setglobalvar("selectPartner", "Bison_");}else
					if(getglobalvar("selectPartner") == "Bison_"){setglobalvar("selectPartner", "SOR2_Electra");}else
					if(getglobalvar("selectPartner") == "SOR2_Electra"){setglobalvar("selectPartner", "SOR3_Shiva");}else
					if(getglobalvar("selectPartner") == "SOR3_Shiva"){setglobalvar("selectPartner", "SOR2_Shiva");}else
					if(getglobalvar("selectPartner") == "SOR2_Shiva"){setglobalvar("selectPartner", "Zan_");}else
					if(getglobalvar("selectPartner") == "Zan_"){setglobalvar("selectPartner", "Adam_");}else
					if(getglobalvar("selectPartner") == "Adam_"){setglobalvar("selectPartner", "Sammy_");}else
					if(getglobalvar("selectPartner") == "Sammy_"){setglobalvar("selectPartner", "Max_");}else
					if(getglobalvar("selectPartner") == "Max_"){setglobalvar("selectPartner", "Blaze_");}else
					if(getglobalvar("selectPartner") == "Blaze_"){setglobalvar("selectPartner", "Axel_");}
				}
				saveCfg();
			}

			//CHANGE CPU PARTNER IN-GAME
			if(playerkeys(player, 1, "attack")){ //SELECT DESIRED OPTION
				if(getglobalvar("partnerAlive") == 0){
					if(getglobalvar("highlight") == max){ //IS PARTNER SPAWN/KILL HIGHLIGHTED??
						if(lives >= 2){
							void vSpawn;

							if(getglobalvar("partnerMp") == NULL()){
								// if(getglobalvar("fullEnergy") == "never"){setglobalvar("partnerMp", 0);}
								// if(getglobalvar("fullEnergy") == "each_new_stage"){setglobalvar("partnerMp", 120);}
								setglobalvar("partnerMp", 120);
							}

							loadmodel(getglobalvar("selectPartner"), 1);
							changeplayerproperty(player, "lives", lives-1);
							playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
							clearspawnentry(); //CLEAR CURRENT SPAWN ENTRY
							setspawnentry("name", getglobalvar("selectPartner")); //ACQUIRE SPAWN ENTITY BY NAME
							vSpawn = spawn(); //SPAWN IN ENTITY
							changeentityproperty(vSpawn, "position", x, z, y+300); //SET SPAWN POSITION
							changeentityproperty(vSpawn, "direction", dir); //SET SPAWN DIRECTION
							changeentityproperty(vSpawn, "mp", getglobalvar("partnerMp"));  //SET SPAWN MP
							setglobalvar("currentPartner", vSpawn); //SET AS CURRENT SPAWNED PARTNER
							setglobalvar("partnerIndex", player); //SAVE CALLER'S PLAYER INDEX
							setglobalvar("partnerSpawn", "kill"); //CHANGE OPTION FROM SPAWN TO KILL
							setglobalvar("highlight", 0); //CHANGE HIGHLIGHT OPTION TO ZERO

							return vSpawn; //RETURN SPAWN
						}else{
							playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
							setglobalvar("blockedPartner", openborvariant("elapsed_time"));
						}
					}
				}
				else
				if(getglobalvar("partnerAlive") == 1){ //NPC PARTNER IS ALIVE??
					if(player == getglobalvar("partnerIndex")){ //ONLY THE CALLER CAN KILL YOUR PARTNER
						if(getglobalvar("highlight") == max){ //IS PARTNER SPAWN/KILL HIGHLIGHTED??
							float screenSpeed = 0.5;

							playsample(openborconstant("SAMPLE_GO"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
							killentity(getglobalvar("currentPartner")); //KILL CURRENT ALIVE PARTNER
							changelevelproperty("scrollspeed", screenSpeed); //RESET THE CURRENT SCROLLING SPEED, FOR SAFE
							setglobalvar("partnerAlive", 0);
							setglobalvar("partnerParrow", NULL());
							setglobalvar("partnerSpawn", "spawn"); //CHANGE OPTION FROM KILL TO SPAWN
							setglobalvar("highlight", 0); //CHANGE HIGHLIGHT OPTION TO ZERO
						}
					}else{
						playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
					}
				}
				saveCfg();
			}
		}
	}

	//CHANGE CPU PARTNER IN SELECT SCREEN
	if(playerkeys(player, 1, "screenshot")){ //SELECT BUTTON IS PRESSED??
		if(openborvariant("in_selectscreen") && hasplayed == 1){ //IN SELECT SCREEN??
			if(openborvariant("current_set") == 0){ //ARCADE MODE ONLY FOR NOW
				if(getglobalvar("partnerIndex") == NULL() && getglobalvar("lives") > 1){ //PLAYER (PARTNER CALLER'S) INDEX VARIABLE IS NULL??
					playsample(openborconstant("SAMPLE_GO"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
					setglobalvar("partnerIndex", player); //SAVE CALLER'S PLAYER INDEX
				}
				else
				if(getglobalvar("partnerIndex") == player && getglobalvar("currentPartner") == NULL()){ //PARTNER IS HIGHLIGHTED BUT NOT CONFIRMED YET??
					if(getglobalvar("selectPartner") == "Axel_"
					|| getglobalvar("selectPartner") == "Blaze_"
					|| getglobalvar("selectPartner") == "Max_"
					|| getglobalvar("selectPartner") == "Sammy_"
					|| getglobalvar("selectPartner") == "Adam_"
					|| getglobalvar("selectPartner") == "Zan_"
					|| getglobalvar("selectPartner") == "SOR2_Shiva"
					|| getglobalvar("selectPartner") == "SOR3_Shiva"
					|| getglobalvar("selectPartner") == "SOR2_Electra"
					|| getglobalvar("selectPartner") == "Bison_"
					|| getglobalvar("selectPartner") == "Chunli_"
					|| getglobalvar("selectPartner") == "Kage_"
					|| getglobalvar("selectPartner") == "Yamato_"){

						//CONFIRM AND SAVE THE SELECTED PARTNER TO BE SPAWNED AT THE GAME STARTS
						playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
						setglobalvar("blockedPartner", 0); //SET AS CURRENT BLOCKED PARTNER
						setglobalvar("partnerSpawn", "kill"); //CHANGE OPTION FROM SPAWN TO KILL
						setglobalvar("currentPartner", getglobalvar("selectPartner")); //SET AS CURRENT SPAWNED PARTNER
						setglobalvar("partnerName", getglobalvar("selectPartner"));
						setglobalvar("partnerAlive", 1);
						setglobalvar("partnerFull", 1);

						if(getglobalvar("fullEnergy") == "never"){setglobalvar("partnerMp", 0);}

					}else{ //CURRENT HIGHLIGHTED PARTNER IS NOT ALLOWED TO BE SELECTED??
						playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
						setglobalvar("blockedPartner", 1); //CONFIRM THAT THE HIGHLIGHTED PARTNER IS BLOCKED AND SAVE IT
					}
				}
			}
		}
		saveCfg();
	}

	//PARTNER CALL BUTTON AND CUSTOM PARROW USED IN ONDRAW.C AND THINK.C
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	if(getglobalvar("activeText") == 0 && getglobalvar("extraButton") == "call_partner"){ //USED TO MAKE THE SCRIPT WORKS WITH ANY PLAYER IN THE SCREEN AND WITH NO MENUS
		if(playerkeys(player, 1, "attack4") && getglobalvar("partnerAlive") == 1){

			//USED TO CHANGE THE PARTNER INDEX IF THE CALLER IS DEAD
			if(getglobalvar("partnerIndex") == 0 && player1 == NULL()){
				if(player2 != NULL()){setglobalvar("partnerIndex", 1);}else
				if(player3 != NULL()){setglobalvar("partnerIndex", 2);}else
				if(player4 != NULL()){setglobalvar("partnerIndex", 3);}
			}
			if(getglobalvar("partnerIndex") == 1 && player2 == NULL()){
				if(player3 != NULL()){setglobalvar("partnerIndex", 2);}else
				if(player4 != NULL()){setglobalvar("partnerIndex", 3);}else
				if(player1 != NULL()){setglobalvar("partnerIndex", 0);}
			}
			if(getglobalvar("partnerIndex") == 2 && player3 == NULL()){
				if(player4 != NULL()){setglobalvar("partnerIndex", 3);}else
				if(player1 != NULL()){setglobalvar("partnerIndex", 0);}else
				if(player2 != NULL()){setglobalvar("partnerIndex", 1);}
			}
			if(getglobalvar("partnerIndex") == 3 && player4 == NULL()){
				if(player1 != NULL()){setglobalvar("partnerIndex", 0);}else
				if(player2 != NULL()){setglobalvar("partnerIndex", 1);}else
				if(player3 != NULL()){setglobalvar("partnerIndex", 2);}
			}

			//USED TO CALL PARTNER
			if(player == getglobalvar("partnerIndex")){
				if(getglobalvar("partnerParrow") != "call"){
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
					setglobalvar("partnerParrow", "call");
				}else{
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
					setglobalvar("partnerParrow", NULL());
				}
			}
		}
	}
}
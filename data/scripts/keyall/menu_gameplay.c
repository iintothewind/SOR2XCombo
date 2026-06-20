#import "data/scripts/keyall/main_savecfg.c"

void menuGameplay(int player)
{//Change Gameplay Menu variables if defined key is pressed

	int highlight = getglobalvar("highlight");
	int hasplayed = getplayerproperty(player, "hasplayed");
	int max		  = 17;
	int min		  = 0;
	int add		  = 1;

	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
		if(getglobalvar("subMenu") == "gameplay"){

			//HIGHLIGHT OPTIONS WHEN MOVE DOWN
			if(openborvariant("in_level")){
				setglobalvar("highlight", 0); //BLOCK GAMEPLAY MENU IF IN ANY LEVEL
			}else{
				if(playerkeys(player, 1, "movedown")){
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					if(highlight >= min && highlight < max){setglobalvar("highlight", highlight+add);}
					if(highlight == max){setglobalvar("highlight", min);}
				}
			}

			//HIGHLIGHT OPTIONS WHEN MOVE UP
			if(openborvariant("in_level")){
				setglobalvar("highlight", 0); //BLOCK GAMEPLAY MENU IF IN ANY LEVEL
			}else{
				if(playerkeys(player, 1, "moveup")){
					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					if(highlight > min && highlight <= max){setglobalvar("highlight", highlight-add);}
					if(highlight == min){setglobalvar("highlight", max);}
				}
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE RIGHT
			if(playerkeys(player, 1, "moveright")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS DIFFICULT HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("difficult") == "normal"){setglobalvar("difficult", "hard");}else
					if(getglobalvar("difficult") == "hard"){setglobalvar("difficult", "mania");}else
					if(getglobalvar("difficult") == "mania"){setglobalvar("difficult", "normal");}
					applyDifficultyPreset();
				}

				//IS SCROLL SPEED HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("enemyLifeRate") == "25%"){setglobalvar("enemyLifeRate", "50%");}else
					if(getglobalvar("enemyLifeRate") == "50%"){setglobalvar("enemyLifeRate", "75%");}else
					if(getglobalvar("enemyLifeRate") == "75%"){setglobalvar("enemyLifeRate", "100%");}else
					if(getglobalvar("enemyLifeRate") == "100%"){setglobalvar("enemyLifeRate", "125%");}else
					if(getglobalvar("enemyLifeRate") == "125%"){setglobalvar("enemyLifeRate", "150%");}else
					if(getglobalvar("enemyLifeRate") == "150%"){setglobalvar("enemyLifeRate", "175%");}else
					if(getglobalvar("enemyLifeRate") == "175%"){setglobalvar("enemyLifeRate", "200%");}else
					if(getglobalvar("enemyLifeRate") == "200%"){setglobalvar("enemyLifeRate", "25%");}
				}

				//IS LIVES HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("lives") < 9){setglobalvar("lives", getglobalvar("lives")+1);}else
					if(getglobalvar("lives") >= 9){setglobalvar("lives", getglobalvar("lives")-8);}
				}

				//IS RAGE SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("lastChance") == "off"){setglobalvar("lastChance", "10%");}else
					if(getglobalvar("lastChance") == "10%"){setglobalvar("lastChance", "20%");}else
					if(getglobalvar("lastChance") == "20%"){setglobalvar("lastChance", "25%");}else
					if(getglobalvar("lastChance") == "25%"){setglobalvar("lastChance", "33%");}else
					if(getglobalvar("lastChance") == "33%"){setglobalvar("lastChance", "off");}
				}

				//IS COUNTER SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("counterAttackReward") == "off"){setglobalvar("counterAttackReward", "25%");}else
					if(getglobalvar("counterAttackReward") == "25%"){setglobalvar("counterAttackReward", "50%");}else
					if(getglobalvar("counterAttackReward") == "50%"){setglobalvar("counterAttackReward", "75%");}else
					if(getglobalvar("counterAttackReward") == "75%"){setglobalvar("counterAttackReward", "100%");}else
					if(getglobalvar("counterAttackReward") == "100%"){setglobalvar("counterAttackReward", "125%");}else
					if(getglobalvar("counterAttackReward") == "125%"){setglobalvar("counterAttackReward", "150%");}else
					if(getglobalvar("counterAttackReward") == "150%"){setglobalvar("counterAttackReward", "175%");}else
					if(getglobalvar("counterAttackReward") == "175%"){setglobalvar("counterAttackReward", "200%");}else
					if(getglobalvar("counterAttackReward") == "200%"){setglobalvar("counterAttackReward", "off");}
				}

				//IS RUSH_HEAT SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("rushHeat") == "off"){setglobalvar("rushHeat", "5");}else
					if(getglobalvar("rushHeat") == "5"){setglobalvar("rushHeat", "7");}else
					if(getglobalvar("rushHeat") == "7"){setglobalvar("rushHeat", "9");}else
					if(getglobalvar("rushHeat") == "9"){setglobalvar("rushHeat", "11");}else
					if(getglobalvar("rushHeat") == "11"){setglobalvar("rushHeat", "13");}else
					if(getglobalvar("rushHeat") == "13"){setglobalvar("rushHeat", "15");}else
					if(getglobalvar("rushHeat") == "15"){setglobalvar("rushHeat", "off");}
				}

				//IS JUGGLES SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("juggleSystem") == "off"){setglobalvar("juggleSystem", "20");}else
					if(getglobalvar("juggleSystem") == "20"){setglobalvar("juggleSystem", "30");}else
					if(getglobalvar("juggleSystem") == "30"){setglobalvar("juggleSystem", "40");}else
					if(getglobalvar("juggleSystem") == "40"){setglobalvar("juggleSystem", "50");}else
					if(getglobalvar("juggleSystem") == "50"){setglobalvar("juggleSystem", "60");}else
					if(getglobalvar("juggleSystem") == "60"){setglobalvar("juggleSystem", "80");}else
					if(getglobalvar("juggleSystem") == "80"){setglobalvar("juggleSystem", "100");}else
					if(getglobalvar("juggleSystem") == "100"){setglobalvar("juggleSystem", "unlimited");}else
					if(getglobalvar("juggleSystem") == "unlimited"){setglobalvar("juggleSystem", "off");}
				}

				//IS OTG SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 8){
					if(getglobalvar("otgSystem") == "off"){setglobalvar("otgSystem", "2");}else
					if(getglobalvar("otgSystem") == "2"){setglobalvar("otgSystem", "4");}else
					if(getglobalvar("otgSystem") == "4"){setglobalvar("otgSystem", "6");}else
					if(getglobalvar("otgSystem") == "6"){setglobalvar("otgSystem", "8");}else
					if(getglobalvar("otgSystem") == "8"){setglobalvar("otgSystem", "10");}else
					if(getglobalvar("otgSystem") == "10"){setglobalvar("otgSystem", "15");}else
					if(getglobalvar("otgSystem") == "15"){setglobalvar("otgSystem", "20");}else
					if(getglobalvar("otgSystem") == "20"){setglobalvar("otgSystem", "unlimited");}else
					if(getglobalvar("otgSystem") == "unlimited"){setglobalvar("otgSystem", "off");}
				}

				//IS CANCELING SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 9){
					if(getglobalvar("enemyRushLimit") == "2"){setglobalvar("enemyRushLimit", "4");}else
					if(getglobalvar("enemyRushLimit") == "4"){setglobalvar("enemyRushLimit", "6");}else
					if(getglobalvar("enemyRushLimit") == "6"){setglobalvar("enemyRushLimit", "8");}else
					if(getglobalvar("enemyRushLimit") == "8"){setglobalvar("enemyRushLimit", "10");}else
					if(getglobalvar("enemyRushLimit") == "10"){setglobalvar("enemyRushLimit", "20");}else
					if(getglobalvar("enemyRushLimit") == "20"){setglobalvar("enemyRushLimit", "30");}else
					if(getglobalvar("enemyRushLimit") == "30"){setglobalvar("enemyRushLimit", "50");}else
					if(getglobalvar("enemyRushLimit") == "50"){setglobalvar("enemyRushLimit", "unlimited");}else
					if(getglobalvar("enemyRushLimit") == "unlimited"){setglobalvar("enemyRushLimit", "2");}
				}

				//IS SUPER ARMOR HIGHLIGHTED??
				if(getglobalvar("highlight") == 10){
					if(getglobalvar("randomBoss") == 0){setglobalvar("randomBoss", 1);}else
					if(getglobalvar("randomBoss") == 1){setglobalvar("randomBoss", 2);}else
					if(getglobalvar("randomBoss") == 2){setglobalvar("randomBoss", 3);}else
					if(getglobalvar("randomBoss") == 3){setglobalvar("randomBoss", 0);}
				}

				//IS SPECIAL COST HIGHLIGHTED??
				if(getglobalvar("highlight") == 11){
					if(getglobalvar("lockMp") == "on"){setglobalvar("lockMp", "off");}else
					if(getglobalvar("lockMp") == "off"){setglobalvar("lockMp", "on");}
				}

				//IS FULL ENERGY HIGHLIGHTED??
				if(getglobalvar("highlight") == 12){
					if(getglobalvar("energyRegenerate") == "never"){setglobalvar("energyRegenerate", "5");}else
					if(getglobalvar("energyRegenerate") == "5"){setglobalvar("energyRegenerate", "10");}else
					if(getglobalvar("energyRegenerate") == "10"){setglobalvar("energyRegenerate", "15");}else
					if(getglobalvar("energyRegenerate") == "15"){setglobalvar("energyRegenerate", "20");}else
					if(getglobalvar("energyRegenerate") == "20"){setglobalvar("energyRegenerate", "25");}else
					if(getglobalvar("energyRegenerate") == "25"){setglobalvar("energyRegenerate", "50");}else
					if(getglobalvar("energyRegenerate") == "50"){setglobalvar("energyRegenerate", "never");}
				}

				//IS WALLS HIGHLIGHTED??
				if(getglobalvar("highlight") == 13){
					if(getglobalvar("walls") == "all_types"){setglobalvar("walls", "bouncing_only");}else
					if(getglobalvar("walls") == "bouncing_only"){setglobalvar("walls", "jumping_only");}else
					if(getglobalvar("walls") == "jumping_only"){setglobalvar("walls", "none");}else
					if(getglobalvar("walls") == "none"){setglobalvar("walls", "all_types");}
				}

				//IS SCREEN EDGE HIGHLIGHTED??
				if(getglobalvar("highlight") == 14){
					if(getglobalvar("screenEdge") == "all_types"){setglobalvar("screenEdge", "lock+bouncing");}else
					if(getglobalvar("screenEdge") == "lock+bouncing"){setglobalvar("screenEdge", "lock_only");}else
					if(getglobalvar("screenEdge") == "lock_only"){setglobalvar("screenEdge", "jumping_only");}else
					if(getglobalvar("screenEdge") == "jumping_only"){setglobalvar("screenEdge", "none");}else
					if(getglobalvar("screenEdge") == "none"){setglobalvar("screenEdge", "all_types");}
				}

				//IS ITEM DROP HIGHLIGHTED??
				if(getglobalvar("highlight") == 15){
					if(getglobalvar("itemDrop") == "mixed"){setglobalvar("itemDrop", "food_only");}else
					if(getglobalvar("itemDrop") == "food_only"){setglobalvar("itemDrop", "money_only");}else
					if(getglobalvar("itemDrop") == "money_only"){setglobalvar("itemDrop", "weapon_only");}else
					if(getglobalvar("itemDrop") == "weapon_only"){setglobalvar("itemDrop", "food+money");}else
					if(getglobalvar("itemDrop") == "food+money"){setglobalvar("itemDrop", "food+weapon");}else
					if(getglobalvar("itemDrop") == "food+weapon"){setglobalvar("itemDrop", "money+weapon");}else
					if(getglobalvar("itemDrop") == "money+weapon"){setglobalvar("itemDrop", "none");}else
					if(getglobalvar("itemDrop") == "none"){setglobalvar("itemDrop", "mixed");}
				}

				//IS QUICK RESPAWN HIGHLIGHTED??
				if(getglobalvar("highlight") == 16){
					if(getglobalvar("smarterEnemy") == "on"){setglobalvar("smarterEnemy", "off");}else
					if(getglobalvar("smarterEnemy") == "off"){setglobalvar("smarterEnemy", "on");}
				}

				//IS ENEMY GET FOOD HIGHLIGHTED??
				if(getglobalvar("highlight") == 17){
					if(getglobalvar("blockCost") == "off"){setglobalvar("blockCost", "1");}else
					if(getglobalvar("blockCost") == "1"){setglobalvar("blockCost", "2");}else
					if(getglobalvar("blockCost") == "2"){setglobalvar("blockCost", "off");}
				}
				saveCfg();
			}

			//CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
			if(playerkeys(player, 1, "moveleft")){
				playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

				//IS DIFFICULT HIGHLIGHTED??
				if(getglobalvar("highlight") == 1){
					if(getglobalvar("difficult") == "normal"){setglobalvar("difficult", "mania");}else
					if(getglobalvar("difficult") == "mania"){setglobalvar("difficult", "hard");}else
					if(getglobalvar("difficult") == "hard"){setglobalvar("difficult", "normal");}
					applyDifficultyPreset();
				}

				//IS SCROLL SPEED HIGHLIGHTED??
				if(getglobalvar("highlight") == 2){
					if(getglobalvar("enemyLifeRate") == "200%"){setglobalvar("enemyLifeRate", "175%");}else
					if(getglobalvar("enemyLifeRate") == "175%"){setglobalvar("enemyLifeRate", "150%");}else
					if(getglobalvar("enemyLifeRate") == "150%"){setglobalvar("enemyLifeRate", "125%");}else
					if(getglobalvar("enemyLifeRate") == "125%"){setglobalvar("enemyLifeRate", "100%");}else
					if(getglobalvar("enemyLifeRate") == "100%"){setglobalvar("enemyLifeRate", "75%");}else
					if(getglobalvar("enemyLifeRate") == "75%"){setglobalvar("enemyLifeRate", "50%");}else
					if(getglobalvar("enemyLifeRate") == "50%"){setglobalvar("enemyLifeRate", "25%");}else
					if(getglobalvar("enemyLifeRate") == "25%"){setglobalvar("enemyLifeRate", "200%");}
				}

				//IS LIVES HIGHLIGHTED??
				if(getglobalvar("highlight") == 3){
					if(getglobalvar("lives") > 1){setglobalvar("lives", getglobalvar("lives")-1);}else
					if(getglobalvar("lives") <= 1){setglobalvar("lives", getglobalvar("lives")+8);}
				}

				//IS RAGE SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 4){
					if(getglobalvar("lastChance") == "33%"){setglobalvar("lastChance", "25%");}else
					if(getglobalvar("lastChance") == "25%"){setglobalvar("lastChance", "20%");}else
					if(getglobalvar("lastChance") == "20%"){setglobalvar("lastChance", "10%");}else
					if(getglobalvar("lastChance") == "10%"){setglobalvar("lastChance", "off");}else
					if(getglobalvar("lastChance") == "off"){setglobalvar("lastChance", "33%");}
				}

				//IS COUNTER SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 5){
					if(getglobalvar("counterAttackReward") == "200%"){setglobalvar("counterAttackReward", "175%");}else
					if(getglobalvar("counterAttackReward") == "175%"){setglobalvar("counterAttackReward", "150%");}else
					if(getglobalvar("counterAttackReward") == "150%"){setglobalvar("counterAttackReward", "125%");}else
					if(getglobalvar("counterAttackReward") == "125%"){setglobalvar("counterAttackReward", "100%");}else
					if(getglobalvar("counterAttackReward") == "100%"){setglobalvar("counterAttackReward", "75%");}else
					if(getglobalvar("counterAttackReward") == "75%"){setglobalvar("counterAttackReward", "50%");}else
					if(getglobalvar("counterAttackReward") == "50%"){setglobalvar("counterAttackReward", "25%");}else
					if(getglobalvar("counterAttackReward") == "25%"){setglobalvar("counterAttackReward", "off");}else
					if(getglobalvar("counterAttackReward") == "off"){setglobalvar("counterAttackReward", "200%");}
				}

				//IS RUSH_HEAT SKILL HIGHLIGHTED??
				if(getglobalvar("highlight") == 6){
					if(getglobalvar("rushHeat") == "off"){setglobalvar("rushHeat", "15");}else
					if(getglobalvar("rushHeat") == "15"){setglobalvar("rushHeat", "13");}else
					if(getglobalvar("rushHeat") == "13"){setglobalvar("rushHeat", "11");}else
					if(getglobalvar("rushHeat") == "11"){setglobalvar("rushHeat", "9");}else
					if(getglobalvar("rushHeat") == "9"){setglobalvar("rushHeat", "7");}else
					if(getglobalvar("rushHeat") == "7"){setglobalvar("rushHeat", "5");}else
					if(getglobalvar("rushHeat") == "5"){setglobalvar("rushHeat", "off");}
				}

				//IS JUGGLES SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 7){
					if(getglobalvar("juggleSystem") == "unlimited"){setglobalvar("juggleSystem", "100");}else
					if(getglobalvar("juggleSystem") == "100"){setglobalvar("juggleSystem", "80");}else
					if(getglobalvar("juggleSystem") == "80"){setglobalvar("juggleSystem", "60");}else
					if(getglobalvar("juggleSystem") == "60"){setglobalvar("juggleSystem", "50");}else
					if(getglobalvar("juggleSystem") == "50"){setglobalvar("juggleSystem", "40");}else
					if(getglobalvar("juggleSystem") == "40"){setglobalvar("juggleSystem", "30");}else
					if(getglobalvar("juggleSystem") == "30"){setglobalvar("juggleSystem", "20");}else
					if(getglobalvar("juggleSystem") == "20"){setglobalvar("juggleSystem", "off");}else
					if(getglobalvar("juggleSystem") == "off"){setglobalvar("juggleSystem", "unlimited");}
				}

				//IS OTG SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 8){
					if(getglobalvar("otgSystem") == "unlimited"){setglobalvar("otgSystem", "20");}else
					if(getglobalvar("otgSystem") == "20"){setglobalvar("otgSystem", "15");}else
					if(getglobalvar("otgSystem") == "15"){setglobalvar("otgSystem", "10");}else
					if(getglobalvar("otgSystem") == "10"){setglobalvar("otgSystem", "8");}else
					if(getglobalvar("otgSystem") == "8"){setglobalvar("otgSystem", "6");}else
					if(getglobalvar("otgSystem") == "6"){setglobalvar("otgSystem", "4");}else
					if(getglobalvar("otgSystem") == "4"){setglobalvar("otgSystem", "2");}else
					if(getglobalvar("otgSystem") == "2"){setglobalvar("otgSystem", "off");}else
					if(getglobalvar("otgSystem") == "off"){setglobalvar("otgSystem", "unlimited");}
				}

				//IS CANCELING SYSTEM HIGHLIGHTED??
				if(getglobalvar("highlight") == 9){
					if(getglobalvar("enemyRushLimit") == "unlimited"){setglobalvar("enemyRushLimit", "50");}else
					if(getglobalvar("enemyRushLimit") == "50"){setglobalvar("enemyRushLimit", "30");}else
					if(getglobalvar("enemyRushLimit") == "30"){setglobalvar("enemyRushLimit", "20");}else
					if(getglobalvar("enemyRushLimit") == "20"){setglobalvar("enemyRushLimit", "10");}else
					if(getglobalvar("enemyRushLimit") == "10"){setglobalvar("enemyRushLimit", "8");}else
					if(getglobalvar("enemyRushLimit") == "8"){setglobalvar("enemyRushLimit", "6");}else
					if(getglobalvar("enemyRushLimit") == "6"){setglobalvar("enemyRushLimit", "4");}else
					if(getglobalvar("enemyRushLimit") == "4"){setglobalvar("enemyRushLimit", "2");}else
					if(getglobalvar("enemyRushLimit") == "2"){setglobalvar("enemyRushLimit", "unlimited");}
				}

				//IS SUPER ARMOR HIGHLIGHTED??
				if(getglobalvar("highlight") == 10){
					if(getglobalvar("randomBoss") == 0){setglobalvar("randomBoss", 3);}else
					if(getglobalvar("randomBoss") == 3){setglobalvar("randomBoss", 2);}else
					if(getglobalvar("randomBoss") == 2){setglobalvar("randomBoss", 1);}else
					if(getglobalvar("randomBoss") == 1){setglobalvar("randomBoss", 0);}
				}

				//IS SPECIAL COST HIGHLIGHTED??
				if(getglobalvar("highlight") == 11){
					if(getglobalvar("lockMp") == "on"){setglobalvar("lockMp", "off");}else
					if(getglobalvar("lockMp") == "off"){setglobalvar("lockMp", "on");}
				}

				//IS FULL ENERGY HIGHLIGHTED??
				if(getglobalvar("highlight") == 12){
					if(getglobalvar("energyRegenerate") == "never"){setglobalvar("energyRegenerate", "50");}else
					if(getglobalvar("energyRegenerate") == "50"){setglobalvar("energyRegenerate", "25");}else
					if(getglobalvar("energyRegenerate") == "25"){setglobalvar("energyRegenerate", "20");}else
					if(getglobalvar("energyRegenerate") == "20"){setglobalvar("energyRegenerate", "15");}else
					if(getglobalvar("energyRegenerate") == "15"){setglobalvar("energyRegenerate", "10");}else
					if(getglobalvar("energyRegenerate") == "10"){setglobalvar("energyRegenerate", "5");}else
					if(getglobalvar("energyRegenerate") == "5"){setglobalvar("energyRegenerate", "never");}
				}

				//IS WALLS HIGHLIGHTED??
				if(getglobalvar("highlight") == 13){
					if(getglobalvar("walls") == "all_types"){setglobalvar("walls", "none");}else
					if(getglobalvar("walls") == "none"){setglobalvar("walls", "jumping_only");}else
					if(getglobalvar("walls") == "jumping_only"){setglobalvar("walls", "bouncing_only");}else
					if(getglobalvar("walls") == "bouncing_only"){setglobalvar("walls", "all_types");}
				}

				//IS SCREEN EDGE HIGHLIGHTED??
				if(getglobalvar("highlight") == 14){
					if(getglobalvar("screenEdge") == "all_types"){setglobalvar("screenEdge", "none");}else
					if(getglobalvar("screenEdge") == "none"){setglobalvar("screenEdge", "jumping_only");}else
					if(getglobalvar("screenEdge") == "jumping_only"){setglobalvar("screenEdge", "lock_only");}else
					if(getglobalvar("screenEdge") == "lock_only"){setglobalvar("screenEdge", "lock+bouncing");}else
					if(getglobalvar("screenEdge") == "lock+bouncing"){setglobalvar("screenEdge", "all_types");}
				}

				//IS ITEM DROP HIGHLIGHTED??
				if(getglobalvar("highlight") == 15){
					if(getglobalvar("itemDrop") == "mixed"){setglobalvar("itemDrop", "none");}else
					if(getglobalvar("itemDrop") == "none"){setglobalvar("itemDrop", "money+weapon");}else
					if(getglobalvar("itemDrop") == "money+weapon"){setglobalvar("itemDrop", "food+weapon");}else
					if(getglobalvar("itemDrop") == "food+weapon"){setglobalvar("itemDrop", "food+money");}else
					if(getglobalvar("itemDrop") == "food+money"){setglobalvar("itemDrop", "weapon_only");}else
					if(getglobalvar("itemDrop") == "weapon_only"){setglobalvar("itemDrop", "money_only");}else
					if(getglobalvar("itemDrop") == "money_only"){setglobalvar("itemDrop", "food_only");}else
					if(getglobalvar("itemDrop") == "food_only"){setglobalvar("itemDrop", "mixed");}
				}

				//IS QUICK RESPAWN HIGHLIGHTED??
				if(getglobalvar("highlight") == 16){
					if(getglobalvar("smarterEnemy") == "on"){setglobalvar("smarterEnemy", "off");}else
					if(getglobalvar("smarterEnemy") == "off"){setglobalvar("smarterEnemy", "on");}
				}

				//IS ENEMY GET FOOD HIGHLIGHTED??
				if(getglobalvar("highlight") == 17){
					if(getglobalvar("blockCost") == "off"){setglobalvar("blockCost", "2");}else
					if(getglobalvar("blockCost") == "2"){setglobalvar("blockCost", "1");}else
					if(getglobalvar("blockCost") == "1"){setglobalvar("blockCost", "off");}
				}
				saveCfg();
			}
		}
	}
}
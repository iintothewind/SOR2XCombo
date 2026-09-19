#import "data/scripts/keyall/main_savecfg.c"

void menuSurvival(int player)
{//Configure Survival mode before start Survival mode

//HIGHLIGHT OPTIONS:
//0  - SURVIVAL MODE            (MAIN.C, KEY.C, ONDRAW.C)
//1  - LIFE RESTORE                (MAIN.C, KEY.C, ONDRAW.C)
//2  - GROUP SIZE                (MAIN.C, KEY.C, ONDRAW.C)
//3  - GROUP RATE                (MAIN.C, KEY.C, ONDRAW.C)
//4  - BOSS RATE                (MAIN.C, KEY.C, ONDRAW.C)
    
    int highlight = getglobalvar("highlight");
    int hasplayed = getplayerproperty(player, "hasplayed");
    
    if(getglobalvar("activeText") == "Survival" && hasplayed == 1){ //SURVIVAL MENU STARTED
        if(playerkeys(player, 1, "movedown")){ //HIGHLIGHT OPTIONS
            playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
            
            //BLOCK GROUP ADJUSTS IF SINGLE MODE IS SELECTED
            if(getglobalvar("survivalMode") == "single"){
                if(highlight == 0){setglobalvar("highlight", 1);}
                if(highlight == 1){setglobalvar("highlight", 0);}
            }
            
            //BLOCK LIFE RESTORE ADJUST IF GROUP MODE IS SELECTED
            if(getglobalvar("survivalMode") == "group"){
                if(highlight == 0){setglobalvar("highlight", 2);}
                if(highlight >= 2 && highlight < 4){setglobalvar("highlight", highlight+1);}
                if(highlight == 4){setglobalvar("highlight", 0);}
            }
            
            //BLOCK ALL ADJUSTS IF BATTLE ROYALE MODE IS SELECTED
            if(getglobalvar("survivalMode") == "battle_royale"){
                if(highlight == 0){setglobalvar("highlight", 0);}
                if(highlight == 0){setglobalvar("highlight", 0);}
            }
        }
        
        //HIGHLIGHT OPTIONS WHEN MOVE UP
        if(playerkeys(player, 1, "moveup")){
            playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
            
            //BLOCK GROUP ADJUSTS IF SINGLE MODE IS SELECTED
            if(getglobalvar("survivalMode") == "single"){
                if(highlight == 0){setglobalvar("highlight", 1);}
                if(highlight == 1){setglobalvar("highlight", 0);}
            }
            
            //BLOCK LIFE RESTORE ADJUST IF GROUP MODE IS SELECTED
            if(getglobalvar("survivalMode") == "group"){
                if(highlight == 0){setglobalvar("highlight", 4);}
                if(highlight > 2 && highlight <= 4){setglobalvar("highlight", highlight-1);}
                if(highlight == 2){setglobalvar("highlight", 0);}
            }
            
            //BLOCK ALL ADJUSTS IF BATTLE ROYALE MODE IS SELECTED
            if(getglobalvar("survivalMode") == "battle_royale"){
                if(highlight == 0){setglobalvar("highlight", 0);}
                if(highlight == 0){setglobalvar("highlight", 0);}
            }
        }
        
        //CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE RIGHT
        if(playerkeys(player, 1, "moveright")){
            playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
            
            //IS SURVIVAL MODE HIGHLIGHTED??
            if(getglobalvar("highlight") == 0){
                if(getglobalvar("survivalMode") == "single"){setglobalvar("survivalMode", "group");}else
                if(getglobalvar("survivalMode") == "group"){setglobalvar("survivalMode", "battle_royale");}else
                if(getglobalvar("survivalMode") == "battle_royale"){setglobalvar("survivalMode", "single");}
            }
            //IS LIFE RESTORE HIGHLIGHTED??
            if(getglobalvar("highlight") == 1){
                if(getglobalvar("survivaLifeRestore") == "50%"){setglobalvar("survivaLifeRestore", "75%");}else
                if(getglobalvar("survivaLifeRestore") == "75%"){setglobalvar("survivaLifeRestore", "100%");}else
                if(getglobalvar("survivaLifeRestore") == "100%"){setglobalvar("survivaLifeRestore", "0%");}else
                if(getglobalvar("survivaLifeRestore") == "0%"){setglobalvar("survivaLifeRestore", "25%");}else
                if(getglobalvar("survivaLifeRestore") == "25%"){setglobalvar("survivaLifeRestore", "50%");}
            }
            
            //IS GROUP SIZE HIGHLIGHTED??
            if(getglobalvar("highlight") == 2){
                if(getglobalvar("survivalGroupSize") < 10){setglobalvar("survivalGroupSize", getglobalvar("survivalGroupSize")+1);}else
                if(getglobalvar("survivalGroupSize") >= 10){setglobalvar("survivalGroupSize", getglobalvar("survivalGroupSize")-9);}}
            
            //IS GROUP RATE HIGHLIGHTED??
            if(getglobalvar("highlight") == 3){
                if(getglobalvar("survivalGroupRate") < 10){setglobalvar("survivalGroupRate", getglobalvar("survivalGroupRate")+1);}else
                if(getglobalvar("survivalGroupRate") >= 10){setglobalvar("survivalGroupRate", getglobalvar("survivalGroupRate")-9);}
            }
            
            //IS BOSS RATE HIGHLIGHTED??
            if(getglobalvar("highlight") == 4){
                if(getglobalvar("survivalBossRate") < 20){setglobalvar("survivalBossRate", getglobalvar("survivalBossRate")+5);}else 
                if(getglobalvar("survivalBossRate") >= 20){setglobalvar("survivalBossRate", getglobalvar("survivalBossRate")-15);}
            }
            saveCfg();
        }
        
        //CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
        if(playerkeys(player, 1, "moveleft")){
            playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
            
            //IS SURVIVAL MODE HIGHLIGHTED??
            if(getglobalvar("highlight") == 0){
                if(getglobalvar("survivalMode") == "single"){setglobalvar("survivalMode", "battle_royale");}else
                if(getglobalvar("survivalMode") == "battle_royale"){setglobalvar("survivalMode", "group");}else
                if(getglobalvar("survivalMode") == "group"){setglobalvar("survivalMode", "single");}
            }
            
            //IS LIFE RESTORE HIGHLIGHTED??
            if(getglobalvar("highlight") == 1){
                if(getglobalvar("survivaLifeRestore") == "50%"){setglobalvar("survivaLifeRestore", "25%");}else
                if(getglobalvar("survivaLifeRestore") == "25%"){setglobalvar("survivaLifeRestore", "0%");}else
                if(getglobalvar("survivaLifeRestore") == "0%"){setglobalvar("survivaLifeRestore", "100%");}else
                if(getglobalvar("survivaLifeRestore") == "100%"){setglobalvar("survivaLifeRestore", "75%");}else
                if(getglobalvar("survivaLifeRestore") == "75%"){setglobalvar("survivaLifeRestore", "50%");}
            }
            
            //IS GROUP SIZE HIGHLIGHTED??
            if(getglobalvar("highlight") == 2){
                if(getglobalvar("survivalGroupSize") > 1){setglobalvar("survivalGroupSize", getglobalvar("survivalGroupSize")-1);}else
                if(getglobalvar("survivalGroupSize") <= 1){setglobalvar("survivalGroupSize", getglobalvar("survivalGroupSize")+9);}
            }
            
            //IS GROUP RATE HIGHLIGHTED??
            if(getglobalvar("highlight") == 3){
                if(getglobalvar("survivalGroupRate") > 1){setglobalvar("survivalGroupRate", getglobalvar("survivalGroupRate")-1);}else
                if(getglobalvar("survivalGroupRate") <= 1){setglobalvar("survivalGroupRate", getglobalvar("survivalGroupRate")+9);}
            }
            
            //IS BOSS RATE HIGHLIGHTED??
            if(getglobalvar("highlight") == 4){
                if(getglobalvar("survivalBossRate") > 5){setglobalvar("survivalBossRate", getglobalvar("survivalBossRate")-5);}else
                if(getglobalvar("survivalBossRate") <= 5){setglobalvar("survivalBossRate", getglobalvar("survivalBossRate")+15);}
            }
            saveCfg();
        }

        //USED TO EXIT WITHOUT SELECT ANY CHARACTER
        if(playerkeys(player, 1, "jump")){
            gotomainmenu(3);
        }

        else
        
        //BEGIN GAME WHEN ANY BUTTON IS PRESSED
        if(playerkeys(player, 1, "anybutton")){
            if(getglobalvar("survivalStart") == 0){
                playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                setglobalvar("survivalStart", 1); //START SURVIVAL MODE
            }
            saveCfg();
        }
    }
}
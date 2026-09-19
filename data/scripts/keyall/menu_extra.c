#import "data/scripts/keyall/main_savecfg.c"
#include "data/scripts/assets.h"

void menuExtra(int player)
{//Change Extra Menu variables if defined key is pressed

//HIGHLIGHT OPTIONS:
//0    - GAMEPLAY                    (UPDATED.C, KEYALL.C)
//1    - CONTROLS                    (UPDATED.C, KEYALL.C)
//2    - FEATURES                    (UPDATED.C, KEYALL.C)
//3    - PARTNERS                    (UPDATED.C, KEYALL.C)
//4    - MULTIPLAYER                (UPDATED.C, KEYALL.C)
    
    int highlight = getglobalvar("highlight");
    int hasplayed = getplayerproperty(player, "hasplayed");
    
    if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
        
        //HIGHLIGHT OPTIONS WHEN MOVE RIGHT
        if(playerkeys(player, 1, "moveright")){
            if(getglobalvar("highlight") == 0){
                if(getglobalvar("subMenu") == "gameplay"){
                    setglobalvar("subMenu", "controls");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "controls"){
                    setglobalvar("subMenu", "features");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "features"){
                    setglobalvar("subMenu", "partners");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "partners"){
                    setglobalvar("subMenu", "multiplayer");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "multiplayer"){
                    setglobalvar("subMenu", "gameplay");setglobalvar("highlight", 0);
                }
            }
        }
        
        //HIGHLIGHT OPTIONS WHEN MOVE LEFT
        if(playerkeys(player, 1, "moveleft")){
            if(getglobalvar("highlight") == 0){
                if(getglobalvar("subMenu") == "gameplay"){
                    setglobalvar("subMenu", "multiplayer");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "multiplayer"){
                    setglobalvar("subMenu", "partners");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "partners"){
                    setglobalvar("subMenu", "features");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "features"){
                    setglobalvar("subMenu", "controls");setglobalvar("highlight", 0);
                }
                else
                if(getglobalvar("subMenu") == "controls"){
                    setglobalvar("subMenu", "gameplay");setglobalvar("highlight", 0);
                }
            }
        }
    }
    
    //COMMAND TO RESTORE DEFAULTS IN ALL MENUS
    if(playerkeys(player, 1, "screenshot")){
        if(openborvariant("current_scene") == "data/scenes/howto.txt"){
            if(getglobalvar("subMenu") != "commands_1" && getglobalvar("subMenu") != "commands_2"){
                playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
                defaultCfg();
            }
        }
    }
    
    //MAIN COMMAND TO OPEN AND CLOSE EXTRA MENU
    if(playerkeys(player, 1, "screenshot") && hasplayed == 1){ //SELECT BUTTON IS PRESSED??
        if(openborvariant("in_level") && getglobalvar("arcadeLock") == 0){ //CHECK IF THE GAME IS IN ANY LEVEL AND ARCADE LOCK IS "0"
            if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
                if(getglobalvar("activeText") == 0){ //CHECK IF ANY MENU IS ALREADY ON
                    playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
                    changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
                    changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
                    setglobalvar("highlight", 0); //SET TO THE FIRST HIGHLIGHTED OPTION
                    setglobalvar("activeText", "Extra"); //SET ACTIVE TEXT ON SCREEN TO "EXTRA MENU" TO ACTIVATE OTHER SCRIPTS
                }
                else
                if(getglobalvar("activeText") == "Extra"){ //CHECK IF EXTRA MENU IS ALREADY ON
                    playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
                    changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
                    changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
                    setglobalvar("highlight", 0); //RESET HIGHLIGHT VARIABLE TO DEFAULT
                    setglobalvar("activeText", 0); //SET ACTIVE TEXT ON SCREEN TO "0" TO DEACTIVATE OTHER SCRIPTS
                }
            }
        }
    }
}
#import "data/scripts/keyall/main_savecfg.c"

void menuMultiplayer(int player)
{//Change Gameplay Menu variables if defined key is pressed

//HIGHLIGHT OPTIONS:
//1 - VERSUS DAMAGE                (UPDATED.C, KEYALL.C)
//2 - MULTIHIT "GLITCH"            (UPDATED.C, KEYALL.C)

    int highlight = getglobalvar("highlight");
    int hasplayed = getplayerproperty(player, "hasplayed");
    int max          = 1;
    int min          = 0;
    int add          = 1;
    
    if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra" && hasplayed == 1){
        if(getglobalvar("subMenu") == "multiplayer"){
        
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
                
                //IS VERSUS DAMAGE HIGHLIGHTED??
                if(getglobalvar("highlight") == 1){
                    if(getglobalvar("versusDamage") == "enabled"){setglobalvar("versusDamage", "disabled");}else
                    if(getglobalvar("versusDamage") == "disabled"){setglobalvar("versusDamage", "enabled");}
                }
                
                //IS MULTIHIT "BUG" HIGHLIGHTED??
                if(getglobalvar("highlight") == 2){
                    if(getglobalvar("multiHit") == "enabled"){setglobalvar("multiHit", "disabled");}else
                    if(getglobalvar("multiHit") == "disabled"){setglobalvar("multiHit", "enabled");}
                }
                saveCfg();
            }
            
            //CHANGE ALL OPTIONS INSIDE THIS MENU WHEN MOVE LEFT
            if(playerkeys(player, 1, "moveleft")){
                playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                
                //IS VERSUS DAMAGE HIGHLIGHTED??
                if(getglobalvar("highlight") == 1){
                    if(getglobalvar("versusDamage") == "enabled"){setglobalvar("versusDamage", "disabled");}else
                    if(getglobalvar("versusDamage") == "disabled"){setglobalvar("versusDamage", "enabled");}
                }
                
                //IS MULTIHIT "BUG" HIGHLIGHTED??
                if(getglobalvar("highlight") == 2){
                    if(getglobalvar("multiHit") == "enabled"){setglobalvar("multiHit", "disabled");}else
                    if(getglobalvar("multiHit") == "disabled"){setglobalvar("multiHit", "enabled");}
                }
                saveCfg();
            }
        }
    }
}
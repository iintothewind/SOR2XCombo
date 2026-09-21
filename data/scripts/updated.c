#import "data/scripts/attributes.h"
#import "data/scripts/assets.h"
#import "data/scripts/keyall/main_savecfg.c"
#import "data/scripts/updated/main_misc.c"
#import "data/scripts/updated/main_hiscore.c"
#import "data/scripts/updated/main_scenes.c"
#import "data/scripts/updated/main_drawguard.c"
#import "data/scripts/updated/main_drawenergy.c"
#import "data/scripts/updated/main_drawoverlay.c"
#import "data/scripts/updated/main_drawheal.c"
#import "data/scripts/updated/main_drawok.c"
#import "data/scripts/updated/main_drawko.c"
#import "data/scripts/updated/main_drawdamage.c"
#import "data/scripts/updated/main_drawjuggle.c"
#import "data/scripts/updated/main_drawotg.c"
#import "data/scripts/updated/main_drawclock.c"
#import "data/scripts/updated/main_completescreen.c"
#import "data/scripts/updated/main_arcadelock.c"
#import "data/scripts/updated/main_debugmode.c"
#import "data/scripts/updated/main_playedtime.c"
#import "data/scripts/updated/menu_extra.c"
#import "data/scripts/updated/menu_gameplay.c"
#import "data/scripts/updated/menu_controls.c"
#import "data/scripts/updated/menu_features.c"
#import "data/scripts/updated/menu_partners.c"
#import "data/scripts/updated/menu_commands.c"
#import "data/scripts/updated/menu_multiplayer.c"
#import "data/scripts/updated/menu_select.c"
#import "data/scripts/levelspawn/main_musicmisc.c"

void main()
{//Start all tasks

    //ENTIRE GAME
    screenshotsOff();
    scenePlay();
    getFps();

    //TITLE SCREEN
    if(openborvariant("in_titlescreen")){

        //SCRIPT USED TO CLEAR ALL VARIABLES AND ASSETS
        if(getglobalvar("clearAll") != NULL()){clearAssets();clearlocalvar();clearglobalvar();}

        //FLAG USED TO INDICATE IF THE LEVEL MUSIC IS STOPPED TO THE "MUSICSTAGE.C" FUNCTIONS
        if(getglobalvar("musicStopped") != 1){setglobalvar("musicStopped", 1);}

        //RESET CREDITS ACCORDING TO DEFAULT VALUE DEFINED IN "LEVELS.TXT" FILE
        // if(getplayerproperty(0, "credits") != 9){changeplayerproperty(0, "credits", 9);}

        //PLAY "PRESS START" WEBM VIDEO
        playwebm("data/scenes/start.webm");
    }

    //SCENES DETECTION
    if(openborvariant("current_scene") == "data/scenes/howto.txt"){ //WORKS WITH "EXTRA MENU" FUNCTIONS
        menuExtra();
        menuGameplay();
        menuControls();
        menuFeatures();
        menuPartners();
        menuCommands();
        menuMultiplayer();
    }
    if(openborvariant("current_scene") == "data/scenes/ending_a.txt"){ //WORKS WITH "CUSTOM HISCORE" FUNCTIONS
        timePlayed();
        changeScore(0);changeScore(1);changeScore(2);changeScore(3);

    }
    else
    if(openborvariant("current_scene") == "data/scenes/ending_b.txt"){ //WORKS WITH "CUSTOM HISCORE" FUNCTIONS
        timePlayed();
        changeScore(0);changeScore(1);changeScore(2);changeScore(3);

    }
    else
    if(openborvariant("current_scene") == "data/scenes/ending_c.txt"){ //WORKS WITH "CUSTOM HISCORE" FUNCTIONS
        timePlayed();
        changeScore(0);changeScore(1);changeScore(2);changeScore(3);
    }

    //MENU SCREEN, START A LOT OF VARIABLES IF "NULL()"
    if(openborvariant("in_menuscreen")){

        //MISC FUNCTIONS
        if(getglobalvar("activeText") == NULL()){setglobalvar("activeText", 0);}
        if(getglobalvar("subMenu") != "gameplay"){setglobalvar("subMenu", "gameplay");}
        if(getglobalvar("highlight") != 0){setglobalvar("highlight", 0);}
        if(getglobalvar("selectPartner") == NULL()){setglobalvar("selectPartner", "Axel_");}
        if(getglobalvar("partnerAlive") == NULL()){setglobalvar("partnerAlive", 0);}
        if(getglobalvar("survivalStart") == NULL()){setglobalvar("survivalStart", 0);}
        if(getglobalvar("dojoStart") == NULL()){setglobalvar("dojoStart", 0);}
        if(getglobalvar("debugMode") == NULL()){setglobalvar("debugMode", 0);}
        showVersion();

        //WORKS WITH "SELECT SCREEN" FUNCTIONS
        if(getglobalvar("previewCol0") == NULL()){
            setglobalvar("previewCol0", 0);
            setglobalvar("previewCol1", 0);
            setglobalvar("previewCol2", 0);
            setglobalvar("previewCol3", 0);
            setglobalvar("previewLine0", 0);
            setglobalvar("previewLine1", 0);
            setglobalvar("previewLine2", 0);
            setglobalvar("previewLine3", 0);
        }

        //WORKS WITH "LEVEL SELECT" FUNCTIONS
        if(getglobalvar("levelName") == NULL()){
            setglobalvar("levelName", "sor2_st1a");
            setglobalvar("levelCol", 0);
            setglobalvar("levelLine", 0);
        }

        //WORKS WITH "PLAYED TIME" FUNCTION
        if(getglobalvar("playedCounter") == NULL()){
            setglobalvar("playedCounter", openborvariant("elapsed_time"));
            setglobalvar("playedSecond", 0);
            setglobalvar("playedMinute", 0);
            setglobalvar("playedHour", 0);
        }

        //CORE FUNCTIONS
        loadCfg();
        loadScore();
        saveAtt();
        saveAssets();
        arcadeLock();

        //WORKS WITH "CLEARALL" FUNCTION
        if(getglobalvar("clearAll") == NULL()){setglobalvar("clearAll", 1);}
    }

    //SELECT SCREEN
    if(openborvariant("in_selectscreen")){
        selectBack();
        selectPlayer();
        turboKey();
    }

    //IN LEVEL
    if(openborvariant("in_level")){
        arcadeLock();
        drawGuard();
        drawEnergy();
        drawOverlay();
        drawHeal();
        drawOk();
        drawKO();
        drawDamage();
        drawJuggle();
        drawOtg();
        drawClock();
        menuExtra();
        menuGameplay();
        menuControls();
        menuFeatures();
        menuPartners();
        menuCommands();
        menuMultiplayer();
        turboKey();
        timePlayed();
        resetCharge();
        debugMode();
        liveScreen();

        //RESET COUNTER TO ACTIVATE COMPLETE SCREEN EVENTS AGAIN
        if(getlocalvar("completeCounter") != 0){setlocalvar("completeCounter", 0);}

        //RESTART MUSICS EVERYTIME THE SOUND MENU IS ACCESSED
        //USED BECAUSE SCRIPTED MUSICS DON'T RESTARTS AUTOMATICALLY IF THE PLAYER DISABLE/ENABLE IT IN THE SOUND MENU
        if(openborvariant("pause") && openborvariant("in_sound_options")){
            if(getglobalvar("soundMenu") == NULL()){
                setglobalvar("soundMenu", 1);
            }
        }
        else
        if(!openborvariant("pause")){
            if(getglobalvar("soundMenu") != NULL()){
                musicReplay();
                setglobalvar("soundMenu", NULL());
            }
        }
    }

    //COMPLETE SCREEN
    if(openborvariant("in_showcomplete")){
        completeScreen();
        resetMaxRush();
        timePlayed();
    }

    //HALL OF FAME SCREEN
    if(openborvariant("in_halloffamescreen")){
        saveScore();
        drawScore();
    }

    //ENGINE CREDITS SCREEN
    if(openborvariant("in_enginecreditsscreen")){
        changeopenborvariant("nopause", 0);
        changeopenborvariant("textbox", NULL());
        changeplayerproperty(0, "disablekeys", 0);
        changeplayerproperty(1, "disablekeys", 0);
        changeplayerproperty(2, "disablekeys", 0);
        changeplayerproperty(3, "disablekeys", 0);
    }
}
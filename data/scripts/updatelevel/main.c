void changeCamera()
{//Adjust camera with XPOS check
    void branch    = openborvariant("current_branch");
    float xPos    = openborvariant("xpos");
    float xCam    = getlevelproperty("cameraxoffset");
    float zCam    = getlevelproperty("camerazoffset");

    if(branch == "sor2_st1a"){
        if(xPos >= 600){
            if(zCam != 0){
                changelevelproperty("camerazoffset", 0);
            }
        }
    }
    else
    if(branch == "sor2_st3b"){
        if(xPos >= 1){
            if(zCam != 0){
                changelevelproperty("camerazoffset", 0);
            }
        }
    }
    else
    if(branch == "sor2_st6b"){
        if(xPos >= 200){
            if(zCam != 0){
                changelevelproperty("camerazoffset", 0);
            }
        }
    }
    else
    if(branch == "sor3_st3b"){
        if(xPos <= 1050){
            if(xCam != -120){
                changelevelproperty("cameraxoffset", -120);
            }
        }
    }
}

void changeLayer()
{//Change layer properties according to graphic effects option
    void effects = getglobalvar("graphicEffects");
    void branch     = openborvariant("current_branch");
    float xPos     = openborvariant("xpos");

    if(branch == "sor2_st3g" || branch == "sor2_st3i"){
        int fglayer0 = getlayerproperty("fglayer", 0, "enabled");
        int fglayer1 = getlayerproperty("fglayer", 1, "enabled");

        if(effects == "original" && fglayer0 == 1){
            changelayerproperty("fglayer", 0, "enabled", 0);
            changelayerproperty("fglayer", 1, "enabled", 1);
        }
        else
        if(effects == "sor2x" && fglayer1 == 1){
            changelayerproperty("fglayer", 0, "enabled", 1);
            changelayerproperty("fglayer", 1, "enabled", 0);
        }
    }
    else
    if(branch == "sor3_st1b"){
        int bglayer1 = getlayerproperty("bglayer", 1, "enabled");
        int bglayer2 = getlayerproperty("bglayer", 2, "enabled");

        if(xPos > 1200 && xPos < 1600){
            if(bglayer2 == 1){
                changelayerproperty("bglayer", 2, "enabled", 0);
                changelayerproperty("bglayer", 5, "enabled", 0);
                changelayerproperty("bglayer", 8, "enabled", 0);
                changelayerproperty("fglayer", 2, "enabled", 0);
            }
        }

        if(xPos >= 1600){
            if(bglayer1 == 1){
                changelayerproperty("bglayer", 1, "enabled", 0);
                changelayerproperty("bglayer", 4, "enabled", 0);
                changelayerproperty("bglayer", 7, "enabled", 0);
                changelayerproperty("fglayer", 1, "enabled", 0);
            }
        }
    }
}

void gasCountdown()
{//Toxic gas countdown (ALARM WITH TOXIC GAS IN ST6A)
    void self     = getlocalvar("self");
    float time     = openborvariant("ticks");
    float total     = 960000; //TOTAL TIME IS total/limit
    float limit     = 60000; //THE ESTIMATED TIME IS AT total - limit

    if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
        if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF THE GAME IS IN EXTRA/PARTNER MENUS
            if(getglobalvar("gasEnable") != 1){ //TOXIC GAS IS DISABLED??

                //TOXIC GAS COUNTDOWN IS NULL?? SAVE START TIME IF NULL
                if(getglobalvar("gasCount") == NULL()){setglobalvar("gasCount", time+total);}

                //THE COUNTDOWN ENDED?? ENABLE GAS
                if(getglobalvar("gasCount") - time < limit){setglobalvar("gasEnable", 1);}
            }
        }
    }

    //USED TO HIDE INFO WHEN THE COUNTDOWN REACHES THE LIMIT
    if(getglobalvar("gasEnable") != 1){ //TOXIC GAS IS DISABLED??
        drawstring(1, 260, 0, "time_left:_"); //SHOW TOXIC GAS COUNTDOWN REMAINING
        drawstring(70, 260, 9, (getglobalvar("gasCount") - time)/limit); //SHOW TOXIC GAS COUNTDOWN REMAINING
    }
}

void cycleSprite(void type, int startIndex, int endIndex, float delay)
{//Apply simple sprite cycle effects to avoid creating new entities
    float timeCurrent = openborvariant("elapsed_time");

    //START ALL VARIABLES
    if(getlocalvar("timeCounter"+type+startIndex) == NULL()){setlocalvar("timeCounter"+type+startIndex, timeCurrent+delay);}
    if(getlocalvar("frameCurrent"+type+startIndex) == NULL()){setlocalvar("frameCurrent"+type+startIndex, endIndex);}
    if(getlocalvar("frameNext"+type+startIndex) == NULL()){setlocalvar("frameNext"+type+startIndex, startIndex);}

    //GET ALL VARIABLES
    float timeCounter    = getlocalvar("timeCounter"+type+startIndex);
    int frameCurrent    = getlocalvar("frameCurrent"+type+startIndex);
    int frameNext        = getlocalvar("frameNext"+type+startIndex);

    if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){

        //DELAY REACHED THE LIMIT?? EXECUTE ALL TASKS
        if(timeCurrent > timeCounter){

            //DEFINE THE CURRENT FRAME
            if(frameCurrent < endIndex){
                setlocalvar("frameCurrent"+type+startIndex, frameCurrent+1);
                setlocalvar("timeCounter"+type+startIndex, timeCurrent+delay);
            }
            else
            {
                setlocalvar("frameCurrent"+type+startIndex, startIndex);
            }

            //DEFINE THE NEXT FRAME
            if(frameNext < endIndex){
                setlocalvar("frameNext"+type+startIndex, frameNext+1);
                setlocalvar("timeCounter"+type+startIndex, timeCurrent+delay);
            }
            else
            {
                setlocalvar("frameNext"+type+startIndex, startIndex);
            }

            //CHANGE LAYERS
            changelayerproperty(type, frameCurrent, "enabled", 0);
            changelayerproperty(type, frameNext, "enabled", 1);
        }
    }
}
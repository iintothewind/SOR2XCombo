void main()
{//Draw "Stage" number and "Start" words before level starts
    void self     = getlocalvar("self");
    void name    = getentityproperty(self, "defaultname");
    int frame    = getentityproperty(self, "animpos");
    int x        = getentityproperty(self, "x");
    int y        = getentityproperty(self, "y");
    int z        = getentityproperty(self, "z");
    int font    = 7;
    int layer    = 1000000003;

    if(openborvariant("current_branch") == "sor3_st6a" && getglobalvar("st6_zpos") != NULL()){
        killentity(self);
    } else {
        if(name == "Stage"){
            if(frame < 5){
                setglobalvar("activeText", "Stage");
                changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
                changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
                changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
            }
            else
            if(frame >= 5){
                if(openborvariant("current_branch") == "sor3_st7d"){
                    if(getglobalvar("activeText") != "Bike_Stage"){
                        changeopenborvariant("nopause", 1); //LOCK PAUSE COMMAND
                        changeopenborvariant("textbox", 1); //CALL TEXTBOX TO FREEZE THE GAME
                        changeplayerproperty(0, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                        changeplayerproperty(1, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                        changeplayerproperty(2, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                        changeplayerproperty(3, "disablekeys", openborconstant("FLAG_START")+openborconstant("FLAG_SCREENSHOT")+openborconstant("FLAG_ESC"));
                        setglobalvar("activeText", "Bike_Stage");
                    }
                }else{
                    setglobalvar("activeText", 0);
                    changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
                    changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
                    changeplayerproperty(0, "disablekeys", 0);
                    changeplayerproperty(1, "disablekeys", 0);
                    changeplayerproperty(2, "disablekeys", 0);
                    changeplayerproperty(3, "disablekeys", 0);
                }
            }
            drawstring(x, z-y, font, "stage", layer);
        }

        if(name == "Number"){
            if(openborvariant("current_stage") == 1){
                drawstring(x+1, z-y, font, openborvariant("current_stage"), layer);
            }else{
                drawstring(x-2, z-y, font, openborvariant("current_stage"), layer);
            }
        }

        if(name == "Start"){drawstring(x, z-y, font, "start", layer);}
    }
}
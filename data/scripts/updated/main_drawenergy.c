#include "data/scripts/assets.h"

void drawEnergy()
{//Draw energy stars
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");

    if(openborvariant("pause") == 0){
        energyFunction(player1);
        energyFunction(player2);
        energyFunction(player3);
        energyFunction(player4);
    }
}

void energyFunction(void player)
{//Script used to reduce code size
    if(player != NULL()){
        int pIndex     = getentityproperty(player, "playerindex");
        int lives     = getplayerproperty(pIndex, "lives");

        if(lives >= 1){
            void star;
            int maxMp    = getentityproperty(player, "maxmp");
            int mp        = getentityproperty(player, "mp");
            int xPos    = 55;
            int xDif    = 120;
            int xAdd    = xDif*pIndex;
            int yPos    = 29;
            int sDif    = 8;
            int layer    = 50000;
            int engXPos     = 24;

            void eng = mp >= 120? 120 : mp;

            drawstring(engXPos+xAdd, yPos, 1, eng, layer);

            if(mp >= maxMp){
                if(getglobalvar("activeText") == 0){
                    if(getglobalvar("levelSelected") != 1){
                        if(openborvariant("current_branch") != "survival_config"){
                            if(getlocalvar("counter"+player) != 1){
                                playsample(SAMPLE_RAGEFULL, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
                                setlocalvar("counter"+player, 1);
                            }
                        }
                    }
                }
                star = "*****";
                drawstring(xPos+xAdd, yPos, 1, star, layer);

            }
            else
            if(mp < maxMp && mp >= maxMp/5*4){
                if(getlocalvar("counter"+player) != 0){setlocalvar("counter"+player, 0);}
                xPos = xPos+sDif;
                star = "****";
                drawstring(xPos+xAdd, yPos, 1, star, layer);
            }
            else
            if(mp < maxMp && mp >= maxMp/5*3){
                if(getlocalvar("counter"+player) != 0){setlocalvar("counter"+player, 0);}
                xPos = xPos+sDif;
                star = "***";
                drawstring(xPos+xAdd, yPos, 1, star, layer);
            }
            else
            if(mp < maxMp && mp >= maxMp/5*2){
                if(getlocalvar("counter"+player) != 0){setlocalvar("counter"+player, 0);}
                xPos = xPos+sDif;
                star = "**";
                drawstring(xPos+xAdd, yPos, 1, star, layer);
            }
            else
            if(mp < maxMp/3*2 && mp >= maxMp/5){
                if(getlocalvar("counter"+player) != 0){setlocalvar("counter"+player, 0);}
                xPos = xPos+sDif*2;
                star = "*";
                drawstring(xPos+xAdd, yPos, 1, star, layer);
            }
            else
            {
                if(getlocalvar("counter"+player) != 0){setlocalvar("counter"+player, 0);}
                star = "";
                drawstring(xPos+xAdd, yPos, 1, star, layer);
            }
        }
    }
}
void menuGameplay()
{//Draw a Menu in/out game
    void str;
    int align;
    int xPos1  = 231;             //BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
    int xDif   = 20;            //DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
    int xPos2  = xPos1+xDif;    //BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
    int yPos   = 70;            //BASE Y POSITION FOR ALL MENU CONTENT, USE THIS TO MOVE ALL OPTIONS TOGETHER
    int font0  = 0;                //ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
    int font1  = 0;
    int font2  = 0;
    int font3  = 0;
    int font4  = 0;
    int font5  = 0;
    int font6  = 0;
    int font7  = 0;
    int font8  = 0;
    int font9  = 0;
    int font10 = 0;
    int font11 = 0;
    int font12 = 0;
    int font13 = 0;
    int font14 = 0;
    int font15 = 0;
    int font16 = 0;
    int font17 = 0;
    int yAdd   = 11;
    int layer  = 1000000003;

    //DEFINE FONTS TO HIGHLIGHTED OPTIONS
    if(getglobalvar("highlight") == 1){    font1 = 1;}else
    if(getglobalvar("highlight") == 2){    font2 = 1;}else
    if(getglobalvar("highlight") == 3){    font3 = 1;}else
    if(getglobalvar("highlight") == 4){    font4 = 1;}else
    if(getglobalvar("highlight") == 5){    font5 = 1;}else
    if(getglobalvar("highlight") == 6){    font6 = 1;}else
    if(getglobalvar("highlight") == 7){    font7 = 1;}else
    if(getglobalvar("highlight") == 8){    font8 = 1;}else
    if(getglobalvar("highlight") == 9){    font9 = 1;}else
    if(getglobalvar("highlight") == 10){font10 = 1;}else
    if(getglobalvar("highlight") == 11){font11 = 1;}else
    if(getglobalvar("highlight") == 12){font12 = 1;}else
    if(getglobalvar("highlight") == 13){font13 = 1;}else
    if(getglobalvar("highlight") == 14){font14 = 1;}else
    if(getglobalvar("highlight") == 15){font15 = 1;}else
    if(getglobalvar("highlight") == 16){font16 = 1;}else
    if(getglobalvar("highlight") == 17){font17 = 1;}else


    //BLOCK GAMEPLAY MENU IF IN ANY LEVEL
    if(openborvariant("in_level")){
        font1  = 2;
        font2  = 2;
        font3  = 2;
        font4  = 2;
        font5  = 2;
        font6  = 2;
        font7  = 2;
        font8  = 2;
        font9  = 2;
        font10 = 2;
        font11 = 2;
        font12 = 2;
        font13 = 2;
        font14 = 2;
        font15 = 2;
        font16 = 2;
        font17 = 2;
    }

    //DRAW MENU
    if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
        if(getglobalvar("subMenu") == "gameplay"){

            str  = "difficult:";align = xPos1-strwidth(str, font0);
            drawstring(align, yPos, font1, str, layer);
            drawstring(xPos2, yPos, font1, getglobalvar("difficult"), layer);

            str  = "enemy_life_rate:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font2, str, layer);
            drawstring(xPos2, yPos, font2, getglobalvar("enemyLifeRate"), layer);

            str  = "lives:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font3, str, layer);
            drawstring(xPos2, yPos, font3, getglobalvar("lives"), layer);

            str  = "last_chance_recover:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font4, str, layer);
            drawstring(xPos2, yPos, font4, getglobalvar("lastChance"), layer);

            str  = "counter_attack_reward:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font5, str, layer);
            drawstring(xPos2, yPos, font5, getglobalvar("counterAttackReward"), layer);

            str  = "rush_heat:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font6, str, layer);
            drawstring(xPos2, yPos, font6, getglobalvar("rushHeat"), layer);

            str  = "juggle_system:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font7, str, layer);
            drawstring(xPos2, yPos, font7, getglobalvar("juggleSystem"), layer);

            str     = "otg_system:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font8, str, layer);
            drawstring(xPos2, yPos, font8, getglobalvar("otgSystem"), layer);

            str  = "enemy_rush_limit:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font9, str, layer);
            drawstring(xPos2, yPos, font9, getglobalvar("enemyRushLimit"), layer);

            str  = "random_boss:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font10, str, layer);
            drawstring(xPos2, yPos, font10, getglobalvar("randomBoss"), layer);

            str  = "lock_mp:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font11, str, layer);
            drawstring(xPos2, yPos, font11, getglobalvar("lockMp"), layer);

            str  = "energy_regenerate:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font12, str, layer);
            drawstring(xPos2, yPos, font12, getglobalvar("energyRegenerate"), layer);

            str  = "walls:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font13, str, layer);
            drawstring(xPos2, yPos, font13, getglobalvar("walls"), layer);

            str  = "screen_edge:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font14, str, layer);
            drawstring(xPos2, yPos, font14, getglobalvar("screenEdge"), layer);

            str     = "item_drop:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font15, str, layer);
            drawstring(xPos2, yPos, font15, getglobalvar("itemDrop"), layer);

            str     = "smarter_enemy:";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font16, str, layer);
            drawstring(xPos2, yPos, font16, getglobalvar("smarterEnemy"), layer);

            str     = "block_cost";align = xPos1-strwidth(str, font0);
            yPos = yPos+yAdd;
            drawstring(align, yPos, font17, str, layer);
            drawstring(xPos2, yPos, font17, getglobalvar("blockCost"), layer);
        }
    }
}
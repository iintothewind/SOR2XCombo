void menuFeatures()
{//Draw a Menu in/out game

//HIGHLIGHT OPTIONS:
//1	- LEVEL TIME				(UPDATED.C, KEYALL.C)
//2	- PLAYED TIME				(UPDATED.C, KEYALL.C)
//3	- PLAYER ARROW				(UPDATED.C, KEYALL.C)
//4	- SHOW DAMAGE				(UPDATED.C, KEYALL.C)
//5	- GRAPHIC EFFECTS			(UPDATED.C, KEYALL.C)
//6	- MUSIC STYLE				(UPDATED.C, KEYALL.C)
//7	- BGM TEST					(UPDATED.C, KEYALL.C)
//8	- LEVEL SELECT				(UPDATED.C, KEYALL.C)
	
	void finished;
	void music = getglobalvar("bgmTest");
	void str;
	int align;
	int xPos1  = 231; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int xDif   = 20;			//DIFFERENCE BETWEEN THE FIRST AND SECOND COLUMNS
	int xPos2  = xPos1+xDif;	//BASE X POSITION, SECOND COLUMN (HIGHLIGHTED OPTIONS CHANGE)
	int yPos   = 70;			//BASE Y POSITION FOR ALL MENU CONTENT, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int font0  = 0;				//ALL FONTS BELOW CHANGES FROM 0 TO 1 IF THE OPTION IS HIGHLIGHTED
	int font1  = 0;
	int font2  = 0;
	int font3  = 0;
	int font4  = 0;
	int font5  = 0;
	int font6  = 0;
	int font7  = 0;
	int font8  = 0;
	int yAdd   = 11;
	int layer  = 1000000003;
	
	//DEFINE FONTS TO HIGHLIGHTED OPTIONS
	if(getglobalvar("highlight") == 1){	font1 = 1;}else 	//IS LEVEL TIME HIGHLIGHTED??
	if(getglobalvar("highlight") == 2){	font2 = 1;}else 	//IS PLAYED TIME HIGHLIGHTED??
	if(getglobalvar("highlight") == 3){	font3 = 1;}else 	//IS PLAYER ARROW HIGHLIGHTED??
	if(getglobalvar("highlight") == 4){	font4 = 1;}else 	//IS SHOW DAMAGE HIGHLIGHTED??
	if(getglobalvar("highlight") == 5){	font5 = 1;}else 	//IS GRAPHIC EFFECTS HIGHLIGHTED??
	if(getglobalvar("highlight") == 6){	font6 = 1;}else 	//IS MUSIC STYLE HIGHLIGHTED??
	if(getglobalvar("highlight") == 7){	font7 = 1;}else 	//IS BGM TEST HIGHLIGHTED??
	if(getglobalvar("highlight") == 8){	font8 = 1;} 		//IS LEVEL SELECT HIGHLIGHTED??
	
	//BLOCK LEVEL SELECT OPTION IF THE GAME IS NOT CLEARED 3 OR MORE TIMES
	if(getsaveinfo(0, "times_completed") < 3){
		font8    = 2;
		finished = "finished_"+getsaveinfo(0, "times_completed")+"/3";
	}else{
		finished = getglobalvar("levelSelect");
	}
	
	//ADD A "0" ALGARISM TO THE MUSIC NAME IF THE TRACK IS BELOW FROM 9
	if(music <= 9){music = "0"+getglobalvar("bgmTest");}
	
	//DRAW MENU
	if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
		if(getglobalvar("subMenu") == "features"){
			
			str  = "show_level_time:";align = xPos1-strwidth(str, font0);
			drawstring(align, yPos, font1, str, layer);
			drawstring(xPos2, yPos, font1, getglobalvar("levelTime"), layer);
			
			str  = "show_played_time:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font2, str, layer);
			drawstring(xPos2, yPos, font2, getglobalvar("playedTime"), layer);

			str  = "show_player_arrow:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font3, str, layer);
			drawstring(xPos2, yPos, font3, getglobalvar("playerArrow"), layer);
			
			str  = "show_damage:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font4, str, layer);
			drawstring(xPos2, yPos, font4, getglobalvar("showDamage"), layer);
			
			str  = "graphic_effects:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font5, str, layer);
			drawstring(xPos2, yPos, font5, getglobalvar("graphicEffects"), layer);
			
			str  = "music_style:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font6, str, layer);
			drawstring(xPos2, yPos, font6, getglobalvar("musicStyle"), layer);
			
			str  = "bgm_test:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font7, str, layer);
			drawstring(xPos2, yPos, font7, music, layer);
			
			str  = "level_select:";align = xPos1-strwidth(str, font0);
			yPos = yPos+yAdd;
			drawstring(align, yPos, font8, str, layer);
			drawstring(xPos2, yPos, font8, finished, layer);
		}
	}
}
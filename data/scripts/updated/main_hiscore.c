void defaultScore()
{//Restore default hi-score file
	int tier = 0;
	int add	 = 1;

	//RANK 1
	setglobalvar("hiscorePoints"+tier, 99999);
	setglobalvar("hiscoreTime"+tier, "01:18:24");
	setglobalvar("hiscoreKO"+tier, 71);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "YZL");
	setglobalvar("hiscoreIcon"+tier, "Kage");
	tier = tier+add;

	//RANK 2
	setglobalvar("hiscorePoints"+tier, 90000);
	setglobalvar("hiscoreTime"+tier, "00:57:24");
	setglobalvar("hiscoreKO"+tier, 72);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "YZL");
	setglobalvar("hiscoreIcon"+tier, "Bison");
	tier = tier+add;

	//RANK 3
	setglobalvar("hiscorePoints"+tier, 80000);
	setglobalvar("hiscoreTime"+tier, "01:05:11");
	setglobalvar("hiscoreKO"+tier, 79);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "YZL");
	setglobalvar("hiscoreIcon"+tier, "Max");
	tier = tier+add;

	//RANK 4
	setglobalvar("hiscorePoints"+tier, 70000);
	setglobalvar("hiscoreTime"+tier, "01:04:48");
	setglobalvar("hiscoreKO"+tier, 55);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "YZL");
	setglobalvar("hiscoreIcon"+tier, "Zan");
	tier = tier+add;

	//RANK 5
	setglobalvar("hiscorePoints"+tier, 60000);
	setglobalvar("hiscoreTime"+tier, "01:38:05");
	setglobalvar("hiscoreKO"+tier, 78);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "YZL");
	setglobalvar("hiscoreIcon"+tier, "Chunli");
	tier = tier+add;

	//RANK 6
	setglobalvar("hiscorePoints"+tier, 50000);
	setglobalvar("hiscoreTime"+tier, "01:41:06");
	setglobalvar("hiscoreKO"+tier, 78);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "BAQ");
	setglobalvar("hiscoreIcon"+tier, "Blaze");
	tier = tier+add;

	//RANK 7
	setglobalvar("hiscorePoints"+tier, 40000);
	setglobalvar("hiscoreTime"+tier, "01:06:44");
	setglobalvar("hiscoreKO"+tier, 81);
	setglobalvar("hiscoreDifficult"+tier, "mania#1");
	setglobalvar("hiscoreName"+tier, "BAQ");
	setglobalvar("hiscoreIcon"+tier, "Shiva_");
	tier = tier+add;

	//RANK 8
	setglobalvar("hiscorePoints"+tier, 30000);
	setglobalvar("hiscoreTime"+tier, "00:00:00");
	setglobalvar("hiscoreKO"+tier, 15);
	setglobalvar("hiscoreDifficult"+tier, "normal");
	setglobalvar("hiscoreName"+tier, "SOR");
	setglobalvar("hiscoreIcon"+tier, "Sammy");
	tier = tier+add;

	//RANK 9
	setglobalvar("hiscorePoints"+tier, 20000);
	setglobalvar("hiscoreTime"+tier, "00:00:00");
	setglobalvar("hiscoreKO"+tier, 10);
	setglobalvar("hiscoreDifficult"+tier, "normal");
	setglobalvar("hiscoreName"+tier, "SOR");
	setglobalvar("hiscoreIcon"+tier, "Axel");
	tier = tier+add;

	//RANK 10
	setglobalvar("hiscorePoints"+tier, 10000);
	setglobalvar("hiscoreTime"+tier, "00:00:00");
	setglobalvar("hiscoreKO"+tier, 5);
	setglobalvar("hiscoreDifficult"+tier, "normal");
	setglobalvar("hiscoreName"+tier, "SOR");
	setglobalvar("hiscoreIcon"+tier, "Blaze");
}

void loadS(void file, int tier)
{//Script to reduce code size
	int pos = 0;
	int add = 1;

	setglobalvar("hiscorePoints"+tier,		getfilestreamargument(file, pos, "int"));pos = pos+add;
	setglobalvar("hiscoreTime"+tier,		getfilestreamargument(file, pos, "string"));pos = pos+add;
	setglobalvar("hiscoreKO"+tier,			getfilestreamargument(file, pos, "int"));pos = pos+add;
	setglobalvar("hiscoreDifficult"+tier,	getfilestreamargument(file, pos, "string"));pos = pos+add;
	setglobalvar("hiscoreName"+tier,		getfilestreamargument(file, pos, "string"));pos = pos+add;
	setglobalvar("hiscoreIcon"+tier,		getfilestreamargument(file, pos, "string"));pos = 0;
	filestreamnextline(file);
}

void loadScore()
{//Load saved custom hi-score file or reset to default if the CFG file not exists

	if(getglobalvar("hiscorePoints0") == NULL()){

		//CONFIGURATION FILE EXISTIS?? GET ALL SAVED VALUES
		if(openfilestream("saves/SOR2X_HISCORE.cfg") != -1){
			void file = openfilestream("saves/SOR2X_HISCORE.cfg");
			int add  = 1;
			int tier = 0;

			//DEFINE ALL DATA TO BE LOADED
			loadS(file, tier);tier = tier+add; //RANK 1
			loadS(file, tier);tier = tier+add; //RANK 2
			loadS(file, tier);tier = tier+add; //RANK 3
			loadS(file, tier);tier = tier+add; //RANK 4
			loadS(file, tier);tier = tier+add; //RANK 5
			loadS(file, tier);tier = tier+add; //RANK 6
			loadS(file, tier);tier = tier+add; //RANK 7
			loadS(file, tier);tier = tier+add; //RANK 8
			loadS(file, tier);tier = tier+add; //RANK 9
			loadS(file, tier);//RANK 10
		}
		else
		{
			defaultScore(); //CONFIGURATION FILE NOT EXISTS?? APPLY DEFAULT VALUES
		}
	}
}

void saveS(void file, int tier, int newLine)
{//Script to reduce code size
	int add = 1;
	int pos = 0;

	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscorePoints"+tier), newLine);pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscoreTime"+tier), 1);pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscoreKO"+tier), 1);pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscoreDifficult"+tier), 1);pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscoreName"+tier), 1);pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("hiscoreIcon"+tier), 1);pos = 0;
	filestreamnextline(file);
}

void saveScore()
{//Save custom hi-score variables to a external file for load each time the game is started

	void file = createfilestream();
	int add   = 1;
	int tier  = 0;

	//DEFINE ALL DATA TO BE WRITEN
	saveS(file, tier, 1);tier = tier+add; //RANK 1
	saveS(file, tier, 0);tier = tier+add; //RANK 2
	saveS(file, tier, 0);tier = tier+add; //RANK 3
	saveS(file, tier, 0);tier = tier+add; //RANK 4
	saveS(file, tier, 0);tier = tier+add; //RANK 5
	saveS(file, tier, 0);tier = tier+add; //RANK 6
	saveS(file, tier, 0);tier = tier+add; //RANK 7
	saveS(file, tier, 0);tier = tier+add; //RANK 8
	saveS(file, tier, 0);tier = tier+add; //RANK 9
	saveS(file, tier, 0);tier = tier+add; //RANK 10

	//FILE CREATION TASK
	savefilestream(file, "SOR2X_HISCORE.cfg", "saves/");
	closefilestream(file);
}

void downTier(int oldTier, int newTier)
{//Script to reduce code size

	setglobalvar("hiscorePoints"+newTier,		getglobalvar("hiscorePoints"+oldTier));
	setglobalvar("hiscoreTime"+newTier,			getglobalvar("hiscoreTime"+oldTier));
	setglobalvar("hiscoreKO"+newTier,			getglobalvar("hiscoreKO"+oldTier));
	setglobalvar("hiscoreDifficult"+newTier,	getglobalvar("hiscoreDifficult"+oldTier));
	setglobalvar("hiscoreName"+newTier,			getglobalvar("hiscoreName"+oldTier));
	setglobalvar("hiscoreIcon"+newTier,			getglobalvar("hiscoreIcon"+oldTier));
}

void setScore(int player)
{//Set player before changing scores

	void icon = getplayerproperty(player, "name");
	void name = getglobalvar("rankName"+player);
	void diff = getglobalvar("difficult");
	void time = getglobalvar("totalPlayed");
	int score = getplayerproperty(player, "score");
	int ko    = getglobalvar("ko"+player);


	// add deathCount hash tag after difficult level
	int lifeCost = getglobalvar("lifeCost"+player);
	if(lifeCost != NULL()) {
		diff = diff+"#"+lifeCost;
	} else {
		diff = diff+"#1";
	}


	int tier;

	if(score >= getglobalvar("hiscorePoints0")){
		tier = 0;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);
		downTier(4, 5);
		downTier(3, 4);
		downTier(2, 3);
		downTier(1, 2);
		downTier(0, 1);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints0") && score >= getglobalvar("hiscorePoints1")){
		tier = 1;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);
		downTier(4, 5);
		downTier(3, 4);
		downTier(2, 3);
		downTier(1, 2);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints1") && score >= getglobalvar("hiscorePoints2")){
		tier = 2;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);
		downTier(4, 5);
		downTier(3, 4);
		downTier(2, 3);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints2") && score >= getglobalvar("hiscorePoints3")){
		tier = 3;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);
		downTier(4, 5);
		downTier(3, 4);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints3") && score >= getglobalvar("hiscorePoints4")){
		tier = 4;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);
		downTier(4, 5);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints4") && score >= getglobalvar("hiscorePoints5")){
		tier = 5;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);
		downTier(5, 6);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints5") && score >= getglobalvar("hiscorePoints6")){
		tier = 6;

		downTier(8, 9);
		downTier(7, 8);
		downTier(6, 7);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints6") && score >= getglobalvar("hiscorePoints7")){
		tier = 7;

		downTier(8, 9);
		downTier(7, 8);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints7") && score >= getglobalvar("hiscorePoints8")){
		tier = 8;

		downTier(8, 9);

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
	else
	if(score < getglobalvar("hiscorePoints8") && score >= getglobalvar("hiscorePoints9")){
		tier = 9;

		setglobalvar("hiscorePoints"+tier, score);
		setglobalvar("hiscoreTime"+tier, time);
		setglobalvar("hiscoreKO"+tier, ko);
		setglobalvar("hiscoreDifficult"+tier, diff);
		setglobalvar("hiscoreName"+tier, name);
		setglobalvar("hiscoreIcon"+tier, icon);
	}
}

void rankName(int player)
{//Draw and register the current player's custom name

	if(getglobalvar("letterA"+player) == NULL()){setglobalvar("letterA"+player, 0);}
	if(getglobalvar("letterB"+player) == NULL()){setglobalvar("letterB"+player, 0);}
	if(getglobalvar("letterC"+player) == NULL()){setglobalvar("letterC"+player, 0);}
	if(getglobalvar("position"+player) == NULL()){setglobalvar("position"+player, 0);}

	void letterA	= getglobalvar("letterA"+player);
	void letterB	= getglobalvar("letterB"+player);
	void letterC	= getglobalvar("letterC"+player);
	int position	= getglobalvar("position"+player);
	int xPos		= 25;	//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int yPos		= 4;	//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int xAdd		= 1;	//DEFAULT X DIFFERENCE BETWEEN LETTERS
	int xDif		= 120;	//DEFAULT X DIFFERENCE BETWEEN COLUMNS
	int font0		= 0;
	int font1		= 1;
	int layer		= 1000000005;
	int xMult		= 63;	//USED TO ADJUST SMOOTHLY THE SPACE BETWEEM SOME LETTERS
	float limit		= 10;
	float time		= openborvariant("elapsed_time")/20;

	xDif = player*xDif;

	//TRANSLATE THE FIRST LETTER
		if(letterA == 0){letterA = "a";}
		if(letterA == 1){letterA = "b";}
		if(letterA == 2){letterA = "c";}
		if(letterA == 3){letterA = "d";}
		if(letterA == 4){letterA = "e";}
		if(letterA == 5){letterA = "f";}
		if(letterA == 6){letterA = "g";}
		if(letterA == 7){letterA = "h";}
		if(letterA == 8){letterA = "i";}
		if(letterA == 9){letterA = "j";}
		if(letterA == 10){letterA = "k";}
		if(letterA == 11){letterA = "l";}
		if(letterA == 12){letterA = "m";}
		if(letterA == 13){letterA = "n";}
		if(letterA == 14){letterA = "o";}
		if(letterA == 15){letterA = "p";}
		if(letterA == 16){letterA = "q";}
		if(letterA == 17){letterA = "r";}
		if(letterA == 18){letterA = "s";}
		if(letterA == 19){letterA = "t";}
		if(letterA == 20){letterA = "u";}
		if(letterA == 21){letterA = "v";}
		if(letterA == 22){letterA = "w";}
		if(letterA == 23){letterA = "x";}
		if(letterA == 24){letterA = "y";}
		if(letterA == 25){letterA = "z";}

		//TRANSLATE THE SECOND LETTER
		if(letterB == 0){letterB = "a";}
		if(letterB == 1){letterB = "b";}
		if(letterB == 2){letterB = "c";}
		if(letterB == 3){letterB = "d";}
		if(letterB == 4){letterB = "e";}
		if(letterB == 5){letterB = "f";}
		if(letterB == 6){letterB = "g";}
		if(letterB == 7){letterB = "h";}
		if(letterB == 8){letterB = "i";}
		if(letterB == 9){letterB = "j";}
		if(letterB == 10){letterB = "k";}
		if(letterB == 11){letterB = "l";}
		if(letterB == 12){letterB = "m";}
		if(letterB == 13){letterB = "n";}
		if(letterB == 14){letterB = "o";}
		if(letterB == 15){letterB = "p";}
		if(letterB == 16){letterB = "q";}
		if(letterB == 17){letterB = "r";}
		if(letterB == 18){letterB = "s";}
		if(letterB == 19){letterB = "t";}
		if(letterB == 20){letterB = "u";}
		if(letterB == 21){letterB = "v";}
		if(letterB == 22){letterB = "w";}
		if(letterB == 23){letterB = "x";}
		if(letterB == 24){letterB = "y";}
		if(letterB == 25){letterB = "z";}

		//TRANSLATE THE THIRD LETTER
		if(letterC == 0){letterC = "a";}
		if(letterC == 1){letterC = "b";}
		if(letterC == 2){letterC = "c";}
		if(letterC == 3){letterC = "d";}
		if(letterC == 4){letterC = "e";}
		if(letterC == 5){letterC = "f";}
		if(letterC == 6){letterC = "g";}
		if(letterC == 7){letterC = "h";}
		if(letterC == 8){letterC = "i";}
		if(letterC == 9){letterC = "j";}
		if(letterC == 10){letterC = "k";}
		if(letterC == 11){letterC = "l";}
		if(letterC == 12){letterC = "m";}
		if(letterC == 13){letterC = "n";}
		if(letterC == 14){letterC = "o";}
		if(letterC == 15){letterC = "p";}
		if(letterC == 16){letterC = "q";}
		if(letterC == 17){letterC = "r";}
		if(letterC == 18){letterC = "s";}
		if(letterC == 19){letterC = "t";}
		if(letterC == 20){letterC = "u";}
		if(letterC == 21){letterC = "v";}
		if(letterC == 22){letterC = "w";}
		if(letterC == 23){letterC = "x";}
		if(letterC == 24){letterC = "y";}
		if(letterC == 25){letterC = "z";}

	if(getglobalvar("nameEntered"+player) == NULL()){
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ANYBUTTON"));
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ANYBUTTON"));
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ANYBUTTON"));
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ANYBUTTON"));

		if(position == 0){ //FIRST POSITION
			if(time%2 == 0){letterA = "";}
			letterB = "";
			letterC = "";
			setglobalvar("rankName"+player, ""+letterA+letterB+letterC);
			drawstring(xPos+xDif, yPos, font0, "name", layer);
			drawstring(xPos+xDif+xAdd*xMult, yPos, font0, "&", layer);
			drawstring(xPos+xDif+strwidth("name__", font0), yPos, font0, ""+letterA+letterB+letterC, layer);
		}
		else
		if(position == 1){ //SECOND POSITION
			if(time%2 == 0){letterB = "";}
			letterC = "";
			setglobalvar("rankName"+player, ""+letterA+letterB+letterC);
			drawstring(xPos+xDif, yPos, font0, "name", layer);
			drawstring(xPos+xDif+xAdd*xMult, yPos, font0, "&", layer);
			drawstring(xPos+xDif+strwidth("name__", font0), yPos, font0, ""+letterA+letterB+letterC, layer);
		}
		else
		if(position == 2){ //THIRD POSITION
			if(time%2 == 0){letterC = "";}
			setglobalvar("rankName"+player, ""+letterA+letterB+letterC);
			drawstring(xPos+xDif, yPos, font0, "name", layer);
			drawstring(xPos+xDif+xAdd*xMult, yPos, font0, "&", layer);
			drawstring(xPos+xDif+strwidth("name__", font0), yPos, font0, ""+letterA+letterB+letterC, layer);
		}
		else //NAME COMPLETELY ENTERED
		{
			setglobalvar("rankName"+player, ""+letterA+letterB+letterC);
			drawstring(xPos+xDif, yPos, font0, "name", layer);
			drawstring(xPos+xDif+xAdd*xMult, yPos, font0, "&", layer);
			drawstring(xPos+xDif+strwidth("name__", font0), yPos, font0, ""+letterA+letterB+letterC, layer);
			setglobalvar("nameEntered"+player, time+limit);
		}
	}
	else
	{
		if(time < getglobalvar("nameEntered"+player)){
			time = openborvariant("elapsed_time")/8;

			if(time%2 == 0){
				drawstring(xPos+xDif+xAdd*xMult, yPos, font1, "&", layer);
			}
			drawstring(xPos+xDif, yPos, font0, "name", layer);
			drawstring(xPos+xDif+strwidth("name__", font0), yPos, font0, ""+letterA+letterB+letterC, layer);

			if(getglobalvar("changedScore"+player) == NULL()){
				setScore(player);
				changeplayerproperty(0, "disablekeys", 0);
				changeplayerproperty(1, "disablekeys", 0);
				changeplayerproperty(2, "disablekeys", 0);
				changeplayerproperty(3, "disablekeys", 0);
				setglobalvar("changedScore"+player, 1);
			}
		}
	}
}

void changeScore(int player)
{//Save a custom hi-score when the entire game is completed, works only at the ending scenes
	int hasplayed	= getplayerproperty(player, "hasplayed");
	int score		= getplayerproperty(player, "score");
	float time		= openborvariant("elapsed_time");
	float limit		= 24000;

	//START TIME COUNTDOWN
	if(getglobalvar("nameTimer") == NULL()){setglobalvar("nameTimer", time+limit);}

	//TIMER REACHED THE LIMIT??
	if(time > getglobalvar("nameTimer")){

		//RE-ENABLE ALL KEYS
		changeplayerproperty(0, "disablekeys", 0);
		changeplayerproperty(1, "disablekeys", 0);
		changeplayerproperty(2, "disablekeys", 0);
		changeplayerproperty(3, "disablekeys", 0);
	}
	else //EXECUTE ALL TASKS RELATED TO THE RANK NAME REGISTRATION
	{
		if(score >= getglobalvar("hiscorePoints9")){rankName(player);}
	}
}

void drawScore()
{//Draw a custom hi-score screen
	void str;
	int align;
	int tier;
	int width;
	int adjust = 100;
	int xPos   = 70; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int yPos   = 35;			//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int xAdd   = 10;			//DEFAULT X DIFFERENCE BETWEEN COLUMNS
	int yAdd   = 15;			//DEFAULT Y DIFFERENCE BETWEEN LINES
	int tAdd   = 1;				//DIFFERENCE BETWEEN EACH TIER
	int title  = yAdd*3;		//DEFAULT TITLE SPACE BETWEEN ALL OTHER CONTENT
	int column = xPos;			//DEFAULT COLUMN VALUE
	int line   = yPos;			//DEFAULT LINE VALUE
	int icon   = 20;			//DEFAULT LINE VALUE FOR ICON ADJUSTMENTS
	int layer0 = 1000000001;	//BACKGROUND LAYER VALUE
	int layer1 = 1000000002;	//TEXT LAYER VALUE
	int font0  = 0;
	int font1  = 1;
	int font2  = 2;
	int font3  = 7;
	float hRes = openborvariant("hresolution");

	//DRAW CONTENT
	//BACKGROUND
	setdrawmethod(NULL(),0,256,256,0,0,0,0);
	drawsprite(getglobalvar("back3"), 0, 0, layer0);

	//TITLE
	drawstring((hRes-strwidth("HI-SCORES", font3))/2+1, line, font3, "HI-SCORES", layer1);line = yPos+title;

	//COLUMN 1 - TIER NUMBER
	str = "rank";align = column-strwidth(str, font2);
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;

	//RANK 1
	tier = 1;str = tier+"st";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "st";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 2
	tier = tier+tAdd;str = tier+"nd";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "nd";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 3
	tier = tier+tAdd;str = tier+"rd";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "rd";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 4
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 5
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 6
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 7
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 8
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 9
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = line+yAdd;

	//RANK 10
	tier = tier+tAdd;str = tier+"th";align = column-strwidth(str, font0);
	drawstring(align, line, font1, str, layer1);
	str = "th";align = column-strwidth(str, font0);
	drawstring(align, line, font0, str, layer1+1);line = yPos+title;

	//COLUMN 2 - PLAYER SCORE
	column = column+xAdd*2.5;
	str = "score";align = column;
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;
	tier = 0;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscorePoints"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = yPos+title;

	//COLUMN 3 - TIME PLAYED
	column = column+xAdd*8;
	str = "time";align = column;
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;
	tier = 0;str = ""+getglobalvar("hiscoreTime"+tier);align = column;
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreTime"+tier);
	drawstring(align, line, font0, str, layer1);line = yPos+title;

	//COLUMN 4 - TOTAL K.O.
	column = column+xAdd*8;
	str = "k.o.";align = column;
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;
	tier = 0;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreKO"+tier);
	drawstring(align, line, font0, str, layer1);line = yPos+title;

	//COLUMN 5 - DIFFICULT
	column = column+xAdd*5;
	str = "difficult";align = column;
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;
	tier = 0;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreDifficult"+tier);
	drawstring(align, line, font0, str, layer1);line = yPos+title;

	//COLUMN 6 - CHARACTER'S NAME
	column = column+xAdd*9;
	str = "player";align = column;
	drawstring(align, line, font2, str, layer1);line = line+yAdd*1.5;
	tier = 0;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = line+yAdd;
	tier = tier+1;str = ""+getglobalvar("hiscoreName"+tier);
	drawstring(align, line, font0, str, layer1);line = yPos+title;

	//COLUMN 7 - CHARACTER'S ICON
	align = column+xAdd*3.3;line = line+icon;

	//RANK 1
	tier = 0;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 2
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 3
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 4
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 5
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 6
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 7
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 8
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 9
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;

	//RANK 10
	tier = tier+1;
	if(getglobalvar("icon"+tier) != NULL()){free(getglobalvar("icon"+tier));setglobalvar("icon"+tier, NULL());}
	if(getglobalvar("icon"+tier) == NULL()){
		setglobalvar("icon"+tier, loadsprite("data/sprites/icons/"+getglobalvar("hiscoreIcon"+tier)+".png"));
	}
	drawsprite(getglobalvar("icon"+tier), align, line, layer1);line = line+yAdd;
}
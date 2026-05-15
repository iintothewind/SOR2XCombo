#import "data/scripts/levelspawn/main_musicmisc.c"

void scenePlay()
{//Play all cutscenes content, used to replace the webm version
	float hRes = openborvariant("hResolution");

	//INTRO SCENE
	if(openborvariant("current_scene") == "data/scenes/intro.txt"){
		sceneIntro();
	}
	if(openborvariant("in_titlescreen") || openborvariant("in_menuscreen")){

		//USED TO MAKE A "FULL RESET" ON ITENS USED BY THE INTRO SCENE
		if(getlocalvar("delay") != NULL()){
			if(getlocalvar("blackFade") != NULL()){		free(getlocalvar("blackFade"));}
			if(getlocalvar("portrait") != NULL()){		free(getlocalvar("portrait"));}
			if(getlocalvar("cityStatic") != NULL()){	free(getlocalvar("cityStatic"));}
			if(getlocalvar("cityLights") != NULL()){	free(getlocalvar("cityLights"));}
			if(getlocalvar("handLeft") != NULL()){		free(getlocalvar("handLeft"));}
			if(getlocalvar("handRight") != NULL()){		free(getlocalvar("handRight"));}
			if(getlocalvar("headFade") != NULL()){		free(getlocalvar("headFade"));}
			if(getlocalvar("headStatic") != NULL()){	free(getlocalvar("headStatic"));}
			if(getlocalvar("sprite0") != NULL()){		free(getlocalvar("sprite0"));}
			if(getlocalvar("sprite1") != NULL()){		free(getlocalvar("sprite1"));}
			if(getlocalvar("sprite2") != NULL()){		free(getlocalvar("sprite2"));}
			if(getlocalvar("sprite3") != NULL()){		free(getlocalvar("sprite3"));}
			if(getlocalvar("sprite4") != NULL()){		free(getlocalvar("sprite4"));}
			if(getlocalvar("sprite5") != NULL()){		free(getlocalvar("sprite5"));}
			if(getlocalvar("sprite6") != NULL()){		free(getlocalvar("sprite6"));}
			playmusic("data/music/empty.ogg", 0);		//USED TO PAUSE MUSICS DUE TO THE "PAUSEMISC" FUNCTION NOT WORKING
			changedrawmethod(NULL(), "reset", 1);		//USED TO REST ALL DRAWMETHOD SETTINGS
			changedrawmethod(NULL(), "enabled", 1);		//USED TO REST ALL DRAWMETHOD SETTINGS
			clearlocalvar();							//USED TO CLEAR ALL LOCAL VARIABLES
		}
	}

	//ENDING SCENES
	void scene;

	if(openborvariant("current_scene") == "data/scenes/ending_a.txt"){scene = "ending_a";}else
	if(openborvariant("current_scene") == "data/scenes/ending_b.txt"){scene = "ending_b";}else
	if(openborvariant("current_scene") == "data/scenes/ending_c.txt"){scene = "ending_c";}

	if(openborvariant("current_scene") == "data/scenes/"+scene+".txt"){
		void counter = getlocalvar("endingCounter");
		while(counter != 1){
			void subent;
			clearspawnentry();
			setspawnentry("name", scene);
			subent = spawn();
			changeentityproperty(subent, "position", 0, 0, 0);
			changeentityproperty(subent, "direction", 1);
			musicEnding(scene);
			counter = setlocalvar("endingCounter", 1);
		}
	}

	//GAME OVER SCENE
	if(openborvariant("current_scene") == "data/scenes/gameover.txt"){
		void counter = getlocalvar("gameOver");
		while(counter != 1){musicGameover();counter = setlocalvar("gameOver", 1);}
		drawstring((hRes-(strwidth("GAME_OVER", 7)-1))/2, 129, 7, "GAME_OVER", 1001);
	}
}

void sceneIntro()
{//Main script to play all Intro scene content
	void str;			//DEFINED STRING FOR THE CURRENT TEXT LINE
	int yPos;			//BASE Y POSITION FOR ALL TEXT
	int yAdd	= 15;	//SPACE BETWEEN TEXT LINES
	float hRes	= openborvariant("hResolution");

	//BELOW IS ALL TEXT TO EASY EDITION
	void text0 	= "ONE YEAR AFTER THE BATTLE...";
	void text1 	= "THE CITY THAT HAD BEEN PLAGUED";
	void text2 	= "WITH CRIME AND VIOLENCE WAS";
	void text3 	= "SAFE AND PEACEFUL.";
	void text4 	= "HOWEVER, EVIL HAS ONCE AGAIN";
	void text5 	= "CAST ITS SHADOW OVER THE CITY.";
	void text6 	= "MR. X, THE SYNDICATE BOSS";
	void text7 	= "BELIEVED DESTROYED BY THE";
	void text8 	= "THREE YOUNG VIGILANTES, HAS";
	void text9 	= "COME BACK TO LIFE STRONG";
	void text10 = "THAN EVER.";
	void text11 = "THIRSTY FOR REVENGE, HE";
	void text12 = "KIDNAPS ADAM IN A ATTEMPT TO";
	void text13 = "LURE AXEL AND BLAZE INTO A";
	void text14 = "TRAP!";
	void text15 = "AXEL AND BLAZE SET OUT TO HELP";
	void text16 = "THEIR FAITHFUL COMPANION, JOINED";
	void text17 = "BY AXEL'S FRIEND MAX, A WRESTLER,";
	void text18 = "AND ADAM'S KID BROTHER, SKATE.";
	void text19 = "THEY'RE DETERMINED TO SAVE ADAM";
	void text20 = "AND PUT MR. X OUT OF ACTION!";
	void text21 = "FOUR YOUNG FRIENDS, RAGE BURNING";
	void text22 = "INSIDE THEM, MAKE A STAND FOR,";
	void text23 = "FRIENDSHIP AND PEACE...";

	//SAVE ALL VARIABLES
	if(getlocalvar("delay") == NULL()){

		//STATIC SPRITES
		setlocalvar("portrait", loadsprite("data/scenes/intro/portrait00.png"));
		setlocalvar("cityStatic", loadsprite("data/scenes/intro/city00.png"));
		setlocalvar("headStatic", loadsprite("data/scenes/intro/head00.png"));

		//INTRO MUSIC
		musicIntro();

		//START DELAY VARIABLE
		setlocalvar("delay", openborvariant("elapsed_time"));

		//START FRAME VARIABLE
		setlocalvar("frame", 0);
	}

	//SHOW CURRENT FRAME, USED FOR DEBUG PURPOSE ONLY
	//drawstring(50, 50, 0, getlocalvar("frame"));

	//ALL STEPS
	if(getlocalvar("frame") == 0){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //FIRST PORTRAIT AND FADE-IN

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeIn("blackFade", "data/scenes/intro/fade.png", 0, 0, 0, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("portrait"), 0, 0, 1000000004);

	}
	else
	if(getlocalvar("frame") == 1){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //PORTRAIT AND TEXT PART 1

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeIn("blackFade", "data/scenes/intro/fade.png", 1, 0, 200, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("portrait"), 0, 0, 1000000004);

		//TEXTS
		str = text0;drawstring((hRes-(strwidth(str, 0)-1))/2, 210, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 2){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //PORTRAIT AND TEXT PART 1 FADE-OUT

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("blackFade", "data/scenes/intro/fade.png", 2, 0, 0, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("portrait"), 0, 0, 1000000004);

		//TEXTS
		str = text0;drawstring((hRes-(strwidth(str, 0)-1))/2, 210, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 3){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //FIRST CITY AND FADE-IN

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeIn("blackFade", "data/scenes/intro/fade.png", 3, 0, 0, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);
	}
	else
	if(getlocalvar("frame") == 4){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY AND TEXT PART 2

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeIn("blackFade", "data/scenes/intro/fade.png", 4, 0, -150, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//TEXTS
		yPos = 40;str = text1;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text2;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text3;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 5){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY AND TEXT PART 2, FADE-OUT

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("blackFade", "data/scenes/intro/fade.png", 5, 0, -150, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//TEXTS
		yPos = 40;str = text1;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text2;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text3;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 6){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 100){ //CITY WAITING

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);
	}
	else
	if(getlocalvar("frame") == 7){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY AND TEXT PART 3, FADE-IN

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeIn("blackFade", "data/scenes/intro/fade.png", 6, 0, -150, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//TEXTS
		yPos = 40;str = text4;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text5;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 8){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY AND TEXT PART 3 WAITING, MOVE HANDS

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		changedrawmethod(NULL(), "enabled", 0);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//TEXTS
		yPos = 40;str = text4;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text5;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 9){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY AND TEXT PART 3 FADE-OUT, MOVE HANDS

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("blackFade", "data/scenes/intro/fade.png", 7, 0, -175, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//TEXTS
		yPos = 40;str = text4;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text5;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 10){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 200){ //CITY WAITING, STOP HANDS

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		changedrawmethod(NULL(), "enabled", 0);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);
	}
	else
	if(getlocalvar("frame") == 11){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //CITY WAITING, HEAD FADE-OUT

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("headFade", "data/scenes/intro/head00.png", 8, 0, 0, 1000000100, 1);
		changedrawmethod(NULL(), "enabled", 0);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);
	}
	else
	if(getlocalvar("frame") == 12){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 500){ //CITY WAITING, HEAD WAITING, CYCLE BACKGROUND SPRITES, SCROLLING TEXT

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		changedrawmethod(NULL(), "enabled", 0);
		cycleSprite(0, 0, 1000000002, 30);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		drawsprite(getlocalvar("headStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//START Y MOVING VARIABLE FOR TEXT SCROLLING
		float yStart	= 300;	//Y STARTING POSITION
		float yStop		= 590;	//Y POSITION LIMIT WHERE THE TEXT STOP SCROLLING
		float yVel 		= 12;	//SCROLLING TEXT VELOCITY
		float yLimit	= 125;	//Y POSITION LIMIT BEFORE THE TEXT DISAPPEARS
		float time		= openborvariant("elapsed_time")/yVel;

		if(getlocalvar("yTime") == NULL()){setlocalvar("yTime", time);}
		if(getlocalvar("yMove") == NULL()){setlocalvar("yMove", 0);}

		//SCROLLING TEXT PART 1
		yPos = yStart-getlocalvar("yMove");str = text6;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text7;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text8;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text9;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text10;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}

		//SCROLLING TEXT PART 2
		yPos = yPos+yAdd*5;str = text11;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text12;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text13;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text14;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}

		//SCROLLING TEXT PART 3
		yPos = yPos+yAdd*5;str = text15;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text16;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text17;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text18;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text19;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}
		yPos = yPos+yAdd;str = text20;
		if(yPos > yLimit){drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);}

		//SCROLLING TEXT FINAL PART
		yPos = yPos+yAdd*5;str = text21;setlocalvar("yLast", yPos);
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text22;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text23;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);

		//REACHED THE MOVING LIMIT?? STOPPING SCROLLING TEXT
		if(getlocalvar("yMove") < yStop){setlocalvar("yMove", time - getlocalvar("yTime"));}
	}
	else
	if(getlocalvar("frame") == 13){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //ALL FADE-OUT, MAINTAIN ONLY HISTORY 3

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("blackFade", "data/scenes/intro/fade.png", 9, 0, 0, 1000000100, 0.25);
		changedrawmethod(NULL(), "enabled", 0);
		cycleSprite(0, 0, 1000000002, 30);
		moveSprite("handLeft", "data/scenes/intro/hand00.png", -200, 0, 1, 1000000005);
		moveSprite("handRight", "data/scenes/intro/hand01.png", 200, 0, 0, 1000000005);
		drawsprite(getlocalvar("cityStatic"), 0, 0, 1000000004);
		drawsprite(getlocalvar("headStatic"), 0, 0, 1000000004);
		blinkSprite("cityLights", "data/scenes/intro/city01.png", 0, 0, 1000000004, 0.5);

		//SCROLLING TEXT FINAL PART
		yPos = getlocalvar("yLast");str = text21;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text22;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text23;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
	}
	else
	if(getlocalvar("frame") == 14){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 300){ //MAINTAIN ONLY HISTORY 3

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SCROLLING TEXT FINAL PART
		yPos = getlocalvar("yLast");str = text21;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text22;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
		yPos = yPos+yAdd;str = text23;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1000000010);
	}
	else
	if(getlocalvar("frame") == 15){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 210){ //ALL FADE-OUT

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);
		}

		//SPRITES
		fadeOut("blackFade", "data/scenes/intro/fade.png", 10, 0, 0, 1000000100, 2);

		//SCROLLING TEXT FINAL PART
		yPos = getlocalvar("yLast");str = text21;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text22;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
		yPos = yPos+yAdd;str = text23;
		drawstring((hRes-(strwidth(str, 0)-1))/2, yPos, 0, str, 1001);
	}
	else
	if(getlocalvar("frame") == 16){
		if(openborvariant("elapsed_time") - getlocalvar("delay") > 10){ //FINISH

			//DELAY COUNTER
			setlocalvar("delay", openborvariant("elapsed_time"));
			setlocalvar("frame", getlocalvar("frame")+1);

			//PLAY WEBM SCENE
			playwebm("data/scenes/intro.webm");
		}
	}
}

void fadeIn(void varName, void sprite, int index, int x, int y, int layer, float speed)
{//Apply fade-in effect using a black image
	float rate  = 100;
	float limit = 0;
	float time  = openborvariant("elapsed_time")/rate;
	float add;

	//START ALL VARIABLES
	if(getlocalvar(varName) == NULL()){setlocalvar(varName, loadsprite(sprite));}
	if(getlocalvar("channel"+index) == NULL()){setlocalvar("channel"+index, 254);}
	if(getlocalvar("startFadeIn"+index) == NULL()){setlocalvar("startFadeIn"+index, time);}

	//EXECUTE ALL TASKS
	if(getlocalvar("channel"+index) > limit){ //CHANNEL DIDN'T REACHED THE LIMIT?? APPLY EFFECTS
		changedrawmethod(NULL(), "enabled", 1);
		changedrawmethod(NULL(), "alpha", 6);
		changedrawmethod(NULL(), "tintmode", 0);
		changedrawmethod(NULL(), "channelr", getlocalvar("channel"+index));
		changedrawmethod(NULL(), "channelg", getlocalvar("channel"+index));
		changedrawmethod(NULL(), "channelb", getlocalvar("channel"+index));
		drawsprite(getlocalvar(varName), x, y, layer);
		add = (time - getlocalvar("startFadeIn"+index))*speed;
		setlocalvar("channel"+index, getlocalvar("channel"+index)-add);
	}
	else
	{
		changedrawmethod(NULL(), "enabled", 1);
		changedrawmethod(NULL(), "alpha", 6);
		changedrawmethod(NULL(), "tintmode", 0);
		changedrawmethod(NULL(), "channelr", limit);
		changedrawmethod(NULL(), "channelg", limit);
		changedrawmethod(NULL(), "channelb", limit);
		drawsprite(getlocalvar(varName), x, y, layer);
	}
}

void fadeOut(void varName, void sprite, int index, int x, int y, int layer, float speed)
{//Apply fade-out effect using a black image
	float rate  = 100;
	float limit = 254;
	float time  = openborvariant("elapsed_time")/rate;
	float add;

	//START ALL VARIABLES
	if(getlocalvar(varName) == NULL()){setlocalvar(varName, loadsprite(sprite));}
	if(getlocalvar("channel"+index) == NULL()){setlocalvar("channel"+index, 0);}
	if(getlocalvar("startFadeOut"+index) == NULL()){setlocalvar("startFadeOut"+index, time);}

	//EXECUTE ALL TASKS
	if(getlocalvar("channel"+index) < limit){ //CHANNEL DIDN'T REACHED THE LIMIT?? APPLY EFFECTS
		changedrawmethod(NULL(), "enabled", 1);
		changedrawmethod(NULL(), "alpha", 6);
		changedrawmethod(NULL(), "tintmode", 0);
		changedrawmethod(NULL(), "channelr", getlocalvar("channel"+index));
		changedrawmethod(NULL(), "channelg", getlocalvar("channel"+index));
		changedrawmethod(NULL(), "channelb", getlocalvar("channel"+index));
		drawsprite(getlocalvar(varName), x, y, layer);
		add = (time - getlocalvar("startFadeOut"+index))*speed;
		setlocalvar("channel"+index, getlocalvar("channel"+index)+add);
	}
	else
	{
		changedrawmethod(NULL(), "enabled", 1);
		changedrawmethod(NULL(), "alpha", 6);
		changedrawmethod(NULL(), "tintmode", 0);
		changedrawmethod(NULL(), "channelr", limit);
		changedrawmethod(NULL(), "channelg", limit);
		changedrawmethod(NULL(), "channelb", limit);
		drawsprite(getlocalvar(varName), x, y, layer);
	}
}

void blinkSprite(void varName, void sprite, int x, int y, int layer, float rate)
{//Apply blinking effects to sprites

	//START ALL VARIABLES
	if(getlocalvar(varName) == NULL()){setlocalvar(varName, loadsprite(sprite));}

	//EXECUTE ALL TASKS
	float time	 = openborvariant("elapsed_time");
	int tintMode = 2;

	changedrawmethod(NULL(), "enabled", 1);
	changedrawmethod(NULL(), "alpha", 0);
	changedrawmethod(NULL(), "tintmode", tintMode);
	changedrawmethod(NULL(), "tintcolor", rgbcolor(time*rate, time*rate, time*rate));
	drawsprite(getlocalvar(varName), x, y, layer);
}

void moveSprite(void varName, void sprite, int x, int y, int dir, int layer)
{//Apply movement to sprites
	float xVel  = 5;
	float limit = 205;
	float time  = openborvariant("elapsed_time")/xVel;

	//START ALL VARIABLES
	if(getlocalvar(varName) == NULL()){setlocalvar(varName, loadsprite(sprite));}
	if(getlocalvar("startMove") == NULL()){setlocalvar("startMove", time);}

	//EXECUTE ALL TASKS
	if(time - getlocalvar("startMove") < limit){
		if(dir == 1){ //MOVING
			setlocalvar("xDir"+varName, (x+time-getlocalvar("startMove")));
			drawsprite(getlocalvar(varName), getlocalvar("xDir"+varName), y, layer);
		}

		if(dir == 0){ //MOVING
			setlocalvar("xDir"+varName, (x+getlocalvar("startMove")-time));
			drawsprite(getlocalvar(varName), getlocalvar("xDir"+varName), y, layer);
		}
	}
	else
	{
		drawsprite(getlocalvar(varName), getlocalvar("xDir"+varName), y, layer);
	}
}

void cycleSprite(int x, int y, int layer, int rate)
{//Apply sprite cycling

	//START ALL VARIABLES
	if(getlocalvar("sprite0") == NULL()){setlocalvar("sprite0", loadsprite("data/scenes/intro/back00.png"));}
	if(getlocalvar("sprite1") == NULL()){setlocalvar("sprite1", loadsprite("data/scenes/intro/back01.png"));}
	if(getlocalvar("sprite2") == NULL()){setlocalvar("sprite2", loadsprite("data/scenes/intro/back02.png"));}
	if(getlocalvar("sprite3") == NULL()){setlocalvar("sprite3", loadsprite("data/scenes/intro/back03.png"));}
	if(getlocalvar("sprite4") == NULL()){setlocalvar("sprite4", loadsprite("data/scenes/intro/back04.png"));}
	if(getlocalvar("sprite5") == NULL()){setlocalvar("sprite5", loadsprite("data/scenes/intro/back05.png"));}
	if(getlocalvar("sprite6") == NULL()){setlocalvar("sprite6", loadsprite("data/scenes/intro/back06.png"));}
	if(getlocalvar("currentSprite") == NULL()){setlocalvar("currentSprite", 0);}
	if(getlocalvar("cycleDelay") == NULL()){setlocalvar("cycleDelay", openborvariant("elapsed_time"));}

	//EXECUTE ALL TASKS
	if(openborvariant("elapsed_time") < getlocalvar("cycleDelay") + rate){
		drawsprite(getlocalvar("sprite"+getlocalvar("currentSprite")), x, y, layer);
	}
	else
	{
		drawsprite(getlocalvar("sprite"+getlocalvar("currentSprite")), x, y, layer);

		//CYCLE SPRITES
		if(getlocalvar("currentSprite") < 6){
			setlocalvar("currentSprite", getlocalvar("currentSprite")+1);
			setlocalvar("cycleDelay", openborvariant("elapsed_time"));
		}
		else
		{
			setlocalvar("currentSprite", 0);
			setlocalvar("cycleDelay", openborvariant("elapsed_time"));
		}
	}
}
#import "data/scripts/levelspawn/main_musicmisc.c"

void completeScreen()
{//Draw title and player number in "Stage Complete"
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	float hRes   = openborvariant("hresolution");
	int set 	 = openborvariant("current_set");
	int stage 	 = openborvariant("current_stage");
	int font0  	 = 7;
	int font1  	 = 9;
	int layer 	 = 100000003;
	int xPos	 = 182;
	int xDif	 = 60;
	int yPos	 = 88;
	int yTitle	 = 55;

	if(set == 0 || set == 2){
		drawstring((hRes-strwidth("STAGE__"+stage+"__COMPLETE", font0))/2+1, yTitle, font0, "STAGE__"+stage+"__COMPLETE", layer);
		if(player1 != NULL()){drawstring(xPos, yPos, font1, "P");}
		xPos = xPos+xDif;
		if(player2 != NULL()){drawstring(xPos, yPos, font1, "Q");}
		xPos = xPos+xDif;
		if(player3 != NULL()){drawstring(xPos, yPos, font1, "R");}
		xPos = xPos+xDif;
		if(player4 != NULL()){drawstring(xPos, yPos, font1, "S");}
	}

	if(set == 1){
		drawstring((hRes-strwidth("SURVIVAL__COMPLETE", font0))/2+1, yTitle, font0, "SURVIVAL__COMPLETE", layer);
		if(player1 != NULL()){drawstring(xPos, yPos, font1, "P");}
		xPos = xPos+xDif;
		if(player2 != NULL()){drawstring(xPos, yPos, font1, "Q");}
		xPos = xPos+xDif;
		if(player3 != NULL()){drawstring(xPos, yPos, font1, "R");}
		xPos = xPos+xDif;
		if(player4 != NULL()){drawstring(xPos, yPos, font1, "S");}
	}

	//USED TO RE-ENABLE KEYS AND PLAY MUSIC ONCE
	void counter = getlocalvar("completeCounter");
	while(counter != 1){
		changeplayerproperty(0, "disablekeys", 0);
		changeplayerproperty(1, "disablekeys", 0);
		changeplayerproperty(2, "disablekeys", 0);
		changeplayerproperty(3, "disablekeys", 0);
		musicComplete();
		setglobalvar("partnerFull", 1);
		setglobalvar("playedCounter", openborvariant("elapsed_time"));
		counter = setlocalvar("completeCounter", 1);
	}

	//INCREASE SCORE SPEED
	if(	getplayerproperty(0, "playkeys") > 0 ||
		getplayerproperty(1, "playkeys") > 0 ||
		getplayerproperty(2, "playkeys") > 0 ||
		getplayerproperty(3, "playkeys") > 0 ){ //HOLD BUTTON
		changeopenborvariant("elapsed_time", openborvariant("elapsed_time")+50); //TIME TRAVEL :)
	}
}

void resetMaxRush()
{//Reset max rush counter in "Stage Complete" screen
	void player1 = getplayerproperty(0, "entity"); //IDENTIFY PLAYER 1
	void player2 = getplayerproperty(1, "entity"); //IDENTIFY PLAYER 2
	void player3 = getplayerproperty(2, "entity"); //IDENTIFY PLAYER 3
	void player4 = getplayerproperty(3, "entity"); //IDENTIFY PLAYER 4

	//IS PLAYER PLAYING THE GAME?? RESET PLAYER MAX RUSH COUNT SAVED VALUE TO ZERO
	if(player1 != NULL()){setglobalvar("maxRush1", 0);}
	if(player2 != NULL()){setglobalvar("maxRush2", 0);}
	if(player3 != NULL()){setglobalvar("maxRush3", 0);}
	if(player4 != NULL()){setglobalvar("maxRush4", 0);}
}
#import "data/scripts/levelspawn/main_level.c"

void main()
{
	changeBranch();
	savePartner();
	saveMaxRush();
	saveAllMp();
	sor3_st6();
	debugMode();
}

void changeBranch()
{//Go to defined branch in levels that have optional rooms or routes (SOR3_ST6A/SOR3_ST8A)

	if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2){ //ARCADE/REBELLION MODES
		if(getglobalvar("levelName") == "sor2_st1a"){
			if(	openborvariant("current_branch") == "sor2_st3g"){jumptobranch("sor2_st4a", 1);}
			if(	openborvariant("current_branch") == "sor2_st7b"){jumptobranch("sor2_st8a", 1);}
			if(	openborvariant("current_branch") == "sor3_st6b"||
				openborvariant("current_branch") == "sor3_st6c"||
				openborvariant("current_branch") == "sor3_st6d"||
				openborvariant("current_branch") == "sor3_st6e"||
				openborvariant("current_branch") == "sor3_st6f"){jumptobranch("sor3_st6a", 1);}
			if(	openborvariant("current_branch") == "sor3_st7c"){jumptobranch("sor3_st8a", 1);}
			if(	openborvariant("current_branch") == "sor3_st8a"){jumptobranch("sor3_st8c", 1);}
		}
	}
}

void savePartner()
{//Save CPU partner info when level ends
	void partner = getglobalvar("currentPartner");
	void pName 	 = getentityproperty(partner, "defaultname");
	int pHealth	 = getentityproperty(partner, "health");
	int pMp	 	 = getentityproperty(partner, "mp");
	int addHealth;

	if(getglobalvar("addLife"+partner) != NULL()){
		addHealth = getglobalvar("addLife"+partner);
	}else{
		addHealth = 0;
	}

	//CPU PARTNER COMPLETED THE LAST LEVEL ALIVE??
	if(getglobalvar("partnerAlive") == 1){
		setglobalvar("partnerName", pName);
		setglobalvar("partnerHealth", pHealth+addHealth);
		setglobalvar("partnerMp", pMp);
	}
}

void saveMaxRush()
{//Save max rush counter when the level ends
	void player1 = getplayerproperty(0, "entity"); //IDENTIFY PLAYER 1
	void player2 = getplayerproperty(1, "entity"); //IDENTIFY PLAYER 2
	void player3 = getplayerproperty(2, "entity"); //IDENTIFY PLAYER 3
	void player4 = getplayerproperty(3, "entity"); //IDENTIFY PLAYER 4

	//IS PLAYER PLAYING THE GAME?? SAVE CURRENT PLAYER MAX RUSH COUNT
	if(player1 != NULL()){setglobalvar("maxRush1", getentityproperty(player1, "rush_tally"));}
	if(player2 != NULL()){setglobalvar("maxRush2", getentityproperty(player2, "rush_tally"));}
	if(player3 != NULL()){setglobalvar("maxRush3", getentityproperty(player3, "rush_tally"));}
	if(player4 != NULL()){setglobalvar("maxRush4", getentityproperty(player4, "rush_tally"));}
}

void saveAllMp()
{//Save current mp for all players, used by "loadAllMp" function
	void player1 = getplayerproperty(0, "entity"); //IDENTIFY PLAYER 1
	void player2 = getplayerproperty(1, "entity"); //IDENTIFY PLAYER 2
	void player3 = getplayerproperty(2, "entity"); //IDENTIFY PLAYER 3
	void player4 = getplayerproperty(3, "entity"); //IDENTIFY PLAYER 4

	if(getglobalvar("fullEnergy") == "never" || getglobalvar("fullEnergy") == "each_respawn"){

		//IS PLAYER PLAYING THE GAME?? SAVE CURRENT PLAYER MP
		if(player1 != NULL()){saveMp(0);}
		if(player2 != NULL()){saveMp(1);}
		if(player3 != NULL()){saveMp(2);}
		if(player4 != NULL()){saveMp(3);}
	}
}

void debugMode()
{//Turn debug mode off when any level ends (PLAYER 1 ONLY)

	//IS DEBUG MODE TURNED ON (TYPE 1)?? DEACTIVATE DEBUG MODE
	if(getglobalvar("debugMode") == 1){setglobalvar("debugMode", 0);}

	//IS SLOW MOTION TURNED ON?? DEACTIVATE SLOW MOTION
	if(openborvariant("slowmotion") != 0){changeopenborvariant("slowmotion", 0);}
}

void sor3_st6()
{//Change some global variables in SOR3 ST6A

	//START ALL NECESSARY VARIABLES
	void branch = openborvariant("current_branch");

	if(getglobalvar("st6_side") == NULL() && getglobalvar("st6_floor") == NULL()){
		if(branch == "sor3_st6b"){setglobalvar("st6_side", "a");setglobalvar("st6_floor", 2);}else
		if(branch == "sor3_st6c"){setglobalvar("st6_side", "a");setglobalvar("st6_floor", 2);}else
		if(branch == "sor3_st6d"){setglobalvar("st6_side", "a");setglobalvar("st6_floor", 1);}else
		if(branch == "sor3_st6e"){setglobalvar("st6_side", "b");setglobalvar("st6_floor", 1);}else
		if(branch == "sor3_st6f"){setglobalvar("st6_side", "b");setglobalvar("st6_floor", 2);}else
		if(branch == "sor3_st6g"){setglobalvar("st6_side", "b");setglobalvar("st6_floor", 2);}
	}

	//GET ALL VARIABLES
	int side	= getglobalvar("st6_side");
	int floor	= getglobalvar("st6_floor");
	int zStart	= 1104;
	int zDif	= 276;
	int add		= 1;

	//ELEVATOR SIDE "A"
	if(side == "a"){

		//ELEVATOR FLOOR 2
		if(floor == 2){
			if(branch == "sor3_st6b"){ //COMPUTER ROOM 1
				setglobalvar("st6_zpos", zStart-zDif);
				setglobalvar("st6_room1", 1);

				//DISABLE LOCKS FOR THE EXIT DOOR
				if(getglobalvar("st6_locks") != NULL()){setglobalvar("st6_locks", getglobalvar("st6_locks")+add);}else
				if(getglobalvar("st6_locks") == NULL()){setglobalvar("st6_locks", add);}
			}
			if(branch == "sor3_st6c"){setglobalvar("st6_zpos", zStart-zDif);}
		}

		//ELEVATOR FLOOR 1
		if(floor == 1){
			zDif = zDif*2;

			if(branch == "sor3_st6b"){ //COMPUTER ROOM 3
				setglobalvar("st6_zpos", zStart-zDif);
				setglobalvar("st6_room3", 1);

				//DISABLE LOCKS FOR THE EXIT DOOR
				if(getglobalvar("st6_locks") != NULL()){setglobalvar("st6_locks", getglobalvar("st6_locks")+add);}else
				if(getglobalvar("st6_locks") == NULL()){setglobalvar("st6_locks", add);}
			}
			if(branch == "sor3_st6d"){setglobalvar("st6_zpos", zStart-zDif);}
		}
	}

	//ELEVATOR SIDE "B"
	if(side == "b"){

		//ELEVATOR FLOOR 2
		if(floor == 2){
			if(branch == "sor3_st6f"){setglobalvar("st6_zpos", zStart-zDif);}
		}

		//ELEVATOR FLOOR 1
		if(floor == 1){
			zDif = zDif*2;

			if(branch == "sor3_st6b"){ //COMPUTER ROOM 5
				setglobalvar("st6_zpos", zStart-zDif);
				setglobalvar("st6_room5", 1);

				//DISABLE LOCKS FOR THE EXIT DOOR
				if(getglobalvar("st6_locks") != NULL()){setglobalvar("st6_locks", getglobalvar("st6_locks")+add);}else
				if(getglobalvar("st6_locks") == NULL()){setglobalvar("st6_locks", add);}
			}
			if(branch == "sor3_st6e"){setglobalvar("st6_zpos", zStart-zDif);}
		}
	}
}
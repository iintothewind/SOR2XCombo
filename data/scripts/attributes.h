void loadEnemyLifeRate() {
	float rate = 1;
	void rateCfg = getglobalvar("enemyLifeRate");
	if(rateCfg == "500%") {
		rate = 5;
	} else if(rateCfg == "400%") {
		rate = 4;
	} else if(rateCfg == "300%") {
		rate = 3;
	} else if(rateCfg == "200%") {
		rate = 2;
	} else if(rateCfg == "175%") {
		rate = 1.75;
	} else if(rateCfg == "150%") {
		rate = 1.5;
	} else if(rateCfg == "125%") {
		rate = 1.25;
	} else if(rateCfg == "100%") {
		rate = 1;
	} else if(rateCfg == "75%") {
		rate = 0.75;
	} else if(rateCfg == "50%") {
		rate = 0.5;
	} else if(rateCfg == "25%") {
		rate = 0.25;
	}
	return rate;
}

void saveAtt()
{//Save characters attributes in global variables for further use (ONDRAW.C/ONSPAWN.C/THINK.C)

	if(getglobalvar("saveAtt") == NULL()){ //TRIGGER TO ALLOW ALL VARIABLES TO BE DEFINED ONCE
		//CAUTION!! ALL GLOBAL VARIABLES BELOW WILL CHANGE ALL PLAYERS/ENEMIES/BOSSES/NPC VERSIONS
		//WILL AFFECT THE CHARACTERS THAT HAS BOTH PLAYABLE AND NON PLAYABLE VERSIONS AND NEED TO BE UNDER ALL BALANCE RULES
		//NOT USED FOR OBSTACLES, ITENS, VEHICLES OR ANY OTHER GENERIC ENTITY RELATED TO LEVEL CONTENT ONLY
		//THE ONLY VARIABLE THAT DON'T CHANGES ANYTHING IS THE "SKILL". IT IS A OVERALL VALUE ABOUT THE CHARACTER PERFORMANCE

		//USED BY THE "ONSPAWN" SCRIPTS ONLY
		setglobalvar("hBase", 50);		//BASE START HEALTH TO ENEMIES/BOSSES
		setglobalvar("aBase", -300);	//BASE START AGRESSION TO ENEMIES/BOSSES
		setglobalvar("pBase", 10);		//BASE START SCORE POINTS TO ENEMIES/BOSSES

		//USED BY ALL SCRIPTS, ESPECIALLY PLAYERS/NPCS/BOSSES
		setglobalvar("sBase", 0.4);		//BASE START SPEED FOR ALL PLAYERS/ENEMIES/BOSSES
		setglobalvar("jBase", 2.6);		//BASE START JUMP FOR ALL PLAYERS/ENEMIES/BOSSES
		setglobalvar("sDif", 0.2);		//DIFFERENCE VALUE BETWEEN EACH SPEED LEVEL
		setglobalvar("jDif", 0.2);		//DIFFERENCE VALUE BETWEEN EACH JUMP LEVEL
		setglobalvar("jDifX", 1.6);		//DIFFERENCE USED TO CALCULATE THE VALUE FOR JUMP SPEED IN X/Z AXIS USING JUMP HEIGHT AS BASE
		setglobalvar("jDifY", 0.2);		//DIFFERENCE USED TO REDUCE JUMP HEIGHT WHILE RUNNING
		setglobalvar("jumpLength", 1.2);//VALUE THAT DEFINES HOW FAR A CHARACTER CAN JUMP WHILE RUNNING
		setglobalvar("runMove", 1);		//ENABLE RUNNING IN Z AXIS
		setglobalvar("runLand", 0);		//VALUE TO DEFINE IF THE ENTITY WILL NOT CONTINUE RUNNING AFTER LAND BY A "JUMP RUN"

		//HEROES
		setglobalvar("Axel"+"Skills", 3);
		setglobalvar("Axel"+"Power", 3);
		setglobalvar("Axel"+"Speed", 3);
		setglobalvar("Axel"+"Jump", 2);
		setglobalvar("Axel"+"Energy", 2);

		setglobalvar("Blaze"+"Skills", 4);
		setglobalvar("Blaze"+"Power", 2);
		setglobalvar("Blaze"+"Speed", 4);
		setglobalvar("Blaze"+"Jump", 2);
		setglobalvar("Blaze"+"Energy", 2);

		setglobalvar("Max"+"Skills", 2);
		setglobalvar("Max"+"Power", 5);
		setglobalvar("Max"+"Speed", 2);
		setglobalvar("Max"+"Jump", 1);
		setglobalvar("Max"+"Energy", 1);

		setglobalvar("Sammy"+"Skills", 4);
		setglobalvar("Sammy"+"Power", 2);
		setglobalvar("Sammy"+"Speed", 4);
		setglobalvar("Sammy"+"Jump", 3);
		setglobalvar("Sammy"+"Energy", 3);

		setglobalvar("Adam"+"Skills", 4);
		setglobalvar("Adam"+"Power", 3);
		setglobalvar("Adam"+"Speed", 3);
		setglobalvar("Adam"+"Jump", 1);
		setglobalvar("Adam"+"Energy", 2);

		setglobalvar("Zan"+"Skills", 3);
		setglobalvar("Zan"+"Power", 4);
		setglobalvar("Zan"+"Speed", 2);
		setglobalvar("Zan"+"Jump", 1);
		setglobalvar("Zan"+"Energy", 1);

		//ENEMIES
		setglobalvar("Galsia"+"Skills", 1);
		setglobalvar("Galsia"+"Power", 1);
		setglobalvar("Galsia"+"Speed", 1);
		setglobalvar("Galsia"+"Jump", 1);
		setglobalvar("Galsia"+"Energy", 1);

		setglobalvar("Donovan"+"Skills", 1);
		setglobalvar("Donovan"+"Power", 1);
		setglobalvar("Donovan"+"Speed", 1);
		setglobalvar("Donovan"+"Jump", 1);
		setglobalvar("Donovan"+"Energy", 1);

		setglobalvar("Signal"+"Skills", 1);
		setglobalvar("Signal"+"Power", 1);
		setglobalvar("Signal"+"Speed", 1);
		setglobalvar("Signal"+"Jump", 1);
		setglobalvar("Signal"+"Energy", 2);

		setglobalvar("Fog"+"Skills", 1);
		setglobalvar("Fog"+"Power", 1);
		setglobalvar("Fog"+"Speed", 1);
		setglobalvar("Fog"+"Jump", 1);
		setglobalvar("Fog"+"Energy", 1);

		setglobalvar("Hakuyo"+"Skills", 1);
		setglobalvar("Hakuyo"+"Power", 2);
		setglobalvar("Hakuyo"+"Speed", 2);
		setglobalvar("Hakuyo"+"Jump", 2);
		setglobalvar("Hakuyo"+"Energy", 5);

		setglobalvar("Kusanagi"+"Skills", 2);
		setglobalvar("Kusanagi"+"Power", 2);
		setglobalvar("Kusanagi"+"Speed", 3);
		setglobalvar("Kusanagi"+"Jump", 3);
		setglobalvar("Kusanagi"+"Energy", 3);

		setglobalvar("Raven"+"Skills", 1);
		setglobalvar("Raven"+"Power", 3);
		setglobalvar("Raven"+"Speed", 2);
		setglobalvar("Raven"+"Jump", 1);
		setglobalvar("Raven"+"Energy", 4);

		setglobalvar("Big-Ben"+"Skills", 1);
		setglobalvar("Big-Ben"+"Power", 4);
		setglobalvar("Big-Ben"+"Speed", 1);
		setglobalvar("Big-Ben"+"Jump", 1);
		setglobalvar("Big-Ben"+"Energy", 1);

		setglobalvar("Electra_"+"Skills", 3);
		setglobalvar("Electra_"+"Power", 2);
		setglobalvar("Electra_"+"Speed", 5);
		setglobalvar("Electra_"+"Jump", 2);
		setglobalvar("Electra_"+"Energy", 1);

		setglobalvar("Jack"+"Skills", 5);
		setglobalvar("Jack"+"Power", 2);
		setglobalvar("Jack"+"Speed", 2);
		setglobalvar("Jack"+"Jump", 1);
		setglobalvar("Jack"+"Energy", 3);

		setglobalvar("Slum"+"Skills", 1);
		setglobalvar("Slum"+"Power", 1);
		setglobalvar("Slum"+"Speed", 2);
		setglobalvar("Slum"+"Jump", 1);
		setglobalvar("Slum"+"Energy", 1);

		setglobalvar("Vice"+"Skills", 1);
		setglobalvar("Vice"+"Power", 1);
		setglobalvar("Vice"+"Speed", 2);
		setglobalvar("Vice"+"Jump", 1);
		setglobalvar("Vice"+"Energy", 1);

		setglobalvar("Garnet"+"Skills", 1);
		setglobalvar("Garnet"+"Power", 1);
		setglobalvar("Garnet"+"Speed", 3);
		setglobalvar("Garnet"+"Jump", 5);
		setglobalvar("Garnet"+"Energy", 2);

		setglobalvar("Macleod"+"Skills", 1);
		setglobalvar("Macleod"+"Power", 1);
		setglobalvar("Macleod"+"Speed", 1);
		setglobalvar("Macleod"+"Jump", 1);
		setglobalvar("Macleod"+"Energy", 1);

		setglobalvar("Tiger"+"Skills", 1);
		setglobalvar("Tiger"+"Power", 3);
		setglobalvar("Tiger"+"Speed", 2);
		setglobalvar("Tiger"+"Jump", 2);
		setglobalvar("Tiger"+"Energy", 4);

		setglobalvar("P-1"+"Skills", 1);
		setglobalvar("P-1"+"Power", 3);
		setglobalvar("P-1"+"Speed", 1);
		setglobalvar("P-1"+"Jump", 6);
		setglobalvar("P-1"+"Energy", 1);

		setglobalvar("Bongo"+"Skills", 1);
		setglobalvar("Bongo"+"Power", 4);
		setglobalvar("Bongo"+"Speed", 1);
		setglobalvar("Bongo"+"Jump", 1);
		setglobalvar("Bongo"+"Energy", 1);

		setglobalvar("Electra"+"Skills", 4);
		setglobalvar("Electra"+"Power", 2);
		setglobalvar("Electra"+"Speed", 4);
		setglobalvar("Electra"+"Jump", 2);
		setglobalvar("Electra"+"Energy", 3);

		setglobalvar("Ash"+"Skills", 3);
		setglobalvar("Ash"+"Power", 4);
		setglobalvar("Ash"+"Speed", 5);
		setglobalvar("Ash"+"Jump", 5);
		setglobalvar("Ash"+"Energy", 4);

		setglobalvar("Bruce"+"Skills", 2);
		setglobalvar("Bruce"+"Power", 2);
		setglobalvar("Bruce"+"Speed", 3);
		setglobalvar("Bruce"+"Jump", 4);
		setglobalvar("Bruce"+"Energy", 3);

		setglobalvar("Roo"+"Skills", 3);
		setglobalvar("Roo"+"Power", 2);
		setglobalvar("Roo"+"Speed", 5);
		setglobalvar("Roo"+"Jump", 5);
		setglobalvar("Roo"+"Energy", 3);

		setglobalvar("Barbon"+"Skills", 3);
		setglobalvar("Barbon"+"Power", 3);
		setglobalvar("Barbon"+"Speed", 3);
		setglobalvar("Barbon"+"Jump", 1);
		setglobalvar("Barbon"+"Energy", 3);

		setglobalvar("Jet"+"Skills", 3);
		setglobalvar("Jet"+"Power", 2);
		setglobalvar("Jet"+"Speed", 5);
		setglobalvar("Jet"+"Jump", 5);
		setglobalvar("Jet"+"Energy", 5);

		setglobalvar("Zamza"+"Skills", 3);
		setglobalvar("Zamza"+"Power", 2);
		setglobalvar("Zamza"+"Speed", 4);
		setglobalvar("Zamza"+"Jump", 5);
		setglobalvar("Zamza"+"Energy", 5);

		setglobalvar("Abadede"+"Skills", 5);
		setglobalvar("Abadede"+"Power", 4);
		setglobalvar("Abadede"+"Speed", 5);
		setglobalvar("Abadede"+"Jump", 2);
		setglobalvar("Abadede"+"Energy", 3);

		setglobalvar("R._Bear"+"Skills", 4);
		setglobalvar("R._Bear"+"Power", 4);
		setglobalvar("R._Bear"+"Speed", 4);
		setglobalvar("R._Bear"+"Jump", 2);
		setglobalvar("R._Bear"+"Energy", 3);

		setglobalvar("Particle"+"Skills", 3);
		setglobalvar("Particle"+"Power", 4);
		setglobalvar("Particle"+"Speed", 1);
		setglobalvar("Particle"+"Jump", 6);
		setglobalvar("Particle"+"Energy", 3);

		setglobalvar("Shiva"+"Skills", 3);
		setglobalvar("Shiva"+"Power", 3);
		setglobalvar("Shiva"+"Speed", 4);
		setglobalvar("Shiva"+"Jump", 3);
		setglobalvar("Shiva"+"Energy", 3);

		setglobalvar("Mr._X"+"Skills", 3);
		setglobalvar("Mr._X"+"Power", 3);
		setglobalvar("Mr._X"+"Speed", 5);
		setglobalvar("Mr._X"+"Jump", 5);
		setglobalvar("Mr._X"+"Energy", 3);

		setglobalvar("Monalisa"+"Skills", 3);
		setglobalvar("Monalisa"+"Power", 2);
		setglobalvar("Monalisa"+"Speed", 3);
		setglobalvar("Monalisa"+"Jump", 6);
		setglobalvar("Monalisa"+"Energy", 4);

		setglobalvar("Break"+"Skills", 4);
		setglobalvar("Break"+"Power", 3);
		setglobalvar("Break"+"Speed", 6);
		setglobalvar("Break"+"Jump", 3);
		setglobalvar("Break"+"Energy", 3);

		setglobalvar("Yamato"+"Skills", 5);
		setglobalvar("Yamato"+"Power", 3);
		setglobalvar("Yamato"+"Speed", 4);
		setglobalvar("Yamato"+"Jump", 5);
		setglobalvar("Yamato"+"Energy", 4);

		setglobalvar("Robot_X"+"Skills", 3);
		setglobalvar("Robot_X"+"Power", 4);
		setglobalvar("Robot_X"+"Speed", 2);
		setglobalvar("Robot_X"+"Jump", 1);
		setglobalvar("Robot_X"+"Energy", 3);

		setglobalvar("Jet_"+"Skills", 3);
		setglobalvar("Jet_"+"Power", 3);
		setglobalvar("Jet_"+"Speed", 5);
		setglobalvar("Jet_"+"Jump", 5);
		setglobalvar("Jet_"+"Energy", 5);

		setglobalvar("Shiva_"+"Skills", 3);
		setglobalvar("Shiva_"+"Power", 3);
		setglobalvar("Shiva_"+"Speed", 5);
		setglobalvar("Shiva_"+"Jump", 3);
		setglobalvar("Shiva_"+"Energy", 2);

		setglobalvar("Neo._X"+"Skills", 3);
		setglobalvar("Neo._X"+"Power", 4);
		setglobalvar("Neo._X"+"Speed", 5);
		setglobalvar("Neo._X"+"Jump", 3);
		setglobalvar("Neo._X"+"Energy", 5);

		setglobalvar("Harakiri"+"Skills", 5);
		setglobalvar("Harakiri"+"Power", 4);
		setglobalvar("Harakiri"+"Speed", 5);
		setglobalvar("Harakiri"+"Jump", 1);
		setglobalvar("Harakiri"+"Energy", 5);

		setglobalvar("Tracker"+"Skills", 3);
		setglobalvar("Tracker"+"Power", 3);
		setglobalvar("Tracker"+"Speed", 3);
		setglobalvar("Tracker"+"Jump", 3);
		setglobalvar("Tracker"+"Energy", 5);

		setglobalvar("Ringmaster"+"Skills", 3);
		setglobalvar("Ringmaster"+"Power", 3);
		setglobalvar("Ringmaster"+"Speed", 4);
		setglobalvar("Ringmaster"+"Jump", 4);
		setglobalvar("Ringmaster"+"Energy", 4);

		setglobalvar("Kun"+"Skills", 1);
		setglobalvar("Kun"+"Power", 1);
		setglobalvar("Kun"+"Speed", 5);
		setglobalvar("Kun"+"Jump", 1);
		setglobalvar("Kun"+"Energy", 5);

		setglobalvar("Bison"+"Skills", 2);
		setglobalvar("Bison"+"Power", 5);
		setglobalvar("Bison"+"Speed", 2);
		setglobalvar("Bison"+"Jump", 1);
		setglobalvar("Bison"+"Energy", 1);

		setglobalvar("Chunli"+"Skills", 3);
		setglobalvar("Chunli"+"Power", 2);
		setglobalvar("Chunli"+"Speed", 4);
		setglobalvar("Chunli"+"Jump", 5);
		setglobalvar("Chunli"+"Energy", 1);

		setglobalvar("Kage"+"Skills", 5);
		setglobalvar("Kage"+"Power", 2);
		setglobalvar("Kage"+"Speed", 5);
		setglobalvar("Kage"+"Jump", 5);
		setglobalvar("Kage"+"Energy", 1);

		setglobalvar("Lee"+"Skills", 3);
		setglobalvar("Lee"+"Power", 2);
		setglobalvar("Lee"+"Speed", 4);
		setglobalvar("Lee"+"Jump", 3);
		setglobalvar("Lee"+"Energy", 2);

		setglobalvar("LEVEL_ENTITY", 262144);


		//TRIGGER TO STOP THE SCRIPT AFTER RUN ONCE, SAVE CPU POWER
		setglobalvar("saveAtt", 1);
	}
}

void applyAtt(void vName, int speedFlag)
{//Apply attributes for all characters
	void self		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void rName		= getentityproperty(self, "defaultname");
	float offense	= getentityproperty(self, "offense", 0);
	float speed		= getentityproperty(self, "speed");
	float jump		= getentityproperty(self, "jumpheight");
	float energy	= getentityproperty(self, "mprate");
	float sBase		= getglobalvar("sBase");
	float jBase		= getglobalvar("jBase");
	float sDif		= getglobalvar("sDif");
	float jDif		= getglobalvar("jDif");
	float pw;
	float sp;
	float ju;
	float en;

	if(vName == NULL()){
		pw = getglobalvar(rName+"Power");
		sp = getglobalvar(rName+"Speed");
		ju = getglobalvar(rName+"Jump");
		en = getglobalvar(rName+"Energy");
	}else{
		pw = getglobalvar(vName+"Power");
		sp = getglobalvar(vName+"Speed");
		ju = getglobalvar(vName+"Jump");
		en = getglobalvar(vName+"Energy");
	}

	//TRANSLATE SPEED AND JUMP VALUES
	//POWER AND ENERGY ATTRIBUTES DON'T NEED TO BE TRANSLATED BECAUSE IT WORKS WITH YOUR REAL VALUE
	sp = sBase+(sDif*sp);
	ju = jBase+(jDif*ju);

	//APPLY POWER VALUES
	if(pw != NULL()){
		changeentityproperty(self, "offense", 0, pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL2"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL3"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL4"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL5"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL6"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL7"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL8"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL9"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_NORMAL10"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_BURN"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_SHOCK"), pw);
		changeentityproperty(self, "offense", openborconstant("ATK_LAND"), pw);
	}

	//APPLY SPEED VALUES
	if(sp != NULL()){
		float jDifY 	 = getglobalvar("jDifY"); 		//DIFFERENCE VALUE TO REDUCE JUMP HEIGHT WHILE RUNNING
		float jumpLength = getglobalvar("jumpLength"); 	//HOW FAR A CHARACTER CAN JUMP WHILE RUNNING
		float runMove 	 = getglobalvar("runMove"); 	//ENABLE RUNNING IN Z AXIS
		float runLand 	 = getglobalvar("runLand"); 	//WILL NOT CONTINUE RUNNING AFTER LAND

		if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
			if(rName != "Break"){ //BREAK CHARACTER CHANGES SPEED USING "SPEEDATT" SCRIPT
				changeentityproperty(self, "speed", sp);
				changeentityproperty(self, "running", sp*2, ju-jDifY, jumpLength, runMove, runLand);
			}
		}

		if(type == openborconstant("TYPE_ENEMY")){
			if(speedFlag == 1){ //USED FOR NPC AND BOSSES ONLY, REGULAR ENEMIES CHANGES SPEED IN ONSPAWN EVENT
				if(getglobalvar("difficult") == "mania") {
					float edelay	  = 0.8;
					changeentityproperty(self, "edelay", 1, edelay, 1, 100, 1, 100);
					changeentityproperty(self, "speed", sp*1.5);
				} else if(getglobalvar("difficult") == "hard") {
					changeentityproperty(self, "speed", sp*1.25);
				} else {
					changeentityproperty(self, "speed", sp);
				}
				changeentityproperty(self, "running", sp*2, ju-jDifY, jumpLength, runMove, runLand);
			}
		}
	}

	//APPLY JUMP VALUES
	if(ju != NULL()){
		float jDifX = getglobalvar("jDifX"); //USED TO CALCULATE THE CORRECT VALUE FOR JUMP SPEED IN X/Z AXIS

		changeentityproperty(self, "jumpspeed", ju-jDifX);
		changeentityproperty(self, "jumpheight", ju);
	}

	//APPLY ENERGY VALUES
	if(en != NULL()){
		changeentityproperty(self, "mpset", NULL(), NULL(), NULL(), en, NULL(), NULL());
	}
}

void speedAtt(void name)
{//Apply speed and change tintcolor with health check (USED ON BREAK CHARACTER - ROBOT AXEL)
	void self 		 = getlocalvar("self");
	void type 		 = getentityproperty(self, "type");
	int mHealth		 = getentityproperty(self, "maxhealth");
	int health		 = getentityproperty(self, "health");
	int speed		 = getentityproperty(self, "speed");
	int life 		 = mHealth/3;
	int runZ		 = getentityproperty(self, "running", "movez");
	int runMove;
	float sp  		 = getglobalvar(name+"Speed");
	float ju  		 = getglobalvar(name+"Jump");
	float sBase		 = getglobalvar("sBase");
	float jBase		 = getglobalvar("jBase");
	float sDif		 = getglobalvar("sDif");
	float jDif		 = getglobalvar("jDif");
	float jDifX 	 = getglobalvar("jDifX"); 		//USED TO CALCULATE THE CORRECT VALUE FOR JUMP SPEED IN X/Z AXIS
	float jDifY 	 = getglobalvar("jDifY"); 		//DIFFERENCE VALUE TO REDUCE JUMP HEIGHT WHILE RUNNING
	float jumpLength = getglobalvar("jumpLength"); 	//HOW FAR A CHARACTER CAN JUMP WHILE RUNNING
	float runLand 	 = getglobalvar("runLand"); 	//WILL NOT CONTINUE RUNNING AFTER LAND
	float speedMult;
	float runMult;
	float jumpAdd;
	float edelay;
	float color;

	sp = sBase+(sDif*sp); //TRANSLATE SPEED VALUE
	ju = jBase+(jDif*ju); //TRANSLATE JUMP VALUE

	//ENABLE OR DISABLE RUNNING IN Z AXIS
	if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
		if(getglobalvar("runType") == "sor2x"){runMove = 1;}else{runMove = 0;}
	}
	else
	{
		runMove = 1;
	}

	//DEFINE AND APPLY VALUES TO EACH SPEED LEVEL
	if(health >= life*2){ //HIGHER THAN 66% LIFE
		runMult	  = 2;
		edelay	  = 1;

		if(getentityvar(self, "speedLV") != 1 || runZ != runMove){
			changeentityproperty(self, "speed", sp);
			changeentityproperty(self, "running", sp*runMult, ju-jDifY, jumpLength, runMove, runLand);
			changeentityproperty(self, "jumpspeed", ju-jDifX);
			changeentityproperty(self, "jumpheight", ju);
			changeentityproperty(self, "edelay", 1, edelay, 1, 100, 1, 100);
			changedrawmethod(self, "enabled", 0);
			setentityvar(self, "speedLV", 1);
		}
	}
	else
	if(health < life*2 && health > life){ //LOWER THAN 66% AND HIGHER THAN 33% LIFE
		speedMult = 1.5;
		runMult	  = 3;
		jumpAdd	  = 0.5;
		edelay	  = 0.8;
		color	  = rgbcolor(0xA0,0x60,0x60);

		if(getentityvar(self, "speedLV") != 2 || runZ != runMove){
			changeentityproperty(self, "speed", sp*speedMult);
			changeentityproperty(self, "running", sp*runMult, ju-jDifY, jumpLength, runMove, runLand);
			changeentityproperty(self, "jumpspeed", ju-jDifX+jumpAdd);
			changeentityproperty(self, "jumpheight", ju);
			changeentityproperty(self, "edelay", 1, edelay, 1, 100, 1, 100);
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", 3);
			changedrawmethod(self, "tintcolor", color);
			setentityvar(self, "speedLV", 2);
		}
	}
	else
	if(health < life && health > 0){ //LOWER THAN 33% LIFE AND HIGHER THAN 0 LIFE
		speedMult = 2;
		runMult	  = 4;
		jumpAdd	  = 1;
		edelay	  = 0.6;
		color	  = rgbcolor(0xC0,0x60,0x60);

		if(getentityvar(self, "speedLV") != 3 || runZ != runMove){
			changeentityproperty(self, "speed", sp*speedMult);
			changeentityproperty(self, "running", sp*runMult, ju-jDifY, jumpLength, runMove, runLand);
			changeentityproperty(self, "jumpspeed", ju-jDifX+jumpAdd);
			changeentityproperty(self, "jumpheight", ju);
			changeentityproperty(self, "edelay", 1, edelay, 1, 100, 1, 100);
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", 3);
			changedrawmethod(self, "tintcolor", color);
			setentityvar(self, "speedLV", 3);
		}
	}
	else
	if(health <= 0){ //DEAD!!
		edelay	  = 1;

		if(getentityvar(self, "speedLV") != 0){
			changeentityproperty(self, "edelay", 1, edelay, 1, 100, 1, 100);
			changedrawmethod(self, "enabled", 0);
			setentityvar(self, "speedLV", 0);
		}
	}
}
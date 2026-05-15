void changeLives(int player)
{//Change lives according to global variable "lives" check

	//ARCADE - REBELLION
	if(openborvariant("current_set") == 0 || openborvariant("current_set") == 2){
		if(getplayerproperty(player, "entity") != NULL()){
			changeplayerproperty(player, "lives", getglobalvar("lives"));
		}
	}

	//SURVIVAL
	if(openborvariant("current_set") == 1){
		if(getplayerproperty(player, "entity") != NULL()){
			changeplayerproperty(player, "lives", 1);
		}
	}
}

void lockScore(int player)
{//Lock score changes, specific for Survival mode

	if(openborvariant("current_set") == 1){
		if(openborvariant("current_branch") == "survival_a" || openborvariant("current_branch") == "survival_b"){
			if(getplayerproperty(player, "entity") != NULL()){
				changeplayerproperty(player, "score", 0);
			}
		}
	}
}

void lifeScore(int player)
{//Custom LifeScore script for add lives, used to avoid native engine LifeScore bug
	void self	  = getplayerproperty(player, "entity");
	int score	  = getplayerproperty(player, "score");
	int lifeScore = 100000; //DEFINED LIFESCORE TARGET TO ADD EACH LIVE
	int add		  = 1; //HOW MUCH LIVES WILL BE ADDED WHEN SCORE REACHED THE TARGET

	//USED TO CHECK IF THE PLAYER IS IN A NEW GAME
	if(getglobalvar("next1up"+player) == NULL()){
		setglobalvar("next1up"+player, lifeScore);
	}

	//USED TO ADD LIVES TO PLAYER
	if(self != NULL()){ //CURRENT PLAYER REMAINS IN GAME??
		while(score >= getglobalvar("next1up"+player)){ //CURRENT SCORE REACHED THE LAST DEFINED TARGET??
			int lives = getplayerproperty(player, "lives"); //CHECK CURRENT LIVES EVERYTIME THIS TASK RUNS
			playsample(openborconstant("SAMPLE_1UP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //PLAY SAMPLE
			changeplayerproperty(player, "lives", lives+add); //ADD +1 LIVE
			setglobalvar("next1up"+player, getglobalvar("next1up"+player)+lifeScore); //DEFINE AND SAVE THE NEXT TARGET
		}
	}
}

void spawnText(void entityName, void skillName)
{//Spawn "Text Entity" at specific location relative to xPos and yPos (MOVE NAMES)
	void self   = getlocalvar("self");
	void vSpawn;
	void skillAni;
	int iPIndex = getentityproperty(self, "playerindex");
	float xPos  = openborvariant("xpos");
	float yPos  = openborvariant("ypos");
	float xDif	= 120;
	float xAdd 	= xDif*iPIndex;
	float fX	= 3;
	float fY	= 86;

	if(skillName == "COUNTER"){			skillAni = openborconstant("ANI_FOLLOW1");}
	if(skillName == "SUPER"){			skillAni = openborconstant("ANI_FOLLOW2");}
	if(skillName == "RAGE"){			skillAni = openborconstant("ANI_FOLLOW3");}
	if(skillName == "GRAB_ESCAPE"){		skillAni = openborconstant("ANI_FOLLOW4");}
	if(skillName == "AERIAL_RECOVER"){	skillAni = openborconstant("ANI_FOLLOW5");}
	if(skillName == "SUPER_ARMOR"){		skillAni = openborconstant("ANI_FOLLOW6");}
	if(skillName == "GUARD_BREAK"){		skillAni = openborconstant("ANI_FOLLOW7");}

	clearspawnentry();
	setspawnentry("name", entityName);

	vSpawn = spawn();

	fX = xPos+fX+xAdd;
	fY = yPos+fY;

	changeentityproperty(vSpawn, "position", fX, fY, 0);
	changeentityproperty(vSpawn, "direction", 1);
	changeentityproperty(vSpawn, "animation", skillAni);

	return vSpawn;
}

void checkText(void selectAni, void skillName)
{//Check defined conditions before use "spawnText" script, used in the "ondraw" event only
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void currentAni = getentityproperty(self, "animationID");
	int frame 		= getentityproperty(self, "animpos");

	if(type == openborconstant("TYPE_PLAYER")){
		if(frame > 0){
			if(getlocalvar("counter"+self) == 1){setlocalvar("counter"+self, 0);}
		}

		if(frame <= 0){
			if(currentAni == openborconstant(selectAni)){
				while(getlocalvar("counter"+self) != 1){
					// spawnText("Moves", skillName);
					setlocalvar("counter"+self, 1);
				}
			}
		}
	}
}

void getCharSkillLevel(void player) {
	void playerName 	 = getentityproperty(player, "defaultname");
	if(playerName != NULL()) {
		float skill = getglobalvar(playerName+"Skills");
		if(skill != NULL()) {
			return skill;
		}
	}

	return 3;
}

void getCharSpeedLevel(void player) {
	void playerName 	 = getentityproperty(player, "defaultname");
	if(playerName != NULL()) {
		float speed = getglobalvar(playerName+"Speed");
		if(speed != NULL()) {
			return speed;
		}
	}

	return 3;
}

void mpRecover() {
	void self = getlocalvar("self");
	int maxMp	 = getentityproperty(self,"maxMp");
	int mp			= getentityproperty(self, "mp");
	int mpRecover		= (maxMp/4)/5*getCharSkillLevel(self);
	if(mp <= maxMp/2) {
		changeentityproperty(self, "mp", mp+mpRecover);
	}
}

void invinc(float duration)
{
	void self  = getlocalvar("self");
	float selfHeight = getentityproperty(self,"y");
	float selfBase = getentityproperty(self,"base");
	float time = openborvariant("elapsed_time");
	float mult = 100;
	float delta  = duration*mult;
	float lastInvincTime = getentityproperty(self, "invinctime");
	if(lastInvincTime == NULL() || (lastInvincTime != NULL() && lastInvincTime < (time + delta))) {
		setglobalvar("armorResist"+self, time+delta);
		changeentityproperty(self, "aiflag", "invincible", 1);
		changeentityproperty(self, "invinctime", time+delta);
	}
}

void rnd(int n) {
	int ticks =  openborvariant("ticks");
	int elapsed =  openborvariant("elapsed_time");
	int playedSecond 	= getglobalvar("playedSecond");
	int randSeed 	= rand();

	if(ticks != NULL()) {
		srand(ticks);
	} else if(elapsed != NULL()) {
		srand(elapsed);
	} else if(playedSecond != NULL()) {
		srand(playedSecond);
	} else {
		srand(randSeed);
	}

	if(n > 1) {
		int rnd = rand() % n;
		if(rnd < 0) {
			rnd = -rnd;
		}
		return rnd + 1;
	}
	return n;
}

void loadCounterAttackReward() {
	float rate = 1;
	void reward = getglobalvar("counterAttackReward");
	if(reward == "200%") {
		rate = 2;
	} else if(reward == "175%") {
		rate = 1.75;
	} else if(reward == "150%") {
		rate = 1.5;
	} else if(reward == "125%") {
		rate = 1.25;
	} else if(reward == "100%") {
		rate = 1;
	} else if(reward == "75%") {
		rate = 0.75;
	} else if(reward == "50%") {
		rate = 0.5;
	} else if(reward == "25%") {
		rate = 0.25;
	} else if(reward == "off") {
		rate = 0;
	}
	return rate;
}

void isBoss(void enemy) {
	if(enemy != NULL()) {
		void type = getentityproperty(enemy,"type");
		void enemyName		= getentityproperty(enemy, "defaultname");
		void bossFlag		= getentityproperty(enemy, "boss");

		if(type == openborconstant("TYPE_ENEMY") && (bossFlag == 1
		|| strinfirst(enemyName, "Ash") != -1
		|| strinfirst(enemyName, "Tamer") != -1
		|| strinfirst(enemyName, "Roo") != -1
		|| strinfirst(enemyName, "Barbon") != -1
		|| strinfirst(enemyName, "Jet") != -1
		|| strinfirst(enemyName, "Reine") != -1
		|| strinfirst(enemyName, "Abadede") != -1
		|| strinfirst(enemyName, "Bear") != -1
		|| strinfirst(enemyName, "Particle") != -1
		|| strinfirst(enemyName, "Shiva") != -1
		|| strinfirst(enemyName, "Mrx") != -1
		|| strinfirst(enemyName, "Monalisa") != -1
		|| strinfirst(enemyName, "Break") != -1
		|| strinfirst(enemyName, "Yamato") != -1
		|| strinfirst(enemyName, "Robotx") != -1
		|| strinfirst(enemyName, "Jet") != -1
		|| strinfirst(enemyName, "Rocket") != -1
		|| strinfirst(enemyName, "Neox") != -1
		|| strinfirst(enemyName, "Harakiri") != -1
		|| strinfirst(enemyName, "Tracker") != -1
		|| strinfirst(enemyName, "Ringmaster") != -1
		|| strinfirst(enemyName, "Bison") != -1
		|| strinfirst(enemyName, "Chunli") != -1
		|| strinfirst(enemyName, "Kage") != -1
		|| strinfirst(enemyName, "Lee") != -1
		|| strinfirst(enemyName, "Musashi") != -1
		|| strinfirst(enemyName, "Zamza") != -1)) {
				return 1;
		}
	}
	return 0;
}

void findEnemy(void name) {
	if(name != NULL()) {
		int entityCount	= openborvariant("count_entities");
		int entityIndex	= 0;
		void entity	= NULL();

		for(entityIndex=0; entityIndex < entityCount; entityIndex++) {
			entity = getentity(entityIndex);
			if(entity != NULL() && getentityproperty(entity, "exists") && getentityproperty(entity, "type") == openborconstant("TYPE_ENEMY")) {
				int isEntityDead	= getentityproperty(entity, "dead");
				void enemyName		= getentityproperty(entity, "defaultname");

				if(isEntityDead == 0 && strinfirst(enemyName, name) != -1) {
					return entity;
				}
			}
		}
	}
	return NULL();
}


void findOtherEnemy(void name) {
	if(name != NULL()) {
		int entityCount	= openborvariant("count_entities");
		int entityIndex	= 0;
		void entity	= NULL();

		for(entityIndex=0; entityIndex < entityCount; entityIndex++) {
			entity = getentity(entityIndex);
			if(entity != NULL() && getentityproperty(entity, "exists") && getentityproperty(entity, "type") == openborconstant("TYPE_ENEMY")) {
				int isEntityDead	= getentityproperty(entity, "dead");
				void enemyName		= getentityproperty(entity, "defaultname");
				if(isEntityDead == 0 && strinfirst(enemyName, name) == -1) {
					return entity;
				}
			}
		}
	}
	return NULL();
}

void countEnemies(void name, int includeFrozen) {
	int entityCount	= openborvariant("count_entities");
	int entityIndex	= 0;
	int bossNumber = 0;
	void entity	= NULL();

	for(entityIndex=0; entityIndex < entityCount; entityIndex++) {
		entity = getentity(entityIndex);
		if(entity != NULL() && getentityproperty(entity, "exists") && getentityproperty(entity, "type") == openborconstant("TYPE_ENEMY")) {
			int isEntityDead	= getentityproperty(entity, "dead");
			int isEntityFrozen	= includeFrozen == 0 ? 0 : getentityproperty(entity, "aiflag", "frozen");
			void enemyName		= getentityproperty(entity, "defaultname");

			if(isEntityDead == 0 && isEntityFrozen == 0) {
				if(name == NULL() || strinfirst(enemyName, name) != -1) {
					bossNumber++;
				}
			}
		}
	}
	return bossNumber;
}

void findLevelBoss() {
	int entityCount	= openborvariant("count_entities");
	int entityIndex	= 0;
	int bossNumber = 0;
	void entity	= NULL();

	for(entityIndex=0; entityIndex < entityCount; entityIndex++) {
		entity = getentity(entityIndex);
		if(entity != NULL() && getentityproperty(entity, "exists") && getentityproperty(entity, "type") == openborconstant("TYPE_ENEMY")) {
			int isEntityDead	= getentityproperty(entity, "dead");
			int isBigBoss		= getentityproperty(entity, "boss");
			if(isEntityDead == 0 && isBigBoss == 1) {
				return entity;
			}
		}
	}
	return NULL();
}

void isPlayerInDanger(void player) {
	if(player != NULL()) {
		int p1Hp	 = getentityproperty(player,"health");
		int p1MaxHp	= getentityproperty(player, "maxhealth");

		if(p1Hp != NULL() && p1MaxHp != NULL() && p1Hp < (p1MaxHp/2)) {
			return 1;
		}
	}
	return 0;
}

void isAnyPlayerInDanger() {
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	return  isPlayerInDanger(player1) || isPlayerInDanger(player2) || isPlayerInDanger(player3) || isPlayerInDanger(player4);
}
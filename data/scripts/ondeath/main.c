#import "data/scripts/main.c"

void slowMotion()
{//Enable slowmotion effect after death even if the enemy is not a boss or the "noslow" function is used

	changeopenborvariant("slowmotion", 1);
}

void musicPause()
{//Stop music if entity dies
 //Alternative script to avoid "pausemusic" bug that makes the current music restarts if the game is paused/unpaused
	void music = "data/music/empty.ogg";

	playmusic(music, 1);
}

void screen(int flag)
{//Turns subject's to screen status
	void self = getlocalvar("self");

	changeentityproperty(self, "subject_to_screen", flag);
}

void partnerAlive(int flag)
{//Set global variable "partnerAlive" flag to 0

	setglobalvar("partnerAlive", flag);
	setglobalvar("partnerParrow", NULL());
}

void partnerRespawn()
{//Automatic CPU partner respawn if this option is activated in Partner Menu

	if(getglobalvar("partnerRespawn") == "automatic"){
		void self 	 = getlocalvar("self");
		void player1 = getplayerproperty(0, "entity");
		void player2 = getplayerproperty(1, "entity");
		void player3 = getplayerproperty(2, "entity");
		void player4 = getplayerproperty(3, "entity");
		float x;
		float y;
		float z;
		int dir;

		if(player1 != NULL()){
			x 	= getentityproperty(player1, "x");
			y 	= getentityproperty(player1, "y");
			z 	= getentityproperty(player1, "z");
			dir = getentityproperty(player1, "direction");
		}
		else
		if(player2 != NULL()){
			x 	= getentityproperty(player2, "x");
			y 	= getentityproperty(player2, "y");
			z 	= getentityproperty(player2, "z");
			dir = getentityproperty(player2, "direction");
		}
		else
		if(player3 != NULL()){
			x 	= getentityproperty(player3, "x");
			y 	= getentityproperty(player3, "y");
			z 	= getentityproperty(player3, "z");
			dir = getentityproperty(player3, "direction");
		}
		else
		if(player4 != NULL()){
			x 	= getentityproperty(player4, "x");
			y 	= getentityproperty(player4, "y");
			z 	= getentityproperty(player4, "z");
			dir = getentityproperty(player4, "direction");
		}

		if(getglobalvar("partnerAlive") == 0){
			int iPIndex	 = getglobalvar("partnerIndex");
			int lives 	 = getplayerproperty(iPIndex, "lives");
			int pMp	 	 = getentityproperty(self, "mp");

			setglobalvar("partnerMp", pMp);

			if(lives >= 2){
				void partner = getglobalvar("currentPartner");
				void pName 	 = getentityproperty(partner, "defaultname");
				void vSpawn;

				loadmodel(getglobalvar("selectPartner"), 1);
				changeplayerproperty(iPIndex, "lives", lives-1);
				clearspawnentry(); //CLEAR CURRENT SPAWN ENTRY
				setspawnentry("name", pName); //ACQUIRE SPAWN ENTITY BY NAME
				vSpawn = spawn(); //SPAWN IN ENTITY
				changeentityproperty(vSpawn, "position", x, z, y+1000); //SET SPAWN POSITION
				changeentityproperty(vSpawn, "direction", dir); //SET SPAWN DIRECTION

				if(getglobalvar("fullEnergy") == "never" || getglobalvar("fullEnergy") == "each_new_stage"){
					changeentityproperty(vSpawn, "mp", getglobalvar("partnerMp"));  //GET LAST SAVED MP AND APPLY IT
				}

				setglobalvar("selectPartner", pName); //SET AS CURRENT SPAWNED PARTNER
				setglobalvar("currentPartner", vSpawn); //SET AS CURRENT SPAWNED PARTNER

				return vSpawn; //RETURN SPAWN
			}
		}
	}

	if(getglobalvar("partnerRespawn") == "manual"){
		void self = getlocalvar("self");
		int pMp	  = getentityproperty(self, "mp");

		setglobalvar("partnerMp", pMp);
	}
}

void resetAuraEffect() {
	void self 	= getlocalvar("self");
	setglobalvar("auraEffect"+self, NULL());
	changedrawmethod(self, "enabled", 0);
}

void dropItem(void item) {
	void self = getlocalvar("self");
	void type = getentityproperty(self,"type");
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	float z 	= getentityproperty(self, "z");

	if(item != NULL() && type == openborconstant("TYPE_ENEMY") && isBoss(self) && isAnyPlayerInDanger()) {
		clearspawnentry();
		setspawnentry("name", item);

		void vSpawn = spawn();
		changeentityproperty(vSpawn, "position", x, z, y);
		changeentityproperty(vSpawn, "direction", 0);
		tossentity(vSpawn, 1, 0, 0);

		return vSpawn;
	}
}
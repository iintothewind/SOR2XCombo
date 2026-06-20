#import "data/scripts/main.c"
#import "data/scripts/animation/main_spawns.c"

void otg()
{//Script to turn off the OTG at defined sittuations
 //Will be disabled when it is turned off at the Extra Menu, or when doesn't have enough OTG points
	void self		= getlocalvar("self");
	void other		= getlocalvar("other");
	void ani		= getentityproperty(other, "animationID");
	int otgPoints	= getentityvar(other, "otgpoints");
	int dmgonland	= getentityproperty(other, "damage_on_landing");
	int dead		= getentityproperty(other, "dead");
	int frame		= getentityproperty(other, "animpos");
	int min			= 0;

	if(getglobalvar("otgSystem") != "unlimited" && otgPoints <= min){
		if(dead != 1){
			if(ani == openborconstant("ANI_FALL") || ani == openborconstant("ANI_BURN") || ani == openborconstant("ANI_SHOCK")){
				if(frame >= 1){changeopenborvariant("lasthitc", 0);}else
				{changeopenborvariant("lasthitc", 1);}
			}
			else
			if(ani == openborconstant("ANI_FALL8") || ani == openborconstant("ANI_FALL9")){
				if(frame >= 2 && dmgonland == 0){changeopenborvariant("lasthitc", 0);}else
				{changeopenborvariant("lasthitc", 1);}
			}
			else
			{
				changeopenborvariant("lasthitc", 1);
			}
		}
	}
}

void parry()
{//Scripted parry, send the key delay to a global variable used in the "ondoattack" event
	void self		= getlocalvar("self");
	void type		= getentityproperty(self,"type");
	void grab		= getentityproperty(self,"grabbing");
	void target		= getlocalvar("other");
	if(target != NULL()) {
	void blockT		= getglobalvar("blockType");
		void grabbed	= getentityproperty(target,"grabbing");
		int pIndex		= getentityproperty(self,"playerindex");
		int which		= getlocalvar("which");
		int atkType		= getlocalvar("attacktype");
		int damage		= getlocalvar("damage");
		int jump		= getentityproperty(self,"aiflag","jumping");
		int drop		= getentityproperty(self,"aiflag","drop");
		int pain		= getentityproperty(self,"aiflag","inpain");
		int fall		= getentityproperty(self,"aiflag","falling");
		int dead		= getentityproperty(self,"dead");
		int seal		= getentityproperty(self,"seal");
		float time		= openborvariant("elapsed_time");

		if(blockT == "parry" || blockT == "parry_(alt._mode_on)"){
			if(type == openborconstant("TYPE_PLAYER")){
				if(atkType != openborconstant("ATK_NORMAL10") && atkType != openborconstant("ATK_TIMEOVER")){ //AVOID ATK_10 (USED FOR ROUTE MENU AND DOORS) AND TIMEOVER DAMAGE
					if(which == 1){
						if(grab == NULL() && grabbed != self && damage > 0){
							if(jump == 0 && drop == 0 && pain == 0 && fall == 0 && dead == 0 && seal == 0){
								if(getglobalvar("parryDelay"+pIndex) > time){executeanimation(self, openborconstant("ANI_FOLLOW12"), 1);}
							}
						}
					}
				}
			}
		}
	}
}

void multihits()
{//Script to avoid "multihits" bug, same as the original SOR2
 //However, to a nostalgic purpose it can be enabled in the Extra Menu

	if(getglobalvar("multiHit") == "disabled"){
		void self	= getlocalvar("self");
		void other	= getlocalvar("other");
		int atkid	= getentityproperty(self, "attackid");
		int land	= getentityproperty(other, "damage_on_landing");

		if(land <= 0){ //USED TO AVOID DAMAGE ON LANDING SITUATIONS
			if(atkid == getglobalvar("atkid"+self+other)){ //THE CURRENT ATTACKBOX ID IS SAME AS THE PREVIOUS USED ONE??
				changeopenborvariant("lasthitc", 0); //DISABLE THE ENGINE HIT HANDLING
			}
			else //THE CURRENT ATTACKBOX ID IS NOT SAME AS THE PREVIOUS USED ONE??
			{
				changeopenborvariant("lasthitc", 1); //ENABLE THE ENGINE HIT HANDLING
			}
			setglobalvar("atkid"+self+other, atkid); //SAVE THE "LAST ATTACKBOX ID" + "CURRENT PLAYER" + "DAMAGED ENTITY"
		}
	}
}

void hitFall(int noHitFalling)
{//Disable excessive collisions during throw/slam "falling" instance

	//WORKS FOR ATTACKER ONLY
	if(!getlocalvar("which")){
		void self	= getlocalvar("self");
		void other	= getlocalvar("other");
		void vAnim	= getentityproperty(self, "animationID");
		void tAnim	= getentityproperty(other, "animationID");
		int falling	= getentityproperty(other, "aiflag", "falling");
		int drop	= getentityproperty(other, "aiflag", "drop");

		//WORKS ONLY DURING THROW OR SLAM FALL
		if(vAnim == openborconstant("ANI_FALL8") || vAnim == openborconstant("ANI_FALL9")){

			//DISABLE COLLISION IF THE OPPONENT IS ALREADY FALLING TOO
			if(falling || drop){
				changeopenborvariant("lasthitc", 0);
			}
		}

		//EXCEPTION FOR ADAM'S ORIGINAL SOR1 BEHAVIOUR,
		//APPLY BLAST PROPERTY IN THE THIRD ATTACK OF THE DEFAULT COMBO IF THE OPPONENT IS IN THE AIR
		if(vAnim == openborconstant("ANI_ATTACK3")){
			void dModel = getentityproperty(self,"defaultmodel");

			if(dModel == "Adam" || dModel == "Adam$"){
				int Ty	= getentityproperty(other,"y");
				int Tb	= getentityproperty(other,"base");

				if(Ty <= Tb){
					setentityvar(self, "noBowling", 1);
				}
				else
				{
					setentityvar(self, "noBowling", NULL());
				}
			}
		}

		//EXCEPTION FOR SOME LASERS, DON'T ALLOW TO HIT OPPONENTS WHILE FALLING
		if(noHitFalling){
			if(	tAnim == openborconstant("ANI_FALL")	||
				tAnim == openborconstant("ANI_FALL8")	||
				tAnim == openborconstant("ANI_FALL9")	||
				tAnim == openborconstant("ANI_BURN")	||
				tAnim == openborconstant("ANI_SHOCK")	){
				changeopenborvariant("lasthitc", 0);
			}
		}
	}
}

void loadRushHeat() {
	int rush = 999;
	void cfg = getglobalvar("rushHeat");
	if(cfg == "15") {
		rush = 15;
	} else if(cfg == "13") {
		rush = 13;
	} else if(cfg == "11") {
		rush = 11;
	} else if(cfg == "9") {
		rush = 9;
	} else if(cfg == "7") {
		rush = 7;
	} else if(cfg == "5") {
		rush = 5;
	}
	return rush;
}

void rushHeat() {
	if(getglobalvar("rushHeat") != "off"){
		int rushHeat = loadRushHeat();
		void self	 = getlocalvar("self");
		void type 		= getentityproperty(self,"type");
		int rush	 = getentityproperty(self,"rush_count");
		if(rush >= rushHeat && type == openborconstant("TYPE_PLAYER")) {
			invinc(1);
		}
	}
}

void airGet()
{//Get weapons in the air
	void self		= getlocalvar("self");
	void other		= getlocalvar("other");
	void parent		= getentityproperty(self,"parent");
	void vWeapEnt	= getentityproperty(self, "weapent");
	void tWeapEnt	= getentityproperty(other, "weapent");
	void vAnim		= getentityproperty(self, "animationID");
	void tAnim		= getentityproperty(other, "animationID");
	void vName		= getentityproperty(self, "defaultname");
	void tName		= getentityproperty(other, "defaultname");
	void vSpawn;
	int vDir		= getentityproperty(self, "direction");
	int tDir		= getentityproperty(other, "direction");

	//WORKS FOR DEFENDER ONLY, USED WHEN PLAYERS ARE HOLDING THE ATTACK BUTTON
	if(getlocalvar("which")){

		//PLAYER CHARACTERS WILL DO ALL THE JOB AT THE MOMENT THEY GET HIT BY PROJECTILES
		if(parent == NULL()){ //IF THIS ENTITY DON'T HAVE A PARENT, HE IS A PLAYER
			if(!vWeapEnt){ //CHECK IF PLAYER IS NOT ALREADY CARRYING A WEAPON
				if(	vAnim == openborconstant("ANI_IDLE")	|| //CHECK CURRENT ANIMATIONS
					vAnim == openborconstant("ANI_WALK")	||
					vAnim == openborconstant("ANI_RUN")		){

					//ATTACK BUTTON IS HELD?? PROCEED
					int pIndex = getentityproperty(self, "playerindex");

					if(playerkeys(pIndex, 0, "attack") && vDir != tDir){

						//KNIFES, ONLY SOR2 JACK CHARACTER THROW A USABLE KNIFE AGAINST PLAYERS
						if(tName == "KnifeT"){
							changeopenborvariant("lasthitc", 0);
							vSpawn = spawn01("Knife", 0, 0, 0);
							killentity(other);
							pickup(self, vSpawn);
							executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
						}

						//PIPES, ONLY SOR1 GALSIA CHARACTER THROW A USABLE PIPE AGAINST PLAYERS
						if(tName == "PipeT"){
							changeopenborvariant("lasthitc", 0);
							vSpawn = spawn01("Pipe", 0, 0, 0);
							killentity(other);
							pickup(self, vSpawn);
							executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
						}

						//KUNAI, ONLY HEROES CHARACTER THROW A USABLE KUNAI AGAINST PLAYERS
						if(tName == "KunaiT"){
							changeopenborvariant("lasthitc", 0);
							vSpawn = spawn01("Kunai", 0, 0, 0);
							killentity(other);
							pickup(self, vSpawn);
							executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
						}

						//SWORD, ONLY HEROES CHARACTER THROW A USABLE SWORD AGAINST PLAYERS
						if(tName == "SwordT"){
							changeopenborvariant("lasthitc", 0);
							vSpawn = spawn01("Sword", 0, 0, 0);
							killentity(other);
							pickup(self, vSpawn);
							executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
						}
					}
				}
			}
		}
	}

	//WORKS FOR ATTACKER ONLY, USED IF PLAYER HITS THE PROJECTILE, OR FOR ENEMIES WHEN THE PROJECTILE HITS THEM
	if(!getlocalvar("which")){

		//PLAYER CHARACTERS WILL DO ALL THE JOB AT THE MOMENT THEY HITS ANY PROJECTILE WITH ATTACKS
		if(parent == NULL()){ //IF THIS ENTITY DON'T HAVE A PARENT, HE IS A PLAYER
			if(!vWeapEnt){ //CHECK IF PLAYER IS NOT ALREADY CARRYING A WEAPON
				if(vAnim == openborconstant("ANI_ATTACK1")){ //CHECK FOR AUTHORIZED ANIMATIONS

					//KNIFES, ONLY JACK CHARACTER THROW A USABLE WEAPON AGAINST PLAYERS
					if(tName == "KnifeT"){
						changeopenborvariant("lasthitc", 0);
						vSpawn = spawn01("Knife", 0, 0, 0);
						killentity(other);
						pickup(self, vSpawn);
						executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
					}

					//KNIFES, ONLY HEROES CHARACTER THROW A USABLE WEAPON AGAINST PLAYERS
					if(tName == "KunaiT"){
						changeopenborvariant("lasthitc", 0);
						vSpawn = spawn01("Kunai", 0, 0, 0);
						killentity(other);
						pickup(self, vSpawn);
						executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
					}

					//KNIFES, ONLY HEROES CHARACTER THROW A USABLE WEAPON AGAINST PLAYERS
					if(tName == "PipeT"){
						changeopenborvariant("lasthitc", 0);
						vSpawn = spawn01("Pipe", 0, 0, 0);
						killentity(other);
						pickup(self, vSpawn);
						executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
					}

					//KNIFES, ONLY HEROES CHARACTER THROW A USABLE WEAPON AGAINST PLAYERS
					if(tName == "SwordT"){
						changeopenborvariant("lasthitc", 0);
						vSpawn = spawn01("Sword", 0, 0, 0);
						killentity(other);
						pickup(self, vSpawn);
						executeanimation(self, openborconstant("ANI_FOLLOW13"), 1);
					}
				}
			}
		}

		//ENEMIES GETTING WEAPONS ON THE AIR
		//PLAYER'S PROJECTILES WILL DO ALL THE JOB AT THE MOMENT THEY HIT THE ENEMIES
		if(parent != NULL()){ //IF THIS ENTITY HAVE A PARENT, HE IS A PROJECTILE
			if(!tWeapEnt){ //CHECK IF THE TARGET IS NOT ALREADY CARRYING A WEAPON
				if(	tAnim == openborconstant("ANI_IDLE")	|| //CHECK CURRENT ANIMATIONS
					tAnim == openborconstant("ANI_WALK")	||
					tAnim == openborconstant("ANI_RUN")		){

					//CALCULATE CHANCE
					int iR = rand()%50+50;
					int pR = 75; //25% CHANCE ON THE NOMAL DIFFICULTY

					//INCREASE CHANCE ACCORDING TO THE DIFFICULTY
					if(getglobalvar("difficulty") == "hard"){	pR = 50;} //50% CHANCE
					if(getglobalvar("difficulty") == "mania"){	pR = 25;} //75% CHANCE

					// if(iR > pR && vDir != tDir){
					if(vDir != tDir){

						//KNIFES, USED BY JACK
						if(getentityvar(other, "useKnife") == 1){ //IS ALLOWED TO USE A KNIFE?? PROCEED
							if(vName == "KnifeT"){
								changeopenborvariant("lasthitc", 0);
								vSpawn = spawn01("Knife", 0, 0, 0);
								pickup(other, vSpawn);
								executeanimation(other, openborconstant("ANI_FOLLOW13"), 1);
								killentity(self);
							}
						}

						//KUNAIS, USED BY NINJAS
						if(getentityvar(other, "useKunai") == 1){ //IS ALLOWED TO USE A KUNAI?? PROCEED
							if(vName == "KunaiT"){
								changeopenborvariant("lasthitc", 0);
								vSpawn = spawn01("Kunai", 0, 0, 0);
								pickup(other, vSpawn);
								executeanimation(other, openborconstant("ANI_FOLLOW13"), 1);
								killentity(self);
							}
						}

						//PIPES, USED BY BIKERS
						if(getentityvar(other, "usePipe") == 1){ //IS ALLOWED TO USE A PIPE?? PROCEED
							if(vName == "PipeT"){
								changeopenborvariant("lasthitc", 0);
								vSpawn = spawn01("Pipe", 0, 0, 0);
								pickup(other, vSpawn);
								executeanimation(other, openborconstant("ANI_FOLLOW13"), 1);
								killentity(self);
							}
						}

						//SWORDS, USED BY NINJAS
						if(getentityvar(other, "useSword") == 1){ //IS ALLOWED TO USE A SWORD?? PROCEED
							if(vName == "SwordT"){
								changeopenborvariant("lasthitc", 0);
								vSpawn = spawn01("Sword", 0, 0, 0);
								pickup(other, vSpawn);
								executeanimation(other, openborconstant("ANI_FOLLOW13"), 1);
								killentity(self);
							}
						}
					}
				}
			}
		}
	}
}

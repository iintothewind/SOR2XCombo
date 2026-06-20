#import "data/scripts/main.c"


void dasher(float Vx, float Vy, float Vz)
{//Dash with desired speed!
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self,"direction");

	if(dir == 0){Vx = -Vx ;}
	changeentityproperty(self, "velocity", Vx, Vz, Vy);
}

void pressTwice()
{//Global registration when the player presses "Left or Right" directions twice before performs any running attack
 //This script will register the ">>" command as a single input to make some key script easier to develop
	void self 	 = getlocalvar("self");
	int iPIndex  = getlocalvar("player");
	int dir 	 = getentityproperty(self,"direction");
	float time	 = openborvariant("elapsed_time");
	float delay	 = 30;

	//STEP 1 - REGISTER "DIRECTIONAL" KEYS RELEASED
	if(playerkeys(iPIndex, 2, "moveleft") && dir == 0){
		setglobalvar("releaseLeft"+iPIndex, time+delay);
	}
	if(playerkeys(iPIndex, 2, "moveright") && dir == 1){
		setglobalvar("releaseRight"+iPIndex, time+delay);
	}

	//STEP 2 - CHECK IF THE CURRENTLY PRESSED KEY WAS RELEASED BEFORE WITH THE CORRECT DELAY AND REGISTER THE "DIRECTIONAL" KEYS PRESSED AGAIN
	if(playerkeys(iPIndex, 1, "moveleft") && dir == 0){
		if(getglobalvar("releaseLeft"+iPIndex) > time){
			setglobalvar("pressLeft"+iPIndex, time+delay);
			setglobalvar("releaseLeft"+iPIndex, NULL());
		}
	}
	if(playerkeys(iPIndex, 1, "moveright") && dir == 1){
		if(getglobalvar("releaseRight"+iPIndex) > time){
			setglobalvar("pressRight"+iPIndex, time+delay);
			setglobalvar("releaseRight"+iPIndex, NULL());
		}
	}
}

void pressQcf()
{//Global registration when the player presses "QCF" command before performs any rage attack
 //This script will register the "DOWN>FRONT" command as a single input to make some key script easier to develop
	void self 	 = getlocalvar("self");
	int iPIndex  = getlocalvar("player");
	int dir 	 = getentityproperty(self,"direction");
	float time	 = openborvariant("elapsed_time");
	float delay	 = 30;

	//STEP 1 - REGISTER "DOWN" KEY PRESSED
	if(playerkeys(iPIndex, 1, "movedown")){
		setglobalvar("qcfDown"+iPIndex, time+delay);
	}

	//STEP 2 - REGISTER "LEFT" KEY PRESSED
	if(playerkeys(iPIndex, 1, "moveleft") && dir == 0){
		if(getglobalvar("qcfDown"+iPIndex) > time){
			setglobalvar("qcfLeft"+iPIndex, time+delay);
			setglobalvar("qcfDown"+iPIndex, NULL());
		}
	}

	//STEP 2 - REGISTER "RIGHT" KEY PRESSED
	if(playerkeys(iPIndex, 1, "moveright") && dir == 1){
		if(getglobalvar("qcfDown"+iPIndex) > time){
			setglobalvar("qcfRight"+iPIndex, time+delay);
			setglobalvar("qcfDown"+iPIndex, NULL());
		}
	}
}

void runAttack()
{//Custom running attack, used when the running animation is disabled
	void self 	 = getlocalvar("self");
	void running = getglobalvar("runType");
	void vAniID  = getentityproperty(self,"animationID");
	int valid1   = getentityproperty(self,"animvalid", openborconstant("ANI_RUNATTACK"));
	int valid2   = getentityproperty(self,"animvalid", openborconstant("ANI_FREESPECIAL2"));
	int iPIndex  = getlocalvar("player");
	int maxMp	 = getentityproperty(self,"maxMp");
	int mp		 = getentityproperty(self,"mp");
	int costMp;
	float time	 = openborvariant("elapsed_time");


	pressTwice();

	if(running == "off"){

		//THIS PART WILL EXECUTE THE RUNNING ATTACKS AND RESET ALL VARIABLES
		if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK")){
			if(getglobalvar("pressLeft"+iPIndex) > time || getglobalvar("pressRight"+iPIndex) > time){

				//NORMAL RUNNING ATTACKS
				if(playerkeys(iPIndex, 1, "attack")){
					if(valid1){
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_RUNATTACK"), 0);
						setglobalvar("pressLeft"+iPIndex, NULL());
						setglobalvar("pressRight"+iPIndex, NULL());
					}
				}

				//SUPER RUNNING ATTACKS
				if(playerkeys(iPIndex, 1, "attack2") && mp >= costMp){
					if(valid2){
						mpCost(costMp);
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
						setglobalvar("pressLeft"+iPIndex, NULL());
						setglobalvar("pressRight"+iPIndex, NULL());
					}
				}
			}
		}
	}
}

void dodge()
{//Dodge with dash
	void self 	= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void dodgeT	= getglobalvar("dodgeType");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getlocalvar("player");
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= getentityproperty(self,"zdir");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	int gp 		= getentityproperty(self,"guardpoints");
	int costGp	= maxGp/4;

	//DEFAULT DODGE COMMAND
	if(dodgeT == "sor2x" || dodgeT == "sor3"  || dodgeT == "both"){
		if(vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")){
			if(playerkeys(iPIndex, 1, "attack3")){
				if(gp >= costGp) {
					executeanimation(self, openborconstant("ANI_FOLLOW10"), 0);
					changeentityproperty(self, "velocity", xdir, zdir);
					// invinc(2);
					gpCost(costGp);
				}
			}
		}
	}

	//DEFAULT + ALTERNATIVE DODGE COMMAND
	if(dodgeT == "sor2x_(alt._mode_on)" || dodgeT == "both_(alt._mode_on)"){
		if(vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")){
			if(playerkeys(iPIndex, 1, "attack3") || playerkeys(iPIndex, 1, "attack", "special") || playerkeys(iPIndex, 0, "attack", "special")){
				if(gp >= costGp) {
					executeanimation(self, openborconstant("ANI_FOLLOW10"), 0);
					changeentityproperty(self, "velocity", xdir, zdir);
					// invinc(2);
					gpCost(costGp);
				}
			}
		}
	}
}

void dodgeJump()
{//Dodge with jump
	void self 	= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void dodgeT	= getglobalvar("dodgeType");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getlocalvar("player");
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= getentityproperty(self,"zdir");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	int gp 		= getentityproperty(self,"guardpoints");
	int costGp	= maxGp/4;

	//DEFAULT DODGE COMMAND
	if(dodgeT == "sor2x" || dodgeT == "sor3" || dodgeT == "both"){
		if(vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")){
			if(playerkeys(iPIndex, 1, "attack3")){
				if(gp >= costGp) {
					executeanimation(self, openborconstant("ANI_FOLLOW10"), 0);
					tossentity(self, 2, xdir, zdir);
					// invinc(2);
					gpCost(costGp);
				}
			}
		}
	}

	//DEFAULT + ALTERNATIVE DODGE COMMAND
	if(dodgeT == "sor2x_(alt._mode_on)" || dodgeT == "both_(alt._mode_on)"){
		if(vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")){
			if(playerkeys(iPIndex, 1, "attack3") || playerkeys(iPIndex, 1, "attack", "special") || playerkeys(iPIndex, 0, "attack", "special")){
				if(gp >= costGp) {
					executeanimation(self, openborconstant("ANI_FOLLOW10"), 0);
					tossentity(self, 2, xdir, zdir);
					// invinc(2);
					gpCost(costGp);
				}
			}
		}
	}
}

void block()
{//Used by the default and alternative block commands, and for the parry system
	void self 	 = getlocalvar("self");
	void blockT	 = getglobalvar("blockType");
	void vAniID  = getentityproperty(self, "animationID");
	int iPIndex  = getlocalvar("player");
	int dir		 = getentityproperty(self, "direction");
	float time	 = openborvariant("elapsed_time");
	float delay	 = 50;

	//DEFAULT BLOCK COMMAND
	if(blockT == "hold"){
		if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_ATTACK1")){
			if(playerkeys(iPIndex, 0, "attack3")){
				executeanimation(self, openborconstant("ANI_FOLLOW11"), 1);
				changeentityproperty(self, "velocity", 0, 0, 0);
			}
		}
	}

	//DEFAULT + ALTERNATIVE BLOCK COMMAND
	if(blockT == "hold_(alt._mode_on)"){
		if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_ATTACK1")){
			if(playerkeys(iPIndex, 0, "attack3") || playerkeys(iPIndex, 0, "attack", "special") || playerkeys(iPIndex, 1, "attack", "special")){
				executeanimation(self, openborconstant("ANI_FOLLOW11"), 1);
				changeentityproperty(self, "velocity", 0, 0, 0);
			}
		}
	}

	//DEFAULT PARRY COMMAND
	if(blockT == "parry"){
		if(playerkeys(iPIndex, 1, "attack3")){
			setglobalvar("parryDelay"+iPIndex, time+delay);
		}
	}

	//DEFAULT + ALTERNATIVE PARRY COMMAND
	if(blockT == "parry_(alt._mode_on)"){
		if(playerkeys(iPIndex, 1, "attack3") || playerkeys(iPIndex, 1, "moveleft") && dir == 0 || playerkeys(iPIndex, 1, "moveright") && dir == 1){
			setglobalvar("parryDelay"+iPIndex, time+delay);
		}
	}
}

void airRecovery()
{//Cancel Player knockdown fall if defined button is pressed with guardpoints cost (HEROES ONLY)
	void self	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getlocalvar("player");
	int frame	= getentityproperty(self,"animpos");
	int health 	= getentityproperty(self,"health");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	int gp 		= getentityproperty(self,"guardpoints");
	int costGp	= maxGp/4;

	if(vAniID == openborconstant("ANI_FALL") && frame == 0){
		if(health >= 1 && gp >= costGp){
			if(playerkeys(iPIndex, 0, "jump", "moveup")){
				gpCost(costGp);
				executeanimation(self, openborconstant("ANI_FOLLOW9"), 1);
				// spawnText("Moves", "AERIAL_RECOVER");
			}
		}
	}
}

void grabEscape()
{//Escape when grabbed
	void self 	= getlocalvar("self");
	void target = getentityproperty(self,"opponent");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getlocalvar("player");
	int dir		= getentityproperty(self,"direction");
	int dead	= getentityproperty(self,"dead");
	int targetDead	= getentityproperty(target,"dead");
	void targetAni 		= getentityproperty(target, "animationID");
	int targetVulnerable	= getentityproperty(target, "vulnerable");
	int targetInvincible	= getentityproperty(target, "invincible");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	int gp 		= getentityproperty(self,"guardpoints");
	int costGp	= maxGp*0.67;
	int xVel	= 2;

	if(dir == 0){xVel = -xVel;}

	if(vAniID == openborconstant("ANI_GRABBED")){
		if(gp >= costGp && dead == 0 && targetDead == 0 && targetInvincible == 0 && targetVulnerable == 1){
			if(playerkeys(iPIndex, 1, "attack")){
				gpCost(costGp);
				damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL"));
				tossentity(target, 0.2, xVel, 0);
				performattack(self, openborconstant("ANI_FOLLOW6"), 0);
				// spawnText("Moves", "GRAB_ESCAPE");
			}
		}
	}
}

void counter()
{//Execute counter attacks, for PLAYERS
	void self 		= getlocalvar("self");
	void target 	= getglobalvar("blocked"+self);
	void rewardCfg = getglobalvar("counterAttackReward");
	int block  		= getentityproperty(self, "aiflag", "blocking");
	int iPIndex 	= getlocalvar("player");
	float freeze	= 40;

	if(block == 1 && getglobalvar("didBlock"+self) >= openborvariant("elapsed_time")){
		if(playerkeys(iPIndex, 0, "moveleft") || playerkeys(iPIndex, 0, "moveright") || playerkeys(iPIndex, 1, "attack2")){
			performattack(self, openborconstant("ANI_FOLLOW7"), 1);
			changeentityproperty(self, "aiflag", "frozen", 1);
			changeentityproperty(self, "freezetime", openborvariant("elapsed_time")+freeze);

			changeentityproperty(target, "aiflag", "frozen", 1);
			changeentityproperty(target, "freezetime", openborvariant("elapsed_time")+freeze*2);

			if(rewardCfg != "off"){
				float counterAttackReward = loadCounterAttackReward();
				float maxMp		= getentityproperty(self, "maxmp");
				float mp			= getentityproperty(self, "mp");
				float skillLevel = getCharSkillLevel(self);
				float rewardRate = skillLevel*0.2*counterAttackReward;
				float invincibleTime = 2*rewardRate;
				float mpRecover		= maxMp*0.25*rewardRate;
				changeentityproperty(self, "mp", mp+mpRecover);
				if(counterAttackReward >= 1) {
					invinc(invincibleTime);
				}
			}

			// spawnText("Moves", "COUNTER");
			setglobalvar("blocked"+self, NULL());
			setglobalvar("didBlock"+self, NULL());
		}
	}else{
		setglobalvar("blocked"+self, NULL());
		setglobalvar("didBlock"+self, NULL());
	}
}

void chargeAttack()
{//Hold button to make a charged attack
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int valid2 	= getentityproperty(self,"animvalid", openborconstant("ANI_ATTACK2"));
	int valid3 	= getentityproperty(self,"animvalid", openborconstant("ANI_ATTACK3"));
	int iPIndex = getlocalvar("player");
	float delay	= 150;

	if(getglobalvar("activeText") == 0){
		if(playerkeys(iPIndex, 1, "attack")){setglobalvar("chargeStart"+iPIndex, NULL());}

		if(playerkeys(iPIndex, 0, "attack")){
			if(getglobalvar("chargeStart"+iPIndex) == NULL()){setglobalvar("chargeStart"+iPIndex, openborvariant("elapsed_time")+delay);}
		}
		else
		if(playerkeys(iPIndex, 2, "attack")){
			if(openborvariant("elapsed_time") > getglobalvar("chargeStart"+iPIndex)){
				if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")){

					//USED TO CHECK IF THE ENTITY HAS ATTACK3 ANIMATION
					if(valid3 == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK3"), 0);
						setglobalvar("chargeStart"+iPIndex, NULL());
					}
					else //USED TO CHECK IF THE ENTITY HAS ATTACK2 ANIMATION, WHEN DON'T HAVE ATTACK3
					if(valid3 == 0 && valid2 == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK2"), 0);
						setglobalvar("chargeStart"+iPIndex, NULL());
					}else{
						setglobalvar("chargeStart"+iPIndex, NULL()); //USED FOR ANY OTHER COMBINATION, CANCEL CHARGE ATTACK
					}
				}
			}else{
				setglobalvar("chargeStart"+iPIndex, NULL());
			}
		}else{
			setglobalvar("chargeStart"+iPIndex, NULL());
		}
	}
}

void extraButton(void ani)
{//Change animations with global variable "extraButtom" check
 //Used in entities that have attack3/back attack moves (ALL HEROES/BEAR/ROO)
	void self    = getlocalvar("self");
	void defaultName		= getentityproperty(self, "defaultname");
	int dir 	= getentityproperty(self,"direction");
	void eButton = getglobalvar("extraButton");
	void vAniID  = getentityproperty(self, "animationID");
	int iPIndex  = getlocalvar("player");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	int gp 		= getentityproperty(self,"guardpoints");
	int costGp	= maxGp/2;

	if(playerkeys(iPIndex, 1, "attack4")){
		if(	vAniID == openborconstant("ANI_IDLE")	||
			vAniID == openborconstant("ANI_WALK")	||
			vAniID == openborconstant("ANI_RUN")	||
			vAniID == openborconstant("ANI_JUMPLAND")){
			if(eButton == "charge_attack"){
				if(playerkeys(iPIndex, 0, "MoveUp")) {
				} else
				if(playerkeys(iPIndex, 0, "MoveDown")) {
					gpCost(gp >= costGp? costGp:gp);
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACKBOTH")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACKBOTH"), 1);
					}
				} else
				if(playerkeys(iPIndex, 0, "Moveleft") || playerkeys(iPIndex, 0, "Moveright")) {
					gpCost(gp >= costGp? costGp:gp);
					if(ani != NULL()){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant(ani), 0);
					}
					else
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK3"), 0);
					}
					else //USED TO CHECK IF THE ENTITY HAS ATTACK2 ANIMATION, WHEN DON'T HAVE ATTACK3
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 0 && getentityproperty(self,"animvalid", openborconstant("ANI_ATTACK2")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK2"), 0);
					}
				} else {
					gpCost(gp >= costGp? costGp:gp);
					if(ani != NULL()){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant(ani), 0);
					}
					else
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK3"), 0);
					}
					else //USED TO CHECK IF THE ENTITY HAS ATTACK2 ANIMATION, WHEN DON'T HAVE ATTACK3
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 0 && getentityproperty(self,"animvalid", openborconstant("ANI_ATTACK2")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK2"), 0);
					}
				}
			}
			else
			if(eButton == "back_attack"){
				if(playerkeys(iPIndex, 0, "Moveleft") || playerkeys(iPIndex, 0, "Moveright")) {
					gpCost(gp >= costGp? costGp:gp);
					if(ani != NULL()){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant(ani), 0);
					}
					else
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK3"), 0);
					}
					else //USED TO CHECK IF THE ENTITY HAS ATTACK2 ANIMATION, WHEN DON'T HAVE ATTACK3
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK3")) == 0 && getentityproperty(self,"animvalid", openborconstant("ANI_ATTACK2")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACK2"), 0);
					}
				} else {
					gpCost(gp >= costGp? costGp:gp);
					if(getentityproperty(self, "animvalid", openborconstant("ANI_ATTACKBOTH")) == 1){
						setidle(self, openborconstant("ANI_IDLE"));
						changeentityproperty(self, "velocity", 0, 0, 0);
						performattack(self, openborconstant("ANI_ATTACKBOTH"), 1);
					}
				}
			}
		}
	}
}

void okBar()
{//Allow the player to use special even if doesn't have enough health, uses the "OK" bar instead
	void self		= getlocalvar("self");
	void specialC	= getglobalvar("specialCost");
	void okBar		= getglobalvar("okBar"+self)*10;
	void target		= getentityproperty(self,"opponent");
	void vAniID		= getentityproperty(self,"animationID");
	int iPIndex		= getlocalvar("player");
	int pain		= getentityproperty(self,"aiflag", "inpain");
	int seal		= getentityproperty(self,"seal");
	int health		= getentityproperty(self,"health");
	int dir			= getentityproperty(self,"direction");
	int cost		= getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL"));
	int valid1		= getentityproperty(self,"animvalid", openborconstant("ANI_SPECIAL"));
	int valid2		= getentityproperty(self,"animvalid", openborconstant("ANI_SPECIAL2"));

	if(specialC == "sor3_'ok'_bar"){
		if(playerkeys(iPIndex, 1, "special")){
			if(okBar >= cost && health <= cost){
				if(vAniID == openborconstant("ANI_GRAB")){
					if(valid1 == 1){
						setglobalvar("noRecover"+self, 1);
						damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}

				if(pain == 1 && seal == 0){
					if(valid1 == 1){
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}

				if(vAniID == openborconstant("ANI_IDLE")){
					if(valid1 == 1){
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}

				if(vAniID == openborconstant("ANI_JUMPLAND")){
					if(playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1){
						if(valid2 == 1){
							setglobalvar("noRecover"+self, 1);
							performattack(self, openborconstant("ANI_SPECIAL2"), 0);
						}
						else
						{
							setglobalvar("noRecover"+self, 1);
							performattack(self, openborconstant("ANI_SPECIAL"), 0);
						}
					}
					else
					{
						if(valid1 == 1){
							setglobalvar("noRecover"+self, 1);
							performattack(self, openborconstant("ANI_SPECIAL"), 0);
						}
					}
				}

				if(vAniID == openborconstant("ANI_WALK")){
					if(valid2 == 1){
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
					else
					{
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}

				}

				if(vAniID == openborconstant("ANI_RUN")){
					if(valid2 == 1){
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
					else
					{
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}
			}
		}
	}
}

void mpCost(float cost)
{//Spend some mp
	void self = getlocalvar("self");
	float mp 	  = getentityproperty(self,"mp");

	if(mp >= cost) {
		changeentityproperty(self, "mp", mp-cost);
	} else {
		changeentityproperty(self, "mp", 0);
	}
}

void hpCost(float cost)
{//Spend some hp
	void self = getlocalvar("self");
	float hp	  = getentityproperty(self,"health");
	if(hp >= cost) {
		changeentityproperty(self, "health", hp-cost);
	}
}

void gpCost(float cost)
{//Spend some gp
	void self = getlocalvar("self");
	float gp  = getentityproperty(self,"guardpoints");
	if(gp >= cost) {
		changeentityproperty(self, "guardpoints", gp-cost);
	} else {
		changeentityproperty(self, "guardpoints", 0);
	}
}

void onScreen()
{//Anti stuck off-screen, checks position on-screen
 //If entity is off-screen, will be moved with defined distance
 //Script for emergency re-adjust players position on-screen if stucked outside of the screen
	void self 		= getlocalvar("self");
	void type 		= getentityproperty(self,"type");
	void vAnID 		= getentityproperty(self,"animationID");
	void subType	= getentityproperty(self,"subtype");
	int iPIndex 	= getlocalvar("player");
	int subScreen	= getentityproperty(self, "subject_to_screen");
	float hRes		= openborvariant("hresolution");
	float x 		= getentityproperty(self, "x");
	float xPos 		= openborvariant("xpos");
	float R 		= (xPos+hRes); // Right side of the screen
	float L 		= (xPos); //Left side of the screen

	if(vAnID == openborconstant("ANI_WALK") || vAnID == openborconstant("ANI_RUN") || vAnID == openborconstant("ANI_ATTACK1")){
		if(subScreen == 1){
			if(type == openborconstant("TYPE_PLAYER")){
				if(playerkeys(iPIndex, 0, "moveleft") || playerkeys(iPIndex, 0, "moveright") || playerkeys(iPIndex, 0, "moveup") || playerkeys(iPIndex, 0, "movedown")){
					if(x > R){changeentityproperty(self, "position", R-20);}else
					if(x < L){changeentityproperty(self, "position", L+20);}
				}
			}

			if(type == openborconstant("TYPE_NPC") && subType == openborconstant("SUBTYPE_FOLLOW")){
				if(x > R){changeentityproperty(self, "position", R-20);}else
				if(x < L){changeentityproperty(self, "position", L+20);}
			}
		}
	}
}

void readKey(void key) {
	void self = getlocalvar("self");
	int pindex = getentityproperty(self,"playerindex");
	int facing = getentityproperty(self, "direction");

	if(key=="left" || key=="l") { return playerkeys(pindex, 0, "moveleft"); }
	else if(key=="right" || key=="r") { return playerkeys(pindex, 0, "moveright"); }
	else if(key=="up" || key=="u") { return playerkeys(pindex, 0, "moveup"); }
	else if(key=="down" || key=="d") { return playerkeys(pindex, 0, "movedown"); }
	else if(key=="attack" || key=="atk" || key=="a") { return playerkeys(pindex, 0, "attack"); }
	else if(key=="attack2" || key=="atk2" || key=="a2") { return playerkeys(pindex, 0, "attack2"); }
	else if(key=="attack3" || key=="atk3" || key=="a3") { return playerkeys(pindex, 0, "attack3"); }
	else if(key=="attack4" || key=="atk4" || key=="a4") { return playerkeys(pindex, 0, "attack4"); }
	else if(key=="jump" || key=="j") { return playerkeys(pindex, 0, "jump"); }
	else if(key=="special" || key=="sp" || key=="s") { return playerkeys(pindex, 0, "special"); }
	else if(key=="backward" || key=="back" || key=="b") {
		if(facing) { return playerkeys(pindex, 0, "moveleft"); }
		else { return playerkeys(pindex, 0, "moveright"); }
	}
	else if(key=="forward" || key=="fwd" || key=="f") {
		if(facing) { return playerkeys(pindex, 0, "moveright"); }
		else { return playerkeys(pindex, 0, "moveleft"); }
	}
	else { return 0; }
}
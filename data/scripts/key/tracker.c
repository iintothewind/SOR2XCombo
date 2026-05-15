#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		dodge();
		rageCancel();
		specialCancel();
		runCancel();
		runAttack();
		chargeAttack();
		extraButton();
		okBar();
		onScreen();
	}
}

void rageCancel()
{//Cancel defined moves with Rage Attacks
	void self 	 = getlocalvar("self");
	void vAniID  = getentityproperty(self,"animationID");
	int iPIndex  = getlocalvar("player");
	int height	 = getentityproperty(self,"y");
	int base	 = getentityproperty(self,"base");
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int maxMp	 = getentityproperty(self,"maxMp");
	int mp		 = getentityproperty(self,"mp");
	int costMp	 = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL"));
	float time	 = openborvariant("elapsed_time");

	pressQcf();

	if(playerkeys(iPIndex, 0, "attack2") && mp >= costMp && rush >= 1 && hits >= 1){
		if(getglobalvar("qcfLeft"+iPIndex) > time || getglobalvar("qcfRight"+iPIndex) > time || playerkeys(iPIndex, 1, "special")){
			if(vAniID == openborconstant("ANI_ATTACK3")){
				mpCost(costMp);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}

			if(vAniID == openborconstant("ANI_RUNATTACK")){
				mpCost(costMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}

			if(vAniID == openborconstant("ANI_SPECIAL") && height == base){
				mpCost(costMp);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}
		}
	}
}

void specialCancel()
{//Cancel defined moves with Special Attacks
	void self 	 = getlocalvar("self");
	void okBar	 = getglobalvar("okBar"+self)*10;
	void target  = getentityproperty(self,"opponent");
	void vAniID  = getentityproperty(self,"animationID");
	int iPIndex  = getlocalvar("player");
	int dir 	 = getentityproperty(self,"direction");
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int health	 = getentityproperty(self,"health");
	int mp		 = getentityproperty(self,"mp");
	int cost	 = getentityproperty(self,"energycost", "cost", openborconstant("ANI_SPECIAL"));
	int mPonly	 = getentityproperty(self,"energycost", "mponly", openborconstant("ANI_SPECIAL"));

	if(playerkeys(iPIndex, 1, "special")){
		if(playerkeys(iPIndex, 0, "moveleft") && dir == 0 || playerkeys(iPIndex, 0, "moveright") && dir == 1){
			if(rush >= 1 && hits >= 1){
				if(mPonly == 1 && mp >= cost || mPonly == 0 && mp >= cost){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						mpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						mpCost(cost);
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
				else
				if(mPonly == 2 && health > cost || mPonly == 0 && health > cost){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						hpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						hpCost(cost);
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
				else
				if(okBar >= cost && health <= cost){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						setglobalvar("noRecover"+self, 1);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
			}
		}
		else
		{
			if(mPonly == 1 && mp >= cost || mPonly == 0 && mp >= cost){
				if(vAniID == openborconstant("ANI_GRAB")){
					mpCost(cost);
					damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}

				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						mpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						mpCost(cost);
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}
			}
			else
			if(mPonly == 2 && health > cost || mPonly == 0 && health > cost){
				if(vAniID == openborconstant("ANI_GRAB")){
					hpCost(cost);
					damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}

				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						hpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						hpCost(cost);
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}
			}
			else
			if(okBar >= cost && health <= cost){
				if(vAniID == openborconstant("ANI_GRAB")){
					setglobalvar("noRecover"+self, 1);
					damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL2")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					damageentity(self, target, 0, 0, openborconstant("ATK_NORMAL")); //USED TO AVOID ENEMY FREEZES IN GRABBED ANIMATION
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}

				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK3")){
						setglobalvar("noRecover"+self, 1);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}

					if(vAniID == openborconstant("ANI_RUNATTACK")){
						changeentityproperty(self, "velocity", 0, 0, 0);
						setglobalvar("noRecover"+self, 1);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL"), 0);
					}
				}
			}
		}
	}
}

void runCancel()
{//Cancel defined moves with Running Attacks
	void self 	 = getlocalvar("self");
	void vAniID  = getentityproperty(self,"animationID");
	int iPIndex  = getlocalvar("player");
	int dir 	 = getentityproperty(self,"direction");
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int maxMp	 = getentityproperty(self,"maxMp");
	int mp		 = getentityproperty(self,"mp");
	int costMp	 = maxMp/3;
	float time	 = openborvariant("elapsed_time");

	if(vAniID == openborconstant("ANI_ATTACK3")){

		if(getglobalvar("pressLeft"+iPIndex) > time || getglobalvar("pressRight"+iPIndex) > time){
			if(rush >= 1 && hits >= 1){

				//NORMAL RUNNING ATTACKS
				if(playerkeys(iPIndex, 1, "attack")){
					setglobalvar("runCancel"+self, openborvariant("elapsed_time"));
					performattack(self, openborconstant("ANI_RUNATTACK"), 0);
					setglobalvar("pressLeft"+iPIndex, NULL());
					setglobalvar("pressRight"+iPIndex, NULL());
				}
			}
		}
	}
}
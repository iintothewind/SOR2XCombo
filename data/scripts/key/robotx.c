#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		rageCancel();
		specialCancel();
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
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int maxMp	 = getentityproperty(self,"maxMp");
	int mp		 = getentityproperty(self,"mp");
	int costMp	 = getentityproperty(self,"energycost", "cost", openborconstant("ANI_FREESPECIAL"));
	float time	 = openborvariant("elapsed_time");

	pressQcf();

	if(playerkeys(iPIndex, 0, "attack2") && mp >= costMp && rush >= 1 && hits >= 1){
		if(getglobalvar("qcfLeft"+iPIndex) > time || getglobalvar("qcfRight"+iPIndex) > time || playerkeys(iPIndex, 1, "special")){
			if(vAniID == openborconstant("ANI_ATTACK2")){
				mpCost(costMp);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}

			if(vAniID == openborconstant("ANI_SPECIAL")){
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
		if(rush >= 1 && hits >= 1){
			if(mPonly == 1 && mp >= cost || mPonly == 0 && mp >= cost){
				if(vAniID == openborconstant("ANI_ATTACK2")){
					mpCost(cost);
					setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}
			}
			else
			if(mPonly == 2 && health > cost || mPonly == 0 && health > cost){
				if(vAniID == openborconstant("ANI_ATTACK2")){
					hpCost(cost);
					setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}
			}
			else
			if(okBar >= cost && health <= cost){
				if(vAniID == openborconstant("ANI_ATTACK2")){
					setglobalvar("noRecover"+self, 1);
					setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
					performattack(self, openborconstant("ANI_SPECIAL"), 0);
				}
			}
		}
	}
}
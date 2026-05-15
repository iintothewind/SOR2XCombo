#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		rageCancel();
		atkChange();
		runAttack();
		okBar();
		getItem();
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
			if(vAniID == openborconstant("ANI_FREESPECIAL3") && height == base){
				mpCost(costMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}

			if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
				mpCost(costMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				setglobalvar("qcfDown"+iPIndex, NULL());
				setglobalvar("qcfLeft"+iPIndex, NULL());
				setglobalvar("qcfRight"+iPIndex, NULL());
			}
		}
	}
}

void atkChange()
{//Change attacks with if defined button is pressed
	void self 	 = getlocalvar("self");
	void vAniID  = getentityproperty(self,"animationID");
	int iPIndex  = getlocalvar("player");
	int height	 = getentityproperty(self,"y");
	int base	 = getentityproperty(self,"base");

	if(playerkeys(iPIndex, 1, "jump")){
		if(vAniID == openborconstant("ANI_LAND")){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
		}
	}

	if(playerkeys(iPIndex, 0, "attack")){
		if(vAniID == openborconstant("ANI_FREESPECIAL3") && height == base){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_ATTACK1"), 0);
		}
	}

	if(playerkeys(iPIndex, 0, "attack")){
		if(vAniID == openborconstant("ANI_RUNATTACK") && height == base){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_ATTACK1"), 0);
		}
	}
}

void getItem()
{//Change to alternative "GET" animation
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getlocalvar("player");

	if(playerkeys(iPIndex, 1, "attack3")){
		if(vAniID == openborconstant("ANI_IDLE")){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_GET"), 0);
		}
		if(vAniID == openborconstant("ANI_WALK")){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_GET"), 0);
		}
		if(vAniID == openborconstant("ANI_RUN")){
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_GET"), 0);
		}
	}
}
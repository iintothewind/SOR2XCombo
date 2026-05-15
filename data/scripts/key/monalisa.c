#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		rageCancel();
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
			if(vAniID == openborconstant("ANI_ATTACK1") && height == base){
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
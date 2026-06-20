#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		specialCancel();
		runAttack();
		chargeAttack();
		extraButton();
		okBar();
		block();
		onScreen();
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
			if(mPonly == 1 && mp >= cost || mPonly == 0 && mp >= cost){
				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK2")){
						mpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
			}
			else
			if(mPonly == 2 && health > cost || mPonly == 0 && health > cost){
				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK2")){
						hpCost(cost);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
			}
			else
			if(okBar >= cost && health <= cost){
				if(rush >= 1 && hits >= 1){
					if(vAniID == openborconstant("ANI_ATTACK2")){
						setglobalvar("noRecover"+self, 1);
						setglobalvar("specialCancel"+self, openborvariant("elapsed_time"));
						performattack(self, openborconstant("ANI_SPECIAL2"), 0);
					}
				}
			}
		}
		else
		{
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
}
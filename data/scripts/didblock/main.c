#import "data/scripts/main.c"
#include "data/scripts/assets.h"

void guardCost()
{//Default guard cost for all entities when block attacks, play sound effects
	void self 		= getlocalvar("self");
	void sType	= getentityproperty(self,"type");
	void attacker	= getlocalvar("attacker");
	void blockT		= getglobalvar("blockType");
	int damage		= getlocalvar("damage");
	int offense		= getentityproperty(attacker, "offense");
	int gp			= getentityproperty(self, "guardpoints");

	if(blockT == "hold" || blockT == "hold_(alt._mode_on)" || blockT == "off"){
		if(gp >= 0){
			damage = damage*offense;

			if(gp-damage < 0){
				damage = (sType == openborconstant("TYPE_PLAYER") || isBoss(self)) ? gp-1 : gp;
			}
			changeentityproperty(self, "guardpoints", gp-damage);
			playsample(SAMPLE_BLOCK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
		}
	}

	if(blockT == "parry" || blockT == "parry_(alt._mode_on)"){
		if(gp >= 0){
			damage = 4;

			if(gp-damage < 0){
				damage = gp;
			}
			changeentityproperty(self, "guardpoints", gp-damage);
			playsample(SAMPLE_PARRY, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
		}
	}
}

void pushBack()
{//Push back entity if block attacks, default for all entities
	void self	= getlocalvar("self");
	int dir		= getentityproperty(self, "direction");
	int xVel	= -2;
	int yVel	= 0.001;

	if(dir == 0){xVel = -xVel;}
	tossentity(self, yVel, xVel, 0);
}

void counter()
{//Execute counter attacks, for PLAYERS, ENEMIES and NPCS
	void self 		= getlocalvar("self");
	void target 	= getlocalvar("attacker");
	void rewardCfg = getglobalvar("counterAttackReward");
	int damage		= getlocalvar("damage");
	int iType 		= getentityproperty(self, "type");
	float delay		= 50;
	float selfFreeze	= 40;
	float targetFreeze	= 100;

	if(damage > 0){
		if(iType == openborconstant("TYPE_PLAYER")){
			setglobalvar("blocked"+self, target);
			setglobalvar("didBlock"+self, openborvariant("elapsed_time")+delay);
		}

		if(iType != openborconstant("TYPE_PLAYER")){
			performattack(self, openborconstant("ANI_FOLLOW7"), 1);
			changeentityproperty(self, "aiflag", "frozen", 1);
			changeentityproperty(target, "aiflag", "frozen", 1);
			changeentityproperty(self, "freezetime", openborvariant("elapsed_time")+selfFreeze);
			changeentityproperty(target, "freezetime", openborvariant("elapsed_time")+targetFreeze);
			if(rewardCfg != "off"){
				float counterAttackReward = loadCounterAttackReward();
				float maxMp		= getentityproperty(self, "maxmp");
				float mp			= getentityproperty(self, "mp");
				float mpRecover		= maxMp/5*getCharSkillLevel(self)*counterAttackReward;
				changeentityproperty(self, "mp", mp+mpRecover);
			}
		}
	}
}

void parry()
{//Scripted parry, freezes the opponent to give a little "pause moment" effect during the block, like SF3 Third Strike
	void self		= getlocalvar("self");
	void target		= getlocalvar("attacker");
	void blockT		= getglobalvar("blockType");
	float time		= openborvariant("elapsed_time");
	float freeze	= 30;

	changeentityproperty(target, "aiflag", "frozen", 1);
	changeentityproperty(target, "freezetime", time+freeze*3);
}
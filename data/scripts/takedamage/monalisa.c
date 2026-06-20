#import "data/scripts/main.c"
#include "data/scripts/assets.h"

void sisterHelp()
{//Script to make teamwork jumpattack, a main character controls some actions of a secondary character in defined conditions
	void self 	= getlocalvar("self");
	void sister	= getentityvar(self, "sister");
	void type 	= getentityproperty(self,"type");
	int base	 = getentityproperty(self,"base");
	int height	 = getentityproperty(self,"y");
	void grabbed = getentityvar(self,"grabbed");
	void grabbing = getentityproperty(self, "grabbing");
	int atkType	= getlocalvar("attacktype");
	int damage 	= getlocalvar("damage");
	int dead	= getentityproperty(self,"dead");
	int fall	= getentityproperty(self,"aiflag","falling");
	int hp	 = getentityproperty(self,"health");
	int maxHp	= getentityproperty(self, "maxhealth");
	int selfMp 		= getentityproperty(self, "mp");
	int selfMaxMp 	= getentityproperty(self, "maxmp");
	int gp		= getentityproperty(self,"guardpoints");
	int maxGp	= getentityproperty(self,"maxguardpoints");
	void ani = getentityproperty(self,"animationID");
	int set 	= openborvariant("current_set");

	if(sister != NULL()) {

    int sysHp	 = getentityproperty(sister,"health");

    if(type == openborconstant("TYPE_ENEMY")
    && height == base
    && dead == 0
    && fall == 0
    && atkType != openborconstant("ATK_NORMAL10")
    && atkType != openborconstant("ATK_TIMEOVER")){
      if(sysHp > hp && (hp <= maxHp/3*2 || damage>= maxHp/10)){
        changeentityproperty(self, "health", sysHp);
        changeentityproperty(self, "mp", maxGp);
        playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
      }
    }
	}
}
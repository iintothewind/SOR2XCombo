#import "data/scripts/main.c"
#import "data/scripts/think/main.c"
#import "data/scripts/onspawn/main.c"
#include "data/scripts/assets.h"

void main()
{
	enemyAI();
	smartDodge();
  grabChance();
	enemyRushControl();
  summonBoss();
}

void grabChance()
{
	void self		= getlocalvar("self");
	int grabValid 	= getentityproperty(self,"animvalid", openborconstant("ANI_GRAB"));
	void target		= findtarget(self);
	float time		= openborvariant("elapsed_time");
	int aimove		= getentityproperty(self, "aimove");

	if(grabValid ==1 && target != NULL()) {
    void eType	= getentityproperty(target,"type");
    void sType	= getentityproperty(target,"subtype");
    if(eType != openborconstant("TYPE_OBSTACLE") && sType != openborconstant("SUBTYPE_NOTGRAB")) {
      int targetVulnerable	= getentityproperty(target, "vulnerable");
      int targetInvincible	= getentityproperty(target, "invincible");
      int targetRising			= getentityproperty(target, "aiflag", "rising");
      int targetBlink			= getentityproperty(target, "blink");
      void smarterEnemy	= getglobalvar("smarterEnemy");
			void selfAni		= getentityproperty(self, "animationID");
      void targetAni 		= getentityproperty(target, "animationID");
      int selfDir = getentityproperty(self, "direction");
      int targetDir = getentityproperty(target, "direction");
      float sx 		= getentityproperty(self,"x");
      float sy 		= getentityproperty(self,"y");
      float sz 		= getentityproperty(self,"z");
      float tx 		= getentityproperty(target,"x");
      float ty 		= getentityproperty(target,"y");
      float tz 		= getentityproperty(target,"z");
      float distanceX = tx -sx;
      float distanceZ = tz -sz;

      if(distanceX < 0) {
        distanceX = -distanceX;
      }

      if(distanceZ < 0) {
        distanceZ = -distanceZ;
      }

      if(distanceX <= 240
      && distanceZ <= 50
      && !targetInvincible && !targetRising && !targetBlink && targetVulnerable
      // && smarterEnemy == "on"
      && (targetAni == openborconstant("ANI_BLOCK")||targetAni == openborconstant("ANI_FOLLOW11"))){
        if(	selfAni == openborconstant("ANI_IDLE") ||
            selfAni == openborconstant("ANI_WALK") ||
            selfAni == openborconstant("ANI_BACKWALK")||
            selfAni == openborconstant("ANI_RUN")){
            performattack(self, openborconstant("ANI_FREESPECIAL6"), 1);
        }
      }
    }
	}
}

void summonBoss() {
	void self = getlocalvar("self");
	void selfAni  = getentityproperty(self, "animationID");
  int selfFrozen	= getentityproperty(self, "aiflag", "frozen");
	void type = getentityproperty(self, "type");
	void model 	= getentityproperty(self, "model");
	int selfMp 		= getentityproperty(self, "mp");
	int selfMaxMp 	= getentityproperty(self, "maxmp");
	int enemies	= openborvariant("count_enemies");
	int players		= openborvariant("count_players");
  int maxSummons = players > 1? players + 1 : 2;

  if(model == "Yamato_Wait1") {
    if(selfMp >= (selfMaxMp/2) && enemies < maxSummons && selfFrozen == 0) {
      if(	selfAni == openborconstant("ANI_IDLE") ||
          selfAni == openborconstant("ANI_WALK") ||
          selfAni == openborconstant("ANI_DODGE")||
          selfAni == openborconstant("ANI_BLOCK")||
          selfAni == openborconstant("ANI_RUN")){
        spawnAlias("Musashi","Yamato", 0, 0, -1, NULL(), 0, 4);
        changeentityproperty(self, "mp", 0);
        playsample(SAMPLE_BEEP3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
      }
    }
  }
}
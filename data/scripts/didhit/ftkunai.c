#import "data/scripts/main.c"
#import "data/scripts/didhit/main.c"
#include "data/scripts/assets.h"

void main()
{
    customGrab();
}

void customGrab()
{//Perform custom grabs in defined animations to avoid "followcond 2" problems
    void self         = getlocalvar("self");

    if(!selfAlive()){return;}

    void parent     = getentityproperty(self, "parent");

  if(parent != NULL()) {
    void parentType      = getentityproperty(parent,"type");
    if(parentType == openborconstant("TYPE_PLAYER")){
      void parentName        = getentityproperty(parent, "defaultname");
      void parentAnim  = getentityproperty(parent,"animationID");
      void parentGrabbed = getentityvar(parent,"grabbed");
      void parentGrabbing = getentityproperty(parent, "grabbing");
      int parentHeight     = getentityproperty(parent,"y");
      int parentBase     = getentityproperty(parent,"base");
      int parentFall    = getentityproperty(parent,"aiflag","falling");
      int parentGrabValid     = getentityproperty(parent,"animvalid", openborconstant("ANI_FOLLOW5"));

      void target     = getlocalvar("damagetaker");
      void tAniID     = getentityproperty(target,"animationID");
      int targetInvincible    = getentityproperty(target, "invincible");
      void iType      = getentityproperty(target,"type");
      void iSubType    = getentityproperty(target,"subtype");
      int tX         = getentityproperty(target,"x");
      int tY         = getentityproperty(target,"y");
      int tZ         = getentityproperty(target,"z");
      int tBase     = getentityproperty(target,"base");
      int tDir         = getentityproperty(target,"direction");
      int xOffset = 30;
      if(tDir == 0){xOffset = -xOffset;}

      if(parentAnim != openborconstant("ANI_FALL")
      && parentAnim != openborconstant("ANI_BURN")
      && parentAnim != openborconstant("ANI_SHOCK")
      && parentAnim != openborconstant("ANI_FALL6")
      && parentAnim != openborconstant("ANI_FALL7")
      && parentAnim != openborconstant("ANI_FALL8")
      && parentAnim != openborconstant("ANI_FALL9")
      && parentAnim != openborconstant("ANI_WALKOFF")
      && parentAnim != openborconstant("ANI_LAND")
      && parentAnim != openborconstant("ANI_JUMPLAND")
      && parentAnim != openborconstant("ANI_JUMPDELAY")
      && parentGrabbed == NULL() && parentGrabbing == NULL()
      && entityAlive(parent)
      && parentFall == 0
      && parentGrabValid == 1) {

        if(tAniID != openborconstant("ANI_FALL8") && tAniID != openborconstant("ANI_FALL9") && tAniID != openborconstant("ANI_FREESPECIAL") && entityAlive(target) && targetInvincible == 0){ //AVOID THROW/SLAM FALLING ANIMATION TO NOT REPEAT THE SAME GRAB MOVE
          if(iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_NPC")){
            if(iSubType != openborconstant("SUBTYPE_NOTGRAB")){
              changeentityproperty(parent,"position", tX+xOffset, tZ, 0);
              changeentityproperty(parent,"velocity", 0, 0, 0);
              changeentityproperty(parent, "aiflag", "jumping", 0);

              if(entityAlive(target)) {
                setidle(target);
                changeentityproperty(target,"position", tX, tZ, 0);
                changeentityproperty(target,"velocity", 0, 0, 0);
                executeanimation(target, openborconstant("ANI_PAIN"), 1);
                changeentityproperty(target,"takeaction", "common_pain");
                changeentityproperty(target,"damage_on_landing",0);
                changeentityproperty(target, "aiflag", "jumping", 0);
                changeentityproperty(target,"aiflag","falling",0);
                changeentityproperty(target,"aiflag","drop",0);
                changeentityproperty(target,"aiflag","projectile",0);
                changeentityproperty(target,"nograb",0);
              }

              playsample(SAMPLE_SHRING, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

              performattack(parent, openborconstant("ANI_FOLLOW5"), 0);
            }
          }
        }

      }
    }
  }
}


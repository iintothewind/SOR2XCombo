#import "data/scripts/main.c"
#include "data/scripts/assets.h"

void main() {
  playBip();
}

void playBip() {
  void self = getlocalvar("self");
  void ani = getentityproperty(self, "animationID");

    int playedSecond     = getglobalvar("playedSecond");

  if(getlocalvar("playedTick") == NULL()) {
    setlocalvar("playedTick", playedSecond);
  }

  void playedTick = getlocalvar("playedTick");

  if((ani == openborconstant("ANI_IDLE")
   || ani == openborconstant("ANI_FOLLOW1")) && playedSecond != playedTick) {
    playsample(SAMPLE_BIP1, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
    setlocalvar("playedTick", playedSecond);
    if(ani == openborconstant("ANI_IDLE")) {
      changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
    }
    if(ani == openborconstant("ANI_FOLLOW1")) {
      changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
    }
  }
}

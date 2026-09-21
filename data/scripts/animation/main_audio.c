#import "data/scripts/main.c"
#include "data/scripts/assets.h"

void samplePlay(void sample, int loop)
{//Play defined sample

    playsample(sample, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, loop);
}

void sampleAlias(void sample, void alias, int loop)
{//Play defined sample if an entity have the specified NAME (ALIAS, NOT DEFAULT NAME - VEHELITS)
    void self     = getlocalvar("self");
    void name     = getentityproperty(self, "name");

    if(name == alias){playsample(sample, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, loop);}
}

void sampleRandom(void sample1, float chance1, void sample2, float chance2, int loop)
{//Play two random samples with defined chance (ST1C THUNDER/CROWDS)
    float iR = rnd(100)-1;

    if(iR >= 0 && iR < chance1){
        playsample(sample1, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, loop);
    }
    else
    if(iR >= chance1 && iR <= chance1+chance2){
        playsample(sample2, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, loop);
    }
}

void musicPlay(void music)
{//Play defined music (SHIVA/MRX)
    void mStyle = getglobalvar("musicStyle");
    void folder;

    if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}

    playmusic(folder+music, 1);
    setglobalvar("musicPlaying", music);
}

void rndMusicPlay(void music)
{//Play pre-defined music
    void folder = "data/music/sor2x/";
    playmusic(folder+music, 1);
}
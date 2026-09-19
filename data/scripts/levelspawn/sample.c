#import "data/scripts/animation/main_audio.c"
#include "data/scripts/assets.h"

void main()
{
    void branch = openborvariant("current_branch");
    int set     = openborvariant("current_set");

    if(branch == "sor2_st2b"){
        samplePlay(SAMPLE_TRUCK, 1);
    }
    
    if(branch == "sor2_st4d"){
        samplePlay(SAMPLE_CROWD3, 1);
    }

    if(branch == "sor3_st7e"){
        samplePlay(SAMPLE_TRUCK, 1);
    }

    if(set == 1){
        samplePlay(SAMPLE_CROWD3, 1);
    }
}
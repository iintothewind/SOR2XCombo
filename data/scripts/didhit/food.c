#import "data/scripts/keyall/main_savecfg.c"
#include "data/scripts/assets.h"

void main()
{//Alternative method to play "get food" sample

	playsample(SAMPLE_FOOD, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
}
#import "data/scripts/ondraw/main.c"
#import "data/scripts/attributes.h"
#import "data/scripts/main.c"

void main()
{
	jumpVel();
	parrow();
	debugMode();
	speedAtt("Break");
	checkText("ANI_FREESPECIAL", "RAGE");
	checkText("ANI_FREESPECIAL2", "SUPER");
}
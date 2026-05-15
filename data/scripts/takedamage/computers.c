#import "data/scripts/takedamage/main.c"

void main()
{
	customHitflash();
	aniHealth(openborconstant("ANI_FOLLOW1"), openborconstant("ANI_FOLLOW3"), openborconstant("ANI_FOLLOW5"));
	smokeHealth(25, 0);
	hitDmg();
	comboDmg();
}
#import "data/scripts/updatelevel/main.c"

void main()
{
	cycleSprite("bglayer", 0, 1, 20);
	cycleSprite("fglayer", 0, 1, 10);
	cycleSprite("fglayer", 2, 3, 10);
	cycleSprite("fglayer", 4, 5, 20);
	cycleSprite("fglayer", 6, 8, 50);
}
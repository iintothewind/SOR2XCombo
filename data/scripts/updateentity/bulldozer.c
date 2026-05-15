#include "data/scripts/assets.h"

void main()
{//Play engine sample and spawn smoke according to xDir
	void self = getlocalvar("self");

	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		void sample = getlocalvar("sample");
		int x		= getentityproperty(self, "x");
		int y		= getentityproperty(self, "y");
		int z		= getentityproperty(self, "z");
		int dead   	= getentityproperty(self, "dead");
		float xDir 	= getentityproperty(self, "xdir");
		float xDif 	= 20;
		float xPos 	= openborvariant("xpos");
		float yDif 	= 80;
		float yVel 	= 0.5;
		float time 	= openborvariant("elapsed_time");
		float rate 	= 20;

		if(dead == 0){
			if(xDir < 0){
				if(time%rate == 0){
					void gas;
					clearspawnentry();
					setspawnentry("name", "Gas");
					setspawnentry("coords", x-xPos-xDif, z+1, y+yDif);
					gas = spawn();
					tossentity(gas, yVel, 0, 0);
					playsample(SAMPLE_BULLDOZER, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				}
			}
			else
			if(xDir >= 0){
				if(time%(rate*2) == 0){
					void gas;
					clearspawnentry();
					setspawnentry("name", "Gas");
					setspawnentry("coords", x-xPos-xDif, z+1, y+yDif);
					gas = spawn();
					tossentity(gas, yVel, 0, 0);
					playsample(SAMPLE_BULLDOZER, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				}
			}
		}
	}
}
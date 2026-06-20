#include "data/scripts/assets.h"

void main()
{//Move Rocket enemy to rescue Shiva after being defeated (SOR3_ST1C)
	void self		= getlocalvar("self");
	void parent		= getentityproperty(self, "parent");
	int vDir		= getentityproperty(self, "direction");
	int pDir		= getentityproperty(parent, "direction");
	int dx			= getentityproperty(self, "x");
	int px			= getentityproperty(parent, "x");
	int xBind		= 40;
	int yDif		= 50;
	float yPos		= openborvariant("ypos");
	float time		= openborvariant("elapsed_time");
	float xVel		= 8;
	float yVel		= 9;
	float limit1	= 600;
	float limit2	= 100;
	
	if(vDir == 0){
		xVel = -xVel;
		dx = -dx;
		px = -px;
	}
	
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		if(getlocalvar("rescued") == NULL()){
			if(dx >= px){
				bindentity(parent, self, xBind, 0, 0, pDir);
				changeentityproperty(self, "velocity", 0, NULL(), NULL());
				setlocalvar("rescued", 1);
				setlocalvar("timeCount", time);
			}
			else
			if(dx < px){changeentityproperty(self, "velocity", xVel, NULL(), NULL());}
		}
		
		if(getlocalvar("rescued") == 1){
			if(time >= getlocalvar("timeCount")+limit1){
				changeentityproperty(self, "velocity", xVel, NULL(), yVel);
				playsample(SAMPLE_WIND3, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				setlocalvar("rescued", 0);
				setlocalvar("timeCount", time);
			}
		}
		
		if(getlocalvar("rescued") == 0){
			if(yPos >= yPos-yDif){
				if(time >= getlocalvar("timeCount")+limit2){
					changeentityproperty(parent, "type", openborconstant("TYPE_NPC"));
					killentity(self);
				}
			}
		}
	}
}
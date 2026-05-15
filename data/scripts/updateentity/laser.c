#import "data/scripts/animation/main_spawns.c"

void main()
{//Draw, move and lean a laser line (SOR3 ST6)
	
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		void self	= getlocalvar("self");
		float xPos	= getentityproperty(self, "x");
		float zPos	= getentityproperty(self, "z");
		float xDir	= getentityproperty(self, "xdir");
		float xAdd	= -142;
		float xRate	= 0.25;
		float limit	= 227;
		float xVel	= 0.2;
		
		//START VARIABLES IF NULL
		if(getlocalvar("xAdd") == NULL()){setlocalvar("xAdd", xAdd);}
		if(getlocalvar("startPos") == NULL()){setlocalvar("startPos", xPos);}
		if(getlocalvar("moveDir") == NULL()){setlocalvar("moveDir", "right");}

		//ADD "VELOCITY" AND "LEAN" RATE
		if(getlocalvar("moveDir") == "right"){
			if(xDir <= 0){changeentityproperty(self, "velocity", xVel, 0, 0);}
			setlocalvar("xAdd", getlocalvar("xAdd")+xRate);
		}
		if(getlocalvar("moveDir") == "left"){
			if(xDir >= 0){changeentityproperty(self, "velocity", -xVel, 0, 0);}
			setlocalvar("xAdd", getlocalvar("xAdd")-xRate);
		}

		//CHANGE DIRECTION WHEN REACHING THE LIMIT
		if(xPos >= getlocalvar("startPos")+limit){setlocalvar("moveDir", "left");}else
		if(xPos <= getlocalvar("startPos")){setlocalvar("moveDir", "right");}
		
		//SHOOT "DOTS" ATBOX TO MATCH THE LINE FORMAT
		float time		= openborvariant("elapsed_time");
		int spawnZ		= 135;
		int mult		= 12;
		int shotRate	= 8;

		if(time%shotRate == 0){spawnToss("St6_Dot", 0, 0, spawnZ, getlocalvar("xAdd")/mult, 0, mult);}

		//DRAW THE LASER LINE
		float zDif1	= 133;
		float zDif2	= 280;
		int layer	= 160;
		int color	= -255;
		int alpha	= 1;

		if(time%2 == 0){
			drawline(xPos, zPos+zDif1, xPos+getlocalvar("xAdd")-2, zPos+zDif2, layer, color, alpha);
			drawline(xPos, zPos+zDif1, xPos+getlocalvar("xAdd")-1, zPos+zDif2, layer, color, alpha);
			drawline(xPos, zPos+zDif1, xPos+getlocalvar("xAdd"), zPos+zDif2, layer, color, alpha);
			drawline(xPos, zPos+zDif1, xPos+getlocalvar("xAdd")+1, zPos+zDif2, layer, color, alpha);
			drawline(xPos, zPos+zDif1, xPos+getlocalvar("xAdd")+2, zPos+zDif2, layer, color, alpha);
		}
	}
}
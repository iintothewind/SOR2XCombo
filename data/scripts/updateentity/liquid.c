#import "data/scripts/animation/main_spawns.c"

void main()
{//Spawn entity at Random location relative to xPos (SOR3_ST8 LIQUID)
	void self 	= getlocalvar("self");
	void name	= getentityproperty(self, "defaultname");
	void ani	= getentityproperty(self, "animationID");
	void vSpawn;
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int z 		= getentityproperty(self, "z");
	int layer	= 1;
	int limit	= 208;
	float yVel	= 1;
	float time 	= openborvariant("elapsed_time");
	float xR 	= rand()%10+10; //RANDOM XPOS
	float yR 	= rand()%50+50; //RANDOM YVEL
	float xAdd	= 254;
	float yAdd	= 160;
	float yMult	= 0.1;
	
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		if(name == "St8_Liquid"){
			if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_FOLLOW1")){
				if(time%2 == 0){
					x 	   = x+xR-xAdd;
					y 	   = y+yAdd;
					z 	   = z+layer;
					yVel   = (yVel+yR)*yMult;
					vSpawn = spawn01("St8_Bubble", x, y, z);
					tossentity(vSpawn, yVel, 0, 0);
				}
			}
			
			if(ani == openborconstant("ANI_IDLE")){
				if(getglobalvar("neoxDead") == 1){changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));}
			}

			if(getglobalvar("alarm") == 1){
				jumptobranch("sor3_ending_b", 0);
			}
			else
			if(getglobalvar("alarm") == 2){
				jumptobranch("sor3_ending_c", 0);
			}
		}

		if(name == "St8_Bubble"){
			if(y >= limit){killentity(self);}
		}
	}
}
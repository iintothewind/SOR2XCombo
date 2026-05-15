#import "data/scripts/ondraw/main.c"

void main()
{
	drawLife();
	rescued();
}

void rescued()
{//Change "General" variables when rescued by heroes
	
	if(getglobalvar("generalRescued") == NULL()){ //CHECK IF THE GENERAL IS ALREADY RESCUED
		if(getglobalvar("generalDied") == NULL()){ //CHECK IF THE GENERAL IS ALREADY DEAD
			void self	= getlocalvar("self");
			int locks	= getglobalvar("st6_locks");
			float xPos	= openborvariant("xpos");
			float limit	= 1597;

			if(locks > 1 && xPos <= limit){
				if(getglobalvar("st6_side") == "b" && getglobalvar("st6_floor") == 2){
					changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
					setglobalvar("generalRescued", 1);
				}
			}
		}
	}
}
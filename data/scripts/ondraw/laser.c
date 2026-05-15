void main()
{//Change animation with time count (LASER IN SOR3 ST6E)
	void self	= getlocalvar("self");
	void anim	= getentityproperty(self, "animationID");
	float clock	= openborvariant("elapsed_time");
	float start	= getlocalvar("startClock");
	float add	= 1200;
	
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		
		//SAVE START CLOCK AT 99 SECONDS IF NULL
		if(start == NULL()){setlocalvar("startClock", clock+add);}
		
		//START CLOCK IS NOT NULL??
		if(start != NULL()){
			if(anim == openborconstant("ANI_IDLE") || anim == openborconstant("ANI_ATTACK1")){ //IS IN CHASE ANIMATION??
				if(clock >= start){ //TIME ENDED
					setlocalvar("startClock", clock+add); //RESET CLOCK COUNT AGAIN
					performattack(self, openborconstant("ANI_FOLLOW1"), 1); //ATTACK
				}
			}
		}
	}
	else
	{
		setlocalvar("startClock", clock+add); //SAVE START CLOCK AT 99 SECONDS IF NULL
	}

	//USED TO DRAW A DOT IN THE GROUND
	int x		= getentityproperty(self, "x");
	int y		= getentityproperty(self, "y");
	int z		= getentityproperty(self, "z");
	int t		= openborvariant("elapsed_time")/5;
	int xDif	= 2;
	int zDif	= 6;
	int width	= 2;
	int height	= 2;
	float color	= rgbcolor(0x00, 0xFF, 0x00);

	if(t%2 == 0){drawbox(x-xDif, z-zDif, width, height, z, color, 0);}
}
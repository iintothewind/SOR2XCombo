void main()
{
	if(openborvariant("current_branch") == "sor1_st7a"){sor1_st7a();}
	if(openborvariant("current_branch") == "sor2_st7b"){sor2_st7b();}
	if(openborvariant("current_branch") == "sor2_st8b"){sor2_st8b();}
	if(openborvariant("current_branch") == "sor3_st3c"){sor3_st3c();}
	if(openborvariant("current_branch") == "sor3_st5h"){sor3_st5h();}
	if(openborvariant("current_branch") == "sor3_st6a"){sor3_st6a();}
}

void sor1_st7a()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	int zPos		= getentityproperty(self, "z");
	int zStart		= getlocalvar("zStart"+self); //REGISTER THE INITIAL POSITION
	int zDif		= 544; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR
	int frameStop	= 2; //DEFINED FRAME THAT THE ANIMATION WILL BE CHANGED WHEN THE ELEVATOR STOPS
	int zStop;

	//START THE "ZSTART" VARIABLE
	if(zStart == NULL()){setlocalvar("zStart"+self, zPos);}

	//DEFINE THE CURRENT "ZSTOP" ACCORDING TO THE CURRENT ANIMATION
	if(anim == openborconstant("ANI_FOLLOW1")){zStop = zStart+zDif;} //FLOOR 1
	if(anim == openborconstant("ANI_FOLLOW2")){zStop = zStart+zDif*2;} //FLOOR 2
	if(anim == openborconstant("ANI_FOLLOW3")){zStop = zStart+zDif*3;} //FLOOR 3
	if(anim == openborconstant("ANI_FOLLOW4")){zStop = zStart+zDif*4;} //FLOOR 4
	if(anim == openborconstant("ANI_FOLLOW5")){zStop = zStart+zDif*5;} //FLOOR 5

	//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zPos >= zStop){
		updateframe(self, frameStop);
		changelevelproperty("vbgspeed", 0);
		changeentityproperty(self, "z", zStop);
		changeentityproperty(self, "velocity", 0, 0, 0);
	}
}

void sor2_st7b()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	int zPos		= getentityproperty(self, "z");
	int zStart		= getlocalvar("zStart"+self); //REGISTER THE INITIAL POSITION
	int zDif		= 222; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR
	int frameStop	= 2; //DEFINED FRAME THAT THE ANIMATION WILL BE CHANGED WHEN THE ELEVATOR STOPS
	int zStop;

	//START THE "ZSTART" VARIABLE
	if(zStart == NULL()){setlocalvar("zStart"+self, zPos);}

	//DEFINE THE CURRENT "ZSTOP" ACCORDING TO THE CURRENT ANIMATION
	if(anim == openborconstant("ANI_FOLLOW1")){zStop = zStart+zDif;} //FLOOR 1
	zDif = 448;
	if(anim == openborconstant("ANI_FOLLOW2")){zStop = zStart+zDif;} //FLOOR 2
	zDif = 660;
	if(anim == openborconstant("ANI_FOLLOW3")){zStop = zStart+zDif;} //FLOOR 3
	zDif = 985;
	if(anim == openborconstant("ANI_FOLLOW4")){zStop = zStart+zDif;} //FLOOR 4
	zDif = 1278;
	if(anim == openborconstant("ANI_FOLLOW5")){zStop = zStart+zDif;} //FLOOR 5

	//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zPos >= zStop){
		updateframe(self, frameStop);
		changeentityproperty(self, "z", zStop);
		changeentityproperty(self, "velocity", 0, 0, 0);
	}
}

void sor2_st8b()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	int zPos		= getentityproperty(self, "z");
	int zStart		= getlocalvar("zStart"+self); //REGISTER THE INITIAL POSITION
	int zDif		= 256; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR
	int frameStop	= 2; //DEFINED FRAME THAT THE ANIMATION WILL BE CHANGED WHEN THE ELEVATOR STOPS
	int zStop;

	//START THE "ZSTART" VARIABLE
	if(zStart == NULL()){setlocalvar("zStart"+self, zPos);}

	//DEFINE THE CURRENT "ZSTOP" ACCORDING TO THE CURRENT ANIMATION
	if(anim == openborconstant("ANI_FOLLOW1")){zStop = zStart+zDif;} //FLOOR 1
	zDif = zDif*2;
	if(anim == openborconstant("ANI_FOLLOW2")){zStop = zStart+zDif;} //FLOOR 2
	zDif = 736;
	if(anim == openborconstant("ANI_FOLLOW3")){zStop = zStart+zDif;} //FLOOR 3

	//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zPos >= zStop){
		updateframe(self, frameStop);
		changeentityproperty(self, "z", zStop);
		changeentityproperty(self, "velocity", 0, 0, 0);
	}
}

void sor3_st3c()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	int xDir		= getentityproperty(self, "xdir");
	int zDir		= getentityproperty(self, "zdir");
	int frameStop	= 2; //DEFINED FRAME THAT THE ANIMATION WILL BE CHANGED WHEN THE ELEVATOR STOPS

	//MOVING LEFT OR RIGHT
	if(xDir != 0 && zDir == 0){
		int xPos	= getentityproperty(self, "x");
		int xStart	= getlocalvar("xStart"+self); //REGISTER THE INITIAL X POSITION
		int xDif	= 384; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR IN X AXIS
		int xStop;

		//START THE "XSTART" VARIABLE
		if(xStart == NULL()){setlocalvar("xStart"+self, xPos);}

		//DEFINE THE CURRENT "XSTOP" ACCORDING TO THE CURRENT ANIMATION
		if(anim == openborconstant("ANI_FOLLOW2")){xStop = xStart-xDif;} //FLOOR 1b
		if(anim == openborconstant("ANI_FOLLOW4")){xStop = xStart;} //FLOOR 2a

		//MOVING RIGHT?? CHECK POSITION AND STOP AT DEFINED LIMIT
		if(xPos <= xStop && xDir < 0){
			updateframe(self, frameStop);
			changeentityproperty(self, "x", xStop);
			changeentityproperty(self, "velocity", 0, 0, 0);
		}

		//MOVING LEFT?? CHECK POSITION AND STOP AT DEFINED LIMIT
		if(xPos >= xStop && xDir > 0){
			updateframe(self, frameStop);
			changeentityproperty(self, "x", xStop);
			changeentityproperty(self, "velocity", 0, 0, 0);
		}
	}

	//MOVING UP
	if(zDir != 0){
		int zPos	= getentityproperty(self, "z");
		int zStart	= getlocalvar("zStart"+self); //REGISTER THE INITIAL Z POSITION
		int zDif	= 256; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR IN Z AXIS
		int zStop;

		//START THE "ZSTART" VARIABLE
		if(zStart == NULL()){setlocalvar("zStart"+self, zPos);}

		//DEFINE THE CURRENT "ZSTOP" ACCORDING TO THE CURRENT ANIMATION
		if(anim == openborconstant("ANI_FOLLOW1")){zStop = zStart+zDif;} //FLOOR 1a
		zDif = 512;
		if(anim == openborconstant("ANI_FOLLOW3")){zStop = zStart+zDif;} //FLOOR 2b
		zDif = 861;
		if(anim == openborconstant("ANI_FOLLOW5")){zStop = zStart+zDif;} //FLOOR 3a
		zDif = 989;
		if(anim == openborconstant("ANI_FOLLOW6")){zStop = zStart+zDif;} //FLOOR 4a

		//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
		if(zPos >= zStop){
			updateframe(self, frameStop);
			changeentityproperty(self, "z", zStop);
			changeentityproperty(self, "velocity", 0, 0, 0);
		}
	}
}

void sor3_st5h()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	int zPos		= getentityproperty(self, "z");
	int zStart		= getlocalvar("zStart"+self); //REGISTER THE INITIAL POSITION
	int zDif		= 256; //DEFAULT DIFFERENCE BETWEEN EACH FLOOR
	int frameStop	= 2; //DEFINED FRAME THAT THE ANIMATION WILL BE CHANGED WHEN THE ELEVATOR STOPS
	int zStop;

	//START THE "ZSTART" VARIABLE
	if(zStart == NULL()){setlocalvar("zStart"+self, zPos);}

	//DEFINE THE CURRENT "ZSTOP" ACCORDING TO THE CURRENT ANIMATION
	if(anim == openborconstant("ANI_FOLLOW1")){zStop = zStart+zDif;} //FLOOR 1
	zDif = zDif*2;
	if(anim == openborconstant("ANI_FOLLOW2")){zStop = zStart+zDif;} //FLOOR 2
	zDif = 736;
	if(anim == openborconstant("ANI_FOLLOW3")){zStop = zStart+zDif;} //FLOOR 3

	//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zPos >= zStop){
		updateframe(self, frameStop);
		changeentityproperty(self, "z", zStop);
		changeentityproperty(self, "velocity", 0, 0, 0);
	}
}

void sor3_st6a()
{//Stop elevator movement according to the current animation
	void self		= getlocalvar("self");
	int floor		= getglobalvar("st6_floor");
	int zDir		= getentityproperty(self, "zdir");
	int zPos		= getentityproperty(self, "z");
	int zDif		= 276;
	int frameStop	= 2;
	int zStop;

	//MOVING DOWN?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zDir < 0){
		if(floor == 2){zStop = zDif*3;}
		if(floor == 1){zStop = zDif*2;}
		if(floor == 0){zStop = zDif;}

		if(zPos <= zStop){
			updateframe(self, frameStop);
			changeentityproperty(self, "z", zStop);
			changeentityproperty(self, "velocity", 0, 0, 0);
		}
	}

	//MOVING UP?? CHECK POSITION AND STOP AT DEFINED LIMIT
	if(zDir > 0){
		if(floor == 1){zStop = zDif*2;}
		if(floor == 2){zStop = zDif*3;}
		if(floor == 3){zStop = zDif*4;}

		if(zPos >= zStop){
			updateframe(self, frameStop);
			changeentityproperty(self, "z", zStop);
			changeentityproperty(self, "velocity", 0, 0, 0);
		}
	}
}
void main()
{//Adjust velocity according to the current position (SPARK LASER IN SOR3 ST6F)
	void self		= getlocalvar("self");
	float xDir		= getentityproperty(self, "xdir");
	float zDir		= getentityproperty(self, "zdir");
	float x			= getentityproperty(self, "x");
	float y			= getentityproperty(self, "y");
	float z			= getentityproperty(self, "z");
	float xVel1		= 0.19;
	float xVel2		= 0.4;
	float zVel		= 0.2;
	float xMid		= 240;
	float zReset	= 164;
	float zMax		= 274;

	//RIGHT SIDE
	if(x > xMid){
		if(xDir > 0 && zDir == 0){
			if(x >= 357 && z < 165){changeentityproperty(self, "velocity", xVel1, zVel);}else
			if(x >= 376 && z < 185){changeentityproperty(self, "velocity", xVel1, zVel);}else
			if(x >= 395 && z < 205){changeentityproperty(self, "velocity", xVel1, zVel);}else
			if(x >= 414 && z < 225){changeentityproperty(self, "velocity", xVel1, zVel);}else
			if(x >= 433 && z < 245){changeentityproperty(self, "velocity", xVel1, zVel);}else
			if(x >= 452 && z < 265){changeentityproperty(self, "velocity", xVel1, zVel);}
		}
		else
		if(zDir > 0 && xDir > 0){
			if(z >= 174 && z < 175){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 194 && z < 195){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 214 && z < 215){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 234 && z < 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 254 && z < 255){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 274 && z < 275){changeentityproperty(self, "velocity", -xVel2, 0);}
		}
		else
		if(xDir < 0 && zDir == 0){
			if(x <= 246 && x > 245 && z <= 274){changeentityproperty(self, "velocity", 0, zVel);}
		}
		else
		if(zDir > 0 && xDir == 0){
			if(z >= 184 && z < 185 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 204 && z < 205 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 224 && z < 225 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 244 && z < 245 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 264 && z < 265 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 284 && z < 285 && x < 247){changeentityproperty(self, "velocity", xVel2, 0);}
		}
	}

	//LEFT SIDE
	if(x < xMid){
		if(xDir < 0 && zDir == 0){
			if(x <= 18 && z < 275){changeentityproperty(self, "velocity", xVel1, -zVel);}else
			if(x <= 37 && z < 255){changeentityproperty(self, "velocity", xVel1, -zVel);}else
			if(x <= 56 && z < 235){changeentityproperty(self, "velocity", xVel1, -zVel);}else
			if(x <= 75 && z < 215){changeentityproperty(self, "velocity", xVel1, -zVel);}else
			if(x <= 94 && z < 195){changeentityproperty(self, "velocity", xVel1, -zVel);}else
			if(x <= 113 && z < 175){changeentityproperty(self, "velocity", xVel1, -zVel);}
		}
		else
		if(zDir < 0 && xDir > 0){
			if(z >= 264 && z < 265){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 244 && z < 245){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 224 && z < 225){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 204 && z < 205){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 184 && z < 185){changeentityproperty(self, "velocity", xVel2, 0);}else
			if(z >= 164 && z < 165){changeentityproperty(self, "velocity", xVel2, 0);}
		}
		else
		if(xDir > 0 && zDir == 0){
			if(x >= 235 && x < 236 && z >= 165 && z < 274){changeentityproperty(self, "velocity", 0, -zVel);}
		}
		else
		if(zDir < 0 && xDir == 0){
			if(z >= 254 && z < 255 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 234 && z < 235 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 214 && z < 215 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 194 && z < 195 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 174 && z < 175 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}else
			if(z >= 154 && z < 155 && x > 235){changeentityproperty(self, "velocity", -xVel2, 0);}
		}
	}

	//FIX THE POSITION EVERY TIME THE SPARK PASS IN THE MIDDLE OF THE SCREEN, TO AVOID INCREASING ANY DIFFERENCE AT EACH CYCLE
	if(x >= xMid && x <= xMid+1 && z >= zReset && z < zMax){changeentityproperty(self, "position", NULL(), zReset);}
}
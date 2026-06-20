#import "data/scripts/main.c"

void dasher(float Vx, float Vy, float Vz)
{//Dash with desired speed!
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self,"direction");

	if(!selfAlive()){return;}

	if(dir == 0){Vx = -Vx ;}
	changeentityproperty(self, "velocity", Vx, Vz, Vy);
}

void dashTarget()
{//Dash with previously attained speed by target script!
	void self 	= getlocalvar("self");
	float Vx 	= getlocalvar("x"+self);
	float Vz 	= getlocalvar("z"+self);

	if(!selfAlive()){return;}

	if(Vx != NULL() && Vz != NULL()){changeentityproperty(self, "velocity", Vx, Vz);}
}

void dashRandom(float Vx, float Vz)
{//Dash with random X/Z axis (ALL DODGE MOVES LIKE KUSANAGI DODGE)
	void self = getlocalvar("self");
	int dir   = getentityproperty(self,"direction");
	float iR1 = rand()%50+50;
	float iR2 = rand()%50+50;

	if(!selfAlive()){return;}

	if(iR1 >= 0 && iR1 < 50){Vx = -Vx;}
	if(iR2 >= 0 && iR2 < 50){Vz = -Vz;}
	changeentityproperty(self, "velocity", Vx, Vz, 0);
	mpRecover();
}

void dashBg(int dir, int ratio)
{//Dash entity with bgSpeed global variable check (BIKE STAGE)
	void self 	  = getlocalvar("self");
	float bgSpeed = getglobalvar("bgSpeed");

	if(!selfAlive()){return;}

	if(dir == 0){bgSpeed = -bgSpeed;}
	changeentityproperty(self, "velocity", bgSpeed/ratio, 0, 0);
}

void leaper(float Vx, float Vy, float Vz)
{//Leap with desired speed!
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self,"direction");

	if(!selfAlive()){return;}

	if(dir == 0){Vx = -Vx ;}
	tossentity(self, Vy, Vx, Vz);
}

void leapTarget(float Vy)
{//Leap with previously attained speed by target script!
	void self 	= getlocalvar("self");
	float Vx 	= getlocalvar("x"+self);
	float Vz 	= getlocalvar("z"+self);

	if(!selfAlive()){return;}

	if(Vx != NULL() && Vz != NULL()){tossentity(self, Vy, Vx, Vz);}
}

void leapRandom(float Vx, float Vy, float Vz)
{//Leap with desired speed and random X/Z axis (ALL DODGE JUMPS, LIKE SHIVA DODGE)
	void self = getlocalvar("self");
	int dir   = getentityproperty(self,"direction");
	float iR1 = rand()%50+50;
	float iR2 = rand()%50+50;

	if(!selfAlive()){return;}

	if(iR1 >= 0 && iR1 < 50){Vx = -Vx;}
	if(iR2 >= 0 && iR2 < 50){Vz = -Vz;}
	tossentity(self, Vy, Vx, Vz);
	mpRecover();
}

void leapJump()
{//Leap using self jumpheight property and velocity defined by targetJump script (ALL ENEMY/NPC JUMPATTACK)
	void self 	= getlocalvar("self");
	float Vx 	= getlocalvar("x"+self);
	float Vz 	= getlocalvar("z"+self);
	float jumpH	= getentityproperty(self, "jumpheight");

	if(!selfAlive()){return;}

	if(Vx != NULL() && Vz != NULL()){tossentity(self, jumpH, Vx, Vz/2);}
}

void stop()
{//Stop movement and changes speed to 0!
	void self = getlocalvar("self");

	if(!selfAlive()){return;}

	changeentityproperty(self, "velocity", 0, 0, 0);
	changeentityproperty(self, "speed", 0, 0, 0);
}

void target(float Velx, float Velz)
{//Targetting opponent before leaping or dashing (REDUCED TARGET SCRIPT)
 //Check subtype and player minZ to avoid targeting decoration enemies, like Shiva/Mr.X waiting to fight in the last stage
	void self 	 = getlocalvar("self");
	void found	 = findtarget(self); //FIND TARGET
	if(!selfAlive()){return;}
	if(found != NULL()) {
		void subType = getentityproperty(found, "subtype"); //GET TARGET'S SUBTYPE
		int targetVulnerable	= getentityproperty(found, "vulnerable");
		int targetInvincible	= getentityproperty(found, "invincible");
		int targetRising			= getentityproperty(found, "aiflag", "rising");
		int targetBlink			= getentityproperty(found, "blink");
		int dir 	 = getentityproperty(self, "direction"); //GET PLAYER'S FACING DIRECTION
		float x 	 = getentityproperty(self, "x"); //GET PLAYER'S X COORDINATE
		float z 	 = getentityproperty(self, "z"); //GET PLAYER'S Z COORDINATE
		float fZ 	 = getentityproperty(found, "z"); //GET TARGET'S Z COORDINATE
		float minZ	 = openborvariant("player_min_z");

		if(subType != openborconstant("SUBTYPE_NOTGRAB") && !targetInvincible && !targetRising && !targetBlink && targetVulnerable){
			if(fZ >= minZ){
				setlocalvar("target"+self, found); //PUT FOUND TARGET IN LOCAL VARIABLE
			}
		}

		if(getlocalvar("target"+self) != NULL()){ //IS THERE A TARGET?
			void target = getlocalvar("target"+self);
			float Tx 	= getentityproperty(target, "x"); //Get target's x coordinate
			float Tz 	= getentityproperty(target, "z"); //Get target's z coordinate
			float Disx	= Tx - x; //GET X DISTANCE
			float Disz 	= Tz - z; //GET Z DISTANCE

			if(Disx < 0){ //NEGATIVE DISX?
				Disx = -Disx; //TURN IT TO POSITIVE
				changeentityproperty(self, "direction", 0); //Face left
			}else{
				changeentityproperty(self, "direction", 1); //Face right
			}

			if(Disz < 0){ //NEGATIVE DISZ?
				Disz = -Disz; //TURN IT TO POSITIVE
			}

			if(Disz < Disx){ //DISX BIGGER THAN DISZ?
				if(Tx < x){ //PLAYER IS BEHIND ENEMY?
					setlocalvar("x"+self, -Velx); //TURN VX TO NEGATIVE
				}else{
					setlocalvar("x"+self, Velx);  //USE DEFINED VX
				}
				setlocalvar("z"+self, Velx*(Tz-z)/Disx); //CALCULATE VZ THEN STORE VALUE IN LOCAL VARIABLE
			}else{ //DISZ BIGGER THAN DISX!
				if(Tz < z){ //PLAYER IS BEHIND ENEMY?
					setlocalvar("z"+self, -Velz); //TURN VZ TO NEGATIVE
				}else{
					setlocalvar("z"+self, Velz); //USE DEFINED VZ
				}
				setlocalvar("x"+self, Velz*(Tx-x)/Disz); //CALCULATE VX THEN STORE VALUE IN LOCAL VARIABLE
			}

		}else{ //NO TARGET AT ALL!
			setlocalvar("z"+self, 0); //0 VELOCITY
			if(dir == 0){ //FACING LEFT?
				setlocalvar("x"+self, -Velx); //NEGATIVE VELOCITY
			}else{
				setlocalvar("x"+self, Velx);  //POSITIVE VELOCITY
			}
		}
	}
}

void targetJump()
{//Targetting opponent before using "leapJump" script with self jumpspeed property (REDUCED TARGET SCRIPT)
 //Check subtype and player minZ to avoid targeting decoration enemies, like Shiva/Mr.X waiting to fight in the last stage
	void self 	 = getlocalvar("self");
	void found	 = findtarget(self); //FIND TARGET

	if(!selfAlive()){return;}

	void subType = getentityproperty(found, "subtype"); //GET TARGET'S SUBTYPE
	int dir 	 = getentityproperty(self, "direction"); //GET PLAYER'S FACING DIRECTION
	float x 	 = getentityproperty(self, "x"); //GET PLAYER'S X COORDINATE
	float z 	 = getentityproperty(self, "z"); //GET PLAYER'S Z COORDINATE
	float fZ 	 = getentityproperty(found, "z"); //GET TARGET'S Z COORDINATE
	float minZ	 = openborvariant("player_min_z");
	float jumpS	 = getentityproperty(self, "jumpspeed"); //GET SELF JUMPSPEED VALUE

	if(subType != openborconstant("SUBTYPE_NOTGRAB")){
		if(fZ >= minZ){
			setlocalvar("target"+self, found); //PUT FOUND TARGET IN LOCAL VARIABLE
		}
	}

	if(getlocalvar("target"+self) != NULL()){ //IS THERE A TARGET?
		void target = getlocalvar("target"+self);
		float Tx 	= getentityproperty(target, "x"); //GET TARGET'S X COORDINATE
		float Tz 	= getentityproperty(target, "z"); //GET TARGET'S Z COORDINATE
		float Disx	= Tx - x; //GET X DISTANCE
		float Disz 	= Tz - z; //GET Z DISTANCE

		if(Disx < 0){ //NEGATIVE DISX?
			Disx = -Disx; //TURN IT TO POSITIVE
			changeentityproperty(self, "direction", 0); //FACE LEFT
		}else{
			changeentityproperty(self, "direction", 1); //FACE RIGHT
		}

		if(Disz < 0){ //NEGATIVE DISZ?
			Disz = -Disz; //TURN IT TO POSITIVE
		}

		if(Disz < Disx){ //DISX BIGGER THAN DISZ?
			if(Tx < x){ //PLAYER IS BEHIND ENEMY?
				setlocalvar("x"+self, -jumpS); //TURN VX TO NEGATIVE
			}else{
				setlocalvar("x"+self, jumpS);  //USE DEFINED VX
			}
			setlocalvar("z"+self, jumpS*(Tz-z)/Disx); //CALCULATE VZ THEN STORE VALUE IN LOCAL VARIABLE
		}else{ //DISZ BIGGER THAN DISX!
			if(Tz < z){ //PLAYER IS BEHIND ENEMY?
				setlocalvar("z"+self, -jumpS); //TURN VZ TO NEGATIVE
			}else{
				setlocalvar("z"+self, jumpS); //USE DEFINED VZ
			}
			setlocalvar("x"+self, jumpS*(Tx-x)/Disz); //CALCULATE VX THEN STORE VALUE IN LOCAL VARIABLE
		}

	}else{ //NO TARGET AT ALL!
		setlocalvar("z"+self, 0); //0 VELOCITY
		if(dir == 0){ //FACING LEFT?
			setlocalvar("x"+self, -jumpS); //NEGATIVE VELOCITY
		}else{
			setlocalvar("x"+self, jumpS);  //POSITIVE VELOCITY
		}
	}
}

void targetXMove(float xDistance, int dir) {
	void self 	= getlocalvar("self");
	int selfDir 	= getentityproperty(self,"direction");
	int selfX 		= getentityproperty(self, "x");
	int selfZ 		= getentityproperty(self, "z");

	if(!selfAlive()){return;}

	if(selfDir == 0){xDistance = -xDistance;}
	if(selfDir == 0){changeentityproperty(self, "direction", 1);}else{changeentityproperty(self, "direction", 0);}

	float isWall = checkwall(selfX + xDistance, selfZ);
	float isHole = checkhole(selfX + xDistance, selfZ);

	if(isWall || isHole) {
		changeentityproperty(self, "position", selfX+xDistance/2, selfZ, 0);

	} else {
		changeentityproperty(self, "position", selfX+xDistance, selfZ, 0);
	}
}


void targetMove(float dx, float dz, int vDir)
{//Instantly move entity to same target X/Z position with added distance and wall check (YAMATO HIDE SLASH)
 //vDir = 0: Same direction as target
 //vDir = 1: Opposite direction as target
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int z 		= getentityproperty(self, "z");

	if(!selfAlive()){return;}

	if(target != NULL()){
		int tDir	= getentityproperty(target, "direction");
		int Tx 		= getentityproperty(target, "x");
		int Tz 		= getentityproperty(target, "z");
		int hp	 = getentityproperty(target,"health");
		int maxHp	= getentityproperty(target, "maxhealth");
		float distX	= dx;
		float W;
		float Wz;

		if(tDir == 0){distX = -distX;}

		W  = checkwall(Tx+distX, Tz);
		Wz = checkhole(Tx+distX, z);

		if(vDir == 0){
			if(tDir == 0){
				dx = -dx;
			}
			vDir = tDir;
		}
		else
		if(vDir == 1){
			if(tDir == 0){
				vDir = 1;
			}else{
				vDir = 0;
			}
		}

		if(W || Wz){
			changeentityproperty(self, "position", Tx-dx/2, Tz+dz, 0);
		}else{
			changeentityproperty(self, "position", Tx+dx, Tz+dz, 0);
			changeentityproperty(self, "direction", vDir);
		}

		if(hp >= maxHp/2) {
			mpRecover();
		}
	}
}

void targetMovep(float dx, float dz, int vDir)
{//Instantly move entity to same target X/Z position with added distance and wall check (YAMATO HIDE SLASH)
 //vDir = 0: Same direction as target
 //vDir = 1: Opposite direction as target
 //no mp recover
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int z 		= getentityproperty(self, "z");

	if(!selfAlive()){return;}

	if(target != NULL()){
		int tDir	= getentityproperty(target, "direction");
		int Tx 		= getentityproperty(target, "x");
		int Tz 		= getentityproperty(target, "z");
		float distX	= dx;
		float W;
		float Wz;

		if(tDir == 0){distX = -distX;}

		W  = checkwall(Tx+distX, Tz);
		Wz = checkhole(Tx+distX, z);

		if(vDir == 0){
			if(tDir == 0){
				dx = -dx;
			}
			vDir = tDir;
		}
		else
		if(vDir == 1){
			if(tDir == 0){
				vDir = 1;
			}else{
				vDir = 0;
			}
		}

		if(W || Wz){
			changeentityproperty(self, "position", Tx-dx/2, Tz+dz, 0);
		}else{
			changeentityproperty(self, "position", Tx+dx, Tz+dz, 0);
			changeentityproperty(self, "direction", vDir);
		}
	}
}

void copyMove()
{//Copy previously attained xDir/zDir
	void self 	= getlocalvar("self");
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= getentityproperty(self,"zdir");

	if(!selfAlive()){return;}

	clearlocalvar();
	setlocalvar("xVel", xdir);
	setlocalvar("zVel", zdir);
}

void pasteMove()
{//Paste previously attained xDir/zDir
	void self = getlocalvar("self");
	float Vx  = getlocalvar("xVel");
	float Vz  = getlocalvar("zVel");

	if(!selfAlive()){return;}

	if(Vx!=NULL() && Vz!=NULL()){changeentityproperty(self, "velocity", Vx, Vz);}
}

void pasteMovex(float rate)
{//Paste previously attained xDir/zDir
	void self = getlocalvar("self");
	float Vx  = getlocalvar("xVel")*rate;
	float Vz  = getlocalvar("zVel")*rate;

	if(!selfAlive()){return;}

	if(Vx!=NULL() && Vz!=NULL()){changeentityproperty(self, "velocity", Vx, Vz);}
}

void antiWall(int distX, int moveX, int distZ)
{//Checks distance from the walls
 //If near of the walls at defined distance, entity (Self/Grabbed) will be moved away with defined movement
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	int subWall		= getentityproperty(self, "subject_to_wall");
	float W;
	float Wz;

	if(!selfAlive()){return;}

	if(direction == 0){ //Is entity facing left?
		distX = -distX;
		moveX = -moveX;
	}

	W  = checkwall(x+distX, z);
	Wz = checkwall(x+distX, z+distZ);

	if(Wz){
		if(subWall == 1){
			changeentityproperty(self, "position", x, z-distZ);
			changeentityproperty(target, "position", Tx, Tz-distZ);
		}
	}

	if(W){
		if(subWall == 1){
			changeentityproperty(self, "position", x+moveX);
			changeentityproperty(target, "position", Tx+moveX);
		}
	}
}

void antiHole(int distX, int type)
{//Checks distance from the holes in X axis
 //If near of the holes at defined distance, entity will be fliped to not fall in the hole
	void self 		= getlocalvar("self");
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int z 			= getentityproperty(self, "z");
	int subHole		= getentityproperty(self, "subject_to_hole");
	int flipDir;
	int H;

	if(!selfAlive()){return;}

	if(direction == 0){
		distX   = -distX;
		flipDir = 1;
	}else{
		flipDir = 0;
	}

	H = checkhole(x+distX, z);

	if(H == 1){
		if(subHole == 1){
			if(type == "reset"){
				changeentityproperty(self, "velocity", 0, 0, 0);
				setidle(self, openborconstant("ANI_IDLE"));
			}

			if(type == "flip"){
				changeentityproperty(self, "direction", flipDir);
			}
		}
	}
}
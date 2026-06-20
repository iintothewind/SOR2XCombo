void spawn01(void vName, float fX, float fY, float fZ, int map, int dir, int mp, int layer, void anim, float delay)
{	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
	//fY: Z location adjustment.

	void vSpawn; //SPAWN OBJECT.
	void self		= getlocalvar("self"); //GET CALLING ENTITY.
	int direction	= getentityproperty(self, "direction"); //GET CALLING DIRECTION.

	clearspawnentry(); //CLEAR CURRENT SPAWN ENTRY.
	setspawnentry("name", vName); //ACQUIRE SPAWN ENTITY BY NAME.
	if(map != NULL()){setspawnentry("map", map);} //DEFINE MAP.
	if(mp != NULL()){setspawnentry("mp", mp);} //DEFINE MP.

	//IS ENTITY FACING LEFT? REVERSE X DIRECTION TO MATCH FACING
	if(dir != NULL()){direction = dir;}else{if(direction == 0){fX = -fX;}}

	fX = fX + getentityproperty(self, "x"); //GET X LOCATION AND ADD ADJUSTMENT.
	fY = fY + getentityproperty(self, "y"); //GET Y LOCATION AND ADD ADJUSTMENT.
	fZ = fZ + getentityproperty(self, "z"); //GET Z LOCATION AND ADD ADJUSTMENT.
	if(checkwall(fX, fZ-1)){fZ = fZ+1;} //CHECK WALLS ABOVE IN Z AXIS AND MOVE IF IT'S NECESSARY

	vSpawn = spawn(); //SPAWN IN ENTITY.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
	changeentityproperty(vSpawn, "direction", direction); //SET DIRECTION.

	//SET CUSTOM LAYER POSITION
	if(layer != NULL()){changeentityproperty(vSpawn, "setlayer", layer);}

	//SET CUSTOM ANIMATION
	if(anim != NULL()){changeentityproperty(vSpawn, "animation", anim);}

	//DEFINE A SPAWN DELAY IF IT'S NOT NULL
	if(delay != NULL()){setentityvar(vSpawn, "spawnDelay", delay);} //DELAY VALUE.

	return vSpawn; //RETURN SPAWN.
}


void shoot(void name, float dx, float dy, float dz, float Vx, float Vy, float Vz, void dualMode)
{//Shoot entity with defined conditions (DEFAULT SHOOT SCRIPT FOR PROJECTILES)
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void hostile	= getentityproperty(self, "hostile");
	void candamage	= getentityproperty(self, "candamage");
	void effects 	= getglobalvar("graphicEffects");
	int disable		= getentityproperty(self, "energycost", "disable", openborconstant(getlocalvar("animnum")));
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "y");
	int z 			= getentityproperty(self, "z");
	float offense	= getentityproperty(self, "offense", 0);
	void vShot;
	void subType;

	if(effects == "original" && dualMode == "dual"){name = name+"_B";}
	if(direction == 0){dx = -dx;}

	vShot = projectile(name, x+dx, z+dz, y+dy, direction, 0, 0, 0); //GENERATE ENTITY USING "PROJECTILE", NOT "SPAWN"
	subType = getentityproperty(vShot, "subtype");
	changeentityproperty(vShot, "speed", Vx); //"X" SPEED CONTROL
	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "parent", self); //SET TO PARENT
	changeentityproperty(vShot, "candamage", candamage); //COPY "SELF" CANDAMAGE PROPERTY
	changeentityproperty(vShot, "subject_to_platform", 0); //SET SUBJECT_TO_PLATFORM TO 0
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL2"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL6"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_BURN"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_SHOCK"), offense);
	setentityvar(vShot, "disable", disable);

	//IS ENTITY A ENEMY TYPE?
	if(type == openborconstant("TYPE_ENEMY")){changeentityproperty(vShot, "type", openborconstant("TYPE_SHOT"));}

	//IS ENTITY A CHASE SUBTYPE? COPY "SELF" HOSTILE PROPERTY (FOR GUIDED PROJECTILES ONLY, ROBOTX)
	if(subType == openborconstant("SUBTYPE_CHASE")){changeentityproperty(vShot, "hostile", hostile);}

	return vShot;
}

void shootBind(void name, float dx, float dy, float dz, void dualMode)
{//Shooting and bind entity
	void self  = getlocalvar("self");
	void vShot = shoot(name, dx, dy, dz, 0, 0, 0, dualMode);

	bindentity(vShot, self, dx, dz, dy, 0, 0);
	setentityvar(self, "projectile", vShot);
}

void throWeapon(float dx, float dy, float dz, float Vx, float Vy, float Vz)
{//Shoot entity with defined conditions (DEFAULT SHOOT SCRIPT FOR PROJECTILES, USING HOLDING WEAPON INSTEAD OF WEAPON NAME)
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void candamage	= getentityproperty(self, "candamage");
	void weapon 	= getentityproperty(self, "weapnum");
	void vShot;
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "y");
	int z 			= getentityproperty(self, "z");
	float offense	= getentityproperty(self, "offense", 0);

	if(direction == 0){dx = -dx;}

	vShot = projectile(weapon, x+dx, z+dz, y+dy, direction, 0, 0, 0); //GENERATE ENTITY USING "PROJECTILE", NOT "SPAWN"
	changeentityproperty(vShot, "speed", Vx); //"X" SPEED CONTROL
	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "parent", self); //SET TO PARENT
	changeentityproperty(vShot, "candamage", candamage); //COPY "SELF" CANDAMAGE PROPERTY
	changeentityproperty(vShot, "subject_to_platform", 0); //SET SUBJECT_TO_PLATFORM TO 0
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL2"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL6"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_BURN"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_SHOCK"), offense);

	//IS ENTITY A ENEMY TYPE?
	if(type == openborconstant("TYPE_ENEMY")){changeentityproperty(vShot, "type", openborconstant("TYPE_SHOT"));}

	return vShot;
}

void toss(void name, float dx, float dy, float dz, float Vx, float Vy, float Vz, int base, void ani, void flip)
{//Toss entity with defined conditions (DEFAULT TOSS SCRIPT FOR PROJECTILES)
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void candamage	= getentityproperty(self, "candamage");
	int disable		= getentityproperty(self, "energycost", "disable", openborconstant(getlocalvar("animnum")));
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "y");
	int z 			= getentityproperty(self, "z");
	float offense	= getentityproperty(self, "offense", 0);
	void vShot;

	if(flip == "flip"){
		if(direction == 0){direction = 1;}else
		if(direction == 1){direction = 0;}
	}

	if(direction == 0){dx = -dx;}

	vShot = projectile(name, x+dx, z+dz, y+dy, direction, 0, 0, 0); //GENERATE ENTITY USING "PROJECTILE", NOT "SPAWN"
	changeentityproperty(vShot, "speed", Vx); //"X" SPEED CONTROL
	changeentityproperty(vShot, "base", base); //BASE CONTROL
	changeentityproperty(vShot, "parent", self); //SET TO PARENT
	changeentityproperty(vShot, "candamage", candamage); //COPY "SELF" CANDAMAGE PROPERTY
	changeentityproperty(vShot, "subject_to_platform", 0); //SET SUBJECT_TO_PLATFORM TO 0
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL2"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_NORMAL6"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_BURN"), offense);
	changeentityproperty(vShot, "offense", openborconstant("ATK_SHOCK"), offense);
	tossentity(vShot, Vy, Vx, Vz); //TOSS ENTITY WITH DEFINED SPEED
	setentityvar(vShot, "disable", disable);

	//IS ENTITY A ENEMY TYPE?
	if(type == openborconstant("TYPE_ENEMY")){changeentityproperty(vShot, "type", openborconstant("TYPE_SHOT"));}

	//SET ANIMATION
	if(ani != NULL()){changeentityproperty(vShot, "animation", openborconstant(ani));}

	return vShot;
}

void tossXZ(void name, void ani, float dx, float dy, float dz, float Vy, float mult)
{//Toss entity with targetted X/Z speed, defined Y speed (FOG GRENADIER)
 //Mult: Multiplier for increase or decrease X/Z speed
	void self 		= getlocalvar("self");
	void target 	= findtarget(self);
	void candamage	= getentityproperty(self, "candamage");
	void vShot;
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "y");
	int z 			= getentityproperty(self, "z");
	int Tx 			= getentityproperty(target, "x");
	int Tz 			= getentityproperty(target, "z");
	float xVel 		= Tx - x;
	float zVel 		= Tz - z;

	if(direction == 0){dx = -dx;xVel = -xVel;}

	if(target != NULL()){
		vShot = projectile(name, x+dx, z+dz, y+dy, direction, 0, 0, 0);
		changeentityproperty(vShot, "animation", openborconstant(ani));
		changeentityproperty(vShot, "speed", xVel/mult);
		changeentityproperty(vShot, "base", 0);
		changeentityproperty(vShot, "parent", self);
		changeentityproperty(vShot, "candamage", candamage);
		changeentityproperty(vShot, "aiflag", "falling", 1);
		changeentityproperty(vShot, "type", openborconstant("TYPE_SHOT"));
		tossentity(vShot, Vy, xVel/mult, zVel/mult);
	}else{
		changeentityproperty(vShot, "animation", openborconstant(ani));
		vShot = projectile(name, x+dx, z+dz, y+dy, direction, 0, 0, 0);
		changeentityproperty(vShot, "speed", 0);
		changeentityproperty(vShot, "base", 0);
		changeentityproperty(vShot, "parent", self);
		changeentityproperty(vShot, "candamage", candamage);
		changeentityproperty(vShot, "aiflag", "falling", 1);
		changeentityproperty(vShot, "type", openborconstant("TYPE_SHOT"));
		tossentity(vShot, Vy, 0, 0.2);
	}

	return vShot;
}

void spawnToss(void name, float dx, float dy, float dz, float Vx, float Vy, float Vz, void ani, int atk)
{//Spawn and Toss entity with defined conditions (DEFAULT TOSS SCRIPT USED FOR ALL SPAWNED ENTITIES, LIKE ITENS)
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void hostile	= getentityproperty(self, "hostile");
	void candamage	= getentityproperty(self, "candamage");
	void vSpawn 	= spawn01(name, dx, dy, dz);
	int direction 	= getentityproperty(self, "direction");

	if(direction == 0){Vx = -Vx;}
	tossentity(vSpawn, Vy, Vx, Vz);
	changeentityproperty(vSpawn, "parent", self);

	//SPAWN WITH A SPECIFIC ANIMATION??
	if(ani != NULL()){changeentityproperty(vSpawn, "animation", openborconstant(ani));}

	//THIS ENTITY IS USED FOR ATTACKS??
	if(atk != NULL()){
		float offense	= getentityproperty(self, "offense", 0);
		int disable		= getentityproperty(self, "energycost", "disable", openborconstant(getlocalvar("animnum")));

		changeentityproperty(vSpawn, "owner", self);
		changeentityproperty(vSpawn, "hostile", hostile);
		changeentityproperty(vSpawn, "candamage", candamage);
		changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL"), offense);
		changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL2"), offense);
		changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL6"), offense);
		changeentityproperty(vSpawn, "offense", openborconstant("ATK_BURN"), offense);
		changeentityproperty(vSpawn, "offense", openborconstant("ATK_SHOCK"), offense);
		setentityvar(vSpawn, "disable", disable);

		//IS ENTITY A ENEMY TYPE?
		if(type == openborconstant("TYPE_ENEMY")){changeentityproperty(vSpawn, "type", openborconstant("TYPE_SHOT"));}
	}
}

void spawnAnim(void name, float dx, float dy, float dz)
{//Spawn entity with same animation and map as spawner's (YAMATO DOUBLE SLASH/RAGE)
	void self 		= getlocalvar("self");
	void type		= getentityproperty(self, "type");
	void hostile	= getentityproperty(self, "hostile");
	void candamage	= getentityproperty(self, "candamage");
	void vSpawn 	= spawn01(name, dx, dy, dz);
	int disable		= getentityproperty(self, "energycost", "disable", openborconstant(getlocalvar("animnum")));
	int  map 		= getentityproperty(self, "map");
	float offense	= getentityproperty(self, "offense", 0);

	performattack(vSpawn, openborconstant(getlocalvar("animnum")), 1);
	changeentityproperty(vSpawn, "map", map);
	changeentityproperty(vSpawn, "parent", self);
	changeentityproperty(vSpawn, "owner", self);
	changeentityproperty(vSpawn, "hostile", hostile);
	changeentityproperty(vSpawn, "candamage", candamage);
	changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL"), offense);
	changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL2"), offense);
	changeentityproperty(vSpawn, "offense", openborconstant("ATK_NORMAL6"), offense);
	changeentityproperty(vSpawn, "offense", openborconstant("ATK_BURN"), offense);
	changeentityproperty(vSpawn, "offense", openborconstant("ATK_SHOCK"), offense);
	setentityvar(vSpawn, "disable", disable);

	//IS ENTITY A ENEMY TYPE?
	if(type == openborconstant("TYPE_ENEMY")){changeentityproperty(vSpawn, "type", openborconstant("TYPE_SHOT"));}
}

void spawnBind(void name, float dx, float dy, float dz, void varName)
{//Spawn and bind other entity
 //Can set entityvar to save the entity for further use
	void self   = getlocalvar("self");
	void vSpawn = spawn01(name, dx, dy, 0);

	bindentity(vSpawn, self, dx, dz, dy, 0, 0);
	changeentityproperty(vSpawn, "parent", self); //SET CALLER AS PARENT.

	if(varName != NULL()){setentityvar(self, varName, vSpawn);}
}

void bindPos(void name, float dx, float dy, float dz)
{//Spawn, bind and change spawned entity position at each frame
	void self 	 = getlocalvar("self");
	void varName = getentityvar(self, name);
	void vSpawn;

	if(varName == NULL()){
		vSpawn = spawn01(name, dx, dy, 0);
		bindentity(vSpawn, self, dx, dz, dy, 0, 0);
		changeentityproperty(vSpawn, "parent", self);
		setentityvar(self, name, vSpawn);
	}else{
		bindentity(varName, self, dx, dz, dy, 0, 0);
	}
}

void spawnScreen(void name, float fX, float fY, float fZ)
{//Spawn entity at specific location relative to xPos and yPos
	void self 	= getlocalvar("self");
	void vSpawn = spawn01(name, 0, 0, 0);
	float xPos 	= openborvariant("xpos");

	fX = xPos+fX; //CHANGES POSITION RELATIVE TO XPOS
	changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
}

void spawnScreenX(void name, float fX, float fY, float fZ)
{//Spawn entity at Random location relative to xPos (WAVE SPLASH)
	void self 	= getlocalvar("self");
	void vSpawn = spawn01(name, 0, 0, 0);
	float xPos 	= openborvariant("xpos");
	float xR 	= rand()%220+240; //RANDOM XPOS
	float sR 	= rand()%50+50; //RANDOM SPAWN

	if(sR >= 0 && sR < 50){
		fX = fX+xPos+xR; //CHANGES POSITION RELATIVE TO XPOS
		changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
	}
}

void spawnScreenZ(void name, float fX, float fY, float fZ, int level)
{//Spawn entity at specific location relative to xPos and yPos with Player_max_z (SOR3_ST6 ELEVATOR)
	void self 	= getlocalvar("self");
	float xPos 	= openborvariant("xpos");
	float zPos	= openborvariant("player_max_z");

	if(getglobalvar("gasEnable") != 1){
		void vSpawn = spawn01(name, 0, 0, 0, level);

		fX = xPos+fX; //CHANGES POSITION RELATIVE TO XPOS
		fZ = zPos+fZ; //CHANGES POSITION RELATIVE TO ZPOS

		changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
	}
}

void spawnScreenD(void name, float fX, float fY, float fZ)
{//Spawn entity at specific location relative to xPos
 //Spawned entity's will have screen's edge location based on caller's DIRECTION (ROCKET RESCUE)
	void self	= getlocalvar("self");
	void vSpawn	= spawn01(name, 0, 0, 0);
	int dir		= getentityproperty(self, "direction");
	float xPos	= openborvariant("xpos");
	float hRes	= openborvariant("hresolution");

	if(dir == 0){
		fX = xPos+hRes-fX; //CHANGES POSITION RELATIVE TO XPOS
	}else{
		fX = xPos+fX; //CHANGES POSITION RELATIVE TO XPOS
	}

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", dir); //Set spawn direction.
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
}

void spawnParent(void name, float dx, float dy, float dz)
{//Spawn and set vSpawn/Self Parent order
	void self   = getlocalvar("self");
	void vSpawn = spawn01(name, dx, dy, dz);

	changeentityproperty(vSpawn, "parent", self); //SET CALLER AS PARENT.
}

void spawnVar(void vName, void varName, float fX, float fY, float fZ, int bossFlag, int map, int dir, void anim)
{//Spawn and mark an entity with a defined entityvar name for further use (SOR3 ST6 PANEL/MONALISA SISTER/YAMATO BROTHERS/BRUCE/ARM)
	void vSpawn;
	void self		= getlocalvar("self");
	int  direction	= getentityproperty(self, "direction");

	clearspawnentry();
	setspawnentry("name", vName);
	setspawnentry("boss", bossFlag);
	setspawnentry("map", map);

	//SET CUSTOM DIRECTION
	if(dir != NULL()){direction = dir;}else{if(direction == 0){fX = -fX;}}

	fX = fX + getentityproperty(self, "x");
	fY = fY + getentityproperty(self, "y");
	fZ = fZ + getentityproperty(self, "z");

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", fX, fZ, fY);
	changeentityproperty(vSpawn, "direction", direction);

	//SET CUSTOM VARIABLE
	if(varName != NULL()){setentityvar(self, varName, vSpawn);}

	//SET CUSTOM ANIMATION
	if(anim != NULL()){changeentityproperty(vSpawn, "animation", anim);}

	return vSpawn;
}

void spawnFacing(void vName, float fX, float fY, float fZ, int facing, int level)
{//Spawn entity with a manual defined direction
	void self 		= getlocalvar("self");
	void vSpawn;
	int  direction 	= getentityproperty(self, "direction");

	clearspawnentry();
	setspawnentry("name", vName);
	setspawnentry("map", level);

	if(direction == 0){fX = -fX;}

	fX = fX + getentityproperty(self, "x");
	fY = fY + getentityproperty(self, "y");
	fZ = fZ + getentityproperty(self, "z");

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", fX, fZ, fY);

	if(facing != NULL()){
		changeentityproperty(vSpawn, "direction", facing);
	}else{
		changeentityproperty(vSpawn, "direction", direction);
	}

	return vSpawn;
}

void spawnAlias(void vName, void vAlias, float fX, float fY, float fZ, void ani)
{//Custom "spawn01" for for Vehelits, spawn and define custom alias
	void vSpawn;
	void self	= getlocalvar("self");
	int iDir	= getentityproperty(self, "direction");

	clearspawnentry();
	setspawnentry("name", vName);
	setspawnentry("boss", 0);
	setspawnentry("map", 4);

	if(iDir == 0){fX = -fX;}

	fX = fX + getentityproperty(self, "x");
	fY = fY + getentityproperty(self, "y");
	fZ = fZ + getentityproperty(self, "z");

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //SET SPAWN LOCATION.
	changeentityproperty(vSpawn, "direction", iDir); //SET DIRECTION.
	changeentityproperty(vSpawn, "name", vAlias); //SET ALIAS.
	changeentityproperty(vSpawn, "parent", self); //SET CALLER AS PARENT.
	if(ani != NULL()){changeentityproperty(vSpawn, "animation", ani);} //SET ANIMATION.

	return vSpawn;
}

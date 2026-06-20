void keyMove(float xVel, float zVel)
{//Move entity if direction button is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= 0;
	float zdir 	= 0;

	if(xVel != 0){
		if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
			xdir = -xVel;
		}
		else
		if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
			xdir = xVel;
		}
	}else{
		xdir = NULL();
	}

	if(zVel != 0){
		if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
			zdir = -zVel/2;
		}
		else
		if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
			zdir = zVel/2;
		}
	}else{
		zdir = NULL();
	}

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keyVel()
{//Change X velocity if defined button is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	int dir 	= getentityproperty(self,"direction");
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= 0;

	if(dir == 0){
		if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
			xdir = xdir*2;
		}
		else
		if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
			xdir = xdir/2;
		}
	}
	else
	if(dir == 1){
		if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
			xdir = xdir/2;
		}
		else
		if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
			xdir = xdir*2;
		}
	}

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keyFlip()
{//Change entity's facing direction if left or right is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index

	if(playerkeys(iPIndex, 0, "moveleft")){changeentityproperty(self, "direction", 0);}else
	if(playerkeys(iPIndex, 0, "moveright")){changeentityproperty(self, "direction", 1);}
}

void keyLoop(void key, int frame, void var, void value)
{//Loops defined frame if defined key is held
 //Use "var" if you want to define a variable requirement, otherwise let it empty
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex");

	if(var != NULL()){
		if(getglobalvar(var) == value){
			if(playerkeys(iPIndex, 0, key)){updateframe(self, frame);}
		}
	}
	else
	{
		if(playerkeys(iPIndex, 0, key)){updateframe(self, frame);}
	}
}

void keyAni(void key, void ani, void var, void value)
{//Execute animation if defined key is held
 //Use "var" if you want to define a variable requirement, otherwise let it empty
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex");

	if(var != NULL()){
		if(getglobalvar(var) == value){
			if(playerkeys(iPIndex, 0, key)){executeanimation(self, openborconstant(ani));}
		}
	}
	else
	{
		if(playerkeys(iPIndex, 0, key)){executeanimation(self, openborconstant(ani));}
	}
}

void readKey(void key) {
	void self = getlocalvar("self");
	int pindex = getentityproperty(self,"playerindex");
	int facing = getentityproperty(self, "direction");

	if(key=="left" || key=="l") { return playerkeys(pindex, 0, "moveleft"); }
	else if(key=="right" || key=="r") { return playerkeys(pindex, 0, "moveright"); }
	else if(key=="up" || key=="u") { return playerkeys(pindex, 0, "moveup"); }
	else if(key=="down" || key=="d") { return playerkeys(pindex, 0, "movedown"); }
	else if(key=="attack" || key=="atk" || key=="a") { return playerkeys(pindex, 0, "attack"); }
	else if(key=="attack2" || key=="atk2" || key=="a2") { return playerkeys(pindex, 0, "attack2"); }
	else if(key=="attack3" || key=="atk3" || key=="a3") { return playerkeys(pindex, 0, "attack3"); }
	else if(key=="attack4" || key=="atk4" || key=="a4") { return playerkeys(pindex, 0, "attack4"); }
	else if(key=="jump" || key=="j") { return playerkeys(pindex, 0, "jump"); }
	else if(key=="special" || key=="sp" || key=="s") { return playerkeys(pindex, 0, "special"); }

	else if(key=="backward" || key=="back" || key=="b") {
		if(facing) { return playerkeys(pindex, 0, "moveleft"); }
		else { return playerkeys(pindex, 0, "moveright"); }
	}
	else if(key=="forward" || key=="fwd" || key=="f") {
		if(facing) { return playerkeys(pindex, 0, "moveright"); }
		else { return playerkeys(pindex, 0, "moveleft"); }
	}
	else { return 0; }
}

/*
 * auto turn to the nearest target
 */
void autoTurn() {
	void self = getlocalvar("self");
	void opponent = findtarget(self);

	float pX = getentityproperty(self, "x");

	if(opponent!= NULL()) {
		float eX = getentityproperty(opponent, "x");

		if(eX < pX) { changeentityproperty(self, "direction", 0); }
		else { changeentityproperty(self, "direction", 1); }
	}
}
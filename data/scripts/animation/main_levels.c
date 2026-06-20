void addBlockade(int pos)
{//Add Blockade in the defined position

	changeopenborvariant("blockade", pos);
}

void removeWall(int id)
{//Remove defined wall by ID

	changelevelproperty("wall", id, "x", 9999, "z", 9999, "depth", 0, "height", 0);
}

void removeHole(int id)
{//Remove defined hole by ID

	changelevelproperty("hole", id, "x", 9999, "z", 9999, "depth", 0, "height", 0);
}

void zeroWait()
{//Change stage "Wait" to 0 to spawn next group

	changeopenborvariant("waiting", 0);
}

void reseTime()
{//Reset game time to 99

	changeopenborvariant("game_time", 39600);
}

void disableLayer(void type, int index)
{//Disable level layers

	changelayerproperty(type, index, "enabled", 0);
}

void autoLife(int iHealth)
{//Recover defined health for all players automatically
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	void partner = getglobalvar("currentPartner");
	int iHealth1 = getentityproperty(player1, "health");
	int iHealth2 = getentityproperty(player2, "health");
	int iHealth3 = getentityproperty(player3, "health");
	int iHealth4 = getentityproperty(player4, "health");
	int iHealth5 = getentityproperty(partner, "health");

	if(iHealth1 > 0){changeentityproperty(player1, "health", iHealth1+iHealth);}
	if(iHealth2 > 0){changeentityproperty(player2, "health", iHealth2+iHealth);}
	if(iHealth3 > 0){changeentityproperty(player3, "health", iHealth3+iHealth);}
	if(iHealth4 > 0){changeentityproperty(player4, "health", iHealth4+iHealth);}
	if(iHealth5 > 0){changeentityproperty(partner, "health", iHealth5+iHealth);}
}

void slowMotion(int flag)
{//Change slowmotion effect

	if(flag == 1){
		changeopenborvariant("slowmotion", 1);
	}else{
		changeopenborvariant("slowmotion", 0);
	}
}

void resetScroll()
{//Reset scrolling speed to the default GAME SETTINGS option
	float screenSpeed;

	setglobalvar("lockScroll", NULL()); //TELL THE ENGINE THAT THE SCREEN SCROLLER IS ALLOWED

	if(getglobalvar("scrollSpeed") == "normal"){screenSpeed = 0.5;}else{screenSpeed = 1;}
	changelevelproperty("scrollspeed", screenSpeed);
}
#import "data/scripts/updatelevel/main.c"

void main()
{
	spawnTime();
	cycleSprite("bglayer", 0, 3, 40);
}

void enemyTime(float dx, float dy, float dz)
{//Spawns random enemy next to caller (ACCORDING TO GAME TIME)
	void self 	= getglobalvar("spawnTime");
	void vName;
	void vSpawn;
	int  iDir	= getentityproperty(self,"direction");
	int  iR 	= rand()%12+12;

	if(getglobalvar("end") != 1){
		if(iR == 1)	{vName = "BasicX1";}else
		if(iR == 2)	{vName = "SignalX";}else
		if(iR == 3)	{vName = "FogX";}else
		if(iR == 4)	{vName = "HakuyoX";}else
		if(iR == 5)	{vName = "KusanagiX";}else
		if(iR == 6)	{vName = "RavenX";}else
		if(iR == 7)	{vName = "BigbenX";}else
		if(iR == 8)	{vName = "ReineX";}else
		if(iR == 9)	{vName = "JackB";}else
		if(iR == 10){vName = "BasicX2";}else
		if(iR == 11){vName = "GarnetX";}else
		if(iR == 12){vName = "BodyGuardX";}else
		if(iR == 13){vName = "TigerX";}else
		if(iR == 14){vName = "P1X";}else
		if(iR == 15){vName = "BongoX";}else
		if(iR == 16){vName = "ElectraX";}else
		if(iR == 17){vName = "AshB";}else
		if(iR == 18){vName = "BruceB";}else
		if(iR == 19){vName = "RooB";}else
		{vName = "BasicX1";}

		clearspawnentry();
		setspawnentry("name", vName);

		vSpawn = spawn();

		bindentity(vSpawn, self, dx, dz, dy, iDir);
		bindentity(vSpawn, NULL());
		setglobalvar("count_enemies", getglobalvar("count_enemies")+1);

		return vSpawn;
	}
}


void enemyKill(float dx, float dy, float dz)
{//Spawns random enemy next to caller (ACCORDING TO GAME TOTAL KILL COUNT)
	void self 	= getglobalvar("spawnTime");
	void vRName = getentityproperty(self,"defaultname");
	void vName;
	void vSpawn;
	int  iDir	= getentityproperty(self,"direction");
	int map;

	if(getglobalvar("end") != 1){

		//STAGE 1
		if(getlocalvar("spawned") == NULL())		{vName = "BarbonB";setlocalvar("spawned", vName);}else

		//STAGE 2
		if(getlocalvar("spawned") == "BarbonB")		{vName = "JetB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "JetB")		{vName = "MonalisaB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "MonalisaB")	{vName = "MonalisaC";setlocalvar("spawned", vName);}else

		//STAGE 3
		if(getlocalvar("spawned") == "MonalisaC")	{vName = "ZamzaB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "ZamzaB")		{vName = "TrackerB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "TrackerB")	{vName = "BreakB";setlocalvar("spawned", vName);}else

		//STAGE 4
		if(getlocalvar("spawned") == "BreakB")		{vName = "AbadedeB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "AbadedeB")	{vName = "YamatoB";setlocalvar("spawned", vName);}else

		//STAGE 5
		if(getlocalvar("spawned") == "YamatoB")		{vName = "BearB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "BearB")		{vName = "RobotxB";setlocalvar("spawned", vName);}else

		//STAGE 6
		if(getlocalvar("spawned") == "RobotxB")		{vName = "HarakiriB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "HarakiriB")	{vName = "RocketB";setlocalvar("spawned", vName);}else

		//STAGE 7
		if(getlocalvar("spawned") == "RocketB")		{vName = "ParticleB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "ParticleB")	{vName = "Shiva_BotB";setlocalvar("spawned", vName);}else

		//STAGE 8
		if(getlocalvar("spawned") == "Shiva_BotB")	{vName = "ShivaB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "ShivaB")		{vName = "MrxB";setlocalvar("spawned", vName);}else
		if(getlocalvar("spawned") == "MrxB")		{vName = "NeoxB";setlocalvar("spawned", vName);}

		clearspawnentry();
		setspawnentry("name", vName);

		//EXCEPTIONS
		if(vName == "MonalisaC"){setspawnentry("map", 1);}
		if(vName == "BreakB"){setspawnentry("map", 1);}
		if(vName == "NeoxB"){setspawnentry("boss", 1);setglobalvar("end", 1);}

		vSpawn = spawn();

		bindentity(vSpawn, self, dx, dz, dy, iDir);
		bindentity(vSpawn, NULL());
		setglobalvar("count_enemies", getglobalvar("count_enemies")+1);

		return vSpawn;
	}
}

void spawnX(void name1, void name2, void name3, void name4, float dx, float dy, float dz)
{//Spawns random entity next to caller (4 ENTITIES, ITENS, WEAPONS)
	void self 	= getglobalvar("spawnTime");
	void vSpawn;
	void vRName = getentityproperty(self,"defaultname");
	int  iDir	= getentityproperty(self,"direction");
	int  iR 	= rand()%50+50;
	float xR 	= rand()%240+240;
	float xPos	= openborvariant("xpos");

	dx = xPos+xR;

	if(iR >= 0 	&& iR < 25){	vRName = name1;}else
	if(iR >= 25 && iR < 50){	vRName = name2;}else
	if(iR >= 50 && iR < 75){	vRName = name3;}else
	if(iR >= 75 && iR <= 100){	vRName = name4;}

	clearspawnentry();
	setspawnentry("name", vRName);

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", dx, dz, dy);
	changeentityproperty(vSpawn, "direction", iDir);

	return vSpawn;
}

void spawnTime()
{//Spawn random Enemy according to elapsed time
	void drop		= getglobalvar("itemDrop");
	int pCount		= openborvariant("count_players");
	int groupSize	= getglobalvar("survivalGroupSize");
	int bossTrigger	= getglobalvar("survivalBossRate");
	int seconds		= 400;
	int ko0			= getglobalvar("ko0");
	int ko1			= getglobalvar("ko1");
	int ko2			= getglobalvar("ko2");
	int ko3			= getglobalvar("ko3");
	int totalKO		= ko0+ko1+ko2+ko3;
	float time		= openborvariant("game_time");
	float limit		= 50;

	if(time <= limit/2){if(openborvariant("count_players") > 0){changeopenborvariant("game_time", limit*1.5);}}
	if(getglobalvar("count_enemies") == NULL()){setglobalvar("count_enemies", 0);}
	if(getlocalvar("bossSpawn") == NULL()){setlocalvar("bossSpawn", bossTrigger);}

	int spawnRate = (getglobalvar("survivalGroupRate")*seconds)+(seconds/4*3);

	if(getglobalvar("activeText") == 0){
		if(getglobalvar("count_enemies") < groupSize && getglobalvar("end") != 1){
			if(time <= limit){
				if(pCount >= 1 && pCount <= 2){
					if(totalKO >= getlocalvar("bossSpawn")){
						enemyKill(0, 300, 0);

						if(drop == "mixed" || drop == "food_only" || drop == "food+money" || drop == "food+weapon"){
							spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 250, 200);
						}

						if(drop == "mixed" || drop == "weapon_only" || drop == "money+weapon" || drop == "food+weapon"){
							spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 270, 230);
						}

						changeopenborvariant("game_time", time+spawnRate);
						setlocalvar("bossSpawn", getlocalvar("bossSpawn")+bossTrigger);
					}
					else
					{
						enemyTime(0, 300, 0);
						changeopenborvariant("game_time", time+spawnRate);
					}
				}
				else
				if(pCount > 2){
					if(totalKO >= getlocalvar("bossSpawn")){
						enemyKill(0, 300, 0);

						if(drop == "mixed" || drop == "food_only" || drop == "food+money" || drop == "food+weapon"){
							spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 250, 200);
						}

						if(drop == "mixed" || drop == "weapon_only" || drop == "money+weapon" || drop == "food+weapon"){
							spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 270, 230);
						}

						changeopenborvariant("game_time", time+spawnRate);
						setlocalvar("bossSpawn", getlocalvar("bossSpawn")+bossTrigger);
					}
					else
					{
						enemyTime(0, 300, 0);
						enemyTime(0, 400, 20);
						changeopenborvariant("game_time", time+spawnRate);
					}
				}
			}
		}
	}

	//DEFINE CONTENT VALUES
	int xPos1 = 1;
	int xPos2 = 85;
	int yPos  = 240;
	int yAdd  = 10;
	int font0 = 0;
	int font1 = 1;

	//DRAW ALL INFO IN THE SCREEN
	drawstring(xPos1, yPos, font0, "total_k.o.:_"); //SHOW TOTAL KO OF ALL PLAYERS
	drawstring(xPos2, yPos, font1, totalKO); //SHOW TOTAL KO OF ALL PLAYERS
	yPos = yPos+yAdd;
	drawstring(xPos1, yPos, font0, "next_enemy:_"); 	//SHOW NEXT SPAWN COUNTDOWN
	drawstring(xPos2, yPos, font1, time/seconds); //SHOW NEXT SPAWN COUNTDOWN
	yPos = yPos+yAdd;
	drawstring(xPos1, yPos, font0, "group_size:_"); //SHOW TOTAL ENEMIES IN THE SCREEN
	drawstring(xPos2, yPos, font1, getglobalvar("count_enemies")); //SHOW TOTAL ENEMIES IN THE SCREEN
}
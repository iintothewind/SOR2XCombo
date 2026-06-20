#import "data/scripts/animation/main_spawns.c"

void main()
{//Start all necessary variables and spawn all necessary entities

	//START ALL NECESSARY VARIABLES
	void self		= getlocalvar("self");
	float maxZ		= openborvariant("player_max_z");
	int sideStart	= "a";
	int floorStart	= 3;

	if(getglobalvar("st6_side") == NULL()){setglobalvar("st6_side", sideStart);}
	if(getglobalvar("st6_floor") == NULL()){setglobalvar("st6_floor", floorStart);}

	//DEFINE PANEL POSITIONS
	int panelDownX	= 1439;
	int panelDownZ	= 872;
	int panelUpX	= 1387;
	int panelUpZ	= 924;

	//SPAWN PANELS
	spawnVar("St6_Panel_Down", "panelDownA", -panelDownX, 0, -panelDownZ, 0);
	spawnVar("St6_Panel_Down", "panelDownB",  panelDownX, 0, -panelDownZ, 0, 0, 0);
	spawnVar("St6_Panel_Up", "panelUpA", -panelUpX, 0, -panelUpZ, 0);
	spawnVar("St6_Panel_Up", "panelUpB", panelUpX, 0, -panelUpZ, 0, 0, 0);

	//DEFINE ROOM POSITIONS
	int roomX1	= -718;
	int roomX2	= -534;
	int roomX3	= -626;
	int roomX4	= -272;
	int roomX5	= 535;
	int roomX6	= 279;
	int roomX7	= 710;
	int exitX	= 391;
	int roomZ	= -952;
	int gateX1	= -807;
	int gateX2	= 0;
	int gateX3	= 807;
	int lockX	= 354;
	int lockZ	= -992;

	//SPAWN ROOM'S DOORS GATES
	spawnAlias("St6_Rooms", "Room1", roomX1, 0, roomZ);
	spawnAlias("St6_Rooms", "Room2", roomX2, 0, roomZ);
	spawnAlias("St6_Rooms", "Room3", roomX3, 0, roomZ);
	spawnAlias("St6_Rooms", "Room4", roomX4, 0, roomZ);
	spawnAlias("St6_Rooms", "Room5", roomX5, 0, roomZ);
	spawnAlias("St6_Rooms", "Room6", roomX6, 0, roomZ);
	spawnAlias("St6_Rooms", "Room7", roomX7, 0, roomZ);
	spawnAlias("St6_Exit", "Exit", exitX, 0, roomZ);
	spawnAlias("St6_Gate", "Gate", gateX1, 0, roomZ);
	spawnAlias("St6_Gate", "Gate", gateX2, 0, roomZ);
	spawnAlias("St6_Gate", "Gate", gateX3, 0, roomZ);
	spawnAlias("St6_Locks", "Locks", lockX, 0, lockZ);

	//DEFINE BOXES POSITIONS
	void vSpawn;
	int boxZ	= -940;
	int zDif	= 276;

	//SPAWN GENERAL IF HE IS NOT RESCUED YET
	if(getglobalvar("generalRescued") == NULL()){

		//DEFINE GENERAL POSITION
		void vGen;
		int xGen	= 343;
		int zGen	= -686;

		//SPAWN GENERAL
		vGen = spawn01("St6_General", 0, 0, 0);
		bindentity(vGen, self, xGen, zGen, 0, 0, 0);
		setglobalvar("general", vGen);

		//CALL LASER ENTITIES
		void vSpawn1;
		void vSpawn2;

		//SPAWN LASER GRID AND BIND ENTITY
		if(getglobalvar("st6_locks") == NULL()){
			vSpawn1 = spawn01("St6_LaserGrid", 0, 0, 0);
			vSpawn2 = spawn01("St6_LaserGrid", 0, 0, 0);
			bindentity(vSpawn1, self, xGen, zGen+1, 0, 0, 0);
			bindentity(vSpawn2, self, xGen, zGen+2, 0, 0, 0);
			changeentityproperty(vSpawn1, "animation", openborconstant("ANI_IDLE"));
			changeentityproperty(vSpawn2, "animation", openborconstant("ANI_FOLLOW1"));
		}
		else
		if(getglobalvar("st6_locks") <= 1){
			vSpawn1 = spawn01("St6_LaserGrid", 0, 0, 0);
			bindentity(vSpawn1, self, xGen, zGen+1, 0, 0, 0);
			changeentityproperty(vSpawn1, "animation", openborconstant("ANI_IDLE"));
		}
	}

	//DEFINE TOXIC GAS POSITIONS
	int gasX1	= -470;
	int gasX2	= 472;
	int gasZ	= -960;

	//SPAWN TOXIC GAS
	spawnAlias("St6_Gas", "Gas1", gasX1, 0, gasZ);
	spawnAlias("St6_Gas", "Gas2", gasX2, 0, gasZ);

	//GET DEFAULT VALUES AND PROPERTIES
	void player1	= getplayerproperty(0, "entity");
	void player2	= getplayerproperty(1, "entity");
	void player3	= getplayerproperty(2, "entity");
	void player4	= getplayerproperty(3, "entity");
	void partner	= getglobalvar("currentPartner");
	int side		= getglobalvar("st6_side");
	int floor		= getglobalvar("st6_floor");
	int floorZpos	= getglobalvar("st6_zpos");
	int startDirA	= 0;
	int startDirB	= 1;
	int startDir;
	int startPosA	= 767;
	int startPosB	= 1707;
	int startPos;
	int adjustX		= 240;
	int difZ		= 20;

	//APPLY THE LAST REGISTERED ELEVATOR'S "Z" POSITION WHEN BACK TO THE ELEVATOR'S LEVEL
	if(floorZpos != NULL()){changeentityproperty(self, "z", floorZpos);}

	//CHECK THE CURRENT ELEVATOR SIDE AND CHANGE THE SPAWN POSITION AND DIRECTION IF NECESSARY
	if(side == "a"){
		startPos = startPosA;
		startDir = startDirA;
	}
	else
	if(side == "b"){
		startPos = startPosB;
		startDir = startDirB;
	}

	//APPLY ALL DEFINED VALUES
	changeentityproperty(player1, "direction", startDir);
	changeentityproperty(player2, "direction", startDir);
	changeentityproperty(player3, "direction", startDir);
	changeentityproperty(player4, "direction", startDir);
	changeentityproperty(partner, "direction", startDir);
	changeentityproperty(player1, "position", startPos+adjustX);
	changeentityproperty(player2, "position", startPos+adjustX);
	changeentityproperty(player3, "position", startPos+adjustX);
	changeentityproperty(player4, "position", startPos+adjustX);
	changeentityproperty(partner, "position", startPos+adjustX);
	changeopenborvariant("xpos", startPos);
}
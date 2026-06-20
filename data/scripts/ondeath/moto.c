void main()
{//Spawns random item next to caller and toss it (SPAWN BIKER ACCORDING TO THE CURRENT PALETTE)
 //Replaces the "Rider" native function for bikers
	void self	= getlocalvar("self");
	void vName	= "FogB";
	void vSpawn;
	void vAlias	= getentityproperty(self,"name");
	int dir		= getentityproperty(self,"direction");
	int map		= getentityproperty(self,"map");
	float time	= openborvariant("elapsed_time");
	float limit	= 150;
	float fX	= getentityproperty(self, "x");
	float fY	= getentityproperty(self, "y");
	float fZ	= getentityproperty(self, "z");
	float Vx	= 1;
	float Vy	= 2;
	float Vz	= 0;

	if(dir == 0){Vx = -Vx;}

	clearspawnentry();
	setspawnentry("name", vName);
	setspawnentry("map", map);

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", fX, fZ, fY);
	changeentityproperty(vSpawn, "direction", dir);
	changeentityproperty(vSpawn, "animation", openborconstant("ANI_WALKOFF"));
	changeentityproperty(vSpawn, "name", vAlias);
	tossentity(vSpawn, Vy, Vx, Vz);
	damageentity(vSpawn, self, 0, 1, openborconstant("ATK_NORMAL10")); //USED TO AVOID WRONG SHOW DAMAGE
	changeentityproperty(vSpawn, "aiflag", "invincible", 1);
	changeentityproperty(vSpawn, "invinctime", time+limit);

	return vSpawn;
}
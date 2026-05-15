#import "data/scripts/animation/main_spawns.c"

void main()
{
	grenade();
	zLimit();
	motorBike();
}

void grenade()
{//Throw Grenade/Molotov with RANGE and HEALTH/MP check (MOTORBIKE ENEMY)
	void self = getlocalvar("self");
	void type = getentityproperty(self,"type");
	
	if(type == openborconstant("TYPE_ENEMY")){
		void target = findtarget(self);
		void ani 	= getentityproperty(self,"animationID");
		int frame	= getentityproperty(self,"animpos");
		int mp 		= getentityproperty(self,"mp");
		int base  	= getentityproperty(self,"base");
		int Vx 		= getentityproperty(self,"x");
		int Vz 		= getentityproperty(self,"z");
		int Tx 		= getentityproperty(target,"x");
		int Ty 		= getentityproperty(target,"y");
		int Tz 		= getentityproperty(target,"z");
		int cost1	= 1;
		int cost2	= 3;
		
		if(openborvariant("current_branch") != "sor3_st7d"){
			if(ani == openborconstant("ANI_IDLE")){
				if(frame >= 1){
					if(mp >= cost1){
						if(Tx <= Vx && Tx >= Vx-2 && Tz <= Vz+999 && Tz >= Vz-999){
							changeentityproperty(self, "mp", mp-cost1);
							executeanimation(self, openborconstant("ANI_FOLLOW1"), 1); //THROW GRENADE
						}
					}
				}
			}
		}
		
		if(openborvariant("current_branch") == "sor3_st7d"){
			if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_WALK")){
				if(frame >= 1){
					if(mp >= cost2){
						if(Tx < Vx && Ty <= base && Tz <= Vz+12 && Tz >= Vz-12){
							changeentityproperty(self, "mp", mp-cost2);
							executeanimation(self, openborconstant("ANI_FOLLOW1"), 1); //THROW MOLOTOV
						}
					}
				}
			}
		}
	}
}

void zLimit()
{//Limit Z in st6b (MOTO)
	void self 	= getlocalvar("self");
	void branch = openborvariant("current_branch");
	void type 	= getentityproperty(self, "type");
	int z 		= getentityproperty(self, "z");
	float zR    = rand()%20+430;
	
	if(branch == "sor2_st6b"){
		if(type == openborconstant("TYPE_ENEMY")){if(z <= 409){changeentityproperty(self, "z", zR);}}
	}
}

void motorBike()
{//Adjust bike ENEMY properties in Bike Stage
	void self 	= getlocalvar("self");
	void branch = openborvariant("current_branch");
	void vType 	= getentityproperty(self, "type");
	
	if(branch == "sor3_st7d"){
		if(vType == openborconstant("TYPE_ENEMY")){
			void vAnID 		= getentityproperty(self, "animationID");
			void vSpawn;
			int pain 		= getentityproperty(self, "aiflag", "inpain");
			int dead 		= getentityproperty(self, "dead");
			int useNitro	= getglobalvar("useNitro");
			int useBrake	= getglobalvar("useBrake");
			float move 		= getglobalvar("move");
			float delay 	= getglobalvar("delay");
			float bgSpeed 	= getglobalvar("bgSpeed");
			
			if(pain == 0 && dead == 0){
				if(vAnID != openborconstant("ANI_FOLLOW1")){
					if(bgSpeed <= 0){updateframe(self, 0);}
				}
				
				if(useNitro == 1){
					changeentityproperty(self, "velocity", -bgSpeed/5000, NULL(), NULL());
				}else{
					changeentityproperty(self, "velocity", NULL(), NULL(), NULL());
				}
				
				if(useBrake == 1){
					changeentityproperty(self, "velocity", bgSpeed/10000, NULL(), NULL());
				}else{
					changeentityproperty(self, "velocity", NULL(), NULL(), NULL());
				}
				
				changeentityproperty(self, "speed", move/1.2);
				changeentityproperty(self, "jumpspeed", move/1.2);
				changeentityproperty(self, "edelay", 0, delay, 1, 9999, 0.001, 9999);
				setlocalvar("counter", 0);
			}
			
			if(dead == 1){
				void counter = getlocalvar("counter");  //Set a variable to trigger the spawn on and off
				while(counter != 1){ //Check the variable to avoid double spawn
					void vAlias	= getentityproperty(self, "name");
					int map		= getentityproperty(self, "map");
					vSpawn = spawn01("FogB", 0, 0, 0);
					changeentityproperty(vSpawn, "name", vAlias);
					changeentityproperty(vSpawn, "map", map);
					changeentityproperty(vSpawn, "subtype", openborconstant("SUBTYPE_NOTGRAB"));
					damageentity(vSpawn, self, 9999, 1, openborconstant("ATK_NORMAL10")); //USED TO AVOID WRONG SHOW DAMAGE
					tossentity(vSpawn, 6, -6, 0);
					counter = setlocalvar("counter", 1); //turn on the variable, blocking a new spawn to be made
				}
				changeentityproperty(self, "edelay", 0, 0, 1, 9999, 0.001, 9999);
				changeentityproperty(self, "velocity", -bgSpeed/5000, 0, 0);
			}
		}
	}
}
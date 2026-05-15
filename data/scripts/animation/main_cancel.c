#import "data/scripts/main.c"

void cancel(int xMin, int xMax, int yMin, int yMax, int zMin, int zMax, void ani)
{//Attack interruption with range check
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int z 		= getentityproperty(self, "z");
	int dir 	= getentityproperty(self, "direction");

	if(target != NULL()){
		int Tx = getentityproperty(target, "x");
		int Ty = getentityproperty(target, "y");
		int Tz = getentityproperty(target, "z");
		int Dx = Tx - x;
		int Dy = Ty - y;
		int Dz = Tz - z;

		if(Dx >= xMin && Dx <= xMax && Dy >= yMin && Dy <= yMax && Dz >= zMin && Dz <= zMax && dir == 1){
			performattack(self, openborconstant(ani), 1);
		}
		else
		if(Dx >= -xMax && Dx <= -xMin && Dy >= yMin && Dy <= yMax && Dz >= zMin && Dz <= zMax && dir == 0){
			performattack(self, openborconstant(ani), 1);
		}
	}
}

void cancelMp(int xMin, int xMax, int yMin, int yMax, int limit, void ani)
{//Attack interruption with range and MP check
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int mp		= getentityproperty(self, "mp");
	int dir 	= getentityproperty(self, "direction");
	int dead	= getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		if(mp >= limit){
			int Tx = getentityproperty(target, "x");
			int Ty = getentityproperty(target, "y");
			int Dx = Tx - x;
			int Dy = Ty - y;

			if(Dx >= xMin && Dx <= xMax && Dy >= yMin && Dy <= yMax && dir == 1){
				mpCost(limit);
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && Dy >= yMin && Dy <= yMax && dir == 0){
				mpCost(limit);
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHp(int xMin, int xMax, int yMin, int yMax, int hpPercent, void ani)
{
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	float maxHp = getentityproperty(self,"maxhealth");
	float hp 	= getentityproperty(self,"health");
	int dir 	= getentityproperty(self, "direction");
	int dead	= getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		if(hp > maxHp*hpPercent/100){
			int Tx = getentityproperty(target, "x");
			int Ty = getentityproperty(target, "y");
			int Dx = Tx - x;
			int Dy = Ty - y;

			if(Dx >= xMin && Dx <= xMax && Dy >= yMin && Dy <= yMax && dir == 1){
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && Dy >= yMin && Dy <= yMax && dir == 0){
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelRandom(int xMin, int xMax, int yMin, int yMax, int limit, void ani)
{//Random attack interruption with range and MP check
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int mp 		= getentityproperty(self, "mp");
	int dir 	= getentityproperty(self, "direction");
	int dead	= getentityproperty(self, "dead");
	float iR 	= rand()%50+50;

	if(target != NULL() && dead == 0){
		int Tx = getentityproperty(target, "x");
		int Ty = getentityproperty(target, "y");
		int Dx = Tx - x;
		int Dy = Ty - y;

		if(iR >= 0 && iR < 50 && mp >= limit){
			if(Dx >= xMin && Dx <= xMax && Dy >= yMin && Dy <= yMax && dir == 1){
				mpCost(limit);
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && Dy >= yMin && Dy <= yMax && dir == 0){
				mpCost(limit);
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHit(int xMin, int xMax, int yMin, int yMax, int limit, void ani)
{//Attack interruption with range, MP and Hit check (ENEMY RAGE CANCEL)
	void self 	 = getlocalvar("self");
	void target  = findtarget(self);
	int x 		 = getentityproperty(self, "x");
	int y 		 = getentityproperty(self, "y");
	int mp		 = getentityproperty(self, "mp");
	int dir 	 = getentityproperty(self, "direction");
	int hit		 = getentityproperty(self, "animhits");
	int dead	 = getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		int Tx = getentityproperty(target, "x");
		int Ty = getentityproperty(target, "y");
		int Dx = Tx - x;
		int Dy = Ty - y;

		if(hit >= 1 && mp >= limit){
			if(Dx >= xMin && Dx <= xMax && Dy >= yMin && Dy <= yMax && dir == 1){
				mpCost(limit);
				changeentityproperty(self, "velocity", 0, 0, 0);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant(ani), 1);

			}
			else
			if(Dx >= -xMax && Dx <= -xMin && Dy >= yMin && Dy <= yMax && dir == 0){
				mpCost(limit);
				changeentityproperty(self, "velocity", 0, 0, 0);
				setglobalvar("rageCancel"+self, openborvariant("elapsed_time"));
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHeight(int xMin, int xMax, int height, void ani)
{//Attack interruption with range and height check (USED FOR JUMP ATTACKS)
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int base	= getentityproperty(self, "base");
	int dir 	= getentityproperty(self, "direction");
	int dead	= getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		if(y - base > height){
			int Tx = getentityproperty(target, "x");
			int Dx = Tx - x;

			if(Dx >= xMin && Dx <= xMax && dir == 1){
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && dir == 0){
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHeightHit(int xMin, int xMax, int height, void ani)
{//Attack interruption with range and height check (USED FOR JUMP ATTACKS)
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int base	= getentityproperty(self, "base");
	int dir 	= getentityproperty(self, "direction");
	int hit		 = getentityproperty(self, "animhits");
	int dead	= getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		if(hit >= 1 && y - base > height){
			int Tx = getentityproperty(target, "x");
			int Dx = Tx - x;

			if(Dx >= xMin && Dx <= xMax && dir == 1){
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && dir == 0){
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHeightMp(int xMin, int xMax, int height, void ani, int cost)
{//Attack interruption with range and height check (USED FOR JUMP ATTACKS)
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int base	= getentityproperty(self, "base");
	int dir 	= getentityproperty(self, "direction");
	int mp		 = getentityproperty(self, "mp");
	int hit		 = getentityproperty(self, "animhits");
	int dead	= getentityproperty(self, "dead");

	if(target != NULL() && dead == 0){
		if(hit >= 1 && mp > cost && y - base > height){
			int Tx = getentityproperty(target, "x");
			int Dx = Tx - x;

			if(Dx >= xMin && Dx <= xMax && dir == 1){
				mpCost(cost);
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && dir == 0){
				mpCost(cost);
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelHeightRnd(int xMin, int xMax, int height, void ani, int cost)
{//Attack interruption with range and height check (USED FOR JUMP ATTACKS)
	void self 	= getlocalvar("self");
	void target = findtarget(self);
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int base	= getentityproperty(self, "base");
	int dir 	= getentityproperty(self, "direction");
	int mp		 = getentityproperty(self, "mp");
	int hit		 = getentityproperty(self, "animhits");
	int dead	= getentityproperty(self, "dead");
	int random = rnd(100);

	if(target != NULL() && dead == 0 && random <= 50){
		if(hit >= 1 && mp > cost && y - base > height){
			int Tx = getentityproperty(target, "x");
			int Dx = Tx - x;

			if(Dx >= xMin && Dx <= xMax && dir == 1){
				mpCost(cost);
				performattack(self, openborconstant(ani), 1);
			}
			else
			if(Dx >= -xMax && Dx <= -xMin && dir == 0){
				mpCost(cost);
				performattack(self, openborconstant(ani), 1);
			}
		}
	}
}

void cancelBack(void ani)
{//Cancel special moves with back attack if grabbed from back (ENEMIES ONLY, MCBRIDE/BEAR "BACK" ATTACKS)
	void self 	= getlocalvar("self");
	void target = getentityproperty(self,"opponent");
	int dir 	= getentityproperty(self,"direction");
	int x		= getentityproperty(self,"x");
	int Tx		= getentityproperty(target,"x");

	//FACING LEFT?
	if(dir == 0){x = -x;Tx = -Tx;}

	//GRABBED FROM BACK?
	if(x > Tx){performattack(self, openborconstant(ani), 1);}
}

void cancelFall(float chance, void ani)
{//Cancel throw or slam fall RANDOMLY with defined animation (ENEMIES/JET FALL)
	void self  = getlocalvar("self");
	int health = getentityproperty(self,"health");
	float iR   = rand()%50+50;

	if(health >= 1){
		if(iR >= 0 && iR <= chance){executeanimation(self, openborconstant(ani), 1);}
	}
}

void cancelVault(void ani)
{//Prevent enemy/npc from execute any grabattack after perform "vault front to back" with no grabbed opponent
 //Used if another entity hit the grabbed entity during vault animation
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");

	if(target == NULL()){
		changeentityproperty(self, "takeaction", "common_grabattack");
		setidle(self);
	}else{
		performattack(self, openborconstant(ani), 1);
	}
}

void rageCancel(int xMin, int xMax, int yMin, int yMax, int limit, void ani, void type)
{//Cancel defined moves with Rage Attacks
 //Similar to the "key.c" version used by the PLAYERS, but this one is used on NPC/ENEMY animations
	if(type == "hit"){cancelHit(xMin, xMax, yMin, yMax, limit, ani);}
	if(type == "mp"){cancelMp(xMin, xMax, yMin, yMax, limit, ani);}
	if(type == "random"){cancelRandom(xMin, xMax, yMin, yMax, limit, ani);}
}

void mpCost(int cost)
{//Spend some MP
	void self = getlocalvar("self");
	int mp 	  = getentityproperty(self,"mp");

	changeentityproperty(self, "mp", mp-cost);
}


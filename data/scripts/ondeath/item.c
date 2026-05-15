#import "data/scripts/main.c"

void main()
{//Spawns random item next to caller and toss it (RANDOM ITEM DROP FROM OBSTACLES)
	void self 	  = getlocalvar("self");
	void dName 	  = getentityproperty(self,"defaultname");
	void drop	  = getglobalvar("itemDrop");
	void vName;
	void vFood;
	void vMoney;
	void vWeapon;
	void vSpawn;
	int set		  = openborvariant("current_set");
	int dir 	  = getentityproperty(self,"direction");
	float fX 	  = getentityproperty(self, "x");
	float fY 	  = getentityproperty(self, "y");
	float fZ 	  = getentityproperty(self, "z");
	float Vx 	  = 0;
	float Vy 	  = 1;
	float Vz 	  = 0;
	float foodR	  = rnd(100);
	float moneyR  = rnd(100);
	float weaponR = rnd(100);
	float iR 	  = rnd(100);

	if(set == 0 || set == 2){ //ARCADE - REBELLION

		//WHAT FOOD IS SELECTED??
		if(foodR >= 0 && foodR < 80){
			vFood = "Apple";
		}
		else
		if(foodR >= 80 && foodR <= 100){
			vFood = "Chicken";
		}

		//WHAT MONEY IS SELECTED??
		if(moneyR >= 0 && moneyR < 80){
			vMoney = "Cash";
		}
		else
		if(moneyR >= 80 && moneyR <= 100){
			vMoney = "Gold";
		}

		//WHAT WEAPON IS SELECTED??
		if(weaponR >= 0 && weaponR < 10){
			vWeapon = "Knife";
		}
		else
		if(weaponR >= 10 && weaponR < 35){
			vWeapon = "Kunai";
		}
		else
		if(weaponR >= 35 && weaponR < 65){
			vWeapon = "Pipe";
		}
		else
		if(weaponR >= 65 && weaponR <= 100){
			vWeapon = "Sword";
		}

		//CALCULATE CHANCE ACCORDING TO SELECTED OPTION IN EXTRA MENU
		if(drop == "mixed"){
			if(iR >= 0 && iR < 60){
				vName = vFood;
			}
			else
			if(iR >= 60 && iR < 85){
				vName = vMoney;
			}
			else
			if(iR >= 85 && iR <= 99){
				vName = vWeapon;
			}
			else
			if(iR > 99 && iR <= 100){
				vName = "1up";
			}
		}
		else
		if(drop == "food_only"){
			vName = vFood;
		}
		else
		if(drop == "money_only"){
			vName = vMoney;
		}
		else
		if(drop == "weapon_only"){
			vName = vWeapon;
		}
		else
		if(drop == "food+money"){
			if(iR >= 0 && iR < 75){
				vName = vFood;
			}
			else
			if(iR >= 75 && iR <= 100){
				vName = vMoney;
			}
		}
		else
		if(drop == "food+weapon"){
			if(iR >= 0 && iR < 75){
				vName = vFood;
			}
			else
			if(iR >= 75 && iR <= 100){
				vName = vWeapon;
			}
		}
		else
		if(drop == "money+weapon"){
			if(iR >= 0 && iR < 50){
				vName = vMoney;
			}
			else
			if(iR >= 50 && iR <= 100){
				vName = vWeapon;
			}
		}
		else
		if(drop == "none"){
			vName = "None";
		}
	}

	if(set == 1){ //SURVIVAL
		if(iR >= 0 && iR < 60){
			vName = "Apple";
		}
		else
		if(iR >= 60 && iR <= 100){
			vName = "Chicken";
		}
	}

	if(dName == "Menu"){Vx = -1;Vy = 2;}

	clearspawnentry();
	setspawnentry("name", vName);

	vSpawn = spawn();

	changeentityproperty(vSpawn, "position", fX, fZ, fY);
	changeentityproperty(vSpawn, "direction", dir);
	tossentity(vSpawn, Vy, Vx, Vz);

	return vSpawn;
}
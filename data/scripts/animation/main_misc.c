#import "data/scripts/animation/main_grabs.c"

void savePos()
{//Get last position and save into a global variable (SOR3 ST6A ELEVATOR)
	void self = getlocalvar("self");
	float x	  = getentityproperty(self, "x");
	float y	  = getentityproperty(self, "y");
	float z	  = getentityproperty(self, "z");

	setglobalvar("lastXpos", x);
	setglobalvar("lastYpos", y);
	setglobalvar("lastZpos", z);
}

void setVar(void variable, float value)
{//Set generic global variable for further use (NUMERIC ONLY)

	setglobalvar(variable, value);
}

void healStart()
{//Set flag to start player health restoration, used in SPECIAL/SPECIAL2/SPECIAL3 moves (SPECIAL COST "LIFE" ONLY)
	void self = getlocalvar("self");

	if(	getglobalvar("specialCost") == "sor4_recovery_(time)"||
		getglobalvar("specialCost") == "sor4_recovery_(hits)"||
		getglobalvar("specialCost") == "sor3_'ok'_bar"){
		setglobalvar("heal"+self, 1);
	}
}

void clearL()
{//Clears all local variables
	void self = getlocalvar("self");
	changeentityproperty(self, "aiflag", "invincible", 0);
  grabEnd();
	clearlocalvar();
}

void cleanup() {
	void self = getlocalvar("self");
	changeentityproperty(self, "aiflag", "invincible", 0);
  grabEnd();
}
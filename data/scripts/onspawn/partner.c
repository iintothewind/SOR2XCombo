#import "data/scripts/onspawn/main.c"
#import "data/scripts/attributes.h"

void main()
{
	void self = getlocalvar("self");
	void name = getentityproperty(self, "defaultname");

	if(name == "Axel_"){	applyAtt("Axel");}
	if(name == "Blaze_"){	applyAtt("Blaze");}
	if(name == "Max_"){		applyAtt("Max");}
	if(name == "Sammy_"){	applyAtt("Sammy");}
	if(name == "Adam_"){	applyAtt("Adam");}
	if(name == "Zan_"){		applyAtt("Zan");}
	if(name == "SOR2_Shiva"){		applyAtt("Shiva");}
	if(name == "SOR3_Shiva"){		applyAtt("Shiva_");}
	if(name == "SOR2_Electra"){		applyAtt("Electra_");}
	if(name == "Yamato_"){		applyAtt("Yamato");}
	if(name == "Bison_"){		applyAtt("Bison");}
	if(name == "Chunli_"){		applyAtt("Chunli");}
	if(name == "Kage_"){		applyAtt("Kage");}

	rageATK();
	juggles();
	specialCost();
	spawnStatus();
	applyAtt();
}

void spawnStatus()
{//Turns invincible status to "on", set global variable "partnerAlive" status to 1 and adjust other initial properties
	void self		= getlocalvar("self");
	float time		= openborvariant("elapsed_time");
	float duration	= 4;
	float mult		= 200;
	float end		= duration*mult;

	changeentityproperty(self, "aiflag", "invincible", 1);
	changeentityproperty(self, "invinctime", time+end);
	changeentityproperty(self, "blink", 2);
	changeentityproperty(self, "subject_to_screen", 1);
	setglobalvar("partnerAlive", 1);
}
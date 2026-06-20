#import "data/scripts/updateentity/main.c"

void main()
{
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	void type = getentityproperty(self, "type");
	void model 	= getentityproperty(self, "model");

	if(ani == openborconstant("ANI_FREESPECIAL")){
		if(type != openborconstant("TYPE_PLAYER") || type != openborconstant("TYPE_ENEMY")){afterImage("YamatoS", 1);}
	}

  if(model != "Yamato_Wait2" || model != "Yamato_Wait3") {
		if(ani == openborconstant("ANI_FREESPECIAL6")){
			afterImage("YamatoS", 1);
		}
	}

	if(ani == openborconstant("ANI_FREESPECIAL7")||
	   ani == openborconstant("ANI_GRABATTACK") ||
	   ani == openborconstant("ANI_GRABFORWARD") ||
	   ani == openborconstant("ANI_GRABBACKWARD") ||
	   ani == openborconstant("ANI_FOLLOW7") ||
	   ani == openborconstant("ANI_DODGE")||
	   ani == openborconstant("ANI_FOLLOW1")){
	   afterImage("YamatoS", 1);
	}

	if(ani == openborconstant("ANI_SPAWN")||
	   ani == openborconstant("ANI_FREESPECIAL3")||
	   ani == openborconstant("ANI_FREESPECIAL4")){
	   afterImage("YamatoS", 0);
	}

	if(getglobalvar("graphicEffects") == "sor2x"){
		if( ani == openborconstant("ANI_FOLLOW10")){
			afterImage("YamatoS", 0);
		}
	}
}
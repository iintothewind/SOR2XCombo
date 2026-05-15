#import "data/scripts/updateentity/main.c"

void main()
{
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	stealthCamo();
	lockMp();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	void type = getentityproperty(self, "type");
	int alpha = getentityproperty(self, "alpha");

	if(ani == openborconstant("ANI_FREESPECIAL")){afterImage("TrackerS", 1);}

	if(getglobalvar("graphicEffects") == "sor2x"){
		if(ani == openborconstant("ANI_RISEATTACK")|| ani == openborconstant("ANI_FOLLOW7") || ani == openborconstant("ANI_FOLLOW10")||ani == openborconstant("ANI_DODGE")){
			if(type == openborconstant("TYPE_PLAYER")){
				if(alpha != 6){afterImage("TrackerS", 0);}
			}
			if(type == openborconstant("TYPE_ENEMY")){afterImage("TrackerS", 1);}
		}
	}
}

void stealthCamo()
{//Reduces mp when the "Stealth Camouflage" is activated (PLAYERS ONLY)
	void self  = getlocalvar("self");
	void type  = getentityproperty(self, "type");
	void ani   = getentityproperty(self, "animationID");
	int mp 	   = getentityproperty(self, "mp");
	int alpha  = getentityproperty(self, "alpha");
	int mode   = 6;
	int reduce = 1;
	int limit  = 0;
	float rate = 300;
	float time = openborvariant("elapsed_time");

	if(time%rate == 0){
		if(type == openborconstant("TYPE_PLAYER")){
			if(alpha == mode){
				if(mp > limit){
					changeentityproperty(self, "mp", mp-reduce);
				}else{
					if(ani == openborconstant("ANI_IDLE") || ani == openborconstant("ANI_WALK") || ani == openborconstant("ANI_RUN")){
						performattack(self, openborconstant("ANI_FREESPECIAL3"), 1);
					}
				}
			}
		}
	}
}

void lockMp()
{//Used to lock "mprate" of the Tracker character during the "stealth"
	void self = getlocalvar("self");
	void name = getentityproperty(self, "defaultname");
	void type = getentityproperty(self, "type");
	float mp  = getentityproperty(self, "mprate");
	float en  = getglobalvar(name+"Energy");

	if(type == openborconstant("TYPE_PLAYER")){
		if(getglobalvar("lockMp"+self) != NULL()){
			if(mp != 0){changeentityproperty(self, "mpset", NULL(), NULL(), NULL(), 0, NULL(), NULL());}
		}
		else
		{
			if(mp != en){changeentityproperty(self, "mpset", NULL(), NULL(), NULL(), en, NULL(), NULL());}
		}
	}
}
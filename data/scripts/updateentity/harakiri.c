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

	if(ani == openborconstant("ANI_DODGE")
	|| ani == openborconstant("ANI_FREESPECIAL")
	|| ani == openborconstant("ANI_FREESPECIAL4")
	|| ani == openborconstant("ANI_FREESPECIAL5")
	|| ani == openborconstant("ANI_FOLLOW1")
	|| ani == openborconstant("ANI_FOLLOW7")){
		afterImage("HarakiriS", 1);
	}

	if(ani == openborconstant("ANI_RUNATTACK")){
		if(type == openborconstant("TYPE_PLAYER")){afterImage("HarakiriS", 0, "legacy");}
	}

	if(ani == openborconstant("ANI_ATTACK3")){
		if(type == openborconstant("TYPE_ENEMY")){afterImage("HarakiriS", 0, "legacy");}
	}

	if(getglobalvar("graphicEffects") == "sor2x"){
		if(ani == openborconstant("ANI_WALK")
		|| ani == openborconstant("ANI_RUN")){
			afterImage("HarakiriS", 0);
		}
	}
}
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

	if(ani == openborconstant("ANI_FREESPECIAL")||ani == openborconstant("ANI_FREESPECIAL2")){
		afterImage("MonalisaS", 1);
	}

	if(getglobalvar("graphicEffects") == "sor2x"){
		if(ani == openborconstant("ANI_SPECIAL")){if(type == openborconstant("TYPE_PLAYER")){afterImage("MonalisaS", 0);}}
		if(ani == openborconstant("ANI_SPECIAL2")){if(type == openborconstant("TYPE_PLAYER")){afterImage("MonalisaS", 0);}}
		if(ani == openborconstant("ANI_DODGE")){if(type == openborconstant("TYPE_ENEMY")){afterImage("MonalisaS", 0);}}
	}
}
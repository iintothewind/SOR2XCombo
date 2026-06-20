#import "data/scripts/updateentity/main.c"

void main()
{
	airGrabCheck2();
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	energyRecover();
	dojoEnergyRecover();
	adjustLives();
	freeGrabbed();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self = getlocalvar("self");
	void vModel	= getentityproperty(self,"model");
	void ani  = getentityproperty(self, "animationID");
	void type = getentityproperty(self, "type");

	if(ani == openborconstant("ANI_FREESPECIAL")
	|| ani == openborconstant("ANI_ATTACKBOTH")
	|| ani == openborconstant("ANI_RISEATTACK")
	|| ani == openborconstant("ANI_RUNATTACK")
	|| ani == openborconstant("ANI_FOLLOW3")
	|| ani == openborconstant("ANI_FOLLOW7")
	|| ani == openborconstant("ANI_FOLLOW10")){
		afterImage("Shiva_BotS", 1);
	}

	if(vModel != "Shiva_"){
		if(ani == openborconstant("ANI_DODGE")
	  || ani == openborconstant("ANI_FREESPECIAL2")
	  || ani == openborconstant("ANI_FREESPECIAL4")
	  || ani == openborconstant("ANI_FREESPECIAL5")
		|| ani == openborconstant("ANI_FOLLOW2")){
			afterImage("Shiva_BotS", 1);
		}
	}

	if(vModel == "Shiva_Bot_Double") {
		if(ani == openborconstant("ANI_ATTACK9")){
			afterImage("Shiva_BotS", 1);
		}
	}
}
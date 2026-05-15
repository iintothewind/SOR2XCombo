#import "data/scripts/main.c"
#import "data/scripts/updateentity/main.c"

void main()
{
	afterEffect();
	blinkEffect();
	otg();
	versusDamage();
	runMove();
	auraEffect();
	freeGrabbed();
	rooEffect();
}

void afterEffect()
{//Check defined conditions before use "after image" effect
	void self  = getlocalvar("self");
	void ani   = getentityproperty(self, "animationID");

	if(getglobalvar("graphicEffects") == "sor2x"){
		if(ani == openborconstant("ANI_FOLLOW10") || ani == openborconstant("ANI_DODGE")){
			afterImage("BruceS", 0);
		}
	}
}

void rooEffect() {
	if(findEnemy("Roo") != NULL() && getlocalvar("bruceHpDoubled") == NULL()) {
		void self 	= getlocalvar("self");
		void model 	= getentityproperty(self, "model");
		int hp	 = getentityproperty(self,"health");
		int maxHp	= getentityproperty(self, "maxhealth");
		void difficult	= getglobalvar("difficult");
		int rate = 1;
		int modelRate = model == "Tamer" ? 1 : 2;
		if(difficult == "mania"){
			rate = 3*modelRate;
		} else if(difficult == "hard"){
			rate = 2*modelRate;
		}  else {
			rate = 1*modelRate;
		}

		changeentityproperty(self, "maxhealth", maxHp*rate);
		changeentityproperty(self, "health", maxHp*rate);
		setlocalvar("bruceHpDoubled", 1);
	}
}

void auraEffectRoo()
{
	void self 	= getlocalvar("self");
	void ani 	= getentityproperty(self, "animationID");
	void model 	= getentityproperty(self, "model");
	void pikachu	= getentityvar(self, "Pikachu");

	if(model == "Tamer" && pikachu != NULL()) {
		int dead	= getentityproperty(pikachu, "dead");
		int pikaHp	 = getentityproperty(pikachu,"health");
		int pikaMaxHp	= getentityproperty(pikachu, "maxhealth");
		int pikaHpRecover	= pikaMaxHp/5;
		int pikaMp 		= getentityproperty(pikachu,"mp");
		int pikaMaxMp 	= getentityproperty(pikachu,"maxmp");
		int pikaMpRecover = pikaMaxMp/5;

		if(dead == 0) {
			float time = openborvariant("elapsed_time");
			float mult = 100;
			float duration=0.5;
			float end  = duration*mult;

			if(ani == openborconstant("ANI_FREESPECIAL")) {
				setglobalvar("auraEffect"+pikachu, time+end-50);
				changeentityproperty(pikachu, "health", pikaMaxHp);
				changeentityproperty(pikachu, "mp", pikaMaxMp);
			}
			if(ani == openborconstant("ANI_FREESPECIAL2")) {
				setglobalvar("auraEffect"+pikachu, time+end-50);
				changeentityproperty(pikachu, "health", pikaHp+pikaHpRecover);
				changeentityproperty(pikachu, "mp", pikaMp+pikaMpRecover);
			}
		}
	}
}
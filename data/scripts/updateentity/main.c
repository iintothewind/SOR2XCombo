#import "data/scripts/main.c"
#import "data/scripts/animation/main_spawns.c"

void afterImage(void shadowEntity, int effectType, int rateFlag)
{//Make "shadow trails" effect for ANY animation (AFTER IMAGE EFFECT)
 //Effect type "0": Alpha 6, NO COLOR change (USED FOR SIMPLE MOVES)
 //Effect type "1": Alpha 6, RED COLOR change (USED FOR RAGE MOVES)
	void self 	 = getlocalvar("self");

	if(!selfAlive()){return;}

	void effects = getglobalvar("graphicEffects");
	void name	 = getentityproperty(self, "defaultname");
	void height	 = getentityproperty(self, "y");
	int yLimit	 = -20;

	if(effects == "sor2x"){
		float time	= openborvariant("elapsed_time");
		float rate 	= 20;

		if(time%rate == 0 && height >= yLimit){
			void vSpawn = spawn01(shadowEntity, 0, 0, -1);
			void vAniID = getentityproperty(self, "animationID");
			int map		= getentityproperty(self, "map");
			int frame	= getentityproperty(self, "animpos");
			float cycle	= getglobalvar("cycle"+self);

			setglobalvar("effectType"+vSpawn, effectType); //SAVE EFFECT TYPE FOR FURTHER USE IN CHANNEL ONDRAW SCRIPT IN EACH SHADOW
			changeentityproperty(vSpawn, "map", map);
			changeentityproperty(vSpawn, "animation", openborconstant(vAniID));
			changeentityproperty(vSpawn, "subject_to_hole", 1);
			changeentityproperty(vSpawn, "no_adjust_base", 0);
			updateframe(vSpawn, frame);

			if(cycle != NULL()){
				changedrawmethod(vSpawn, "enabled", 1);
				changedrawmethod(vSpawn, "rotate", cycle);
			}
		}
	}

	if(effects == "original" && height >= yLimit){
		float time = openborvariant("elapsed_time");
		float rate = 20;

		if(rateFlag == "legacy"){rate = 8;}

		if(time%rate == 0){
			void vSpawn = spawn01(shadowEntity, 0, 0, -1);
			void vAniID = getentityproperty(self, "animationID");
			int map		= getentityproperty(self, "map");
			int frame	= getentityproperty(self, "animpos");

			setglobalvar("effectType"+vSpawn, effectType); //SAVE EFFECT TYPE FOR FURTHER USE IN CHANNEL ONDRAW SCRIPT IN EACH SHADOW
			setglobalvar("legacy"+vSpawn, rateFlag);
			changeentityproperty(vSpawn, "map", map);
			changeentityproperty(vSpawn, "animation", openborconstant(vAniID));
			changeentityproperty(vSpawn, "subject_to_hole", 1);
			changeentityproperty(vSpawn, "no_adjust_base", 0);
			updateframe(vSpawn, frame);
		}
	}
}

void blinkEffect()
{//Turn on/off generic blink effects according to global variables, works with any feature

	if(openborvariant("in_selectscreen")){	blinkSelect();}
	if(openborvariant("in_level")){			blinkDamage();}
	if(openborvariant("in_level")){			blinkCancel();}
	if(openborvariant("in_level")){			blinkCharge();}
}


void disableBlink(void target) {
	if(target != NULL()) {
		void targetName		= getentityproperty(target, "defaultname");
		void type  	= getentityproperty(target,"type");
		void ani  = getentityproperty(target,"animationID");
		void grabbed = getentityvar(target,"grabbed");
		void grabbing = getentityvar(target,"grabbing");
		float height = getentityproperty(target,"y");
		float base = getentityproperty(target,"base");
		int fall	= getentityproperty(target,"aiflag","falling");

		if(strinfirst(targetName, "Garnet") != -1
		|| strinfirst(targetName, "Mona") != -1
		|| strinfirst(targetName, "Lisa") != -1
		|| strinfirst(targetName, "Electra") != -1
		|| strinfirst(targetName, "Reine") != -1
		|| height != base
		|| fall == 1
		|| !entityAlive(target)
		|| ani == openborconstant("ANI_GRAB")
		|| ani == openborconstant("ANI_GRABBED")
		|| ani == openborconstant("ANI_GRABATTACK")
		|| ani == openborconstant("ANI_GRABATTACK2")
		|| ani == openborconstant("ANI_GRABUP")
		|| ani == openborconstant("ANI_GRABUP2")
		|| ani == openborconstant("ANI_GRABDOWN")
		|| ani == openborconstant("ANI_GRABDOWN2")
		|| ani == openborconstant("ANI_GRABFORWARD")
		|| ani == openborconstant("ANI_GRABFORWARD2")
		|| ani == openborconstant("ANI_GRABBACKWARD")
		|| ani == openborconstant("ANI_GRABBACKWARD2")
		|| grabbed  != NULL()
		|| grabbing  != NULL()) {
				return 1;
		}
	}
	return 0;
}

void blinkSelect()
{//Turn on/off generic blink effects during the "select" animation

	void self 		= getlocalvar("self");
	void animation	= getentityproperty(self, "animationID");
	int frame		= getentityproperty(self, "animpos");

	//SELECT SCREEN
	if(animation == openborconstant("ANI_PICK")){ //SELECT ANIMATION
		int tintMode	= 1;
		float time		= openborvariant("elapsed_time");
		float rate		= 22;

		//APPLY BLINK EFFECTS
		if(frame == 1){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(time*rate, time*rate, time*rate));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset();}
		}
	}

	//CAUTION!!! THE LINES BELOW ARE VERY IMPORTANT BECAUSE IS THE ONLY WAY TO GET ALL PREVIEW MODELS SPAWNED BY THE ENGINE IN THE SELECT SCREEN!
	//THIS CODE WILL SAVE THE DEFAULT PREVIEW MODELS IN A VARIABLE AND ALLOWS TO EDIT SOME PROPERTIES
	//THE ONLY WAY TO DEFINE EVERY INDEX IS BY GETTING THE X POSITION AT THE SELECT SCREEN, PLEASE CHECK EACH POSITION IN THE LEVELS.TXT FILE
	//NEED TO REMEMBER THAT THE ENTITES IN THE SELECT SCREEN WILL NOT ALLOW YOU TO GET SOME PROPERTIES BY REGULAR METHODS, LIKE "PLAYERINDEX"

	void type = getentityproperty(self, "type");
	int xPos  = getentityproperty(self, "x");
	int index;

	if(xPos == 100){index = 0;}else
	if(xPos == 200){index = 1;}else
	if(xPos == 300){index = 2;}else
	if(xPos == 400){index = 3;}

	if(type != openborconstant("TYPE_NPC")){setglobalvar("defaultEntity"+index, self);}
}

void blinkDamage()
{//Turn on/off generic blink effects during some "takedamage" events
	void self		= getlocalvar("self");

	if(!selfAlive()){return;}

	void spawn;
	void animation	= getentityproperty(self, "animationID");
	int frame		= getentityproperty(self, "animpos");
	int tintMode;
	float time;
	float duration;
	float rate;

	void selfName		= getentityproperty(self, "defaultname");

	if(animation == openborconstant("ANI_BURN")){ //BURN FALL

		//GET NEW VALUES
		time	 = openborvariant("elapsed_time");
		tintMode = 4;
		rate	 = 16;
		spawn	 = 20;

		//APPLY BLINK EFFECTS
		if(frame < 1){
			if(time%spawn == 0){spawnToss("Smoke", 0, 50, 1, 0, 1, 0);}
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(time*rate, 0x10, 0x00));
		}
		else
		{
			if(	getglobalvar("armorResist"+self) 	== NULL()&&
				getglobalvar("runCancel"+self) 		== NULL()&&
				getglobalvar("specialCancel"+self)	== NULL()&&
				getglobalvar("rageCancel"+self)		== NULL()){

				if(getdrawmethod(self, "enabled") == 1){blinkReset();}
			}
		}
	}
	else
	if(animation == openborconstant("ANI_SHOCK")){ //SHOCK FALL

		//GET NEW VALUES
		time	 = openborvariant("elapsed_time");
		tintMode = 4;
		duration = 99999;
		rate	 = 16;

		//APPLY BLINK EFFECTS
		if(frame < 1){
			if(getlocalvar("shock") == NULL()){setlocalvar("shock", time);}

			if(time - getlocalvar("shock") > rate*2){
				spawnBind("Electrocute", 10, 40, 1);
				setlocalvar("shock", time+duration);
			}

			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(time*rate, time*rate, 0x00));
		}
		else
		{
			if(	getglobalvar("armorResist"+self) 	== NULL()&&
				getglobalvar("runCancel"+self) 		== NULL()&&
				getglobalvar("specialCancel"+self)	== NULL()&&
				getglobalvar("rageCancel"+self)		== NULL()){
				setlocalvar("shock", NULL());

				if(getdrawmethod(self, "enabled") == 1){blinkReset();}
			}
		}
	}
	else
	if(animation == openborconstant("ANI_GUARDBREAK")){ //GUARD BREAK

		//GET NEW VALUES
		time	 = openborvariant("elapsed_time");
		tintMode = 2;
		rate	 = 16;

		//APPLY BLINK EFFECTS
		if(frame < 15){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(time*rate, time*rate, time*rate));
		}
		else
		{
			if(	getglobalvar("armorResist"+self) 	== NULL()&&
				getglobalvar("runCancel"+self) 		== NULL()&&
				getglobalvar("specialCancel"+self)	== NULL()&&
				getglobalvar("rageCancel"+self)		== NULL()){

				if(getdrawmethod(self, "enabled") == 1){blinkReset();}
			}
		}
	}
	else
	if(animation == openborconstant("ANI_FOLLOW9")){ //AERIAL RECOVER

		//GET NEW VALUES
		tintMode = 1;
		rate	 = 16;

		//APPLY BLINK EFFECTS
		if(frame < 1){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0xFF, 0xFF, 0xFF));
		}
		else
		{
			if(	getglobalvar("armorResist"+self) 	== NULL()&&
				getglobalvar("runCancel"+self) 		== NULL()&&
				getglobalvar("specialCancel"+self)	== NULL()&&
				getglobalvar("rageCancel"+self)		== NULL()){

				if(getdrawmethod(self, "enabled") == 1){blinkReset();}
			}
		}
	}
	else //BLINK RESET
	if(animation != 25){ //IS NOT IN SELECT ANIMATION??
		if(	getglobalvar("armorResist"+self) 	== NULL()&&
			getglobalvar("runCancel"+self) 		== NULL()&&
			getglobalvar("specialCancel"+self)	== NULL()&&
			getglobalvar("rageCancel"+self)		== NULL()){

			if(getdrawmethod(self, "enabled") == 1){blinkReset();}
		}
	}

	//SUPER ARMOR
	if(getglobalvar("armorResist"+self) != NULL()){
		//GET NEW VALUES
		time	 = openborvariant("elapsed_time");
		tintMode = 1;
		duration = 20;
		rate	 = 24;
		//APPLY BLINK EFFECTS
		if(time-getglobalvar("armorResist"+self) < duration && !disableBlink(self)){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0x00, 0x00, time*rate));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset("armorResist"+self);}
		}
	}

  //AURA
	if(getglobalvar("auraEffect"+self) != NULL()){

		//GET NEW VALUES
		time	 = openborvariant("elapsed_time");
		tintMode = 1;
		duration = 20;
		rate	 = 24;

		//APPLY BLINK EFFECTS
		if(time-getglobalvar("auraEffect"+self) < duration && !disableBlink(self)){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0x00, time*rate, 0x00));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset("auraEffect"+self);}
		}
	}
}

void blinkCancel()
{//Turn on/off generic blink effects during "attack cancelation" events
	void self 		= getlocalvar("self");

	if(!selfAlive()){return;}

	void animation	= getentityproperty(self, "animationID");
	int tintMode	= 4;
	float duration	= 25;

	//RUNNING ATTACKS CANCEL
	if(getglobalvar("runCancel"+self) != NULL()){

		//APPLY BLINK EFFECTS
		if(openborvariant("elapsed_time")-getglobalvar("runCancel"+self) < duration){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0xFF, 0xFF, 0x00));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset("runCancel"+self);}
		}
	}

	//SPECIAL CANCEL
	if(getglobalvar("specialCancel"+self) != NULL()){

		//APPLY BLINK EFFECTS
		if(openborvariant("elapsed_time") - getglobalvar("specialCancel"+self) < duration){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0x00, 0x00, 0xFF));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset("specialCancel"+self);}
		}
	}

	//RAGE CANCEL
	if(getglobalvar("rageCancel"+self) != NULL()){

		//APPLY BLINK EFFECTS
		if(openborvariant("elapsed_time") - getglobalvar("rageCancel"+self) < duration){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", rgbcolor(0xFF, 0x00, 0x00));
		}else{
			if(getdrawmethod(self, "enabled") == 1){blinkReset("rageCancel"+self);}
		}
	}
}

void blinkCharge()
{//Turn on/off generic blink effects during "charge attack" events
	void self	= getlocalvar("self");

	if(!selfAlive()){return;}

	int pIndex	= getentityproperty(self, "playerindex");

	//CHARGE ATTACK
	if(getglobalvar("chargeStart"+pIndex) != NULL()){
		void type		= getentityproperty(self, "type");
		void animation	= getentityproperty(self, "animationID");
		int valid		= getentityproperty(self, "animvalid", openborconstant("ANI_ATTACK2"));
		int tintMode	= 1;
		int warning		= 15;
		float time		= openborvariant("elapsed_time");
		float duration	= 20;

		//APPLY BLINK EFFECTS
		if(type == openborconstant("TYPE_PLAYER")){
			if(time > getglobalvar("chargeStart"+pIndex)-warning){
				if(time-getglobalvar("chargeStart"+pIndex) < duration){
					if(selfAlive() && valid == 1){
						changedrawmethod(self, "enabled", 1);
						changedrawmethod(self, "tintmode", tintMode);
						changedrawmethod(self, "tintcolor", rgbcolor(0xBB, 0xBB, 0xBB));
					}
				}else{
					if(	animation != openborconstant("ANI_BURN")&&
						animation != openborconstant("ANI_SHOCK")&&
						animation != openborconstant("ANI_GUARDBREAK")&&
						animation != openborconstant("ANI_FOLLOW9")&&
						getglobalvar("armorResist"+self) 	== NULL()&&
						getglobalvar("runCancel"+self) 		== NULL()&&
						getglobalvar("specialCancel"+self)	== NULL()&&
						getglobalvar("rageCancel"+self)		== NULL()){

						if(getdrawmethod(self, "enabled") == 1){blinkReset();}
					}
				}
			}
		}
	}
}

void blinkReset(void varReset)
{//Reset any blink effect and all used variables
	void self = getlocalvar("self");

	if(varReset != NULL()){setglobalvar(varReset, NULL());}
	changedrawmethod(self, "enabled", 0); //GLOBAL RESET

	//USED ONLY FOR BREAK CHARACTER
	if(getentityvar(self, "speedLV") == 2){ //USED TO RESET "BREAK" CHARACTER TO PREVIOUS DRAWMETHOD "REDDISH" TONE
		changedrawmethod(self, "enabled", 1);
		changedrawmethod(self, "tintmode", 3);
		changedrawmethod(self, "tintcolor", rgbcolor(0xA0, 0x60, 0x60));
	}
	else
	if(getentityvar(self, "speedLV") == 3){ //USED TO RESET "BREAK" CHARACTER TO PREVIOUS DRAWMETHOD "REDDISH" TONE
		changedrawmethod(self, "enabled", 1);
		changedrawmethod(self, "tintmode", 3);
		changedrawmethod(self, "tintcolor", rgbcolor(0xC0, 0x60, 0x60));
	}
}

void suicideP(void ani, int frame)
{//Suicide if your caller is a Parent and have a specific animation
	void self	= getlocalvar("self");
	void target	= getentityproperty(self, "parent");
	void vAni	= getentityproperty(target, "animationID");
	int vFrame	= getentityproperty(target, "animpos");

	if(vAni == openborconstant(ani) && vFrame >= frame){killentity(self);}
}

void loadOtgLimit() {
	void otgSystem = getglobalvar("otgSystem");
	int otgLimit = 99;
	if(otgSystem != "unlimited") {
		if(otgSystem == "20") {
			otgLimit = 20;
		} else if(otgSystem == "15") {
			otgLimit = 15;
		} else if(otgSystem == "10") {
			otgLimit = 10;
		} else if(otgSystem == "8") {
			otgLimit = 8;
		} else if(otgSystem == "6") {
			otgLimit = 6;
		} else if(otgSystem == "4") {
			otgLimit = 4;
		} else if(otgSystem == "2") {
			otgLimit = 2;
		} else {
			otgLimit = 0;
		}
	}
	return otgLimit;
}

void otg()
{//Used to start variables and refill OTG points
	void otgLimit = loadOtgLimit();
	void self		= getlocalvar("self");

	if(!selfAlive()){return;}

	int otgPoints	= getentityvar(self, "otgpoints");

	if(otgPoints == NULL()) {
		setentityvar(self, "otgpoints", otgLimit);
	} else {
		int idling	= getentityproperty(self, "aiflag", "idling");
		int walking	= getentityproperty(self, "aiflag", "walking");
		int running	= getentityproperty(self, "aiflag", "running");
		int rising	= getentityproperty(self, "aiflag", "rising");

		if(idling || walking || running || rising){
			if(otgPoints < otgLimit){
				setentityvar(self, "otgpoints", otgLimit);
			}
		}
	}
}

void versusDamage()
{//Enable/Disable the Versus Damage with global variable check
	void self		= getlocalvar("self");

	if(!selfAlive()){return;}

	void versusDmg	= getglobalvar("versusDamage"); //Get Versus Damage option.
	void type		= getentityproperty(self, "type");
	int candamage	= getlocalvar("candamage"+self);


	if(versusDmg == "disabled" && candamage != 0){ //VERSUS DAMAGE IS DISABLED??
		if(type == openborconstant("TYPE_PLAYER")){
			changeentityproperty(self, "hostile", "type_enemy");
			changeentityproperty(self, "candamage", "type_enemy", "type_obstacle", "type_shot");
			setlocalvar("candamage"+self, 0);
		}

		if(type == openborconstant("TYPE_NPC")){
			changeentityproperty(self, "candamage", "type_enemy", "type_obstacle");
			setlocalvar("candamage"+self, 0);
		}
	}
	else
	if(versusDmg == "enabled" && candamage != 1){ //VERSUS DAMAGE IS ENABLED??
		if(type == openborconstant("TYPE_PLAYER")){
			changeentityproperty(self, "hostile", "type_enemy");
			changeentityproperty(self, "candamage", "type_player", "type_enemy", "type_npc", "type_obstacle", "type_shot");
			setlocalvar("candamage"+self, 1);
		}

		if(type == openborconstant("TYPE_NPC")){
			changeentityproperty(self, "candamage", "type_player", "type_enemy", "type_npc", "type_obstacle");
			setlocalvar("candamage"+self, 1);
		}
	}
}

void runMove()
{//Enable or disable "running" in Z axis
	void self = getlocalvar("self");

	if(!selfAlive()){return;}

	void type = getentityproperty(self, "type");
	int runZ  = getentityproperty(self, "running", "movez");
	int runMove;

	if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
		if(getglobalvar("runType") == "sor2x"){runMove = 1;}else{runMove = 0;}
		if(runZ != runMove){changeentityproperty(self, "running", NULL(), NULL(), NULL(), NULL(), runMove);}
	}
}

void onScreen()
{//Anti stuck off-screen, checks position on-screen
 //If entity is off-screen, will be moved with defined distance
 //Script for emergency re-adjust players position on-screen if stucked outside of the screen
	void self 		= getlocalvar("self");

	if(!selfAlive()){return;}

	void type 		= getentityproperty(self,"type");
	void vAnID 		= getentityproperty(self,"animationID");
	void subType	= getentityproperty(self,"subtype");
	int iPIndex 	= getlocalvar("player");
	int subScreen	= getentityproperty(self, "subject_to_screen");
	float hRes		= openborvariant("hresolution");
	float x 		= getentityproperty(self, "x");
	float xPos 		= openborvariant("xpos");
	float R 		= (xPos+hRes); // Right side of the screen
	float L 		= (xPos); //Left side of the screen

	if(vAnID == openborconstant("ANI_WALK") || vAnID == openborconstant("ANI_RUN") || vAnID == openborconstant("ANI_DODGE") || vAnID == openborconstant("ANI_ATTACK1")){
		if(type == openborconstant("TYPE_PLAYER")){
			if(playerkeys(iPIndex, 0, "moveleft") || playerkeys(iPIndex, 0, "moveright") || playerkeys(iPIndex, 0, "moveup") || playerkeys(iPIndex, 0, "movedown")){
				if(x > R){changeentityproperty(self, "position", R-20);}else
				if(x < L){changeentityproperty(self, "position", L+20);}
			}
		}

		if(type == openborconstant("TYPE_NPC") && subType == openborconstant("SUBTYPE_FOLLOW")){
			if(x > R){changeentityproperty(self, "position", R-20);}else
			if(x < L){changeentityproperty(self, "position", L+20);}
		}

		if(type == openborconstant("TYPE_ENEMY")){
			if(x > R){changeentityproperty(self, "position", R-20);}else
			if(x < L){changeentityproperty(self, "position", L+20);}
		}
	}
}

void screen(int flag)
{//Turns subject's to screen status
	void self = getlocalvar("self");

	changeentityproperty(self, "subject_to_screen", flag);
}

void loadEnergyRecoverRate() {
	void energyRateCfg = getglobalvar("energyRegenerate");
	int rate = 0;
	if(energyRateCfg != "never") {
		if(energyRateCfg == "50") {
			rate = 50;
		} else if(energyRateCfg == "25") {
			rate = 25;
		} else if(energyRateCfg == "20") {
			rate = 20;
		} else if(energyRateCfg == "15") {
			rate = 15;
		} else if(energyRateCfg == "10") {
			rate = 10;
		} else if(energyRateCfg == "5") {
			rate = 5;
		} else {
			rate = 0;
		}
	}
	return rate;
}

void energyRecover() {
	void self = getlocalvar("self");

	if(!selfAlive()){return;}

	void type = getentityproperty(self, "type");
	int maxMp 	= getentityproperty(self,"maxmp");
	int mp 		= getentityproperty(self,"mp");
	int set 	= openborvariant("current_set");
	int energyRate = loadEnergyRecoverRate();
	int playedSecond 	= getglobalvar("playedSecond");
  int playedTick = getlocalvar("playedTick");

	if(set == 0 && energyRate > 0 && playedSecond != playedTick) {
		if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
			changeentityproperty(self, "mp", mp+energyRate > maxMp? maxMp:mp+energyRate);
			setlocalvar("playedTick", playedSecond);
		}
	}
}

void dojoEnergyRecover() {
	void self = getlocalvar("self");

	if(!selfAlive()){return;}

	void type = getentityproperty(self, "type");
	int maxMp 	= getentityproperty(self,"maxmp");
	int mp 		= getentityproperty(self,"mp");
	int set 	= openborvariant("current_set");
	int dojoEnergyRate = getglobalvar("dojoEnergyRate");
	int playedSecond 	= getglobalvar("playedSecond");
  int playedTick = getlocalvar("playedTick");

	if(set == 3 && dojoEnergyRate > 0 && playedSecond != playedTick) {
		if(type == openborconstant("TYPE_PLAYER") || type == openborconstant("TYPE_NPC")){
			changeentityproperty(self, "mp", mp+dojoEnergyRate > maxMp ? maxMp:mp+dojoEnergyRate);
			setlocalvar("playedTick", playedSecond);
		}
	}
}

void adjustLives() {
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");

	if(openborvariant("current_set") == 0 && getglobalvar("lives")== 1){
		if(player1 != NULL()){changeplayerproperty(0, "lives", 1);changeplayerproperty(0, "credits", 0);}
		if(player2 != NULL()){changeplayerproperty(1, "lives", 1);changeplayerproperty(1, "credits", 0);}
		if(player3 != NULL()){changeplayerproperty(2, "lives", 1);changeplayerproperty(2, "credits", 0);}
		if(player4 != NULL()){changeplayerproperty(3, "lives", 1);changeplayerproperty(3, "credits", 0);}
	}
}

void freeGrabbed() {
	void self = getlocalvar("self");
	void sSubType	= getentityproperty(self,"subtype");
	void defaultName = getentityproperty(self, "defaultname");
	void type  	= getentityproperty(self,"type");
	void ani  = getentityproperty(self,"animationID");
	void grabbed = getentityvar(self,"grabbed");
	void grabbing = getentityproperty(self,"grabbing");
	float height = getentityproperty(self,"y");
	float base = getentityproperty(self,"base");
	int fall	= getentityproperty(self,"aiflag","falling");

	if(grabbed != NULL()
	&& (!entityAlive(self) || !entityAlive(grabbed))){
		grabRelease(self);
		return;
	}

	if((ani == openborconstant("ANI_IDLE")
	|| ani == openborconstant("ANI_WALK")
	|| ani == openborconstant("ANI_RUN")
	|| ani == openborconstant("ANI_BLOCK")
	|| ani == openborconstant("ANI_DODGE")
	|| ani == openborconstant("ANI_FOLLOW11")
	|| ani == openborconstant("ANI_RISE"))
	&& entityAlive(self)
	&& sSubType != openborconstant("SUBTYPE_NOTGRAB")
	&& grabbed != NULL()) {
		grabRelease(self);
	}
}

void auraEffect() {
	void self	= getlocalvar("self");
	void defaultName = getentityproperty(self, "defaultname");
	float mult = 100;
	int elapsedTime = openborvariant("elapsed_time");
	void levelBoss = findLevelBoss();
	void branch = openborvariant("current_branch");

	int playedSecond 	= getglobalvar("playedSecond");

  if(getlocalvar("playedTick") == NULL()) {
    setlocalvar("playedTick", playedSecond);
  }

  void playedTick = getlocalvar("playedTick");


	if(branch != "sor2_st8b"
			&& branch != "sor3_st6a"
			&& branch != "sor3_st6b"
			&& branch != "sor3_st6c"
			&& branch != "sor3_st6d"
			&& branch != "sor3_st6e"
			&& branch != "sor3_st6f"
			&& branch != "sor3_st6g"
			&& branch != "sor3_st8e") {
		if(entityAlive(self) && levelBoss == NULL()) {
			int entityCount	= openborvariant("count_entities");
			int entityIndex	= 0;
			void entity	= NULL();
			for(entityIndex=0; entityIndex < entityCount; entityIndex++) {
				entity = getentity(entityIndex);
				if(entity != NULL() && getentityproperty(entity, "exists") && getentityproperty(entity, "type") == openborconstant("TYPE_ENEMY")) {
					void enemy = entity;
					void model 	= getentityproperty(enemy, "model");
					void enemyName		= getentityproperty(entity, "defaultname");
					void animId  = getentityproperty(enemy,"animationID");
					void grabbedTarget = getentityvar(enemy,"grabbed");
					void grabbingTarget = getentityproperty(enemy, "grabbing");
					int height	 = getentityproperty(enemy,"y");
					int base	 = getentityproperty(enemy,"base");
					int fall	= getentityproperty(enemy,"aiflag","falling");
					int enemyHp	 = getentityproperty(enemy,"health");
					int enemyMaxHp	= getentityproperty(enemy, "maxhealth");
					int enemyHpRecover	= enemyMaxHp/10;
					int enemyMp 		= getentityproperty(enemy,"mp");
					int enemyMaxMp 	= getentityproperty(enemy,"maxmp");
					int enemyMpRecover = enemyMaxMp/10;

					if((strinfirst(enemyName, "Roo") != -1 || strinfirst(model, "Roo") != -1)
					&& entityAlive(enemy) && fall == 0 && height == base && enemyHp <= (enemyMaxHp/3*2)) {
						if(animId != openborconstant("ANI_FALL")
						&& animId != openborconstant("ANI_BURN")
						&& animId != openborconstant("ANI_SHOCK")
						&& animId != openborconstant("ANI_FALL6")
						&& animId != openborconstant("ANI_FALL7")
						&& animId != openborconstant("ANI_FALL8")
						&& animId != openborconstant("ANI_FALL9")
						&& animId != openborconstant("ANI_WALKOFF")
						&& animId != openborconstant("ANI_LAND")
						&& animId != openborconstant("ANI_JUMPLAND")
						&& animId != openborconstant("ANI_JUMPDELAY")
						&& grabbedTarget == NULL()
						&& grabbingTarget == NULL()) {
							changeentityproperty(enemy, "health", enemyMaxHp);
							changeentityproperty(enemy, "mp", enemyMaxMp);
						}
					} else if(strinfirst(defaultName, "Tamer") != -1 && strinfirst(enemyName, "Tamer") == -1
					&& entityAlive(enemy) && fall == 0 && height == base && enemyHp <= (enemyMaxHp/5*4) && playedSecond != playedTick) {
						if(animId != openborconstant("ANI_FALL")
						&& animId != openborconstant("ANI_BURN")
						&& animId != openborconstant("ANI_SHOCK")
						&& animId != openborconstant("ANI_FALL6")
						&& animId != openborconstant("ANI_FALL7")
						&& animId != openborconstant("ANI_FALL8")
						&& animId != openborconstant("ANI_FALL9")
						&& animId != openborconstant("ANI_WALKOFF")
						&& animId != openborconstant("ANI_LAND")
						&& animId != openborconstant("ANI_JUMPLAND")
						&& animId != openborconstant("ANI_JUMPDELAY")
						&& grabbedTarget == NULL()
						&& grabbingTarget == NULL()) {
							changeentityproperty(enemy, "health", enemyHp+(enemyMaxHp/10));
							changeentityproperty(enemy, "mp", enemyMp+(enemyMaxMp/10));
						}
					}
				}
			}
		}
	}
}

void airGrabCheck2() {
	void self 	 = getlocalvar("self");

	if(!selfAlive()){return;}

	void type		= getentityproperty(self,"type");
	int height	 = getentityproperty(self,"y");
	int base	 = getentityproperty(self,"base");
	int iPIndex  = getlocalvar("player");
	void vAniID  = getentityproperty(self,"animationID");
	void model	= getentityproperty(self,"model");
	int mp		 = getentityproperty(self,"mp");
	int frame	= getentityproperty(self,"animpos");
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int jgCost = 5;

	if(type == openborconstant("TYPE_PLAYER")){
		if(vAniID == openborconstant("ANI_JUMPATTACK2") && height > base && mp < jgCost && hits == 0){
			executeanimation(self, openborconstant("ANI_LAND"), 1);
			changeentityproperty(self, "aiflag", "falling", 1);
		}
	}
}


void airGrabCheck3() {
	void self 	 = getlocalvar("self");

	if(!selfAlive()){return;}

	void type		= getentityproperty(self,"type");
	int height	 = getentityproperty(self,"y");
	int base	 = getentityproperty(self,"base");
	int iPIndex  = getlocalvar("player");
	void vAniID  = getentityproperty(self,"animationID");
	void model	= getentityproperty(self,"model");
	int mp		 = getentityproperty(self,"mp");
	int frame	= getentityproperty(self,"animpos");
	int rush	 = getentityproperty(self,"rush_count");
	int hits	 = getentityproperty(self,"animhits");
	int jgCost = 5;

	if(type == openborconstant("TYPE_PLAYER")){
		if(vAniID == openborconstant("ANI_JUMPATTACK3") && height > base && mp < jgCost && hits == 0){
			executeanimation(self, openborconstant("ANI_LAND"), 1);
			changeentityproperty(self, "aiflag", "falling", 1);
		}
	}
}

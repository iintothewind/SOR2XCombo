//SOR2X SAMPLE CONSTANTS
#define SAMPLE_BEEP3 		loadsample("data/sounds/beep3.wav")
#define SAMPLE_FOOD 		loadsample("data/sounds/food.wav")
#define SAMPLE_BLOCK 		loadsample("data/sounds/blocking.wav")
#define SAMPLE_PARRY 		loadsample("data/sounds/parrying.wav")
#define SAMPLE_GUARDBREAK 	loadsample("data/sounds/guardBreak.wav")
#define SAMPLE_RAGEFULL 	loadsample("data/sounds/rageFull.wav")
#define SAMPLE_RAGESPEND 	loadsample("data/sounds/ragespend.wav")
#define SAMPLE_IRON5 		loadsample("data/sounds/iron5.wav")
#define SAMPLE_BULLDOZER 	loadsample("data/sounds/bulldozer.wav")
#define SAMPLE_STRONGPUNCH	loadsample("data/sounds/strongPunch.wav")
#define SAMPLE_JUMPLAND 	loadsample("data/sounds/jumpland.wav")
#define SAMPLE_BIKERUN 		loadsample("data/sounds/bikeRun.wav")
#define SAMPLE_BIKEIDLE 	loadsample("data/sounds/bikeIdle.wav")
#define SAMPLE_BIKEIGNITE 	loadsample("data/sounds/bikeIgnite.wav")
#define SAMPLE_TRUCK 		loadsample("data/sounds/truck.wav")
#define SAMPLE_RAIN 		loadsample("data/sounds/rain.wav")
#define SAMPLE_THUNDER 		loadsample("data/sounds/thunder.wav")
#define SAMPLE_THUNDER2 	loadsample("data/sounds/thunder2.wav")
#define SAMPLE_WIND 		loadsample("data/sounds/wind.wav")
#define SAMPLE_WIND2 		loadsample("data/sounds/wind2.wav")
#define SAMPLE_WIND3 		loadsample("data/sounds/wind3.wav")
#define SAMPLE_CROWD 		loadsample("data/sounds/crowd.wav")
#define SAMPLE_CROWD2 		loadsample("data/sounds/crowd2.wav")
#define SAMPLE_CROWD3 		loadsample("data/sounds/crowd3.wav")
#define SAMPLE_MUTE 		loadsample("data/sounds/mute.wav")
#define SAMPLE_VEHELITS2	loadsample("data/voices/vehelits2.wav")
#define SAMPLE_BIP1 		loadsample("data/sounds/bip1.wav")
#define SAMPLE_BIP2 		loadsample("data/sounds/bip2.wav")
#define SAMPLE_NINPO 		loadsample("data/sounds/ninpo.wav")
#define SAMPLE_SHRING 	loadsample("data/sounds/shring.wav")
#define SAMPLE_SHRING2 	loadsample("data/sounds/shring2.wav")
#define SAMPLE_SHRING3 	loadsample("data/sounds/shring3.wav")
#define SAMPLE_SHRING4 	loadsample("data/sounds/shring4.wav")
#define SAMPLE_SHRING5 	loadsample("data/sounds/shring5.wav")
#define SAMPLE_ALARM 		loadsample("data/sounds/alarm.wav")
#define SAMPLE_MONEY 		loadsample("data/sounds/money.wav")
#define SAMPLE_KO 		loadsample("data/sounds/ko.wav")

void saveAssets()
{//Load global assets for further use

	if(getglobalvar("saveAssets") == NULL()){ //TRIGGER TO ALLOW ALL VARIABLES TO BE DEFINED ONCE

		//CAUTION!! ALL GLOBAL VARIABLES BELOW WILL CHANGE ALL ASSETS USED IN MANY SCRIPTS

		//GLOBAL USAGE
		setglobalvar("charIcon1",	loadsprite("data/sprites/charicon1.png"));
		setglobalvar("charIcon2",	loadsprite("data/sprites/charicon2.png"));
		setglobalvar("timeIcon",	loadsprite("data/sprites/timeicon.png"));
		setglobalvar("back1",		loadsprite("data/sprites/back1.png"));
		setglobalvar("back2",		loadsprite("data/sprites/back2.png"));
		setglobalvar("back3",		loadsprite("data/sprites/back3.png"));
		setglobalvar("back4",		loadsprite("data/sprites/back4.png"));
		setglobalvar("lifebarP1",	loadsprite("data/sprites/lifebarP1.png"));
		setglobalvar("lifebarP2",	loadsprite("data/sprites/lifebarP2.png"));
		setglobalvar("lifebarE1",	loadsprite("data/sprites/lifebarE1.png"));
		setglobalvar("lifebarE2",	loadsprite("data/sprites/lifebarE2.png"));
		setglobalvar("grids",		loadsprite("data/bgs/select/grids.png"));
		setglobalvar("locked",		loadsprite("data/bgs/select/locked.png"));
		setglobalvar("type_1",		loadsprite("data/sprites/layout1.png"));
		setglobalvar("type_2",		loadsprite("data/sprites/layout2.png"));
		setglobalvar("type_3",		loadsprite("data/sprites/layout3.png"));
		setglobalvar("type_4",		loadsprite("data/sprites/layout4.png"));
		setglobalvar("type_5",		loadsprite("data/sprites/layout5.png"));
		setglobalvar("arrowDown",	loadsprite("data/sprites/arrowd.gif"));
		setglobalvar("parrow5",		loadsprite("data/sprites/parrow5.png"));

		//ENDINGS USAGE
		setglobalvar("sor3_endb1",	loadsprite("data/scenes/ending_b/endb00.png"));
		setglobalvar("sor3_endb2",	loadsprite("data/scenes/ending_b/endb04.png"));
		setglobalvar("textFade",	loadsprite("data/sprites/text_fade.png"));

		//TRIGGER TO STOP THE SCRIPT AFTER RUN ONCE, SAVE CPU POWER
		setglobalvar("saveAssets",1);
	}
}

void clearAssets()
{//Clear all used assets to save memory

	if(getglobalvar("clearAssets") == NULL()){ //TRIGGER TO ALLOW ALL VARIABLES TO BE DEFINED ONCE

		//GLOBAL USAGE
		free(getglobalvar("charIcon1"));
		free(getglobalvar("charIcon2"));
		free(getglobalvar("timeIcon"));
		free(getglobalvar("back1"));
		free(getglobalvar("back2"));
		free(getglobalvar("back3"));
		free(getglobalvar("back4"));
		free(getglobalvar("lifebarP1"));
		free(getglobalvar("lifebarP2"));
		free(getglobalvar("lifebarE1"));
		free(getglobalvar("lifebarE2"));
		free(getglobalvar("grids"));
		free(getglobalvar("locked"));
		free(getglobalvar("type_1"));
		free(getglobalvar("type_2"));
		free(getglobalvar("type_3"));
		free(getglobalvar("type_4"));
		free(getglobalvar("type_5"));
		free(getglobalvar("arrowDown"));
		free(getglobalvar("parrow5"));

		//ENDINGS USAGE
		free(getglobalvar("sor3_endb1"));
		free(getglobalvar("sor3_endb2"));
		free(getglobalvar("textFade"));

		//ROUTE MENU USAGE
		if(getglobalvar("preview") != NULL()){free(getglobalvar("preview"));}
		if(getglobalvar("label") != NULL()){free(getglobalvar("label"));}

		//HI-SCORE USAGE
		if(getglobalvar("icon0") != NULL()){free(getglobalvar("icon0"));}
		if(getglobalvar("icon1") != NULL()){free(getglobalvar("icon1"));}
		if(getglobalvar("icon2") != NULL()){free(getglobalvar("icon2"));}
		if(getglobalvar("icon3") != NULL()){free(getglobalvar("icon3"));}
		if(getglobalvar("icon4") != NULL()){free(getglobalvar("icon4"));}
		if(getglobalvar("icon5") != NULL()){free(getglobalvar("icon5"));}
		if(getglobalvar("icon6") != NULL()){free(getglobalvar("icon6"));}
		if(getglobalvar("icon7") != NULL()){free(getglobalvar("icon7"));}
		if(getglobalvar("icon8") != NULL()){free(getglobalvar("icon8"));}
		if(getglobalvar("icon9") != NULL()){free(getglobalvar("icon9"));}

		//SAMPLES USAGE
		unloadsample(SAMPLE_BEEP3);
		unloadsample(SAMPLE_FOOD);
		unloadsample(SAMPLE_GUARDBREAK);
		unloadsample(SAMPLE_RAGEFULL);
		unloadsample(SAMPLE_RAGESPEND);
		unloadsample(SAMPLE_IRON5);
		unloadsample(SAMPLE_BULLDOZER);
		unloadsample(SAMPLE_STRONGPUNCH);
		unloadsample(SAMPLE_JUMPLAND);
		unloadsample(SAMPLE_BIKERUN);
		unloadsample(SAMPLE_BIKEIDLE);
		unloadsample(SAMPLE_BIKEIGNITE);
		unloadsample(SAMPLE_TRUCK);
		unloadsample(SAMPLE_RAIN);
		unloadsample(SAMPLE_THUNDER);
		unloadsample(SAMPLE_THUNDER2);
		unloadsample(SAMPLE_WIND);
		unloadsample(SAMPLE_WIND2);
		unloadsample(SAMPLE_WIND3);
		unloadsample(SAMPLE_CROWD);
		unloadsample(SAMPLE_CROWD2);
		unloadsample(SAMPLE_CROWD3);
		unloadsample(SAMPLE_MUTE);
		unloadsample(SAMPLE_VEHELITS2);
		unloadsample(SAMPLE_BIP1);
		unloadsample(SAMPLE_BIP2);
		unloadsample(SAMPLE_NINPO);
		unloadsample(SAMPLE_SHRING);
		unloadsample(SAMPLE_SHRING2);
		unloadsample(SAMPLE_SHRING3);
		unloadsample(SAMPLE_SHRING4);
		unloadsample(SAMPLE_SHRING5);
		unloadsample(SAMPLE_ALARM);
		unloadsample(SAMPLE_MONEY);
		unloadsample(SAMPLE_KO);

		//TRIGGER TO STOP THE SCRIPT AFTER RUN ONCE, SAVE CPU POWER
		setglobalvar("clearAssets", 1);
	}
}
void loadCfg()
{//Load saved configuration file or reset to default if the CFG file not exists

	if(getglobalvar("difficult") == NULL()){

		//USED TO LOAD DEFAULT OPENBOR *.SAV FILE
		loadgamefile();

		//CONFIGURATION FILE EXISTIS?? GET ALL SAVED VALUES
		if(openfilestream("saves/SOR2XComboExtra.cfg") != -1){
			void cfg = openfilestream("saves/SOR2XComboExtra.cfg");
			int pos  = 0;

			//GAMEPLAY MENU
			setglobalvar("difficult", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("enemyLifeRate",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("lives",				getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);
			setglobalvar("lastChance", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("counterAttackReward", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("rushHeat", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("juggleSystem", 		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("otgSystem",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("enemyRushLimit",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("randomBoss", 			getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);
			setglobalvar("lockMp",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("energyRegenerate", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("walls",				getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("screenEdge",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("itemDrop",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("smarterEnemy",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("blockCost",				getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);

			//CONTROLS MENU
			setglobalvar("blockType", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("runType", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("dodgeType", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("jumpType", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("extraButton",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("screenshots",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("arcadeLockToggle",	getfilestreamargument(cfg, pos, "string")); filestreamnextline(cfg);
			setglobalvar("touchLayout",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);

			//FEATURES MENU
			setglobalvar("levelTime", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("playedTime", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("playerArrow",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("showDamage", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("graphicEffects",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("musicStyle", 			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("bgmTest", 			getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);
			setglobalvar("levelSelect",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);

			//PARTNER MENU
			setglobalvar("partnerMode",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("partnerAggression",	getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("partnerGetFood",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("partnerFollow",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("partnerRespawn",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);

			//MULTIPLAYER MENU
			setglobalvar("versusDamage",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("multiHit",			getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);

			//SURVIVAL MENU
			setglobalvar("survivalMode",		getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("survivaLifeRestore",	getfilestreamargument(cfg, pos, "string"));	filestreamnextline(cfg);
			setglobalvar("survivalGroupSize",	getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);
			setglobalvar("survivalGroupRate",	getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);
			setglobalvar("survivalBossRate",	getfilestreamargument(cfg, pos, "int"));	filestreamnextline(cfg);

			//MISC
			setglobalvar("arcadeLock", 			getfilestreamargument(cfg, pos, "int"));
		}
		else
		{
			defaultCfg(); //CONFIGURATION FILE NOT EXISTS?? APPLY DEFAULT VALUES
		}
	}
}

void defaultCfg()
{//Restore default configuration file

	//GAMEPLAY MENU
	setglobalvar("difficult", "normal");
	setglobalvar("enemyLifeRate", "100%");
	setglobalvar("lives", 9);
	setglobalvar("lastChance", "10%");
	setglobalvar("counterAttackReward", "25%");
	setglobalvar("rushHeat", "9");
	setglobalvar("juggleSystem", "40");
	setglobalvar("otgSystem", "4");
	setglobalvar("enemyRushLimit", "unlimited");
	setglobalvar("randomBoss", 1);
	setglobalvar("lockMp", "on");
	setglobalvar("energyRegenerate", "never");
	setglobalvar("walls", "all_types");
	setglobalvar("screenEdge", "all_types");
	setglobalvar("itemDrop", "mixed");
	setglobalvar("smarterEnemy", "on");
	setglobalvar("blockCost", "2");

	//CONTROLS MENU
	setglobalvar("blockType", "hold");
	setglobalvar("runType", "sor2x");
	setglobalvar("dodgeType", "sor2x");
	setglobalvar("jumpType", "sor2x");
	setglobalvar("extraButton", "charge_attack");
	setglobalvar("screenshots", "off");
	setglobalvar("arcadeLockToggle", "off");
	setglobalvar("touchLayout", "type_3");

	//FEATURES MENU
	setglobalvar("levelTime", "timeline");
	setglobalvar("playedTime", "on");
	setglobalvar("playerArrow", "off");
	setglobalvar("showDamage", "combos_only");
	setglobalvar("graphicEffects", "sor2x");
	setglobalvar("musicStyle", "remake");
	setglobalvar("bgmTest", 0);
	setglobalvar("levelSelect", "off");

	//PARTNER MENU
	setglobalvar("partnerMode", "balanced");
	setglobalvar("partnerAggression", "*********");
	setglobalvar("partnerGetFood", "50%_life");
	setglobalvar("partnerFollow", "automatic");
	setglobalvar("partnerRespawn", "automatic");

	//MULTIPLAYER MENU
	setglobalvar("versusDamage", "disabled");
	setglobalvar("multiHit", "disabled");

	//SURVIVAL MENU
	setglobalvar("survivalMode", "single");
	setglobalvar("survivaLifeRestore", "25%");
	setglobalvar("survivalGroupSize", 5);
	setglobalvar("survivalGroupRate", 5);
	setglobalvar("survivalBossRate", 5);

	//MISC
	setglobalvar("arcadeLock", 0);
	setglobalvar("defaults", NULL());
}

void saveCfg()
{//Save custom menu variables to a external file for load each time the game is started
	void file = createfilestream();
	int pos	  = 0;

	//GAMEPLAY MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("difficult"), 1);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("enemyLifeRate"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("lives"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("lastChance"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("counterAttackReward"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("rushHeat"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("juggleSystem"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("otgSystem"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("enemyRushLimit"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("randomBoss"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("lockMp"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("energyRegenerate"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("walls"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("screenEdge"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("itemDrop"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("smarterEnemy"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("blockCost"), 0);

	//CONTROLS MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("blockType"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("runType"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("dodgeType"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("jumpType"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("extraButton"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("screenshots"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("arcadeLockToggle"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("touchLayout"), 0);

	//FEATURES MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("levelTime"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("playedTime"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("playerArrow"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("showDamage"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("graphicEffects"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("musicStyle"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("bgmTest"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("levelSelect"), 0);

	//PARTNER MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("partnerMode"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("partnerAggression"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("partnerGetFood"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("partnerFollow"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("partnerRespawn"), 0);

	//MULTIPLAYER MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("versusDamage"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("multiHit"), 0);

	//SURVIVAL MENU
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("survivalMode"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("survivaLifeRestore"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("survivalGroupSize"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("survivalGroupRate"), 0);
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("survivalBossRate"), 0);

	//MISC
	setfilestreamposition(file, pos);filestreamappend(file, getglobalvar("arcadeLock"), 0);

	//FILE CREATION TASK
	savefilestream(file, "SOR2XComboExtra.cfg", "saves/");
	closefilestream(file);
}
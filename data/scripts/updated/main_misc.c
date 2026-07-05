#import "data/scripts/keyall/menu_select.c"
#import "data/scripts/keyall/menu_level.c"


void randomSeed()
{//Thanks to msmalik681 RANDOM++ SCRIPT

	if(getlocalvar("seed") == NULL()){
		float seed; //INITIALIZE SEED.

		if(seed == NULL()){seed = 1;} //START IT OFF

		seed++; //INCREMENT SEED
		srand(seed); //APPLY SEED TO RANDOM FUNCTION
		setlocalvar("seed", 1);
	}
}

void screenshotsOff()
{//Set screenshots on/off according to extra menu option

	if(getglobalvar("screenshots") == "off" && openborvariant("noscreenshot") != 1){changeopenborvariant("noscreenshot", 1);}else
	if(getglobalvar("screenshots") == "on" && openborvariant("noscreenshot") != 0){changeopenborvariant("noscreenshot", 0);}
}

void resetCharge()
{//Reset "Charge Attack" timer when any menu or text entity is on

	if(getglobalvar("activeText") != 0){
		int limit	= 10000;
		int add		= 1000000;

		if(getglobalvar("chargeStart0") < openborvariant("elapsed_time")+limit){setglobalvar("chargeStart0", openborvariant("elapsed_time")+add);}
		if(getglobalvar("chargeStart1") < openborvariant("elapsed_time")+limit){setglobalvar("chargeStart1", openborvariant("elapsed_time")+add);}
		if(getglobalvar("chargeStart2") < openborvariant("elapsed_time")+limit){setglobalvar("chargeStart2", openborvariant("elapsed_time")+add);}
		if(getglobalvar("chargeStart3") < openborvariant("elapsed_time")+limit){setglobalvar("chargeStart3", openborvariant("elapsed_time")+add);}
	}
}

void showVersion()
{
	float hRes		= openborvariant("hResolution");
	void text1		= "MOD By iintothewind V.";	//TEXT "V"
	void text2		= "SOR2XCombo B.";	//TEXT "B"
	void version	= "2.3.1";	//CURRENT GAME VERSION NUMBER
	void build		= "20260621";	//RECOMENDED OPENBOR BUILD NUMBER
	int yPos		= 262;
	int font0		= 0;
	int font1		= 1;
	int layer		= 1001;

	//DRAW CURRENT VERSION
	drawstring(1, yPos, font0, text1, layer);
	drawstring(2+strwidth(text1, font0), yPos, font1, version, layer);
	drawstring((hRes-1)-strwidth(text2, font0)-strwidth(build, font1), yPos, font0, text2, layer);
	drawstring(hRes-strwidth(build, font0), yPos, font1, build, layer);
}

void getFps()
{//Get FPS value by checking engine ticks
	int mult1	= 2;
	int mult2	= 100000;
	int mult3	= 100;
	int add		= 9;
	float fps;

	//START ALL NECESSARY VARIABLES
	if(getlocalvar("lastTick") == NULL()){setlocalvar("lastTick", 0);}
	if(getlocalvar("frameRate") == NULL()){setlocalvar("frameRate", 0);}

	//CALCULATE AND REGISTER THE FPS IN A GLOBAL VARIABLE TO BE ACCESSIBLE FOR OTHER SCRIPTS
	setlocalvar("frameRate", (getlocalvar("frameRate")+(openborvariant("ticks")-getlocalvar("lastTick")))/mult1);
	setlocalvar("lastTick", openborvariant("ticks"));
	fps = ((mult2/getlocalvar("frameRate"))+add)/mult3;
	if(fps == NULL() || fps > 1000){setglobalvar("getFps", 1001);}else{setglobalvar("getFps", fps);}
}

void applyTurbo(int player)
{//Script to increase cursor repeat rate and speed, like a turbo key
	float time	= openborvariant("elapsed_time"); //CURRENT TIME
	float delay	= 10; //TURBO KEY REPEAT DELAY

	//WORKS IN BOTH "CHARACTER SELECT" AND "LEVEL SELECT" SCREENS
	if(openborvariant("in_selectscreen") || getglobalvar("activeText") == "Level"){
		if(time > getglobalvar("heldStart"+player)){ //REACHED DEFINED DELAY??
			if(getglobalvar("heldRepeat"+player) == NULL()){setglobalvar("heldRepeat"+player, time+delay);}

			//ADD BELOW ALL EVENTS THAT WILL USE THE TURBO KEY FEATURE
			if(time > getglobalvar("heldRepeat"+player)){
				menuLevel(player);
				menuSelect(player);
				setglobalvar("heldRepeat"+player, time+delay); //RESET THE "HELD BUTTON" OLD VARIABLE TO ADJUST THE NEXT REPEAT
			}
		}
	}

	//WORKS IN LEVEL
	if(openborvariant("in_level")){
		if(getplayerproperty(player, "joining") == 1){ //THE PLAYER ENTERED IN THE GAME BUT THE HERO IS NOT SELECTED YET??
			if(getglobalvar("heldStart"+player) != NULL()){ //ANY DIRECTIONAL BUTTON IS HELD??
				if(time > getglobalvar("heldStart"+player)+delay*2){ //REACHED DEFINED DELAY??
					changeplayerproperty(player, "playkeys", getplayerproperty(player, "keys")); //RESET HELD KEY STATUS
					setglobalvar("heldStart"+player, time);
				}
			}
		}
	}
}

void turboKey()
{//Check if the defined player exists before execute any task in Turbo Key feature
	if(getplayerproperty(0, "name")){applyTurbo(0);}
	if(getplayerproperty(1, "name")){applyTurbo(1);}
	if(getplayerproperty(2, "name")){applyTurbo(2);}
	if(getplayerproperty(3, "name")){applyTurbo(3);}
}

void liveScreen()
{//Draw a "live screen" in the background
	if(openborvariant("current_branch") == "sor2_st4b"){
		if(getglobalvar("liveScreenX") != NULL()){
			void vScreen;
			float x			= getglobalvar("liveScreenX");
			float y			= getglobalvar("liveScreenY");
			int minZ		= openborvariant("PLAYER_MIN_Z");
			int sprqDif		= 200;
			int screenDif	= 100;
			int scale		= 48;

			if(getglobalvar("vScreen") == NULL()){
				setglobalvar("vScreen", allocscreen(openborvariant("hResolution"), openborvariant("vResolution")));
			}

			vScreen = getglobalvar("vScreen");

			clearscreen(vScreen);

			if(openborvariant("pause") == 0){
				drawspriteq(vScreen, x, openborconstant("MIN_INT"), minZ+sprqDif, 0, 0);
				changedrawmethod(NULL(),"reset", 1);
				changedrawmethod(NULL(),"enabled", 1);
				changedrawmethod(NULL(),"scalex", scale);
				changedrawmethod(NULL(),"scaley", scale);
				drawscreen(vScreen, x, y, minZ-screenDif);
			}
		}
	}
	else
	{
		if(getglobalvar("vScreen") != NULL()){
			free(getglobalvar("vScreen"));
			setglobalvar("vScreen", NULL());
		}
	}
}

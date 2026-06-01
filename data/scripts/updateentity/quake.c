void main()
{//Custom scripted quake
 //You need to create a simple entity to use it and call this script at the "update entity" event, is more accurate
 //To use properly, you need to spawn the "quake" entity at any moment you want

	void self  = getlocalvar("self");
	void name  = getentityproperty(self, "defaultname");
	float time = openborvariant("elapsed_time")/10;	//GLOBAL TIME COUNTER USED TO CONTROL QUAKE POWER OR DURATION
	float timeS;		//APPLY THE DELAY VALUE USED TO CONTROL THE SHAKE SPEED
	float intensity; 	//HOW MUCH THE PANEL WILL GO DOWN IN PIXELS
	float duration; 	//HOW LONG THE QUAKE WILL LAST
	float rate; 		//CONTROLS THE QUAKE RATE, USE 1 FOR SHAKE ONCE OR 2 TO SHAKE CONSTANTLY
	float speed; 		//CONTROLS THE QUAKE SPEED BY CHANGING THE DELAY BETWEEN EACH SHAKE
	int smooth; 		//THIS FLAG ACTIVATES A MORE SMOOTH MOVEMENT WHEN USING A HIGH RATE VALUE, LIKE AN EARTHQUAKE
	int reset;			//DEFAULT SHAKE EFFECT VALUE WHEN DISABLED, DON'T CHANGE THIS!!!!!

	// Screen quake is disabled globally because it can cause severe scene flicker
	// when multiple quake emitters overlap with moving backgrounds or effects.
	if(name == "QuakeHigh" || name == "QuakeLow"){
		setglobalvar("quakePower"+self, NULL());
		setglobalvar("quakeTimer"+self, NULL());
		setglobalvar("quakeOn", NULL());
		changelevelproperty("quake", 0);
		killentity(self);
		return;
	}

	//GRADUAL EFFECT, DURATION IS MANAGED BY INTENSITY
	if(name == "QuakeHigh"){
		intensity	= 8;
		duration 	= 0;
		rate 		= 2;
		speed 		= 1;
		smooth		= 0;
		reset 		= 0;
		timeS 		= openborvariant("elapsed_time")/speed;

		if(getglobalvar("quakePower"+self) == NULL()){setglobalvar("quakePower"+self, time+intensity);}
		if(getglobalvar("quakeOn") == NULL()){setglobalvar("quakeOn", 1);}

		if(timeS%rate == 0){ //USED TO CONTROL SHAKE RATE
			if(getglobalvar("quakePower"+self)-time > 0){ //USED TO AVOID NEGATIVE NUMBERS
				changelevelproperty("quake", getglobalvar("quakePower"+self)-time); //APPLY SHAKE EFFECT IN THE CURRENT LEVEL
			}
			else
			{
				//CLEAR ALL QUAKE VARIABLES
				setglobalvar("quakePower"+self, NULL());
				setglobalvar("quakeTimer"+self, NULL());
				setglobalvar("quakeOn", NULL());
				changelevelproperty("quake", reset);
				killentity(self); //SUICIDE
			}
		}
		else
		{
			if(smooth != 1){changelevelproperty("quake", reset);} //USED TO AVOID THE SMOOTH MOVEMENT IF THE FLAG IS NOT 1
		}
	}

	else

	//REGULAR EFFECT, DURATION IS MANAGED BY TIME
	if(name == "QuakeLow"){
		intensity	= 1;
		duration 	= 4;
		rate 		= 2;
		speed 		= 1;
		smooth		= 0;
		reset 		= 0;
		timeS 		= openborvariant("elapsed_time")/speed;

		if(getglobalvar("quakePower"+self) == NULL()){setglobalvar("quakePower"+self, intensity);}
		if(getglobalvar("quakeTimer"+self) == NULL()){setglobalvar("quakeTimer"+self, time+duration);}
		if(getglobalvar("quakeOn") == NULL()){setglobalvar("quakeOn", 1);}

		if(timeS%rate == 0){ //USED TO CONTROL SHAKE RATE
			if(getglobalvar("quakeTimer"+self)-time > 0){ //USED TO AVOID NEGATIVE NUMBERS
				changelevelproperty("quake", getglobalvar("quakePower"+self)); //APPLY SHAKE EFFECT IN THE CURRENT LEVEL
			}
			else
			{
				//CLEAR ALL QUAKE VARIABLES
				setglobalvar("quakePower"+self, NULL());
				setglobalvar("quakeTimer"+self, NULL());
				setglobalvar("quakeOn", NULL());
				changelevelproperty("quake", reset);
				killentity(self); //SUICIDE
			}
		}
		else
		{
			if(smooth != 1){changelevelproperty("quake", reset);} //USED TO AVOID THE SMOOTH MOVEMENT IF THE FLAG IS NOT 1
		}
	}
}
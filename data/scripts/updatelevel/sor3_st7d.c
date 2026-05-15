void main()
{//Bike stage (EXPERIMENTAL)
	void player1 = getplayerproperty(0, "entity"); //DEFINE MAIN ENTITY
	void player2 = getplayerproperty(1, "entity"); //DEFINE MAIN ENTITY
	void player3 = getplayerproperty(2, "entity"); //DEFINE MAIN ENTITY
	void player4 = getplayerproperty(3, "entity"); //DEFINE MAIN ENTITY
	void leader;
	int iPIndex;
	int x;
	int y;
	int z;
	int xDif	= 4;  	//VALUE TO ADJUST POSITION IN X AXIS
	int yDif	= 15;	//VALUE TO ADJUST POSITION IN Y AXIS
	int font0  	= 0;
	int font1  	= 1;
	int font2  	= 2; 	//DEFAULT FONT FOR LEADER INDICATION STAR
	int font3  	= 7;
	int font4  	= 9;
	float fps	= getglobalvar("getFps");
	float time	= openborvariant("elapsed_time"); //GET ELAPSED TIME
	
	//DEFINE PLAYER LEADER, THE ONE THAT CONTROLS BGSPEED
	if(player1 != NULL()){
		leader  = player1;
		iPIndex = 0;
		setglobalvar("leader", iPIndex);
		x 		= getentityproperty(player1, "x");
		y 		= getentityproperty(player1, "y");
		z 		= getentityproperty(player1, "z");
		drawstring(x-xDif, z-y-yDif, font2, "*", z);
		changeplayerproperty(0, "disablekeys", 0);
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ATTACK2"));
	}
	else
	if(player2 != NULL()){
		leader  = player2;
		iPIndex = 1;
		setglobalvar("leader", iPIndex);
		x 		= getentityproperty(player2, "x");
		y 		= getentityproperty(player2, "y");
		z 		= getentityproperty(player2, "z");
		drawstring(x-xDif, z-y-yDif, font2, "*", z);
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(1, "disablekeys", 0);
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ATTACK2"));
	}
	else
	if(player3 != NULL()){
		leader  = player3;
		iPIndex = 2;
		setglobalvar("leader", iPIndex);
		x 		= getentityproperty(player3, "x");
		y 		= getentityproperty(player3, "y");
		z 		= getentityproperty(player3, "z");
		drawstring(x-xDif, z-y-yDif, font2, "*", z);
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(2, "disablekeys", 0);
		changeplayerproperty(3, "disablekeys", openborconstant("FLAG_ATTACK2"));
	}
	else
	if(player4 != NULL()){
		leader  = player4;
		iPIndex = 3;
		setglobalvar("leader", iPIndex);
		x 		= getentityproperty(player4, "x");
		y 		= getentityproperty(player4, "y");
		z 		= getentityproperty(player4, "z");
		drawstring(x-xDif, z-y-yDif, font2, "*", z);
		changeplayerproperty(0, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(1, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(2, "disablekeys", openborconstant("FLAG_ATTACK2"));
		changeplayerproperty(3, "disablekeys", 0);
	}
	
	//FIRST TIME LOADING THE SCRIPT?? SET VARIABLES IF NULL
	if(getglobalvar("bgSpeed") == NULL()){
		setlocalvar("accel", 1); //VALUE TO ADD ACCELERATION
		setlocalvar("brake", 40); //VALUE TO REDUCE ACCELERATION
		setlocalvar("distance", 1290000000); //TOTAL DISTANCE TO FINISH THE LEVEL, WILL BE REDUCED BY BGSPEED (12,9KM)
		setlocalvar("jump", 2); //VALUE TO ADD JUMP
		setlocalvar("nitroSpeed", 40); //VALUE NECESSARY TO USE NITRO SPEED
		setglobalvar("useNitro", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE NITRO IS USED OR NOT
		setglobalvar("move", 0); //VALUE TO ADD MOBILITY
		setglobalvar("delay", 20); //VALUE TO CALCULATE EDELAY FOR TIRE HASTE/SLOW MOVING EFFECT
		setglobalvar("bgSpeed", 0); //VALUE TO MOVE ALL BACKGROUNDS
	}
	
	//GET AND NAME ALL VARIABLES TO EASY USE
	float accel 		= getlocalvar("accel");
	float brake 		= getlocalvar("brake");
	float dist			= getlocalvar("distance");
	float jump			= getlocalvar("jump");
	float nitroSpeed	= getlocalvar("nitroSpeed");
	float move 			= getglobalvar("move");
	float delay 		= getglobalvar("delay");
	float bgSpeed 		= getglobalvar("bgSpeed");
	float rate			= 2;
	
	if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
		if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF THE GAME IS IN EXTRA/PARTNER MENUS
			void ani	= getentityproperty(leader, "animationID"); //GET LEADER ANIMATION
			float maxMp = getentityproperty(leader, "maxmp"); //GET LEADER MAX MP
			float mp 	= getentityproperty(leader, "mp"); //GET CURRENT LEADER MP

			//CHANGE ACCEL, NITRO AND BRAKE MULTIPLIER ACCORDING TO THE CURRENT FPS
			if(bgSpeed > 0){

				//USED ON ANDROID OR LOW HARDWARE DEVICES, THAT SOMETIMES CAN RUN BELOW 60 FPS
				if(fps >= 0  && fps < 150){	accel = accel*3;nitroSpeed = nitroSpeed*3;brake = brake*3;rate = rate/rate;}

				//USED ON WINDOWS, NORMAL FRAME RATE BETWEEN 200 AND 250 FPS
				if(fps >= 150 && fps < 300){accel = accel;nitroSpeed = nitroSpeed;brake = brake;rate = rate/rate;}
				
				//USED ON V-SYNC DISABLED BUILDS LIKE THE 4.0 ALPHA OR MINIS, TO ADJUST FOR 300+ FPS
				if(fps >= 300 && fps < 600){accel = accel/2;nitroSpeed = nitroSpeed/2;brake = brake/2;rate = rate*2;}
				if(fps >= 600 && fps < 900){accel = accel/2;nitroSpeed = nitroSpeed/2;brake = brake/2;rate = rate*3;}
				if(fps >= 900){				accel = accel/2;nitroSpeed = nitroSpeed/2;brake = brake/2;rate = rate*4;}
			}
			
			if(ani == openborconstant("ANI_FREESPECIAL9")){
				if(bgSpeed < 63000){ //MAXIMUM NITRO SPEED LIMIT
					setglobalvar("bgSpeed", bgSpeed+accel*nitroSpeed); //ADD NITROUS SPEED!!
					setglobalvar("useNitro", 1); //FLAG TO SHOW TO OTHER ENTITIES THAT THE NITRO IS USED OR NOT
					setglobalvar("useBrake", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE BRAKE IS USED OR NOT
				}
			}
			else
			if(ani != openborconstant("ANI_FREESPECIAL9")){
				if(bgSpeed < 45000){ //MAXIMUM NORMAL SPEED LIMIT
					setglobalvar("bgSpeed", bgSpeed+accel); //ADD SPEED!!
					setglobalvar("useNitro", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE NITRO IS USED OR NOT
					setglobalvar("useBrake", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE BRAKE IS USED OR NOT
				}
				if(bgSpeed > 45000){ //ABOVE NORMAL SPEED LIMIT
					setglobalvar("bgSpeed", bgSpeed-accel); //SLOWLY LOSE SPEED!!
					setglobalvar("useNitro", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE NITRO IS USED OR NOT
					setglobalvar("useBrake", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE BRAKE IS USED OR NOT
				}
			}
			
			if(playerkeys(iPIndex, 0, "special")){ //PRESSING BRAKES??
				if(bgSpeed > -1){ //AVOID NEGATIVE NUMBERS
					setglobalvar("bgSpeed", bgSpeed-brake); //REDUCE SPEED!!
					setglobalvar("useNitro", 0); //FLAG TO SHOW TO OTHER ENTITIES THAT THE NITRO IS USED OR NOT
					setglobalvar("useBrake", 1); //FLAG TO SHOW TO OTHER ENTITIES THAT THE BRAKE IS USED OR NOT
				}
			}
			
			int painL = getentityproperty(leader, "aiflag", "inpain"); //GET CURRENT LEADER PAIN STATUS
			int deadL = getentityproperty(leader, "dead"); //GET CURRENT LEADER DEAD STATUS
			
			if(painL == 0 && deadL == 0){ //IS NOT IN PAIN OR DEAD STATUS??
				if(bgSpeed > 0 && bgSpeed < 4000){ //FIRST GEAR
					setlocalvar("accel", 12);
					setglobalvar("move", 0.1);
					setglobalvar("delay", 20);
				}
				else
				if(bgSpeed >= 4000 && bgSpeed < 9000){ //SECOND GEAR
					setlocalvar("accel", 10);
					setglobalvar("move", 0.3);
					setglobalvar("delay", 15);
				}
				else
				if(bgSpeed >= 9000 && bgSpeed < 15000){ //THIRD GEAR
					setlocalvar("accel", 8);
					setglobalvar("move", 0.6);
					setglobalvar("delay", 10);
				}
				else
				if(bgSpeed >= 15000 && bgSpeed < 23000){ //FOURTH GEAR
					setlocalvar("accel", 6);
					setglobalvar("move", 1.2);
					setglobalvar("delay", 5);
				}
				else
				if(bgSpeed >= 23000 && bgSpeed < 36000){ //FIFTH GEAR
					setlocalvar("accel", 4);
					setglobalvar("move", 1.5);
					setglobalvar("delay", 1);
				}
				else
				if(bgSpeed >= 36000){
					setlocalvar("accel", 2); //LOWER ACCEL VALUE TO SIMULATE ENGINE LIMIT
					setglobalvar("move", 1.5);
					setglobalvar("delay", 1);
				}
				else
				{//IS NOT MOVING?? DEFAULT VALUES
					setlocalvar("accel", 1); //DEFAULT ACCEL VALUE
					setglobalvar("move", 0); //RESET MOBITY TO ZERO IF THE BIKE IS STOPPED
					setglobalvar("delay", 20); //DEFAULT DELAY VALUE
				}
			}
			else
			if(painL == 1){ //IS IN PAIN STATUS??
				setlocalvar("accel", brake); //LOSE SPEED
				setglobalvar("bgSpeed", bgSpeed-accel); //LOWER BGSPEED
			}
			else
			if(deadL == 1){ //IS IN DEAD STATUS??
				setlocalvar("accel", brake*10); //LOSE SPEED
				setglobalvar("move", 0); //RESET MOBITY TO ZERO IF THE BIKE IS STOPPED
				setglobalvar("delay", 20); //DEFAULT DELAY VALUE
				setglobalvar("bgSpeed", bgSpeed-accel); //LOWER BGSPEED
			}
			
			//CHANGE BGSPEED AND TOTAL DISTANCE IN REAL TIME
			if(time%rate == 0){
				if(bgSpeed >= 0){

					//DEFAULT DISTANCE SUBTRACTION
					changelevelproperty("bgspeed", bgSpeed);setlocalvar("distance", dist-bgSpeed);

					//ADDITIONAL DISTANCE SUBTRACTION, USED ON ANDROID OR LOW HARDWARE DEVICES, THAT SOMETIMES CAN RUN BELOW 60 FPS
					if(fps < 150){changelevelproperty("bgspeed", bgSpeed);setlocalvar("distance", getlocalvar("distance")-bgSpeed);}
				}
			}
			
			//USED TO PREVENT NEGATIVE NUMBERS AND ROLL BACK ALL BACKGROUND
			if(bgSpeed < 0){setglobalvar("bgSpeed", 0);}

			//USED TO PREVENT HIGHER SPEEDS THAN THE ENGINE LIMIT+NITRO
			if(bgSpeed > 63000){setglobalvar("bgSpeed", 63000);}
			
			//THE LEADER BIKE IS STOPPED??
			if(bgSpeed <= 0){
				int pain1 = getentityproperty(player1, "aiflag", "inpain"); //GET PAIN STATUS
				int pain2 = getentityproperty(player2, "aiflag", "inpain"); //GET PAIN STATUS
				int pain3 = getentityproperty(player3, "aiflag", "inpain"); //GET PAIN STATUS
				int pain4 = getentityproperty(player4, "aiflag", "inpain"); //GET PAIN STATUS
				
				//IS IN PAIN?? USED TO PREVENT ENTITY TO BE STUCKED IN PAIN ANIMATION
				//MAINTAIN ALL ANIMATIONS IN THE FIRST FRAME TO PREVENT WHEELS TO MOVING WITH NO BIKE SPEED
				if(pain1 == 0){updateframe(player1, 0);}
				if(pain2 == 0){updateframe(player2, 0);}
				if(pain3 == 0){updateframe(player3, 0);}
				if(pain4 == 0){updateframe(player4, 0);}
			}
			
			//REACHED DISTANCE LIMIT?? END THE CURRENT LEVEL
			if(dist <= 199999999){jumptobranch("sor3_st8a", 1);}
			
			//USED TO SIMULATE MOBILITY OF THE BIKE, LESS SPEED = LESS MOBILITY
			changeentityproperty(player1, "speed", move);
			changeentityproperty(player2, "speed", move);
			changeentityproperty(player3, "speed", move);
			changeentityproperty(player4, "speed", move);
			changeentityproperty(player1, "jumpspeed", move);
			changeentityproperty(player2, "jumpspeed", move);
			changeentityproperty(player3, "jumpspeed", move);
			changeentityproperty(player4, "jumpspeed", move);
			changeentityproperty(player1, "jumpheight", jump);
			changeentityproperty(player2, "jumpheight", jump);
			changeentityproperty(player3, "jumpheight", jump);
			changeentityproperty(player4, "jumpheight", jump);
			
			//ADJUST ALL ANIMATIONS DELAY
			changeentityproperty(player1, "edelay", 0, delay, 1, 9999, 0.001, 9999);
			changeentityproperty(player2, "edelay", 0, delay, 1, 9999, 0.001, 9999);
			changeentityproperty(player3, "edelay", 0, delay, 1, 9999, 0.001, 9999);
			changeentityproperty(player4, "edelay", 0, delay, 1, 9999, 0.001, 9999);
		}
	}
	
	drawstring(1, 250, font0, "finish:_"); //SHOW DISTANCE REMAINING
	drawstring(47, 250, font4, dist/200000000); //SHOW DISTANCE REMAINING
	drawstring(1, 260, font0, "speed:_"); //SHOW CURRENT BIKE SPEED
	drawstring(47, 260, font4, bgSpeed/7000); //SHOW CURRENT BIKE SPEED
	
	if(getglobalvar("activeText") == "Bike_Stage"){
		float hRes  = openborvariant("hresolution");
		int xPos1 	= 235;
		int xPos2  	= xPos1+10;
		int yPos 	= 70;
		int yDif 	= 11;
		int layer1 	= 1000000001;
		int layer2 	= 1000000003;
		
		//DRAW BACKGROUND AND RED ARROW
		setdrawmethod(NULL(),1,256,256,0,0,0,2);
		drawsprite(getglobalvar("back1"), 0, 0, layer1, 0);
		setdrawmethod(NULL(),0,256,256,0,0,0,0);
		drawsprite(getglobalvar("arrowDown"), 19, 216, layer2);
		
		//DRAW TEXT CONTENT
		drawstring((hRes-strwidth("run_until_the", font3))/2+1, yPos, font3, "run_until_the", layer2);
		yPos = yPos+yDif*2;
		drawstring((hRes-strwidth("level_is_finished", font3))/2+1, yPos, font3, "level_is_finished", layer2);
		yPos = yPos+yDif*4;
		drawstring((hRes-strwidth("buttons", font2))/2, yPos, font2, "buttons", layer2);
		yPos = yPos+yDif*2;
		drawstring(xPos1-strwidth("attack:", font2), yPos, font0, "attack:", layer2);
		drawstring(xPos2, yPos, font1, "punch", layer2);
		yPos = yPos+yDif;
		drawstring(xPos1-strwidth("special:", font2), yPos, font0, "special:", layer2);
		drawstring(xPos2, yPos, font1, "brake", layer2);
		yPos = yPos+yDif;
		drawstring(xPos1-strwidth("energy:", font2), yPos, font0, "energy:", layer2);
		drawstring(xPos2, yPos, font1, "Nitro", layer2);
		yPos = yPos+yDif*4;
		drawstring((hRes-strwidth("(press_attack_button_to_begin)", font2))/2, yPos, font2, "(press_attack_button_to_begin)", layer2);
		
		//DRAW FINISH AND SPEED STATUS USING A BIGGER LAYER TO PUT IT IN FRONT OF THE BACKGROUND
		drawstring(1, 250, font0, "finish:_", layer2); //SHOW DISTANCE REMAINING
		drawstring(47, 250, font4, dist/200000000, layer2); //SHOW DISTANCE REMAINING
		drawstring(1, 260, font0, "speed:_", layer2); //SHOW CURRENT BIKE SPEED
		drawstring(47, 260, font4, bgSpeed/7000, layer2); //SHOW CURRENT BIKE SPEED
		
		//DETECT IF ANY BUTTON IS PRESSED TO TURN OFF THE INFO SCREEN
		if(playerkeys(iPIndex, 1, "anybutton")){ //PRESSING ANY BUTTON??
			changeopenborvariant("nopause", 0); //UNLOCK PAUSE COMMAND
			changeopenborvariant("textbox", NULL()); //CLEAR TEXTBOX TO NOT FREEZE THE GAME
			changeplayerproperty(0, "disablekeys", 0);
			changeplayerproperty(1, "disablekeys", 0);
			changeplayerproperty(2, "disablekeys", 0);
			changeplayerproperty(3, "disablekeys", 0);
			setglobalvar("activeText", 0);
		}
	}
}
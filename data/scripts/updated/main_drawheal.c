void drawHeal()
{//Draw life restoration bar when player uses special, used in SPECIAL/SPECIAL2/SPECIAL3 moves (SPECIAL COST "LIFE" ONLY)
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	void partner = getglobalvar("currentPartner");

	if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
		if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF THE GAME IS IN EXTRA/PARTNER MENUS
			if(getglobalvar("specialCost") == "sor4_recovery_(time)" || getglobalvar("specialCost") == "sor4_recovery_(hits)"){
				healFunction(player1);
				healFunction(player2);
				healFunction(player3);
				healFunction(player4);
				healFunction(partner);
			}
		}
	}
}

void healFunction(void player)
{//Script used to reduce code size

	if(player != NULL()){
		int pIndex 	= getentityproperty(player, "playerindex");
		int lives 	= getplayerproperty(pIndex, "lives");

		if(lives >= 1){ //DETECTS IF THE DEFINED PLAYER IS IN-GAME AND ALIVE
			void type 		= getentityproperty(player, "type");
			void vAniID 	= getentityproperty(player, "animationID");
			int maxHealth 	= getentityproperty(player, "maxhealth");
			int health		= getentityproperty(player, "health");
			int cost		= getentityproperty(player, "energycost", "cost", openborconstant(vAniID));
			int xPos 		= 2;			//DEFAULT X POSITION
			int xSize		= 88;			//CURRENT LIFE BAR SIZE IN X AXIS, SAME AS DEFINED IN LEVELS.TXT
			int xDif		= 120;			//DEFAULT X DIFFERENCE OF EACH PLAYER LIFEBAR
			int xAdd		= xDif*pIndex;	//CALCULATE THE X DIFFERENCE OF EACH PLAYER LIFEBAR
			int yPos 		= 22;			//DEFAULT Y POSITION
			int ySize		= 3;			//CURRENT LIFE BAR SIZE IN Y AXIS, SAME AS DEFINED IN LEVELS.TXT
			int layer		= 10005; 		//DEFAULT LAYER VALUE
			int blinkRate	= 1.5; 			//GREEN BLINK RATE
			int addTime		= 1; 			//HOW MUCH LIFE WILL BE ADDED DURING THE RECOVERY BY TIME
			int addHits		= 5; 			//HOW MUCH LIFE WILL BE ADDED DURING THE RECOVERY BY HIT
			float rate		= 40;			//RATE TO SLOW OR HASTE RECOVERY BY TIME
			float time 		= openborvariant("elapsed_time");
			float fps		= getglobalvar("getFps");

			//CHANGE RATE ACCORDING TO THE CURRENT FPS
			//USED ON ANDROID OR LOW HARDWARE DEVICES, THAT SOMETIMES CAN RUN BELOW 60 FPS
			if(fps >= 0   && fps < 75){		rate = rate/3;}
			if(fps >= 75  && fps < 150){	rate = rate/2;}

			//USED ON WINDOWS, NORMAL FRAME RATE BETWEEN 200 AND 250 FPS
			if(fps >= 150  && fps < 300){	rate = rate;}

			//USED ON V-SYNC DISABLED BUILDS LIKE THE 4.0 ALPHA OR MINIS, TO ADJUST FOR 300+ FPS
			if(fps >= 300 && fps < 450){	rate = rate*2;}
			if(fps >= 450 && fps < 600){	rate = rate*3;}
			if(fps >= 600 && fps < 750){	rate = rate*4;}
			if(fps >= 750){					rate = rate*5;}

			//USED TO REDUCE ALL RATES DURING SLOWMOTION
			if(openborvariant("slowmotion")){rate = rate*2;}

			//USED TO START THE VARIABLE ONLY
			if(getglobalvar("addLife"+player) == NULL()){setglobalvar("addLife"+player, 0);}

			//USED WHEN ANY SPECIAL IS PERFORMED WITH "HEALSTART" VARIABLE, DETECT IF THE "HEAL+PLAYER" VARIABLE IS 1 AND SAVE ALL NECESSARY INFORMATIONS
			if(getglobalvar("heal"+player) == 1){ //USED SPECIAL MOVE?? ACTIVATE THE SCRIPT
				setglobalvar("addLife"+player, getglobalvar("addLife"+player)+cost); //DETECT LIFE SPEND AND SAVE IN A VARIABLE

				if((health+getglobalvar("addLife"+player)) > maxHealth){ //CHECK IF CURRENT "CURRENT LIFE"+"SPEND LIFE" WILL BE MORE THAN MAX LIFE
					setglobalvar("greenXdif"+player, maxHealth); //SET THE GREEN BAR SIZE TO MATCH THE MAX LIFE BAR SIZE
				}else{ //CHECK IF CURRENT "CURRENT LIFE"+"SPEND LIFE" WILL BE LESS THAN MAX LIFE
					setglobalvar("greenXdif"+player, health+getglobalvar("addLife"+player)); //SET THE GREEN BAR SIZE TO MATCH "CURRENT LIFE"+"SPEND LIFE"
				}
				setglobalvar("heal"+player, 0); //ALL NECESSARY VARIABLES ARE SAVED?? FINISH THIS STEP
			}

			//USED DURING HEALTH RECOVERY TASK, DETECT IF THE "MAIN" VARIABLE IS BIGGER THAN 0 AND START RECOVERY PROCESS
			if(getglobalvar("addLife"+player) > 0){ //LIFE IS NOT FULLY RECOVERED YET??
				if(getglobalvar("specialCost") == "sor4_recovery_(time)"){ //GET EXTRA MENU SPECIAL COST OPTION
					if(time%rate == 0){ //DECORATION ONLY, USED TO SLOW OR HASTE RECOVERY PROCESS IF SLOWMOTION DEBUG IS ON
						changeentityproperty(player, "health", health+addTime); //ADD LIFE AT EACH ENGINE TICK
						setglobalvar("addLife"+player, getglobalvar("addLife"+player)-addTime); //REDUCE RECOVERY REMAINING AT EACH ENGINE TICK AND SAVE IT
					}
				}
				else
				if(getglobalvar("specialCost") == "sor4_recovery_(hits)"){ //GET EXTRA MENU SPECIAL COST OPTION
					if(getglobalvar("healHit"+player) == 1){ //DETECT FLAG USED BY DIDHIT, EACH PLAYER HIT WILL CHANGE THE FLAG TO 1
						changeentityproperty(player, "health", health+addHits); //ADD LIFE AT EACH PLAYER HIT
						setglobalvar("addLife"+player, getglobalvar("addLife"+player)-addHits); //REDUCE RECOVERY REMAINING AT EACH PLAYER HIT AND SAVE IT
						setglobalvar("healHit"+player, 0); //RESET THE DIDHIT FLAG TO 0, USED TO RUN ONCE
					}
				}

				//USED TO ADJUST GREEN BAR SIZE AND EFFECTS
				if(type == openborconstant("TYPE_PLAYER")){ //USED ONLY FOR PLAYER TYPE, AVOID CPU PARTNER
					int greenXdif = getglobalvar("greenXdif"+player); //GET GREEN BAR SIZE DIFFERENCE IN X AXIS
					greenXdif = (greenXdif*xSize)/(maxHealth); //CALCULATE TO MATCH THE SAME HEALTH SIZE IN PERCENTAGE, SAME AS THE NATIVE ENGINE FORMULA

					//PLAYER IS ALIVE??
					if(health >= 1){
						drawbox(xPos+xAdd, yPos, greenXdif, ySize, layer, rgbcolor(0x00, time*blinkRate,0x00)); //DRAW GREEN BAR IN THE SCREEN
					}
				}

				//USED TO STOP THE RECOVERY PROCESS
				if(health >= maxHealth || health >= getglobalvar("greenXdif"+player)){ //CURRENT LIFE IS FULL OR HAVE THE SAME SIZE AS THE GREEN RECOVERY BAR??
					setglobalvar("addLife"+player, 0); //STOP RECOVERY PROCESS BY RESETING THE "MAIN" VARIABLE TO 0
				}
			}
		}
	}
}
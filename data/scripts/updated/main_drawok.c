void drawOk()
{//Draw "OK" bar when player uses special, used in SPECIAL/SPECIAL2/SPECIAL3 moves (SAME AS SOR3, SPECIAL COST "LIFE" ONLY)
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	void partner = getglobalvar("currentPartner");

	if(getglobalvar("specialCost") == "sor3_'ok'_bar"){
		okFunction(player1);
		okFunction(player2);
		okFunction(player3);
		okFunction(player4);
		okFunction(partner);
	}
}

void okFunction(void player)
{//Script used to reduce code size

	if(player != NULL()){
		int pIndex 	= getentityproperty(player, "playerindex");
		int lives 	= getplayerproperty(pIndex, "lives");

		if(lives >= 1){ //DETECTS IF THE DEFINED PLAYER IS IN-GAME AND ALIVE
			void type		= getentityproperty(player, "type");
			void vAniID		= getentityproperty(player, "animationID");
			int health		= getentityproperty(player, "health");
			int cost		= getentityproperty(player, "energycost", "cost", openborconstant("ANI_SPECIAL"));
			int xPos		= 100;			//DEFAULT X POSITION
			int xDif		= 120;			//DEFAULT X DIFFERENCE OF EACH PLAYER LIFEBAR
			int xAdd		= xDif*pIndex;	//CALCULATE THE X DIFFERENCE OF EACH PLAYER LIFEBAR
			int yPos		= 28;			//DEFAULT Y POSITION
			int yAdd		= 9;			//USED TO ADJUST THE "OK" WORD Y POSITION
			int layer		= 10005;		//DEFAULT LAYER VALUE
			int font0		= 0;			//NORMAL FONT
			int font1		= 9;			//"OK" BAR FONT
			int addTime		= 0.02;		//HOW MUCH POINTS WILL BE ADDED DURING THE BAR RECOVERY
			float okRate	= 20;			//"OK" WORD BLINKING RATE WHEN IS FULL
			float barRate	= 15;			//BAR BLINKING RATE WHEN IS FULL
			float time		= openborvariant("elapsed_time");
			float fps		= getglobalvar("getFps");

			//CHANGE RATE ACCORDING TO THE CURRENT FPS
			//USED ON ANDROID OR LOW HARDWARE DEVICES, THAT SOMETIMES CAN RUN BELOW 60 FPS
			if(fps >= 0   && fps < 75){		addTime = addTime*3;}
			if(fps >= 75  && fps < 150){	addTime = addTime*2;}

			//USED ON WINDOWS, NORMAL FRAME RATE BETWEEN 200 AND 250 FPS
			if(fps >= 150  && fps < 300){	addTime = addTime;}

			//USED ON V-SYNC DISABLED BUILDS LIKE THE 4.0 ALPHA OR MINIS, TO ADJUST FOR 300+ FPS
			if(fps >= 300 && fps < 450){	addTime = addTime/2;}
			if(fps >= 450 && fps < 600){	addTime = addTime/3;}
			if(fps >= 600 && fps < 750){	addTime = addTime/4;}
			if(fps >= 750){					addTime = addTime/5;}

			//USED TO REDUCE ALL RATES DURING SLOWMOTION
			if(openborvariant("slowmotion")){addTime = addTime/2;okRate = okRate*2;barRate = barRate*2;}

			//USED TO START THE VARIABLES ONLY
			if(getglobalvar("okBar"+player) == NULL()){setglobalvar("okBar"+player, 0);}
			if(getglobalvar("okLv"+player) == NULL()){setglobalvar("okLv"+player, "");}

			//USED WHEN ANY SPECIAL IS PERFORMED WITH "HEALSTART" VARIABLE, RESTORE THE HEALTH LOST WHEN NECESSARY
			if(getglobalvar("heal"+player) == 1){
				if(getglobalvar("noRecover"+player) == NULL()){ //USED TO AVOID LIFE RESTORATION WHEN THE HEALTH IS ALREADY LOWER THAN THE COST
					changeentityproperty(player, "health", health+(getglobalvar("okBar"+player)*10)); //RESTORE THE LIFE LOST INSTANTLY
				}
				setglobalvar("noRecover"+player, NULL()); //RESET THE "NO RECOVER" FLAG
				setglobalvar("okBar"+player, 0); //RESET THE "OK" BAR
				setglobalvar("heal"+player, 0); //ALL NECESSARY VARIABLES ARE SAVED?? FINISH THIS STEP
			}

			//USED DURING "OK" BAR RECOVERY TASK
			if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
				if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF THE GAME IS IN EXTRA/PARTNER MENUS
					if(getglobalvar("okBar"+player) < 4){ //CHECK IF THE "OK" BAR IS NOT FULL
						if((time/okRate)%2 == 0){ //USED TO ADJUST THE RECOVERY RATE ACCORDING TO THE DEFINED RATE
							setglobalvar("okBar"+player, getglobalvar("okBar"+player)+addTime); //INCREASE POINTS DURING THE DEFINED RATE
						}
					}
				}
			}

			//USED TO DRAW THE "OK" BAR
			if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
				if(type == openborconstant("TYPE_PLAYER")){ //USED ONLY FOR PLAYER TYPE, AVOID CPU PARTNER
					if(health >= 1){ //PLAYER IS ALIVE??
						void okLv = getglobalvar("okLv"+player);

						//DEFINE THE SPRITE TO BE USED
						if(getglobalvar("okBar"+player) < 1){setglobalvar("okLv"+player, "");setglobalvar("blinkOk"+player, NULL());}else
						if(getglobalvar("okBar"+player) < 2 && getglobalvar("okBar"+player) >= 1){setglobalvar("okLv"+player, "A");}else
						if(getglobalvar("okBar"+player) < 3 && getglobalvar("okBar"+player) >= 2){setglobalvar("okLv"+player, "B");}else
						if(getglobalvar("okBar"+player) < 4 && getglobalvar("okBar"+player) >= 3){setglobalvar("okLv"+player, "C");}else

						//"OK" BAR IS FULL?? DRAW ALL NECESSARY CONTENT
						if(getglobalvar("okBar"+player) >= 4){
							if(getglobalvar("blinkOk"+player) == NULL()){setglobalvar("blinkOk"+player, time+barRate);}

							//ALTERNATE BETWEEN ALL SPRITES WHEN THE "OK" BAR IS FULL
							if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF THE GAME IS IN EXTRA/PARTNER MENUS
								if(time > getglobalvar("blinkOk"+player)){
									if(okLv == "C"){setglobalvar("okLv"+player, "D");}else
									if(okLv == "D"){setglobalvar("okLv"+player, "a");}else
									if(okLv == "a"){setglobalvar("okLv"+player, "b");}else
									if(okLv == "b"){setglobalvar("okLv"+player, "c");}else
									if(okLv == "c"){setglobalvar("okLv"+player, "d");}else
									if(okLv == "d"){setglobalvar("okLv"+player, "a");}
									setglobalvar("blinkOk"+player, time+barRate);
								}

								//"OK" WORD BLINKING RATE
								if((time/okRate)%2 == 0){
									drawstring(xPos+xAdd, yPos, font0, "OK", layer);
								}
							}
							else
							{
								//"OK" WORD WITH NO BLINKING
								drawstring(xPos+xAdd, yPos, font0, "OK", layer);
							}
						}

						//DRAW "OK" BAR IN THE SCREEN
						drawstring(xPos+xAdd, yPos+yAdd, font1, okLv, layer);
					}
					else
					{
						//RESET THE "OK" BAR
						setglobalvar("okBar"+player, 0);
					}
				}
			}
		}
	}
}
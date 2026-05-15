void superArmor()
{//Turn on/off "superArmor" properties according to global variables
	void self = getlocalvar("self");

	if(openborvariant("current_branch") != "sor3_st7d"){
		void target	 = getentityproperty(self,"opponent");
		void grab 	 = getentityproperty(self,"grabbing");
		if(target != NULL()) {
			void grabbed = getentityproperty(target,"grabbing");
			int maxGp	 = getentityproperty(self,"maxguardpoints");
			int gp		 = getentityproperty(self,"guardpoints");
			int height	 = getentityproperty(self,"y");
			int base	 = getentityproperty(self,"base");
			int seal 	 = getentityproperty(self,"seal");
			int noPain 	 = getentityproperty(self,"nopain");
			float def;

			if(gp >= maxGp && grab == NULL() && grabbed != self && height == base && seal == 0){
				if(noPain != 1){ // in pain
					def = 1.5;
					changeentityproperty(self, "nopain", 1);
					changeentityproperty(self, "weaploss", 0);
					changeentityproperty(self, "defense", 0, def);
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL2"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL6"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_BURN"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_SHOCK"), def); //Set defense.
				}
			}else{
				if(noPain != 0){ // in no pain
					def = 1;
					changeentityproperty(self, "nopain", 0);
					changeentityproperty(self, "weaploss", 0);
					changeentityproperty(self, "defense", 0, def);
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL2"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_NORMAL6"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_BURN"), def); //Set defense.
					changeentityproperty(self, "defense", openborconstant("ATK_SHOCK"), def); //Set defense.
				}
			}
		}
	}
}

void jumpVel()
{//Change X/Z velocity/flip if defined button is pressed during jump animations (SOR2X/SOR3/SOR2/SOR1 JUMP TYPES)
 //Works for default JUMP/JUMPATTACK animations only, do not use it for dodges because it uses scripted jumps
	void self 	= getlocalvar("self");
	void jumpT 	= getglobalvar("jumpType"); //Get jump type option.
	void type 	= getentityproperty(self,"type");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");

	if(type == openborconstant("TYPE_PLAYER")){ //WORKS FOR PLAYERS ONLY

		//SOR3 TYPE
		//ENABLE OR DISABLE SPEED CONTROL IN X AXIS DURING JUMP ANIMATION
		//USED TO AVOID UGLY EFFECT IN DEFAULT ENGINE COMMAND JUMPMOVE IN CHAR HEADER THAT CHANGES X SPEED TOO MUCH ABRUPTLY
		if(jumpT == "sor3" || jumpT == "sor2x+sor3" || jumpT == "sor1+sor3" || jumpT == "all_types"){ //SOR3 JUMP TYPE IS ACTVATED??
			if(	vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF") || vAniID == openborconstant("ANI_JUMPATTACK")||
				vAniID == openborconstant("ANI_JUMPATTACK2") || vAniID == openborconstant("ANI_JUMPATTACK3") || vAniID == openborconstant("ANI_JUMPFORWARD")){
				float jumpS	= getentityproperty(self,"jumpspeed");
				float xDir 	= getentityproperty(self,"xdir");
				float xAdd 	= 0.04;

				if(playerkeys(iPIndex, 0, "moveleft")){ //LEFT IS PRESSED?
					if(xDir > -jumpS){xDir = xDir-xAdd;}
				}
				else
				if(playerkeys(iPIndex, 0, "moveright")){ //RIGHT IS PRESSED?
					if(xDir < jumpS){xDir = xDir+xAdd;}
				}

				changeentityproperty(self, "velocity", xDir, NULL(), NULL()); //CHANGE VELOCITY
			}
		}

		//SOR2X TYPE
		//CHANGE SPEED IN Z AXIS DURING JUMP ANIMATION BASED ON THE LAST MOMENT SAVED IN WALK OR RUN ANIMATIONS
		//USED TO AVOID BUG IN SCRIPTED JUMPMOVEZ COMMAND, THAT NOT ALLOW TO CHANGE Z MOVEMENT LIKE THE SAME COMMAND IN CHAR HEADER
		//USED TO AVOID BUG IN SCRIPTED JUMPMOVEX COMMAND, THAT NOT ALLOW TO CHANGE X FLIP LIKE THE SAME COMMAND IN CHAR HEADER
		if(jumpT == "sor2x" || jumpT == "sor2x+sor1" || jumpT == "sor2x+sor3" || jumpT == "all_types"){ //SOR2X JUMP TYPE IS ACTVATED??

			//SAVE THE LAST ZDIR SPEED
			if(	vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_BACKWALK")||
				vAniID == openborconstant("ANI_UP")   || vAniID == openborconstant("ANI_DOWN")||
				vAniID == openborconstant("ANI_RUN")){
				setlocalvar("zVel"+self, getentityproperty(self,"zdir"));
			}

			//APPLY THE LAST ZDIR SPEED AND RESET IT TO ZERO
			if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_WALKOFF")){
				float zVel = getlocalvar("zVel"+self);

				if(zVel != 0){
					changeentityproperty(self, "velocity", NULL(), zVel, NULL()); //CHANGE VELOCITY
					setlocalvar("zVel"+self, 0);
				}
			}

			//RESET ZDIR SPEED TO ZERO IN ANY OTHER ANIMATION
			if(	vAniID != openborconstant("ANI_WALK") && vAniID != openborconstant("ANI_BACKWALK")&&
				vAniID != openborconstant("ANI_UP")   && vAniID != openborconstant("ANI_DOWN")&&
				vAniID != openborconstant("ANI_RUN")  && vAniID != openborconstant("ANI_JUMPDELAY")&&
				vAniID != openborconstant("ANI_JUMP") && vAniID != openborconstant("ANI_WALKOFF")){
				setlocalvar("zVel"+self, 0);
			}
		}

		//SOR2 TYPE
		//ENABLE THE "BACKWARD" JUMP GLITCH IN X AXIS, SAME AS THE ORIGINAL SOR2
		if(jumpT == "sor2"){ //SOR2 JUMP TYPE IS ACTVATED??

			//SAVE THE DIRECTION/VELOCITY VALUES
			if(vAniID == openborconstant("ANI_JUMPDELAY")){
				int direction	= getentityproperty(self,"direction");
				float jumpS		= getentityproperty(self,"jumpspeed");

				if(direction == 1 && playerkeys(iPIndex, 0, "moveleft")){ //RIGHT FACING AND LEFT IS PRESSED?
					setlocalvar("flipDir"+self, 1);
					setlocalvar("xVel"+self, -jumpS);
				}
				else
				if(direction == 0 && playerkeys(iPIndex, 0, "moveright")){ //LEFT FACING AND RIGHT IS PRESSED?
					setlocalvar("flipDir"+self, 0);
					setlocalvar("xVel"+self, jumpS);
				}
			}

			//APPLY THE DIRECTION/VELOCITY VALUES AND RESET ALL VARIABLES TO NULL
			if(vAniID == openborconstant("ANI_JUMP")){
				int flipDir = getlocalvar("flipDir"+self);
				float xVel 	= getlocalvar("xVel"+self);

				if(flipDir != NULL()){
					changeentityproperty(self, "direction", flipDir); //CHANGE DIRECTION
					changeentityproperty(self, "velocity", xVel, NULL(), NULL()); //CHANGE VELOCITY
					setlocalvar("flipDir"+self, NULL());
					setlocalvar("xVel"+self, NULL());
				}
			}

			//RESET THE DIRECTION/VELOCITY VARIABLES TO NULL IN ANY OTHER ANIMATION
			if(vAniID != openborconstant("ANI_JUMPDELAY")){
				setlocalvar("flipDir"+self, NULL());
				setlocalvar("xVel"+self, NULL());
			}
		}

		//SOR1 TYPE
		//ENABLE JUMP FLIP IN X AXIS
		if(jumpT == "sor1" || jumpT == "sor2x+sor1" || jumpT == "sor1+sor3" || jumpT == "all_types"){ //SOR1 JUMP TYPE IS ACTVATED??
			changeentityproperty(self, "jumpmovez", 1); //ENABLE X FLIP
		}else{
			changeentityproperty(self, "jumpmovez", 0); //DISABLE X FLIP
		}
	}
}

void grabIdle(void ani, int type)
{//Set to idle if no entity is being grabbed
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	void vAniID = getentityproperty(self, "animationID");

	if(vAniID == openborconstant(ani)){
		if(type == 0){ //GROUND TYPE RESET
			if(target == NULL()){
				setidle(self);
			}
		}

		if(type == 1){ //JUMPING TYPE RESET
			if(target == NULL()){
				changeentityproperty(self, "takeaction", "common_jump");
				changeentityproperty(self, "aiflag", "jumping", 1);
			}
		}
	}
}

void quakeDetect(void ani1, void ani2)
{//Detect "QuakeHigh" global variable and change animation
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");

	if(getglobalvar("quakeOn") != NULL()){
		if(ani == openborconstant(ani1)){
			changeentityproperty(self, "animation", openborconstant(ani2));
		}
	}
}

void flyUp(void ani)
{//Pull up with correct animation if on the ground
	void self 	= getlocalvar("self");
	void vAni  	= getentityproperty(self,"animationID");
	int height	= getentityproperty(self,"y");

	if(height <= 0){
		if(	vAni == openborconstant("ANI_IDLE")||
			vAni == openborconstant("ANI_WALK")||
			vAni == openborconstant("ANI_BACKWALK")||
			vAni == openborconstant("ANI_RUN")){
			executeanimation(self, openborconstant(ani), 1);
		}
	}
}

void motorBike(void modelName)
{//Change model to Motor Bike type in Bike Stage
	void self  = getlocalvar("self");
	void model = getentityproperty(self, "model");

	if(openborvariant("current_branch") == "sor3_st7d"){
		if(model != modelName){changeentityproperty(self, "model", modelName, 1);}
	}
}

void drawLife()
{//Draw life bar in the screen, entity binded like RPG games
	void self = getlocalvar("self");

	if(openborvariant("in_level")){ //IN ANY LEVEL??
		int maxLife	= getentityproperty(self, "maxhealth");
		int life 	= getentityproperty(self, "health");
		int x 		= getentityproperty(self, "x");
		int y 		= getentityproperty(self, "y");
		int z 		= getentityproperty(self, "z");
		float xPos 	= openborvariant("xpos");
		float yPos 	= openborvariant("ypos");
		float xSize	= 20; //BAR WIDTH INCREASE FACTOR, MORE VALUE IS MORE SIZE
		float ySize	= 2; //BAR HEIGHT INCREASE FACTOR, MORE VALUE IS MORE SIZE
		float xDif	= 0; //BAR POSITION IN X AXIS, USE THIS TO MOVE ALL BARS TOGETHER
		float yDif	= 0; //BAR POSITION IN Y AXIS, USE THIS TO MOVE ALL BARS TOGETHER
		float greenXdif;

		if(life > 0){ //ENTITY IS ALIVE??
			greenXdif 	= (getglobalvar("greenXdif"+self)*xSize)/(maxLife); //CALCULATE REMAINING LIFE TO BE HEALED
			life 		= (life*xSize)/(maxLife); //CALCULATE REMAINING LIFE BAR SIZE
			maxLife		= (maxLife*xSize)/(maxLife); //CALCULATE MAX LIFE BAR SIZE
			x 			= x-xPos-(maxLife/2)+xDif; //CALCULATE X POSITION TO BIND BAR IN THE ENTITY, OFFSET IS ALWAYS THE CENTER
			y 			= z-yPos-y+yDif; //CALCULATE Y POSITION TO BIND BAR IN THE ENTITY
			drawbox(x, y, life, ySize, z+3, rgbcolor(0xFF,0xFF,0x00), 0); //YELLOW BAR, LIFE REMAINING
			drawbox(x, y, maxLife, ySize, z+1, rgbcolor(0xFF,0x00,0x00), 0); //RED BAR, LIFE LOST
			drawbox(x, y-1, maxLife, ySize*2, z, rgbcolor(0xFF,0xFF,0xFF), 0); //WHITE BORDER (UP/DOWN)
			drawbox(x-1, y, maxLife+2, ySize, z, rgbcolor(0xFF,0xFF,0xFF), 0); //WHITE BORDER (LEFT/RIGHT)

			if(getglobalvar("specialCost") == "sor4_recovery_(time)" || getglobalvar("specialCost") == "sor4_recovery_(hits)"){
				if(getglobalvar("addLife"+self) > 0){
					drawbox(x, y, greenXdif, ySize, z+2, rgbcolor(0x00,0xEE,0x00), 0); //GREEN BAR, HEAL IN PROGRESS
				}
			}
		}
	}
}

void parrow()
{//Draw custom parrow in the screen, entity binded like RPG games
	void self = getlocalvar("self");
	void type = getentityproperty(self, "type");

	if(getglobalvar("playerArrow") == "on"){
		if(openborvariant("in_level")){
			if(type == openborconstant("TYPE_PLAYER")){
				void cursor;
				int player 	= getentityproperty(self, "playerindex");
				int life 	= getentityproperty(self, "health");
				int x 		= getentityproperty(self, "x");
				int y 		= getentityproperty(self, "y");
				int z 		= getentityproperty(self, "z");
				int blink 	= getentityproperty(self, "blink");
				int height 	= getentityproperty(self, "height");
				int xDif	= 4;
				int yDif	= 20;
				int font	= 9;
				int layer	= 1001;
				float xPos 	= openborvariant("xpos");
				float yPos 	= openborvariant("ypos");

				if(player == 0){cursor = "E";}
				if(player == 1){cursor = "F";}
				if(player == 2){cursor = "G";}
				if(player == 3){cursor = "H";}

				if(life > 0){ //ENTITY IS ALIVE??
					if(blink != 1){ //USED TO NOT SHOW BOTH MINI PARROW AND NORMAL PARROW TOGETHER WHEN PLAYER IS BLINKING
						x = x-xPos-xDif; //CALCULATE X POSITION TO BIND PARROW IN THE ENTITY, OFFSET IS ALWAYS THE CENTER
						y = z-yPos-y-height-yDif; //CALCULATE Y POSITION TO BIND PARROW IN THE ENTITY
						drawstring(x, y, font, cursor, layer); //DRAW PARROW
					}
				}
			}
		}
	}
}

void parrowPartner()
{//Draw custom parrow in the screen for NPC PARTNERS, entity binded like RPG games
	void self  = getlocalvar("self");
	float time = openborvariant("elapsed_time");

	if(openborvariant("in_level")){ //IN ANY LEVEL??
		void cursor	= "O";
		int blink 	= getentityproperty(self, "blink");
		int life 	= getentityproperty(self, "health");
		int x 		= getentityproperty(self, "x");
		int y 		= getentityproperty(self, "y");
		int z 		= getentityproperty(self, "z");
		int height 	= getentityproperty(self, "height");
		float xPos 	= openborvariant("xpos");
		float yPos 	= openborvariant("ypos");

		if(getglobalvar("partnerParrow") == "call" && blink == 0){ //PARTNER CALL BUTTON IS HELD??
			int xDif	= 4;
			int yDif	= 20;
			int font0	= 0;
			int font1	= 9;

			if(life > 0){ //ENTITY IS ALIVE??
				x 		= x-xPos-xDif; //CALCULATE X POSITION TO BIND PARROW IN THE ENTITY, OFFSET IS ALWAYS THE CENTER
				y 		= z-yPos-y-height-yDif; //CALCULATE Y POSITION TO BIND PARROW IN THE ENTITY
				drawstring(x-12, y-10, font0, "call", z); //DRAW CALL MESSAGE
				drawstring(x, y, font1, cursor, z); //DRAW PARROW
			}
		}

		if(life > 0 && blink == 1){ //PARTNER IS RESPAWNED??
			int xDif = 15;
			int yDif = 140;

			setdrawmethod(NULL(),0,256,256,0,0,0,0);
			x = x-xPos-xDif; //CALCULATE X POSITION TO BIND PARROW IN THE ENTITY, OFFSET IS ALWAYS THE CENTER
			y = z-yPos-y-yDif; //CALCULATE Y POSITION TO BIND PARROW IN THE ENTITY
			drawsprite(getglobalvar("parrow5"), x, y, z); //DRAW PARROW
		}
	}
}

void debugMode()
{//Draw some entity info in the screen when debug mode 1 or 2 are activated
	void self = getlocalvar("self");
	int debug = getglobalvar("debugMode");

	if(debug == 1 || debug == 2){ //IS DEBUG MODE 1 OR 2 ACTIVATED??
		float x 	= getentityproperty(self, "x");
		float y 	= getentityproperty(self, "y");
		float z 	= getentityproperty(self, "z");
		float h 	= getentityproperty(self, "height");
		float xPos  = openborvariant("xpos");
		float yPos  = openborvariant("ypos");
		int hp 		= getentityproperty(self, "health");
		int mp 		= getentityproperty(self, "mp");
		int gp 		= getentityproperty(self, "guardpoints");
		int jp 		= getentityproperty(self, "jugglepoints");
		int op 		= getentityvar(self, "otgpoints");
		int pw 		= getentityproperty(self, "offense", 0);
		int df 		= getentityproperty(self, "defense", 0);
		int sp 		= getentityproperty(self, "speed");
		int ju 		= getentityproperty(self, "jumpheight");
		int en 		= getentityproperty(self, "mprate");
		int ag 		= getentityproperty(self, "aggression");
		int font0	= 0;
		int font1	= 1;
		int xDif	= 26;
		int yDif	= -100;
		int yAdd	= 10;
		int layer	= 1001;

		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "HP, MP:_", layer);
		drawstring(x-xPos-xDif+strwidth("HP, MP:_", 0), z-y-h-yPos+yDif, font0, ""+hp+", "+mp, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "GP, JP, OP:_", layer);
		drawstring(x-xPos-xDif+strwidth("GP, JP, OP:_", 0), z-y-h-yPos+yDif, font0, ""+gp+", "+jp+", "+op, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "PW:_", layer);
		drawstring(x-xPos-xDif+strwidth("PW:_", 0), z-y-h-yPos+yDif, font0, pw, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "DF:_", layer);
		drawstring(x-xPos-xDif+strwidth("DF:_", 0), z-y-h-yPos+yDif, font0, df, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "SP:_", layer);
		drawstring(x-xPos-xDif+strwidth("SP:_", 0), z-y-h-yPos+yDif, font0, sp, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "JU:_", layer);
		drawstring(x-xPos-xDif+strwidth("JU:_", 0), z-y-h-yPos+yDif, font0, ju, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "EN:_", layer);
		drawstring(x-xPos-xDif+strwidth("EN:_", 0), z-y-h-yPos+yDif, font0, en, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "AG:_", layer);
		drawstring(x-xPos-xDif+strwidth("AG:_", 0), z-y-h-yPos+yDif, font0, ag, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "X:_", layer);
		drawstring(x-xPos-xDif+strwidth("X:_", 0), z-y-h-yPos+yDif, font0, x, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "Y:_", layer);
		drawstring(x-xPos-xDif+strwidth("X:_", 0), z-y-h-yPos+yDif, font0, y, layer);
		yDif = yDif+yAdd;
		drawstring(x-xPos-xDif, z-y-h-yPos+yDif, font1, "Z:_", layer);
		drawstring(x-xPos-xDif+strwidth("Z:_", 0), z-y-h-yPos+yDif, font0, z, layer);
	}
}

void subTarget()
{//Change subtype to none is no hostile target is found
	void self   = getlocalvar("self");
	void target = findtarget(self);
	int bbox 	= getentityproperty(target, "vulnerable");

	if(target == NULL()){
		changeentityproperty(self, "subtype", openborconstant("SUBTYPE_NONE"));
	}

	if(target != NULL()){
		if(bbox == 0){
			changeentityproperty(self, "subtype", openborconstant("SUBTYPE_NONE"));
		}else{
			changeentityproperty(self, "subtype", openborconstant("SUBTYPE_CHASE"));
		}
	}
}
void main()
{//Change animation if defined entity is "inpain" status
	void self		= getlocalvar("self");
	void anim		= getentityproperty(self, "animationID");
	float xPos		= openborvariant("xpos");
	int eCount		= openborvariant("count_enemies");
	int eLimit		= 4;
	int side		= getglobalvar("st6_side");
	int floor		= getglobalvar("st6_floor");
	int topFloor	= 3;
	int bottomFloor	= 0;
	int addFloor	= 1;

	//WORK ACCORDING TO THE ENEMY COUNT
	if(eCount <= eLimit){
		
		//MOVE THE ELEVATOR ONLY DURING THE IDLE ANIMATION
		if(anim == openborconstant("ANI_IDLE")){
			void panelDownA	= getentityvar(self, "panelDownA");
			void panelDownB	= getentityvar(self, "panelDownB");
			void panelUpA	= getentityvar(self, "panelUpA");
			void panelUpB	= getentityvar(self, "panelUpB");
			int painDownA	= getentityproperty(panelDownA, "aiflag", "inpain");
			int painDownB	= getentityproperty(panelDownB, "aiflag", "inpain");
			int painUpA		= getentityproperty(panelUpA, "aiflag", "inpain");
			int painUpB		= getentityproperty(panelUpB, "aiflag", "inpain");
			int wallId		= 2;
			int wallOn		= 278;
			int wallOff		= 9999;
			float leftOn	= 0;
			float rightOn	= 2494;

			//DID YOU NOT REACHED TO THE BOTTOM FLOOR YET?? MOVE EVEVATOR DOWN
			if(floor > bottomFloor){

				//DID YOU HIT THE PANEL AT THE SIDE A?? CONTINUE
				if(painDownA && xPos <= leftOn){

					//DISABLE THE CENTER WALL WHILE NOT IN THE BOTTOM FLOOR
					if(floor == bottomFloor+1){changelevelproperty("wall", wallId, "z", wallOff);}

					//EXECUTE ALL TASKS
					changelevelproperty("scrollspeed", 0);
					setglobalvar("lockScroll", 1); //TELL THE GAME THAT THE SCREEN SCROLLING IS NOT ALLOWED, USED FOR PARTNERS
					setglobalvar("st6_side", "a");
					setglobalvar("st6_floor", floor-addFloor);
					executeanimation(self, openborconstant("ANI_FOLLOW1"));
				}

				//DID YOU HIT THE PANEL AT THE SIDE B?? CONTINUE
				if(painDownB && xPos >= rightOn){

					//DISABLE THE CENTER WALL WHILE NOT IN THE BOTTOM FLOOR
					if(floor == bottomFloor+1){changelevelproperty("wall", wallId, "z", wallOff);}

					//EXECUTE ALL TASKS
					changelevelproperty("scrollspeed", 0);
					setglobalvar("lockScroll", 1); //TELL THE GAME THAT THE SCREEN SCROLLING IS NOT ALLOWED, USED FOR PARTNERS
					setglobalvar("st6_side", "b");
					setglobalvar("st6_floor", floor-addFloor);
					executeanimation(self, openborconstant("ANI_FOLLOW1"));
				}
			}

			//DID YOU NOT REACHED TO THE TOP FLOOR YET?? MOVE EVEVATOR UP
			if(floor < topFloor){

				//DID YOU HIT THE PANEL AT THE SIDE A?? CONTINUE
				if(painUpA && xPos <= leftOn){

					//ENABLE THE CENTER WALL WHILE NOT IN THE BOTTOM FLOOR
					if(floor == bottomFloor){changelevelproperty("wall", wallId, "z", wallOn);}

					//EXECUTE ALL TASKS
					changelevelproperty("scrollspeed", 0);
					setglobalvar("lockScroll", 1); //TELL THE GAME THAT THE SCREEN SCROLLING IS NOT ALLOWED, USED FOR PARTNERS
					setglobalvar("st6_side", "a");
					setglobalvar("st6_floor", floor+addFloor);
					executeanimation(self, openborconstant("ANI_FOLLOW2"));
				}

				//DID YOU HIT THE PANEL AT THE SIDE B?? CONTINUE
				if(painUpB && xPos >= rightOn){

					//ENABLE THE CENTER WALL WHILE NOT IN THE BOTTOM FLOOR
					if(floor == bottomFloor){changelevelproperty("wall", wallId, "z", wallOn);}

					//EXECUTE ALL TASKS
					changelevelproperty("scrollspeed", 0);
					setglobalvar("lockScroll", 1); //TELL THE GAME THAT THE SCREEN SCROLLING IS NOT ALLOWED, USED FOR PARTNERS
					setglobalvar("st6_side", "b");
					setglobalvar("st6_floor", floor+addFloor);
					executeanimation(self, openborconstant("ANI_FOLLOW2"));
				}
			}
		}
	}

	if(anim == openborconstant("ANI_FOLLOW1") || anim == openborconstant("ANI_FOLLOW2")){setglobalvar("st6_zpos", getentityproperty(self, "z"));}
	
	//LOCK CAMERA MOVEMENT WHILE NEAR THE CENTER WALL
	float xLockA = 897;
	float xLockB = 1597;

	//CHECK IF YOU ARE NOT IN THE BOTTOM FLOOR
	if(floor > bottomFloor){
		if(side == "a"){
			if(xPos >= xLockA){changeopenborvariant("xpos", xLockA);}
		}
		if(side == "b"){
			if(xPos <= xLockB){changeopenborvariant("xpos", xLockB);}
		}
	}
}
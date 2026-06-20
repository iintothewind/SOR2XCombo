void main()
{//Change animation with enemy count and defined conditions
	void self		= getlocalvar("self");
	void vName		= getentityproperty(self, "name");
	void anim		= getentityproperty(self, "animationID");
	float x			= getentityproperty(self, "x");
	float z			= getentityproperty(self, "z");
	float xPos		= openborvariant("xpos");
	float hRes		= openborvariant("hresolution");
	int eCount		= openborvariant("count_enemies");
	int side		= getglobalvar("st6_side");
	int floor		= getglobalvar("st6_floor");
	int maxLocks	= 3;
	int eLimit1		= 4;
	int eLimit2		= 7;
	int dist		= 50;

	//NO ENEMY ON THE SCREEN?? EXECUTE ALL TASKS
	if(eCount <= eLimit1){

		//CHECK THE REQUIRED ANIMATION BEFORE OPEN ANY DOOR
		if(anim == openborconstant("ANI_IDLE")){

			//CHECK IF THE DOORS ARE VISIBLE ON THE SCREEN
			if(x > (xPos+dist) && x < ((xPos+hRes)-dist)){

				//ELEVATOR SIDE A
				if(side == "a"){

					//COMPUTER ROOM 1 AND NORMAL ROOM 2
					if(floor == 2){
						if(vName == "Room1"){
							if(getglobalvar("st6_room1") == NULL()){
								setlocalvar("xReset"+self, x);
								setlocalvar("zReset"+self, z);
								changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
							}
						}
						if(vName == "Room2"){
							setlocalvar("xReset"+self, x);
							setlocalvar("zReset"+self, z);
							changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
						}
					}

					//COMPUTER ROOM 3 AND NORMAL ROOM 4
					if(floor == 1){
						if(vName == "Room3"){
							if(getglobalvar("st6_room3") == NULL()){
								setlocalvar("xReset"+self, x);
								setlocalvar("zReset"+self, z);
								changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
							}
						}
						if(vName == "Room4"){
							setlocalvar("xReset"+self, x);
							setlocalvar("zReset"+self, z);
							changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
						}
					}
				}

				//ELEVATOR SIDE B
				if(side == "b"){

					//COMPUTER ROOM 5 AND NORMAL ROOM 6
					if(floor == 1){
						if(vName == "Room5"){
							if(getglobalvar("st6_room5") == NULL()){
								setlocalvar("xReset"+self, x);
								setlocalvar("zReset"+self, z);
								changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
							}
						}
						if(vName == "Room6"){
							setlocalvar("xReset"+self, x);
							setlocalvar("zReset"+self, z);
							changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
						}
					}

					//NORMAL ROOM 7
					if(floor == 2){
						if(vName == "Room7"){
							setlocalvar("xReset"+self, x);
							setlocalvar("zReset"+self, z);
							changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
						}
					}

					//EXIT DOOR
					if(floor == 3){
						if(vName == "Exit"){
							if(getglobalvar("st6_locks") >= maxLocks){
								setlocalvar("xReset"+self, x);
								setlocalvar("zReset"+self, z);
								changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
							}
						}
					}
				}
			}
		}
	}

	//THERE ARE ENEMIES ON THE SCREEN?? EXECUTE ALL TASKS
	if(eCount > eLimit1 || getglobalvar("gasEnable") == 1){

		//CHANGED THE FLOOR?? CLOSE ALL DOORS AGAIN
		if(anim == openborconstant("ANI_FOLLOW1")){
			int xReset = getlocalvar("xReset"+self);
			int zReset = getlocalvar("zReset"+self);

			//ELEVATOR SIDE A
			if(side == "a"){

				//COMPUTER ROOM 1 AND NORMAL ROOM 2
				if(floor != 2){
					if(vName == "Room1"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
					if(vName == "Room2"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
				}

				//COMPUTER ROOM 1 AND NORMAL ROOM 4
				if(floor != 1){
					if(vName == "Room3"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
					if(vName == "Room4"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
				}
			}

			//ELEVATOR SIDE B
			if(side == "b"){

				//COMPUTER ROOM 5 AND NORMAL ROOM 6
				if(floor != 1){
					if(vName == "Room5"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
					if(vName == "Room6"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
				}

				//NORMAL ROOM 7
				if(floor != 2){
					if(vName == "Room7"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
				}

				//EXIT DOOR
				if(floor != 3){
					if(vName == "Exit"){
						changeentityproperty(self, "position", xReset, zReset);
						changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
					}
				}
			}

			//ELEVATOR BASEMENT
			if(floor != 0){
				if(vName == "Gate"){
					changeentityproperty(self, "position", xReset, zReset);
					changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
				}
			}
		}
	}

	//USED ONLY FOR THE BASEMENT FLOOR
	if(getglobalvar("gasEnable") != 1){
		if(eCount <= eLimit2){

			//CHECK THE REQUIRED ANIMATION BEFORE OPEN ANY DOOR
			if(vName == "Gate"){
				if(anim == openborconstant("ANI_IDLE")){

					//CHECK IF THE DOORS ARE VISIBLE ON THE SCREEN
					if(x > (xPos+dist) && x < ((xPos+hRes)-dist)){

						//ELEVATOR BASEMENT
						if(floor == 0){
							setlocalvar("xReset"+self, x);
							setlocalvar("zReset"+self, z);
							changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
						}
					}
				}
			}
		}
	}
}
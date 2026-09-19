void route()
{//Change "branch" global variable according to current branch
 //Used to define the next level in ondraw.c for route "arrow" entity
	void self   = getlocalvar("self");
	void plat 	= getlocalvar("platform");
	void branch = openborvariant("current_branch");
	void pName  = getentityproperty(plat, "defaultname");
	void type  	= getentityproperty(self, "type");
	int iPIndex = getentityproperty(self, "playerindex");
	int set 	= openborvariant("current_set");

	if(type == openborconstant("TYPE_PLAYER")){
		if(getglobalvar("activeText") == 0){ //CHECK IF EXTRA MENU IS ON
			if(getglobalvar("routeConfirm") == NULL()){ //ALWAYS START THE ROUTE CONFIRMATION VARIABLE TO "NO"
				setglobalvar("routeConfirm", "no");
			}

			//START ROUTE
			if(branch == "route"){
				if(pName == "Route_Left"){ //STREETS A
					if(playerkeys(iPIndex, 0, "moveleft")){
						detectRoute(pName, "sor2_st1a", "sor2_label");
					}
				}
				else
				if(pName == "Route_Right"){ //SEAPORT STORAGE
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor3_st1a", "sor3_label");
					}
				}
				else
				if(pName == "Route_Down"){ //SOR1 Street
					if(playerkeys(iPIndex, 0, "movedown")){
						detectRoute(pName, "sor1_st01", "sor1sms_label");
					}
				}
			}

			//SOR3 STREETS
			if(branch == "sor3_st2a"){
				if(pName == "Route_Down"){ //DANCE CLUB
					if(playerkeys(iPIndex, 0, "movedown")){
						detectRoute(pName, "sor3_st2b", "sor3_label");
					}
				}
				else
				if(pName == "Route_Right"){ //TRUCK
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor2_st2b", "sor2_label");
					}
				}
			}

			//SOR2 ARCADE
			if(branch == "sor2_st3b"){
				if(pName == "Route_Up"){ //PIRATES 1F
					if(playerkeys(iPIndex, 0, "moveup")){
						detectRoute(pName, "sor2_st3c", "sor2_label");
					}
				}
				else
				if(pName == "Route_Right"){ //BULLDOZER
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor3_st3b", "sor3_label");
					}
				}
			}

			//SOR2 ALIEN CAVE ENTRANCE
			if(branch == "sor2_st3f"){
				if(pName == "Route_Up"){ //LAVA BRIDGE
					if(playerkeys(iPIndex, 0, "moveup")){
						detectRoute(pName, "sor2_st3h", "sor2GG_label");
					}
				}
				else
				if(pName == "Route_Right"){ //ALIEN CAVE ZAMZA
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor2_st3g", "sor2_label");
					}
				}
			}

			//SOR3 SAMURAI TEMPLE
			if(branch == "sor3_st4c"){
				if(pName == "Route_Up"){ //SHIP FLOOR B2
					if(playerkeys(iPIndex, 0, "moveup")){
						detectRoute(pName, "sor3_st5a", "sor3_label");
					}
				}
				else
				if(pName == "Route_Right"){ //TEMPLE ROOM A
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor2_st5a", "sor2_label");
					}
				}
			}

			//SOR2 ABANDONED ROAD
			if(branch == "sor2_st6b"){
				if(pName == "Route_Up"){ //INDUSTRY
					if(playerkeys(iPIndex, 0, "moveup")){
						detectRoute(pName, "sor2_st7a", "sor2_label");
					}
				}
				else
				if(pName == "Route_Right"){ //TO AVOID BIKE STAGE
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor3_st7e", "sor3_label");
					}
				}
			}

			//SOR2 INDUSTRY
			if(branch == "sor2_st7a"){
				if(pName == "Route_Right"){ //SOR2 INDUSTRY ELEVATOR
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor2_st7b", "sor2_label");
					}
				}
				else
				if(pName == "Route_Down"){ //SOR1 SMS INDUSTRY
					if(playerkeys(iPIndex, 0, "movedown")){
						detectRoute(pName, "sor2_st7c", "sor1SMS_label");
					}
				}
			}

			//SOR2 BUILDING ELEVATOR HALL
			if(branch == "sor2_st8a"){
				if(pName == "Route_Up"){ //BUILDING ELEVATOR SHIVA/MR.X
					if(playerkeys(iPIndex, 0, "moveup")){
						detectRoute(pName, "sor2_st8b", "sor2_label");
					}
				}
				else
				if(pName == "Route_Right"){ //FACTORY ELEVATOR
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor3_st8b", "sor3_label");
					}
				}
			}

			//SOR3 DR.ZERO LAB
			if(branch == "sor3_st8d"){
				if(pName == "Route_Left"){ //NEO.X ROOM
					if(playerkeys(iPIndex, 0, "moveleft")){
						detectRoute(pName, "sor3_st8e", "sor3_label");
					}
				}
				else
				if(pName == "Route_Right"){ //BUILDING ELEVATOR SHIVA/MR.X
					if(playerkeys(iPIndex, 0, "moveright")){
						detectRoute(pName, "sor2_st8b", "sor2_label");
					}
				}
			}
		}else{
			setglobalvar("pName", 0);
		}
	}
}

void detectRoute(void pName, void preview, void label)
{//Function used to reduce the code size
	if(getglobalvar("preview") != NULL()){free(getglobalvar("preview"));}
	if(getglobalvar("label") != NULL()){free(getglobalvar("label"));}

	setglobalvar("pName", pName);
	setglobalvar("branch", preview);
	setglobalvar("preview", loadsprite("data/bgs/route/"+preview+".png"));
	setglobalvar("label", loadsprite("data/bgs/route/"+label+".png"));
}

void platform()
{//Up or move to not stuck into platforms or non breakable obstacles (ALL STAGES)
	void self = getlocalvar("self");
	void plat = getlocalvar("platform");
	int pName = getentityproperty(plat, "defaultname");
	int x	  = getentityproperty(self, "x");
	int z	  = getentityproperty(self, "z");
	int xDir  = getentityproperty(self, "xdir");
	int zDir  = getentityproperty(self, "zdir");

	if(pName == "St1_Manhole"){
		tossentity(self, 0.001, xDir, zDir);
	}

	if(pName == "Wall"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x+30, z);
		}
	}

	if(pName == "Computer"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x-30, z);
		}
	}

	if(pName == "Route_Left"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x+10, z);
		}
	}

	if(pName == "Route_Right"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x-10, z);
		}
	}

	if(pName == "Route_Up"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x, z+10);
		}
	}

	if(pName == "Route_Down"){
		if(checkplatformbetween(x, z, 0, 1000)){
			changeentityproperty(self, "position", x, z-10);
		}
	}
}
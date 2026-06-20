void main()
{//Change "jumptobranch" command according to level and stage
	void self	= getlocalvar("self");
	void vName	= getentityproperty(self, "name");
	
	//ROOM 1 - COMPUTER
	if(vName == "Room1"){jumptobranch("sor3_st6b", 1);}
	
	//ROOM 2 - NORMAL
	if(vName == "Room2"){jumptobranch("sor3_st6c", 1);}
	
	//ROOM 3 - COMPUTER
	if(vName == "Room3"){jumptobranch("sor3_st6b", 1);}
	
	//ROOM 4 - NORMAL
	if(vName == "Room4"){jumptobranch("sor3_st6d", 1);}

	//ROOM 5 - COMPUTER
	if(vName == "Room5"){jumptobranch("sor3_st6b", 1);}

	//ROOM 6 - NORMAL
	if(vName == "Room6"){jumptobranch("sor3_st6e", 1);}

	//ROOM 7 - NORMAL
	if(vName == "Room7"){jumptobranch("sor3_st6f", 1);}

	//EXIT - ROOF JET
	if(vName == "Exit"){jumptobranch("sor3_st6g", 1);}
}
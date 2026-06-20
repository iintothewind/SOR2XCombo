void main()
{//Change "jumptobranch" command according to level and stage
	void self  = getlocalvar("self");
	void vName = getentityproperty(self, "defaultname");
	
	//ROOM 1
	if(vName == "St6_Door1"){jumptobranch("sor3_st6b", 1);}
	
	//ROOM 2
	if(vName == "St6_Door2"){jumptobranch("sor3_st6c", 1);}
	
	//ROOM 3
	if(vName == "St6_Door3"){jumptobranch("sor3_st6d", 1);}
	
	//ROOM 4
	if(vName == "St6_Door4"){jumptobranch("sor3_st6e", 1);}
	
	//ROOF JET
	if(vName == "St6_Exit"){jumptobranch("sor3_st6f", 1);}
}
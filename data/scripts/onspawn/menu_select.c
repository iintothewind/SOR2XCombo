void main()
{//Change animation according to current set
	void self = getlocalvar("self");
	void ani  = getentityproperty(self, "animationID");
	int set   = openborvariant("current_set");

	if(set == 0){
		if(getglobalvar("lives") > 1){
			changeentityproperty(self, "animation", openborconstant("ANI_IDLE")); //ARCADE MODE - MORE THAN 1 LIVES
		}else{
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2")); //ARCADE MODE - HAVE 1 LIVES ONLY
		}
	}
	else
	if(set == 1){
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2")); //SURVIVAL MODE
	}
	else
	if(set == 2){
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3")); //REBELLION MODE
	}
	else
	if(set == 3){
		changeentityproperty(self, "animation", openborconstant("ANI_IDLE")); //DOJO MODE
	}
}
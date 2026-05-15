void main()
{//Change animation after hit some opponents
	void self 	= getlocalvar("self");
	void target = getlocalvar("damagetaker");
	void driver = getentityvar(self, "driver");
	void ani 	= getentityproperty(driver, "animationID");
	
	if(getentityproperty(target, "defaultname") == "St3_Column"){
		if(ani == openborconstant("ANI_IDLE")){
			changeentityproperty(driver, "animation", openborconstant("ANI_FOLLOW1"));
		}
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));
		bindentity(driver, NULL());
	}else{
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
	}
}
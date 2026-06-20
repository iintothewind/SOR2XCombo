void main()
{//Change animation with entity variable (DR ZERO ROBOT ARM)
	void self   = getlocalvar("self");
	void target = getentityvar(self, "Arm");
	void name 	= getentityproperty(self, "defaultname");
	void vAnID 	= getentityproperty(self, "animationID");
	int dead	= getentityproperty(target, "dead");
	int frame	= getentityproperty(target, "animpos");
	
	if(name == "St8_Dr_Zero"){
		if(dead == 1){
			if(vAnID != openborconstant("ANI_FOLLOW2")){
				setglobalvar("turnOff", 1);
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
			}
		}
	}
	if(name == "St8_Machine3"){
		if(getglobalvar("turnOff") == 1){
			if(vAnID != openborconstant("ANI_FOLLOW1")){
				setlocalvar("frame"+self, frame);
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
			}

			if(frame != getlocalvar("frame"+self)){
				updateframe(self, getlocalvar("frame"+self));
			}
		}
	}
	if(name == "St8_Machine3Sa"){
		if(getglobalvar("turnOff") == 1){
			killentity(self);
		}
	}
	if(name == "St8_Machine3Sb"){
		if(getglobalvar("turnOff") == 1){
			killentity(self);
		}
	}
	if(name == "St8_Machine3Sc"){
		if(getglobalvar("turnOff") == 1){
			killentity(self);
		}
	}
	if(name == "St8_Ray"){
		if(getglobalvar("turnOff") == 1){
			killentity(self);
		}
	}
}
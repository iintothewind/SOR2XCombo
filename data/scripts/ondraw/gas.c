void main()
{//Change animation with global variable "gasEnable" (TOXIC GAS IN ST6A)
	void self  = getlocalvar("self");
	void vAnID = getentityproperty(self, "animationID");
	
	if(vAnID == openborconstant("ANI_IDLE")){ //IS IN DEFAULT IDLE ANIMATION??
		if(getglobalvar("gasEnable") == 1){ //GAS ALREADY ENABLED??
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //CHANGE ANIMATION
		}
	}
}
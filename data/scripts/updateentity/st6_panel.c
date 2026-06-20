void main()
{//Change animation if defined entity is "inpain" status
	void self 	 = getlocalvar("self");
	void target1 = getentityvar(self, "panel1");
	void target2 = getentityvar(self, "panel2");
	void vAniID  = getentityproperty(self, "animationID");
	int pain1	 = getentityproperty(target1, "aiflag", "inpain");
	int pain2	 = getentityproperty(target2, "aiflag", "inpain");
	int z		 = getentityproperty(self, "z");
	int eCount 	 = openborvariant("count_enemies");
	float time 	 = openborvariant("elapsed_time");
	
	if(time%2 == 0){
		if(eCount <= 2){
			if(vAniID == openborconstant("ANI_IDLE")){
				if(z <= 50 && pain1 == 1 ){ //"Z" VALUE IS THE ELEVATOR UP/DOWN LIMIT, OR IT WILL GO UP TO HEAVEN LOL!!!
					changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
				}
				else 
				if(z >= -50 && pain2 == 1){ //"Z" VALUE IS THE ELEVATOR UP/DOWN LIMIT, OR IT WILL GO UP TO HEAVEN LOL!!!
					changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
				}
			}
		}
	}
}
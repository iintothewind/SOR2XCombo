void main()
{//Change animation with enemy count
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self, "animpos");
	int pCount	= openborvariant("count_players");
	int eCount	= openborvariant("count_enemies");
	float time 	= openborvariant("elapsed_time");
	
	if(time%2 == 0){
		if(pCount >= 1 && eCount <= 1){
			if(vAniID == openborconstant("ANI_IDLE") && frame >= 1){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW1") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW2") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW3") && frame >= 4){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW4") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW5"));
			}
		}
	}
}
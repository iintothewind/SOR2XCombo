void main()
{//Change animation with enemy count
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self, "animpos");
	int eCount	= openborvariant("count_enemies");

	if(eCount <= 0){
		if(vAniID == openborconstant("ANI_IDLE") && frame >= 1){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW1") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW2") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW3") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW4") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW5"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW5") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW6"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW6") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW7"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW7") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW8"));
		}

		if(vAniID == openborconstant("ANI_FOLLOW8") && frame >= 2){
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW9"));
		}
	}
}
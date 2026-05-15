void main()
{
	bindBoss();
	eCount();
}

void bindBoss()
{//Bind defined entity in st8b elevator
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void shiva	= getglobalvar("ShivaBoss");
	void mrx	= getglobalvar("MrxBoss");
	int frame	= getentityproperty(self, "animpos");
	
	if(vAniID == openborconstant("ANI_FOLLOW3")){
		if(shiva != NULL() && mrx != NULL()){
			if(frame < 1){
				bindentity(shiva, self, 295, -553, 0, 0);
				bindentity(mrx, self, 235, -546, 0, 0);
			}
			else
			if(frame >= 1){
				bindentity(shiva, NULL());
				bindentity(mrx, NULL());
				setglobalvar("ShivaBoss", NULL());
				setglobalvar("MrxBoss", NULL());
			}
		}
	}
}

void eCount()
{//Change animation with enemy count
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self, "animationID");
	int frame	= getentityproperty(self, "animpos");
	int pCount	= openborvariant("count_players");
	int eCount	= openborvariant("count_enemies");
	float time 	= openborvariant("elapsed_time");
	
	if(time%2 == 0){
		if(pCount >= 1 && eCount <= 1){
			if(vAniID == openborconstant("ANI_IDLE") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW1") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
			}
			
			if(vAniID == openborconstant("ANI_FOLLOW2") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));
			}
		}
		
		if(pCount >= 1 && eCount > 3){
			if(vAniID == openborconstant("ANI_FOLLOW3") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
			}
		}
	}
}
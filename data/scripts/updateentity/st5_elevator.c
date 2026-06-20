void main()
{
	bindBoss();
	eCount();
}

void bindBoss()
{//Bind defined entity in st5e elevator
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void robotx	= getglobalvar("RobotxBoss");
	int frame	= getentityproperty(self, "animpos");
	
	if(vAniID == openborconstant("ANI_FOLLOW3")){
		if(robotx != NULL()){
			if(frame < 1){
				bindentity(robotx, self, 237, -540, 0, 0);
			}
			
			if(frame >= 1){
				bindentity(robotx, NULL());
				setglobalvar("RobotxBoss", NULL());
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
		
		if(pCount >= 1 && eCount >= 2){
			if(vAniID == openborconstant("ANI_FOLLOW3") && frame >= 2){
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
			}
		}
	}
}
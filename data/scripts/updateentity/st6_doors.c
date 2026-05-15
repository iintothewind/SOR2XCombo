void main()
{//Change animation with enemy count and defined conditions
	void self   = getlocalvar("self");
	void vName  = getentityproperty(self, "defaultname");
	void vAniID = getentityproperty(self, "animationID");
	int eCount  = openborvariant("count_enemies");
	float x     = getentityproperty(self, "x");
	float y     = getentityproperty(self, "y");
	float z     = getentityproperty(self, "z");
	float xPos  = openborvariant("xpos");
	float yPos  = openborvariant("ypos");
	float hRes  = openborvariant("hresolution");
	float time  = openborvariant("elapsed_time");
	float yDist = 272;
	
	if(time%2 == 0){
		if(x > xPos && x < xPos+hRes){
			if(y >= yPos+y-z && y <= yPos+yDist+y-z){
				setlocalvar("onScreen", 1);
			}else{
				setlocalvar("onScreen", 0);
			}
		}
		
		if(eCount <= 2 && getlocalvar("onScreen") == 1){
			if(vName == "St6_Door1"){
				if(getglobalvar("st6_lock1") != 1){
					if(vAniID == openborconstant("ANI_IDLE")){
						changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
					}
				}
			}
			
			if(vName == "St6_Door2"){
				if(getglobalvar("st6_lock2") != 1){
					if(vAniID == openborconstant("ANI_IDLE")){
						changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
					}
				}
			}
			
			if(vName == "St6_Door3"){
				if(getglobalvar("st6_lock3") != 1){
					if(vAniID == openborconstant("ANI_IDLE")){
						changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
					}
				}
			}
			
			if(vName == "St6_Door4"){
				if(getglobalvar("st6_lock4") != 1){
					if(vAniID == openborconstant("ANI_IDLE")){
						changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
					}
				}
			}
			
			if(vName == "St6_Exit"){
				if(getglobalvar("st6_lock1") == 1){
					if(getglobalvar("st6_lock2") == 1){
						if(getglobalvar("st6_lock3") == 1){
							if(getglobalvar("st6_lock4") == 1){
								if(vAniID == openborconstant("ANI_IDLE")){
									changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
								}
							}
						}
					}
				}
			}
		}
	}
}
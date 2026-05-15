void main()
{//Lean sprite with shiftX and frame check (SOR3 DANCE CLUB)
	void self  = getlocalvar("self");
	float time = openborvariant("elapsed_time");
	
	if(getlocalvar("value") == NULL()){
		setlocalvar("value", 0);
	}
	
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){
		void name	= getentityproperty(self, "defaultname");
		int frame	= getentityproperty(self, "animpos");
		float speed	= 0.010;
		
		if(time%2 == 0){
			if(name == "St2_Disco1"){
				if(frame == 0){
					setlocalvar("value", getlocalvar("value")+1.6);
					speed = speed;
				}else{
					setlocalvar("value", getlocalvar("value")-1.6);
					speed = -speed;
				}
				
				setdrawmethod(self,1,256,256,0,0, getlocalvar("value"),1);
				changeentityproperty(self, "velocity", speed, 0, 0);
			}
			
			if(name == "St2_Disco2"){
				if(frame == 0){
					setlocalvar("value", getlocalvar("value")-1.6);
					speed = speed;
				}else{
					setlocalvar("value", getlocalvar("value")+1.6);
					speed = -speed;
				}
				
				setdrawmethod(self,1,256,256,0,0, getlocalvar("value"), 1);
				changeentityproperty(self, "velocity", speed, 0, 0);
			}
		}
	}
}
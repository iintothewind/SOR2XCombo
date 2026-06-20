void main()
{
	suicideP();
	changeVel();
}

void suicideP()
{//Suicide if your caller is a Parent with defined conditions
	void self 	= getlocalvar("self");
	void parent = getentityproperty(self,"parent");
	void ani 	= getentityproperty(parent,"animationID");
	int pain 	= getentityproperty(parent,"aiflag","inpain");
	int fall 	= getentityproperty(parent,"aiflag","falling");
	
	if(ani == openborconstant("ANI_GRABBED") || pain == 1 || fall == 1){killentity(self);}
}

void changeVel()
{//Change velocity like a boomerang and revert xdir
	void self	= getlocalvar("self");
	int dir		= getentityproperty(self,"direction");
	float xVel	= getentityproperty(self,"xdir");
	float mult	= 60;
	
	if(getglobalvar("debugMode") == 1){mult = 180;}
	if(getlocalvar("reduce"+self) == NULL()){setlocalvar("reduce"+self, xVel/mult);}
	
	changeentityproperty(self, "velocity", xVel-getlocalvar("reduce"+self));
}
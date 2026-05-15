#import "data/scripts/animation/main_spawns.c"

void main()
{
	suicideP();
	bindParent();
	changeVel();
}

void suicideP()
{//Suicide if your caller is a Parent with defined conditions
	void self 	= getlocalvar("self");
	void parent = getentityproperty(self,"parent");
	void ani 	= getentityproperty(parent,"animationID");
	int dir		= getentityproperty(parent,"direction");
	int pain 	= getentityproperty(parent,"aiflag","inpain");
	int fall 	= getentityproperty(parent,"aiflag","falling");
	
	if(ani == openborconstant("ANI_GRABBED") || pain == 1 || fall == 1){
		changeentityproperty(self, "direction", dir);
		spawn01("Burn", 0, 0, 0);
		killentity(self);
	}
}

void bindParent()
{//Bind self to parent
	void self 	= getlocalvar("self");
	void name 	= getentityproperty(self,"defaultname");
	void parent = getentityproperty(self,"parent");
	void ani 	= getentityproperty(parent,"animationID");
	int dir		= getentityproperty(parent,"direction");
	int dx		= getentityproperty(self,"x");
	int dy		= getentityproperty(self,"y");
	int dz		= getentityproperty(self,"z");
	
	if(name == "Bongo_Fire"){
		if(getlocalvar("binded"+self) == NULL()){
			bindentity(self, parent, 20, 1, 60, dir, 0);
			setlocalvar("binded"+self, 1);
		}
	}
}

void changeVel()
{//Change velocity according to parent
	void self 	= getlocalvar("self");
	void name 	= getentityproperty(self,"defaultname");
	void parent = getentityproperty(self,"parent");
	void ani 	= getentityproperty(parent,"animationID");
	int dir		= getentityproperty(parent,"direction");
	int dx		= getentityproperty(self,"x");
	int dy		= getentityproperty(self,"y");
	int dz		= getentityproperty(self,"z");
	float xVel	= getentityproperty(parent,"xdir");
	float add	= 1;
	
	if(name == "Bongo_Fire_B"){
		if(dir == 0){add = -add;}changeentityproperty(self, "velocity", xVel+add);
	}
}
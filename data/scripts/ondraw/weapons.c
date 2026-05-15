void main()
{
	holeFix();
	minzKill();
}

void holeFix()
{//Make some adjustments if falling in any hole
	void self 	= getlocalvar("self");
	int x		= getentityproperty(self, "x");
	int y		= getentityproperty(self, "y");
	int z		= getentityproperty(self, "z");
	float hole 	= checkhole(x, z);
	
	if(hole && y < 5){
		if(getlocalvar("changed"+self) != 1){
			changeentityproperty(self, "subject_to_hole", 1);
			changeentityproperty(self, "no_adjust_base", 0);
			setlocalvar("changed"+self, 1);
		}
	}
}

void minzKill()
{//Suicide if the entity is beyond the player minZ, used only for items because this type of entity can't detect minZ automatically
	void self	= getlocalvar("self");
	void type	= getentityproperty(self, "type");
	int zPos	= getentityproperty(self, "z");
	int minZ	= openborvariant("player_min_z");

	if(type == openborconstant("TYPE_ITEM")){
		if(zPos < minZ-5){killentity(self);}
	}
}
void main()
{//Simulates a "Wall" in some levels
	void self 	= getlocalvar("self");
	void branch	= openborvariant("current_branch");
	
	if(branch == "sor2_st1a"){if(openborvariant("xpos") >= 600){killentity(self);}}
	if(branch == "sor2_st3b"){if(openborvariant("xpos") >= 1){killentity(self);}}
	if(branch == "sor2_st6b"){if(openborvariant("xpos") >= 200){killentity(self);}}
}

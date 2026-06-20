void main()
{//Change global variables when each computer is destroyed to unlock exit door in ST6A
	void self   = getlocalvar("self");
	void branch = openborvariant("current_branch");
	
	//DISABLE LOCKS FOR THE EXIT DOOR
	if(branch == "sor3_st6b"){setglobalvar("st6_lock1", 1);}
	if(branch == "sor3_st6c"){setglobalvar("st6_lock2", 1);}
	if(branch == "sor3_st6d"){setglobalvar("st6_lock3", 1);}
	if(branch == "sor3_st6e"){setglobalvar("st6_lock4", 1);}
}
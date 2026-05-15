void main()
{//Register self in a global variable for further use
	void self = getlocalvar("self");
	
	setglobalvar("spawnTime", self);
}
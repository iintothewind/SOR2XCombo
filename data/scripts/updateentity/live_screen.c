void main()
{//Register the current position to fix the Live Screen position
	void self	= getlocalvar("self");
	float x		= getentityproperty(self, "x");
	float y		= getentityproperty(self, "y");

	setglobalvar("liveScreenX", x);
	setglobalvar("liveScreenY", y);
}
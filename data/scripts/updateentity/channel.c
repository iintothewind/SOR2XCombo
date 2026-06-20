void main()
{//Set gradual channel reduction effect in each spawned entity
	void self 	 = getlocalvar("self");
	void effects = getglobalvar("graphicEffects");
	void name	 = getentityproperty(self, "defaultname");
	float time	 = openborvariant("elapsed_time");
	int type  	 = getglobalvar("effectType"+self);
	int legacy 	 = getglobalvar("legacy"+self);
	int map	  	 = getentityproperty(self, "map");
	int alpha	 = 6;
	int chStart  = 160;
	int color;

	if(effects == "sor2x"){
		if(type == 1){
			color	= rgbcolor(0xFF, 0x00, 0x00); //RAGE MOVES
		}else{
			color	= rgbcolor(0x00, 0x00, 0x00); //SIMPLE MOVES
		}

		float channel = getlocalvar("channel"+self);
		float reduce  = 2;

		if(getlocalvar("channel"+self) == NULL()){setlocalvar("channel"+self, chStart);}

		if(channel >= chStart){
			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "alpha", alpha);
			changedrawmethod(self, "remap", map);
			changedrawmethod(self, "fillcolor", color);
			changedrawmethod(self, "channelr", channel);
			changedrawmethod(self, "channelg", channel);
			changedrawmethod(self, "channelb", channel);
			setlocalvar("channel"+self, channel-reduce);
		}
		if(channel < chStart){
			changedrawmethod(self, "channelr", channel);
			changedrawmethod(self, "channelg", channel);
			changedrawmethod(self, "channelb", channel);
			setlocalvar("channel"+self, channel-reduce);
		}

		if(getlocalvar("channel"+self) <= 0){killentity(self);}
	}

	if(effects == "original"){
		float lifespan;

		if(legacy == "legacy"){
			lifespan = 30;

			if(getlocalvar("lifespan"+self) == NULL()){
				changeentityproperty(self, "lifespancountdown", lifespan);
				setlocalvar("lifespan"+self, 1);
			}
		}else{
			lifespan = 40;

			if(getlocalvar("lifespan"+self) == NULL()){
				changeentityproperty(self, "lifespancountdown", lifespan);
				setlocalvar("lifespan"+self, 1);
			}

			if(time%2 == 0){
				changedrawmethod(self, "enabled", 1);
				changedrawmethod(self, "remap", map);
				changedrawmethod(self, "scalex", 0);
				changedrawmethod(self, "scaley", 0);
			}else{
				changedrawmethod(self, "enabled", 1);
				changedrawmethod(self, "remap", map);
				changedrawmethod(self, "scalex", 256);
				changedrawmethod(self, "scaley", 256);
			}
		}
	}
}
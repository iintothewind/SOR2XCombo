void main()
{//Change model with defined condition in according to GRAPHIC EFFECTS VARIABLE
	void self  	 = getlocalvar("self");
	void effects = getglobalvar("graphicEffects");
	void name	 = getentityproperty(self, "defaultname");
	
	if(effects == "original"){
		if(name == "BloodHit"){
			changeentityproperty(self, "model", "Flash_B", 1);
		}
		else
		if(name == "FallHit" || name == "Impact"){
			changeentityproperty(self, "model", "Impact_B", 1);
		}
		else
		if(name == "Counter" || name == "Rage" || name == "Splash" || name == "Water"){
			killentity(self);
		}
		else
		{
			changeentityproperty(self, "model", name+"_B", 1);
		}
	}

	if(name == "Block" || name == "Block_B"){
		if(getglobalvar("blockType") == "parry" || getglobalvar("blockType") == "parry_(alt._mode_on)"){
			int tintMode  = 1;
			int tintColor = rgbcolor(0xAA, 0x00, 0x00);

			changedrawmethod(self, "enabled", 1);
			changedrawmethod(self, "tintmode", tintMode);
			changedrawmethod(self, "tintcolor", tintColor);
		}
	}
}
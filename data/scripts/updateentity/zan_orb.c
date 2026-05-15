#import "data/scripts/updateentity/main.c"

void main()
{//Suicide if your caller is a Parent with defined conditions. Apply some effects too
	void self 	= getlocalvar("self");
	void parent = getentityproperty(self,"parent");
	void vName 	= getentityproperty(self,"defaultname");
	void dModel	= getentityproperty(parent,"defaultmodel");
	void tModel	= getentityproperty(parent,"model");
	void ani 	= getentityproperty(parent,"animationID");
	
	if(vName == "Zan_Orb1"){
		if(parent != NULL()){
			if(tModel == dModel || ani == openborconstant("ANI_ATTACKBOTH")){
				setentityvar(parent, "Zan_Orb1", NULL());
				killentity(self);
			}
		}else{
			killentity(self);
		}
	}
	
	if(vName == "Zan_Orb2"){
		if(getglobalvar("graphicEffects") == "sor2x"){afterImage("Zan_OrbS", 0);}
	}
	
	if(vName == "Zan_Orb3"){
		if(getglobalvar("graphicEffects") == "sor2x"){afterImage("Zan_OrbS", 0);}
	}
}
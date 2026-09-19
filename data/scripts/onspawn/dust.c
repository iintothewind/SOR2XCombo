void main()
{//Change model with defined condition in specific branch (DUST TO SPLASH/CROWD)
    void self      = getlocalvar("self");
    void effects = getglobalvar("graphicEffects");
    void branch  = openborvariant("current_branch");
    int set      = openborvariant("current_set");
    
    if(effects == "sor2x"){
        
        //ARCADE - REBELLION
        if(set == 0 || set == 2){
            if(branch == "sor2_st1c"){
                changeentityproperty(self, "model", "Splash", 1); //BAR EXIT BARBON
            }
            
            if(branch == "sor2_st4d" || branch == "sor3_st7c"){
                changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //RING ABADEDE - PRESS ROOM SHIVA
            }
        }
        
        //SURVIVAL
        if(set == 1){
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //RING ABADEDE
        }
    }
    
    if(effects == "original"){
        
        //ARCADE - REBELLION
        if(set == 0 || set == 2){
            if(branch == "sor2_st4d" || branch == "sor3_st7c"){
                changeentityproperty(self, "model", "Dust_B", 1);
                changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //RING ABADEDE - PRESS ROOM SHIVA
            }else{
                changeentityproperty(self, "model", "Dust_B", 1);
            }
        }
        
        //SURVIVAL
        if(set == 1){
            changeentityproperty(self, "model", "Dust_B", 1);
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //RING ABADEDE
        }
    }
}
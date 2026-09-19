void offScreenKill(float dx, int edge)
{//Check position relative to screen. If is offscreen, suicide! (OBSTACLES)
 //dx: Distance to screen edge
 //edge: 0 = left, 1 = right
    void self    = getlocalvar("self");
    float x        = getentityproperty(self,"x");
    float xPos    = openborvariant("xpos");
    float hRes    = openborvariant("hresolution");
    
    if((x > xPos+hRes+dx) && (edge == 1)){killentity(self);} //OFFSCREEN TO THE RIGHT?? SUICIDE!
    else
    if((x < xPos-dx) && (edge == 0)){killentity(self);}//OFFSCREEN TO THE LEFT?? SUICIDE!
}

void hurtSelf(int damage)
{//Hurt self with defined damage 
    void self = getlocalvar("self");

    damageentity(self, self, damage, 0, openborconstant("ATK_NORMAL"));
}

void hurtPerc(float percent)
{//Hurt self with defined Health percent check and always damage with max health (PARTICLE SUICIDE)
    void self     = getlocalvar("self");
    int mHealth = getentityproperty(self,"maxhealth"); //Get entity's max health
    int health     = getentityproperty(self,"health"); //Get entity's health

    if(health <= mHealth*percent/100){damageentity(self, self, mHealth, 0, openborconstant("ATK_NORMAL"));}
}

void suicide()
{//Suicide!!
    void self = getlocalvar("self");

    killentity(self); //SUICIDE!
}

void suicideFrame(int frame)
{//Change the parent frame and suicide!!
    void self   = getlocalvar("self");
    void parent = getentityproperty(self, "parent");

    updateframe(parent, frame);
    killentity(self); //SUICIDE!
}
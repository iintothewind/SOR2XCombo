void main()
{
    tailV();
    layerUPD();
    suicideP();
}

void tailV()
{//Change Vehelits TAIL (OR BODY :D) velocity
    void self         = getlocalvar("self");
    void parent        = getentityproperty(self, "parent");
    void vName         = getentityproperty(self, "name");
    int pain         = getentityproperty(parent, "aiflag", "inpain");
    float time        = openborvariant("elapsed_time");
    float TxVel        = getentityproperty(parent, "xdir");
    float TzVel        = getentityproperty(parent, "zdir");
    float reduce    = 0.4;
    float vSpeed;
    
    if(vName == "Tail19"){    vSpeed = 10;}
    if(vName == "Tail18"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail17"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail16"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail15"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail14"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail13"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail12"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail11"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail10"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail9"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail8"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail7"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail6"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail5"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail4"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail3"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail2"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail1"){    vSpeed = vSpeed-reduce;}
    if(vName == "Tail0"){    vSpeed = vSpeed-reduce;}
    
    if(pain != 0){
        if(time > getglobalvar("pauseAdd"+parent)){changeentityproperty(self, "velocity", TxVel/vSpeed, TzVel/vSpeed, 0);}else
        {changeentityproperty(self, "velocity", 0, 0, 0);}
    }
    else
    {
        if(getglobalvar("pauseAdd"+parent) != NULL()){setglobalvar("pauseAdd"+parent, NULL());}
        changeentityproperty(self, "velocity", TxVel/vSpeed, TzVel/vSpeed, 0);
    }
}

void layerUPD()
{//Update layer
    void self = getlocalvar("self");
    int layer = getentityproperty(self, "z");

    changeentityproperty(self, "setlayer", layer/5);
}

void suicideP()
{//Suicide if your caller is a Parent and if are dead
    void self     = getlocalvar("self");
    void target = getlocalvar("target"+self);
    void vName     = getentityproperty(self,"name");
    int tHealth = getentityproperty(target, "health");
    
    if(target == NULL()){target = getentityproperty(self, "parent");setlocalvar("target"+self, target);}
    if(target != NULL()){if(tHealth <= 0){killentity(self);}}
}
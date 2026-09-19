void main()
{//Animation changer with Xpos check (DONOVAN MANHOLE)
    void self    = getlocalvar("self");
    void ani    = getentityproperty(self, "animationID");
    float x        = getentityproperty(self, "x");
    float xPos    = openborvariant("xpos");
    float hRes    = openborvariant("hresolution");
    float limit    = 100;
    
    if(x <= xPos + hRes - limit){
        if(ani == openborconstant("ANI_IDLE")){
            changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
        }
    }
}
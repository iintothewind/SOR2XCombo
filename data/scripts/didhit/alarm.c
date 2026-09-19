void main()
{//Use "killentity/damageentity" commands on enemies in ST6A when toxic gas is enabled
    void self        = getlocalvar("self");
    void target        = getlocalvar("damagetaker");
    void iType        = getentityproperty(target,"type");
    void iSubType    = getentityproperty(target,"subtype");
    float Tx        = getentityproperty(target,"x");
    float xPos        = openborvariant("xpos");
    float hRes        = openborvariant("hresolution");
    
    if(iType == openborconstant("TYPE_ENEMY") && iSubType != openborconstant("SUBTYPE_NOTGRAB")){
        if(Tx < xPos || Tx > xPos+hRes){killentity(target);}else{damageentity(target, self, 10000, 1);}
    }
}
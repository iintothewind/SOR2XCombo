void main()
{//Change position based on global variable lastPos
    void self = getlocalvar("self");
    
    if(getglobalvar("lastXpos") != NULL()){
        float x = getglobalvar("lastXpos");
        float y = getglobalvar("lastYpos");
        float z = getglobalvar("lastZpos");
        changeentityproperty(self, "position", x, z, y);
    }
}
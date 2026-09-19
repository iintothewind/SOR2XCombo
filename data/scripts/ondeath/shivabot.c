#import "data/scripts/ondeath/main.c"

void main()
{
    void self = getlocalvar("self");
    void name = getentityproperty(self, "defaultname");

    resetAuraEffect();
    if(name == "Shiva_Bot_Flee"){
        musicPause();
        slowMotion();
        screen(1);
    }

    if(name == "Shiva_Bot_Wait"){
        musicPause();
        screen(1);
        changeentityproperty(getglobalvar("St7_People"), "animation", openborconstant("ANI_FOLLOW1"));
    }
    dropItem("Apple");
}
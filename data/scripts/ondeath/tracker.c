#import "data/scripts/ondeath/main.c"

void main()
{//Reset "lockMp" global variable to restore the default "mprate"
    void self = getlocalvar("self");
    resetAuraEffect();

    setglobalvar("lockMp"+self, NULL());
    dropItem("Apple");
}
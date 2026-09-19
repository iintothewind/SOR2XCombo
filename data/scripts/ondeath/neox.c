#import "data/scripts/ondeath/main.c"

void main()
{
    musicPause();
    slowMotion();
    screen(1);
    resetAuraEffect();
    endLevel();
}

void hostileAni()
{//Changes hostile/candamage properties when entity dies
    void self = getlocalvar("self");

    changeentityproperty(self, "hostile", "type_obstacle");
    changeentityproperty(self, "candamage", "type_player", "type_obstacle");
    setglobalvar("neoxDead", 1);
}

void endLevel() {
    void self = getlocalvar("self");
    void model     = getentityproperty(self, "model");
  if(model == "Neox_Death") {
        if(getglobalvar("alarm") == 1){
            jumptobranch("sor3_ending_b", 0);
        }
        else
        if(getglobalvar("alarm") == 2){
            jumptobranch("sor3_ending_c", 0);
        } else {
            jumptobranch("sor3_ending_c", 0);
        }
  }
}
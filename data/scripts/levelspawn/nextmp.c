#import "data/scripts/levelspawn/main_level.c"

void main()
{//Calculate the life ammount to be restored
    void player1 = getplayerproperty(0, "entity");
    void player2 = getplayerproperty(1, "entity");
    void player3 = getplayerproperty(2, "entity");
    void player4 = getplayerproperty(3, "entity");
    int restore;
    int refill;

    if(player1 != NULL()){
        restore = getentityproperty(player1, "maxhealth");
        refill  = getentityproperty(player1, "maxmp");
    }
    else
    if(player2 != NULL()){
        restore = getentityproperty(player2, "maxhealth");
        refill  = getentityproperty(player2, "maxmp");
    }
    else
    if(player3 != NULL()){
        restore = getentityproperty(player3, "maxhealth");
        refill  = getentityproperty(player3, "maxmp");
    }
    else
    if(player4 != NULL()){
        restore = getentityproperty(player4, "maxhealth");
        refill  = getentityproperty(player4, "maxmp");
    }

    autoLife(restore);

    // if(getglobalvar("fullEnergy") == "always" || getglobalvar("fullEnergy") == "each_new_stage"){
        autoMp(refill);
    // }
}
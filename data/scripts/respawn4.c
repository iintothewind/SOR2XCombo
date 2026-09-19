#import "data/scripts/levelspawn/main_level.c"

void main()
{//Used to lock the native engine "re-fill" mp feature at each respawn and load the last saved mp value
    if(getglobalvar("fullEnergy") == "never" || getglobalvar("fullEnergy") == "each_new_stage"){
        loadMp(3);
    }
}
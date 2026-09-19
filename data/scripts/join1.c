#import "data/scripts/main.c"
#import "data/scripts/levelspawn/main_level.c"
#import "data/scripts/levelspawn/music_random.c"

void main()
{
    changeLives(0);

    //USED TO LOCK THE NATIVE ENGINE "RE-FILL" MP FEATURE AT EACH RESPAWN AND LOAD THE LAST SAVED MP VALUE
    if(getglobalvar("fullEnergy") == "never" || getglobalvar("fullEnergy") == "each_new_stage"){
        loadMp(0);
    }

    if(openborvariant("current_set") == 3){
        randomMusic();
    }
}
#import "data/scripts/levelspawn/main_musicmisc.c"

void selectBack()
{//Spawn Select Screen background

    void counter = getlocalvar("selectCounter");  //Set a variable to trigger the spawn on and off
    while(counter != 1){ //Check the variable to avoid double spawn
        void subent;
        clearspawnentry(); //clean the spawn entry
        setspawnentry("name", "Select_Menu"); //define the entity to be spawn
        subent = spawn();  //spawn the entity
        changeentityproperty(subent, "position", 0, 0, 0);//for safe, set again the position
        changeentityproperty(subent, "direction", 1); //set the direction
        musicSelect();
        counter = setlocalvar("selectCounter", 1); //turn on the variable, blocking a new spawn to be made
    }
}

void selectPlayer()
{//Draw Select Screen content
    float time    = openborvariant("elapsed_time");
    float hRes  = openborvariant("hresolution");
    int set        = openborvariant("current_set");
    int yTitle    = 2;
    int xLock    = 0;
    int yLock    = 0;
    int xPos1    = 208;
    int xPos2    = 260;
    int yPos    = 141;
    int font    = 7;
    int layer1    = 2000;
    int layer2    = 3000;

    //DISABLE DRAWMETHOD
    setdrawmethod(NULL(),0,256,256,0,0,0,0);

    //DRAW GLOBAL CONTENT
    drawstring((hRes-strwidth("SELECT_PLAYER", font))/2+1, yTitle, font, "SELECT_PLAYER");

    //ARCADE-SURVIVAL
    // if(set != 2){
    //     if(getsaveinfo(0, "times_completed") < 1){ //THE GAME IS NOT FINISHED YET
    //         drawsprite(getglobalvar("locked"), xLock, yLock, layer1); //BLACK IMAGE
    //         drawstring(xPos1, yPos, font, "?", layer2); //ADAM LOCKED
    //         drawstring(xPos2, yPos, font, "?", layer2); //ZAN LOCKED
    //     }
    // }

    //DRAW GRIDS
    drawsprite(getglobalvar("grids"), 0, 0, 0);
}
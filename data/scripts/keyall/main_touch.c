void defineTouch()
{//Define custom touch config to a external file for load each time the game is started
    void file = createfilestream();
    
    if(openborvariant("current_scene") == "data/scenes/howto.txt" || getglobalvar("activeText") == "Extra"){
        if(getglobalvar("touchLayout") != "custom" && getglobalvar("touchLayout") != "type_1"){
            void layout = openfilestream("data/scripts/keyall/touch_"+getglobalvar("touchLayout")+".h");
            
            changeButton(file, layout, 1); //MOVELEFT
            changeButton(file, layout, 0); //MOVERIGHT
            changeButton(file, layout, 0); //MOVEUP
            changeButton(file, layout, 0); //MOVEDOWN
            changeButton(file, layout, 0); //SPECIAL
            changeButton(file, layout, 0); //ATTACK
            changeButton(file, layout, 0); //JUMP
            changeButton(file, layout, 0); //ATTACK2
            changeButton(file, layout, 0); //ATTACK3
            changeButton(file, layout, 0); //ATTACK3
            changeButton(file, layout, 0); //ESC
            changeButton(file, layout, 0); //START
            changeButton(file, layout, 0); //SCREENSHOT
            
            savefilestream(file, "touch.txt", "saves/bor/");
            savefilestream(file, "touch.txt", "saves/");
            closefilestream(file);
        }
        
        if(getglobalvar("touchLayout") == "type_1"){
            setfilestreamposition(file, 0);
            filestreamappend(file, "//", 1);
            savefilestream(file, "touch.txt", "saves/bor/");
            savefilestream(file, "touch.txt", "saves/");
            closefilestream(file);
        }
    }
}

void changeButton(void file, void layout, int newLine)
{//Change buttons to write a custom touch layout in a external file
    int add    = 1;
    int pos    = 0;

    setfilestreamposition(file, pos);filestreamappend(file, "button", newLine);
    pos = pos+add;
    setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(layout, pos, "string"), 1);
    pos = pos+add;
    setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(layout, pos, "float"), 1);
    pos = pos+add;
    setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(layout, pos, "float"), 1);
    pos = pos+add;
    setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(layout, pos, "float"), 1);
    pos = pos+add;
    setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(layout, pos, "int"), 1);
    filestreamnextline(layout);
    pos = 0;
}
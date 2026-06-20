void playList()
{//Create custom music folder and playlist.txt
	
	//CONFIGURATION FILE NOT EXISTS?? APPLY DEFAULT VALUES
	if(openfilestream("Musics/PlayList.txt") == -1){
		void file = createfilestream();
		void list = openfilestream("data/music/remake/PlayList.txt");
		
		changeTrack(file, list, 1); //TRACK 00
		changeTrack(file, list, 0); //TRACK 01
		changeTrack(file, list, 0); //TRACK 02
		changeTrack(file, list, 0); //TRACK 03
		changeTrack(file, list, 0); //TRACK 04
		changeTrack(file, list, 0); //TRACK 05
		changeTrack(file, list, 0); //TRACK 06
		changeTrack(file, list, 0); //TRACK 07
		changeTrack(file, list, 0); //TRACK 08
		changeTrack(file, list, 0); //TRACK 09
		changeTrack(file, list, 0); //TRACK 10
		changeTrack(file, list, 0); //TRACK 11
		changeTrack(file, list, 0); //TRACK 12
		changeTrack(file, list, 0); //TRACK 13
		changeTrack(file, list, 0); //TRACK 14
		changeTrack(file, list, 0); //TRACK 15
		changeTrack(file, list, 0); //TRACK 16
		changeTrack(file, list, 0); //TRACK 17
		changeTrack(file, list, 0); //TRACK 18
		changeTrack(file, list, 0); //TRACK 19
		changeTrack(file, list, 0); //TRACK 20
		changeTrack(file, list, 0); //TRACK 21
		changeTrack(file, list, 0); //TRACK 22
		changeTrack(file, list, 0); //TRACK 23
		changeTrack(file, list, 0); //TRACK 24
		changeTrack(file, list, 0); //TRACK 25
		changeTrack(file, list, 0); //TRACK 26
		changeTrack(file, list, 0); //TRACK 27
		changeTrack(file, list, 0); //TRACK 28
		changeTrack(file, list, 0); //TRACK 29
		changeTrack(file, list, 0); //TRACK 30
		changeTrack(file, list, 0); //TRACK 31
		changeTrack(file, list, 0); //TRACK 32
		changeTrack(file, list, 0); //TRACK 33
		changeTrack(file, list, 0); //TRACK 34
		changeTrack(file, list, 0); //TRACK 35
		changeTrack(file, list, 0); //TRACK 36
		changeTrack(file, list, 0); //TRACK 37
		changeTrack(file, list, 0); //TRACK 38
		changeTrack(file, list, 0); //TRACK 39
		changeTrack(file, list, 0); //TRACK 40
		changeTrack(file, list, 0); //TRACK 41
		changeTrack(file, list, 0); //TRACK 42
		changeTrack(file, list, 0); //TRACK 43
		changeTrack(file, list, 0); //TRACK 44
		changeTrack(file, list, 0); //TRACK 45
		changeTrack(file, list, 0); //TRACK 46
		changeTrack(file, list, 0); //TRACK 47
		changeTrack(file, list, 0); //TRACK 48
		changeTrack(file, list, 0); //TRACK 49
		
		savefilestream(file, "PlayList.txt", "Musics/");
		closefilestream(file);
	}
}

void changeTrack(void file, void list, int newLine)
{//Change tracks to write a playlist in a external file
	int add	= 1;
	int pos	= 0;

	setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(list, pos, "string"), newLine);
	pos = pos+add;
	setfilestreamposition(file, pos);filestreamappend(file, getfilestreamargument(list, pos, "string"), 1);
	filestreamnextline(list);
	pos = 0;
}

void bgmTest()
{//Play musics freely using the BGM Test option, same as the original SOR series
	void mStyle = getglobalvar("musicStyle");
	void music	= getglobalvar("bgmTest");
	void folder;
	
	if(getglobalvar("highlight") == 7){
		
		//DEFINE CURRENT MUSIC STYLE
		if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
		
		//ADD A "0" ALGARISM TO THE MUSIC NAME IF THE TRACK IS BELOW FROM 9
		if(music <= 9){music = "0"+music+".ogg";}else{music = music+".ogg";}
		
		//PLAY SELECTED MUSIC
		playmusic(folder+music, 1);
	}else{
		//STOP PLAYING MUSIC IF THE PLAYER SELECTS OTHER OPTIONS
		if(openborvariant("current_scene") == "data/scenes/howto.txt"){pausemusic(1);}
	}
}
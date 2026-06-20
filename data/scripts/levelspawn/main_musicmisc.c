void musicIntro()
{//Play Intro scene music
	void mStyle;
	void folder;
	void music	= "00.ogg";

	//DETECT IF THE MUSIC STYLE VARIABLE IS ALREADY SAVED, OTHERWISE GET DIRECTLY FROM THE SOR2X.CFG FILE
	if(getglobalvar("musicStyle") == NULL()){

		//CFG FILE EXISTS?? GET VALUES FROM EXTERNAL CFG FILE
		if(openfilestream("saves/SOR2XComboExtra.cfg") != -1){
			void cfg	= openfilestream("saves/SOR2XComboExtra.cfg");
			int pos		= 0;
			int limit	= 29;

			if(getglobalvar("nextLine") == NULL()){setglobalvar("nextLine", 0);}

			while(getglobalvar("nextLine") < limit){
				filestreamnextline(cfg);
				setglobalvar("nextLine", getglobalvar("nextLine")+1);
			}

			if(getglobalvar("nextLine") >= limit){
				mStyle = getfilestreamargument(cfg, pos, "string");
				closefilestream(cfg);
			}
		}
		else //CFG FILE NOT EXISTS?? USE THE DEFAULT VALUE
		{
			mStyle = "remake";
		}
	}
	else //MUSIC STYLE VARIABLE EXISTS?? GET MUSIC STYLE
	{
		mStyle = getglobalvar("musicStyle");
	}

	//PLAY DEFINED MUSIC
	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 0);
	setglobalvar("musicPlaying", music);
}

void musicSelect()
{//Play Select Screen music
	void mStyle = getglobalvar("musicStyle");
	void music  = "01.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}

void musicComplete()
{//Play Complete Screen music
	void mStyle = getglobalvar("musicStyle");
	void music  = "19.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 0);
	setglobalvar("musicPlaying", music);
}

void musicEnding(void ending)
{//Play game Ending music
	void mStyle = getglobalvar("musicStyle");
	void music1 = "20.ogg";
	void music2 = "41.ogg";
	void music3 = "42.ogg";
	void music;
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	if(ending == "ending_a"){music = music1;}else
	if(ending == "ending_b"){music = music2;}else
	if(ending == "ending_c"){music = music3;}

	playmusic(folder+music, 0);
	setglobalvar("musicPlaying", music);
}

void musicGameover()
{//Play Game over music
	void mStyle = getglobalvar("musicStyle");
	void music = "43.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 0);
	setglobalvar("musicPlaying", music);
}

void musicReplay()
{//Replay the current music if the style is changed in-game
	void mStyle = getglobalvar("musicStyle");
	void music  = getglobalvar("musicPlaying");
	void folder;

	if(music != NULL()){

		//TEMPORARY SOLUTION UNTIL ALL SOR TRACKS ARE ADDED, IT WILL PLAY GG/SMS TRACKS ON SPECIFIC ORIGINAL LEVELS
		if(openborvariant("current_branch") == "sor2_st3i"){
			if(mStyle == "original" && music == "04.ogg"){music = "49.ogg";}else
			if(mStyle == "remake" && music == "49.ogg"){music = "04.ogg";}
		}

		if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
		if(openborvariant("in_level")){playmusic(folder+music, 1);}
	}
}
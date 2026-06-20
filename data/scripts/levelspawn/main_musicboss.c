#import "data/scripts/main.c"

void musicBoss1()
{//Play SOR1 boss music
	void mStyle = getglobalvar("musicStyle");
	void music  = "48.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}

	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}

void musicBoss2()
{//Play SOR2 boss music
	void mStyle = getglobalvar("musicStyle");
	void music  = "04.ogg";
	void folder;

	//TEMPORARY SOLUTION UNTIL ALL SOR TRACKS ARE ADDED, IT WILL PLAY GG/SMS TRACKS ON SPECIFIC ORIGINAL LEVELS
	if(openborvariant("current_branch") == "sor2_st3i"){
		if(mStyle == "original"){music = "49.ogg";}
	}

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}

void musicBoss3()
{//Play SOR3 boss music
	void mStyle = getglobalvar("musicStyle");
	void music  = "27.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}


void musicBossNinja1()
{//Play SOR3 boss music
	playmusic("data/music/sor2x/reverse_situation.ogg", 1);
}

void musicBossNinja2()
{//Play SOR3 boss music
	playmusic("data/music/sor2x/drum_beat_yakuza_ishin.ogg", 1);
}

void musicBossNinja3()
{//Play SOR3 boss music
	playmusic("data/music/sor2x/naruto_dt.ogg", 1);
}

void musicBossX()
{//Play random bosses musics
	void mStyle = getglobalvar("musicStyle");
	void music1 = "04.ogg"; //SOR2 BOSS THEME
	void music2 = "17.ogg"; //SOR2 SHIVA THEME
	void music3 = "18.ogg"; //SOR2 MRX THEME
	void music4 = "27.ogg"; //SOR3 BOSS THEME
	void music5 = "33.ogg"; //SOR3 YAMATO THEME
	void music6 = "36.ogg"; //SOR3 ROBO X THEME
	void music7 = "37.ogg"; //SOR3 JET THEME
	void music8 = "40.ogg"; //SOR3 DR. ZERO THEME
	void music;
	void folder;
	float iR 	= rand()%50+50;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}

	if(iR >= 0 && iR < 12.5)	{music = music1;}else
	if(iR >= 12.5 && iR < 25)	{music = music2;}else
	if(iR >= 25 && iR < 37.5)	{music = music3;}else
	if(iR >= 37.5 && iR < 50)	{music = music4;}else
	if(iR >= 50 && iR < 62.5)	{music = music5;}else
	if(iR >= 62.5 && iR < 75)	{music = music6;}else
	if(iR >= 75 && iR < 87.5)	{music = music7;}else
	if(iR >= 87.5 && iR <= 100)	{music = music8;}

	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}



void musicShiva()
{//Play Shiva music
	void mStyle = getglobalvar("musicStyle");
	void music = "17.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}

void musicMrx()
{//Play MrX music
	void mStyle = getglobalvar("musicStyle");
	void music  = "18.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}

void musicBear()
{
	void mStyle = getglobalvar("musicStyle");
	void music  = "18.ogg";
	void folder;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}
	void music  = "18.ogg";
	playmusic(folder+music, 1);
	setglobalvar("musicPlaying", music);
}
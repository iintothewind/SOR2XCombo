#import "data/scripts/levelspawn/music_random.c"

void musicStage()
{//Play music in each stage
 //musicStopped global variable usage: 1 = Stage music is Stopped / NULL() = Stage music is Playing
	void mStyle = getglobalvar("musicStyle");
	void branch = openborvariant("current_branch");
	void music;
	void folder;
	int set 	= openborvariant("current_set");
	int stage 	= openborvariant("current_stage");
	int stopMusic;

	if(mStyle == "custom"){folder = "Musics/";}else{folder = "data/music/"+mStyle+"/";}

	if(set == 0 || set == 2){
		//MAIN ROUTE//
		if(branch == "route"){music = "24.ogg";		playmusic(folder+music, 1);}

		//SOR1 ROUTE
		if(branch == "sor1_st01"){playmusic("data/music/sor1/01.ogg", 1);}
		if(branch == "sor1_st02"){playmusic("data/music/sor1/02.ogg", 1);}
		if(branch == "sor1_st03"){playmusic("data/music/sor1/03.ogg", 1);}
		if(branch == "sor1_st04"){playmusic("data/music/sor1/04.ogg", 1);}
		if(branch == "sor1_st05"){playmusic("data/music/sor1/05.ogg", 1);}
		if(branch == "sor1_st06"){playmusic("data/music/sor1/06.ogg", 1);}
		if(branch == "sor1_st07"){playmusic("data/music/sor1/07.ogg", 1);}
		if(branch == "sor1_st08"){playmusic("data/music/sor1/08.ogg", 1);}

		//SOR2 ROUTE

		//STAGE 1
		if(branch == "sor2_st1a"){music = "02.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st1b"){music = "03.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st1c"){music = 0;		playmusic(folder+music, 1);}

		//STAGE 2
		if(branch == "sor2_st2a"){music = "05.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st2b"){music = "06.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st2c"){music = "05.ogg";	playmusic(folder+music, 1);}

		//STAGE 3
		stopMusic = "yes"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor2_st3a"){music = "07.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}
			if(branch == "sor2_st3b"){if(getglobalvar("musicStopped") != NULL()){music = "07.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
			if(branch == "sor2_st3c"){if(getglobalvar("musicStopped") != NULL()){music = "07.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
			if(branch == "sor2_st3d"){if(getglobalvar("musicStopped") != NULL()){music = "07.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			if(branch == "sor2_st3a"){music = "07.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st3b"){music = "07.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st3c"){music = "07.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st3d"){music = "07.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		if(branch == "sor2_st3e"){music = "06.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st3f"){music = "07.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st3g"){music = "08.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st3h"){music = "45.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st3i"){music = "46.ogg";	playmusic(folder+music, 1);}

		//STAGE 4
		stopMusic = "no"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor2_st4a"){music = "09.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}
			if(branch == "sor2_st4b"){if(getglobalvar("musicStopped") != NULL()){music = "09.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			if(branch == "sor2_st4a"){music = "09.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st4b"){music = "09.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		if(branch == "sor2_st4c"){music = "10.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st4d"){music = 0;		playmusic(folder+music, 1);}

		//STAGE 5
		stopMusic = "yes"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor2_st5a"){music = "11.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}
			if(branch == "sor2_st5b"){if(getglobalvar("musicStopped") != NULL()){music = "11.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
			if(branch == "sor2_st5c"){if(getglobalvar("musicStopped") != NULL()){music = "11.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			if(branch == "sor2_st5a"){music = "11.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st5b"){music = "12.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st5c"){music = "13.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		//STAGE 6
		// if(branch == "sor2_st6a"){music = "12.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st6a"){music = "12.ogg";	playmusic("data/music/sor2x/ghost_of_yoti_trailer.ogg", 1);}
		// if(branch == "sor2_st6b"){music = "13.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st6b"){music = "13.ogg";	playmusic("data/music/sor2x/ghost_of_yoti_trailer.ogg", 1);}

		//STAGE 7
		if(branch == "sor2_st7a"){music = "14.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st7b"){music = "15.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor2_st7c"){music = "47.ogg";	playmusic(folder+music, 1);}

		//STAGE 8
		stopMusic = "yes"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor2_st8a"){music = "16.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}
			if(branch == "sor2_st8b"){if(getglobalvar("musicStopped") != NULL()){music = "16.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			if(branch == "sor2_st8a"){music = "16.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor2_st8b"){music = "16.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		//SOR3 ROUTE

		//STAGE 1
		if(branch == "sor3_st1a"){music = "21.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st1b"){music = "22.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st1c"){music = "24.ogg";	playmusic(folder+music, 1);}

		//STAGE 2
		if(branch == "sor3_st2a"){music = "25.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st2b"){music = "26.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st2c"){music = 0;		playmusic(folder+music, 1);}

		//STAGE 3
		if(branch == "sor3_st3a"){music = "28.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st3b"){music = "29.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st3c"){music = "30.ogg";	playmusic(folder+music, 1);}

		//STAGE 4
		if(branch == "sor3_st4a"){music = "31.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st4b"){music = "32.ogg";	playmusic(folder+music, 1);}
		// if(branch == "sor3_st4c"){music = "33.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st4c"){music = "33.ogg";	playmusic("data/music/sor2x/drum_beat_yakuza_ishin.ogg", 1);setglobalvar("musicStopped", NULL());}

		//STAGE 5
		stopMusic = "yes"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor3_st5a"){music = "34.ogg";playmusic("data/music/sor2x/drum_beat_yakuza_ishin.ogg", 1);setglobalvar("musicStopped", NULL());}
			// if(branch == "sor3_st5b"){if(getglobalvar("musicStopped") != NULL()){music = "34.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
			if(branch == "sor3_st5b"){if(getglobalvar("musicStopped") != NULL()){music = "33.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
			if(branch == "sor3_st5c"){if(getglobalvar("musicStopped") != NULL()){music = "34.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			// if(branch == "sor3_st5a"){music = "34.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor3_st5a"){music = "34.ogg";	playmusic("data/music/sor2x/drum_beat_yakuza_ishin.ogg", 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor3_st5b"){music = "33.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor3_st5c"){music = "34.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		if(branch == "sor3_st5d"){music = "35.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st5e"){music = "25.ogg";	playmusic(folder+music, 1);}

		//STAGE 6
		if(branch == "sor3_st6a"){music = "21.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st6b"){music = "22.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st6c"){music = "22.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st6d"){music = "22.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st6e"){music = "22.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st6f"){music = "37.ogg";	playmusic(folder+music, 1);}

		//STAGE 7
		stopMusic = "no"; //IF YOU DON'T WANT THE MUSIC TO COTINUE ALONG THE NEXT LEVELS, SIMPLY FILL "YES"

		if(stopMusic == "no"){ //THE "STOPMUSIC" OPTION IS "NO"?? ALL LEVELS BELOW WILL USE THE SAME MUSIC
			if(branch == "sor3_st7a"){music = "38.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}
			if(branch == "sor3_st7b"){if(getglobalvar("musicStopped") != NULL()){music = "38.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", NULL());}}
		}
		else
		if(stopMusic == "yes"){ //THE "STOPMUSIC" OPTION IS "YES"?? EACH LEVEL BELOW WILL USE THE DEFINED MUSIC
			if(branch == "sor3_st7a"){music = "38.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
			if(branch == "sor3_st7b"){music = "38.ogg";	playmusic(folder+music, 1);} //DEFINE EACH MUSIC FOR EACH STAGE
		}

		if(branch == "sor3_st7c"){music = 0;		playmusic(folder+music, 1);}
		if(branch == "sor3_st7d"){music = "44.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st7e"){music = "44.ogg";	playmusic(folder+music, 1);}

		//STAGE 8
		if(branch == "sor3_st8a"){music = "24.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st8b"){music = "25.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st8c"){music = "39.ogg";	playmusic(folder+music, 1);}
		if(branch == "sor3_st8d"){music = "40.ogg";playmusic(folder+music, 1);setglobalvar("musicStopped", 1);}
		if(branch == "sor3_st8e"){music = "21.ogg";playmusic(folder+music, 1);}

		setglobalvar("musicPlaying", music);
	}

	if(set == 1){ //SURVIVAL
		if(branch == "survival_config"){
			music = "24.ogg";
			playmusic(folder+music, 1);
			setglobalvar("musicPlaying", music);
		}else{
			randomMusic();
		}
	}

	if(set == 3){
		if(branch == "dojo_config"){
			playmusic("data/music/sor2x/fist_of_fury.ogg", 1);
		}else if(branch == "Dojo"){
			playmusic("data/music/sor2x/rotd_dojo.ogg", 1);
		}else if(branch == "Sea01"){
			playmusic("data/music/sor2x/a_tear_of_vm_loh4.ogg", 1);
		// }else if(branch == "Sea01"){
		// 	playmusic("data/music/sor2x/ninja_gaiden_skyline.ogg", 1);
		}else if(branch == "Sea02"){
			playmusic("data/music/sor2x/ltfmn_unknown_woman.ogg", 1);
		}else if(branch == "ChinaTown"){
			playmusic("data/music/sor2x/zhifou_lan.ogg", 1);
		}else{
			randomMusic();
		}
	}
}

#import "data/scripts/main.c"

void main()
{
  randomMusic();
}

void musicMax() {
  return 31;
}

void unsetMusicVars() {
    int counter = 1;
    while(counter <= musicMax()) {
        setglobalvar("musicx"+counter, NULL());
        counter++;
    }
}

void findRestMusicVar() {
    int counter = 1;
    while(counter <= musicMax()) {
        int created = getglobalvar("musicx"+counter);
        if(created == NULL()) {
            return counter;
        }
        counter++;
    }
    return 0;
}

void randomMusic() {
    void music1 = "data/music/sor2x/ninja_gaiden_theme.ogg";
    void music2 = "data/music/sor2x/shinobi.ogg";
    void music3 = "data/music/sor2x/shinobi_idaten.ogg";
    void music4 = "data/music/sor2x/ddneogeo_chengfu.ogg";
    void music5 = "data/music/sor2x/kof98_esaka.ogg";
    void music6 = "data/music/sor2x/langrisser2_leon.ogg";
    void music7 = "data/music/sor2x/naruto_dt.ogg";
    void music8 = "data/music/sor2x/ninja_gaiden_skyline_remix.ogg";
    void music9 = "data/music/sor2x/sf_guile.ogg";
    void music10 = "data/music/sor2x/aot_main.ogg";
    void music11 = "data/music/sor2x/aot_give_your_hart.ogg";
    void music12 = "data/music/sor2x/tou_gong.ogg";
    void music13 = "data/music/sor2x/rotd_dojo.ogg";
    void music14 = "data/music/sor2x/wukong.ogg";
    void music15 = "data/music/sor2x/children_of_the_dark.ogg";
    void music16 = "data/music/sor2x/ezios_family.ogg";
    void music17 = "data/music/sor2x/okatsu_nioh1.ogg";
    void music18 = "data/music/sor2x/fist_of_fury.ogg";
    void music19 = "data/music/sor2x/silver_will.ogg";
    void music20 = "data/music/sor2x/wong_feihung.ogg";
    void music21 = "data/music/sor2x/ltfmn_unknown_woman.ogg";
    void music22 = "data/music/sor2x/djrm.ogg";
    void music23 = "data/music/sor2x/smooth_criminal.ogg";
    void music24 = "data/music/sor2x/hyj_jay.ogg";
    void music25 = "data/music/sor2x/ygxy_black_myth.ogg";
    void music26 = "data/music/sor2x/fist_of_legent_jet_li.ogg";
    void music27 = "data/music/sor2x/jtlr_ra3_mod.ogg";
    void music28 = "data/music/sor2x/ghost_of_yoti_trailer.ogg";
    void music29 = "data/music/sor2x/drum_beat_yakuza_ishin.ogg";
    void music30 = "data/music/sor2x/reverse_situation.ogg";
    void music31 = "data/music/sor2x/ninja_gaiden_skyline.ogg";
    int musicNumber = rnd(musicMax());

    int counter = 0;
    while(counter <= 99 && getglobalvar("musicx"+musicNumber) == 1 && findRestMusicVar() != 0) {
        if(counter < 99) {
            musicNumber = rnd(musicMax());
        } else {
            musicNumber = findRestMusicVar();
        }
        counter++;
    }

    if(musicNumber == 1)    {
        playmusic(music1, 1);
    }else if(musicNumber == 2)    {
        playmusic(music2, 1);
    }else if(musicNumber == 3)    {
        playmusic(music3, 1);
    }else if(musicNumber == 4)    {
        playmusic(music4, 1);
    }else if(musicNumber == 5)    {
        playmusic(music5, 1);
    }else if(musicNumber == 6)    {
        playmusic(music6, 1);
    }else if(musicNumber == 7)    {
        playmusic(music7, 1);
    }else if(musicNumber == 8)    {
        playmusic(music8, 1);
    }else if(musicNumber == 9)    {
        playmusic(music9, 1);
    }else if(musicNumber == 10)    {
        playmusic(music10, 1);
    }else if(musicNumber == 11)    {
        playmusic(music11, 1);
    }else if(musicNumber == 12)    {
        playmusic(music12, 1);
    }else if(musicNumber == 13)    {
        playmusic(music13, 1);
    }else if(musicNumber == 14)    {
        playmusic(music14, 1);
    }else if(musicNumber == 15)    {
        playmusic(music15, 1);
    }else if(musicNumber == 16)    {
        playmusic(music16, 1);
    }else if(musicNumber == 17)    {
        playmusic(music17, 1);
    }else if(musicNumber == 18)    {
        playmusic(music18, 1);
    }else if(musicNumber == 19)    {
        playmusic(music19, 1);
    }else if(musicNumber == 20)    {
        playmusic(music20, 1);
    }else if(musicNumber == 21)    { //skip
        playmusic(music30, 1);
    }else if(musicNumber == 22)    {
        playmusic(music22, 1);
    }else if(musicNumber == 23)    {
        playmusic(music23, 1);
    }else if(musicNumber == 24)    {
        playmusic(music24, 1);
    }else if(musicNumber == 25)    {
        playmusic(music25, 1);
    }else if(musicNumber == 26)    {
        playmusic(music26, 1);
    }else if(musicNumber == 27)    {
        playmusic(music27, 1);
    }else if(musicNumber == 28)    {
        playmusic(music28, 1);
    }else if(musicNumber == 29)    {
        playmusic(music29, 1);
    }else if(musicNumber == 30)    {
        playmusic(music30, 1);
    }else if(musicNumber == 31)    {
        playmusic(music31, 1);
    }else {
        playmusic(music1, 1);
    }

    if(musicNumber == 0 || findRestMusicVar() == 0) {
        unsetMusicVars();
    } else {
        setglobalvar("musicx"+musicNumber, 1);
    }

}
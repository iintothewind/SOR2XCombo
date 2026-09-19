#import "data/scripts/main.c"
#import "data/scripts/onspawn/main.c"

void main()
{
    if(openborvariant("current_set") == 0){
        int generated = 0;
        for(generated = 0; generated < getglobalvar("randomBoss"); generated++) {
            bossX1();
        }
    } else {
        bossX1();
    }
}

void bossMax() {
  return 28;
}

void unsetBossVars() {
    int counter = 1;
    while(counter <= bossMax()) {
        setglobalvar("boss"+counter, NULL());
        counter++;
    }
}

void findRestBossVar() {
    int counter = 1;
    while(counter <= bossMax()) {
        int created = getglobalvar("boss"+counter);
        if(created == NULL()) {
            return counter;
        }
        counter++;
    }
    return 0;
}

void calcLevel() {
    void difficult    = getglobalvar("difficult");
    if(difficult == "mania"){
        return 4;
    } else if(difficult == "hard"){
        return 2;
    }  else {
        return 1;
    }
}

void bossX1() {
    void boss1 = "AbadedeB";
    void boss2 = "BarbonB";
    void boss3 = "BearB";
    void boss4 = "HarakiriB";
    void boss5 = "JetB";
    void boss6 = "MonalisaB";
    void boss7 = "MrxB";
    void boss8 = "NeoxB";
    void boss9 = "ParticleB";
    void boss10 = "RingmasterB";
    void boss11 = "RobotxB";
    void boss12 = "RocketB";
    void boss13 = "ShivaB";
    void boss14 = "Shiva_BotB";
    void boss15 = "TrackerB";
    void boss16 = "YamatoB";
    void boss17 = "ZamzaB";
    void boss18 = "BreakB";
    void boss19 = "HarakiriD";
    void boss20 = "Musashi";
    void boss21 = "AshB";
    void boss22 = "ReineB";
    void boss23 = "BisonB";
    void boss24 = "ChunliB";
    void boss25 = "KageB";
    void boss26 = "LeeB";
    void boss27 = "Tamer";
    void boss28 = "RooB";

    void branch = openborvariant("current_branch");
    int numHoles = openborvariant("numholes");
    int numWalls = openborvariant("numwalls");

    int bossNum    = rnd(bossMax());
    int bossLevel = calcLevel();
    int counter = 0;
    while(counter <= 99 && getglobalvar("boss"+bossNum) == 1 && findRestBossVar() != 0) {
        if(counter < 99) {
            bossNum = rnd(bossMax());
        } else {
            bossNum = findRestBossVar();
        }
        counter++;
    }

    int x = 20;
    int y = 0;
    int z = 1;

    if(bossNum == 1) {
        enemyX(boss1, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 2) {
        enemyX(boss2, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 3) {
        enemyX(boss3, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 4) {
        enemyX(boss4, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 5) {
        enemyX(boss5, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 6 && numHoles == 0 && numWalls == 0
        && branch != "sor2_st7a"
        && branch != "sor2_st7c"
        && branch != "sor2_st8b"
        && branch != "sor3_st8c"
        && branch != "sor3_st8d"
        && branch != "sor3_st8e") {
        enemyX(boss6, x, y, z, 0, 0, 4);
    } else if(bossNum == 7
        && branch != "sor2_st8b"
        && branch != "sor3_st8e") {
        enemyX(boss7, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 8
        && branch != "sor2_st8b"
        && branch != "sor3_st8e") {
        enemyX(boss8, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 9) {
        enemyX(boss9, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 10) {
        enemyX(boss10, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 11) {
        enemyX(boss11, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 12) {
        enemyX(boss12, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 13) {
        enemyX(boss13, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 14) {
        enemyX(boss14, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 15
        && branch != "sor2_st8b"
        && branch != "sor3_st8e") {
        enemyX(boss15, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 16) {
        enemyX(boss16, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 17) {
        enemyX(boss17, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 18) {
        enemyX(boss18, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 19) {
        enemyX(boss19, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 20) {
        enemyX(boss20, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 21) {
        enemyX(boss21, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 22) {
        enemyX(boss22, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 23) {
        enemyX(boss23, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 24) {
        enemyX(boss24, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 25) {
        enemyX(boss25, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 26) {
        enemyX(boss26, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 27 && numHoles == 0 && numWalls == 0
        && findLevelBoss() == NULL()
        && branch != "sor2_st7a"
        && branch != "sor2_st7c"
        && branch != "sor2_st8b"
        && branch != "sor3_st6a"
        && branch != "sor3_st6b"
        && branch != "sor3_st6c"
        && branch != "sor3_st6d"
        && branch != "sor3_st6e"
        && branch != "sor3_st6f"
        && branch != "sor3_st6g"
        && branch != "sor3_st8c"
        && branch != "sor3_st8d"
        && branch != "sor3_st8e") {
        enemyX(boss27, x, y, z, 0, 0, bossLevel, bossNum);
    } else if(bossNum == 28
        && findLevelBoss() == NULL()
        && branch != "sor2_st8b"
        && branch != "sor3_st6a"
        && branch != "sor3_st6b"
        && branch != "sor3_st6c"
        && branch != "sor3_st6d"
        && branch != "sor3_st6e"
        && branch != "sor3_st6f"
        && branch != "sor3_st6g"
        && branch != "sor3_st8e") {
        enemyX(boss28, x, y, z, 0, 0, bossLevel, bossNum);
    } else {
        enemyX(boss1, x, y, z, 0, 0, bossLevel, bossNum);
    }

    if(bossNum == 0 || findRestBossVar() == 0) {
        unsetBossVars();
    } else {
        setglobalvar("boss"+bossNum, 1);
    }
}
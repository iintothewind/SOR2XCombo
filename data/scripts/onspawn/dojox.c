#import "data/scripts/onspawn/main.c"

void main()
{
    spawnDojoOpponent();
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

void spawnDojoOpponent() {
    void dojoOpponent    = getglobalvar("dojoOpponent");
  if(dojoOpponent == NULL()) {
    dojoOpponent = "Kun";
  }

    int level = calcLevel();

    if(dojoOpponent == "Kun") {
        enemyX("Kun", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Abadede") {
        enemyX("AbadedeB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Ash") {
        enemyX("AshB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Barbon") {
        enemyX("BarbonB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Bear") {
        enemyX("BearB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Bison") {
        enemyX("BisonB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Break") {
        enemyX("BreakB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Tamer") {
        enemyX("Tamer", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Chunli") {
        enemyX("ChunliB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "HarakiriB") {
        enemyX("HarakiriB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "HarakiriD") {
        enemyX("HarakiriD", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Jet") {
        enemyX("JetB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Kage") {
        enemyX("KageB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Lee") {
        enemyX("LeeB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Monalisa") {
        enemyX("MonalisaB", 260, 300, 80, 1, 0, 4);
    } else if(dojoOpponent == "MrX") {
        enemyX("MrxB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "NeoX") {
        enemyX("NeoxB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Particle") {
        enemyX("ParticleB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Reine") {
        enemyX("ReineB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "RingMaster") {
        enemyX("RingmasterB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "RobotX") {
        enemyX("RobotxB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Rocket") {
        enemyX("RocketB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "SOR2_Shiva") {
        enemyX("ShivaB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "SOR3_Shiva") {
        enemyX("Shiva_BotB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Tracker") {
        enemyX("TrackerB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Yamato") {
        enemyX("YamatoB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Musashi") {
        enemyX("Musashi", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Zamza") {
        enemyX("ZamzaB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Jack") {
        enemyX("JackB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Raven") {
        enemyX("RavenB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Hakuyo") {
        enemyX("HakuyoB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Tiger") {
        enemyX("TigerB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Bongo") {
        enemyX("BongoB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "BigBen") {
        enemyX("BigBenB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Electra") {
        enemyX("ElectraB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Kusanagi") {
        enemyX("KusanagiB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Joker") {
        enemyX("BruceB", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Signal") {
        enemyX("Signal_Bottle", 260, 300, 80, 1, 0, level);
    } else if(dojoOpponent == "Roo") {
        enemyX("RooB", 260, 300, 80, 1, 0, level);
    } else {
        enemyX("Kun", 260, 300, 80, 1, 0, level);
    }
}
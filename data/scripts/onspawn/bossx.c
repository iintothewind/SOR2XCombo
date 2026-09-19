#import "data/scripts/onspawn/main.c"

void main()
{
    bossX();
}

void bossX()
{//Spawn defined Boss
    int branch = openborvariant("current_branch");
    int xDir   = 60;
    int xDif   = 90;
    int xAdd   = 10;
    int zDir   = 200;
    int zDif   = 30;

    if(branch == "survival_c1"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
    }
    else
    if(branch == "survival_c2"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
    }
    else
    if(branch == "survival_c3"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
    }
    else
    if(branch == "survival_c4"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
    }
    else
    if(branch == "survival_c5"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
    }
    else
    if(branch == "survival_c6"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
    }
    else
    if(branch == "survival_c7"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
    }
    else
    if(branch == "survival_c8"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
    }
    else
    if(branch == "survival_c9"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
    }
    else
    if(branch == "survival_c10"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
    }
    else
    if(branch == "survival_c11"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
    }
    else
    if(branch == "survival_c12"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
    }
    else
    if(branch == "survival_c13"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 0, 0);
    }
    else
    if(branch == "survival_c14"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("RocketB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
    }
    else
    if(branch == "survival_c15"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("RocketB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
        enemyX("Shiva_BotB", xDir+xDif*4+xAdd, 0, zDir, 0, 0, 0);
    }
    else
    if(branch == "survival_c16"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir-zDif/2, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("RocketB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
        enemyX("Shiva_BotB", xDir+xDif*4+xAdd, 0, zDir, 0, 0, 0);
        enemyX("TrackerB", xDir+xDif*4+xAdd, 0, zDir+zDif, 0, 0, 0);
    }
    else
    if(branch == "survival_c17"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 0, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 0, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 0, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 0, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 0, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 0, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir-zDif/2, 1, 0, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 0, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 0, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 0, 0);
        enemyX("RocketB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
        enemyX("Shiva_BotB", xDir+xDif*4+xAdd, 0, zDir, 0, 0, 0);
        enemyX("TrackerB", xDir+xDif*4+xAdd, 0, zDir+zDif, 0, 0, 0);
        enemyX("RingmasterB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
    }
    else
    if(branch == "survival_c18"){
        enemyX("BarbonB", xDir-xAdd, 0, zDir+zDif*2, 1, 1, 0);
        enemyX("JetB", xDir-xAdd, 40, zDir+zDif, 1, 1, 0);
        enemyX("ZamzaB", xDir-xAdd, 0, zDir, 1, 1, 0);
        enemyX("AbadedeB", xDir+xDif-xAdd, 0, zDir+zDif*2, 1, 1, 0);
        enemyX("BearB", xDir+xDif-xAdd, 0, zDir+zDif, 1, 1, 0);
        enemyX("HarakiriB", xDir+xDif-xAdd, 0, zDir, 1, 1, 0);
        enemyX("ParticleB", xDir+xDif*2, 0, zDir+zDif*2, 1, 1, 0);
        enemyX("ShivaB", xDir+xDif*2, 0, zDir+zDif, 1, 1, 0);
        enemyX("MrxB", xDir+xDif*2, 0, zDir-zDif/2, 1, 1, 0);
        enemyX("MonalisaB", xDir+xDif*3+xAdd, 0, zDir+zDif*2, 0, 1, 0);
        enemyX("BreakB", xDir+xDif*3+xAdd, 0, zDir+zDif, 0, 1, 1);
        enemyX("YamatoB", xDir+xDif*3+xAdd, 0, zDir, 0, 1, 0);
        enemyX("RobotxB", xDir+xDif*4+xAdd, 0, zDir+zDif*2, 0, 1, 0);
        enemyX("RocketB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 1, 0);
        enemyX("Shiva_BotB", xDir+xDif*4+xAdd, 0, zDir, 0, 1, 0);
        enemyX("TrackerB", xDir+xDif*4+xAdd, 0, zDir+zDif, 0, 1, 0);
        enemyX("RingmasterB", xDir+xDif*4+xAdd, 40, zDir+zDif, 0, 0, 0);
        enemyX("NeoxB", xDir+xDif*2, 0, zDir, 1, 1, 0);
    }
}
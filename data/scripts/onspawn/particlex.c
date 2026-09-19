#import "data/scripts/onspawn/main.c"

void main()
{
    particleX();
}

void particleX()
{//Spawn Enemy according player count
    void difficult    = getglobalvar("difficult");
    void partner    = getglobalvar("partnerAlive");
    int  set         = openborvariant("current_set");
    int  branch        = openborvariant("current_branch");
    int  pCount     = openborvariant("count_players");
    
    if(partner > 0){pCount = pCount+partner;}
    
    if(set == 0 || set == 2){
        if(branch == "sor2_st7b"){
            if(difficult != "mania"){
                if(pCount >= 3){enemyX("ParticleB", 0, 0, 0, 1, 1, 2);enemyX("ParticleB", 380, 100, 0, 0, 1, 3);}
            }
            if(difficult == "mania"){
                enemyX("ParticleB", 0, 0, 0, 1, 1, 2);
                enemyX("ParticleB", 380, 100, 0, 0, 1, 3);
            }
        } 
        
        if(branch == "sor2_st8a"){
            if(pCount >= 1 && pCount <= 2){enemyX("ParticleB", 0, 0, 0, 1, 0, 2);}else
            if(pCount >= 3 && pCount <= 4){enemyX("ParticleB", 0, 0, 0, 1, 0, 2);enemyX("ParticleB", 600, 0, 0, 0, 0, 3);}
        }
    }
}
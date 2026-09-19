#import "data/scripts/onspawn/main.c"

void main()
{
    foodX();
}

void foodX()
{//Spawn random food
    void partner = getglobalvar("partnerAlive");
    int pCount      = openborvariant("count_players");
    
    if(partner > 0){pCount = pCount+partner;}
    
    if(pCount == 1){
        spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 0, 0);
    }
    else
    if(pCount == 2){
        spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 0, 0);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 50, 0, 0);
    }
    else
    if(pCount == 3){
        spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 0, 0);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 50, 0, 0);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 25, 0, 15);
    }
    else
    if(pCount >= 4){
        spawnX("Apple", "Apple", "Chicken", "Chicken", 0, 0, 0);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 50, 0, 0);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 25, 0, 15);
        spawnX("Apple", "Apple", "Chicken", "Chicken", 75, 0, 15);
    }
}
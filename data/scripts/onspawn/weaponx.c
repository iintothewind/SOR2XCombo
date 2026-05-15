#import "data/scripts/onspawn/main.c"

void main()
{
	weaponX();
}

void weaponX()
{//Spawn random Weapon
	int pCount = openborvariant("count_players");
	
	if(pCount == 1){
		spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 0, 0);
	}
	else
	if(pCount == 2){
		spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 0, 0);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 50, 0, 0);
	}
	else
	if(pCount == 3){
		spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 0, 0);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 50, 0, 0);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 25, 0, 15);
	}
	else
	if(pCount >= 4){
		spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 0, 0);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 50, 0, 0);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 25, 0, 15);
		spawnX("Knife", "Kunai", "Pipe", "Sword", 75, 0, 15);
	}
}
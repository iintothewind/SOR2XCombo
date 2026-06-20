#import "data/scripts/levelspawn/main_level.c"
#import "data/scripts/levelspawn/music_random.c"

void main()
{//Calculate the life ammount to be restored
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	int restore;
	int mHealth;
	int refill;

	if(player1 != NULL()){mHealth = getentityproperty(player1, "maxhealth");}else
	if(player2 != NULL()){mHealth = getentityproperty(player2, "maxhealth");}else
	if(player3 != NULL()){mHealth = getentityproperty(player3, "maxhealth");}else
	if(player4 != NULL()){mHealth = getentityproperty(player4, "maxhealth");}

	if(getglobalvar("survivaLifeRestore") == "25%")	{restore = mHealth/4;}else
	if(getglobalvar("survivaLifeRestore") == "50%")	{restore = mHealth/2;}else
	if(getglobalvar("survivaLifeRestore") == "75%")	{restore = (mHealth/4)*3;}else
	if(getglobalvar("survivaLifeRestore") == "100%"){restore = mHealth;}else{restore = 0;}

	if(player1 != NULL()){
		refill  = getentityproperty(player1, "maxmp");
	}
	else
	if(player2 != NULL()){
		refill  = getentityproperty(player2, "maxmp");
	}
	else
	if(player3 != NULL()){
		refill  = getentityproperty(player3, "maxmp");
	}
	else
	if(player4 != NULL()){
		refill  = getentityproperty(player4, "maxmp");
	}

	autoLife(restore, 1);

	// if(getglobalvar("fullEnergy") == "always"){
	// 	autoMp(refill);
	// }

	spawnX("Knife", "Kunai", "Pipe", "Sword", 0, 270, 230);

  randomMusic();
}

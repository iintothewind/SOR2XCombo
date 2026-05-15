#import "data/scripts/onspawn/main.c"

void main()
{
	jetX();
}

void jetX()
{//Spawn enemy according player count
	void difficult	= getglobalvar("difficult");
	void partner	= getglobalvar("partnerAlive");
	int  set 		= openborvariant("current_set");
	int  branch		= openborvariant("current_branch");
	int  pCount 	= openborvariant("count_players");
	
	if(partner > 0){pCount = pCount+partner;}
	
	if(set == 0 || set == 2){
		if(branch == "sor2_st2c"){
			if(difficult != "mania"){
				if(pCount >= 2){enemyX("JetB", 0, 0, 0, 0, 0, 1);}
			}
			if(difficult == "mania"){
				enemyX("JetB", 0, 0, 0, 0, 0, 1);
			}
		}
		
		if(branch == "sor2_st5c"){
			if(difficult != "mania"){
				if(pCount >= 1 && pCount <= 2){enemyX("JetB", 0, 0, 0, 0, 0, 2);}else
				if(pCount >= 3 && pCount <= 4){enemyX("JetB", 0, 0, 0, 0, 0, 2);enemyX("JetB", 50, 0, 0, 1, 0, 3);}
			}
			if(difficult == "mania"){
				enemyX("JetB", 0, 0, 0, 0, 0, 2);
				enemyX("JetB", 50, 0, 0, 1, 0, 3);
			}
		}
		
		if(branch == "sor2_st7b"){
			if(difficult != "mania"){
				if(pCount >= 1 && pCount <= 2){enemyX("JetB", 0, 0, 0, 0, 0, 5);}else
				if(pCount >= 3 && pCount <= 4){enemyX("JetB", 0, 0, 0, 0, 0, 5);enemyX("JetB", 50, 0, 0, 1, 0, 4);}
			}
			if(difficult == "mania"){
				enemyX("JetB", 0, 0, 0, 0, 0, 5);
				enemyX("JetB", 50, 0, 0, 1, 0, 5);
			}
		}
	}
}
void rankName(int player)
{//Change Gameplay Menu variables if defined key is pressed
	void letterA	= getglobalvar("letterA"+player);
	void letterB	= getglobalvar("letterB"+player);
	void letterC	= getglobalvar("letterC"+player);
	float time		= openborvariant("elapsed_time");
	int hasplayed	= getplayerproperty(player, "hasplayed");
	int position	= getglobalvar("position"+player);
	int max			= 25;
	int min			= 0;
	int add			= 1;
	
	if(hasplayed == 1){
		if(getglobalvar("nameEntered"+player) == NULL()){
			if(time < getglobalvar("nameTimer")){

				//HIGHLIGHT OPTIONS WHEN MOVE DOWN
				if(playerkeys(player, 1, "movedown")){
					if(position == 0){
						if(letterA >= min && letterA < max){setglobalvar("letterA"+player, letterA+add);}
						if(letterA == max){setglobalvar("letterA"+player, min);}
					}
					else
					if(position == 1){
						if(letterB >= min && letterB < max){setglobalvar("letterB"+player, letterB+add);}
						if(letterB == max){setglobalvar("letterB"+player, min);}
					}
					else
					if(position == 2){
						if(letterC >= min && letterC < max){setglobalvar("letterC"+player, letterC+add);}
						if(letterC == max){setglobalvar("letterC"+player, min);}
					}
				}
				
				//HIGHLIGHT OPTIONS WHEN MOVE UP
				if(playerkeys(player, 1, "moveup")){
					if(position == 0){
						if(letterA > min && letterA <= max){setglobalvar("letterA"+player, letterA-add);}
						if(letterA == min){setglobalvar("letterA"+player, max);}
					}
					else
					if(position == 1){
						if(letterB > min && letterB <= max){setglobalvar("letterB"+player, letterB-add);}
						if(letterB == min){setglobalvar("letterB"+player, max);}
					}
					else
					if(position == 2){
						if(letterC > min && letterC <= max){setglobalvar("letterC"+player, letterC-add);}
						if(letterC == min){setglobalvar("letterC"+player, max);}
					}
				}

				//ADVANCE LETTER
				if(playerkeys(player, 1, "moveright")){
					max	= 3;
					min	= 0;

					if(position >= min && position < max){setglobalvar("position"+player, position+add);}
				}

				//BACK LETTER
				if(playerkeys(player, 1, "moveleft")){
					max	= 3;
					min	= 0;

					if(position > min && position < max){setglobalvar("position"+player, position-add);}
				}
			}
		}
	}
}
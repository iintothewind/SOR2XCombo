void main()
{//Script to avoid engine "noshare" BUG that don't give enough time to press start button and continue the game if the all players are dead
 //This bug happens only if "noshare" command is not present in "levels.txt". If it is present with flag 1, this bug not happens and the engine give you 10 seconds
	float limit	= 4000; //TIME LIMIT TO CHECK IF THERE'S A CONTDOWN RUNNING
	float add	= 3960; //TIME TO BE ADDED IF ALL PLAYERS ARE DEAD BUT HAS CREDITS TO USE
	
	if(getglobalvar("activeText") == "continue"){ //CONTINUE SCREEN IS BEING SHOWN??
		if(openborvariant("count_players") > 0){ //PLAYERS ARE IN THE SCREEN??
			setglobalvar("activeText", 0); //DISABLE CONTINUE COUNTER
		}
	}
	
	if(getglobalvar("activeText") != "continue"){ //CONTINUE SCREEN IS NOT BEING SHOWN??
		if(	getplayerproperty(0, "joining") != 1 &&
			getplayerproperty(1, "joining") != 1 &&
			getplayerproperty(2, "joining") != 1 &&
			getplayerproperty(3, "joining") != 1 ){

			if(openborvariant("count_players") <= 0){ //NO PLAYERS IN THE SCREEN??
				if(getplayerproperty(0, "credits") > 0){ //ALREADY HAVE CREDITS TO PLAY??
					if(openborvariant("game_time") < limit){ //CONTINUE COUNTER IS LESS THAN 10 SECONDS??
						changeopenborvariant("game_time", add); //CHANGE CONTINUE TIMER TO 10 SECONDS
						setglobalvar("activeText", "continue"); //SET CONTINUE SCREEN FLAG TO 1
					}
				}
			}
		}
	}
}
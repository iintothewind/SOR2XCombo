void timePlayed()
{//Total played time counter
	float time 	= openborvariant("elapsed_time");
	int playS 	= getglobalvar("playedSecond");
	int playM 	= getglobalvar("playedMinute");
	int playH 	= getglobalvar("playedHour");
	int xBase 	= 462;		//DEFAULT X POSITION BASE USED FOR ALL CONTENT
	int yBase 	= 260;		//DEFAULT Y POSITION BASE USED FOR ALL CONTENT
	int font  	= 1;		//DEFAULT FONT NUMBER
	int xDif;

	//USED TO UPDATE THE TIMER
	if(getglobalvar("activeText") == 0 || getglobalvar("activeText") == NULL()){ //CHECK IF ANY MENU IS ON
		if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
			if(openborvariant("in_level") && !openborvariant("in_showcomplete")){ //CHECK IF ANY MENU IS ON OR IN COMPLETE SCREEN
				int add		= 1;	//USED TO ADD +1 SECOND/MINUTE/HOUR
				int sec		= 59;	//SECONDS LIMIT BEFORE ADD +1 MINUTE
				int min		= 59;	//MINUTES LIMIT BEFORE ADD +1 HOUR
				int limit	= 200;	//THIS IS SAME AS 1 SECOND IN ENGINE CENTISECONDS, USED FOR CONVERSION PURPOSE
				
				//REACHED 60 SECONDS LIMIT?? ADD +1 MINUTE AND RESET SECOND COUNTER TO ZERO
				if(getglobalvar("playedSecond") > sec){
					setglobalvar("playedSecond", 0);
					setglobalvar("playedMinute", getglobalvar("playedMinute")+add);
				}
				
				//COUNT EACH SECOND PASSED AND REGISTER IN A VARIABLE
				if(time-(getglobalvar("playedCounter")) > limit){
					setglobalvar("playedSecond", getglobalvar("playedSecond")+add);
					setglobalvar("playedCounter", time);
				}
				
				//REACHED 60 MINUTES LIMIT?? ADD +1 HOUR AND RESET MINUTE COUNTER TO ZERO
				if(getglobalvar("playedMinute") > min){
					setglobalvar("playedMinute", 0);
					setglobalvar("playedHour", getglobalvar("playedHour")+add);
				}
			}
		}
	}
	
	//USED TO ADJUST POSITION IF EQUAL/LESS THAN 9 SECONDS AND DRAW CONTENT
	if(playS <= 9){
		playS = "0"+playS;
	}
	
	//USED TO ADJUST POSITION IF EQUAL/LESS THAN 9 MINUTES AND DRAW CONTENT
	if(playM <= 9){
		playM = "0"+playM;
	}
	
	//USED TO ADJUST POSITION IF EQUAL/LESS THAN 9 HOURS AND DRAW CONTENT
	if(playH <= 9){
		playH = "0"+playH;
	}

	//SAVE THE TOTAL TIME IN A VARIABLE FOR FURTHER USE, USED ONLY AT ENDING SCENES
	if(openborvariant("current_scene") == "data/scenes/ending_a.txt"){
		if(getglobalvar("totalPlayed") == NULL()){setglobalvar("totalPlayed", playH+":"+playM+":"+playS);}
	}
	else
	if(openborvariant("current_scene") == "data/scenes/ending_b.txt"){
		if(getglobalvar("totalPlayed") == NULL()){setglobalvar("totalPlayed", playH+":"+playM+":"+playS);}
	}
	else
	if(openborvariant("current_scene") == "data/scenes/ending_c.txt"){
		if(getglobalvar("totalPlayed") == NULL()){setglobalvar("totalPlayed", playH+":"+playM+":"+playS);}
	}
	
	//DRAW ALL CONTENT IN THE SCREEN
	if(getglobalvar("playedTime") == "on"){
		if(getglobalvar("activeText") != "Level" && getglobalvar("activeText") != "Survival"){

			//ADJUST THE POSITION TO FIT CORRECTLY IN THE COMPLETE SCREEN
			if(openborvariant("in_showcomplete")){
				xBase = 242;
				xDif  = 155;
				yBase = 209;
				font  = 0;
				drawstring(xBase-xDif, yBase, font, "played_time");
			}

			//DRAW ALL INFO IN THE SCREEN
			if(openborvariant("in_level") || openborvariant("in_showcomplete")){
				int dist1 = 30;				//DISTANCE BETWEEN SECONDS, MINUTES AND HOURS
				int dist2 = 39;				//IS THE FIRST ":" POSITION
				int dist3 = 9;				//IS THE SECOND ":" POSITION
				int xSec  = xBase;			//SECONDS POSITION IN X AXIS
				int xMin  = xSec-dist1;		//MINUTES POSITION IN X AXIS
				int xHour = xSec-dist1*2;	//HOURS POSITION IN X AXIS

				if(openborvariant("pause") == 0){
					drawstring(xSec-dist2, yBase, font, ":");
					drawstring(xSec-dist3, yBase, font, ":");
					drawstring(xSec, yBase, font, playS);
					drawstring(xMin, yBase, font, playM);
					drawstring(xHour, yBase, font, playH);
				}
			}
		}
	}
}
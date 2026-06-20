void drawClock()
{//Draw custom clock used for level timer
	float hRes		= openborvariant("hresolution");
	float time		= openborvariant("game_time");
	float channel	= 80;
	float maxTime	= 39600;
	float black		= rgbcolor(0x00,0x00,0x00);
	float red		= rgbcolor(0x80,0x00,0x00);
	float white		= rgbcolor(0xFF,0xFF,0xFF);
	int xSprite		= 226;
	int xBox		= 0;
	int yBox		= 269;
	int font0		= 3;
	int font1		= 7;
	int iconLayer	= 60000;
	int barLayer	= 50000;
	int backLayer	= 1000000001;
	int textLayer	= 1000000003;
	
	//APPLY DRAWMETHOD EFFECTS
	setdrawmethod(NULL(),1,256,256,0,0,0,6);
	changedrawmethod(NULL(), "channelr", channel); //CHANNEL DRAWMETHOD SETTINGS
	changedrawmethod(NULL(), "channelg", channel); //CHANNEL DRAWMETHOD SETTINGS
	changedrawmethod(NULL(), "channelb", channel); //CHANNEL DRAWMETHOD SETTINGS
	
	//GAME TIMER
	if(openborvariant("pause") == 0 && openborvariant("in_options") != 1){ //CHECK IF THE GAME IS NOT PAUSED OR IN OPTIONS
		if(getglobalvar("levelTime") == "timeline"){
			drawsprite(getglobalvar("timeIcon"), xSprite, 263, iconLayer); //TIME ICON
			drawbox(xBox, yBox, (maxTime*hRes)/(maxTime), 3, barLayer, black); //BLACK BORDER
			drawbox(xBox, yBox+1, (maxTime*hRes)/(maxTime), 1, barLayer+1, red); //RED FILL
			drawbox(xBox, yBox+1, (time*hRes)/(maxTime), 1, barLayer+2, white); //WHITE BAR
		}
		else
		if(getglobalvar("levelTime") == "numeric"){
			drawsprite(getglobalvar("timeIcon"), xSprite, 249, iconLayer); //TIME ICON
			drawstring((hRes-strwidth(""+time/400, font0))/2, 256, font0, time/400, barLayer); //CLOCK
		}
		else
		if(getglobalvar("levelTime") == "both"){
			drawsprite(getglobalvar("timeIcon"), xSprite, 246, iconLayer); //TIME ICON
			drawstring((hRes-strwidth(""+time/400, font0))/2, 253, font0, time/400, barLayer); //CLOCK
			drawbox(xBox, yBox, (maxTime*hRes)/(maxTime), 3, barLayer, black); //BLACK BORDER
			drawbox(xBox, yBox+1, (maxTime*hRes)/(maxTime), 1, barLayer+1, red); //RED FILL
			drawbox(xBox, yBox+1, (time*hRes)/(maxTime), 1, barLayer+2, white); //WHITE BAR
		}
	}
	
	//"CONTINUE" SCREEN TIMER
	if(getglobalvar("activeText") == "continue"){
		if(openborvariant("game_time") <= (maxTime/10) && openborvariant("game_time") > 0){
			setdrawmethod(NULL(),1,256,256,0,0,0,2);
			drawsprite(getglobalvar("back1"), 0, 0, backLayer);
			drawstring((hRes-strwidth("CONTINUE?", font1))/2+1, 120, font1, "CONTINUE?", textLayer);
			drawstring((hRes-strwidth(""+time/400, font1))/2+1, 138, font1, openborvariant("game_time")/400, textLayer);
		}else{
			setglobalvar("activeText", 0);
		}
	}
}
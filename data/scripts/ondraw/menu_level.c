void main()
{//Draw Level Select menu before start in Arcade/Rebellion modes
	void self  = getlocalvar("self");
	float hRes = openborvariant("hresolution");
	int xPos   = 49; 			//BASE X POSITION, FIRST COLUMN (HIGHLIGHTED OPTIONS NAME)
	int yPos   = 50;			//BASE Y POSITION FOR ALL MENU CONTENT IN GAME, USE THIS TO MOVE ALL OPTIONS TOGETHER
	int xAdd   = 50;			//DEFAULT X DIFFERENCE BETWEEN COLUMNS
	int yAdd   = 11;			//DEFAULT Y DIFFERENCE BETWEEN LINES
	int column = xPos;			//DEFAULT COLUMN VALUE
	int line   = yPos;			//DEFAULT LINE VALUE
	int layer  = 1000000003;	//DEFAULT LAYER VALUE
	int font0  = 0;
	int font1  = 1;
	int font2  = 2;

	//DRAW CONTENT
	//TITLE
	drawstring((hRes-strwidth("level_select", font2))/2, yPos-yAdd*3, font2, "level_select", layer);

	//CALCULATE ARROW POSITION AND MOVE IT
	int xCol  = column+(xAdd*getglobalvar("levelCol"));
	int yLine = line+(yAdd*getglobalvar("levelLine"));

	//CHANGE ARROW POSITION AND FONTS
	if(getglobalvar("levelSelected") == 1){
		drawstring(xCol-yAdd, yLine, font1, ">", layer);
	}else{
		drawstring(xCol-yAdd, yLine, font0, ">", layer);
	}
	//SOR1 LABEL
	drawstring(column-7, line-yAdd, font1, "#SOR1", layer);

	//COLUMN 1 - SOR1
	drawstring(column, line, font0, "st01", layer);	line = line+yAdd*2;

	//SOR2 LABEL
	drawstring(column-7, line-yAdd, font1, "#SOR2", layer);

	//COLUMN 1 - SOR2
	drawstring(column, line, font0, "st1a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st1b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st1c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//SOR3 LABEL
	drawstring(column-7, line-yAdd, font1, "#SOR3", layer);

	//COLUMN 1 - SOR3
	drawstring(column, line, font0, "st1a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st1b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st1c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 2 - SOR1
	drawstring(column, line, font0, "st02", layer);	line = line+yAdd*2;

	//COLUMN 2 - SOR2
	drawstring(column, line, font0, "st2a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st2b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st2c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 2 - SOR3
	drawstring(column, line, font0, "st2a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st2b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st2c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 3 - SOR1
	drawstring(column, line, font0, "st03", layer);	line = line+yAdd*2;

	//COLUMN 3 - SOR2
	drawstring(column, line, font0, "st3a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3e", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3f", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3g", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3h", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3i", layer);	line = line+yAdd*3;

	//COLUMN 3 - SOR3
	drawstring(column, line, font0, "st3a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st3c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 4 - SOR1
	drawstring(column, line, font0, "st04", layer);	line = line+yAdd*2;

	//COLUMN 4 - SOR2
	drawstring(column, line, font0, "st4a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st4b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st4c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st4d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 4 - SOR3
	drawstring(column, line, font0, "st4a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st4b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st4c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 5 - SOR1
	drawstring(column, line, font0, "st05", layer);	line = line+yAdd*2;

	//COLUMN 5 - SOR2
	drawstring(column, line, font0, "st5a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 5 - SOR3
	drawstring(column, line, font0, "st5a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st5e", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6g", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 6 - SOR1
	drawstring(column, line, font0, "st06", layer);	line = line+yAdd*2;

	//COLUMN 6 - SOR2
	drawstring(column, line, font0, "st6a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 6 - SOR3
	drawstring(column, line, font0, "st6a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6e", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st6f", layer);	line = yPos;

	column = column+xAdd;
	//COLUMN 7 - SOR1
	drawstring(column, line, font0, "st07", layer);	line = line+yAdd*2;

	//COLUMN 7 - SOR2
	drawstring(column, line, font0, "st7a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7c", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 7 - SOR3
	drawstring(column, line, font0, "st7a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st7e", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = yPos;

	column = column+xAdd;
	//COLUMN 8 - SOR1
	drawstring(column, line, font0, "st08", layer);	line = line+yAdd*2;

	//COLUMN 8 - SOR2
	drawstring(column, line, font0, "st8a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st8b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;

	//COLUMN 8 - SOR3
	drawstring(column, line, font0, "st8a", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st8b", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st8c", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st8d", layer);	line = line+yAdd;
	drawstring(column, line, font0, "st8e", layer);	line = line+yAdd;
	drawstring(column, line, font0, "-----", layer);line = line+yAdd*3;
	drawstring((hRes-strwidth("(press_start_to_begin,_or_jump_to_exit)", font2))/2, line, font2, "(press_start_to_begin,_or_jump_to_exit)", layer);
}
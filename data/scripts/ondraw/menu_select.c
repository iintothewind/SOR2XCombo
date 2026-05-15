void main()
{
	void self = getlocalvar("self");

	if(openborvariant("in_selectscreen")){
		if(openborvariant("current_set") != 2){drawHeroes();}
		if(openborvariant("current_set") == 2){drawEnemies();}
	}

	if(openborvariant("in_selectscreen") != 1){killentity(self);}
}

void drawHeroes()
{//Draw characters attributes in select screen
 //Thanks to msmalik681!!!
	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");

	//CHARACTERS INFO
	if(vName1){
		if(getglobalvar("previewModel0") == NULL()){setglobalvar("previewModel0", vName1);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		heroInfo(getglobalvar("previewModel0"), 0);
	}
	if(vName2){
		if(getglobalvar("previewModel1") == NULL()){setglobalvar("previewModel1", vName2);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		heroInfo(getglobalvar("previewModel1"), 1);
	}
	if(vName3){
		if(getglobalvar("previewModel2") == NULL()){setglobalvar("previewModel2", vName3);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		heroInfo(getglobalvar("previewModel2"), 2);
	}
	if(vName4){
		if(getglobalvar("previewModel3") == NULL()){setglobalvar("previewModel3", vName4);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		heroInfo(getglobalvar("previewModel3"), 3);
	}
}

void drawEnemies()
{//Draw characters attributes in select screen
 //Thanks to msmalik681!!!
 	void vName1	= getplayerproperty(0, "name");
	void vName2	= getplayerproperty(1, "name");
	void vName3	= getplayerproperty(2, "name");
	void vName4	= getplayerproperty(3, "name");

	//CHARACTERS INFO
	if(vName1){
		if(getglobalvar("previewModel0") == NULL()){setglobalvar("previewModel0", vName1);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		enemyInfo(getglobalvar("previewModel0"), 0);
	}
	if(vName2){
		if(getglobalvar("previewModel1") == NULL()){setglobalvar("previewModel1", vName2);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		enemyInfo(getglobalvar("previewModel1"), 1);
	}
	if(vName3){
		if(getglobalvar("previewModel2") == NULL()){setglobalvar("previewModel2", vName3);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		enemyInfo(getglobalvar("previewModel2"), 2);
	}
	if(vName4){
		if(getglobalvar("previewModel3") == NULL()){setglobalvar("previewModel3", vName4);} //USED TO GET THE PREVIEW MODEL BY THE FIRST TIME
		enemyInfo(getglobalvar("previewModel3"), 3);
	}
}

void heroInfo(void vName, int pIndex)
{//Script used to reduce code size

	if(vName){

		//GLOBAL USAGE
		void self 	= getlocalvar("self");
		void cursor;
		void previewEntity;
		void str;
		float hRes	= openborvariant("hresolution")+1;
		int xCol	= 413;	//X DIFERRENCE BETWEEN PLAYERS COLUMNS
		int yLine	= 135;	//X DIFERRENCE BETWEEN PLAYERS LINES
		int aniDif	= 4;	//DIFFERENCE BETWEEN "FOLLOW" ANIMATIONS (EX: FOLLOW1, FOLLOW2, FOLLOW3, ETC...)

		//GET THE CURRENT ANIMATION OF THE HIGHLIGHTED/SELECTED CHARACTER
		void aniPrev	= getentityproperty(getglobalvar("previewEntity"+pIndex), "animationID");
		void aniDef		= getentityproperty(getglobalvar("defaultEntity"+pIndex), "animationID");
		int frameDef	= getentityproperty(getglobalvar("defaultEntity"+pIndex), "animpos");
		int pNumber		= pIndex+1;

		//CALCULATE LINES AND COLUMNS FOR MODEL PREVIEW POSITION
		int xPrev	= 33;	//X VALUE USED TO ADJUST PREVIEW MODEL IN SELECT SCREEN
		int yPrev	= 131;	//Y VALUE USED TO ADJUST PREVIEW MODEL IN SELECT SCREEN
		int facing	= 1;

		if(pNumber == 2){xPrev = xPrev+xCol+facing;facing = 0;}
		if(pNumber == 3){yPrev = yPrev+yLine;}
		if(pNumber == 4){xPrev = xPrev+xCol+facing;yPrev = yPrev+yLine;facing = 0;}

		//SPAWN MODEL PREVIEW BY THE FIRST TIME
		if(getglobalvar("previewEntity"+pIndex) == NULL()){
			clearspawnentry();
			setspawnentry("name", vName);
			previewEntity = spawn();
			changeentityproperty(previewEntity, "type", openborconstant("TYPE_NPC"));
			changeentityproperty(previewEntity, "position", xPrev, yPrev, 0);
			changeentityproperty(previewEntity, "direction", facing);
			changeentityproperty(previewEntity, "animation", openborconstant("ANI_SELECT"));
			changeentityproperty(previewEntity, "map", pIndex);
			setglobalvar("previewMap"+pIndex, pIndex);
			setglobalvar("previewEntity"+pIndex, previewEntity);
		}

		//SPAWN CURSOR BY THE FIRST TIME
		if(getlocalvar("cursor"+pNumber) == NULL()){
			clearspawnentry();
			setspawnentry("name", "Cursor_A");
			cursor = spawn();
			changeentityproperty(cursor, "position", 0, 0, 0);
			changeentityproperty(cursor, "direction", 1);
			changeentityproperty(cursor, "animation", openborconstant("ANI_FOLLOW"+pNumber));
			setlocalvar("cursor"+pNumber, cursor);
		}

		//CHANGE CURSOR POSITION ACCORDING TO THE HERO'S NAME
		int xBase = 141;	//BASE X POSITION
		int yBase = 50;		//BASE Y POSITION
		int xMove = 110;	//DIFERRENCE BETWEEN PLAYER'S PORTRAITS COLUMNS
		int yMove = 54;		//DIFERRENCE BETWEEN PLAYER'S PORTRAITS LINES
		int xAdam = 36;		//DIFERRENCE BETWEEN PLAYER'S PORTRAITS COLUMNS ONLY FOR ADAM
		int xZan  = 74;		//DIFERRENCE BETWEEN PLAYER'S PORTRAITS COLUMNS ONLY FOR ZAN

		if(getlocalvar("cursor"+pNumber) != NULL()){
			if(vName == "Axel"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Axel_");
						setlocalvar("partnerCursorX", xBase); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase, yBase, 0);
			}

			if(vName == "Blaze"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Blaze_");
						setlocalvar("partnerCursorX", xBase+xMove); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase+xMove, yBase, 0);
			}

			if(vName == "Max"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Max_");
						setlocalvar("partnerCursorX", xBase); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase+yMove*2); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase, yBase+yMove*2, 0);
			}

			if(vName == "Sammy"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Sammy_");
						setlocalvar("partnerCursorX", xBase+xMove); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase+yMove*2); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase+xMove, yBase+yMove*2, 0);
			}

			if(vName == "Adam"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Adam_");
						setlocalvar("partnerCursorX", xBase+xAdam); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase+yMove); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase+xAdam, yBase+yMove, 0);
			}

			if(vName == "Zan"){
				if(getglobalvar("partnerIndex") == pIndex){
					if(getglobalvar("currentPartner") == NULL()){
						setglobalvar("selectPartner", "Zan_");
						setlocalvar("partnerCursorX", xBase+xZan); //SAVE PARTNER CURSOR X POSITION
						setlocalvar("partnerCursorY", yBase+yMove); //SAVE PARTNER CURSOR Y POSITION
					}
				}
				changeentityproperty(getlocalvar("cursor"+pNumber), "position", xBase+xZan, yBase+yMove, 0);
			}
		}

		//CALCULATE LINES AND COLUMNS FOR CHARACTER'S INFO POSITION
		int xName	= 3;			//X POSITION FOR THE MODEL NAME
		int yName	= 22;			//Y POSITION FOR THE MODEL NAME
		int xAtt1	= 69;			//FIRST COLUMN (ATTRIBUTES NAME)
		int xDif	= 52;			//DIFFERENCE BETWEEN COLUMNS
		int xAtt2	= xAtt1+xDif;	//SECOND COLUMN (ATTRIBUTES VALUE)
		int yAtt	= 49;			//FIRSL LINE (START POSITION)
		int yDif	= 6;			//Y DIFFERENCE FROM PLAYER NUMBER TO PLAYER NAME
		int yAdd	= 12;			//Y SPACE TO ADD BETWEEN EACH LINE
		int font0	= 0;			//ATTRIBUTES NAME FONT
		int font1	= 7;			//PLAYER NAME FONT
		int font2	= 9;			//ATTRIBUTES VALUE FONT
		int fontDif	= 3;			//USED TO CHANGE FONT COLOR ACCORDING TO THE PLAYER NUMBER

		//SMALL LEFT ALIGNMENT FOR PLAYERS 2 AND 4
		if(pNumber == 2 || pNumber == 4){xName = xName-2;xAtt2 = xAtt1+xDif-6;}

		//ADD A LINE IN THE ATTRIBUTE POSITION FOR PLAYERS 3 AND 4
		if(pNumber == 3 || pNumber == 4){yName = yName+yLine;yAtt = yAtt+yLine;}

		//DRAW CHARACTER'S INFO
		str = vName;
		if(pNumber == 1 || pNumber == 3){drawstring(xName, yName, font1, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font1)-xName, yName, font1, str);}

		str = pNumber+"p";
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt-yDif, pIndex+fontDif, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, pIndex+fontDif)-xAtt1, yAtt-yDif, pIndex+fontDif, str);}

		str = "SKILLS";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Skills");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "POWER";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Power");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "SPEED";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Speed");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "JUMP";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Jump");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "ENERGY";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Energy");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}
		yAtt = yAtt+yAdd;

		//THE CURRENT HIGHLIGHTED CHARACTER IS NOT CONFIRMED YET?? EXECUTE ALL TASKS BELOW
		if(aniPrev != openborconstant("ANI_PICK")){

			//MAKE SHAKE EFFECT WHEN THE HERO IS HIGHLIGHTED
			if(	playerkeys(pIndex, 1, "moveleft")	||
				playerkeys(pIndex, 1, "moveright")	||
				playerkeys(pIndex, 1, "moveup")		||
				playerkeys(pIndex, 1, "movedown")	){

				if(getentityproperty(getlocalvar("cursor"+pNumber), "animationID") != openborconstant("ANI_FOLLOW"+(pNumber+aniDif))){
					updateframe(getlocalvar("cursor"+pNumber), 0);
				}
			}

			if(aniDef == openborconstant("ANI_PICK")){

				//MAKE CHOSEN EFFECT WHEN THE HERO IS SELECTED
				if(vName == "Adam"){aniDif = aniDif*2;}
				if(vName == "Zan"){aniDif = aniDif*3;}

				if(getentityproperty(getlocalvar("cursor"+pNumber), "animationID") != openborconstant("ANI_FOLLOW"+(pNumber+aniDif))){
					changeentityproperty(getlocalvar("cursor"+pNumber), "animation", openborconstant("ANI_FOLLOW"+(pNumber+aniDif)));
				}

				//USED TO CONFIRM THE SELECTED CHARACTER AND CHANGE YOUR DEFAULT NAME/MODEL
				//CHANGE ANIMATION AND PLAYER NAME IF THE HIGHLIGHTED CHARACTER IS CHOSEN
				changeplayerproperty(pIndex, "name", getglobalvar("previewModel"+pIndex));
				changeentityproperty(getglobalvar("previewEntity"+pIndex), "animation", openborconstant("ANI_PICK"));
			}
		}

		//THE CURRENT HIGHLIGHTED CHARACTER IS ALREADY CONFIRMED?? EXECUTE ALL TASKS BELOW
		if(aniPrev == openborconstant("ANI_PICK")){
			void colorBar	= "M";
			void arrowLeft	= "I";
			void arrowRight	= "J";
			int xAdjust		= 5;

			if(frameDef <= 0){

				//SHOW PALETTE CURSOR CHANGES, IT'S A VISUAL FEATURE ONLY (BUTTON HELD)
				if(playerkeys(pIndex, 0, "moveleft")){arrowLeft = "K";}
				if(playerkeys(pIndex, 0, "moveright")){arrowRight = "L";}

				str = ""+arrowLeft+colorBar+arrowRight;
				if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font2, str);}
				if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt1+xAdjust, yAtt, font2, str);}

				//CHANGE PALETTE WHEN MOVE LEFT (BUTTON PRESS)
				if(playerkeys(pIndex, 1, "moveleft")){
					int map 	= getglobalvar("previewMap"+pIndex);
					int count 	= getentityproperty(getglobalvar("previewEntity"+pIndex), "mapcount")-1;

					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

					if(map > 0 && map <= count){
						setglobalvar("previewMap"+pIndex, map-1);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
					if(map == 0){
						setglobalvar("previewMap"+pIndex, count);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
				}

				//CHANGE PALETTE WHEN MOVE RIGHT (BUTTON PRESS)
				if(playerkeys(pIndex, 1, "moveright")){
					int map 	= getglobalvar("previewMap"+pIndex);
					int count 	= getentityproperty(getglobalvar("previewEntity"+pIndex), "mapcount")-1;

					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

					if(map >= 0 && map < count){
						setglobalvar("previewMap"+pIndex, map+1);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
					if(map == count){
						setglobalvar("previewMap"+pIndex, 0);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
				}

				//CONFIRM THE SELECTED PALETTE AND APPLY IT
				if(playerkeys(pIndex, 1, "anybutton")){
					playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					updateframe(getglobalvar("previewEntity"+pIndex), 1);
					updateframe(getglobalvar("defaultEntity"+pIndex), 1);
					changeplayerproperty(pIndex, "colourmap", getglobalvar("previewMap"+pIndex));
				}
			}
		}

		//SPAWN CPU PARTNER CURSOR IN SELECT SCREEN
		if(getglobalvar("partnerIndex") != NULL()){
			if(getlocalvar("partnerCursor") == NULL()){
				clearspawnentry();
				setspawnentry("name", "Cursor_A");
				cursor = spawn();
				changeentityproperty(cursor, "position", getlocalvar("partnerCursorX"), getlocalvar("partnerCursorY"), 0);
				changeentityproperty(cursor, "direction", 1);
				changeentityproperty(cursor, "animation", openborconstant("ANI_FOLLOW17"));
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
				setlocalvar("partnerCursor", cursor);
			}
		}

		//MISC CPU PARTNER TASKS
		if(getglobalvar("partnerIndex") != NULL()){

			//CHANGE CPU PARTNER CURSOR POSITION IN SELECT SCREEN
			if(getlocalvar("partnerCursor") != NULL() && getglobalvar("currentPartner") == NULL()){
				changeentityproperty(getlocalvar("partnerCursor"), "position", getlocalvar("partnerCursorX"), getlocalvar("partnerCursorY"), 0);
			}

			//MAKE SHAKE EFFECT WHEN THE CPU PARTNER IS HIGHLIGHTED
			if(	playerkeys(pIndex, 1, "moveleft")	||
				playerkeys(pIndex, 1, "moveright")	||
				playerkeys(pIndex, 1, "moveup")		||
				playerkeys(pIndex, 1, "movedown")	){

				if(getlocalvar("partnerCursor") != NULL()){
					if(getentityproperty(getlocalvar("partnerCursor"), "animationID") == openborconstant("ANI_FOLLOW17")){updateframe(getlocalvar("partnerCursor"), 0);}
				}
			}

			//MAKE CHOSEN EFFECT WHEN THE CPU PARTNER IS SELECTED
			if(getlocalvar("partnerCursor") != NULL() && getglobalvar("currentPartner") != NULL()){
				if(getentityproperty(getlocalvar("partnerCursor"), "animationID") == openborconstant("ANI_FOLLOW17")){
					changeentityproperty(getlocalvar("partnerCursor"), "animation", openborconstant("ANI_FOLLOW18"));
					changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
				}
			}

			//CHANGE CPU PARTNER CURSOR ANIMATION IN SELECT SCREEN IF THE HIGHLIGHTED CHARACTER IS BLOCKED
			if(getlocalvar("partnerCursor") != NULL() && getglobalvar("blockedPartner") == 1){
				if(getentityproperty(getlocalvar("partnerCursor"), "animationID") == openborconstant("ANI_FOLLOW17")){
					changeentityproperty(getlocalvar("partnerCursor"), "animation", openborconstant("ANI_FOLLOW19"));
					setglobalvar("blockedPartner", 0); //SET AS CURRENT BLOCKED PARTNER
				}
			}
		}
	}
}

void enemyInfo(void vName, int pIndex)
{//Script used to reduce code size

	if(vName){

		//GLOBAL USAGE
		void self 	= getlocalvar("self");
		void cursor;
		void previewEntity;
		void str;
		float hRes	= openborvariant("hresolution")+1;
		int xCol	= 413;	//X DIFERRENCE BETWEEN PLAYERS COLUMNS
		int yLine	= 135;	//X DIFERRENCE BETWEEN PLAYERS LINES
		int aniDif	= 4;	//DIFFERENCE BETWEEN "FOLLOW" ANIMATIONS (EX: FOLLOW1, FOLLOW2, FOLLOW3, ETC...)

		//GET THE CURRENT ANIMATION OF THE HIGHLIGHTED/SELECTED CHARACTER
		void aniPrev	= getentityproperty(getglobalvar("previewEntity"+pIndex), "animationID");
		void aniDef		= getentityproperty(getglobalvar("defaultEntity"+pIndex), "animationID");
		int frameDef	= getentityproperty(getglobalvar("defaultEntity"+pIndex), "animpos");
		int pNumber		= pIndex+1;

		//CALCULATE LINES AND COLUMNS FOR MODEL PREVIEW POSITION
		int xPrev	= 33;	//X VALUE USED TO ADJUST PREVIEW MODEL IN SELECT SCREEN
		int yPrev	= 131;	//Y VALUE USED TO ADJUST PREVIEW MODEL IN SELECT SCREEN
		int facing	= 1;

		if(pNumber == 2){xPrev = xPrev+xCol+facing;facing = 0;}
		if(pNumber == 3){yPrev = yPrev+yLine;}
		if(pNumber == 4){xPrev = xPrev+xCol+facing;yPrev = yPrev+yLine;facing = 0;}

		//SPAWN MODEL PREVIEW BY THE FIRST TIME
		if(getglobalvar("previewEntity"+pIndex) == NULL()){
			clearspawnentry();
			setspawnentry("name", vName);
			previewEntity = spawn();
			changeentityproperty(previewEntity, "type", openborconstant("TYPE_NPC"));
			changeentityproperty(previewEntity, "position", xPrev, yPrev, 0);
			changeentityproperty(previewEntity, "direction", facing);
			changeentityproperty(previewEntity, "animation", openborconstant("ANI_SELECT"));
			changeentityproperty(previewEntity, "map", pIndex);
			setglobalvar("previewMap"+pIndex, pIndex);
			setglobalvar("previewEntity"+pIndex, previewEntity);
		}

		//SPAWN CURSOR BY THE FIRST TIME
		if(getlocalvar("cursor"+pNumber) == NULL()){
			clearspawnentry();
			setspawnentry("name", "Cursor_B");
			cursor = spawn();
			changeentityproperty(cursor, "position", 0, 0, 0);
			changeentityproperty(cursor, "direction", 1);
			changeentityproperty(cursor, "animation", openborconstant("ANI_FOLLOW"+pNumber));
			setlocalvar("cursor"+pNumber, cursor);
		}

		//CHANGE CURSOR POSITION ACCORDING TO THE HERO'S NAME
		int xBase = 150;	//BASE X POSITION
		int yBase = 65;		//BASE Y POSITION
		int xAdd  = 18;		//DIFERRENCE BETWEEN PLAYER'S PORTRAITS COLUMNS
		int yAdd  = 18;		//DIFERRENCE BETWEEN PLAYER'S PORTRAITS LINES
		int xMove;			//FINAL X POSITION RESULT
		int yMove;			//FINAL Y POSITION RESULT


		if(getlocalvar("cursor"+pNumber) != NULL()){

			//FIRST LINE
			xMove = xBase;
			yMove = yBase;

			if(vName == "Galsia"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Donovan"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Signal"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Fog"){			changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Hakuyo"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Kusanagi"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Raven"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Big-Ben"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Electra_"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Jack"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;

			//SECOND LINE
			xMove = xBase;
			yMove = yMove+yAdd;

			if(vName == "Slum"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Vice"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Garnet"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Macleod"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Tiger"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "P-1"){			changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Bongo"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Electra"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Ash"){			changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Bruce"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;

			//THIRD LINE
			xMove = xBase;
			yMove = yMove+yAdd;

			if(vName == "Roo"){			changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Barbon"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Jet"){			changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Zamza"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Abadede"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "R._Bear"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Particle"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Shiva"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Mr._X"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Monalisa"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;

			//FOURTH LINE
			xMove = xBase;
			yMove = yMove+yAdd;

			if(vName == "Break"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Yamato"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Robot_X"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Jet_"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Shiva_"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Neo._X"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Harakiri"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Tracker"){		changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}xMove = xMove+xAdd;
			if(vName == "Ringmaster"){	changeentityproperty(getlocalvar("cursor"+pNumber), "position", xMove, yMove, 0);}
		}

		//CALCULATE LINES AND COLUMNS FOR CHARACTER'S INFO POSITION
		int xName	= 3;			//X POSITION FOR THE MODEL NAME
		int yName	= 22;			//Y POSITION FOR THE MODEL NAME
		int xAtt1	= 69;			//FIRST COLUMN (ATTRIBUTES NAME)
		int xDif	= 52;			//DIFFERENCE BETWEEN COLUMNS
		int xAtt2	= xAtt1+xDif;	//SECOND COLUMN (ATTRIBUTES VALUE)
		int yAtt	= 49;			//FIRSL LINE (START POSITION)
		int yDif	= 6;			//Y DIFFERENCE FROM PLAYER NUMBER TO PLAYER NAME
		int yAdd	= 12;			//Y SPACE TO ADD BETWEEN EACH LINE
		int font0	= 0;			//ATTRIBUTES NAME FONT
		int font1	= 7;			//PLAYER NAME FONT
		int font2	= 9;			//ATTRIBUTES VALUE FONT
		int fontDif	= 3;			//USED TO CHANGE FONT COLOR ACCORDING TO THE PLAYER NUMBER

		//SMALL LEFT ALIGNMENT FOR PLAYERS 2 AND 4
		if(pNumber == 2 || pNumber == 4){xName = xName-2;xAtt2 = xAtt1+xDif-6;}

		//ADD A LINE IN THE ATTRIBUTE POSITION FOR PLAYERS 3 AND 4
		if(pNumber == 3 || pNumber == 4){yName = yName+yLine;yAtt = yAtt+yLine;}

		//DRAW CHARACTER'S INFO
		str = vName;
		if(pNumber == 1 || pNumber == 3){drawstring(xName, yName, font1, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font1)-xName, yName, font1, str);}

		str = pNumber+"p";
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt-yDif, pIndex+fontDif, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, pIndex+fontDif)-xAtt1, yAtt-yDif, pIndex+fontDif, str);}

		str = "SKILLS";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Skills");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "POWER";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Power");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "SPEED";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Speed");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "JUMP";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Jump");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}

		str = "ENERGY";
		yAtt = yAtt+yAdd;
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font0, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font0)-xAtt1, yAtt, font0, str);}
		str = ""+getglobalvar(vName+"Energy");
		if(pNumber == 1 || pNumber == 3){drawstring(xAtt2, yAtt, font2, str);}
		if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt2, yAtt, font2, str);}
		yAtt = yAtt+yAdd;

		//THE CURRENT HIGHLIGHTED CHARACTER IS NOT CONFIRMED YET?? EXECUTE ALL TASKS BELOW
		if(aniPrev != openborconstant("ANI_PICK")){

			//MAKE SHAKE EFFECT WHEN THE HERO IS HIGHLIGHTED
			if(	playerkeys(pIndex, 1, "moveleft")	||
				playerkeys(pIndex, 1, "moveright")	||
				playerkeys(pIndex, 1, "moveup")		||
				playerkeys(pIndex, 1, "movedown")	){

				if(getentityproperty(getlocalvar("cursor"+pNumber), "animationID") != openborconstant("ANI_FOLLOW"+(pNumber+aniDif))){
					updateframe(getlocalvar("cursor"+pNumber), 0);
				}
			}

			if(aniDef == openborconstant("ANI_PICK")){

				//MAKE CHOSEN EFFECT WHEN THE HERO IS SELECTED
				if(getentityproperty(getlocalvar("cursor"+pNumber), "animationID") != openborconstant("ANI_FOLLOW"+(pNumber+aniDif))){
					changeentityproperty(getlocalvar("cursor"+pNumber), "animation", openborconstant("ANI_FOLLOW"+(pNumber+aniDif)));
				}

				//USED TO CONFIRM THE SELECTED CHARACTER AND CHANGE YOUR DEFAULT NAME/MODEL
				//CHANGE ANIMATION AND PLAYER NAME IF THE HIGHLIGHTED CHARACTER IS CHOSEN
				changeplayerproperty(pIndex, "name", getglobalvar("previewModel"+pIndex));
				changeentityproperty(getglobalvar("previewEntity"+pIndex), "animation", openborconstant("ANI_PICK"));
			}
		}

		//THE CURRENT HIGHLIGHTED CHARACTER IS ALREADY CONFIRMED?? EXECUTE ALL TASKS BELOW
		if(aniPrev == openborconstant("ANI_PICK")){
			void colorBar	= "M";
			void arrowLeft	= "I";
			void arrowRight	= "J";
			int xAdjust		= 5;

			if(frameDef <= 0){

				//SHOW PALETTE CURSOR CHANGES, IT'S A VISUAL FEATURE ONLY (BUTTON HELD)
				if(playerkeys(pIndex, 0, "moveleft")){arrowLeft = "K";}
				if(playerkeys(pIndex, 0, "moveright")){arrowRight = "L";}

				str = ""+arrowLeft+colorBar+arrowRight;
				if(pNumber == 1 || pNumber == 3){drawstring(xAtt1, yAtt, font2, str);}
				if(pNumber == 2 || pNumber == 4){drawstring(hRes-strwidth(str, font2)-xAtt1+xAdjust, yAtt, font2, str);}

				//CHANGE PALETTE WHEN MOVE LEFT (BUTTON PRESS)
				if(playerkeys(pIndex, 1, "moveleft")){
					int map 	= getglobalvar("previewMap"+pIndex);
					int count 	= getentityproperty(getglobalvar("previewEntity"+pIndex), "mapcount")-1;

					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

					if(map > 0 && map <= count){
						setglobalvar("previewMap"+pIndex, map-1);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
					if(map == 0){
						setglobalvar("previewMap"+pIndex, count);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
				}

				//CHANGE PALETTE WHEN MOVE RIGHT (BUTTON PRESS)
				if(playerkeys(pIndex, 1, "moveright")){
					int map 	= getglobalvar("previewMap"+pIndex);
					int count 	= getentityproperty(getglobalvar("previewEntity"+pIndex), "mapcount")-1;

					playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

					if(map >= 0 && map < count){
						setglobalvar("previewMap"+pIndex, map+1);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
					if(map == count){
						setglobalvar("previewMap"+pIndex, 0);
						changeentityproperty(getglobalvar("previewEntity"+pIndex), "map", getglobalvar("previewMap"+pIndex));
					}
				}

				//CONFIRM THE SELECTED PALETTE AND APPLY IT
				if(playerkeys(pIndex, 1, "anybutton")){
					playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
					updateframe(getglobalvar("previewEntity"+pIndex), 1);
					updateframe(getglobalvar("defaultEntity"+pIndex), 1);
					changeplayerproperty(pIndex, "colourmap", getglobalvar("previewMap"+pIndex));
				}
			}
		}
	}
}
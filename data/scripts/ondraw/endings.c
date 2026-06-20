void main()
{//Draw ending content
	void self 	= getlocalvar("self");
	void name	= getentityproperty(self, "defaultname");
	void str;
	float hRes	= openborvariant("hresolution");
	int frame	= getentityproperty(self, "animpos");
	int y		= getentityproperty(self, "y");
	int z		= getentityproperty(self, "z");
	int zDir	= getentityproperty(self, "zdir");
	int font0	= 0;
	int font1	= 1;
	int font2	= 7;
	int layer1	= 100000100;
	int layer2	= 100000004;
	int layer3	= 1001;
	int yPos	= 1-z;
	int yAdd	= 15;
	int yGroup	= 9;
	int yEnd	= 220;
	int zStop	= 1665;
	int align;

	if(openborvariant("current_scene") == "data/scenes/ending_a.txt" || openborvariant("current_scene") == "data/scenes/ending_c.txt"){
		if(name == "Ending_A2" || name == "Ending_C2"){

			//FADE TEXT
			changedrawmethod(NULL(), "enabled", 1);
			changedrawmethod(NULL(), "alpha", 2);
			drawsprite(getglobalvar("textFade"), 0, 0, 1000000000);

			//GAME DESIGN/PROGRAM
			str = "GAME DESIGN AND PROGRAM";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "FLAVIO MARTIN (KRATUS)";align = align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//ENGINE HELP AND TESTS
			yPos = yPos+yAdd*yGroup;str = "ENGINE HELP AND TESTS";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "PUDU";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "TETSUO9999";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "KIMONO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "O ILUSIONISTA";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "ADRIMUS";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "PEPODMC";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "YMB 9 SHINZOU";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "DAMON CASKEY";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "MOHAMMED MALIK";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "DAVPREEC";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "BRUNO ALENCAR";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "NIKOLAY PUZYRKOV";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "MR. DIN";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "DAFAMILY";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "ANTHOPANTS";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "MIRU";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "LORD KARASUMAN";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "PSYKAI";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "Yinghua Chen";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//SUPPORT
			yPos = yPos+yAdd*yGroup;str = "SUPPORT";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "DANIEL JOHNSON (DANNO)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "JAMES P. INGRASSIA";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "CIKA3000";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "BENITO JUAREZ";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "GRANT";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "REECE RAPIER";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "SHAUN KING (BLACK SUNSHINE)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "GOVINDER KALSI (COMBO)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "GILBERTO MELO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "LAWRENCE DECHICO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//GRAPHICS
			yPos = yPos+yAdd*yGroup;str = "GRAPHICS";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "KIMONO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "DAORS";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "O ILUSIONISTA";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "ADRIMUS";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "LUKE K.";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "CAJNATALIE";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//MUSICS
			yPos = yPos+yAdd*yGroup;str = "MUSICS";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "BOMBERGAMES (ALL REMIXES)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "VERTIPHON (ORIGINAL REMASTERS)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "MUHAMAD SAEED (SOR3 'GOOD ENDING')";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//SPECIAL THANKS
			yPos = yPos+yAdd*yGroup;str = "SPECIAL THANKS";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);
			yPos = yPos+yAdd;str = "SEGA";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "YUZO KOSHIRO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "AYANO KOSHIRO";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "MOTOHIRO KAWASHIMA";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "BOMBERGAMES";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "SENILE TEAM";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "CHRONO CRASH";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "DAMON CASKEY";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "PONDERPOL";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);
			yPos = yPos+yAdd;str = "KLETONSS";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//AND YOU
			yPos = yPos+yAdd*yGroup;str = "AND YOU...";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//PAUL CLARK TRIBUTE
			yPos = yPos+yAdd*yGroup;str = "IN MEMORY OF PAUL CLARK (BGM1401)";align = (hRes-strwidth(str, font0))/2;
			drawstring(align, yPos, font0, str, layer1);

			//THANKS FOR PLAYING
			yPos = yPos+yAdd*yGroup;str = "THANKS FOR PLAYING!";align = (hRes-strwidth(str, font1))/2;
			drawstring(align, yPos, font1, str, layer1);

			//USED TO STOP SCROLLING AT DEFINED POINT
			//NEED TO READJUST THE "ZSTOP" EVERYTIME SOME NEW TEXT IS ADDED (+13 PIXELS TO "ZSTOP" VALUE BY EACH CONTENT LINE ADDED)
			if(z >= zStop && zDir != 0){changeentityproperty(self, "velocity", 0, 0, 0);}
		}
	}
	else
	if(openborvariant("current_scene") == "data/scenes/ending_b.txt"){
		changedrawmethod(NULL(), "enabled", 0);

		if(name == "Ending_B"){
			if(frame < 20){drawsprite(getglobalvar("sor3_endb1"), 0, 0, layer1);}
			if(frame >= 3 && frame < 19){drawsprite(getglobalvar("sor3_endb2"), 0, 0, layer2);}
			if(frame > 29){drawstring((hRes-(strwidth("THE_END?", font2)-1))/2, yEnd, font2, "THE_END?", layer3);}
		}
	}
	else
	{
		killentity(self);
	}
}
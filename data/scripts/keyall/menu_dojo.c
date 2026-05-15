void menuDojo(int player)
{
  if(getglobalvar("dojoStage") == NULL()) {
    setglobalvar("dojoStage", "Dojo");
  }

  if(getglobalvar("dojoOpponent") == NULL()) {
    setglobalvar("dojoOpponent", "Kun");
  }

  if(getglobalvar("dojoEnergyRate") == NULL()) {
    setglobalvar("dojoEnergyRate", 0);
  }


	int highlight = getglobalvar("highlight");

	if(getglobalvar("activeText") == "Dojo"){
		if(playerkeys(player, 1, "movedown")){ //HIGHLIGHT OPTIONS
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
      if(highlight == 0){setglobalvar("highlight", 1);}
      if(highlight == 1){setglobalvar("highlight", 2);}
      if(highlight == 2){setglobalvar("highlight", 0);}
		}

		//HIGHLIGHT OPTIONS WHEN MOVE UP
		if(playerkeys(player, 1, "moveup")){
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
      if(highlight == 0){setglobalvar("highlight", 2);}
      if(highlight == 2){setglobalvar("highlight", 1);}
      if(highlight == 1){setglobalvar("highlight", 0);}
		}

		if(playerkeys(player, 1, "moveright")){
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

			if(getglobalvar("highlight") == 0){
        if(getglobalvar("dojoStage") == "Dojo"){setglobalvar("dojoStage", "Sea01");}else
        if(getglobalvar("dojoStage") == "Sea01"){setglobalvar("dojoStage", "Sea02");}else
        if(getglobalvar("dojoStage") == "Sea02"){setglobalvar("dojoStage", "ChinaTown");}else
        if(getglobalvar("dojoStage") == "ChinaTown"){setglobalvar("dojoStage", "Dojo");}
      }

			if(getglobalvar("highlight") == 1){
        if(getglobalvar("dojoOpponent") == "Kun"){setglobalvar("dojoOpponent", "Abadede");}else
        if(getglobalvar("dojoOpponent") == "Abadede"){setglobalvar("dojoOpponent", "Ash");}else
        if(getglobalvar("dojoOpponent") == "Ash"){setglobalvar("dojoOpponent", "Barbon");}else
        if(getglobalvar("dojoOpponent") == "Barbon"){setglobalvar("dojoOpponent", "Bear");}else
        if(getglobalvar("dojoOpponent") == "Bear"){setglobalvar("dojoOpponent", "Bison");}else
        if(getglobalvar("dojoOpponent") == "Bison"){setglobalvar("dojoOpponent", "Break");}else
        if(getglobalvar("dojoOpponent") == "Break"){setglobalvar("dojoOpponent", "Tamer");}else
        if(getglobalvar("dojoOpponent") == "Tamer"){setglobalvar("dojoOpponent", "Chunli");}else
        if(getglobalvar("dojoOpponent") == "Chunli"){setglobalvar("dojoOpponent", "HarakiriB");}else
        if(getglobalvar("dojoOpponent") == "HarakiriB"){setglobalvar("dojoOpponent", "HarakiriD");}else
        if(getglobalvar("dojoOpponent") == "HarakiriD"){setglobalvar("dojoOpponent", "Jet");}else
        if(getglobalvar("dojoOpponent") == "Jet"){setglobalvar("dojoOpponent", "Kage");}else
        if(getglobalvar("dojoOpponent") == "Kage"){setglobalvar("dojoOpponent", "Lee");}else
        if(getglobalvar("dojoOpponent") == "Lee"){setglobalvar("dojoOpponent", "Monalisa");}else
        if(getglobalvar("dojoOpponent") == "Monalisa"){setglobalvar("dojoOpponent", "MrX");}else
        if(getglobalvar("dojoOpponent") == "MrX"){setglobalvar("dojoOpponent", "NeoX");}else
        if(getglobalvar("dojoOpponent") == "NeoX"){setglobalvar("dojoOpponent", "Particle");}else
        if(getglobalvar("dojoOpponent") == "Particle"){setglobalvar("dojoOpponent", "Reine");}else
        if(getglobalvar("dojoOpponent") == "Reine"){setglobalvar("dojoOpponent", "RingMaster");}else
        if(getglobalvar("dojoOpponent") == "RingMaster"){setglobalvar("dojoOpponent", "RobotX");}else
        if(getglobalvar("dojoOpponent") == "RobotX"){setglobalvar("dojoOpponent", "Rocket");}else
        if(getglobalvar("dojoOpponent") == "Rocket"){setglobalvar("dojoOpponent", "SOR2_Shiva");}else
        if(getglobalvar("dojoOpponent") == "SOR2_Shiva"){setglobalvar("dojoOpponent", "SOR3_Shiva");}else
        if(getglobalvar("dojoOpponent") == "SOR3_Shiva"){setglobalvar("dojoOpponent", "Tracker");}else
        if(getglobalvar("dojoOpponent") == "Tracker"){setglobalvar("dojoOpponent", "Yamato");}else
        if(getglobalvar("dojoOpponent") == "Yamato"){setglobalvar("dojoOpponent", "Musashi");}else
        if(getglobalvar("dojoOpponent") == "Musashi"){setglobalvar("dojoOpponent", "Zamza");}else
        if(getglobalvar("dojoOpponent") == "Zamza"){setglobalvar("dojoOpponent", "Jack");}else
        if(getglobalvar("dojoOpponent") == "Jack"){setglobalvar("dojoOpponent", "Raven");}else
        if(getglobalvar("dojoOpponent") == "Raven"){setglobalvar("dojoOpponent", "Hakuyo");}else
        if(getglobalvar("dojoOpponent") == "Hakuyo"){setglobalvar("dojoOpponent", "Tiger");}else
        if(getglobalvar("dojoOpponent") == "Tiger"){setglobalvar("dojoOpponent", "Bongo");}else
        if(getglobalvar("dojoOpponent") == "Bongo"){setglobalvar("dojoOpponent", "BigBen");}else
        if(getglobalvar("dojoOpponent") == "BigBen"){setglobalvar("dojoOpponent", "Electra");}else
        if(getglobalvar("dojoOpponent") == "Electra"){setglobalvar("dojoOpponent", "Kusanagi");}else
        if(getglobalvar("dojoOpponent") == "Kusanagi"){setglobalvar("dojoOpponent", "Joker");}else
        if(getglobalvar("dojoOpponent") == "Joker"){setglobalvar("dojoOpponent", "Roo");}else
        if(getglobalvar("dojoOpponent") == "Roo"){setglobalvar("dojoOpponent", "Signal");}else
        if(getglobalvar("dojoOpponent") == "Signal"){setglobalvar("dojoOpponent", "Kun");}
      }

			if(getglobalvar("highlight") == 2){
        if(getglobalvar("dojoEnergyRate") == 0){setglobalvar("dojoEnergyRate", 5);}else
        if(getglobalvar("dojoEnergyRate") == 5){setglobalvar("dojoEnergyRate", 10);}else
        if(getglobalvar("dojoEnergyRate") == 10){setglobalvar("dojoEnergyRate", 15);}else
        if(getglobalvar("dojoEnergyRate") == 15){setglobalvar("dojoEnergyRate", 20);}else
        if(getglobalvar("dojoEnergyRate") == 20){setglobalvar("dojoEnergyRate", 25);}else
        if(getglobalvar("dojoEnergyRate") == 25){setglobalvar("dojoEnergyRate", 0);}
      }
		}

		if(playerkeys(player, 1, "moveleft")){
			playsample(openborconstant("SAMPLE_BEEP"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);

			if(getglobalvar("highlight") == 0){
        if(getglobalvar("dojoStage") == "Dojo"){setglobalvar("dojoStage", "ChinaTown");}else
        if(getglobalvar("dojoStage") == "ChinaTown"){setglobalvar("dojoStage", "Sea02");}else
        if(getglobalvar("dojoStage") == "Sea02"){setglobalvar("dojoStage", "Sea01");}else
        if(getglobalvar("dojoStage") == "Sea01"){setglobalvar("dojoStage", "Dojo");}
      }

			if(getglobalvar("highlight") == 1){
        if(getglobalvar("dojoOpponent") == "Kun"){setglobalvar("dojoOpponent", "Signal");}else
        if(getglobalvar("dojoOpponent") == "Signal"){setglobalvar("dojoOpponent", "Roo");}else
        if(getglobalvar("dojoOpponent") == "Roo"){setglobalvar("dojoOpponent", "Joker");}else
        if(getglobalvar("dojoOpponent") == "Joker"){setglobalvar("dojoOpponent", "Kusanagi");}else
        if(getglobalvar("dojoOpponent") == "Kusanagi"){setglobalvar("dojoOpponent", "Electra");}else
        if(getglobalvar("dojoOpponent") == "Electra"){setglobalvar("dojoOpponent", "BigBen");}else
        if(getglobalvar("dojoOpponent") == "BigBen"){setglobalvar("dojoOpponent", "Bongo");}else
        if(getglobalvar("dojoOpponent") == "Bongo"){setglobalvar("dojoOpponent", "Tiger");}else
        if(getglobalvar("dojoOpponent") == "Tiger"){setglobalvar("dojoOpponent", "Hakuyo");}else
        if(getglobalvar("dojoOpponent") == "Hakuyo"){setglobalvar("dojoOpponent", "Raven");}else
        if(getglobalvar("dojoOpponent") == "Raven"){setglobalvar("dojoOpponent", "Jack");}else
        if(getglobalvar("dojoOpponent") == "Jack"){setglobalvar("dojoOpponent", "Zamza");}else
        if(getglobalvar("dojoOpponent") == "Zamza"){setglobalvar("dojoOpponent", "Musashi");}else
        if(getglobalvar("dojoOpponent") == "Musashi"){setglobalvar("dojoOpponent", "Yamato");}else
        if(getglobalvar("dojoOpponent") == "Yamato"){setglobalvar("dojoOpponent", "Tracker");}else
        if(getglobalvar("dojoOpponent") == "Tracker"){setglobalvar("dojoOpponent", "SOR3_Shiva");}else
        if(getglobalvar("dojoOpponent") == "SOR3_Shiva"){setglobalvar("dojoOpponent", "SOR2_Shiva");}else
        if(getglobalvar("dojoOpponent") == "SOR2_Shiva"){setglobalvar("dojoOpponent", "Rocket");}else
        if(getglobalvar("dojoOpponent") == "Rocket"){setglobalvar("dojoOpponent", "RobotX");}else
        if(getglobalvar("dojoOpponent") == "RobotX"){setglobalvar("dojoOpponent", "RingMaster");}else
        if(getglobalvar("dojoOpponent") == "RingMaster"){setglobalvar("dojoOpponent", "Reine");}else
        if(getglobalvar("dojoOpponent") == "Reine"){setglobalvar("dojoOpponent", "Particle");}else
        if(getglobalvar("dojoOpponent") == "Particle"){setglobalvar("dojoOpponent", "NeoX");}else
        if(getglobalvar("dojoOpponent") == "NeoX"){setglobalvar("dojoOpponent", "MrX");}else
        if(getglobalvar("dojoOpponent") == "MrX"){setglobalvar("dojoOpponent", "Monalisa");}else
        if(getglobalvar("dojoOpponent") == "Monalisa"){setglobalvar("dojoOpponent", "Lee");}else
        if(getglobalvar("dojoOpponent") == "Lee"){setglobalvar("dojoOpponent", "Kage");}else
        if(getglobalvar("dojoOpponent") == "Kage"){setglobalvar("dojoOpponent", "Jet");}else
        if(getglobalvar("dojoOpponent") == "Jet"){setglobalvar("dojoOpponent", "HarakiriD");}else
        if(getglobalvar("dojoOpponent") == "HarakiriD"){setglobalvar("dojoOpponent", "HarakiriB");}else
        if(getglobalvar("dojoOpponent") == "HarakiriB"){setglobalvar("dojoOpponent", "Chunli");}else
        if(getglobalvar("dojoOpponent") == "Chunli"){setglobalvar("dojoOpponent", "Tamer");}else
        if(getglobalvar("dojoOpponent") == "Tamer"){setglobalvar("dojoOpponent", "Break");}else
        if(getglobalvar("dojoOpponent") == "Break"){setglobalvar("dojoOpponent", "Bison");}else
        if(getglobalvar("dojoOpponent") == "Bison"){setglobalvar("dojoOpponent", "Bear");}else
        if(getglobalvar("dojoOpponent") == "Bear"){setglobalvar("dojoOpponent", "Barbon");}else
        if(getglobalvar("dojoOpponent") == "Barbon"){setglobalvar("dojoOpponent", "Ash");}else
        if(getglobalvar("dojoOpponent") == "Ash"){setglobalvar("dojoOpponent", "Abadede");}else
        if(getglobalvar("dojoOpponent") == "Abadede"){setglobalvar("dojoOpponent", "Kun");}
      }

			if(getglobalvar("highlight") == 2){
        if(getglobalvar("dojoEnergyRate") == 25){setglobalvar("dojoEnergyRate", 20);}else
        if(getglobalvar("dojoEnergyRate") == 20){setglobalvar("dojoEnergyRate", 15);}else
        if(getglobalvar("dojoEnergyRate") == 15){setglobalvar("dojoEnergyRate", 10);}else
        if(getglobalvar("dojoEnergyRate") == 10){setglobalvar("dojoEnergyRate", 5);}else
        if(getglobalvar("dojoEnergyRate") == 5){setglobalvar("dojoEnergyRate", 0);}else
        if(getglobalvar("dojoEnergyRate") == 0){setglobalvar("dojoEnergyRate", 25);}
      }
		}

		//USED TO EXIT WITHOUT SELECT ANY CHARACTER
		if(playerkeys(player, 1, "jump")){
			gotomainmenu(3);
		}

		else

		//BEGIN GAME WHEN ANY BUTTON IS PRESSED
		if(playerkeys(player, 1, "anybutton")){
			if(getglobalvar("dojoStart") == 0){
				playsample(openborconstant("SAMPLE_BEEP2"), 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
				setglobalvar("dojoStart", 1);
			}
		}
	}
}
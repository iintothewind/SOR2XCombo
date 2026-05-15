void main()
{//Change animation with global variable "gasEnable", and damage all players gradually (TOXIC GAS IN ST6A)
	void self	= getlocalvar("self");
	void vAnID	= getentityproperty(self, "animationID");
	int frame	= getentityproperty(self, "animpos");
	float time	= openborvariant("elapsed_time");

	//IS IN DEFAULT IDLE ANIMATION??
	if(vAnID == openborconstant("ANI_IDLE")){
		if(getglobalvar("gasEnable") == 1){ //GAS ALREADY ENABLED??
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1")); //CHANGE ANIMATION
		}
	}

	//IS IN FOLLOW1 ANIMATION AND FRAME IS LOWER THAN/EQUAL 0??
	if(vAnID == openborconstant("ANI_FOLLOW1") && frame <= 0){
		if(getlocalvar("damaged") != 1){
			void player1	= getplayerproperty(0, "entity");
			void player2	= getplayerproperty(1, "entity");
			void player3	= getplayerproperty(2, "entity");
			void player4	= getplayerproperty(3, "entity");
			void partner	= getglobalvar("currentPartner");
			void general	= getglobalvar("general");

			float damageRate	 = 0.03;

			gasDmg(player1, damageRate);
			gasDmg(player2, damageRate);
			gasDmg(player3, damageRate);
			gasDmg(player4, damageRate);
			gasDmg(partner, damageRate);

			if(getglobalvar("generalRescued") == NULL()){
				gasDmg(general, damageRate);
				setglobalvar("generalHealth", getentityproperty(general, "health"));
			}
			setlocalvar("damaged", 1);
		}
	}

	//IS IN FOLLOW1 ANIMATION AND FRAME IS BIGGER THAN 0??
	if(vAnID == openborconstant("ANI_FOLLOW1") && frame > 0){
		if(getlocalvar("damaged") != 0){setlocalvar("damaged", 0);}
	}
}

// void gasDmg(void player, int damage)
// {//Script to reduce code size

// 	if(player != NULL()){
// 		void self	= getlocalvar("self");
// 		int iHealth	= getentityproperty(player, "health");
// 		int blink	= getentityproperty(player, "blink");

// 		if(!blink){
// 			if(iHealth > damage){
// 				if(getglobalvar("addLife"+player) != 0){setglobalvar("addLife"+player, 0);}
// 				changeentityproperty(player, "health", iHealth-damage);
// 			}
// 			else
// 			{
// 				damageentity(player, self, damage*2, 1, openborconstant("ATK_NORMAL10"));
// 			}
// 		}
// 	}
// }

void gasDmg(void player, float damageRate)
{//Script to reduce code size

	if(player != NULL() && damageRate > 0){
		void self	= getlocalvar("self");
		int maxHp		 = getentityproperty(player, "maxhealth");
		int hp		 = getentityproperty(player, "health");
		int damage = maxHp*damageRate;
		int blink	= getentityproperty(player, "blink");

		if(blink != 1){
			if(hp > damage){
				if(getglobalvar("addLife"+player) != 0){setglobalvar("addLife"+player, 0);}
				changeentityproperty(player, "health", hp-damage);
			}else{
				damageentity(player, self, damage*2, 1, openborconstant("ATK_NORMAL10"));
			}
		}
	}
}
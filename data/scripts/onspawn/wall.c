void main()
{
	void self 		 	= getlocalvar("self");
	void difficult		= getglobalvar("difficult");
	void partner 		= getglobalvar("partnerAlive");
	int pCount			= openborvariant("count_players");

	if(partner > 0){pCount = pCount+partner;}

	float baseMp		= getentityproperty(self, "mp");
	float hBase = getglobalvar("hBase");
	float baseHealth	= hBase*pCount;
	float addHealth		= baseMp;
	float baseScore		= baseMp*100;
	float iMHealth;
	float iHealth;

	if(difficult == "normal"){
		iMHealth = baseHealth+addHealth;
		iHealth  = iMHealth;
	}
	else
	if(difficult == "hard"){
		iMHealth = baseHealth+addHealth*1.2;
		iHealth  = iMHealth;
	}
	else
	if(difficult == "mania"){
		iMHealth = baseHealth+addHealth*1.4;
		iHealth  = iMHealth;
	}

	changeentityproperty(self, "maxhealth", iMHealth);
	changeentityproperty(self, "health", iHealth);
	changeentityproperty(self, "score", baseScore);
}
void main()
{//Suicide according to enemy count
	void self 	= getlocalvar("self");
	int pCount	= openborvariant("count_players");
	int eCount	= openborvariant("count_enemies");
	float time 	= openborvariant("elapsed_time");
	
	if(time%2 == 0){if(pCount >= 1 && eCount <= 5){killentity(self);}}
}
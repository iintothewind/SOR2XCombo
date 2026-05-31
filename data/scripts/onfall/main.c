#import "data/scripts/main.c"
#import "data/scripts/animation/main_moves.c"
#import "data/scripts/animation/main_spawns.c"

void unBind()
{//Release binded entity by GRABSTART script if falling by time over
	void self 	= getlocalvar("self");
	void target = getentityvar(self, "grabbed");
	void ani	= getentityproperty(self, "animationID");

	//USED WHEN PLAYER IS FALLING BY TIME OVER AND THE GRABBER IS THE PLAYER, NEED TO UNBIND THE ENEMY
	//USED WHEN ENEMY IS FALLING BY NODROPEN AND THE GRABBER IS THE ENEMY, NEED TO UNBIND THE PLAYER
	if(target != NULL()){
		if(ani != openborconstant("ANI_FALL7") && ani != openborconstant("ANI_FALL8") && ani != openborconstant("ANI_FALL9")){
			bindentity(target, NULL());
			changeentityproperty(target,"damage_on_landing",0);
			changeentityproperty(target,"aiflag","falling",0);
			changeentityproperty(target,"aiflag","drop",0);
			changeentityproperty(target,"aiflag","projectile",0);
			changeentityproperty(target,"aiflag","frozen",0);
			changeentityproperty(target,"takeaction","common_animation_normal");
			changeentityproperty(target,"velocity",0,0,0);
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL"));
			setidle(target);
			setentityvar(self, "grabbed", NULL());
		}
	}
}

void weaponFix()
{//Make some adjustments if falling, used for weapons when hitting walls
	void self	= getlocalvar("self");
	float dir	= getentityproperty(self, "direction");
	float Vx	= 0.7;
	float Vy	= 2;

	if(dir == 0){changeentityproperty(self, "direction", 1);}else
	if(dir == 1){changeentityproperty(self, "direction", 0);}

	spawn01("Flash", 0, 0, 0);
	leaper(Vx, Vy, 0);
	changeentityproperty(self, "subject_to_wall", 0);
}

void enemyOnFall() {
	void self = getlocalvar("self");
	void attacker = getlocalvar("attacker");

	if (getentityproperty(attacker, "type") == openborconstant("TYPE_ENEMY")){
		if(getentityproperty(attacker, "xdir") > 0){
			if(getentityproperty(self, "xdir") < 0){
				changeentityproperty(self, "velocity", getentityproperty(self, "xdir") * -1, getentityproperty(self, "zdir"), getentityproperty(self, "tossv"));
				changeentityproperty(self, "direction", 0);
			}
		}else if(getentityproperty(attacker, "xdir") < 0){
			if(getentityproperty(self, "xdir") > 0){
				changeentityproperty(self, "velocity", getentityproperty(self, "xdir") * -1, getentityproperty(self, "zdir"), getentityproperty(self, "tossv"));
				changeentityproperty(self, "direction", 1);
			}
		}
	}	else if (getentityproperty(attacker, "name") == "oil"){
		if(getentityproperty(attacker, "direction") == 1){
			if(getentityproperty(self, "xdir") < 0){
				changeentityproperty(self, "velocity", getentityproperty(self, "xdir") * -1, getentityproperty(self, "zdir"), getentityproperty(self, "tossv"));
				changeentityproperty(self, "direction", 0);
			}
		}else if(getentityproperty(attacker, "direction") == 0){
			if(getentityproperty(self, "xdir") > 0){
				changeentityproperty(self, "velocity", getentityproperty(self, "xdir") * -1, getentityproperty(self, "zdir"), getentityproperty(self, "tossv"));
				changeentityproperty(self, "direction", 1);
			}
		}
	}

}

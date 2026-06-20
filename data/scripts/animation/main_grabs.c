#import "data/scripts/main.c"

void grabAbort()
{//Emergency release when grabber dies mid-animation (health<=0, dead still 0)
	void self = getlocalvar("self");

	grabRelease(self);
	setidle(self);
}

void grabStart()
{//Grab Starter for grab moves
 //Use SLAM or THROW after using this
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");

	if(!selfAlive()){grabAbort();return;}

	if(target == NULL()){
		target = getentityproperty(self, "grabbing");
		int targetInvincible	= getentityproperty(target, "invincible");

		if(target == NULL() || !entityAlive(target) || targetInvincible == 1){ //USED WHEN PLAYER DIES BY TIME OVER AND THE GRABBER IS THE ENEMY
			setidle(self);
		}else{
			setentityvar(self, "grabbed", target);
		}
	}

	target = getentityvar(self,"grabbed");

	if(target != NULL()){
		setglobalvar("armorResist"+self, NULL());
		changeentityproperty(self, "blink", 0);
		changeentityproperty(self, "aiflag", "invincible", 0);

		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7"));
		changeentityproperty(target, "aiflag", "frozen", 1); //USED TO AVOID GRAB INTERRUPTION WHEN THE NODROPEN IS OFF AND ANY PLAYER IS RESPAWNED
		lockMpG();
		specialCostG(0);
	}
}

void grabStart2()
{//Grab Starter for non-grab moves
 //Use SLAM or THROW after using this
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");

	if(!selfAlive()){grabAbort();return;}

	if(target == NULL()){
		target = getentityproperty(self, "opponent");
		int targetInvincible	= getentityproperty(target, "invincible");
		if(target == NULL() || !entityAlive(target) || targetInvincible == 1){ //USED WHEN PLAYER DIES BY TIME OVER AND THE GRABBER IS THE ENEMY
			setidle(self);
		}else{
			setentityvar(self, "grabbed", target);
		}
	}

	target = getentityvar(self,"grabbed");

	if(target != NULL()){
		setglobalvar("armorResist"+self, NULL());
		changeentityproperty(self, "blink", 0);
		changeentityproperty(self, "aiflag", "invincible", 0);

		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7"));
		changeentityproperty(target, "aiflag", "frozen", 1); //USED TO AVOID GRAB INTERRUPTION WHEN THE NODROPEN IS OFF AND ANY PLAYER IS RESPAWNED
		lockMpG();
		specialCostG(0);
	}
}

void position(int frame, float dx, float dy, float dz, int face)
{//Modify grabbed entity's position relative to grabber
 //Use grabstart 1st before using this
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");

	if(!selfAlive()){grabAbort();return;}

	if(target != NULL()){
		if(!entityAlive(target)){ //USED WHEN PLAYER DIES BY TIME OVER AND THE GRABBER IS THE ENEMY
			grabRelease(self);
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL"));
			damageentity(self, self, 0, 1, openborconstant("ATK_NORMAL"));
			lockMpG();
			specialCostG(0);
		}else{
			updateframe(target, frame);
			bindentity(target, self, dx, dz, dy, face, 0);
		}
	}
}

void slam(int damage, int type, int Vx, int Vy, int Vz, int face)
{//Damage as slam finisher
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");
	int tDir 	= getentityproperty(target,"direction");
	int vDir;

	if(!selfAlive()){grabAbort();return;}

	if(face == 0){ //SAME FACING?
		vDir = tDir;
	}

	if(face == 1){ //OPPOSITE FACING?
		if(tDir == 0){ //FACING LEFT?
			vDir = 1;
		}else{
			vDir = 0;
		}
	}

	if(target != NULL()){
		if(!entityAlive(target)){
			grabRelease(self);
			return;
		}

		void eType = getentityproperty(target,"type");
		int dir	= getentityproperty(target,"direction");
		void atkType;
		void projectile;

		if(dir == 0){Vx = -Vx;}
		if(type == 1){atkType = openborconstant("ATK_NORMAL8");}
		if(type == 2){atkType = openborconstant("ATK_NORMAL9");}

		if(eType == openborconstant("TYPE_PLAYER") || eType == openborconstant("TYPE_NPC")){
			changeentityproperty(target, "projectilehit", "type_player", "type_npc", "type_obstacle");
		}
		else
		if(eType == openborconstant("TYPE_ENEMY")){
			changeentityproperty(target, "projectilehit", "type_enemy", "type_obstacle");
		}

		damageentity(target, self, damage, 1, atkType); //SPLIT DAMAGE
		lockMpG();
		specialCostG(damage);
		changeentityproperty(target, "direction", vDir);
		changeentityproperty(target, "aiflag", "projectile", 1);
		changeentityproperty(target, "damage_on_landing", damage/2); //RESET PROJECTILE STATUS TO 0 WHEN FALL ON THE GROUND, SPLIT DAMAGE
		finishGrab(Vx, Vy, Vz); //EXECUTE ALL NECESSARY TASKS TO END THE GRAB MOVE (ANTIWALL, UNBIND AND TOSSENTITY)
		setentityvar(self, "grabbed", NULL()); //CLEAR ENTITYVAR
	}
}

void throw(int damage, int type, int Vx, int Vy, int Vz, int face)
{//Damage as throw finisher
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");
	int z 		= getentityproperty(self,"z");
	int tDir 	= getentityproperty(target,"direction");
	int vDir;

	if(!selfAlive()){grabAbort();return;}

	if(face == 0){ //SAME FACING?
		vDir = tDir;
	}

	if(face == 1){ //OPPOSITE FACING?
		if(tDir == 0){ //FACING LEFT?
			vDir = 1;
		}else{
			vDir = 0;
		}
	}

	if(target != NULL()){
		if(!entityAlive(target)){
			grabRelease(self);
			return;
		}

		void eType = getentityproperty(target,"type");
		int dir    = getentityproperty(target,"direction");
		void atkType;
		void projectile;

		if(dir == 0){Vx = -Vx;}
		if(type == 1){atkType = openborconstant("ATK_NORMAL8");}
		if(type == 2){atkType = openborconstant("ATK_NORMAL9");}
		if(z > (openborconstant("PLAYER_MIN_Z")+openborconstant("PLAYER_MAX_Z"))/2){Vz = -Vz ;}

		if(eType == openborconstant("TYPE_PLAYER") || eType == openborconstant("TYPE_NPC")){
			changeentityproperty(target, "projectilehit", "type_player", "type_npc", "type_obstacle");
		}
		else
		if(eType == openborconstant("TYPE_ENEMY")){
			changeentityproperty(target, "projectilehit", "type_enemy", "type_obstacle");
		}

		damageentity(target, self, damage, 1, atkType);
		lockMpG();
		specialCostG(damage);
		changeentityproperty(target, "direction", vDir);
		changeentityproperty(target, "aiflag", "projectile", 1);
		changeentityproperty(target, "damage_on_landing", damage/2); //RESET PROJECTILE STATUS TO 0 WHEN FALL ON THE GROUND, TOTAL DAMAGE
		finishGrab(Vx, Vy, Vz); //EXECUTE ALL NECESSARY TASKS TO END THE GRAB MOVE (ANTIWALL, UNBIND AND TOSSENTITY)
		setentityvar(self, "grabbed", NULL()); //CLEAR ENTITYVAR
	}
}

void lockMpG()
{//Lock mprate with defined conditions. Same as used in "didhit event" but only for grab animations
	void self 	= getlocalvar("self");
	int disable	= getentityproperty(self,"energycost", "disable", openborconstant(getlocalvar("animnum")));
	int maxMp 	= getentityproperty(self,"maxmp");
	int mp 		= getentityproperty(self,"mp");
	int mpRate 	= getentityproperty(self,"mprate");

	if(disable == 6){
		if(mp < maxMp){
			changeentityproperty(self, "mp", mp-mpRate);
		}
	}
}

void specialCostG(int dmg)
{//Lock mprate according to "Special Cost" global variable. Same as used in "didhit event" but only for grab animations
	void self 	  = getlocalvar("self");
	// void specialC = getglobalvar("specialCost");
	void specialC = "sor2x_energy_only";
	int disable	  = getentityproperty(self,"energycost", "disable", openborconstant(getlocalvar("animnum")));
	int maxMp 	  = getentityproperty(self,"maxmp");
	int mp 		  = getentityproperty(self,"mp");
	int mpRate 	  = getentityproperty(self,"mprate");

	if(specialC != "sor4_recovery_(time)" && specialC != "sor4_recovery_(hits)" && specialC != "sor2_life_only"){
		if(disable == 5){
			if(mp < maxMp){
				changeentityproperty(self, "mp", mp-mpRate);
			}
		}
	}

	//USED BY "HEAL HIT" GLOBAL VARIABLE, TO RECOVER HEALTH BY EACH HIT INSTEAD OF RECOVERY BY TIME
	if(specialC == "sor4_recovery_(hits)"){
		if(dmg > 0){ //USED FOR GRABS AND OTHER "NO DAMAGE" ATTACKS
			if(getglobalvar("addLife"+self) > 0){
				setglobalvar("healHit"+self, 1);
			}
		}
	}
}

void finishGrab(int Vx, int Vy, int Vz)
{//This new function was created by mixing the "antiwall", "depost" and "tossentity" into a unique function
	void self 		= getlocalvar("self");
	void target 	= getentityvar(self, "grabbed");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	float wall 		= checkwall(Tx, Tz);

	if(target != NULL()){
		if(wall){ //WAS DETECTED ANY WALL IN THE TARGET'S POSITION?? RUN ALL TASKS BELOW!!
			changeentityproperty(target, "position", x, z); //FIX THE GRABBED ENTITY'S POSITION ACCORDING TO GRABBER CORRDINATES BEFORE THE OPPONENT IS RELEASED
			bindentity(target, NULL()); //RELEASE GRABBED ENTITY, NOW THE OLD FUNCTION "DEPOST" WORKS HERE
			tossentity(target, Vy); //TOSS OPPONENT WITH Y VELOCITY ONLY, THIS WAY THE RELEASED OPPONENT WILL NOT BE MOVED AGAINST A WALL AGAIN
		}
		else //NO WALLS DETECTED?? ONLY THE DEFAULT TASKS WILL RUN
		{
			bindentity(target, NULL()); //RELEASE GRABBED ENTITY, NOW THE OLD FUNCTION "DEPOST" WORKS HERE
			tossentity(target, Vy, Vx, Vz); //TOSS OPPONENT WITH NORMAL VELOCITY, X, Y AND Z
		}
	}
}

void grabEnd()
{//End grab jump and free enemy on the ground if no attack is performed (MAX GRAB JUMP)
	void self 	= getlocalvar("self");
	void target = getentityvar(self,"grabbed");

	if(!selfAlive()){grabAbort();return;}

	if(target != NULL()){
		if(!entityAlive(target)){ //USED WHEN PLAYER DIES BY TIME OVER AND THE GRABBER IS THE ENEMY
			finishGrab();
		}else{
			changeentityproperty(target,"damage_on_landing",0);
			changeentityproperty(target,"aiflag","falling",0);
			changeentityproperty(target,"aiflag","drop",0);
			changeentityproperty(target,"aiflag","projectile",0);
			changeentityproperty(target,"aiflag","frozen", 0); //USED TO AVOID GRAB INTERRUPTION WHEN THE NODROPEN IS OFF AND ANY PLAYER IS RESPAWNED
			changeentityproperty(target,"takeaction", "common_animation_normal");
			setidle(target);
			finishGrab();
		}
	}
	setentityvar(self, "grabbed", NULL());
}


void fakeBind(int dist)
{//Move grabbed entity together with grabber with defined distance
 //Used ind the end of the vault animation if grabber is moved before touch wall/obstacle/platform/offscreen and stuck
 //Changes grabbed position relative to grabber without use bindentity
	void self 		= getlocalvar("self");
	void target 	= getentityproperty(self, "grabbing");
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");

	if(target != NULL()){
		setglobalvar("armorResist"+self, NULL());
		changeentityproperty(self, "blink", 0);
		changeentityproperty(self, "aiflag", "invincible", 0);

		if(direction == 1){
			if(Tx-x < dist){
				changeentityproperty(target,"position", x+dist);
			}
			else
			if(Tx-x > dist){
				changeentityproperty(target,"position", x+dist);
			}
		}

		if(direction == 0){
			if(x-Tx < dist){
				changeentityproperty(target,"position", x-dist);
			}
			else
			if(x-Tx > dist){
				changeentityproperty(target,"position", x-dist);
			}
		}
	}
}

void vaultStuck()
{//Checks if the entity can be stucked between Left edge of the screen and any Wall at your right side
 //If near of both at defined distance, entity (Self/Grabbed) will be moved away with defined movement
 //Specific script for stages st1a/st3b/st6b when camera go down, used on Grab animation before Vault animation
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	int distL		= 70;
	int distW		= 70;
	int moveZ		= 35;
	float xPos 		= openborvariant("xpos");
	float W			= checkwall(x+distW, z);
	float L			= x-xPos;

	if(target != NULL()){
		if(L < distL && W){ //Near from the left edge of the screen and there is a wall near at right side?
			changeentityproperty(self, "position", NULL(), z+moveZ); //Move down in Z axis to gain more space
			changeentityproperty(target, "position", NULL(), Tz+moveZ); //Move down in Z axis to gain more space
		}
	}
}

void vaultFix()
{//Fix position and some properties during vault animation
 //Used to execute all tasks needed by vault animation in one function only
	void self	= getlocalvar("self");
	void target	= getentityproperty(self, "grabbing");
	int dir		= getentityproperty(self, "direction");
	int flip;
	int grabDist;
	float x		= getentityproperty(self, "x");
	float y		= getentityproperty(self, "y");
	float Tx	= getentityproperty(target, "x");
	float z		= getentityproperty(self, "z");
	float xPos	= openborvariant("xpos");
	float hRes	= openborvariant("hresolution");

	if(dir == 0){
		flip = 1;
		grabDist = (Tx-x)*2;
		x = x+grabDist;
	}
	else
	if(dir == 1){
		flip = 0;
		grabDist = (x-Tx)*2;
		x = x-grabDist;
	}

	if(getlocalvar("animnum") == openborconstant("ANI_GRABATTACK2")){
		if(checkplatformbetween(x, z, y, y)){ //PLAYER IS STUCKED IN ANY PLATFORM??
			changeentityproperty(self, "position", Tx, NULL(), NULL());
			fakeBind(grabDist/2);
		}
		else
		if(checkwall(x, z)){ //PLAYER IS STUCKED IN ANY WALL??
			changeentityproperty(self, "position", Tx, NULL(), NULL());
			fakeBind(grabDist/2);
		}
		else
		if(x > xPos+hRes || x < xPos){ //PLAYER IS OUTSIDE OF THE SCREEN??
			changeentityproperty(self, "position", Tx, NULL(), NULL());
			fakeBind(grabDist/2);
		}
		else
		{ //NORMAL ADJUST
			changeentityproperty(self, "position", x, NULL(), NULL());
			fakeBind(grabDist/2);
		}
		changeentityproperty(self, "direction", flip);
		changeentityproperty(self, "takeaction", "common_grab");
	}

	if(getlocalvar("animnum") == openborconstant("ANI_GRABUP2")){
		changeentityproperty(self, "position", x, NULL(), NULL()); //NORMAL ADJUST
		changeentityproperty(self, "direction", flip);
		changeentityproperty(self, "takeaction", "common_grabattack");

		if(target != NULL()){setidle(target);}
	}
}


void adjustGrabDistance(void attacker, void target)
{//Fix position and some properties during vault animation
 //Used to execute all tasks needed by vault animation in one function only
	if(attacker != NULL() && target != NULL()) {
		int dir		= getentityproperty(attacker, "direction");
		int flip;
		int grabDist;
		float x		= getentityproperty(attacker, "x");
		float y		= getentityproperty(attacker, "y");
		float Tx	= getentityproperty(target, "x");
		float z		= getentityproperty(attacker, "z");
		float xPos	= openborvariant("xpos");
		float hRes	= openborvariant("hresolution");

		if(dir == 0){
			flip = 1;
			grabDist = (Tx-x)*2;
			x = x+grabDist;
		}
		else
		if(dir == 1){
			flip = 0;
			grabDist = (x-Tx)*2;
			x = x-grabDist;
		}

		if(getlocalvar("animnum") == openborconstant("ANI_GRABATTACK2")){
			if(checkplatformbetween(x, z, y, y)){ //PLAYER IS STUCKED IN ANY PLATFORM??
				changeentityproperty(attacker, "position", Tx, NULL(), NULL());
				fakeBind(grabDist/2);
			}
			else
			if(checkwall(x, z)){ //PLAYER IS STUCKED IN ANY WALL??
				changeentityproperty(attacker, "position", Tx, NULL(), NULL());
				fakeBind(grabDist/2);
			}
			else
			if(x > xPos+hRes || x < xPos){ //PLAYER IS OUTSIDE OF THE SCREEN??
				changeentityproperty(attacker, "position", Tx, NULL(), NULL());
				fakeBind(grabDist/2);
			}
			else
			{ //NORMAL ADJUST
				changeentityproperty(attacker, "position", x, NULL(), NULL());
				fakeBind(grabDist/2);
			}
			changeentityproperty(attacker, "direction", flip);
			changeentityproperty(attacker, "takeaction", "common_grab");
		}

		if(getlocalvar("animnum") == openborconstant("ANI_GRABUP2")){
			changeentityproperty(attacker, "position", x, NULL(), NULL()); //NORMAL ADJUST
			changeentityproperty(attacker, "direction", flip);
			changeentityproperty(attacker, "takeaction", "common_grabattack");

			if(target != NULL()){setidle(target);}
		}
	}
}


void doGrab(int flag)
{//Grab target with normal grab
	void self  = getlocalvar("self");
	void target;

	if(!selfAlive()){grabAbort();return;}

	if(flag == 0){
		target = getentityproperty(self,"grabbing");
	}else{
		target = getentityproperty(self,"opponent");
	}

	void type 	 = getentityproperty(target,"type");
	void subType = getentityproperty(target,"subtype");

	if(target != NULL()){
		if(type != openborconstant("TYPE_OBSTACLE")){
			if(subType != openborconstant("SUBTYPE_NOTGRAB")){
				dograb(self, target, 0);
			}
		}
	}
}

void grabIdle()
{//Set to idle if no entity is being grabbed (FOG GRAB)
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");

	if(target == NULL()){setidle(self);}
}

void landGrab()
{//Grab target with normal grab
	void self  = getlocalvar("self");
	void target = getentityproperty(self,"opponent");

	if(!selfAlive()){grabAbort();return;}

	if(target == NULL()) {
		target = getentityproperty(self,"grabbing");
	}

	int targetInvincible	= getentityproperty(target, "invincible");
	void targetAni 		= getentityproperty(target, "animationID");
	int targetX 		= getentityproperty(target,"x");
	int targetY 		= getentityproperty(target,"y");
	int targetZ 		= getentityproperty(target,"z");
	int targetBase 	= getentityproperty(target,"base");
	void targetType 	 = getentityproperty(target,"type");
	void targetSubType = getentityproperty(target,"subtype");

	if(target != NULL()
	&& targetInvincible == 0
	&& targetAni != openborconstant("ANI_FREESPECIAL")
	&& targetType != openborconstant("TYPE_OBSTACLE")
	&& targetSubType != openborconstant("SUBTYPE_NOTGRAB")
	&& entityAlive(target)){
		setglobalvar("armorResist"+self, NULL());
		changeentityproperty(self, "blink", 0);
		changeentityproperty(self, "aiflag", "invincible", 0);
		if(targetY > targetBase) {
			setidle(target);
			changeentityproperty(target,"position", targetX, targetZ, 0);
			changeentityproperty(target,"velocity", 0, 0, 0);
			executeanimation(target, openborconstant("ANI_PAIN"), 1);
			changeentityproperty(target,"takeaction", "common_pain");
			changeentityproperty(target,"damage_on_landing",0);
			changeentityproperty(target,"aiflag","falling",0);
			changeentityproperty(target,"aiflag","drop",0);
			changeentityproperty(target,"aiflag","projectile",0);
			changeentityproperty(target,"nograb",0);
		}
		dograb(self, target, 0);
	} else {
     setidle(self); //Don't perform the slam.
	}
}

void selfNoGrab(int flag) {
	void self  = getlocalvar("self");
	changeentityproperty(self,"nograb", flag);
}

void grabcheck()
{// Prevents hero from performing the slam if he/she's not grabbing anyone
   void self = getlocalvar("self");
   void target = getentityproperty(self, "grabbing");

   if(target==NULL())
   {
     setidle(self); //Don't perform the slam.
   }
}

void dethrown()
{
	void self = getlocalvar("self");

	changeentityproperty(self, "attacking", 0);
	changeentityproperty(self, "damage_on_landing", 0);
	changeentityproperty(self, "projectile", 0);
}

void slamstart()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void sposition(int Frame, float dx, float dy, float dz, int face)
{
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}
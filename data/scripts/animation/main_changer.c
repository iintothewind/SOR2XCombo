#import "data/scripts/main.c"
#include "data/scripts/assets.h"

void aniChange(int type, void ani)
{//Change animations
 //Type 0: Default animation changer
 //Type 1: Execute animation changer
 //Type 2: Performattack animation changer
    void self = getlocalvar("self");

    if(!selfAlive()){return;}

    if(type == 0){changeentityproperty(self, "animation", openborconstant(ani));}
    if(type == 1){executeanimation(self, openborconstant(ani), 1);}
    if(type == 2){performattack(self, openborconstant(ani), 1);}
}

void aniParent(int type, void ani)
{//Change parent animations
 //Type 0: Default animation changer
 //Type 1: Execute animation changer
 //Type 2: Performattack animation changer
    void self    = getlocalvar("self");
    void parent    = getentityproperty(self, "parent");

    if(!entityAlive(parent)){return;}

    if(type == 0){changeentityproperty(parent, "animation", openborconstant(ani));}
    if(type == 1){executeanimation(parent, openborconstant(ani), 1);}
    if(type == 2){performattack(parent, openborconstant(ani), 1);}
}

void aniEcount(int type, void ani, int count)
{//Animation changer with ENEMY count (ELEVATORS)
 //Type 0: Less than "count"
 //Type 1: More than "count"
    void self  = getlocalvar("self");
    int eCount = openborvariant("count_enemies");

    if(type == 0){
        if(eCount <= count){
            changeentityproperty(self, "animation", openborconstant(ani));
        }
    }

    if(type == 1){
        if(eCount >= count){
            changeentityproperty(self, "animation", openborconstant(ani));
        }
    }
}

void aniHp(void ani, int limit)
{//Execute defined animation with HP check
    void self  = getlocalvar("self");
    int health = getentityproperty(self, "health");

    if(health <= limit && health > 0){
        executeanimation(self, openborconstant(ani), 1);
    }
}

void aniMp(void ani, int limit)
{//Execute defined animation with MP check
    void self = getlocalvar("self");
    int mp       = getentityproperty(self, "mp");

    if(!selfAlive()){return;}

    if(mp <= limit){executeanimation(self, openborconstant(ani), 1);}
}

void aniRandom(void ani)
{//Random animation changer (SOR3 LAMPS)
    void self = getlocalvar("self");
    float iR  = rnd(100)-1;

    if(!selfAlive()){return;}

    if(iR >= 0 && iR < 50){changeentityproperty(self, "animation", openborconstant(ani));}
}

void aniXpos(float pos, int mode, void ani)
{//Animation changer with Xpos check(ASH BOAT/ST8_CANNON/HARAKIRI ROAD)
 //mode 0: lower than xPos+pos
 //mode 1: higher than xPos+pos
 //mode 2: higher than or same as xPos
    void self    = getlocalvar("self");
    float x        = getentityproperty(self, "x");
    float xPos    = openborvariant("xpos");

    if(mode == 0){
        if(x < xPos+pos){
            changeentityproperty(self, "animation", openborconstant(ani));
        }
    }

    if(mode == 1){
        if(x > xPos+pos){
            changeentityproperty(self, "animation", openborconstant(ani));
        }
    }

    if(mode == 2){
        if(xPos >= pos){
            changeentityproperty(self, "animation", openborconstant(ani));
        }
    }
}

void aniVar(void ani, void variable, float value, int type)
{//Execute defined animation with generic global/local variable check by setVar/aniCount scripts
    void self = getlocalvar("self");

    if(!selfAlive()){return;}

    if(type == 1){ //FOR LOCAL VARIABLES AND "+SELF" USAGE
        if(getlocalvar(variable+self) >= value){
            executeanimation(self, openborconstant(ani), 1);
            setlocalvar(variable+self, NULL());
        }
    }
    else
    { //FOR GLOBAL VARIABLES
        if(getglobalvar(variable) == value){executeanimation(self, openborconstant(ani), 1);}
    }
}

void nodieBlink(int flag)
{//Changes nodieblink property
    void self = getlocalvar("self");

    changeentityproperty(self, "nodieblink", flag);
}

void setIdle()
{//Reset to idle instance
    void self = getlocalvar("self");

    setidle(self, openborconstant("ANI_IDLE"));
}

void aniCount(int add)
{//Count how many times the animation was played to further use
    void self = getlocalvar("self");
    int count = getlocalvar("aniCount"+self);

    if(count == NULL()){ //START THE COUNTER IF THE VARIABLE IS NULL
        setlocalvar("aniCount"+self, add);
    }
    else
    { //ADD +1 TO THE COUNTER
        setlocalvar("aniCount"+self, getlocalvar("aniCount"+self)+add);
    }
}

void delayDetect()
{//Lock frame advance until mp reach 0
 //Uses mp as delay to spawn enemies one-by-one in level.txt
 //CAUTION: Apply ONLY in enemies that don't need mp
    void self = getlocalvar("self");
    int mp       = getentityproperty(self, "mp");

    if(mp > 0){changeentityproperty(self, "mp", mp-1);updateframe(self, 0);}
}

void deGravity(float ratio)
{//Changes antigravity effect
    void self = getlocalvar("self");

    changeentityproperty(self, "antigravity", ratio);
}

void setLayer(int layer)
{//Changes layer
    void self = getlocalvar("self");

    changeentityproperty(self, "setlayer", layer);
}

void stealth(int factor) //YAMATO HIDE SLASH
{//Changes stealth factor
    void self = getlocalvar("self");

    if(!selfAlive()){return;}

    changeentityproperty(self, "stealth", factor);
}

void wall(int flag)
{//Turns subject's to wall status
    void self = getlocalvar("self");

    changeentityproperty(self, "subject_to_wall", flag);
}

void screen(int flag)
{//Turns subject's to screen status
    void self = getlocalvar("self");

    changeentityproperty(self, "subject_to_screen", flag);
}

void platform(int flag)
{//Turns subject's to platform status
    void self = getlocalvar("self");

    changeentityproperty(self, "subject_to_platform", flag);
}

void hole(int flag)
{//Turns subject's to hole status
    void self = getlocalvar("self");

    changeentityproperty(self, "subject_to_hole", flag);
}

void minz(int flag)
{//Turns subject's to minZ status
    void self = getlocalvar("self");

    changeentityproperty(self, "subject_to_minz", flag);
}

void block(int flag)
{//Turns blocking status
    void self = getlocalvar("self");

    if(flag == 1){
        changeentityproperty(self, "aiflag", "blocking", 1);
        changeentityproperty(self, "takeaction", "common_block");
    }else{
        changeentityproperty(self, "aiflag", "blocking", 0);
    }
}

void jump(int flag)
{//Turns jumping status
    void self = getlocalvar("self");

    if(flag == 1){
        changeentityproperty(self, "aiflag", "jumping", 1);
        changeentityproperty(self, "takeaction", "common_jump");
    }else{
        changeentityproperty(self, "aiflag", "jumping", 0);
    }
}

void frozen(int flag)
{//Turns frozen status, used to deny "nodropen" to put enemies in a fall animation if your spawn animation are not completed yet
    void self = getlocalvar("self");

    if(flag == 1){
        changeentityproperty(self, "aiflag", "frozen", 1);
    }else{
        changeentityproperty(self, "aiflag", "frozen", 0);
    }
}

void invinc(float duration)
{
    void self  = getlocalvar("self");
    float selfHeight = getentityproperty(self,"y");
    float selfBase = getentityproperty(self,"base");
    float time = openborvariant("elapsed_time");
    float mult = 100;
    float delta  = duration*mult;
    float lastInvincTime = getentityproperty(self, "invinctime");

    if(!selfAlive()){return;}

    if(lastInvincTime == NULL() || (lastInvincTime != NULL() && lastInvincTime < (time + delta))) {
        // if(selfBase <= selfHeight) {
        //     setglobalvar("armorResist"+self, time+delta);
        // }
        setglobalvar("armorResist"+self, time+delta);
        changeentityproperty(self, "aiflag", "invincible", 1);
        changeentityproperty(self, "invinctime", time+delta);
    }
}


void invincible(int flag, float duration)
{//Turns invincible status, used on riseattack and aerial recovery animations
    void self  = getlocalvar("self");
    float time = openborvariant("elapsed_time");
    float mult = 200;
    float end  = duration*mult;

    if(!selfAlive()){return;}

    if(flag == 1){
        changeentityproperty(self, "aiflag", "invincible", 1);
        changeentityproperty(self, "invinctime", time+end);
    }
}

void graphics(void effect, void model)
{//Change model according to graphics effects variable
    void self      = getlocalvar("self");
    void effects = getglobalvar("graphicEffects");

    if(effects == effect){changeentityproperty(self, "model", model, 1);}
}

void looper(int frame, int limit)
{//Loops current animation
    void self    = getlocalvar("self");
    void anim    = getentityproperty(self, "animationID");
    int loop    = getlocalvar("loop"+self+anim);

    if(loop == NULL()){ //LOCALVAR EMPTY?
        setlocalvar("loop"+self+anim, 0);
        loop = 0;
    }

    if(loop < limit){ //LOOPS REACH LIMIT?
        setlocalvar("loop"+self+anim, loop+1); //INCREMENT NUMBER OF LOOPS
        updateframe(self, frame); //CHANGE FRAME
    }
    else
    if(loop == limit){ //LOOPS REACH LIMIT?
        setlocalvar("loop"+self+anim, NULL());
    }
}

void loopXpos(int pos, int mode, int frame)
{//Loops current animation while the defined xpos is not reached
 //mode 0: lower than xPos+pos
 //mode 1: higher than xPos+pos
 //mode 2: higher than or same as xPos
    void self    = getlocalvar("self");
    float x        = getentityproperty(self, "x");
    float xPos    = openborvariant("xpos");

    if(mode == 0){
        if(x < xPos+pos){
            updateframe(self, frame);
        }
    }

    if(mode == 1){
        if(x > xPos+pos){
            updateframe(self, frame);
        }
    }

    if(mode == 2){
        if(xPos >= pos){
            updateframe(self, frame);
        }
    }
}

void looParent(int frame)
{//Loops current animation while the current binded parent projectile is alive
    void self     = getlocalvar("self");
    void parent = getentityvar(self, "projectile");
    void exists = getentityproperty(parent, "exists");

    if(exists){updateframe(self, frame);}
}

void lockAni(void variable, void value)
{//Check global variable to free or lock some animations (DODGE/BIKE HEROES)
 //CAUTION: THIS ANIMATION NEED TO BE (SETIDLE 0, 1, 200) TO RESET CORRECTLY
    void self    = getlocalvar("self");
    void ani    = getentityproperty(self, "animationID");
    int iPIndex    = getentityproperty(self, "playerindex");

    if(getglobalvar(variable) == value){
        changeentityproperty(self, "takeaction", "common_animation_normal");
        changeentityproperty(self, "combostep", 0);
        changeentityproperty(self, "aiflag", "running", 0);
        setidle(self, openborconstant("ANI_IDLE"), 1, 200);
    }
}

void checkBlock(int minGp) {
    void self    = getlocalvar("self");
    int gp         = getentityproperty(self,"guardpoints");
    int threshold = minGp == NULL()?0:minGp;

    if(gp <= threshold) {
        //playsample(SAMPLE_GUARDBREAK, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
        changeentityproperty(self, "takeaction", "common_animation_normal");
        changeentityproperty(self, "combostep", 0);
        changeentityproperty(self, "aiflag", "running", 0);
        setidle(self, openborconstant("ANI_GUARDBREAK"), 1, 200);
    }
}

void flip()
{//Flip to opposite direction
    void self = getlocalvar("self");
    int dir   = getentityproperty(self,"direction");

    if(!selfAlive()){return;}

    if(dir == 0){ //FACING LEFT?
        changeentityproperty(self, "direction", 1);
    }else{
        changeentityproperty(self, "direction", 0);
    }
}

void flipRandom()
{//Flip to opposite direction Randomly (JET LANDSAFE, ROO RISEATTACK)
    void self = getlocalvar("self");
    int dir   = getentityproperty(self,"direction");
    float iR  = rnd(100)-1;

    if(!selfAlive()){return;}

    if(iR >= 0 && iR < 50){changeentityproperty(self, "direction", 1);}else
    if(iR >= 50 && iR <= 100){changeentityproperty(self, "direction", 0);}
}

void flipSet(int dirCheck)
{//Flip to desired direction in defined frame according to current direction
 //dirCheck 0: Always maintain facing left
 //dirCheck 1: Always maintain facing right
    void self = getlocalvar("self");
    int dir   = getentityproperty(self,"direction");

    if(!selfAlive()){return;}

    if(dirCheck == 0){
        if(dir == 1){ // Facing right?
            changeentityproperty(self, "direction", 0);
        }
    }
    else
    if(dirCheck == 1){
        if(dir == 0){ // Facing left?
            changeentityproperty(self, "direction", 1);
        }
    }
}

void landSafe()
{//Alternative safe landing with script
    void self     = getlocalvar("self");
    void juggles = getglobalvar("juggleSystem");
    int maxJp     = getentityproperty(self, "maxjugglepoints");

    changeentityproperty(self,"damage_on_landing",0);
    changeentityproperty(self,"nograb",0);
    changeentityproperty(self,"aiflag","falling",0);
    changeentityproperty(self,"aiflag","jumping",1);
    changeentityproperty(self,"aiflag","drop",0);
    changeentityproperty(self,"aiflag","projectile",0);
    changeentityproperty(self,"takeaction","common_jump");

    if(juggles != "off"){changeentityproperty(self, "jugglepoints", maxJp);}
}

void landFrame(int add)
{//Alternative landframe with script to avoid performattack/landframe bug
 //Loops one previous frame only until hit the ground/platforms
 //Used in any animation that have bugs in normal landframes
    void self     = getlocalvar("self");
    int frame    = getentityproperty(self, "animpos");
    int height    = getentityproperty(self, "y");
    int base    = getentityproperty(self, "base");

    if(!selfAlive()){return;}

    if(add == NULL()){add = 1;}

    if(height > base){updateframe(self, getlocalvar("frame")-add);}
}

void stealthCamo(float channelr, float channelg, float channelb)
{//Apply an "Stealth Camouflage" effect, like Predator
    void self = getlocalvar("self");
    int alpha = getentityproperty(self, "alpha");

    if(!selfAlive()){return;}

    if(alpha != 6){
        changeentityproperty(self, "alpha", 6);
        changeentityproperty(self, "stealth", 2);
        changeentityproperty(self, "gfxshadow", 0);
        changeentityproperty(self, "shadowbase", 0);
    }else{
        changeentityproperty(self, "alpha", 0);
        changeentityproperty(self, "stealth", 0);
        changeentityproperty(self, "gfxshadow", 1);
        changeentityproperty(self, "shadowbase", 1);
    }
}

void exception(void var, void value, int frame)
{//Apply some exceptions to animations by jumping to the defined frame
    void self = getlocalvar("self");

    if(getglobalvar(var) == value){updateframe(self, frame);}
}

void mpCost(int cost)
{//Spend some mp
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");

    if(mp >= cost) {
        changeentityproperty(self, "mp", mp-cost);
    } else {
        changeentityproperty(self, "mp", 0);
    }
}

void hpCost(float cost)
{
    void self = getlocalvar("self");
    float hp      = getentityproperty(self,"health");
    if(hp >= cost) {
        changeentityproperty(self, "health", hp-cost);
    }
}

void recoverGp() {
    void self = getlocalvar("self");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    changeentityproperty(self, "guardpoints", maxGp);
}


void loadBockCost() {
    int cost = 2;
    void cfg = getglobalvar("blockCost");
    if(cfg == "2") {
        cost = 2;
    } else if(cfg == "1") {
        cost = 1;
    }
    return cost;
}

void blockCost() {
    if(getglobalvar("blockCost") != "off") {
        int cost = loadBockCost();
        gpCost(cost);
    } else {
        void self = getlocalvar("self");
        int maxGp    = getentityproperty(self,"maxguardpoints");
        changeentityproperty(self, "guardpoints", maxGp);
    }
}

void gpCost(int cost)
{//Spend some gp
    void self = getlocalvar("self");
    float gp  = getentityproperty(self,"guardpoints");
    int maxGp    = getentityproperty(self,"maxguardpoints");
    if(cost > 0) {
        if(gp >= cost) {
            changeentityproperty(self, "guardpoints", gp-cost);
        } else {
            changeentityproperty(self, "guardpoints", 0);
        }
    } else {
        if(gp - cost >= maxGp) {
            changeentityproperty(self, "guardpoints", maxGp);
        } else {
            changeentityproperty(self, "guardpoints", gp-cost);
        }
    }
}

void readKey(void key) {
    void self = getlocalvar("self");
    int pindex = getentityproperty(self,"playerindex");
    int facing = getentityproperty(self, "direction");

    if(key=="left" || key=="l") { return playerkeys(pindex, 0, "moveleft"); }
    else if(key=="right" || key=="r") { return playerkeys(pindex, 0, "moveright"); }
    else if(key=="up" || key=="u") { return playerkeys(pindex, 0, "moveup"); }
    else if(key=="down" || key=="d") { return playerkeys(pindex, 0, "movedown"); }
    else if(key=="attack" || key=="atk" || key=="a") { return playerkeys(pindex, 0, "attack"); }
    else if(key=="attack2" || key=="atk2" || key=="a2") { return playerkeys(pindex, 0, "attack2"); }
    else if(key=="attack3" || key=="atk3" || key=="a3") { return playerkeys(pindex, 0, "attack3"); }
    else if(key=="attack4" || key=="atk4" || key=="a4") { return playerkeys(pindex, 0, "attack4"); }
    else if(key=="jump" || key=="j") { return playerkeys(pindex, 0, "jump"); }
    else if(key=="special" || key=="sp" || key=="s") { return playerkeys(pindex, 0, "special"); }
    else if(key=="backward" || key=="back" || key=="b") {
        if(facing) { return playerkeys(pindex, 0, "moveleft"); }
        else { return playerkeys(pindex, 0, "moveright"); }
    }
    else if(key=="forward" || key=="fwd" || key=="f") {
        if(facing) { return playerkeys(pindex, 0, "moveright"); }
        else { return playerkeys(pindex, 0, "moveleft"); }
    }
    else { return 0; }
}

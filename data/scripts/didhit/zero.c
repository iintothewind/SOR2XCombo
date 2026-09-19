#import "data/scripts/didhit/main.c"

void main()
{//Used to make a "custom" jugglecost/invincibility to not hit twice, even if the target is in the ground
    void target        = getlocalvar("damagetaker");
    float time        = openborvariant("elapsed_time");
    float mult        = 200;
    float duration    = 1;
    float end        = duration*mult;

    changeentityproperty(target, "aiflag", "invincible", 1);
    changeentityproperty(target, "invinctime", time+end);
    changeentityproperty(target, "jugglepoints", 0);
}
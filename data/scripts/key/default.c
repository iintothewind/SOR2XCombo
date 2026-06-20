#import "data/scripts/key/main.c"

void main()
{
	if(getglobalvar("activeText") == 0){
		runAttack();
		chargeAttack();
		extraButton();
		okBar();
		onScreen();
	}
}
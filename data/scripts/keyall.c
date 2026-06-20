#import "data/scripts/keyall/main_misc.c"
#import "data/scripts/keyall/main_hiscore.c"
#import "data/scripts/keyall/main_debugmode.c"
#import "data/scripts/keyall/menu_extra.c"
#import "data/scripts/keyall/menu_gameplay.c"
#import "data/scripts/keyall/menu_controls.c"
#import "data/scripts/keyall/menu_features.c"
#import "data/scripts/keyall/menu_partners.c"
#import "data/scripts/keyall/menu_commands.c"
#import "data/scripts/keyall/menu_multiplayer.c"
#import "data/scripts/keyall/menu_select.c"
#import "data/scripts/keyall/menu_level.c"
#import "data/scripts/keyall/menu_survival.c"
#import "data/scripts/keyall/menu_dojo.c"
#import "data/scripts/keyall/menu_route.c"

void main()
{//Global keyall scripts, detects player index
  int player = getlocalvar("player");
	menuExtra(player);
	menuGameplay(player);
	menuControls(player);
	menuFeatures(player);
	menuPartners(player);
	menuCommands(player);
	menuMultiplayer(player);
	menuSelect(player);
	menuLevel(player);
	menuSurvival(player);
	menuDojo(player);
	arcadeLock(player);
	turboKey(player);
	rankName(player);
	debugMode(player);
	menuRoute(player);
}
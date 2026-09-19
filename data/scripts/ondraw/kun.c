#import "data/scripts/ondraw/main.c"

void main()
{
    jumpVel();
    parrow();
    subScreen();
    debugMode();
}

void subScreen()
{//Adjust subject to screen property according to defined animation
  void self        = getlocalvar("self");
  void type        = getentityproperty(self, "type");
  int subScreen    = getentityproperty(self, "subject_to_screen");
  int set            = openborvariant("current_set");

  if((set == 0 || set == 3) && subScreen == 0) {
    changeentityproperty(self, "subject_to_screen", 1);
  }
}
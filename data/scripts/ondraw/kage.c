#import "data/scripts/ondraw/main.c"

void main()
{
    subScreen();

    void self = getlocalvar("self");
    void type = getentityproperty(self, "type");

    if(type == openborconstant("TYPE_PLAYER")){
        jumpVel();
        parrow();
    }

    if(type == openborconstant("TYPE_NPC")){
        parrowPartner();
        drawLife();
    }

    debugMode();
    grabIdle("ANI_GRABDOWN", 0);
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
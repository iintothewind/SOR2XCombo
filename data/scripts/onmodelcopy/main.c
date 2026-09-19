void modelCopy()
{//Maintain default header config for alternative models (WEAPON MODELS)

    void self         = getlocalvar("self");
    void old         = getlocalvar("old");
    void vAlias     = getentityproperty(old,"name"); //GET OLD ALIAS.
    int  iMHealth     = getentityproperty(old,"maxhealth"); //GET OLD MAX HEALTH.
    int  iHealth     = getentityproperty(old,"health"); //GET OLD HEALTH.
    int  iMaxMP     = getentityproperty(old,"maxmp"); //GET OLD MAX MP.
    int  iMp         = getentityproperty(old,"mp"); //GET OLD MP.
    int  iMprate     = getentityproperty(old,"mprate"); //GET OLD MP RECOVERY RATE.
    int  iMaxGuard    = getentityproperty(old,"maxguardpoints"); //GET OLD MAX GUARDPOINTS.
    int  iGuard        = getentityproperty(old,"guardpoints"); //GET OLD GUARDPOINTS.
    int  iMaxJuggle    = getentityproperty(old,"maxjugglepoints"); //GET OLD MAX JUGGLEPOINTS.
    int  iJuggle    = getentityproperty(old,"jugglepoints"); //GET OLD JUGGLEPOINTS.
    int  iPower     = getentityproperty(old,"offense", 0); //GET OLD OFFENSE.
    int  iSpeed     = getentityproperty(old,"speed"); //GET OLD SPEED.
    int  iRunS        = getentityproperty(old,"running","speed"); //GET OLD RUNNING SPEED.
    int  iRunY        = getentityproperty(old,"running","jumpy"); //GET OLD RUNNING HEIGHT.
    int  iRunX        = getentityproperty(old,"running","jumpx"); //GET OLD RUNNING LENGTH.
    int  iRunL        = getentityproperty(old,"running","land"); //GET OLD RUNNING LAND.
    int  iRunM        = getentityproperty(old,"running","movez"); //GET OLD RUNNING MOVE.
    int  iJumpS     = getentityproperty(old,"jumpspeed"); //GET OLD JUMP SPEED.
    int  iJumpH     = getentityproperty(old,"jumpheight"); //GET OLD JUMP HEIGHT.
    int  iAggre     = getentityproperty(old,"aggression"); //GET OLD AGGRESSION.
    int  iScore     = getentityproperty(old,"score"); //GET OLD SCORE.
    int  iMap         = getentityproperty(old,"map"); //GET OLD MAP.
    int  iSubS         = getentityproperty(old,"subject_to_screen"); //GET OLD SUBJECT_TO_SCREEN.
    int  hostile    = getentityproperty(old,"hostile"); //GET OLD HOSTILE.
    int  candamage    = getentityproperty(old,"candamage"); //GET OLD CANDAMAGE.

    changeentityproperty(self, "name", vAlias); //SET ALIAS.
    changeentityproperty(self, "maxhealth", iMHealth); //SET MAX HEALTH.
    changeentityproperty(self, "health", iHealth); //SET HEALTH.
    changeentityproperty(self, "maxmp", iMaxMP); //SET MAX MP.
    changeentityproperty(self, "mp", iMp); //SET MP.
    changeentityproperty(self, "mpset", NULL(), NULL(), NULL(), iMprate, NULL(), NULL()); //SET MP RECOVERY RATE.
    changeentityproperty(self, "maxguardpoints", iMaxGuard); //SET MAX GUARDPOINTS.
    changeentityproperty(self, "guardpoints", iGuard); //SET GUARDPOINTS.
    changeentityproperty(self, "maxjugglepoints", iMaxJuggle); //SET MAX JUGGLEPOINTS.
    changeentityproperty(self, "jugglepoints", iJuggle); //SET JUGGLEPOINTS.
    changeentityproperty(self, "offense", 0, iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL2"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL3"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL4"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL5"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL6"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL7"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL8"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL9"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_NORMAL10"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_BURN"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_SHOCK"), iPower); //SET OFFENSE.
    changeentityproperty(self, "offense", openborconstant("ATK_LAND"), iPower); //SET OFFENSE.
    changeentityproperty(self, "speed", iSpeed); //SET SPEED.
    changeentityproperty(self, "running", iRunS, iRunY, iRunX, iRunL, iRunM); //SET RUNNING SPEED.
    changeentityproperty(self, "jumpspeed", iJumpS); //SET JUMP SPEED.
    changeentityproperty(self, "jumpheight", iJumpH); //SET JUMP HEIGHT.
    changeentityproperty(self, "aggression", iAggre); //SET AGGRESSION.
    changeentityproperty(self, "score", iScore); //SET SCORE.
    changeentityproperty(self, "map", iMap); //SET MAP.
    changeentityproperty(self, "subject_to_screen", iSubS); //SET SUBJECT_TO_SCREEN'S FLAG.
    changeentityproperty(self, "hostile", hostile); //SET HOSTILE'S FLAG.
    changeentityproperty(self, "candamage", candamage); //SET CANDAMAGE'S FLAG.
}
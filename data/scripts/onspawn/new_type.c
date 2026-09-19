void main()
{//Change the type to a custom one, to avoid wrong "hostile/candamage" behaviours
    void self = getlocalvar("self");

    //USED BY ENTITIES THAT NEEDS TO BE DETECTED BY OTHER CHARACTERS
    changeentityproperty(self, "type", getglobalvar("LEVEL_ENTITY"));
}
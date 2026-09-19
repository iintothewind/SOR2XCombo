void main()
{//Change invincible status
    void self   = getlocalvar("self");
    void branch = openborvariant("current_branch");
    
    if(branch == "sor3_st3b"){
        changeentityproperty(self, "invincible", 1);
        changeentityproperty(self, "invinctime", 1000000);
    }
}
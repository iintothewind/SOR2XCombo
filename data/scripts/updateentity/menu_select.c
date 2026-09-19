void main()
{//Turn on/off some effects according to global variables, used to cursor blink effect at the select screen
    void self    = getlocalvar("self");
    float time    = openborvariant("elapsed_time");
    
    //SHOW ALL MESSAGES
    if(time%2 == 0){ //USED TO SAVE CPU POWER
        void operation    = getlocalvar("operation");
        float channel     = getlocalvar("channel"+self);
        float rate         = 0.5;
        float maxLimit    = 75;
        float minLimit    = 10;

        if(channel == NULL()){setlocalvar("channel"+self, maxLimit);}
        
        if(channel != NULL()){
            changedrawmethod(self, "enabled", 1);
            changedrawmethod(self, "channelr", channel);
            changedrawmethod(self, "channelg", channel);
            changedrawmethod(self, "channelb", channel);
            
            //CHANGE OPERATION WHEN REACHED THE MIN/MAX LIMITS
            if(channel >= maxLimit){setlocalvar("operation", "decrease");}
            else
            if(channel <= minLimit){setlocalvar("operation", "increase");}
            
            //INCREASE OR DECREASE CHANNEL VALUE
            if(operation == "increase"){setlocalvar("channel"+self, channel+rate);}
            else
            if(operation == "decrease"){setlocalvar("channel"+self, channel-rate);}
        }
    }
}
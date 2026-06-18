#pragma once
#include "BuiltIn.h"
#include "Command.h"
#include "hasArgs.h"
class exitCommand : public BuiltIn{

    public:
    exitCommand();
    
    virtual ~exitCommand();

   //Actual effect of the command  
    ECommandStatus execute() override;
    
};
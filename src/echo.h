#pragma once
#include "BuiltIn.h"
#include "Command.h"
#include "hasArgs.h"
class echo : public BuiltIn ,public hasArgs{

    public:
    echo();
    
    virtual ~echo();

   //Actual effect of the command  
    ECommandStatus execute() override;

    void setArgs(std::string args) override;
    
};
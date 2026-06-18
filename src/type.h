#pragma once
#include "BuiltIn.h"
#include "Command.h"
#include "hasArgs.h"
#include "BuiltIn.h"
#include "Parser.h"
#include "Command.h"
#include <iostream>
#include <memory>
#include "Register.h"
#include "Command.h"
#include "Register.h"
#include <memory>
class type : public BuiltIn ,public hasArgs{

    public:
    type();
    
    virtual ~type();

   //Actual effect of the command  
    ECommandStatus execute() override;

    void setArgs(std::string args) override;
    
};
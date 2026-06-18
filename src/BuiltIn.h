#pragma once
#include <iostream>
#include "Command.h"
class BuiltIn : public Command{

    public:
        
    BuiltIn(std::string name);
    
    virtual ~BuiltIn();

    void getType() override;
};
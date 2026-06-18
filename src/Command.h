#pragma once
#include <string>
#include "ECommandStatus.hpp"
class Command{
    public:
    std::string name;
    
    Command(std::string name);

    virtual ~Command();
    
    virtual void getType() = 0;

    virtual ECommandStatus execute() = 0;
};
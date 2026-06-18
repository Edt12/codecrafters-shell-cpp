#pragma once

#include <string>
class hasArgs{
    protected:
        std::string args;
    public:
    virtual void setArgs(std::string args) = 0;

    hasArgs() = default;
    
    virtual ~hasArgs() = default;
};
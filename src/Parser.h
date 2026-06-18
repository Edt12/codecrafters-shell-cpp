/**
 * Purpose of class - decide what command to actually call and output an enum to main
 */
#pragma once
#include "Command.h"
#include "ECommand.hpp"
#include <memory>
#include <string>
#include <unordered_map> 
template<typename  T>
std::unique_ptr<Command> instanciateCommand(){
    return std::make_unique<T>();
}

class Parser{
    int maxCommandLength;//Here to ensure that we only check all substrings up to the point we need to

    int currentCommandLength = 2;

    //Store list of commands we return a pointer to a function which can then instanciate our classes void in this case means no params
    std::unordered_map<std::string, std::unique_ptr<Command> (*)(void)> commands;

    public:
    
    Parser(int maxCommandLength);

    ~Parser() = default;

    void RegisterCommand(std::string name,std::unique_ptr<Command> (*) (void));
    
    std::unique_ptr<Command> parseCommand(std::string input);    
    
    //Turns strings version of commands into 'tokens' enums then outputs the object for that command 
    std::unique_ptr<Command> Parse(std::string input);
};
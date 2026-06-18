#include "echo.h"
#include "BuiltIn.h"
#include "hasArgs.h"
#include "Command.h"
#include <complex>

echo::echo():BuiltIn("echo"),hasArgs(){
}

echo::~echo(){
    
}
ECommandStatus echo::execute(){
    std::cout << this->args << "\n";
    return ECommandStatus::STATUS_SUCCESS;
}

void echo::setArgs(std::string args){
    //removes spaces from before the argument
    int startOfString = 0;
    for(char character: args){
        if(character == ' '){
            startOfString++;
        }else{
            break;
        }
    }
    this->args = args.substr(startOfString);
}
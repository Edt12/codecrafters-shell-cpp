#include "BuiltIn.h"
#include "Command.h"
#include <iostream>

BuiltIn::BuiltIn(std::string name):Command(name){
        
}
BuiltIn::~BuiltIn(){
    
}
void BuiltIn::getType(){
    std::cout << name << " is a shell builtin"<<"\n";
}
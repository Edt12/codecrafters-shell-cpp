#include "type.h"
#include <iostream>

type::type():BuiltIn("type"){
    
}
    
type::~type(){
    
}

//Actual effect of the command   
 ECommandStatus type::execute(){
     
    
     Parser parser(4);
     registerCommands(&parser);
     std::unique_ptr<Command> command = parser.Parse(this->args);
     std::cout << "PARSED COMMAND"<< "\n";
     if(command == nullptr){
         std::cout<<"invalid_command: not found" << "\n";
     }else{
         command->getType();
     }
     
     return STATUS_SUCCESS;
 }




void type::setArgs(std::string args){
    //gets rid of start of trailing spaces at the start of the string
    int startOfString = 0;
    for (char character: args) {
        if(character != ' '){
            break;
        }
        startOfString++;
    }
    this->args = args.substr(startOfString);
}
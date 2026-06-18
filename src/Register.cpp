#include "Register.h"
//mechanism for adding new commands it these will just call
void registerCommands(Parser* parser){
    parser->RegisterCommand("echo", &instanciateCommand<echo>);
    parser->RegisterCommand("exit", &instanciateCommand<exitCommand>);
    parser->RegisterCommand("type", &instanciateCommand<type>);
}
#include "exitCommand.h"


exitCommand::exitCommand():BuiltIn("exit"){
    
}
    
exitCommand::~exitCommand(){
    
}

ECommandStatus exitCommand::execute(){
    return ECommandStatus::STATUS_EXIT;
}
    
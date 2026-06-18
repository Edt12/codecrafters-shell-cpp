#pragma once
#include "exitCommand.h"
#include "BuiltIn.h"
#include "Command.h"

exitCommand::exitCommand():BuiltIn("exit"){
    
}
    
exitCommand::~exitCommand(){
    
}

ECommandStatus exitCommand::execute(){
    return ECommandStatus::STATUS_EXIT;
}
    
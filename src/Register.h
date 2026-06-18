#pragma once
#include "Parser.h"
#include "echo.h"
#include "exitCommand.h"
#include "type.h"
//mechanism for adding new commands it these will just call
void registerCommands(Parser* parser);
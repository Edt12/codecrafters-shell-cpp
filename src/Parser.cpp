#include "Parser.h"
#include "Command.h"
#include "hasArgs.h"
#include <iostream>
#include <memory>
#include <utility>

Parser::Parser(int maxCommandLength) {
  this->maxCommandLength = maxCommandLength;
}

// Finds the actual command this is fed to the parse function to execute it
std::unique_ptr<Command> Parser::parseCommand(std::string input) {
  // function which then instanciates the command object
  std::unique_ptr<Command> (*command)(void) = nullptr;
  while (currentCommandLength <= this->maxCommandLength) {
    if (commands.find(input.substr(0, currentCommandLength)) != commands.end()) {
        command = commands[input.substr(0, currentCommandLength)];
        break;
    }

    this->currentCommandLength += 1;
  }
  // Nullcheck
  if (command == nullptr) {
    return nullptr;
  } else {
    return command();
  }
}

void Parser::RegisterCommand(std::string name,
                             std::unique_ptr<Command> (*createFunc)(void)) {
  std::pair<std::string, std::unique_ptr<Command> (*)(void)> entry =
      std::make_pair(name, createFunc);
      commands.insert(entry);
}

//  WARNING RETURNS NULLPTR IF NO COMMAND IS FOUND -HANDLE THIS WHEN CALLING
//  THIS FUNCTION
// All possible substrings starts at checking at character length 2
std::unique_ptr<Command> Parser::Parse(std::string input) {
    std::unique_ptr<Command> outputCommand = parseCommand(input);
  
  // Checking if it has arguments and if yes pass in
  //  We dynamically cast here to check if we inherit the has args
  //  This pointer is safe in its current usage as the object is still
  //  controlled by unique ptr have not used unique ptr as dynamic cast does not
  //  accept them
  if (hasArgs *commandWithArgs = dynamic_cast<hasArgs *>(outputCommand.get())) {
    // plus 1 so we exclude the space between command line arguments
    commandWithArgs->setArgs(input.substr(currentCommandLength));
  }
  // reset currentCommandLength attribute to defualt value in this case 2
  currentCommandLength = 2;
  return outputCommand;
}

#include "Command.h"
#include "Parser.h"
#include "Register.h"
#include <iostream>
#include <memory>
#include <string>
int main(int argc, char **argv) {
    int currentArg = 0;
    while (currentArg < argc) {
        std::cout << argv[currentArg] << "\n";
        currentArg++;
    }
    std::unique_ptr<Parser> parser = std::make_unique<Parser>(4);
    registerCommands(parser.get());
    while (true) {

        std::string input;

        std::cout << "$ ";
        std::cout << std::unitbuf;
        std::cerr << std::unitbuf;

        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }

        std::unique_ptr<Command> command = parser->Parse(input);
        // Case where no command is found by the parser
        if (command == nullptr) {
            std::cout << input << ": not found" << "\n";
            std::cout << std::unitbuf;
            std::cerr << std::unitbuf;

        } else {
            ECommandStatus status = command->execute();
            std::cout << std::unitbuf;
            std::cerr << std::unitbuf;
            if (status == STATUS_EXIT) {
                break;
            }
        }
    }
  return 0;
}

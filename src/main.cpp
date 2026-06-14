#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <system_error>

int main() {
  // Flush after every std::cout / std:cerr
  //
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    try {
      std::string input;
      // TODO: Uncomment the code below to pass the first stage
      std::cout << "$ ";
      std::cin >> input;
      if(input == "exit"){
          break;
      }
      if (true) {
        throw std::runtime_error(input + ": command not found");
      }
    } catch (const std::exception &ex) {
      std::cerr << ex.what() << "\n";
      continue;
    }

    return 0;
  }
}

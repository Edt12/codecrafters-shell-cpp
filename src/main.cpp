#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <system_error>

void echo(std::string input){
    std::cout << input <<"\n";
}
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
      std::getline(std::cin,input);
      if(input == "exit"){
          break;
      }
      if(input.substr(0,4) == "echo"){
          echo(input.substr(5));
      }else{
          throw std::runtime_error(input + ": command not found");
      }
      
      
    } catch (const std::exception &ex) {
      std::cerr << ex.what() << "\n";
      continue;
    }

  }
  return 0;
}

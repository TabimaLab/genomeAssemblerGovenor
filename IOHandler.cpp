///////////////////////////////////////////////////////////////
// Handles IO for the program                                // 
// By: Cameron McIlvenna                                     //
// Date : 7/6/2021                                           //
///////////////////////////////////////////////////////////////

#include <iostream> // std::cout and std::cin
#include <string.h> // strcat()
#include <string>   // std::string::compare()
#include "IOHandler.h" // IO calls for program

std::string* assemblyPrompt(){
  std::string *returnStr = new std::string;
  int choiceNum;
  std::cout << "Please pick the assembler you wish to use:\n--------------------------------------------------" << std::endl;
  std::cout << "1 -- Unicycler assembly\n2 -- SPADES assembly" << std::endl;
  while(!(std::cin  >> choiceNum)){
    std::cout << "ERROR: please enter an integer value: ";

    // Clear input stream //
    std::cin.clear();
    // Discard the previous input //
    std::cin.ignore(123, '\n');
  }

  if(choiceNum == 1){
    *returnStr = "unicycler";
  }else if(choiceNum == 2){
    *returnStr = "spades.py";
  }else{
    system("clear");
    std::cout << "Please enter one of the choices provided\n--------------------------------------------------" << std::endl;
    returnStr = assemblyPrompt();
  }
  return returnStr;
}

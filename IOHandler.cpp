///////////////////////////////////////////////////////////////
// Handles IO for the program                                // 
// By: Cameron McIlvenna                                     //
// Date : 7/6/2021                                           //
///////////////////////////////////////////////////////////////

#include <iostream> // std::cout and std::cin
#include <string.h> // strcat()
#include <string>   // std::string::compare()
#include "IOHandler.h" // IO calls for program

std::string assemblyPrompt(){
  int choiceNum;
  std::cout << "Please pick the assembler you wish to use:\n--------------------------------------------------" << std::endl;
  std::cout << "1 -- Unicycler assembly\n2 -- SPADES assembly" << std::endl;
  choiceNum = grabNum();

  if(choiceNum == 1){
    return "unicycler";
  }else if(choiceNum == 2){
    return "spades.py";
  }else{
    system("clear");
    std::cout << "Please enter one of the choices provided\n--------------------------------------------------" << std::endl;
    return assemblyPrompt();
  }
}

char** argsPrompt(){
  char **retArray = new char*[2];
  char temp[] = "pizza";
  retArray[0] = temp;
  retArray[1] = NULL;
  return retArray;
}

int inFilePrompt(std::string cmd){
  int input;
  system("clear");
  std::vector <std::string> cmdVec = {cmd}; 
  std::cout << "Are the read inputs interlaced (one file), or Double ended." << std::endl;   
  std::cout << "1 -- Interlaced\n2 -- Double ended" << std::endl;
  input = grabNum();
  return input;
}

int grabNum(){
  int choiceNum;
  while(!(std::cin >> choiceNum)){
    std::cout << "ERROR: please enter an integer value: ";

    // Clear input stream //
    std::cin.clear();
    // Discard the previous input //
    std::cin.ignore(123, '\n');
  }
  return choiceNum;
}

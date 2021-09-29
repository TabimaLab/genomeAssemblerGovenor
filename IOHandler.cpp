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

// Takes arguments from other visual prompts and loads them into a char** for exec call to desired assembly
char** argsPrompt(std::string allowedThreads){
  int readType = inFilePrompt();
  char **retArray; 
  char outFlag[] = "-o";
  char threadFlag[] = "-t";
  std::string outDir;

  // Interlaced read types
  if (readType == 1){
    retArray = new char*[8];
    char fileInterlaced[] = "--12";
    std::string interlaced;

    std::cout << "Please enter path of interlaced file" << std::endl;
    std::cin >> interlaced;
    std::cout << "Please enter the path to the output directory" << std::endl;
    std::cin >> outDir;

    retArray[0] = fileInterlaced;
    retArray[1] = (char*) interlaced.c_str();
    retArray[2] = outFlag;
    retArray[3] = (char*) outDir.c_str();
    retArray[4] = threadFlag;
    retArray[5] = (char*) allowedThreads.c_str();
    retArray[6] = NULL;

  // Not interlaced read types
  } else if (readType == 2){
    retArray = new char*[9];
    char file1[] = "-1";
    char file2[] = "-2";
    std::string filep1;
    std::string filep2;

    std::cout << "Please enter path of the first file" << std::endl;
    std::cin >> filep1;
    std::cout << "Please enter the path to the second file" << std::endl;
    std::cin >> filep2;
    std::cout << "Please enter the path to the output directory" << std::endl;
    std::cin >> outDir;

    retArray[0] = file1;
    retArray[1] = (char*) filep1.c_str();
    retArray[2] = file2;
    retArray[3] = (char*) filep2.c_str();
    retArray[4] = outFlag;
    retArray[5] = (char*) outDir.c_str();
    retArray[6] = threadFlag;
    retArray[7] = (char*) allowedThreads.c_str();
    retArray[8] = NULL;

  } else{
    return argsPrompt(allowedThreads);
  }

  return retArray;
}

int inFilePrompt(){
  int input;
  system("clear");
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

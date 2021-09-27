///////////////////////////////////////////////////////////////
// Handles IO for the program                                // 
// By: Cameron McIlvenna                                     //
// Date : 7/6/2021                                           //
///////////////////////////////////////////////////////////////

#ifndef IO_HANDLER_H
#define IO_HANDLER_H
#include <iostream>                 // std::cout and std::cin
#include <string>                   // std::string
#include <vector>                   // std::vector

int* mainMenu();
std::string assemblyPrompt();
void inFilePrompt(std::string cmd);
int grabNum();

#endif

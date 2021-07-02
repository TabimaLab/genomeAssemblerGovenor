//////////////////////////////////////////////////////////////
// Creates Process                                           //
// By: Cameron McIlvenna                                     //
// Date : 6/29/2021                                          //
///////////////////////////////////////////////////////////////
#include "createProcess.h"  // linkage header file between this file and main.cpp
extern "C" {
  #include "execute.h"
}
#include <iostream>         // cout << cin << endl
#include <unistd.h>         // execv(), fork()
#include <sys/types.h>      // pid_t
#include <sys/wait.h>       // waitpid()
#include <fstream>
#if defined(__cplusplus) || defined(_cplusplus)
#include <exception>        // terminate()
#else
#include <cstdlib>          // abort()
#endif


pid_t createProcess(char inCmd[], char *inArg[]){
  // Casts inCmd[] to cmd[50] //
  int i = 0;
  char cmd[50];
  while(inCmd[i] != '\0'){ // Iterate through inCmd[] and copy onto cmd[] until \0 is met, then add \0 onto end of cmd[]
    cmd[i] = inCmd[i];
    i++; 
  }
  cmd[i] = '\0';
  
  // Casts *inArg[] to child_args[] //
  int j = 1;
  char *child_args[10];
  child_args[0] = cmd;
  while(inArg[j-1] != NULL){ // Iterate through *inArg[] and copy to child_args[] until NULL is met, then add NULL to onto end of child_args[]
    child_args[j] = inArg[j-1];   
    j++;
  }
  child_args[j+1] = NULL;
 
  // Debug child_args[] //
  bool debugChildArg = false;
  if(debugChildArg){
    std::cout << inArg[0] << std::endl;
    int k = 0;
    while(child_args[k] != NULL){
      std::cout << child_args[k] << std::endl;
      k++;
    }
  }

  // Starts New Process Here //
  pid_t child_pid = fork();

  // Creates folder in output path for program for stdout logs //

  switch(child_pid){
    case -1:  // I am the parent and failed to turn into process.
      break;

    case 0:   // I am the child.
      char mkDirStr[] = "mkdir -p ";
      char touchCmd[] = "touch ";
      char logDirName[] = "/stdIOLogs";
      char logFileName[] = "/stdOutLog";
      char *dirClone = child_args[6];
      char logDir[100]; 
      int l = 0; int m = 0;
      while(mkDirStr[l] != '\0'){
        logDir[l] = mkDirStr[l];    
        l++;
      }
      while(child_args[6][m] != '\0'){
        logDir[l] = dirClone[m];
        l++; m++;
      }
      m = 0;
      while(logDirName[m] != '\0'){
        logDir[l] = logDirName[m];
        l++; m++;
      }
      l = 0; m = 0;
      char logOut[100]; 
      while(touchCmd[l] != '\0'){
        logOut[l] = touchCmd[l];
        l++;
      }
      while(child_args[6][m] != '\0'){
        logOut[l] = dirClone[m];
        l++; m++;
      }
      m = 0;
      while(logDirName[m] != '\0'){
        logOut[l] = logDirName[m];
        l++; m++;
      }
      m = 0;
      while(logFileName[m] != '\0'){
        logOut[l] = logFileName[m];
        l++; m++;
      }
      system(logDir);
      system(logOut);
      execProcess(cmd, child_args);
  }


  return child_pid;
}

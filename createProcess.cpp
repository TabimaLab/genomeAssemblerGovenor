///////////////////////////////////////////////////////////////
// Creates Process                                           //
// By: Cameron McIlvenna                                     //
// Date : 6/29/2021                                          //
///////////////////////////////////////////////////////////////
#include "createProcess.h"  // linkage #include
#include <iostream>         // cout << cin << endl
#include <unistd.h>         // execv(), fork()
#include <sys/types.h>      // pid_t
#include <sys/wait.h>       // waitpid()
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
  while(inArg[j-1] != NULL){            // Iterate through *inArg[] and copy to child_args[] until NULL is met, then add NULL to onto end of child_args[]
    child_args[j] = inArg[j-1];   
    j++;
  }
  child_args[j+1] = NULL;
 
  // Debug child_args[] //
  std::cout << inArg[0] << std::endl;
  std::cout << child_args[0] << std::endl;
  std::cout << child_args[1] << std::endl;
  std::cout << child_args[2] << std::endl;
  std::cout << child_args[3] << std::endl;

  // Starts New Process Here //
  pid_t child_pid = fork();
  
  switch(child_pid){
    case -1:  // I am the parent and failed to turn into process.
      break;

    case 0:   // I am the child.
      execvp(cmd, child_args);
      #if defined(__cpluplus) || defined(__cplusplus)
      std::terminate();
      #else
        abort()
      #endif
  }


  return child_pid;
}

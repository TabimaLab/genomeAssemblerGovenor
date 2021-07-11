//////////////////////////////////////////////////////////////
// Creates Process                                           //
// By: Cameron McIlvenna                                     //
// Date : 6/29/2021                                          //
///////////////////////////////////////////////////////////////
#include <cstdio>           // freopen() change the stdout of the forked child to a log document rather than stdouting to the terminal
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
#include <string.h>         // strcat

class process{
public:
  std::string whatAmI;
  std::string logPath;
  pid_t myID;
  pid_t gPid;

  process(char *cmdArg, char *argsIn[]){
    whatAmI = "Not Assigned";
    logPath = "No Path Yet";
    createProcess(cmdArg, argsIn);
  }
private:
  pid_t createProcess(char *inCmd, char *inArg[]){
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
    char *child_args[100];
    child_args[0] = cmd;
    while(inArg[j-1] != NULL){ // Iterate through *inArg[] and copy to child_args[] until NULL is met, then add NULL to onto end of child_args[]
      child_args[j] = inArg[j-1];   
      j++;
    }
    child_args[j+1] = NULL;
   
    // Debug child_args[] //
    bool debugChildArg = false;
    if(debugChildArg){
      //std::cout << cmd << std::endl;
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
        std::string logDir = "mkdir -p " + (std::string)child_args[6] + "/stdIOLogs";
        std::string logOut = (std::string)child_args[6] + "/stdIOLogs/stdOutLog"; 
        // Creates system folder for process logs //
        system(logDir.c_str());
        // Creats stdOutLog file for created process to store its standard output into a log
        freopen(logOut.c_str(), "a", stdout);

        // Turns forked proccess into desired process //
        execvp(cmd, child_args); 
    }
    whatAmI = cmd;
    myID = child_pid;
    gPid = setpgid(0, 0);
    return child_pid;
  }
};

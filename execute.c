///////////////////////////////////////////////////////////////
// Creates Process                                           //
// By: Cameron McIlvenna                                     //
// Date : 6/29/2021                                          //
///////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
  #include "execute.h"
}
#endif
#include <unistd.h>         // execv(), fork()
#include <sys/types.h>      // pid_t
#if defined(__cplusplus) || defined(_cplusplus)
#include <exception>        // terminate()
#endif

void execProcess(char *inCmd, char **inArg){
  execvp(inCmd, inArg); 
  #if defined(__cplusplus)
    std::terminate();   
  #endif
}

///////////////////////////////////////////////////////////////
// Creates Process                                           //
// By: Cameron McIlvenna                                     //
// Date : 6/29/2021                                          //
///////////////////////////////////////////////////////////////

#ifndef EXECUTE_PROCESS_H
#define EXECUTE_PROCESS_H
#include <sys/types.h>      // pid_t
#if defined(__cplusplus)
  extern "C" {
#endif
    void execProcess(char *inCmd, char **inArg);  
#if defined(__cplusplus)
  }
#endif

#endif

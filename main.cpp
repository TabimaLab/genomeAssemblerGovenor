////////////////////////////////////////////////////////
// Schedules Assemblies Concurrently                   //
// By: Cameron McIlvenna                               //
// Date: 6/22/21                                       //
/////////////////////////////////////////////////////////

#include <sys/types.h>      // pid_t                    // process id number
#include <sys/wait.h>       // waitpid()                // waits for process to finish
#include <iostream>         // std::cout                // standard input and output funcionality
#include <sys/time.h>       // gettimeofday()           // gets wall time
#include <time.h>           // clock()                  // gets CPU time on Linux
#include "createProcess.h"  // createProcess()          // creates a process
#include "IOHandler.h"      // assemblyPrompt(), etc    // handles IO for the rest of the program



int main(int argc, char *argv[]){
  char *testCmd = (char*)assemblyPrompt()->c_str();
  std::cout << testCmd << std::endl;
  char outDir[] = "-o";
  char outDirP[] = "Unicycler_Test";
  char file1Indicator[] = "-1";
  char file2Indicator[] = "-2";
  char file1[] = "-1";
  char file2[] = "-2";
  char file1P[] = "NB0720_010_S38_R1_001.fastq.gz";
  char file2P[] = "NB0720_010_S38_R2_001.fastq.gz";
  char *procArgs[] = {file1, file1P, file2, file2P, outDir, outDirP, NULL};
  
  process *firstProcess = new process(testCmd, procArgs);
  std::cout << firstProcess->gPid << std::endl;
  //createProcess(testCmd, procArgs); 

}

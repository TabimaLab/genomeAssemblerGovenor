////////////////////////////////////////////////////////
// Schedules Assemblies Concurrently                   //
// By: Cameron McIlvenna                               //
// Date: 6/22/21                                       //
/////////////////////////////////////////////////////////

#include <sys/types.h>      // pid_t              // process id number
#include <sys/wait.h>       // waitpid()          // waits for process to finish
#include <iostream>         // std::cout          // standard input and output funcionality
#include <sys/time.h>       // gettimeofday()     // gets wall time
#include <time.h>           // clock()            // gets CPU time on Linux
#include "createProcess.h"  // createProcess()    // creates a process



int main(int argc, char *argv[]){
  char testCmd[] = "unicycler";
  char outDir[] = "-o";
  char outDirP[] = "Unicycler_Test";
  char file1Indicator[] = "-1";
  char file2Indicator[] = "-2";
  char file1[] = "-1";
  char file2[] = "-2";
  char file1P[] = "NB0720_010_S38_R1_001.fastq.gz";
  char file2P[] = "NB0720_010_S38_R2_001.fastq.gz";
  char *procArgs[] = {file1, file1P, file2, file2P, outDir, outDirP, NULL};
  std::cout << "B4 proccess" << std::endl;
  
  createProcess(testCmd, procArgs);
  createProcess(testCmd, procArgs); 
  std::cout << "After process" << std::endl;

}

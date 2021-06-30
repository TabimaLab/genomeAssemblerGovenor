////////////////////////////////////////////////////////
// Schedules Assemblies Concurrently                   //
// By: Cameron McIlvenna                               //
// Date: 6/22/21                                       //
/////////////////////////////////////////////////////////

#include <sys/types.h>      // pid_t
#include <sys/wait.h>       // waitpid()
#include <iostream>         // std::cout
#include "createProcess.h"  // creates a process



int main(int argc, char *argv[]){
  char testCmd[] = "unicycler";
  char outDir[] = "-o unicyclerTest";
  char file1Indicator[] = "-1";
  char file2Indicator[] = "-2";
  char file1[] = "-1 NB0720_010_S38_R1_001.fastq.gz";
  char file2[] = "-2 NB0720_010_S38_R2_001.fastq.gz";
  char *procArgs[] = {file1, file2, outDir, NULL};
  std::cout << "B4 proccess" << std::endl;
  
  createProcess(testCmd, procArgs);
  std::cout << "After process" << std::endl;

}

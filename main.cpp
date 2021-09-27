////////////////////////////////////////////////////////
// Schedules Assemblies Concurrently                   //
// By: Cameron McIlvenna                               //
// Date: 6/22/21                                       //
/////////////////////////////////////////////////////////

#include <string>
#include <sys/types.h>      // pid_t                    // process id number
#include <sys/wait.h>       // waitpid()                // waits for process to finish
#include <iostream>         // std::cout                // standard input and output funcionality
#include <sys/time.h>       // gettimeofday()           // gets wall time
#include <time.h>           // clock()                  // gets CPU time on Linux
#include <vector>           // std::vector              // vector object 
#include <thread>           // std::thread
#include "createProcess.h"  // createProcess()          // creates a process
#include "IOHandler.h"      // assemblyPrompt(), etc    // handles IO for the rest of the program
#include <stdlib.h>         // abs()                    // for the timers

// Current way to input arg 1: output directory
//                      arg 2: threads allocated


std::vector <process*> processVector;

struct timeval myTimer;
struct timeval secondTimer;
int timeDiffSec = 0;
int timeDiffMicro = 0;
int cpuStart = 0;
int cpuEnd = 0;
int cpuDiff = 0;
int status;

int main(int argc, char *argv[]){
  std::string tmp = assemblyPrompt();
  char *testCmd = (char*) assemblyPrompt().c_str();
  //char testCmd[] = "spades.py";
  char outDir[] = "-o";
  char outDirP[] = "Threads_Test_4";
  char file1Indicator[] = "-1";
  char file2Indicator[] = "-2";
  char file1[] = "-1";
  char file2[] = "-2";
  char file1P[] = "/home/cmcilvenna/assemblyScheduleInator/NB0720_010_S38_R1_001.fastq.gz";
  char file2P[] = "/home/cmcilvenna/assemblyScheduleInator/NB0720_010_S38_R2_001.fastq.gz";
  char threadFlag[] = "-t";
  char threadAlloc[] = "4";
  char *procArgs[] = {file1, file1P, file2, file2P, outDir, argv[1], threadFlag, argv[2],NULL};
  
  
  cpuStart = clock(); // Cpu start time
  gettimeofday(&myTimer, NULL); // Start time
  processVector.emplace_back(new process(testCmd, procArgs));

  waitpid(processVector[0]->myID, &status, 0); // Wait for the process to die
  gettimeofday(&secondTimer, NULL); // End time
  cpuEnd = clock(); // Cpu end time
  
  timeDiffSec = abs(secondTimer.tv_sec - myTimer.tv_sec);
  timeDiffMicro = abs(secondTimer.tv_usec - myTimer.tv_usec);
    
  std::string timeDir(argv[1]);
  timeDir = timeDir + "/timeLog.txt";
  freopen(timeDir.c_str(), "w", stdout);
  std::cout << "Time elapsed: " << timeDiffSec << " seconds, and " << timeDiffMicro << " microseconds." << std::endl;
  std::cout << "Cpu ticks elapsed: " << cpuEnd - cpuStart << std::endl;
  std::cout << "Threads available: " << std::thread::hardware_concurrency() << std::endl;
  
}

# Genome assembly automation for **SPADES** and **unicycler**.
## Future goals

1. **Input and output**
> As of now this program has no IO at all! 
> I will be working on a basic text prompt style IO.
2. **Assembly queuing**
> After initial IO is out of the way feature will be added to queue multiple assemblies to either run linearly (one after another) or concurrently start processes giving them to the operating system to decide when they run with the thread count that I set. This will not improve the speed at which any **individual** assembly runs as a I would be allocating less threads to each process. If I find that the majority of the programs in the pipeline take good advantage of parallel programming, automation will proceed in a linear fashion. 
3. **Analysis Tools Automation**
> Tools like **bwa**, **blastn**, **Pileup**, **sendSketch**, **Prokka**,  will be automated as well.
4. **Rcpp interface for graphing and easier analysis and beyond**
>  I will be teaching myself and taking courses on more C++, and R with the goal of allowing all of the previous automation work to be analyzed in languages like **R** and **Python** to make data analysis easier and have less barrier of entry. Right now most people need to be able to navigate in a Linux environment with bash and other shell languages. Not knowing bash should not be a barrier to entry with utilizing computers in genetic research. 

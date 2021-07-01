# Genome assembly automation and scheduling

The pipeline for assembling genomes is still long, complicated, slow, and needlessly bad at organizing output files. In order to fix this I propose that we
automate the pipeline for *SPADES*, *Unicycler* and various analysis programs further down the pipline like *bwa*, *pileup.sh*, etc. By unifying programs that
analyze *Illumina Seq* and other various short/long read technologies such as *Nanopore*, I plan to create and easier interface for scientists to interact 
with.

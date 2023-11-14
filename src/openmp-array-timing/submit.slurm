#!/bin/bash

# 1 core
#SBATCH -n 1
#SBATCH --job-name="array_timming"
#SBATCH -o array_timming.%J.out
#SBATCH -e array_timming.%J.err
#SBATCH -t 00:01:00
#SBATCH -p test

module load gcc
gcc -o array_timming Timming.c
ulimit -s unlimited
./array_timming 6 10
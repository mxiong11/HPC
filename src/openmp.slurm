#!/bin/bash

# 1 node
#SBATCH --nodes=1
#SBATCH --job-name="hello-openmp"
#SBATCH -o hello-openmp.%J.out
#SBATCH -e hello-openmp.%J.err
#SBATCH -t 00:01:00
#SBATCH -p shared

module load openmp

export OMP_NUM_THREADS=4
gcc -fopenmp openmp.c -o hello-openmp
./hello-openmp

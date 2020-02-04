#!/bin/bash
# typically put in your home directory 
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-MacOSX-x86_64.sh
#wget https://repo.continuum.io/miniconda/Miniconda2-latest-Linux-x86_64.sh
bash Miniconda3-latest-MacOSX-x86_64.sh
export PATH="$CONDA_PREFIX/miniconda3/bin:$PATH"
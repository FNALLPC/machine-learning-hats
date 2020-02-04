#!/bin/bash

echo "ML tutorial setup script"


conda create --name MLtutorial2 python=3.7.0

conda activate MLtutorial2

pip install jupyter
pip install uproot
pip install h5py keras tensorflow
pip install pandas matplotlib
pip install sklearn
pip install torch

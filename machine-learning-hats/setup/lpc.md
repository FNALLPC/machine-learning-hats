# LPC

This is possible, but with a little less user support. You will need to use the following command to open up your ssh connection:

```bash
ssh -L localhost:8888:localhost:8888 <username>@cmslpc-sl7.fnal.gov
```
Replace `<username>` with your LPC username. Then `cd` to the directory of your choice where you will clone the repository as before:
```bash
git clone https://github.com/FNALLPC/machine-learning-hats
```

In order to open Jupyter with all the appopriate libraries, you will need to have either installed a `conda` environment with Jupyter in your `nobackup` area (where you have more space) or have a CMSSW environment setup. To install and activate a `conda` environment you can do:
```bash
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O $HOME/nobackup/miniconda3.sh
bash $HOME/nobackup/miniconda3.sh -b -f -u -p $HOME/nobackup/miniconda3
source $HOME/nobackup/miniconda3/etc/profile.d/conda.sh
conda env create -f environment.yml
conda activate machine-learning-hats
```

Once you have a `conda` environment, open Jupyter (which is actually the Jupyter that gets installed as part of the `conda` environment):
```bash
jupyter notebook --no-browser --port=8888 --ip 127.0.0.1
```
If everything worked, the last line of the output should be a url of the form:
```bash
http://127.0.0.1:8888/?token=<long string of numbers and letters>
```
Copy this url into your browser. You may now perform the rest of the exercise like normal, except you will have to change the kernel to the default python3 one (it will have all the necessary libararies because you are using the Jupyter version that is part of your `conda` installation).

In the future, when you need access to Jupyter and want to run this exercise, you can do `source $HOME/nobackup/miniconda3/etc/profile.d/conda.sh; conda activate machine-learning-hats`
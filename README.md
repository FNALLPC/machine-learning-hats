# CMS Machine Learning Hands-on Advanced Tutorial Session (HATS)

[![Jupyter Book Badge](https://jupyterbook.org/badge.svg)](https://FNALLPC.github.io/machine-learning-hats/main.html)
[![Codestyle](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/FNALLPC/machine-learning-hats/main.svg)](https://results.pre-commit.ci/latest/github/FNALLPC/machine-learning-hats/main)

## Introduction

This is a set of tutorials for the CMS Machine Learning Hands-on Advanced Tutorial Session (HATS). 
They are intended to show you how to build machine learning models in python (`Keras`/`TensorFlow`) and use them in your `ROOT`-based analyses. 
We will build event-level classifiers for differentiating VBF Higgs and standard model background 4 muon events and jet-level classifiers for differentiating boosted W boson jets from QCD jets.

## Setup

**TODO**


### Vanderbilt Jupyterhub

Check out the instructions in **TODO**.

## FAQ

### If someone updates the notebooks after it've clones the repository, how do I get they updates?

In this case you will want to open a terminal, just as you did when you first cloned the repository. Move (`cd`) to the repository directory if not already there. Then do `git pull origin master`. This will pull the latest changes from GitHub. If you've already made edits to a notebook which will be updated, those changes will be conflict. You may want to stash those changes or copy your modified notebook.

To revert the changes made to all of your notebooks you can use the command:
```
git checkout .
```
If you would like to save your changes first, you can copy your modified notebook to a new name and then run the `checkout` command.

Alternatively, to stash your un-staged changes, use the command:
```
git stash
```

You can then return those changes with the command:
```
git stash pop
```
Be aware that you may have conflicts that need to be fixed before the notebook can be run again.

### I want to follow along on the LPC rather than ACCRE.

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
conda env create -f environment.yml --name machine-learning-hats-2021
conda activate machine-learning-hats-2021
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

In the future, when you need access to Jupyter and want to run this exercise, you can do `source $HOME/nobackup/miniconda3/etc/profile.d/conda.sh; conda activate machine-learning-hats-2021`

## Links

The indico page is: [https://indico.cern.ch/event/1311559/](https://indico.cern.ch/event/1311559/)

The Mattermost for live support is: [https://mattermost.web.cern.ch/cms-exp/channels/hatslpc-2023](https://mattermost.web.cern.ch/cms-exp/channels/hatslpc-2023)

The datasets we will use are located here: [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.3901869.svg)](https://doi.org/10.5281/zenodo.3901869)


## Credits

This project is created using the excellent open source [Jupyter Book project](https://jupyterbook.org/) and the [executablebooks/cookiecutter-jupyter-book template](https://github.com/executablebooks/cookiecutter-jupyter-book).
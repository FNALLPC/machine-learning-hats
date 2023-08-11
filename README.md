# CMS Machine Learning Hands-on Advanced Tutorial Session (HATS)

[![Jupyter Book Badge](https://jupyterbook.org/badge.svg)](https://FNALLPC.github.io/machine-learning-hats/index.html)
[![Codestyle](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/FNALLPC/machine-learning-hats/master.svg)](https://results.pre-commit.ci/latest/github/FNALLPC/machine-learning-hats/master)

## Introduction

This is a set of tutorials for the CMS Machine Learning Hands-on Advanced Tutorial Session (HATS). 
They are intended to show you how to build machine learning models in python, using `Keras`, `TensorFlow`, and `PyTorch`, and use them in your `ROOT`-based analyses. 
We will build event-level classifiers for differentiating VBF Higgs and standard model background 4 muon events and jet-level classifiers for differentiating boosted W boson jets from QCD jets using dense and convolutional neural networks.
We will also explore more advanced models such as graph neural networks (GNNs), variational autoencoders (VAEs), and generative adversarial networks (GANs) on simple datasets.

## Setup

### Vanderbilt Jupyterhub (Recommended!)

The recommended method for running the tutorials live is the Vanderbilt Jupyterhub, follow the instructions [here](asdf).

### FNAL LPC

Not as well supported, but instructions are [here](asdf).

### Locally

All these notebooks can be run on your local machine as well. 
It can often be useful to test your models and pipelines locally, but it is not recommended to run full trainings as these can be resource-intensive.

To run locally, run these commands from your terminal:

```bash
# Download the setup bash file for your machine from here https://github.com/conda-forge/miniforge#mambaforge
# e.g. wget https://github.com/conda-forge/miniforge/releases/latest/download/Mambaforge-Linux-x86_64.sh
# Install: (the mamba directory can end up taking O(1-10GB) so make sure the directory you're using allows that quota)
chmod u+x Mambaforge-Linux-x86_64.sh
./Mambaforge-Linux-x86_64.sh  # follow instructions in the installation

git clone https://github.com/FNALLPC/machine-learning-hats/
cd machine-learning-hats
mamba create -f environment.yml
mamba activate machine-learning-hats
jupyter lab  # this will create a JupyterLab instance from which you can run all the notebooks.
```

### Binder

TODO


### Google Colab

TODO


## Links

The indico page is: [https://indico.cern.ch/event/1311559/](https://indico.cern.ch/event/1311559/)

The Mattermost for live support is: [https://mattermost.web.cern.ch/cms-exp/channels/hatslpc-2023](https://mattermost.web.cern.ch/cms-exp/channels/hatslpc-2023)

The datasets we will use are located here: [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.3901869.svg)](https://doi.org/10.5281/zenodo.3901869)


## Credits

This project is created using the excellent open source [Jupyter Book project](https://jupyterbook.org/) and the [executablebooks/cookiecutter-jupyter-book template](https://github.com/executablebooks/cookiecutter-jupyter-book).
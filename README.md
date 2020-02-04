# Machine Learning Hands-on Advanced Tutorial Session (HATS)

## Introduction

This is a set of tutorials for the Machine Learning Hands-on Advanced Tutorial Session (HATS). They are intended to show you how to build machine learning models in python (`Keras`/`TensorFlow`) and use them in your `ROOT`-based analyses. We will build event-level classifiers for differentiating VBF Higgs and standard model background 4 muon events and jet-level classifiers for differentiating boosted W boson jets from QCD jets.

## Main notebooks in this tutorial

 0. [`a-dataset-and-plot.ipynb`](0-setup-libraries.ipynb): reading/writing datasets from `ROOT` files with `uproot` and plotting with `matplotlib`
 1. [`b-dense.ipynb`](1-datasets-uproot.ipynb): building, training, and evaluating a fully connected (dense) neural network in `Keras`
 2. [`4-preprocessing.ipynb`](4-preprocessing.ipynb): preprocessing CMS open data to build jet-images (optional) -- *still adapting, do not try yet*
 3. [`5-conv2d.ipynb`](5-conv2d.ipynb): building, training, and evaluating a 2D convolutional neural network in `Keras` -- *still adapting, do not try yet*

## Setup

We will be setting up the environment using Miniconda () wity Python3.  This is wrapped in a Docker () container for easy deployment.  

### Plain Miniconda3 setup
```
# currently it's setup for Mac, change the file if you want to run on Linux
source install_miniconda3.sh
# setup conda environmeent and install needed packages
source setup.sh
```

### Docker setup
_On its way -- need some help from Maria_

## Links

The indico page is: [https://indico.cern.ch/event/814896/](https://indico.cern.ch/event/814896/)

The Mattermost for live support is: [https://mattermost.web.cern.ch/cms-exp/channels/machine-learning-hats](https://mattermost.web.cern.ch/cms-exp/channels/machine-learning-hats)


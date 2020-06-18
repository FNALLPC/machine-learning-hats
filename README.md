# CMS Machine Learning Hands-on Advanced Tutorial Session (HATS)

## Introduction

This is a set of tutorials for the CMS Machine Learning Hands-on Advanced Tutorial Session (HATS). They are intended to show you how to build machine learning models in python (`Keras`/`TensorFlow`) and use them in your `ROOT`-based analyses. We will build event-level classifiers for differentiating VBF Higgs and standard model background 4 muon events and jet-level classifiers for differentiating boosted W boson jets from QCD jets.

## Main notebooks in this tutorial

 0. [`0-setup-libraries.ipynb`](0-setup-libraries.ipynb): setting up libraries using `CMSSW`
 1. [`1-datasets-uproot.ipynb`](1-datasets-uproot.ipynb): reading/writing datasets from `ROOT` files with `uproot`
 2. [`2-plotting.ipynb`](2-plotting.ipynb): plotting with `pyROOT` and `matplotlib`
 3. [`3-dense.ipynb`](3-dense.ipynb): building, training, and evaluating a fully connected (dense) neural network in `Keras`
 4. [`3.1-dense-pytorch.ipynb`](3.1-dense-pytorch.ipynb): The same as [`3-dense.ipynb`](3-dense.ipynb), but using `PyTorch` rather than `Keras`/`TensorFlow.
 5. [`3.2-dense-bayesian-optimization.ipynb`](3.2-dense-bayesian-optimization.ipynb): The same as [`3-dense.ipynb`](3-dense.ipynb), but using Bayesian optimization of the hyperparameters of the model
 6. [`4-preprocessing.ipynb`](4-preprocessing.ipynb): preprocessing CMS open data to build jet-images (optional)
 7. [`5-conv2d.ipynb`](5-conv2d.ipynb): building, training, and evaluating a 2D convolutional neural network in `Keras`
 8. [`7-vae-mnist.ipynb`](8-gan-mnist.ipynb): building, training, and evaluating a variational autoencoder in `Keras`
 9. [`8-gan-mnist.ipynb`](8-gan-mnist.ipynb): building, training, and evaluating a generative adversarial neural network in `Keras`

## Setup

We will be using the Vanderbilt JupyterHub. Point your browser to:

[https://jupyter.accre.vanderbilt.edu/](https://jupyter.accre.vanderbilt.edu/)

If this is the first time using this JupyterHub, you should see:

<p align="center">
  <img src="vanderbilt.png" width="500"/>
</p>

Click the "Sign in with Jupyter ACCRE" button. On the following page, select CERN as your identity provider and click the "Log On" button. Then, enter your CERN credentials or use your CERN grid certificate to autheticate. Click "Spawn" to start a "Default ACCRE Image v5" image with "8 Cores, 8 GB RAM, 1 day timeout."

Now you should see the JupyterHub home directory. Click on "New" then "Terminal" in the top right to launch a new terminal. 

<p align="center">
  <img src="new_terminal.png" width="200"/>
</p>

To download the tutorials, type

```
git clone https://github.com/FNALLPC/machine-learning-hats
```

Now, in your directory tab, there should be a new directory called `machine-learning-hats`. All of the tutorials and exercises are in there. Start by clicking on [`0-setup-libraries.ipynb`](0-setup-libraries.ipynb) and running it. Please note that the last cell may take up to 20 minutes to run.

Now close this notebook by clicking on `File->Close and Halt`. Click the "New" button again. You should see a new kernal called `machine-learning-hats`. If you do not, refresh the page and look again.

<p align="center">
  <img src="new_mlhats.png" width="200"/>
</p>

## Links

The indico page is: [https://indico.cern.ch/event/814896/](https://indico.cern.ch/event/814896/)

The Mattermost for live support is: [https://mattermost.web.cern.ch/cms-exp/channels/machine-learning-hats](https://mattermost.web.cern.ch/cms-exp/channels/machine-learning-hats)


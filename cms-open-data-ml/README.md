# CMS Open Data + Machine Learning

## Introduction

This is introductory tutorial for hands-on session of the DS@HEP2017 workshop and the CMS Hands on Tutorial Session (HATS). It is intended to show you how to analyze simulated and reconstructed pp collision events from the 2011 CMS Open Data release and build classifiers for differentiating boosted, merged W boson jets from QCD jets.

# Main notebook in this tutorial

 1. `dshep2017.ipynb`

## Getting started with AWS

You will be issued a unique IP in class for access to an Amazon Web Services GPU node. The disk is persistent, but the IP may change day-to-day.

Download the encrypted access key:

    wget http://home.fnal.gov/~burt/ds.pem.enc

Decrypt and protect the access key (the decryption password will be given at the session):

    openssl aes-256-cbc -in ds.pem.enc -d -a -out ds.pem
    chmod 400 ds.pem

When you log into AWS, add a `-L` option to your ssh command, and use the access key:

    ssh -i ds.pem -L localhost:8888:localhost:8888 ec2-user@<your AWS IP>

After you're logged in source the python distribution you want for example:

    source src/anaconda2/bin/activate
   
Then cottoncandy is useful for reading from S3:

     sudo pip install boto3 pydrive
     git clone https://github.com/holzman/cottoncandy
     cd cottoncandy
     sudo python setup.py install
     eval `./parse_metadata.py`
     cd ..
    
Then clone this repository

    git clone https://github.com/jmduarte/scientific-python-hats
    cd scientific-python-hats/cms-open-data-ml

And now start Jupyter with this command:

    jupyter notebook --no-browser --port=8888 --ip localhost

After a pause (while cmslpc loads the necessary libraries for the first time) you should see a message like the following:

    [I 08:22:45.871 NotebookApp] Serving notebooks from local directory: /uscms_data/d2/pivarski/CMSSW_9_0_0_pre6/src
    [I 08:22:45.871 NotebookApp] 0 active kernels 
    [I 08:22:45.871 NotebookApp] The Jupyter Notebook is running at: http://localhost:8888/?token=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    [I 08:22:45.871 NotebookApp] Use Control-C to stop this server and shut down all kernels (twice to skip confirmation).
    [C 08:22:45.873 NotebookApp] 
        
        Copy/paste this URL into your browser when you connect for the first time,
        to login with a token:
            http://localhost:8888/?token=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Copy/paste the URL it gives you into your web browser and from now on, all interactions with Python and your user account will be through the browser. The `-L` option we passed to ssh is forwarding Jupyter's web traffic through SSH, so your account is safe, even if you access it from home.

Jupyter and all the other Python libraries we will be studying are bundled in CMSSW / AWS. For these exercises, there is no need to install anything else.

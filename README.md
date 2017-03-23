# Scientific Python HATS

Intro...

## Getting started

We will use Jupyter to present these tutorials, only because it is a convenient interface to Python. Everything that we will present can be performed the old-fashioned way, by editing scripts and running them from the command line. However, a notebook interface lets you interact with the process and retry steps, which is good for learning.

When you log into cmslpc, add a `-L` option to your ssh command:

    ssh -L localhost:8888:localhost:8888 cmslpc-sl6.fnal.gov

On cmslpc, create a CMSSW directory as usual (version 9 and above):

    export SCRAM_ARCH=slc6_amd64_gcc530
    cmsrel CMSSW_9_0_0_pre6
    cd CMSSW_9_0_0_pre6/src
    cmsenv

And now start Jupyter with this command:

    jupyter notebook --no-browser --port=8888 --ip localhost

After a pause (while cmslpc loads the necessary libraries, you should see a message like the following:

    [I 08:22:45.871 NotebookApp] Serving notebooks from local directory: /uscms_data/d2/pivarski/CMSSW_9_0_0_pre6/src
    [I 08:22:45.871 NotebookApp] 0 active kernels 
    [I 08:22:45.871 NotebookApp] The Jupyter Notebook is running at: http://localhost:8888/?token=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    [I 08:22:45.871 NotebookApp] Use Control-C to stop this server and shut down all kernels (twice to skip confirmation).
    [C 08:22:45.873 NotebookApp] 
        
        Copy/paste this URL into your browser when you connect for the first time,
        to login with a token:
            http://localhost:8888/?token=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Copy/paste the URL it gives you into your web browser and from now on, all interactions with Python and your user account will be through the browser. The `-L` option we passed to ssh is forwarding Jupyter's web traffic through SSH, so your account is safe, even if you access it from home.

Jupyter and all the other Python libraries we will be studying are bundled in CMSSW. For these exercises, there is no need to install anything else.

## First notebook

...

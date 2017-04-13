from os import listdir
from os.path import isfile, join

###
#    HATS comment: 
# Now we want to create an interface for our class in python
# Since we have a lot of data, we will write this so that it loops over a directory
# filled with our input files, and spits out a one output file 
# corresponding to the entire directory.
###

###
#    HATS comment: 
#  Let's not hardcode anything, instead let's run our class's Loop method by
#  passing our python interface some options
#  In case we forget how to use our python interface, we'll write help comments too :-)
###
from optparse import OptionParser
parser = OptionParser()
parser.add_option("-l", "--load", dest = "load",
                  action = "store_true", default = False,
                  help = "do not recompile the class, instead load it from a compiled library" )
parser.add_option("-i", "--inDir", dest = "inDir",
                  help = "the input directory of root files" )
parser.add_option("-t", "--inTreeName", dest = "inTreeName",
                  help = "the name of the input tree inside the input file" )
parser.add_option("-o", "--outFileName", dest = "outFileName",
                  help = "the file output root file" )
(options, args) = parser.parse_args()

###
#    HATS comment: 
# Here is a pyROOT gotcha: once you import anything from ROOT, the ROOT command line options 
# will override anything you've defined with your OptionParser. So if you define something
# in your options like -l, that will conflict with the ROOT option to disable the ROOT 
# splash logo. So we only import ROOT once we've already parsed our options.
###

from ROOT import *

###   HATS comment:
# let's combine all the input trees into one TChain 
# Then we can pass that to our ROOT class to crunch
###
chain = TChain(options.inTreeName)
inFiles = []
for inFile in listdir(options.inDir):
  if isfile(join(options.inDir, inFile)):
    inFiles.append(join(options.inDir, inFile))
for sample in inFiles:
  chain.Add(sample)

###   HATS comment:
# By default, gSystem.CompileMacro will compile your ROOT class, load it on its own, and then delete it
# once your pyROOT script is closed. Instead, we want to be able to just compile it once, keep the
# compiled library, and then we can reuse it again without recompiling it
# This is important if you're going to run this script e.g. in a cluster submission
# because if two parallel processes try to compile the macro simultaneously,
# one process might try overwriting the library while another is trying to load it.
#
# The options we use are:
# g --> compile with debug symbols. This is nice if you have a bug in your macro
# O --> optimize the code. This does something behind the scenes, so why not
# c --> compile the macro only and don't load it. We do this so that if we only want to load it, we can, but if we want to do both, we won't try twice
# k --> keep the compiled library and don't delete it when the pyroot script ends.
###
if not options.load:
  gSystem.CompileMacro("hatsTrees.C", "gOck")

### Now we can load our class into our pyROOT session:
gSystem.Load("hatsTrees_C")

### HATS comment:
# now we create an instance of our class
###
instance = hatsTrees(chain)

### HATS comment:
# and now we call our class's 'Loop' method
###
instance.Loop("output/%s" % options.outFileName)

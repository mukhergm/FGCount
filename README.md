##Requirements

unix system (tested on Ubuntu 18.04 LTS and PharmCADD server)
bash shell to run the CLI scripts
conda for RDKIT (https://conda.io/projects/conda/en/latest/user-guide/install/index.html)
gcc, g++, make


## Folder structure
src/: 
This folder contains all C/C(++)-programs to count functional groups from a molecule. 

bin/: 
This folder contains all executable files

scripts/: 
This folder contains all scripts which call all the executable files from bin folder to count the functional groups of a molecule

example/: 
This folder contains a few example input files (molecule.smi and test.pdb), and results of test run can be found at descriptors.txt file 

config/: 
In this folder a script file, init.sh, resides. It is required to source the root of the cloned repository (e.g.; programme) and path to your conda installation eg, /home/<user name>/miniconda3

## How to install:

Step 1: Copy FGCount.git folder to your account

Step 2: Install miniconda

Step 3: conda env create -f fgcount.yml

Step 4: Edit the init file which is located inside the "config/" folder

Step 5: Compile all the C-code which is there inside the src/ folder
	
	cd src
	
	make

	(Ignore messages)

Step 6: Run the script anywhere except inside the bin/, config/, scripts/ and src/ folder

How to run the script:

bash script.sh Filename

e.g.;

if you have a SMILES code of an organic ligand molecule (asp) and the file name is asp.smi then, run the following command without .smi extention

bash script.sh asp

Output file: 

	Descriptors_Final.txt <---This file contains counting of functional groups in a given molecule as SMILES string
	
	FG_Binary.txt <---This file contains occurance of functional groups (binary file line a fingerprint) in a molecule

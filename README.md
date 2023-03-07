##Requirements

unix system (tested on Ubuntu 18.04 LTS and PharmCADD server)
bash shell to run the CLI scripts
conda for RDKIT (https://conda.io/projects/conda/en/latest/user-guide/install/index.html)
gcc, g++, make


## Folder structure
**src/:** 
This folder contains all C/C(++)-programs to count functional groups from a molecule. 

**bin/:** 
This folder is empty, but will contains executable files (*.exe) after running "make" command inside the src/ folder

**scripts/:** 
This folder contains all scripts which call all the executable files from the bin folder to count the functional groups in a molecule. The main script file is script.sh

**config/:** 
In this folder a script file, init.sh, resides. It is required to source the root of the cloned repository (e.g.; /home/<*user name*>/FGCount) and path to your conda installation eg, /home/<*user name*>/miniconda3

**example/:** 
This folder contains an example input file (asp.smi) and a script.sh file 

## How to install:

Step 1: Copy FGCount.git folder to your account

Step 2: Install miniconda (https://docs.conda.io/en/latest/miniconda.html)

Step 3: create a conda environment as 

	cd FGCount/
	
	conda env create -f fgcount.yml

Step 4: Edit the init file which is located inside the "config/" folder and source the file as
	
	source config/init.sh

Step 5: Compile all the C/C++-codes which are there inside the src/ folder
	
	cd src
	
	make

	(Ignore messages)

Step 6: Run the script anywhere except inside the bin/, config/, scripts/ and src/ folder


## How to run the script:

If you have a SMILES code of an organic ligand molecule and the file name is asp.smi then, run the following command without .smi extention

	cd example
	
	bash script.sh asp

Output file: 

	• Descriptors_Final.txt: In this file, counting of functional groups is there in a column (semicolon seperated) for a query SMILES string
	
	• FG_Binary.txt: In this file, occurance of functional groups (binary file line a fingerprint) is there for the same query


## A description of 517 FGSFs can be found in Supporting Information (SI) Table S5 of the following link:
	https://ndownloader.figstatic.com/files/39506852

	https://pubs.acs.org/doi/10.1021/acs.jcim.3c00050

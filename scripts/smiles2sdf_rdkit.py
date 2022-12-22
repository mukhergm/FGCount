#>  Copyright (c) 2022
#>  PharmCADD  (https://pharmcadd.com/)
#>  12F, 331, Jungang-daero, Dong-gu, Busan, Republic of Korea
#>  Author of this script: Goutam Mukherjee
##python smiles2sdf_rdkit.py molecule.smi molecule.sdf

from __future__ import print_function
import argparse
from rdkit import Chem
from rdkit.Chem import AllChem, Draw
import rdkit



parser = argparse.ArgumentParser()
parser.add_argument("-t", "--target", required=True, type=str, help="Path to file with smiles of ligands")
parser.add_argument("-o", "--output", required=True, type=str, help="Path to output file")
args = parser.parse_args()

with open(args.target, "r") as target_file, open(args.output, 'w') as outfile: #, open(args.query, 'r') as query_file:
    for ln, line in enumerate(target_file):
        smile = line.split("\t")[0]
        try:
            #read_smile = Chem.MolFromSmiles(smile)
            cannon_smile = Chem.CanonSmiles(smile)
            read_smile = Chem.MolFromSmiles(cannon_smile)
            m3 = Chem.AddHs(read_smile)
            mol = AllChem.EmbedMolecule(m3, randomSeed=0xf00d)

            bits = Chem.MolToMolBlock(m3)
        except:
            print("invalid smile or failure during canonicalization in line {}".format(ln + 1))
            out = "error"
        finally:
            outfile.write("{}\n".format(bits))
            #Draw.MolToFile(read_smile, "test_{}.png".format(ln)) ##For save image of the query molecule

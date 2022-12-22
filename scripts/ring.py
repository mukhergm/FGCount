#>  Author of this script: Goutam Mukherjee
#>  How to run this script:
#> conda activate raspdml
#> python ring.py pdb test.txt; here pdb is a folder name where a single pdbfile is present and text.txt is a output file name.
#> cat test.txt | awk '{print($NF)}' | sed 's/_/ /g' | awk '{for(i=1; i<=NF; i++) {print $i}}' >tmp1
#> sed 's:),:);:g' test.txt | sed 's:, :-:g' | awk '{for(i=2; i<=NF-2; i++) {print $i}}' | sed 's:(: :g'  | sed 's:): :g' | sed 's/;//g' | sed 's/-/ /g' >tmp2
#> paste tmp1 tmp2 >ring_info

from rdkit import Chem
import sys
import pandas as pd
import os

def main():
    file_out = open(sys.argv[2], "w")

    # Read input file with all sequences
    pdb_file = sys.argv[1]
    for pdb in os.listdir(pdb_file):
        mol=Chem.MolFromPDBFile(os.path.join(pdb_file, pdb))
        ri = mol.GetRingInfo()
        rings = ri.AtomRings()

        pdb_id = pdb.split('.')[0]
        lengths = [str(len(ring)) for ring in rings]
        lengths = '_'.join(lengths)
        file_out.write(f'{pdb_id} \t {rings} \t {len(rings)} \t {lengths}\n')

    file_out.close()

if __name__ == '__main__':

    main()

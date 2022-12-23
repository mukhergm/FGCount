#>  Copyright (c) 2022
#>  PharmCADD  (https://pharmcadd.com/)
#>  12F, 331, Jungang-daero, Dong-gu, Busan, Republic of Korea
#>  Author of this script: Goutam Mukherjee
#>  How to run this script:
#>  bash script.sh <filename>
#>  e.g.; 
#>  bash script.sh asp (without .smi extension)
#>  Note, SMILES code is given as an input for the script

export scripts_path=$root_dir/scripts
export path=$root_dir/bin
eval "$($conda_root/condabin/conda shell.bash hook)"
line=$1

if [ -z "$root_dir" ]
then
        echo -e '\033[7mPlease set path of the Functional_Group calculation repository, miniconda to config/init.sh file and source it\033[0m'
        echo -e '\033[7msource config/init.sh\033[0m'
        echo " "

        else if [ -z $line".smi" ]
        then
        echo -e '\033[7mNo input ligand file ID is provided. Input file extension should be ".smi"\033[0m'
              else if [ ! -f $line".smi" ]
              then
              echo -e '\033[1mInput ligand do not exist at the present working directory.\033[0m'
              echo -e '\033[1mPlease provide a valid input ligand-id without a ".smi" extension\033[0m'
                        else
                                echo "Calculation start"

			rm metal_prop.txt
			awk -F \. '{for(i=1;i<=NF;i++) print $i}' $line".smi" >test.smi
			var=`awk -F \. '{for(i=1;i<=NF;i++) print $i}' $line".smi" | wc -l | awk '{print($1)}'`
			one=1;
			if [ $var -eq $one ];
			then
				awk -F \. '{for(i=1;i<=NF;i++) print $i}' $line".smi" >test.smi
				conda activate fgcount
				python $scripts_path/smiles2sdf_rdkit.py -t test.smi -o test.sdf
				babel -isdf test.sdf -opdb test.pdb
				$path/pdbtopdb.exe test.pdb test1.pdb
				varx=`egrep "ATOM" test1.pdb | awk '{print($6)}' | sort -n | uniq | wc -l`
				vary=`egrep "ATOM" test1.pdb | awk '{print($7)}' | sort -n | uniq | wc -l`
				varz=`egrep "ATOM" test1.pdb | awk '{print($8)}' | sort -n | uniq | wc -l`
				if [[ ( $varx -eq 1 ) || ( $vary -eq 1 ) || ( $varz -eq 1 )]]
				then
					echo "Wrong RDkit SDF Conversion"
					babel -isdf test.sdf -opdb test.pdb --gen3d
				fi
				check=`egrep "ATOM|HETATM" $lne".pdb" | wc -l`
				one=1;
				if [ $check -eq $one ];
				then
					$path/weight_calc.exe $lne".pdb" >property.txt
					rm metal_prop.txt
					for i in {1..517}
					do
			        		echo "0" >>metal_prop.txt
					done
					cat property.txt >>metal_prop.txt
					awk '{printf($1";")}' metal_prop.txt >$line"_descriptors.txt"
				else
					bash $scripts_path/fg_calc.sh test
					mv descriptors.txt $line"_descriptors.txt"
				fi
			else	
				rm metal_prop.txt largefile
				awk -F \. '{for(i=1;i<=NF;i++) print $i}' $line".smi" >test1.smi
				#/home/mukhergm/test/multiple_smiles/2/ChemIDPlus/FG/new/smiles_edit.exe test1.smi >test.smi
				$path/smiles_edit.exe test1.smi >test.smi
				seq 1 `wc -l test.smi | awk '{print($1)}'` >list_tmp
				for i in {1..517}
				do
			        	echo "0" >>metal_prop.txt
				done

				exec 3<list_tmp
				while read -r lne <&3
				do
					sed -n `echo $lne`p test.smi >test_aa.smi
					python $scripts_path/smiles2sdf_rdkit.py -t test_aa.smi -o $lne".sdf"
					babel -isdf $lne".sdf" -opdb $lne".pdb"
					check=`egrep "ATOM|HETATM" $lne".pdb" | wc -l`
					one=1;
				if [ $check -eq $one ];
				then
					$path/weight_calc.exe $lne".pdb" >property.txt
					cat metal_prop.txt >metal_prop1.txt
					cat property.txt >>metal_prop1.txt
					mv metal_prop1.txt $lne"_descriptors_final.txt"
				else
					bash $scripts_path/fg_calc.sh $lne
					awk -F \; '{for(i=1;i<=NF;i++) print $i}' descriptors.txt >$lne"_descriptors_final.txt"
				fi
				echo -n $lne"_descriptors_final.txt " >>largefile
				cp largefile largefile.bk
				awk '{print("paste " $0 " >largefile")}' largefile >paste.sh
				done
				bash paste.sh
				check_again=`egrep "Problem in the coordinates" largefile | wc -l | awk '{print($1)}'`
				if [ $check_again -eq 0 ];
				then
					awk '{for(i=1;i<=NF;i++) t+=$i; print t; t=0}' largefile | awk '{printf($1";")}' | awk '{print($1)}' >>$line"_descriptors.txt"
				else
					echo "Problem in the coordinates" >$line"_descriptors.txt"
				fi
			fi
			cat $line"_descriptors.txt" >>Descriptors_Final.txt
			awk -F \; '{for(i=1;i<=NF;i++) print $i}' Descriptors_Final.txt | sed -n 1,517p | awk '{if($1 != 0) print 1; else print 0}' | awk '{printf($1)}' | awk '{print($1)}' >>FG_Binary.txt
			conda deactivate
			
			rm arrangeline $line"_descriptors.txt" bondorder* kk LOGP LPMR1 lst Molecular_Weight MR new_bo output.log physicochemical_descriptors ring_info ring.txt RR temp.con test* tmp*
		fi
	fi	
fi

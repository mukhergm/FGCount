#>  Copyright (c) 2022
#>  PharmCADD  (https://pharmcadd.com/)
#>  12F, 331, Jungang-daero, Dong-gu, Busan, Republic of Korea
#>  Author of this script: Goutam Mukherjee
#>  How to run this script:
#>  bash fg_calc.sh <filename>
#>  e.g.; 
#>  bash fg_calc.sh molecule (without .pdb extension)
#>  Here, molecule is the pdb file name of a molecule

date
rm kk bondorder_sdf bondorder_ConnectMol_sdf new_bo bondorder_ConnectMol tmpfile lst tmpfile tmp.pdb tmp.con RR bondorder_mol2_sort_sort

if [ -z "$root_dir" ]
then
	echo -e '\033[1mPlease set path of the Functional_Group calculation repository, miniconda to config/init.sh file and source it\033[0m'
        echo -e '\033[1m   source <config/init.sh\033[0m'
        echo " "
fi
export path=$root_dir/bin
export scripts_path=$root_dir/scripts

line=$1
eval "$($conda_root/condabin/conda shell.bash hook)"
conda activate fgcount
$path/pdbtopdb.exe $line".pdb" tmp.pdb
$path/Connect2.0.exe tmp.pdb tmp.con 1 >RR
$path/pdbarrange.exe tmp.pdb arrangeline >$line"MD.pdb"
$path/pdbtopdb.exe $line"MD.pdb" $line"_M.pdb"
$path/mass.exe $line"_M.pdb" >Molecular_Weight
$path/Connect2.0.exe $line"_M.pdb" $line"New.pdb" 1 > RR
$path/Connect2.0.exe $line"_M.pdb" $line"New1.pdb" 0 > RR
sed -i 's/000   0  0  0/001   0  0  0/g' $line"New.pdb"

$path/lp1.exe $line"_M.pdb" $line".aa"
$path/lp2.exe $line"New.pdb" $line".aa" $line".bb"
$path/lp3.exe $line"New.pdb" $line".cc"
/usr/bin/perl $scripts_path/lp4.pl $line"New1.pdb" >bondorder
$path/logp_mr_calc_5.exe bondorder $line".bb" $line".cc" $line".dd"
$path/logp_mr_calc_6.exe $line".dd" $line".cc" $line".ee"
$path/logp_mr_calc_7.exe $line".ee" LPMR1 >RR
$path/logp_mr_calc_8.exe LPMR1 LOGP MR
paste Molecular_Weight LOGP MR >physicochemical_descriptors 
babel -ipdb $line".pdb" -osdf -O $line".sdf"
babel -ipdb $line".pdb" -osmi -O tmp.smi
babel -ipdb $line".pdb" -omol2 -O $line".mol2"

############################################CHECH BOND ORDER#######################################################
$path/bond_order_sdf.exe $line".sdf" | sort -k2n >tmpfile
seq 1 `egrep "V2000" $line".sdf" | awk '{print($1)}' | cut -c1-3` >lst
exec 3<lst
while read -r lne <&3
        do
                awk '{if($1 == '$lne') print $0}' tmpfile >>bondorder_sdf
        done

$path/bond_order_CM.exe tmp.con >bondorder_ConnectMol

sz1=`wc -l bondorder_sdf | awk '{print($1)}'`
sz2=`wc -l bondorder_ConnectMol | awk '{print($1)}'`
if [ $sz1 -eq $sz2 ]
	then
		paste bondorder_ConnectMol bondorder_sdf >bondorder_ConnectMol_sdf
		$path/bond_order_calc.exe tmp.pdb bondorder_ConnectMol_sdf >new_bo
		$path/grep.exe tmp.con >tmp
		paste bondorder_ConnectMol_sdf new_bo >tmp1
		$path/bond_order_correct.exe tmp1 >>tmp
		mv tmp tmp.con

		$path/grep.exe tmp.con >temp
		$path/bond_order_correct_sdf.exe tmp1 >>temp
		mv temp temp.con
	else
		echo "Considering RDKit"
		$path/bond_order_mol2.exe $line".mol2" >bondorder_mol2
		sed -i 's/ar/ 4/g' bondorder_mol2
		sed -i 's/am/ 1/g' bondorder_mol2
		sed -i 's/du/ 0/g' bondorder_mol2
		sed -i 's/un/ 0/g' bondorder_mol2
		sed -i 's/nc/ 0/g' bondorder_mol2
		sort -k2n bondorder_mol2 >bondorder_mol2_sort
		exec 3<lst
		while read -r lne <&3
			do
				awk '{if($1 == '$lne') print $0}' bondorder_mol2_sort >>bondorder_mol2_sort_sort
			done
		$path/grep.exe tmp.con >tmp
		$path/bond_order_correct_mol2.exe bondorder_mol2_sort_sort >>tmp
		mv tmp tmp.con

		$path/grep.exe tmp.con >temp
		$path/bond_order_correct_sdf.exe bondorder_sdf >>temp
		mv temp temp.con
	fi
###################################################################################################################
	rm -rf pdb
	mkdir pdb
	cp $line".pdb" pdb/
	conda activate fgcount
	python $scripts_path/ring.py pdb ring.txt
	cat ring.txt | awk '{print($NF)}' | sed 's/_/ /g' | awk '{for(i=1; i<=NF; i++) {print $i}}' >tmp1
	sed 's:),:);:g' ring.txt | sed 's:, :-:g' | awk '{for(i=2; i<=NF-2; i++) {print $i}}' | sed 's:(: :g'  | sed 's:): :g' | sed 's/;//g' | sed 's/-/ /g' >tmp2
	paste tmp1 tmp2 >ring_info
	$path/ring.exe ring_info | sort -n >$line".ring"
	rm -rf pdb
	conda deactivate
	cp tmp.con $line".pdb"
	$path/lp1.exe $line".pdb" $line".aa"
	$path/lp2.exe $line".pdb" $line".aa" $line".bb"
	$path/lp2.exe temp.con $line".aa" $line".b"
	
	sz=`wc -l $line".ring" | awk '{print($1)}'`
	if [ $sz -ne 0 ]
		then
		$path/ring_edit.exe $line".bb" $line".ring" >$line".cc"
		$path/lp3.exe $line".pdb" $line".dd"
		$path/correct_aromatic_double_bond.exe $line".cc" $line".dd" $line".ccc"
		$path/correct_cn_bondorder.exe $line".ccc" $line".dd" $line"_edit.cc"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit.cc" $line".dd" $line"_edit1.cc"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit1.cc" $line".dd" $line"_edit2.cc"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit2.cc" $line".dd" $line"_edit3.cc"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit3.cc" $line".dd" $line"_edit4.cc"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit4.cc" $line".dd" $line"_edit5.cc"
		$path/lp4.exe $line"_edit5.cc" $line".dd" $line".ee"
		$path/lp5.exe $line".ee" >$line".ff"
		$path/lp6.exe $line".ff" $line".dd" $line".gg"
		$path/lp7.exe $line".gg" >$line".hh"
		$path/lp8.exe $line".hh" >kk

		$path/ring_edit.exe $line".b" $line".ring" >$line".c"
		$path/lp44.exe $line".c" $line".dd" $line".e"
		$path/lp55.exe $line".e" $line".dd" $line".f"
		paste $line".f" $line".hh" >$line".fh"
		$path/check_fc_imidazole.exe $line".fh" >>kk
		$path/lp9.exe $line".ring" >>kk
	else
		$path/lp3.exe $line".pdb" $line".dd"
		$path/correct_cn_bondorder.exe $line".bb" $line".dd" $line"_edit.bb"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit.bb" $line".dd" $line"_edit1.bb"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit1.bb" $line".dd" $line"_edit2.bb"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit2.bb" $line".dd" $line"_edit3.bb"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit3.bb" $line".dd" $line"_edit4.bb"
		$path/correct_cc_aromatic_bondorder.exe $line"_edit4.bb" $line".dd" $line"_edit5.bb"
		$path/lp4.exe $line"_edit5.bb" $line".dd" $line".ee"
		$path/lp5.exe $line".ee" >$line".ff"
		$path/lp6.exe $line".ff" $line".dd" $line".gg"
		$path/lp7.exe $line".gg" >$line".hh"
		$path/lp8.exe $line".hh" >kk
		
		$path/lp44.exe $line".b" $line".dd" $line".e"
		$path/lp55.exe $line".e" $line".dd" $line".f"
		paste $line".f" $line".hh" >$line".fh"
		$path/check_fc_imidazole.exe $line".fh" >>kk
		$path/lp9.exe $line".ring" >>kk
	fi
	
	check=`$path/value_non_zero.exe physicochemical_descriptors`
	zero=0;
	if [ $check -ne $zero ];
	then
		awk '{printf($4";")}' kk | awk '{print($1)}' | sed '$ s/.$//' >descriptors.txt
	else
		echo "Problem in the coordinates\n" >descriptors.txt
	fi
	conda deactivate

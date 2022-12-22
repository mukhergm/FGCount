

BIN=pdbtopdb bond_order_sdf bond_order_CM bond_order_calc bond_order_correct grep bond_order_correct_sdf bond_order_mol2 bond_order_correct_mol2 ring lp1 lp2 lp3 lp4 lp5 lp6 lp7 lp8 lp9 ring_edit lp44 check_fc_imidazole logp_mr_calc_5 logp_mr_calc_6 logp_mr_calc_7 logp_mr_calc_8 mass pdbarrange value_non_zero line_number pdb2pdb correct_cn_bondorder correct_cc_aromatic_bondorder lp55 correct_aromatic_double_bond smiles_edit

all: $(BIN) connectmol

#mkdir -p ../bin/

connectmol: 
	cd CONNECTMOLv2_t2 && $(MAKE) 
	cp CONNECTMOLv2_t2/Connect2.0.exe ../bin/	

pdbtopdb: pdbtopdb.c
	g++ pdbtopdb.c -o ../bin/pdbtopdb.exe

bond_order_sdf: bond_order_sdf.c
	g++ bond_order_sdf.c -o ../bin/bond_order_sdf.exe

bond_order_CM: bond_order_CM.c
	g++ bond_order_CM.c -o ../bin/bond_order_CM.exe

bond_order_calc: bond_order_calc.c
	g++ bond_order_calc.c -o ../bin/bond_order_calc.exe

bond_order_correct:bond_order_correct.c
	g++ bond_order_correct.c -o ../bin/bond_order_correct.exe

grep: grep.c
	g++ grep.c -o ../bin/grep.exe

bond_order_correct_sdf: bond_order_correct_sdf.c
	g++ bond_order_correct_sdf.c -o ../bin/bond_order_correct_sdf.exe

bond_order_mol2: bond_order_mol2.c
	g++ bond_order_mol2.c -o ../bin/bond_order_mol2.exe

bond_order_correct_mol2: bond_order_correct_mol2.c
	g++ bond_order_correct_mol2.c -o ../bin/bond_order_correct_mol2.exe

ring: ring.c
	g++ ring.c -o ../bin/ring.exe

lp1: lp1.c
	g++ lp1.c -o ../bin/lp1.exe

lp2: lp2.c
	g++ lp2.c -o ../bin/lp2.exe

lp3: lp3.c
	g++ lp3.c -o ../bin/lp3.exe

lp4: lp4.c
	g++ lp4.c -o ../bin/lp4.exe

lp5: lp5.c
	g++ lp5.c -o ../bin/lp5.exe

lp6: lp6.c
	g++ lp6.c -o ../bin/lp6.exe

lp7: lp7.c
	g++ lp7.c -o ../bin/lp7.exe

lp8: lp8.c
	g++ lp8.c -o ../bin/lp8.exe

lp9: lp9.c
	g++ lp9.c -o ../bin/lp9.exe

ring_edit: ring_edit.c
	g++ ring_edit.c -o ../bin/ring_edit.exe

lp44: lp44.c
	g++ lp44.c -o ../bin/lp44.exe

check_fc_imidazole: check_fc_imidazole.c
	g++ check_fc_imidazole.c -o ../bin/check_fc_imidazole.exe

logp_mr_calc_5: logp_mr_calc_5.c
	g++ logp_mr_calc_5.c -o ../bin/logp_mr_calc_5.exe

logp_mr_calc_6: logp_mr_calc_6.c
	g++ logp_mr_calc_6.c -o ../bin/logp_mr_calc_6.exe

logp_mr_calc_7: logp_mr_calc_7.c
	g++ logp_mr_calc_7.c -o ../bin/logp_mr_calc_7.exe

logp_mr_calc_8: logp_mr_calc_8.c
	g++ logp_mr_calc_8.c -o ../bin/logp_mr_calc_8.exe

mass: mass.c
	g++ mass.c -o ../bin/mass.exe

pdbarrange: pdbarrange.c
	g++ pdbarrange.c -o ../bin/pdbarrange.exe

value_non_zero: value_non_zero.c
	g++ value_non_zero.c -o ../bin/value_non_zero.exe

line_number: line_number.c
	g++ line_number.c -o ../bin/line_number.exe

pdb2pdb: pdb2pdb.c
	g++ pdb2pdb.c -o ../bin/pdb2pdb.exe

correct_cn_bondorder: correct_cn_bondorder.c
	g++ correct_cn_bondorder.c -o ../bin/correct_cn_bondorder.exe

correct_cc_aromatic_bondorder: correct_cc_aromatic_bondorder.c
	g++ correct_cc_aromatic_bondorder.c -o ../bin/correct_cc_aromatic_bondorder.exe

lp55: lp55.c
	g++ lp55.c -o ../bin/lp55.exe

correct_aromatic_double_bond: correct_aromatic_double_bond.c
	g++ correct_aromatic_double_bond.c -o ../bin/correct_aromatic_double_bond.exe

smiles_edit: smiles_edit.c
	g++ smiles_edit.c -o ../bin/smiles_edit.exe

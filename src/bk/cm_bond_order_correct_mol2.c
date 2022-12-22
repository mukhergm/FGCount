/*
 * Written by Goutam Mukherjee
 * Purpose: If there is a difference between bond order of C-C, C-N, C-H, N-H, O-H and S-H bonds as printed by CONNECTMOL and babel programmes, then this programme printed the bond order as per output of bond_order_calc.exe programme. This programme assign aromatic bond order as 4.
 * How to run:
 * g++ bond_order_correct.c -o bond_order_correct.exe
 * ./bond_order_correct.exe <A concatenate bond order printed by bond_order_CM.exe, bond_order_sdf.exe and bond_order_calc.exe programmes>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct cyp {    // ligand1
        float x,y,z;
        int r, atomno;
        char  atomname[5];
        char resname[4];

}L;
typedef struct arm {  // Aromatic ring position
        int pos,sz;

}K;
int main(int argc, char *argv[])
	{
	FILE *fp,*fr;
	if (argc<2) 
	  {
          printf("./bond_order_correct_mol2.exe               				<Input file>\n");
	  printf("./bond_order_correct_mol2.exe <A concatenate bond order printed by bond_order_CM.exe, bond_order_sdf.exe and bond_order_calc.exe programmes>\n");
	  exit(1);
	  }

	struct format
		{
		int a=0;
		int b=0;
		int c=0;
		int d=0;
		int e=0;
		int f=0;
		int g=0;
		};
		struct format f;
	char str[100], s[100];
	L L1 [20000];
	K L2 [20000];
	fr=fopen(argv[1],"r");
	
	int line=0;
	while (fgets (s, 100, fr)!=NULL)
	{
			sscanf(s,"%d %d %d %d %d %d", &f.a, &f.b, &f.c, &f.d, &f.e, &f.f);
			if(f.a==f.d && f.b==f.e && f.c==4 && f.f!=4)
				printf("%03u%03u%03u   0  0  0\n", f.a, f.b, f.c);
				//printf("%4d %4d %4d\n", f.a, f.b, f.g);
			else if(f.a==f.d && f.b==f.e && f.c!=4 && f.f==4)
				printf("%03u%03u%03u   0  0  0\n", f.a, f.b, f.f);
                                //printf("%4d %4d %4d\n", f.b, f.a, f.f);
			else
                                printf("%03u%03u%03u   0  0  0\n", f.a, f.b, f.c);
	}
fclose(fr);
	}

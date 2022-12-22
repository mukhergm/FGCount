/*
 * Written by Goutam Mukherjee
 * Purpose: This programe print the bond order present in a sdf file as per CONNECTMOL prited bond order format. Although as an input it takes a concatenate bond order printed by bond_order_CM.exe, bond_order_sdf.exe and bond_order_calc.exe programmes, instead of sdf file. The output of this programme is later used by lp2.exe
 * How to run:
 * g++ bond_order_correct_sdf.c -o bond_order_correct_sdf.exe
 * ./bond_order_correct_sdf.exe <A concatenate bond order printed by bond_order_CM.exe, bond_order_sdf.exe and bond_order_calc.exe programmes>
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
	  printf("./bond_order_correct_sdf.exe                                         <Input file>\n");
          printf("./bond_order_correct_sdf.exe <A concatenate bond order printed by bond_order_CM.exe, bond_order_sdf.exe and bond_order_calc.exe programmes>\n");
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
		if(strlen(s)<20)
		{
			sscanf(s,"%d %d %d", &f.a, &f.b, &f.c);
                        printf("%03u%03u%03u   0  0  0\n", f.a, f.b, f.c);
			/*sscanf(s,"%d %d %d %d %d %d %d", &f.a, &f.b, &f.c, &f.d, &f.e, &f.f, &f.g);
			if(f.d<f.e)
				printf("%03u%03u%03u   0  0  0\n", f.d, f.e, f.f);
			if(f.d>f.e)
				printf("%03u%03u%03u   0  0  0\n", f.e, f.d, f.f);*/
		}
		else
			sscanf(s,"%d %d %d %d %d %d %d", &f.a, &f.b, &f.c, &f.d, &f.e, &f.f, &f.g);
                        if(f.d<f.e)
                                printf("%03u%03u%03u   0  0  0\n", f.d, f.e, f.f);
                        if(f.d>f.e)
                                printf("%03u%03u%03u   0  0  0\n", f.e, f.d, f.f);
		
	}
fclose(fr);
	}



/*
 * Written by Goutam Mukherjee
 * Purpose: Print bond order between atoms from a mol2 file of a molecule to ConnectMol format.
 * How to run:
 * g++ bond_order_mol2_4noCM.c -o bond_order_mol2_4noCM.exe
 * ./bond_order_mol2_4noCM.exe <Input sdf file>
 * e.g.;
 * ./bond_order_mol2_4noCM.exe test.mol2
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
	FILE *fp,*fr, *fw;
	if (argc<2) 
	  {
          printf("                      	<Input file>      >Output file\n");
	  printf("./bond_order_mol2_4noCM.exe <filename.mol2>\n");
	  exit(1);
	  }

	struct format
		{
		int a=0;
		int b=0;
		int c=0;
		int d=0;
		};
		struct format f;
		char st1[3], st2[3], st3[3];
	char str[100], s[100];
	L L1 [20000];
	K L2 [20000];
	fr=fopen(argv[1],"r");

	int line=1;
	while (fgets (s, 100, fr)!=NULL)
	{
		if(strlen(s)<25 && strlen(s)>20)
			{
				sscanf(s,"%d %d %d %d", &f.a, &f.b, &f.c, &f.d);
				printf("%03u%03u%03u   0  0  0\n", f.b, f.c, f.d);
			}
	}
fclose(fr);
	}

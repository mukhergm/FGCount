/*
 * Written by Goutam Mukherjee
 * Purpose: Print bond order between atoms in a molecule from mol2 format to CONNECTMOL bond order format
 * How to run:
 * g++ bond_order_correct_mol2.c -o bond_order_correct_mol2.exe
 * ./bond_order_correct_mol2 <Input bond order file obtained from mol2 format>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
/*typedef struct cyp {    // ligand1
        float x,y,z;
        int r, atomno;
        char  atomname[5];
        char resname[4];

}L;
typedef struct arm {  // Aromatic ring position
        int pos,sz;

}K;*/
int main(int argc, char *argv[])
	{
	FILE *fp,*fr;
	if (argc<2) 
	  {
          printf("                               		  <Input file>     			 >Output file\n");
	  printf("./bond_order_correct_mol2.exe <Input bond order file obtained from mol2 format>\n");
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
	//L L1 [20000];
	//K L2 [20000];
	fr=fopen(argv[1],"r");
	
	int line=0;
	while (fgets (s, 100, fr)!=NULL)
	{
			sscanf(s,"%d %d %d", &f.a, &f.b, &f.c);
			if(f.a<f.b)
				printf("%03u%03u%03u   0  0  0\n", f.a, f.b, f.c);
			if(f.a>f.b)
				printf("%03u%03u%03u   0  0  0\n", f.b, f.a, f.c);
	}
fclose(fr);
	}



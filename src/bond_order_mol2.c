/*
 * Written by Goutam Mukherjee
 * Purpose: Print bond order between atoms in a molecule from a mol2 file as printed by babel programme.
 * How to run:
 * g++ bond_order_mol2.c -o bond_order_mol2.exe
 * ./bond_order_mol2.exe <Input mol2 file>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
/*typedef struct cyp {    // ligand1
        float x,y,z;
        int r, atomno;
        char  atomname[5];
        char resname[4];

}L;
typedef struct arm {  
        int pos,sz;

}K;*/
int main(int argc, char *argv[])
	{
	FILE *fp,*fr, *fw;
	if (argc<2) 
	  {
          printf("                         <Input file>     >Output file\n");
	  printf("./bond_order_mol2.exe <filename.mol2>\n");
	  exit(1);
	  }

	struct format
		{
		int a=0;
		int b=0;
		int c=0;
		char d[2];
		};
		struct format f;
	char str[100], s[100];
	//L L1 [20000];
	//K L2 [20000];
	fr=fopen(argv[1],"r");

	int line=0;
	while (fgets (s, 100, fr)!=NULL)
	{
		if(strlen(s)<25 && strlen(s)>20)
			{
				sscanf(s,"%d %d %d %s", &f.a, &f.b, &f.c, f.d);
				if(f.b<f.c)
					printf("%4d %4d %4s\n", f.b, f.c, f.d);
				if(f.b>f.c)
                                	printf("%4d %4d %4s\n", f.c, f.b, f.d);
			}
	}
fclose(fr);
	}


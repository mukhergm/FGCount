/*
 * Written by Goutam Mukherjee
 * Purpose: Print bond order between atoms from a sdf file of a molecule.
 * How to run:
 * g++ bond_order_sdf.c -o bond_order_sdf.exe
 * ./bond_order_sdf.exe <Input sdf file>
 * e.g.;
 * ./a.out test.sdf
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
          printf("                      <Input file>      >Output file\n");
	  printf("./bond_order_sdf.exe <filename.sdf>\n");
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

	int line=0;
	while (fgets (s, 100, fr)!=NULL)
	{
		if(strlen(s)<25 && strlen(s)>20)
			{
                                st1[0]=s[0];
                                st1[1]=s[1];
                                st1[2]=s[2];
                                st1[3]='\0';
                                f.a=atoi(st1);

                                st2[0]=s[3];
                                st2[1]=s[4];
                                st2[2]=s[5];
                                st2[3]='\0';
                                f.b=atoi(st2);

                                st3[0]=s[6];
                                st3[1]=s[7];
                                st3[2]=s[8];
                                st3[3]='\0';
                                f.c=atoi(st3);

				sscanf(s,"%d %d %d %d", &f.a, &f.b, &f.c, &f.d);
				if(f.a<f.b)
					printf("%4d %4d %4d\n", f.a, f.b, f.c);
				if(f.a>f.b)
                                	printf("%4d %4d %4d\n", f.b, f.a, f.c);
			}
		if(strstr(s,"M  END") || strstr(s,"M  CHG"))
			break;
	}
fclose(fr);
	}


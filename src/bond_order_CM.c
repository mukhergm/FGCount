/*
 * Written by Goutam Mukherjee
 * Purpose: Print aromatic atom bond order between atoms in a molecule which is the output of CONNECTMOL programme
 * How to run:
 * g++ bond_order_CM.c -o bond_order_CM.exe
 * ./bond_order_CM.exe <Output of CONNECTMOL programme>
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
typedef struct arm {  
        int pos,sz;

}K;*/
int main(int argc, char *argv[])
	{
	FILE *fp,*fr;
	char st1[4], st2[4], st3[4], st4[4];
	int a=0, b=0, c=0, d=0;
	if (argc<2) 
	  {
          printf("                      <Input file>    >Output file\n");
	  printf("./bond_order_CM.exe <filename>\n");
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
	char str[100], s[100];
	//L L1 [20000];
	//K L2 [20000];
	fr=fopen(argv[1],"r");
	
	int line=0;
	while (fgets (s, 100, fr)!=NULL)
	{
		if(strstr(s,"   0  0  0"))
			{
				st1[0]=s[0];
				st1[1]=s[1];
				st1[2]=s[2];
				st1[3]='\0';
				a=atoi(st1);

				st2[0]=s[3];
                                st2[1]=s[4];
                                st2[2]=s[5];
				st2[3]='\0';
				b=atoi(st2);

				st3[0]=s[6];
                                st3[1]=s[7];
                                st3[2]=s[8];
                                st3[3]='\0';
				c=atoi(st3);

				printf("%4d %4d %4d\n", a, b, c);
			}
	}
fclose(fr);
	}



/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 *Purpose: Print atom symbol of atoms present in a ligand (non-standard) molecule.
 * How to run:
 * ./lp1.exe <ligand name with extension (.pdb)> <output file>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;

int main(int argc, char *argv[])
{
FILE *fp,*fw;
struct format
{
  char atom[6],atmsmb[3],resid[4];
  int atomno,resno,k;
  float x,y,z;
};
struct format f;

char s[500];

if (argc<2) {
  printf("./lp1.exe <ligand name with extension (.pdb)> <output file>\n");
  exit(1);
}

fp=fopen(argv[1],"r");
fw=fopen(argv[2],"w");


if (fw==NULL) 
	{
  	printf("lp1.exe: Cannot write output. No output file name is given\n");
  	exit(1);
	}


while(fgets(s,500,fp)!=NULL)
	{
	if(strncmp("ATOM",s,4)==0||strncmp("HETATM",s,6)==0)
		{
			sscanf(s,"%s%d%s%s%d%f%f%f",f.atom, &f.atomno, f.atmsmb, f.resid, &f.resno, &f.x, &f.y, &f.z);
				if(strstr(f.atmsmb,"C") && strlen(f.atmsmb)==1)
					fprintf(fw, "C");
				else if(strstr(f.atmsmb,"H") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "H");
				else if(strstr(f.atmsmb,"N") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "N");
				else if(strstr(f.atmsmb,"O") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "O");
				else if(strstr(f.atmsmb,"P") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "P");
				else if(strstr(f.atmsmb,"S") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "S");
				else if(strstr(f.atmsmb,"F") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "F");
				else if(strstr(f.atmsmb,"I") && strlen(f.atmsmb)==1)
                                	fprintf(fw, "I");
				else if(strstr(f.atmsmb,"Cl") && strlen(f.atmsmb)==2)
                                	fprintf(fw, "l");
				else if(strstr(f.atmsmb,"Br") && strlen(f.atmsmb)==2)
                                	fprintf(fw, "B");
				else
					fprintf(fw, "V");
		}
	}
fclose(fp);
}


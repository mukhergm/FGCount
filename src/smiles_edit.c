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

char s[1000];
char str[1000];

if (argc<2) {
  printf("./lp1.exe <ligand name with extension (.pdb)> <output file>\n");
  exit(1);
}

fp=fopen(argv[1],"r");


if (fw==NULL)
        {
        printf("lp1.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }


while(fgets(s,1000,fp)!=NULL)
        {
		sscanf(s,"%s", str);
		if(strstr(str,"Cl") && strlen(str)==2)
			printf("[Cl-]\n");
		else if(strstr(str,"Br") && strlen(str)==2)
                        printf("[Br-]\n");
		else if(strstr(str,"F") && strlen(str)==1)
                        printf("[F-]\n");
		else if(strstr(str,"I") && strlen(str)==1)
                        printf("[I-]\n");
		else
			printf("%s\n", str);
	}
fclose(fp);
}


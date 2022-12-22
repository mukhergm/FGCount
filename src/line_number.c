/*
 * How to run:
 * g++ main.c
 * ./a.out <PDB-ID> 
 * say,
 * ./pdb2noh.exe test.pdb 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
	{
	FILE *fr, *fw;
	if (argc<3) {
  	printf("./line_number.exe <Input file> <Output file>\n");
  	exit(1);
	}
	char s[10000];
        int flag=0;
	int sum=0;
	int a[1000];
	int line=1;
	char s1[20];
  		
	char atom[6], atmsmb[6], resname[4];
  	int atomno=1, resno=1;
	float x=0, y=0, z=0;

		fr=fopen(argv[1],"r");
		fw=fopen(argv[2],"w");

		while(fgets(s, 10000, fr)!=NULL)
		{
		if(strstr(s,"MODEL"))
		{
			printf("sed -n %d,", line);
			fprintf(fw, "sed -n %dp\n", line);
		}
		if(strstr(s,"ENDMDL"))	
			printf("%dp\n", line);
		line=line+1;
		}
	fclose(fr);
	fclose(fw);
}

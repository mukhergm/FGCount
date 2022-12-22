/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 *Purpose: Print atom type of ligand (non-standard) molecule.
 * How to run:
 * ./lp2.exe <Output file of Connect2.0.exe> <Output of lp1.exe> <Output file name> 
 * Say, for Methane (CH4) molecule, this program will generate the following outout:
 * CH1CH1CH1CH1 (Carbon atom of methane)
 * HC1          (Hydrogen of methane)
 * HC1          (Hydrogen of methane)
 * HC1          (Hydrogen of methane)
 * HC1          (Hydrogen of methane)
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int main(int argc, char *argv[])
{
FILE *fp,*fr,*fw;

if (argc<3) {
  printf("	         <Input file-1>               <Input file-2>       <Output file>\n");
  printf("./lp2.exe <Output file of Connect2.0.exe> <Output of lp1.exe> <Output file name>\n");
  exit(1);
}

struct format
{
  char connectivity[10];
  int a,b,c;
};
struct format f;
int i,j,k,l,sum=0;
char s[100],str[1000],storeinf[1000][100],st[1000],str_array[1000][100],string[1000];
int g;
fw=fopen(argv[3],"w");
fp=fopen(argv[1],"r");
fr=fopen(argv[2],"r");

if (fw==NULL)            
        {
        printf("lp2.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }

int storeinfline=0;
        while(fgets(s,100,fp)!=NULL) 
		{
		if(strncmp(s,"0",1)==0||strncmp(s,"1",1)==0||strncmp(s,"2",1)==0||strncmp(s,"3",1)==0||strncmp(s,"4",1)==0||strncmp(s,"5",1)==0||strncmp(s,"6",1)==0||strncmp(s,"7",1)==0||strncmp(s,"8",1)==0||strncmp(s,"9",1)==0)
			{
			sscanf(s,"%s%d%d%d",f.connectivity,&f.a,&f.b,&f.c);
			strcpy(storeinf[storeinfline],f.connectivity);
			storeinfline++;
			}
		}

int line=0;
while(fgets(string,1000,fr)!=NULL)
	{ 
	strcpy(str_array[line],string); 
	line++; 
	}

for(g=1;g<=999;g++)
	{
	for(int myln=0;myln<line;myln++)
		{
		strcpy(str,str_array[myln]);
		for(int my=0;my<storeinfline;my++)
        		{
        		strcpy(st,storeinf[my]);

			int num;
			num=atoi(st);
			i=num/1000000;
			j=num%1000000;
			k=j%1000;
			l=j/1000;
			if(k==0)
			sum=sum+1;
			if(g==i)// && sum==0)
			fprintf(fw,"%c%c%d",str[g-1],str[l-1],k);
			if(g==l)// && sum==0)
			fprintf(fw,"%c%c%d",str[g-1],str[i-1],k);
			}
fprintf(fw,"\n");
		}
	}
fclose(fp);
fclose(fr);
}

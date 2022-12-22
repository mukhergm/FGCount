/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 *Purpose: Extract CONNECT Part from the Connect2.0.exe output.
 * How to run:
 * ./lp3.exe <Output file of Connect2.0.exe> <Output file name> 
 * Please note here, This can also be done by "grep" command
 * egrep "CONNECT" <Output file of Connect2.0.exe>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
	{
	FILE *fp,*fw;
	if (argc<2) 
	  {
          printf("                 <Input file>                 <Output file>\n");
	  printf("./lp3.exe <Output file of Connect2.0.exe> <Output file name>\n");
	  exit(1);
	  }

	struct format
		{
		char a[5];
		char b[4];
		char c[4],d[4],e[8],f[8],g[8],h[8];
		};
		struct format f;
	char str[500];
	fp=fopen(argv[1],"r");
	fw=fopen(argv[2],"w");
	if (fw==NULL)
        {
        printf("lp3.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }
	while(fgets(str,500,fp)!=NULL)
		{
		if(strncmp("CONE",str,4)==0 || strncmp("CONNE",str,5)==0)
			{
			f.b[0]='\0';
			f.c[0]='\0';
			f.c[0]='\0';
			f.d[0]='\0';
			f.e[0]='\0';
			f.f[0]='\0';
			f.g[0]='\0';
			f.h[0]='\0';
			sscanf(str,"%s%s%s%s%s%s%s%s",f.a,f.b,f.c,f.d,f.e,f.f,f.g,f.h);
			fprintf(fw,"%s   \t",f.b);
			fprintf(fw,"%s   \t",f.c);
			if(f.d[0]!='\0')
			fprintf(fw,"%s   \t",f.d);

			if(f.e[0]!='\0')
			fprintf(fw,"%s   \t",f.e);
			if(f.f[0]!='\0')
			fprintf(fw,"%s   \t",f.f);

			if(f.g[0]!='\0')
			fprintf(fw,"%s   \t",f.g);
			
			if(f.h[0]!='\0')
			fprintf(fw,"%s   \t",f.h);

			fprintf(fw,"\n");
			}
		}
fclose(fp);
	}


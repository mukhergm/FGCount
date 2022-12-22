/*
 * Written by Goutam Mukherjee
 *Purpose: Grep line number which is start with ATOM and CONNECT in a file.
 * How to run:
 * ./grep.exe <Output of CONNECTMOL programme>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc, char *argv[])
{
void fill(char *);
        char *b;
        FILE *fr;
        char st[4];
        char st1[2], st2[2], st3[2], st4[2];
        int line=0;
        //int fn1=0, fn2=0, fn3=0, fn4=0, fn5=0, fn6=0, fn7=0, fn8=0, fn9=0, f10=0;
        char str[100], s[100];
	if (argc<2) {
 	printf("./grep.exe <Output of CONNECTMOL programme>\n");
 	 exit(1);
	}

        fr=fopen(argv[1],"r");
        while(fgets(str,100,fr)!=NULL)
        {
		if(strncmp(str,"ATOM",4)==0 || strncmp(str,"CONN",4)==0)
			printf("%s",str);
	}
	fclose(fr);
}


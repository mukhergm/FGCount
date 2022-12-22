/*
 * Written by Goutam Mukherjee
 *Purpose: Print the number of rings present in a molecule. Say, in cyclobutane, this programme print one 4-Member-Ring
 * How to run:
 * ./lp9.exe <Output of ring.exe programme>
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
        int fn1=0, fn2=0, fn3=0, fn4=0, fn5=0, fn6=0, fn7=0, fn8=0, fn9=0, f10=0;
        char str[100], s[100];
	int num=0;
        fr=fopen(argv[1],"r");
	if (argc<2) {
	printf("./lp9.exe <Output of ring.exe programme>\n");
	exit(1);
	}

        while(fgets(str,100,fr)!=NULL)
        {
	sscanf(str,"%d %s", &num, s);
	if(strstr(s,"3MR"))
		fn1=fn1+1;
	if(strstr(s,"4MR"))
                fn2=fn2+1;
	if(strstr(s,"5MR"))
                fn3=fn3+1;
	if(strstr(s,"6MR"))
                fn4=fn4+1;
	if(strstr(s,"7MR"))
                fn5=fn5+1;
	if(strstr(s,"8MR"))
                fn6=fn6+1;
	}
	printf("f513 (3-Member-Ring) = %d\n",fn1/3);
	printf("f514 (4-Member-Ring) = %d\n",fn2/4);
	printf("f515 (5-Member-Ring) = %d\n",fn3/5);
	printf("f516 (6-Member-Ring) = %d\n",fn4/6);
	printf("f517 (7-Member-Ring) = %d\n",fn5/7);
	printf("f518 (8-Member-Ring) = %d\n",fn6/8);
fclose(fr);
}


/*
 * Written by Goutam Mukherjee
 * Purpose: This program will concatenate "RTO" to the acyclic methylene group when the atomtype string of methylene group contains SMeSMe string or, this programme concatenate "RTO" to the cyclic methylene group when the atomtype string of methylene group contains SMeSMeSMe string
 * How to run:
 * ./lp7.exe <Output file of lp6.exe>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
void fill(char *);
        char *b;
        FILE *fr;
        int sum=0;
        char str[100], s[100];
        fr=fopen(argv[1],"r");
	if (argc<2) {
  	printf("./lp7.exe <Output file of lp6.exe>\n");
  	exit(1);
	}
        while(fgets(s,100,fr)!=NULL)
     	{
		sscanf(s,"%s", str);
		sum=0;
		int k=strlen(s);

		if(strncmp(str,"C",1)==0 && k>=12)
      		{
        		b=strstr(s,"SMe");
			if(b)
			{    	
				fill(b);
				sum=sum+1;
         			b=strstr(s,"SMe");
         			if(b)
				{        
        				fill(b);
					sum=sum+1;
					b=strstr(s,"SMe");
					if(b)
					{
						fill(b);
						sum=sum+1;
					}
				}
			}

			if(sum>=2 && strstr(str,"MR")==NULL)
                        strcat(str,"RTO");
			if(sum>=3 && strstr(str,"MR"))
                        strcat(str,"RTO");
		}
		printf("%s\n", str);
	}
      fclose(fr);
}
void fill(char *a)
      {
        int i=0;
        for(i=0;i<3;i++)
        *(a+i)='p';
      }		

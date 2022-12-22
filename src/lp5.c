/*
 * Written by Goutam Mukherjee
 * Purpose: This program concatenate a three letter nomenclature at the end of the atomtype printed by lp4.exe programme
 * The list of nomenclaures are given below:
 * PMe: Methyl group
 * SMe: Methylene group
 * TMe: Tert methyl group
 * QMe: Quaternary methyl group
 * How to run:
 * ./lp5.exe <Output file of lp4.exe>
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
void fill(char *);
        char *b;
	char st1[2], st2[2], st3[2], st4[2];
        FILE *fr;
        int sum=0;
        char str[100], s[100];
        fr=fopen(argv[1],"r");
	if (argc<2) {
 	printf("./lp5.exe <Output file of lp4.exe>\n");
	exit(1);
	}
        while(fgets(s,100,fr)!=NULL)
     	{
		sscanf(s,"%s", str);
		st1[0]=str[2];
                st1[1]='\0';

                st2[0]=str[5];
                st2[1]='\0';

                st3[0]=str[8];
                st3[1]='\0';

                st4[0]=str[11];
                st4[1]='\0';
		sum=0;
		int k=strlen(s);

		if(strncmp(str,"C",1)==0 && strchr(st1,'1') && strchr(st2,'1') && strchr(st3,'1') && strchr(st4,'1'))
				//strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st1,'4')==NULL && 
				//strchr(st1,'5')==NULL && strchr(st1,'6')==NULL && strchr(st1,'8')==NULL && 
				//strchr(st1,'9')==NULL && strchr(st2,'2')==NULL && strchr(st2,'3')==NULL && 
				//strchr(st2,'4')==NULL && strchr(st2,'5')==NULL && strchr(st2,'6')==NULL && 
				//strchr(st2,'8')==NULL && strchr(st2,'9')==NULL && strchr(st3,'2')==NULL && 
				//strchr(st3,'3')==NULL && strchr(st3,'4')==NULL && strchr(st3,'5')==NULL && 
				//strchr(st3,'6')==NULL && strchr(st3,'8')==NULL && strchr(st3,'9')==NULL)
      		{
			//if((k<=13 && strstr(s,"MR")==NULL) || (k<=16 && strstr(s,"4MR")) || (k<=16 && strstr(s,"5MR")) || (k<=16 && strstr(s,"6MR")) || (k<=16 && strstr(s,"7MR")) ||
			  //(k<=16 && strstr(s,"3MR")) || (k<=19 && strstr(s,"3MR3")) || (k<=19 && strstr(s,"3MR4")) || (k<=19 && strstr(s,"3MR5")) || (k<=19 && strstr(s,"3MR6")) || (k<=19 && strstr(s,"3MR7")) || (k<=19 && strstr(s,"4MR3")) || (k<=19 && strstr(s,"4MR4")) || (k<=19 && strstr(s,"4MR5")) || (k<=19 && strstr(s,"4MR6")) || (k<=19 && strstr(s,"4MR7")) || 
//       (k<=19 && strstr(s,"5MR3")) || (k<=19 && strstr(s,"5MR4")) || (k<=19 && strstr(s,"5MR5")) || (k<=19 && strstr(s,"5MR6")) || (k<=19 && strstr(s,"5MR7")) ||
//       (k<=19 && strstr(s,"6MR3")) || (k<=19 && strstr(s,"6MR4")) || (k<=19 && strstr(s,"6MR5")) || (k<=19 && strstr(s,"6MR6")) || (k<=19 && strstr(s,"6MR7")) ||
//       (k<=19 && strstr(s,"7MR3")) || (k<=19 && strstr(s,"7MR4")) || (k<=19 && strstr(s,"7MR5")) || (k<=19 && strstr(s,"7MR6")) || (k<=19 && strstr(s,"7MR7")))
                        //if((k==12 && strstr(s,"MR")==NULL))
//			{
        		 	b=strstr(s,"CH1");
				if(b)
				{    	
					fill(b);
					sum=sum+1;
         				b=strstr(s,"CH1");
         				if(b)
					{        
        					fill(b);
						sum=sum+1;
         					b=strstr(s,"CH1");
         					if(b)
						{        
        						fill(b);
							sum=sum+1;
	 					}
					}
				}
//			}
			if(sum==3)
				strcat(str,"PMe");
			if(sum==2)
                        	strcat(str,"SMe");
			if(sum==1)
                        	strcat(str,"TMe");
			if(sum==0)
                        	strcat(str,"QMe");
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

/*
 * Written by Goutam Mukherjee
 * Purpose: This program will concatenate "SMe" to the methylene group when the adjacent functional group also contains "SMe" group.
 * How to run:
 * ./lp6.exe <Output file of lp5.exe> <Output file of lp3.exe> <Output file name> 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <iostream.h>

main(int argc, char *argv[])
{
	void fill(char *);
        void fill2(char *);
	void fill3(char *);

	char *b;

	FILE *fp,*fr,*fw;
	if (argc<3) {
  	printf("               <Input file-1>            <Input file-2>       <Output file>\n");
  	printf("./lp6.exe <Output file of lp5.exe> <Output file of lp3.exe> <Output file name>\n");
  	exit(1);
	}

       	struct format
       {
        int a;
        int b;
        int c;
	int d;
	int e;
	int f;
	int g;	
       };
        struct format f;
	
        char strings[100],str[100];
	char strings_array[1000][100];
	//char str_array[100][100];
	char final_string[999][50];
 	char *result;	
	fp=fopen(argv[1],"r");
	fr=fopen(argv[2],"r");
	fw=fopen(argv[3],"w");
		
	if (fw==NULL)            
        {
        printf("lp6.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }

	int line1=0;
	while(fgets(strings,100,fp)!=NULL)
	{
		int len = strlen(strings);
		strncpy(strings_array[line1],strings,len-1);	
		line1++;
	}


	int line=0;
	while(fgets(str,100,fr)!=NULL)
	{
                f.a=0;
                f.b=0;
                f.c=0;
		f.d=0;
		f.e=0;
		f.f=0;
		f.g=0;
                sscanf(str,"%d%d%d%d%d%d%d",&f.a,&f.b,&f.c,&f.d,&f.e,&f.f,&f.g);
                    
                
		strcpy(final_string[line],strings_array[line]);

		if(strstr(final_string[line],"SMe"))
                {
			if(strstr(strings_array[f.b-1],"SMe"))
			strcat(final_string[line],"SMe");
                        if(strstr(strings_array[f.c-1],"SMe"))
                        strcat(final_string[line],"SMe");
			if(strstr(strings_array[f.d-1],"SMe"))
                        strcat(final_string[line],"SMe");
			if(strstr(strings_array[f.e-1],"SMe"))
                        strcat(final_string[line],"SMe");
			//strncat(final_string[line],strings_array[f.b-1],18);
                        //strncat(final_string[line],strings_array[f.c-1],18);
                        //strncat(final_string[line],strings_array[f.d-1],18);
                        //strncat(final_string[line],strings_array[f.e-1],18);
                        //strncat(final_string[line],strings_array[f.f-1],18);
                }
		//Added on 14 December 2021
		if(strncmp(final_string[line],"SP1NEG",6)==0)
		{
			if(strstr(strings_array[f.b-1],"PS2"))
				strcpy(final_string[line],"SP2");
		}

		if(strncmp(final_string[line],"OC1OH1",6)==0 || strncmp(final_string[line],"OH1OC1",6)==0)
                {
			if(strstr(final_string[line],"ELN")==NULL)
			{
                        	if(strstr(strings_array[f.c-1],"CN2") || strstr(strings_array[f.b-1],"CN2"))
                        		strcat(final_string[line],"ELN");
			}
                }
		//End of addition
		if(strncmp(final_string[line],"O",1)==0 && strlen(final_string[line])>4 && strstr(final_string[line], "SO2")==NULL && strstr(final_string[line], "PO2")==NULL )   //Added on 17.04.21
                {
                	if(strstr(strings_array[f.b-1],"SO2") || strstr(strings_array[f.c-1],"SO2"))
                        	strcat(final_string[line],"S=O");
                        if(strstr(strings_array[f.b-1],"PO2") || strstr(strings_array[f.c-1],"PO2"))
                        	strcat(final_string[line],"P=O");
                }
		if(strncmp(final_string[line],"O",1)==0 && strstr(final_string[line],"OO1"))
		{
			if(strstr(final_string[line],"EST")==NULL)
			{
				if(strstr(strings_array[f.b-1],"EST") || strstr(strings_array[f.c-1],"EST"))
					strcat(final_string[line],"EST");
			}
		}
		if(strncmp(final_string[line],"O",1)==0)
                        {
                                if(strstr(final_string[line],"ON1NEG"))
                                {
                                        if(strstr(strings_array[f.b-1],"NO1NN1NEG") || strstr(strings_array[f.b-1],"NN1NO1NEG"))
                                                strcpy(final_string[line],"ON2");
                                }
                        }

                if(strncmp(final_string[line],"O",1)==0)
                {
                	if(strstr(final_string[line],"ON1NEG"))
                        {
                        	if(strstr(strings_array[f.b-1],"NO2NN1"))
                                                strcpy(final_string[line],"ON2");
                        }
                }
		if(strncmp(final_string[line],"N",1)==0)
                        {
                                if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]!='1' && final_string[line][8]!='2' && final_string[line][8]!='3' && final_string[line][8]!='4')
                                                {
                                                        if(strstr(final_string[line],"NC1") && (strstr(strings_array[f.b-1],"CN2") || strstr(strings_array[f.c-1],"CN2")))
                                                        {
                                                                b=strstr(final_string[line],"NC1");
                                                                if(b)
                                                                        fill(b);
								b=strstr(final_string[line],"NEG");
                                                                if(b)
                                                                        fill2(b);
                                                        }
						}
			}
		if(strncmp(final_string[line],"C",1)==0)
                {
			if(final_string[line][2]=='4' && final_string[line][5]=='4' && final_string[line][8]=='4')
			{
				if((strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')) ||
				   (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
				   (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL))
				{
					b=strstr(final_string[line],"CC4");
					if(b)
						fill3(b);
				}
			}
		}

                fprintf(fw,"%s\n",final_string[line]);
		line++;
          }
          

	fclose(fp);
	fclose(fr);

}
void fill(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='2';
      }
void fill2(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='\0';
        for(i=1;i<2;i++)
        *(a+i)='\0';
        for(i=2;i<3;i++)
        *(a+i)='\0';
      }
void fill3(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='1';
      }

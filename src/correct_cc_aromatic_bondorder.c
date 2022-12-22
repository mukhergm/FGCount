/*
 * Author: Goutam Mukherjee, PhD
 * This code correct the bond order of aromatic C-C bonds
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
	void fill4(char *);
	void fill5(char *);
	void fill6(char *);
	void fill7(char *);
	void fill8(char *);
	void fill9(char *);
	void fill10(char *);
	void fill11(char *);
	void fill12(char *);

	char *b, *c;
	FILE *fp,*fr,*fw;
	if (argc<3) {
  	printf("               <Input file-1>                 <Input file-2>       <Output file>\n");
  	printf("./correct_cc_aromatic_bondorder.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name>\n");
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
        printf("lp4.exe: Cannot write output. No output file name is given\n");
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
			//Correcting C-N bond order
			
		if(strncmp(final_string[line],"C",1)==0)
			{
				if(strstr(final_string[line],"CC4CC4") && (final_string[line][8]=='1' || final_string[line][2]=='1'))
				{
					   if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
					      (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
					      (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
						//printf("Found\n");
                                                b=strstr(final_string[line],"CC4CC4");
                                                if(b)
                                                        fill(b);
                                        }
				}
				//
				if(strstr(final_string[line],"CC4CC4") && (final_string[line][8]=='1' || final_string[line][2]=='1'))
                                {
                                           if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                //printf("Found\n");
                                                b=strstr(final_string[line],"CC4CC4");
                                                if(b)
                                                        fill(b);
                                        }
                                }

				//CN4CN4
				if(strstr(final_string[line],"CN4CN4") && (final_string[line][8]=='1' || final_string[line][2]=='1'))
                                {
                                           if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                //printf("Found\n");
                                                b=strstr(final_string[line],"CN4CN4");
                                                if(b)
                                                        fill(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CN4") && (final_string[line][8]=='1' || final_string[line][2]=='1'))
                                {
                                           if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                //printf("Found\n");
                                                b=strstr(final_string[line],"CN4CN4");
                                                if(b)
                                                        fill(b);
                                        }
                                }
				//CC4CN4
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CN4") && strchr(final_string[line],'1'))
				{
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
						if((strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4') ||
						   (strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4') ||
						   (strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4'))
						{
							b=strstr(final_string[line],"CN4");
							if(b)
								fill5(b);
							b=strstr(final_string[line],"CC4");
                                                        if(b)
                                                                fill4(b);
						}
						if((strncmp(strings_array[f.b-1],"N",1)==0 && (strings_array[f.b-1][8]=='1' || strings_array[f.b-1][8]=='2' || strings_array[f.b-1][8]=='3' || strings_array[f.b-1][8]=='4')) ||
						   (strncmp(strings_array[f.c-1],"N",1)==0 && (strings_array[f.c-1][8]=='1' || strings_array[f.c-1][8]=='2' || strings_array[f.c-1][8]=='3' || strings_array[f.c-1][8]=='4')) ||
						   (strncmp(strings_array[f.d-1],"N",1)==0 && (strings_array[f.d-1][8]=='1' || strings_array[f.d-1][8]=='2' || strings_array[f.d-1][8]=='3' || strings_array[f.d-1][8]=='4')))
						{
							b=strstr(final_string[line],"CN4");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(final_string[line],"CC4");
                                                        if(b)
                                                                fill5(b);
                                                }
					}
				}
				//
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CN4") && strchr(final_string[line],'1'))
                                {
				 if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                if((strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4') ||
                                                   (strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4') ||
                                                   (strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4'))
                                                {
                                                        b=strstr(final_string[line],"CN4");
                                                        if(b)
                                                                fill5(b);
                                                        b=strstr(final_string[line],"CC4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                                if((strncmp(strings_array[f.b-1],"N",1)==0 && (strings_array[f.b-1][8]=='1' || strings_array[f.b-1][8]=='2' || strings_array[f.b-1][8]=='3' || strings_array[f.b-1][8]=='4')) ||
                                                   (strncmp(strings_array[f.c-1],"N",1)==0 && (strings_array[f.c-1][8]=='1' || strings_array[f.c-1][8]=='2' || strings_array[f.c-1][8]=='3' || strings_array[f.c-1][8]=='4')) ||
                                                   (strncmp(strings_array[f.d-1],"N",1)==0 && (strings_array[f.d-1][8]=='1' || strings_array[f.d-1][8]=='2' || strings_array[f.d-1][8]=='3' || strings_array[f.d-1][8]=='4')))
                                                {
                                                        b=strstr(final_string[line],"CN4");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(final_string[line],"CC4");
                                                        if(b)
                                                                fill5(b);
                                                }
                                        }
                                }
				//CC4CO4
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CO4") && strchr(final_string[line],'1'))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                        	b=strstr(final_string[line],"CO4");
                                                if(b)
                                                	fill4(b);
                                                b=strstr(final_string[line],"CC4");
                                                if(b)
                                                	fill5(b);
                                                }
				}
				//
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CO4") && strchr(final_string[line],'1'))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CO4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(final_string[line],"CC4");
                                                if(b)
                                                        fill5(b);
                                                }
                                }
				//CC4CS4
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CS4") && strchr(final_string[line],'1'))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CS4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(final_string[line],"CC4");
                                                if(b)
                                                        fill5(b);
                                                }
                                }
				//
				if(strstr(final_string[line],"CC4") && strstr(final_string[line],"CS4") && strchr(final_string[line],'1'))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CS4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(final_string[line],"CC4");
                                                if(b)
                                                        fill5(b);
                                                }
                                }
				//
				if(strstr(final_string[line],"CC4CC1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CC1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CC1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CC1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CC1CN4
				if(strstr(final_string[line],"CN4CC1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CC1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CC1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CC1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				
				//CC4CH1CC4
				if(strstr(final_string[line],"CC4CH1CC4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CH1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CH1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CH1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CH1CN4
				if(strstr(final_string[line],"CN4CH1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CH1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CH1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CH1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				
				//CC4CN1CC4
				if(strstr(final_string[line],"CC4CN1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CN1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CN1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CN1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CN1CN4
				if(strstr(final_string[line],"CN4CN1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CN1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CN1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CN1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				
				//CC4CO1CC4
				if(strstr(final_string[line],"CC4CO1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CO1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CO1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CO1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CO1CN4
				if(strstr(final_string[line],"CN4CO1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CO1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CO1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CO1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				
				//CC4CS1CC4
				if(strstr(final_string[line],"CC4CS1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CS1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CS1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CS1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CS1CN4
				if(strstr(final_string[line],"CN4CS1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CS1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CS1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CS1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CC4CF1CC4
				if(strstr(final_string[line],"CC4CF1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CF1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CF1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CF1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//CN4CF1CN4
				if(strstr(final_string[line],"CN4CF1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CF1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CF1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CF1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CC4Cl1CC4
				if(strstr(final_string[line],"CC4Cl1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4Cl1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4Cl1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4Cl1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CN4Cl1CN4
				if(strstr(final_string[line],"CN4Cl1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4Cl1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4Cl1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4Cl1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CC4CB1CC4
				if(strstr(final_string[line],"CC4CB1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CB1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CB1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CB1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CN4CB1CN4
				if(strstr(final_string[line],"CN4CB1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CB1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CB1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CB1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CC4CI1CC4
				if(strstr(final_string[line],"CC4CI1CC4"))
                                {
					if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
					{
                                                b=strstr(final_string[line],"CC4CI1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CC4CI1CC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CC4CI1CC4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }

				//CN4CI1CN4
				if(strstr(final_string[line],"CN4CI1CN4"))
                                {
                                        if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2') && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CI1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
				//
				if(strstr(final_string[line],"CN4CI1CN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) || (strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.b-1],'4')==NULL) || (strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.d-1],'4') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                              (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"CN4CI1CN4");
                                                if(b)
                                                        fill8(b);
                                        }
                                }
			}
		if(strncmp(final_string[line],"N",1)==0)
                        {
				//For NC4NC4
                                if(strstr(final_string[line],"NC4NC4") && strchr(final_string[line],'1')==NULL)
                                {	
					if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'2')) ||
					   (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'2')) ||
					   (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'2')))
					{
						b=strstr(final_string[line],"NC4NC4");
							if(b)
                                                        	fill3(b);
					}
				}
				if(strstr(final_string[line],"NC4NC4") && strchr(final_string[line],'1')==NULL)
                                {
					if(strchr(strings_array[f.c-1],'4')==NULL || strchr(strings_array[f.b-1],'4')==NULL)
                                	//if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) || 
                                    	  // (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) ||
					   //(strchr(strings_array[f.b-1],'4')==NULL || strchr(strings_array[f.c-1],'4')==NULL)) //||
					   //(strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')))
                                        {
                                                b=strstr(final_string[line],"NC4NC4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NC4NC4") && strchr(final_string[line],'1'))
                                {
				    if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))
                                        {
                                                b=strstr(final_string[line],"NC4");
						if(b)
						{
							fill4(b);
							b=strstr(final_string[line],"NC4");
                                                	if(b)
								fill4(b);
						}
					}
				}
				if(strstr(final_string[line],"NC4NC4") && strchr(final_string[line],'1'))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NC4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }
				
				//For NC4NN4
				if(strstr(final_string[line],"NC4NN4") && strchr(final_string[line],'1')==NULL)
                                {
                                        if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'2')) ||
                                           (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'2')) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'2')))
                                        {
                                                b=strstr(final_string[line],"NC4NN4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NC4NN4") && strchr(final_string[line],'1')==NULL)
                                {
					if(strchr(strings_array[f.c-1],'4')==NULL || strchr(strings_array[f.b-1],'4')==NULL)
					/*if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) ||
                                           (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')) ||
                                           (strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')))*/
                                        {
                                                b=strstr(final_string[line],"NC4NN4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NC4NN4") && strchr(final_string[line],'1'))
                                {
				    if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }
				if(strstr(final_string[line],"NC4NN4") && strchr(final_string[line],'1'))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NN4NC4
				if(strstr(final_string[line],"NN4NC4") && strchr(final_string[line],'1')==NULL)
                                {
                                        if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'2')) ||
                                           (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'2')) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'2')))
                                        {
                                                b=strstr(final_string[line],"NN4NC4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NN4NC4") && strchr(final_string[line],'1')==NULL)
                                {
					if(strchr(strings_array[f.c-1],'4')==NULL || strchr(strings_array[f.b-1],'4')==NULL)
					/*if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) ||
                                           (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')) ||
                                           (strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')))*/
                                        {
                                                b=strstr(final_string[line],"NN4NC4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NN4NC4") && strchr(final_string[line],'1'))
                                {
				    if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }
				if(strstr(final_string[line],"NN4NC4") && strchr(final_string[line],'1'))
                                {
                                if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
				   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NN4NN4
				if(strstr(final_string[line],"NN4NN4") && strchr(final_string[line],'1')==NULL)
                                {
                                        if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'2')) ||
                                           (strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.d-1],'2')) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.d-1],'2')))
                                        {
                                                b=strstr(final_string[line],"NN4NN4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NN4NN4") && strchr(final_string[line],'1')==NULL)
                                {
					if(strchr(strings_array[f.c-1],'4')==NULL || strchr(strings_array[f.b-1],'4')==NULL)
					/*if((strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
                                           (strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) ||
                                           (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')) ||
                                           (strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.b-1],'4')))*/
                                        {
                                                b=strstr(final_string[line],"NN4NN4");
                                                        if(b)
                                                                fill3(b);
                                        }
                                }
				if(strstr(final_string[line],"NN4NN4") && strchr(final_string[line],'1'))
                                {
				    if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                       (strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))
                                        {
                                                b=strstr(final_string[line],"NN4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }
				if(strstr(final_string[line],"NN4NN4") && strchr(final_string[line],'1'))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NN4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NC4NX1NC4
				if(strstr(final_string[line],"NC4NC1NC4") || strstr(final_string[line],"NC4NH1NC4") ||
				   strstr(final_string[line],"NC4NN1NC4") || strstr(final_string[line],"NC4NO1NC4") ||
				   strstr(final_string[line],"NC4NF1NC4") || strstr(final_string[line],"NC4Nl1NC4") ||
				   strstr(final_string[line],"NC4NB1NC4") || strstr(final_string[line],"NC4NI1NC4"))
				{
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
				   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NC4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NC4NX1NN4
				if(strstr(final_string[line],"NC4NC1NN4") || strstr(final_string[line],"NC4NH1NN4") ||
                                   strstr(final_string[line],"NC4NN1NN4") || strstr(final_string[line],"NC4NO1NN4") ||
                                   strstr(final_string[line],"NC4NF1NN4") || strstr(final_string[line],"NC4Nl1NN4") ||
                                   strstr(final_string[line],"NC4NB1NN4") || strstr(final_string[line],"NC4NI1NN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NN4NX1NC4
				if(strstr(final_string[line],"NN4NC1NC4") || strstr(final_string[line],"NN4NH1NC4") ||
                                   strstr(final_string[line],"NN4NN1NC4") || strstr(final_string[line],"NN4NO1NC4") ||
                                   strstr(final_string[line],"NN4NF1NC4") || strstr(final_string[line],"NN4Nl1NC4") ||
                                   strstr(final_string[line],"NN4NB1NC4") || strstr(final_string[line],"NN4NI1NC4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NC4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }

				//For NN4NX1NN4
				if(strstr(final_string[line],"NN4NC1NN4") || strstr(final_string[line],"NN4NH1NN4") ||
                                   strstr(final_string[line],"NN4NN1NN4") || strstr(final_string[line],"NN4NO1NN4") ||
                                   strstr(final_string[line],"NN4NF1NN4") || strstr(final_string[line],"NN4Nl1NN4") ||
                                   strstr(final_string[line],"NN4NB1NN4") || strstr(final_string[line],"NN4NI1NN4"))
                                {
				if((strchr(strings_array[f.b-1],'4') && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4') && strchr(strings_array[f.d-1],'4')==NULL) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')) ||
                                   (strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL && strchr(strings_array[f.d-1],'4')==NULL))
                                        {
                                                b=strstr(final_string[line],"NN4");
                                                if(b)
                                                {
                                                        fill4(b);
                                                        b=strstr(final_string[line],"NN4");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
                                }


			}

			if(strncmp(final_string[line],"O",1)==0)
                        {
                                if(strstr(final_string[line],"OC4OC4"))
                                {
				if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2'))) //May be f.b=4==NULL || f.c b==NULL is better
                                        {
                                                b=strstr(final_string[line],"OC4OC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"OC4ON4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"OC4ON4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"ON4OC4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"ON4OC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"OC4OS4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"OC4OS4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"OS4OC4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"OS4OC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"OC4OO4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"OC4OO4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"OO4OC4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"OO4OC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
			}

			if(strncmp(final_string[line],"S",1)==0)
                        {
                                if(strstr(final_string[line],"SC4SC4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"SC4SC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SC4SN4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"SC4SN4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SN4SC4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"SN4SC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SC4SO4"))
                                {
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"SC4SO4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SO4SC4"))
                                {
                                     /*if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                        (strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                        (strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))*/
					if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        {
                                                b=strstr(final_string[line],"SO4SC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SC4SS4"))
                                {
                                     if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
                                        /*(strchr(strings_array[f.c-1],'2') && strchr(strings_array[f.b-1],'4')==NULL) ||
					(strchr(strings_array[f.b-1],'2') && strchr(strings_array[f.c-1],'4')==NULL) ||
					(strchr(strings_array[f.b-1],'4')==NULL && strchr(strings_array[f.c-1],'4')==NULL) ||
					(strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))*/
                                        {
                                                b=strstr(final_string[line],"SC4SS4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
				if(strstr(final_string[line],"SS4SC4"))
                                {
                                     //if((strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.c-1],'2') || strchr(strings_array[f.c-1],'4')==NULL)) ||
                                        //(strchr(strings_array[f.b-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)) ||
                                        //(strchr(strings_array[f.c-1],'2') && (strchr(strings_array[f.d-1],'2') || strchr(strings_array[f.d-1],'4')==NULL)))
                                        if((strchr(strings_array[f.b-1],'2') || strchr(strings_array[f.c-1],'2')))
					{
                                                b=strstr(final_string[line],"SS4SC4");
                                                        if(b)
                                                                fill12(b);
                                        }
                                }
			}
			//Correcting bond order of N-atom, when present as a bridge of two aromatic groups and contains a single bond and two aromatic bond orders
			if(strncmp(final_string[line],"N",1)==0)
			{
				if((final_string[line][2]=='4' && final_string[line][5]=='4' && final_string[line][8]=='1'))
				{
					if(strings_array[f.b-1][2]=='4' && strings_array[f.b-1][5]=='4' && strings_array[f.b-1][8]=='4' && 
					   strings_array[f.c-1][2]=='4' && strings_array[f.c-1][5]=='4' && strings_array[f.c-1][8]=='4')
					{
						b=strchr(final_string[line],'4');
						if(b)
						{
							fill6(b);
							b=strchr(final_string[line],'4');
							if(b)
								fill6(b);
						}
						b=strstr(strings_array[f.b-1],"CN4");
						if(b)
							fill4(b);
						b=strstr(strings_array[f.c-1],"CN4");
                                                if(b)
                                                        fill4(b);
					}
				}
				if((final_string[line][2]=='4' && final_string[line][5]=='1' && final_string[line][8]=='4'))
                                {
                                        if(strings_array[f.b-1][2]=='4' && strings_array[f.b-1][5]=='4' && strings_array[f.b-1][8]=='4' &&
                                           strings_array[f.d-1][2]=='4' && strings_array[f.d-1][5]=='4' && strings_array[f.d-1][8]=='4')
                                        {
                                                b=strchr(final_string[line],'4');
                                                if(b)
						{
                                                        fill6(b);
							b=strchr(final_string[line],'4');
							if(b)
								fill6(b);
						}
                                                b=strstr(strings_array[f.b-1],"CN4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(strings_array[f.d-1],"CN4");
                                                if(b)
                                                        fill4(b);
                                        }
                                }
				if((final_string[line][2]=='1' && final_string[line][5]=='4' && final_string[line][8]=='4'))
                                {
                                        if(strings_array[f.d-1][2]=='4' && strings_array[f.d-1][5]=='4' && strings_array[f.d-1][8]=='4' &&
                                           strings_array[f.c-1][2]=='4' && strings_array[f.c-1][5]=='4' && strings_array[f.c-1][8]=='4')
                                        {
                                                b=strchr(final_string[line],'4');
                                                if(b)
						{
                                                        fill6(b);
							b=strchr(final_string[line],'4');
							if(b)
								fill6(b);
						}
                                                b=strstr(strings_array[f.d-1],"CN4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(strings_array[f.c-1],"CN4");
                                                if(b)
                                                        fill4(b);
                                        }
                                }
			}
			//When a ether-type oxygen present in a 6-membered ring and bond order printed by connectmol programme as 4
			if(strncmp(final_string[line],"O",1)==0)
                        {
                                if(strstr(final_string[line],"OC4OC46MR") && strstr(final_string[line],"5MR")==NULL)
                                {
                                        b=strchr(final_string[line],'4');
                                                if(b)
                                                {
							fill6(b);
							b=strchr(final_string[line],'4');
							if(b)
								fill6(b);
						}
						b=strstr(strings_array[f.b-1],"CO4");
						if(b)
							fill4(b);
						b=strstr(strings_array[f.c-1],"CO4");
                                                if(b)
                                                        fill4(b);
                                }
                        }
			//When a thioether-type S atom present in a 6-membered ring and bond order printed by connectmol programme as 4
			if(strncmp(final_string[line],"S",1)==0)
                        {
                                if(strstr(final_string[line],"SC4SC46MR") && strstr(final_string[line],"5MR")==NULL)
                                {
                                        b=strchr(final_string[line],'4');
                                                if(b)
                                                {
                                                        fill6(b);
                                                        b=strchr(final_string[line],'4');
                                                        if(b)
                                                                fill6(b);
                                                }
                                                b=strstr(strings_array[f.b-1],"CS4");
                                                if(b)
                                                        fill4(b);
                                                b=strstr(strings_array[f.c-1],"CS4");
                                                if(b)
                                                        fill4(b);
                                }
                        }

                //fprintf(fw,"%s\n",final_string[line]);
		
		line++;
          }
         	for(int k=0; k<line; k++)
		       fprintf(fw,"%s\n",final_string[k]);	

	fclose(fp);
	fclose(fr);

}
//Added on 14 December 2021
void fill(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='1';
	for(i=5;i<6;i++)
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
	for(i=5;i<6;i++)
        *(a+i)='2';
      }

void fill4(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='1';
      }

void fill5(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='2';
      }

void fill6(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='1';
      }

void fill7(char *a)
      {
        int i=0;
        for(i=5;i<6;i++)
        *(a+i)='2';
      }
void fill8(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='2';
	for(i=5;i<6;i++)
        *(a+i)='1';
	for(i=8;i<9;i++)
        *(a+i)='1';
      }

void fill9(char *a)
      {
	int i=0;
        for(i=2;i<3;i++)
        *(a+i)='1';
        for(i=5;i<6;i++)
        *(a+i)='2';
        for(i=8;i<9;i++)
        *(a+i)='2';
      }

void fill10(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='3';
      }

void fill11(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='2';
      }
void fill12(char *a)
      {
        int i=0;
        for(i=2;i<3;i++)
        *(a+i)='1';
        for(i=5;i<6;i++)
        *(a+i)='1';
      }
//End of addition

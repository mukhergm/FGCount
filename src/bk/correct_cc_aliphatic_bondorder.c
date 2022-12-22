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

	char *b, *c;
	FILE *fp,*fr,*fw;
	if (argc<3) {
  	printf("               <Input file-1>                 <Input file-2>       <Output file>\n");
  	printf("./correct_cn_bondorder.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name>\n");
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
		//Correcting C-C bond order
		if(strncmp(final_string[line],"C",1)==0)
                        {
                                if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
                                {
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
					   (strings_array[f.c-1][0]=='C' && (strings_array[f.c-1][2]=='1' || strings_array[f.c-1][5]=='1' || strings_array[f.c-1][8]=='1') && (strings_array[f.c-1][2]=='4' || strings_array[f.c-1][5]=='4' || strings_array[f.c-1][8]=='4')) ||
					   (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
                                        {
                                                b=strstr(final_string[line],"CC1CC1CC1");
                                                if(b)
                                                        fill10(b);
                                        }

                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CO1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CH1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CS1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CF1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1Cl1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CB1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
                                        if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           (strings_array[f.d-1][0]=='C' && (strings_array[f.d-1][2]=='1' || strings_array[f.d-1][5]=='1' || strings_array[f.d-1][8]=='1') && (strings_array[f.d-1][2]=='4' || strings_array[f.d-1][5]=='4' || strings_array[f.d-1][8]=='4')))
					{
                                                b=strstr(final_string[line],"CC1CI1CC1");
                                                if(b)
                                                        fill10(b);
                                        }
					if(strstr(final_string[line],"CC1CC1") && strstr(final_string[line],"CC1CC1CC1")==NULL && strstr(final_string[line],"CN1")==NULL)
					{
						if((strings_array[f.b-1][0]=='C' && (strings_array[f.b-1][2]=='1' || strings_array[f.b-1][5]=='1' || strings_array[f.b-1][8]=='1') && (strings_array[f.b-1][2]=='4' || strings_array[f.b-1][5]=='4' || strings_array[f.b-1][8]=='4')) ||
                                           	   (strings_array[f.c-1][0]=='C' && (strings_array[f.c-1][2]=='1' || strings_array[f.c-1][5]=='1' || strings_array[f.c-1][8]=='1') && (strings_array[f.c-1][2]=='4' || strings_array[f.c-1][5]=='4' || strings_array[f.c-1][8]=='4')))
                                        	{	
							b=strstr(final_string[line],"CC1CC1");
							if(b)
								fill9(b);
						}
					}

                                }
                        }
                fprintf(fw,"%s\n",final_string[line]);
		
		

		line++;
	        
              
              //printf("%s\n",final_string[line]);
          }
          

	fclose(fp);
	fclose(fr);

}
//Added on 14 December 2021
void fill(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='P';
	for(i=1;i<2;i++)
        *(a+i)='S';
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
	for(i=5;i<6;i++)
        *(a+i)='1';
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
        *(a+i)='1';
	for(i=5;i<6;i++)
        *(a+i)='2';
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
      }

void fill10(char *a)
      {
	int i=0;
        for(i=2;i<3;i++)
        *(a+i)='2';
        for(i=5;i<6;i++)
        *(a+i)='1';
        for(i=8;i<9;i++)
        *(a+i)='1';
      }

void fill11(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='2';
      }
//End of addition

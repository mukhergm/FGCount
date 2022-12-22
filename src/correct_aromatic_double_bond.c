/*
 * Author: Goutam Mukherjee, PhD
 * This code correct the bond order of unsaturated non-aromatic carbon atom when it attached with another group which contains both a double and aromatic-bonds.
 * Note, no atom contains both double and aromatic-bonds at a time
 * e.g.; 
 * 	When a N or C or, O or, S-atoms which attachs with the central carbon atom, contains only single bonds, then this code guess the double bond formed betwen central-atom with other carbon (which contains both double and aromatic bond order) is wrong. Hence, the central carbon bond order 2 is corrected to 1 by calling a function, fill().
 *
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
  	printf("./correct_aromatic_double_bond.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name>\n");
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

		if(strncmp(final_string[line],"C",1)==0)
                {
			//When a Carbon-atom contains only double bonds no aromatic bond
                        if(strchr(final_string[line],'2') && strchr(final_string[line],'4')==NULL)
                        {
                                //When an attached C-atom contains both double and aromatic bonds with the central atom which contains only double bonds no aromatic bond
                                        if(strncmp(strings_array[f.b-1],"C",1)==0)
                                        {
                                                if(strstr(strings_array[f.b-1],"4") && strstr(strings_array[f.b-1],"2"))
                                                {
							//When a N-atom which attachs with the central atom, contains only two single bonds, then this code guess, the double bond formed betwen central-atom with other carbon(f.b) is wrong, and is corrected it as a single bond order.
                                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.c-1][0]=='C' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='C' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='O' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='O' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='S' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='S' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                }
                                        }
                                                //
                                        if(strncmp(strings_array[f.c-1],"C",1)==0)
                                        {
                                                if(strstr(strings_array[f.c-1],"4") && strstr(strings_array[f.c-1],"2"))
                                                {
                                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.b-1][0]=='C' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='C' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.b-1][0]=='O' && strings_array[f.b-1][5]!='1' && strings_array[f.b-1][5]!='2' && strings_array[f.b-1][5]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='O' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.b-1][0]=='S' && strings_array[f.b-1][5]!='1' && strings_array[f.b-1][5]!='2' && strings_array[f.b-1][5]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='S' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                }
                                        }
                                        if(strncmp(strings_array[f.d-1],"C",1)==0)
                                        {
                                                if(strstr(strings_array[f.d-1],"4") && strstr(strings_array[f.d-1],"2"))
                                                {
                                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }

                                                        if(strings_array[f.b-1][0]=='C' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='C' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='O' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='O' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.c-1][0]=='S' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
                                                        if(strings_array[f.d-1][0]=='S' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                                        {
                                                                b=strchr(final_string[line],'2');
                                                                if(b)
                                                                        fill6(b);
                                                        }
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
        *(a+i)='1';
        for(i=8;i<9;i++)
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
        for(i=2;i<3;i++)
        *(a+i)='2';
      }

void fill12(char *a)
      {
        int i=0;
        for(i=8;i<9;i++)
        *(a+i)='2';
      }
//End of addition

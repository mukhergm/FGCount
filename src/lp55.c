/*
 * Written by Goutam Mukherjee
 * Purpose: This program concatenate a three letter nomenclature, IMZ, at the end of the C2 of Imidazole atomtype printed by ring_edit.exe and lp3.exe programme
 * How to run:
 * ./lp6.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name> 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <iostream.h>

main(int argc, char *argv[])
{
	
	FILE *fp,*fr,*fw;
	if (argc<3) {
  	printf("               <Input file-1>            <Input file-2>       <Output file>\n");
  	printf("./lp55.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name>\n");
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
        printf("lp44.exe: Cannot write output. No output file name is given\n");
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


			//When central C-atom doesn't contain any C=N, and the attached N also do not contain any N=C bond
			if(strncmp(final_string[line],"C",1)==0 && final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' && final_string[line][11]!='1' && strstr(final_string[line],"2")==NULL)
                	{	
                        	if(strstr(final_string[line],"CN1CN1"))// && strstr(final_string[line],"5MR"))
                        	{
                                	if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strchr(strings_array[f.b-1],'2')==NULL &&
					  strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strchr(strings_array[f.c-1],'2')==NULL)
                                	        strcat(final_string[line],"IMZ");

					if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strchr(strings_array[f.d-1],'2')==NULL &&
                                          strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strchr(strings_array[f.c-1],'2')==NULL && strstr(strings_array[f.c-1],"5MR"))
                                                strcat(final_string[line],"IMZ");

                                	//if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strchr(strings_array[f.c-1],'2')==NULL)
                                	//        strcat(final_string[line],"IMZ");

                                	//if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strchr(strings_array[f.d-1],'2')==NULL)
                                	//        strcat(final_string[line],"IMZ");
					if(strstr(strings_array[f.b-1],"NC2") || strstr(strings_array[f.c-1],"NC2") || strstr(strings_array[f.d-1],"NC2"))
						strcat(final_string[line],"NOT");
                       		}
				//
				if((strstr(final_string[line],"CN1CC1CN1") || strstr(final_string[line],"CN1CH1CN1") || strstr(final_string[line],"CN1CO1CN1") || strstr(final_string[line],"CN1CN1CN1") || strstr(final_string[line],"CN1CS1CN1") || strstr(final_string[line],"CN1CF1CN1") || strstr(final_string[line],"CN1Cl1CN1") || strstr(final_string[line],"CN1CB1CN1") || strstr(final_string[line],"CN1CI1CN1")))
                                {
                                        if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strchr(strings_array[f.b-1],'2')==NULL &&
					  strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strchr(strings_array[f.d-1],'2')==NULL)
                                                strcat(final_string[line],"IMZ");

                                        //if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strchr(strings_array[f.c-1],'2')==NULL)
                                                //strcat(final_string[line],"IMZ");

                                        //if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strchr(strings_array[f.d-1],'2')==NULL)
                                                //strcat(final_string[line],"IMZ");
                                        if(strstr(strings_array[f.b-1],"NC2") || strstr(strings_array[f.c-1],"NC2") || strstr(strings_array[f.d-1],"NC2"))
                                                strcat(final_string[line],"NOT");
                                }

                	}
		
			//When central C-atom contains C=N bond, but the attached N do not contain any N=C bond	
			if(strncmp(final_string[line],"C",1)==0 && strstr(final_string[line],"CN2") && strstr(final_string[line],"CN1"))
			{
					if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][8]=='1' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.d-1],'2')==NULL) //When C-atom contains C=N, but the attached N do not contain any N=C bond
                                                strcat(final_string[line],"IMZ");
					//if(strncmp(strings_array[f.b-1],"N",1)==0 && strchr(strings_array[f.b-1],'2'))
					//	strcat(final_string[line],"NOT");

                                        //if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strchr(strings_array[f.c-1],'2')==NULL && strstr(strings_array[f.c-1],"5MR"))
					if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][8]=='1' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.d-1],'2')==NULL) //When C-atom contains C=N, but the attached N do not contain any N=C bond
                                                strcat(final_string[line],"IMZ");
					
					if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][8]=='1' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.c-1],'2')==NULL) //When C-atom contains C=N, but the attached N do not contain any N=C bond
                                                strcat(final_string[line],"IMZ");
			}


		
			line++;
	}
	for (int k=0; k<line; k++)
		fprintf(fw,"%s\n",final_string[k]);

	fclose(fr);
}

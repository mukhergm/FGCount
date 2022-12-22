/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 *Purpose: This program will concatenate Phosphorus (P) atom types with all the neighbouring group atom types which are attach with P atom
 *Say, in Fosinopril molecule, there is one P atom which is connected with two carbons atoms and one double bonded oxygen and one single bonded oxygen. Therefore, the primary atom types of P atom:
 *PC1PC1PO1PO2
 *This program will concatenate all the neighbouring group atom types which are attach with P atom. It means,
 *The atom types of two carbon atoms and two oxygen atoms will be concatenated with the central P atom by this program. The final atom type of P atom:
 *PC1PC1PO1PO2 CC1CP1CH1CH1 CC1CP1CH1CH1 OC1OP1 OP2
 * How to run:
 * ./logp_mr_calc_6.exe <Output file of logp_mr_calc_5.exe> <Output file of lp3.exe> <Output file name> 
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
  	printf("./logp_mr_calc_6.exe <Output file of logp_mr_calc_5.exe> <Output file of lp3.exe> <Output file name>\n");
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
	char final_string[300][100];
 	char *result;	
	fp=fopen(argv[1],"r");
	fr=fopen(argv[2],"r");
	fw=fopen(argv[3],"w");
		
	if (fw==NULL)            
        {
        printf("logp_mr_calc_6.exe: Cannot write output. No output file name is given\n");
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
                if(strncmp(final_string[line],"P",1)==0){       	                
	        strncat(final_string[line],strings_array[f.b-1],18);          
	        strncat(final_string[line],strings_array[f.c-1],18);
                strncat(final_string[line],strings_array[f.d-1],18);
		strncat(final_string[line],strings_array[f.e-1],18);
		strncat(final_string[line],strings_array[f.f-1],18);}
		//strncat(final_string[line],strings_array[f.g-1],18);
                fprintf(fw,"%s\n",final_string[line]);
		
		

		line++;
	        
              
              //printf("%s\n",final_string[line]);
          }
          

	fclose(fp);
	fclose(fr);

}


/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 *Purpose: Format a pdf file of ligand (non-standard) molecule.
 * How to run:
 * ./pdbtopdb.exe <ligand name with extension (.pdb)> <output.pdb>
 * say,
 * ./pdb2pdb.exe ligand.pdb output.pdb
 * This programme conver a non-standard to standard pdb format
 * The information about standard pdb format can be found at 
 * http://www.scfbio-iitd.res.in/software/drugdesign/PDBFormat.pdf
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
int main(int argc, char *argv[])
	{
	FILE *fr,*fw;
	if (argc<2) {
 	 printf("./pdb2pdb.exe <ligand name with extension (.pdb)> <output.pdb>\n");
	 exit(1);
	}
char s[100];
int i=1,l=1;
char drg[4]="DRG";

char ATOM1[] = "AT";
char ATOM2[] = "OM";
strcat (ATOM1, ATOM2);
char t[4];
int atomno,r;
char xcod[8],ycod[8],zcod[8];
char atmsmb[3];
float xcod1=0,ycod1=0,zcod1=0;

fr=fopen(argv[1],"r");
fw=fopen(argv[2],"w");

	if (fw==NULL)            
        {
        printf("pdb2pdb.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }

while(fgets(s,100,fr)!=NULL)
	{
	if(strncmp(s,"ATOM",4)==0||strncmp(s,"HETATM",6)==0)
		{
		t[0]=s[12];
		t[1]=s[13];
		t[2]=s[14];
		t[3]=s[15];
		t[4]='\0';
//C
		if((strncmp(t,"C",1)==0 || strncmp(t," C",2)==0 || strncmp(t,"1C",2)==0 || strncmp(t,"2C",2)==0 || strncmp(t,"3C",2)==0 || strncmp(t,"4C",2)==0 || strncmp(t,"5C",2)==0 || strncmp(t,"6C",2)==0 || strncmp(t,"7C",2)==0 || strncmp(t,"8C",2)==0 || strncmp(t,"9C",2)==0 || strncmp(t,"0C",2)==0 || strncmp(t,"*C",2)==0 || strncmp(t,"'C",2)==0) && strstr(t,"Cl")==NULL && strstr(t,"CL")==NULL && strstr(s,"Co")==NULL && strstr(s,"Cr")==NULL && strstr(s,"Cu")==NULL && strstr(s,"Cd")==NULL && strstr(s,"Ca")==NULL)
		strcpy(atmsmb,"C");

//Cl
		else if(strstr(t,"Cl") || strstr(t,"CL"))
		strcpy(atmsmb,"Cl");
//N
		else if((strncmp(t,"N",1)==0 || strncmp(t," N",2)==0 || strncmp(t,"1N",2)==0 || strncmp(t,"2N",2)==0 || strncmp(t,"3N",2)==0 || strncmp(t,"4N",2)==0 || strncmp(t,"5N",2)==0 || strncmp(t,"6N",2)==0 || strncmp(t,"7N",2)==0 || strncmp(t,"8N",2)==0 || strncmp(t,"9N",2)==0 || strncmp(t,"0N",2)==0 || strncmp(t,"*N",2)==0 || strncmp(t,"'N",2)==0) && strstr(s,"Ni")==NULL && strstr(s,"Na")==NULL)
		strcpy(atmsmb,"N");
//Br
		else if(strstr(t,"Br") || strstr(t,"BR"))
		strcpy(atmsmb,"Br");
//F
		else if((strncmp(t,"F",1)==0 || strncmp(t," F",2)==0 || strncmp(t,"1F",2)==0 || strncmp(t,"2F",2)==0 || strncmp(t,"3F",2)==0 || strncmp(t,"4F",2)==0 || strncmp(t,"5F",2)==0 || strncmp(t,"6F",2)==0 || strncmp(t,"7F",2)==0 || strncmp(t,"8F",2)==0 || strncmp(t,"9F",2)==0 || strncmp(t,"0F",2)==0 || strncmp(t,"*F",2)==0 || strncmp(t,"'F",2)==0) && strstr(s,"Fe")==NULL)
		strcpy(atmsmb,"F");
//I
		else if((strncmp(t,"I",1)==0 || strncmp(t," I",2)==0 || strncmp(t,"1I",2)==0 || strncmp(t,"2I",2)==0 || strncmp(t,"3I",2)==0 || strncmp(t,"4I",2)==0 || strncmp(t,"5I",2)==0 || strncmp(t,"6I",2)==0 || strncmp(t,"7I",2)==0 || strncmp(t,"8I",2)==0 || strncmp(t,"9I",2)==0 || strncmp(t,"0I",2)==0 || strncmp(t,"*I",2)==0 || strncmp(t,"'I",2)==0) && strstr(t,"In")==NULL && strstr(t,"Ir")==NULL)
		strcpy(atmsmb,"I");
//O
		else if((strncmp(t,"O",1)==0 || strncmp(t," O",2)==0 || strncmp(t,"1O",2)==0 || strncmp(t,"2O",2)==0 || strncmp(t,"3O",2)==0 || strncmp(t,"4O",2)==0 || strncmp(t,"5O",2)==0 || strncmp(t,"6O",2)==0 || strncmp(t,"7O",2)==0 || strncmp(t,"8O",2)==0 || strncmp(t,"9O",2)==0 || strncmp(t,"0O",2)==0 || strncmp(t,"*O",2)==0 || strncmp(t,"'O",2)==0) && strstr(t,"Os")==NULL)
		strcpy(atmsmb,"O");
//S
		else if((strncmp(t,"S",1)==0 || strncmp(t," S",2)==0 || strncmp(t,"1S",2)==0 || strncmp(t,"2S",2)==0 || strncmp(t,"3S",2)==0 || strncmp(t,"4S",2)==0 || strncmp(t,"5S",2)==0 || strncmp(t,"6S",2)==0 || strncmp(t,"7S",2)==0 || strncmp(t,"8S",2)==0 || strncmp(t,"9S",2)==0 || strncmp(t,"0S",2)==0 || strncmp(t,"*S",2)==0 || strncmp(t,"'S",2)==0) && strstr(t,"SE")==NULL && strstr(t,"Se")==NULL && strstr(t,"SI")==NULL && strstr(t,"Si")==NULL && strstr(t,"Sb")==NULL && strstr(t,"SN")==NULL && strstr(t,"Sn")==NULL)
		strcpy(atmsmb,"S");
//P
		else if((strncmp(t,"P",1)==0 || strncmp(t," P",2)==0 || strncmp(t,"1P",2)==0 || strncmp(t,"2P",2)==0 || strncmp(t,"3P",2)==0 || strncmp(t,"4P",2)==0 || strncmp(t,"5P",2)==0 || strncmp(t,"6P",2)==0 || strncmp(t,"7P",2)==0 || strncmp(t,"8P",2)==0 || strncmp(t,"9P",2)==0 || strncmp(t,"0P",2)==0 || strncmp(t,"*P",2)==0 || strncmp(t,"'P",2)==0) && strstr(t,"Pb")==NULL && strstr(t,"Pd")==NULL && strstr(t,"Pt")==NULL)
		strcpy(atmsmb,"P");
//H
		else if((strncmp(t,"H",1)==0 || strncmp(t," H",2)==0 || strncmp(t,"1H",2)==0 || strncmp(t,"2H",2)==0 || strncmp(t,"3H",2)==0 || strncmp(t,"4H",2)==0 || strncmp(t,"5H",2)==0 || strncmp(t,"6H",2)==0 || strncmp(t,"7H",2)==0 || strncmp(t,"8H",2)==0 || strncmp(t,"9H",2)==0 || strncmp(t,"0H",2)==0 || strncmp(t,"*H",2)==0 || strncmp(t,"'H",2)==0) && strstr(t,"Hg")==NULL)
		strcpy(atmsmb,"H");

//B	
		else if((strncmp(t,"B",1)==0 || strncmp(t," B",2)==0 || strncmp(t,"1B",2)==0 || strncmp(t,"2B",2)==0 || strncmp(t,"3B",2)==0 || strncmp(t,"4B",2)==0 || strncmp(t,"5B",2)==0 || strncmp(t,"6B",2)==0 || strncmp(t,"7B",2)==0 || strncmp(t,"8B",2)==0 || strncmp(t,"9B",2)==0 || strncmp(t,"0B",2)==0) && strstr(t,"BR")==NULL && strstr(t,"Br")==NULL && strstr(t,"CB")==NULL && strstr(t,"NB")==NULL && strstr(t,"OB")==NULL && strstr(t,"PB")==NULL && strstr(t,"SB")==NULL && strstr(t,"IB")==NULL && strstr(t,"HB")==NULL && strstr(t,"Be")==NULL)
		strcpy(atmsmb,"B");

//Se
		else if(strstr(t,"Se") || strstr(t,"SE"))
                strcpy(atmsmb,"Se");
//Te
		else if(strstr(t,"Te") || strstr(t,"TE"))
                strcpy(atmsmb,"Te");	

//Al
		else if(strstr(t,"AL") || strstr(t,"Al"))
                strcpy(atmsmb,"Al");

//Sn
		else if(strstr(t,"Sn") || strstr(t,"SN"))
                strcpy(atmsmb,"Sn");

//Pb
		else if(strstr(t,"Pb"))
                strcpy(atmsmb,"Pb");

//K
		else if(strstr(t,"K"))
                strcpy(atmsmb,"K");

//Ge
		else if(strstr(t,"GE") || strstr(t,"Ge"))
                strcpy(atmsmb,"Ge");
//GA
		else if(strstr(t,"GA") || strstr(t,"GA"))
                strcpy(atmsmb,"GA");

//In
		else if(strstr(t,"In"))
                strcpy(atmsmb,"In");
//Tl
		else if(strstr(t,"Tl") || strstr(t,"TL"))
                strcpy(atmsmb,"Tl");

//GD
		else if(strstr(t,"GD") || strstr(t,"Gd"))
                strcpy(atmsmb,"Gd");
//Mg
		else if(strstr(t,"MG") || strstr(t,"Mg"))
		strcpy(atmsmb,"Mg");
//Mn
		else if(strstr(t,"MN") || strstr(t,"Mn"))
                strcpy(atmsmb,"Mn");		
//Ag
		else if(strstr(t,"AG") || strstr(t,"Ag"))
                strcpy(atmsmb,"Ag");
//Au
		else if(strstr(t,"AU") || strstr(t,"Au"))
                strcpy(atmsmb,"Au");		
//Zn
		else if(strstr(t,"ZN") || strstr(t,"Zn"))
                strcpy(atmsmb,"Zn");
//Ti
		else if(strstr(t,"TI") || strstr(t,"Ti"))
                strcpy(atmsmb,"Ti");
//Si
		else if(strstr(t,"SI") || strstr(t,"Si"))
                strcpy(atmsmb,"Si");		
//As
		else if(strstr(t,"AS") || strstr(t,"As"))
                strcpy(atmsmb,"As");

//Sb
		else if(strstr(t,"Sb") || strstr(t,"SB"))
                strcpy(atmsmb,"Sb");

//Co
		else if(strstr(t,"Co"))
                strcpy(atmsmb,"Co");

//Cr
		else if(strstr(t,"Cr"))
                strcpy(atmsmb,"Cr");
//Cu	
		else if(strstr(t,"Cu"))
                strcpy(atmsmb,"Cu");

//Ni
		else if(strstr(t,"Ni"))
                strcpy(atmsmb,"Ni");	

//Fe
		else if(strstr(t,"Fe"))
                strcpy(atmsmb,"Fe");	

//Cd
		else if(strstr(t,"Cd"))
                strcpy(atmsmb,"Cd");
	
//Os
		else if(strstr(t,"Os"))
                strcpy(atmsmb,"Os");

//Ir
		else if(strstr(t,"Ir"))
                strcpy(atmsmb,"Ir");	

//Pd
		else if(strstr(t,"Pd"))
                strcpy(atmsmb,"Pd");

//Pt
		else if(strstr(t,"Pt"))
                strcpy(atmsmb,"Pt");

//Rh
		else if(strstr(t,"Rh") || strstr(t,"RH"))
                strcpy(atmsmb,"Rh");

//Ru
		else if(strstr(t,"Ru") || strstr(t,"RU"))
                strcpy(atmsmb,"Ru");

//Mo
		else if(strstr(t,"Mo") || strstr(t,"MO"))
                strcpy(atmsmb,"Mo");

//W
		else if(strstr(t,"W"))
                strcpy(atmsmb,"W");
//Na
		else if(strstr(t,"Na"))
                strcpy(atmsmb,"Na");
//Ca
		else if(strstr(t,"Ca"))
                strcpy(atmsmb,"Ca");

//Be
		else if(strstr(t,"Be"))
                strcpy(atmsmb,"Be");

		else
			strcpy(atmsmb,"V");

		xcod[0]=s[30];
		xcod[1]=s[31];
		xcod[2]=s[32];
		xcod[3]=s[33];
		xcod[4]=s[34];
		xcod[5]=s[35];
		xcod[6]=s[36];
		xcod[7]=s[37];
		xcod[8]='\0';
		xcod1=atof(xcod);

		ycod[0]=s[38];
		ycod[1]=s[39];
		ycod[2]=s[40];
		ycod[3]=s[41];
		ycod[4]=s[42];
		ycod[5]=s[43];
		ycod[6]=s[44];
		ycod[7]=s[45];
		ycod[8]='\0';
		ycod1=atof(ycod);
		
		zcod[0]=s[46];
		zcod[1]=s[47];
		zcod[2]=s[48];
		zcod[3]=s[49];
		zcod[4]=s[50];
		zcod[5]=s[51];
		zcod[6]=s[52];
		zcod[7]=s[53];
		zcod[8]='\0';
		zcod1=atof(zcod);

		fprintf(fw,"%-6s%5d%3s   %3s    %2d    %8.3f%8.3f%8.3f \n",ATOM1,l,atmsmb,drg,i,xcod1,ycod1,zcod1);
		l++;
		}
	}

fclose(fr);
}

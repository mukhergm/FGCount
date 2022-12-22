/*
 * Written by Goutam Mukherjee
 * Purpose: Calculate moleular weight of small drug-like molecule
 * Input is a pdb file without chain information of a ligand
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
FILE *fp;
if (argc<2) {
  printf("./mass.exe <Input pdb file>\n");
  exit(1);
}

	float sum=0;
	char str[100];
	float x2,y2,z2;
    	
	float   H = 1.008, HE = 4.003, LI = 6.941, BE = 9.012, B = 10.811,\
                C = 12.011, N = 14.007, O = 15.999, F = 18.998, NE = 20.180,\
                NA = 22.990, MG = 24.305,\
                AL = 26.982, SI = 28.086, P = 30.974, S = 32.066,\
                CL = 35.453, AR = 39.948, K = 39.098, CA = 40.078,\
                SC = 44.956, TI = 47.867, V = 50.942, CR = 51.996,\
                MN = 54.938, FE = 55.845, CO = 58.933, NI = 58.693,\
                CU = 63.546, ZN = 65.38, GA = 69.723, GE = 72.631,\
                AS = 74.922, SE = 78.971, BR = 79.904, KR = 84.798,\
                RB = 84.468, SR = 87.62, Y = 88.906, ZR = 91.224,\
                NB = 92.906, MO = 95.95, TC = 98.907, RU = 101.07,\
                RH = 102.906, PD = 106.42, AG = 107.868, CD = 112.414,
                IN = 114.818, SN = 118.711, SB = 121.760, TE = 126.7,\
                I = 126.904, XE = 131.294, CS = 132.905, BA = 137.328,\
                LA = 138.905, CE = 140.116, PR = 140.908, ND = 144.243,\
                PM = 144.913, SM = 150.36, EU = 151.964, GD = 157.25,\
                TB = 158.925, DY= 162.500, HO = 164.930, ER = 167.259,\
                TM = 168.934, YB = 173.055, LU = 174.967, HF = 178.49,\
                TA = 180.948, W = 183.84, RE = 186.207, OS = 190.23,\
                IR = 192.217, PT = 195.085, AU = 196.967, HG = 200.592,\
                TL = 204.383, PB = 207.2, BI = 208.980, PO = 208.982,\
                AT = 209.987, RN = 222.081, FR = 223.020, RA = 226.025,\
                AC = 227.028, TH = 232.038, PA = 231.036, U = 238.029,\
                NP = 237, PU = 244, AM = 243, CM = 247, BK = 247,\
                CT = 251, ES = 252, FM = 257, MD = 258, NO = 259,\
                LR = 262, RF = 261, DB = 262, SG = 266, BH = 264,\
                HS = 269, MT = 268, DS = 271, RG = 272, CN = 285,\
                NH = 284, FL = 289, MC = 288, LV = 292, TS = 294,\
                OG = 294;

	char atom[10],atomsmb[6],d[6];
	int atomno,r;
	fp=fopen(argv[1],"r");
	while(fgets(str,100,fp)!=NULL)
		{
			if(strncmp(str,"ATOM",4)==0 || strncmp(str,"HETATM",6)==0)
			{
				sscanf(str,"%s%d%s%s%d%f%f%f",atom,&atomno,atomsmb,d,&r,&x2,&y2,&z2);
	                	if(strstr(atomsmb,"H") && strlen(atomsmb)<2)
                			sum=sum+H;
				else if(strstr(atomsmb,"C") && strlen(atomsmb)<2)
                			sum=sum+C;
				else if(strstr(atomsmb,"N") && strlen(atomsmb)<2)
					sum=sum+N;
				else if(strstr(atomsmb,"O") && strlen(atomsmb)<2)
					sum=sum+O;
				else if(strstr(atomsmb,"P") && strlen(atomsmb)<2)
					sum=sum+P;
				else if(strstr(atomsmb,"S") && strlen(atomsmb)<2)
					sum=sum+S;
				else if(strstr(atomsmb,"F") && strlen(atomsmb)<2)
					sum=sum+F;
				else if(strstr(atomsmb,"CL") || strstr(atomsmb,"Cl"))
					sum=sum+CL;
				else if(strstr(atomsmb,"BR") || strstr(atomsmb,"Br"))
					sum=sum+BR;
				else if(strstr(atomsmb,"I") && strlen(atomsmb)<2)
					sum=sum+I;
				else if(strstr(atomsmb,"LI") || strstr(atomsmb,"Li"))
					sum=sum+LI;
				else if(strstr(atomsmb,"NA") || strstr(atomsmb,"Na"))
					sum=sum+NA;
				else if(strstr(atomsmb,"MG") || strstr(atomsmb,"Mg"))
					sum=sum+MG;
				else if(strstr(atomsmb,"AL") || strstr(atomsmb,"Al"))
					sum=sum+AL;
				else if(strstr(atomsmb,"K") && strlen(atomsmb)<2)
					sum=sum+K;
				else if(strstr(atomsmb,"CA") || strstr(atomsmb,"Ca"))
					sum=sum+CA;
				else if(strstr(atomsmb,"BE") || strstr(atomsmb,"Be"))
					sum=sum+BE;
				else if(strstr(atomsmb,"B") && strlen(atomsmb)<2)
					sum=sum+B;
				else if(strstr(atomsmb,"SI") || strstr(atomsmb,"Si"))
					sum=sum+SI;
				else if(strstr(atomsmb,"SC") || strstr(atomsmb,"Sc"))
					sum=sum+SC;
				else if(strstr(atomsmb,"TI") || strstr(atomsmb,"Ti"))
					sum=sum+TI;
				else if(strstr(atomsmb,"V") && strlen(atomsmb)<2)
					sum=sum+V;
				else if(strstr(atomsmb,"CR") || strstr(atomsmb,"Cr"))
					sum=sum+CR;
				else if(strstr(atomsmb,"MN") || strstr(atomsmb,"Mn"))
					sum=sum+MN;
				else if(strstr(atomsmb,"FE") || strstr(atomsmb,"Fe"))
					sum=sum+FE;
				else if(strstr(atomsmb,"CO") || strstr(atomsmb,"Co"))
					sum=sum+CO;
				else if(strstr(atomsmb,"NI") || strstr(atomsmb,"Ni"))
					sum=sum+NI;
				else if(strstr(atomsmb,"CU") || strstr(atomsmb,"Cu"))
					sum=sum+CU;
				else if(strstr(atomsmb,"ZN") || strstr(atomsmb,"Zn"))
					sum=sum+ZN;
				else if(strstr(atomsmb,"GA") || strstr(atomsmb,"Ga"))
					sum=sum+GA;
				else if(strstr(atomsmb,"GE") || strstr(atomsmb,"Ge"))
					sum=sum+GE;
				else if(strstr(atomsmb,"AS") || strstr(atomsmb,"As"))
					sum=sum+AS;
				else if(strstr(atomsmb,"SE") || strstr(atomsmb,"Se"))
					sum=sum+SE;
				else if(strstr(atomsmb,"KR") || strstr(atomsmb,"Kr"))
					sum=sum+KR;
				else if(strstr(atomsmb,"RB") || strstr(atomsmb,"Rb"))
					sum=sum+RB;
				else if(strstr(atomsmb,"SR") || strstr(atomsmb,"Sr"))
					sum=sum+SR;
				else if(strstr(atomsmb,"Y") && strlen(atomsmb)<2)
					sum=sum+Y;
				else if(strstr(atomsmb,"ZR") || strstr(atomsmb, "Zr"))
					sum=sum+ZR;
				else if(strstr(atomsmb,"NB") || strstr(atomsmb, "Nb"))
					sum=sum+NB;
				else if(strstr(atomsmb,"MO") || strstr(atomsmb, "Mo"))
					sum=sum+MO;
				else if(strstr(atomsmb,"TC") || strstr(atomsmb, "Tc"))
					sum=sum+TC;
				else if(strstr(atomsmb,"RU") || strstr(atomsmb, "Ru"))
					sum=sum+RU;
				else if(strstr(atomsmb,"RH") || strstr(atomsmb, "Rh"))
					sum=sum+RH;
				else if(strstr(atomsmb,"PD") || strstr(atomsmb, "Pd"))
					sum=sum+PD;
				else if(strstr(atomsmb,"AG") || strstr(atomsmb, "Ag"))
					sum=sum+AG;
				else if(strstr(atomsmb,"CD") || strstr(atomsmb, "Cd"))
					sum=sum+CD;
				else if(strstr(atomsmb,"IN") || strstr(atomsmb, "In"))
					sum=sum+IN;
				else if(strstr(atomsmb,"SN") || strstr(atomsmb, "Sn"))
					sum=sum+SN;
				else if(strstr(atomsmb,"SB") || strstr(atomsmb, "Sb"))
					sum=sum+SB;
				else if(strstr(atomsmb,"TE") || strstr(atomsmb, "Te"))
					sum=sum+TE;
				else if(strstr(atomsmb,"CS") || strstr(atomsmb, "Cs"))
					sum=sum+CS;
				else if(strstr(atomsmb,"BA") || strstr(atomsmb, "Ba"))
					sum=sum+BA;
				else if(strstr(atomsmb,"LA") || strstr(atomsmb, "La"))
					sum=sum+LA;
				else if(strstr(atomsmb,"CE") || strstr(atomsmb, "Ce"))
					sum=sum+CE;
				else if(strstr(atomsmb,"PR") || strstr(atomsmb, "Pr"))
					sum=sum+PR;
				else if(strstr(atomsmb,"ND") || strstr(atomsmb, "Nd"))
					sum=sum+ND;
				else if(strstr(atomsmb,"PM") || strstr(atomsmb, "Pm"))
					sum=sum+PM;
				else if(strstr(atomsmb,"SM") || strstr(atomsmb, "Sm"))
					sum=sum+SM;
				else if(strstr(atomsmb,"EU") || strstr(atomsmb, "Eu"))
					sum=sum+EU;
				else if(strstr(atomsmb,"GD") || strstr(atomsmb, "Gd"))
					sum=sum+GD;
				else if(strstr(atomsmb,"TB") || strstr(atomsmb, "Tb"))
					sum=sum+TB;
				else if(strstr(atomsmb,"DY") || strstr(atomsmb, "Dy"))
					sum=sum+DY;
				else if(strstr(atomsmb,"HO") || strstr(atomsmb, "Ho"))
					sum=sum+HO;
				else if(strstr(atomsmb,"ER") || strstr(atomsmb, "Er"))
					sum=sum+ER;
				else if(strstr(atomsmb,"TM") || strstr(atomsmb, "Tm"))
					sum=sum+TM;
				else if(strstr(atomsmb,"YB") || strstr(atomsmb, "Yb"))
					sum=sum+YB;
				else if(strstr(atomsmb,"LU") || strstr(atomsmb, "Lu"))
					sum=sum+LU;
				else if(strstr(atomsmb,"HF") || strstr(atomsmb, "Hf"))
					sum=sum+HF;
				else if(strstr(atomsmb,"TA") || strstr(atomsmb, "Ta"))
					sum=sum+TA;
				else if(strstr(atomsmb,"RE") || strstr(atomsmb, "Re"))
					sum=sum+RE;
				else if(strstr(atomsmb,"OS") || strstr(atomsmb, "Os"))
					sum=sum+OS;
				else if(strstr(atomsmb,"W") && strlen(atomsmb)<2)
					sum=sum+W;
				else if(strstr(atomsmb,"IR") || strstr(atomsmb, "Ir"))
					sum=sum+IR;
				else if(strstr(atomsmb,"PT") || strstr(atomsmb, "Pt"))
					sum=sum+PT;
				else if(strstr(atomsmb,"AU") || strstr(atomsmb, "Au"))
					sum=sum+AU;
				else if(strstr(atomsmb,"HG") || strstr(atomsmb, "HG"))
					sum=sum+HG;
				else if(strstr(atomsmb,"TL") || strstr(atomsmb, "Tl"))
					sum=sum+TL;
				else if(strstr(atomsmb,"PB") || strstr(atomsmb, "Pb"))
					sum=sum+PB;
				else if(strstr(atomsmb,"BI") || strstr(atomsmb, "Bi"))
					sum=sum+BI;
				else if(strstr(atomsmb,"PO") || strstr(atomsmb, "Po"))
					sum=sum+PO;
				else if(strstr(atomsmb,"AT") || strstr(atomsmb, "At"))
					sum=sum+AT;
				else if(strstr(atomsmb,"RN") || strstr(atomsmb, "Rn"))
					sum=sum+RN;
				else if(strstr(atomsmb,"FR") || strstr(atomsmb, "Fr"))
					sum=sum+FR;
				else if(strstr(atomsmb,"RA") || strstr(atomsmb, "Ra"))
					sum=sum+RA;
				else if(strstr(atomsmb,"AC") || strstr(atomsmb, "Ac"))
					sum=sum+AC;
				else if(strstr(atomsmb,"U") && strlen(atomsmb)<2)
					sum=sum+U;
				else if(strstr(atomsmb,"TH") || strstr(atomsmb, "Th"))
					sum=sum+TH;
				else if(strstr(atomsmb,"PA") || strstr(atomsmb, "Pa"))
					sum=sum+PA;
				else if(strstr(atomsmb,"NP") || strstr(atomsmb, "Np"))
					sum=sum+NP;
				else if(strstr(atomsmb,"PU") || strstr(atomsmb, "Pu"))
					sum=sum+PU;
				else if(strstr(atomsmb,"AM") || strstr(atomsmb, "Am"))
					sum=sum+AM;
				else if(strstr(atomsmb,"CM") || strstr(atomsmb, "Cm"))
					sum=sum+CM;
				else if(strstr(atomsmb,"BK") || strstr(atomsmb, "Bk"))
					sum=sum+BK;
				else
					sum=sum+0;

		}
	}
printf("%0.2f\n",sum);
fclose(fp);
}

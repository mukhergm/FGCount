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
    float m;

    char atom[10],residuename[6],atomsmb[6];
    int atomno,r;
    fp=fopen(argv[1],"r");
    int ln=1;
    float 	H = 1.008, HE = 4.003, LI = 6.941, BE = 9.012, B = 10.811,\
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
while(fgets(str,100,fp)!=NULL)
	{
	if(strncmp(str,"ATOM",4)==0 || strncmp(str,"HETATM",6)==0)
		{
		sscanf(str,"%s%d%s%s%d%f%f%f",atom,&atomno,atomsmb,residuename,&r,&x2,&y2,&z2);
		//printf("%s\n", atomsmb);
                if(strstr(atomsmb,"H") && strlen(atomsmb)<2)
                printf("%0.3f\n", H);
		else if(strstr(atomsmb,"C") && strlen(atomsmb)<2)
                printf("%0.3f\n", C);
		else if(strstr(atomsmb,"N") && strlen(atomsmb)<2)
                printf("%0.3f\n", N);
		else if(strstr(atomsmb,"O") && strlen(atomsmb)<2)
                printf("%0.3f\n", O);
		else if(strstr(atomsmb,"P") && strlen(atomsmb)<2)
                printf("%0.3f\n", P);
		else if(strstr(atomsmb,"S") && strlen(atomsmb)<2)
                printf("%0.3f\n", S);
		else if(strstr(atomsmb,"F") && strlen(atomsmb)<2)
                printf("%0.3f\n", F);
		else if(strstr(atomsmb,"CL") || strstr(atomsmb,"Cl"))
                printf("%0.3f\n", CL);
		else if(strstr(atomsmb,"BR") || strstr(atomsmb,"Br"))
		printf("%0.3f\n", BR);
		else if(strstr(atomsmb,"I") && strlen(atomsmb)<2)
		printf("%0.3f\n", I);
		else if(strstr(atomsmb,"LI") || strstr(atomsmb,"Li"))
                printf("%0.3f\n", LI);
		else if(strstr(atomsmb,"NA") || strstr(atomsmb,"Na"))
                printf("%0.3f\n", NA);
		else if(strstr(atomsmb,"MG") || strstr(atomsmb,"Mg"))
                printf("%0.3f\n", MG);
		else if(strstr(atomsmb,"AL") || strstr(atomsmb,"Al"))
                printf("%0.3f\n", AL);
		else if(strstr(atomsmb,"K") && strlen(atomsmb)<2)
                printf("%0.3f\n", K);
		else if(strstr(atomsmb,"CA") || strstr(atomsmb,"Ca"))
                printf("%0.3f\n", CA);
		else if(strstr(atomsmb,"BE") || strstr(atomsmb,"Be"))
                printf("%0.3f\n", BE);
		else if(strstr(atomsmb,"B") && strlen(atomsmb)<2)
                printf("%0.3f\n", B);
		else if(strstr(atomsmb,"SI") || strstr(atomsmb,"Si"))
                printf("%0.3f\n", SI);
		else if(strstr(atomsmb,"SC") || strstr(atomsmb,"Sc"))
                printf("%0.3f\n", SC);
		else if(strstr(atomsmb,"TI") || strstr(atomsmb,"Ti"))
                printf("%0.3f\n", TI);
		else if(strstr(atomsmb,"V") && strlen(atomsmb)<2)
                printf("%0.3f\n", V);
		else if(strstr(atomsmb,"CR") || strstr(atomsmb,"Cr"))
                printf("%0.3f\n", CR);
		else if(strstr(atomsmb,"MN") || strstr(atomsmb,"Mn"))
                printf("%0.3f\n", MN);
		else if(strstr(atomsmb,"FE") || strstr(atomsmb,"Fe"))
                printf("%0.3f\n", FE);
		else if(strstr(atomsmb,"CO") || strstr(atomsmb,"Co"))
                printf("%0.3f\n", CO);
		else if(strstr(atomsmb,"NI") || strstr(atomsmb,"Ni"))
                printf("%0.3f\n", NI);
		else if(strstr(atomsmb,"CU") || strstr(atomsmb,"Cu"))
                printf("%0.3f\n", CU);
		else if(strstr(atomsmb,"ZN") || strstr(atomsmb,"Zn"))
                printf("%0.3f\n", ZN);
		else if(strstr(atomsmb,"GA") || strstr(atomsmb,"Ga"))
                printf("%0.3f\n", GA);
		else if(strstr(atomsmb,"GE") || strstr(atomsmb,"Ge"))
                printf("%0.3f\n", GE);
		else if(strstr(atomsmb,"AS") || strstr(atomsmb,"As"))
                printf("%0.3f\n", AS);
		else if(strstr(atomsmb,"SE") || strstr(atomsmb,"Se"))
                printf("%0.3f\n", SE);
		else if(strstr(atomsmb,"KR") || strstr(atomsmb,"Kr"))
                printf("%0.3f\n", KR);
		else if(strstr(atomsmb,"RB") || strstr(atomsmb,"Rb"))
                printf("%0.3f\n", RB);
		else if(strstr(atomsmb,"SR") || strstr(atomsmb,"Sr"))
                printf("%0.3f\n", SR);
		else if(strstr(atomsmb,"Y") && strlen(atomsmb)<2)
                printf("%0.3f\n", Y);
		else if(strstr(atomsmb,"ZR") || strstr(atomsmb, "Zr"))
                printf("%0.3f\n", ZR);
		else if(strstr(atomsmb,"NB") || strstr(atomsmb, "Nb"))
                printf("%0.3f\n", NB);
		else if(strstr(atomsmb,"MO") || strstr(atomsmb, "Mo"))
                printf("%0.3f\n", MO);
		else if(strstr(atomsmb,"TC") || strstr(atomsmb, "Tc"))
                printf("%0.3f\n", TC);
		else if(strstr(atomsmb,"RU") || strstr(atomsmb, "Ru"))
                printf("%0.3f\n", RU);
		else if(strstr(atomsmb,"RH") || strstr(atomsmb, "Rh"))
                printf("%0.3f\n", RH);
		else if(strstr(atomsmb,"PD") || strstr(atomsmb, "Pd"))
                printf("%0.3f\n", PD);
		else if(strstr(atomsmb,"AG") || strstr(atomsmb, "Ag"))
                printf("%0.3f\n", AG);
		else if(strstr(atomsmb,"CD") || strstr(atomsmb, "Cd"))
                printf("%0.3f\n", CD);
		else if(strstr(atomsmb,"IN") || strstr(atomsmb, "In"))
                printf("%0.3f\n", IN);
		else if(strstr(atomsmb,"SN") || strstr(atomsmb, "Sn"))
                printf("%0.3f\n", SN);
		else if(strstr(atomsmb,"SB") || strstr(atomsmb, "Sb"))
                printf("%0.3f\n", SB);
		else if(strstr(atomsmb,"TE") || strstr(atomsmb, "Te"))
                printf("%0.3f\n", TE);
		else if(strstr(atomsmb,"CS") || strstr(atomsmb, "Cs"))
                printf("%0.3f\n", CS);
		else if(strstr(atomsmb,"BA") || strstr(atomsmb, "Ba"))
                printf("%0.3f\n", BA);
		else if(strstr(atomsmb,"LA") || strstr(atomsmb, "La"))
                printf("%0.3f\n", LA);
		else if(strstr(atomsmb,"CE") || strstr(atomsmb, "Ce"))
                printf("%0.3f\n", CE);
		else if(strstr(atomsmb,"PR") || strstr(atomsmb, "Pr"))
                printf("%0.3f\n", PR);
		else if(strstr(atomsmb,"ND") || strstr(atomsmb, "Nd"))
                printf("%0.3f\n", ND);
		else if(strstr(atomsmb,"PM") || strstr(atomsmb, "Pm"))
                printf("%0.3f\n", PM);
		else if(strstr(atomsmb,"SM") || strstr(atomsmb, "Sm"))
                printf("%0.3f\n", SM);
		else if(strstr(atomsmb,"EU") || strstr(atomsmb, "Eu"))
                printf("%0.3f\n", EU);
		else if(strstr(atomsmb,"GD") || strstr(atomsmb, "Gd"))
                printf("%0.3f\n", GD);
		else if(strstr(atomsmb,"TB") || strstr(atomsmb, "Tb"))
                printf("%0.3f\n", TB);
		else if(strstr(atomsmb,"DY") || strstr(atomsmb, "Dy"))
                printf("%0.3f\n", DY);
		else if(strstr(atomsmb,"HO") || strstr(atomsmb, "Ho"))
                printf("%0.3f\n", HO);
		else if(strstr(atomsmb,"ER") || strstr(atomsmb, "Er"))
                printf("%0.3f\n", ER);
		else if(strstr(atomsmb,"TM") || strstr(atomsmb, "Tm"))
                printf("%0.3f\n", TM);
		else if(strstr(atomsmb,"YB") || strstr(atomsmb, "Yb"))
                printf("%0.3f\n", YB);
		else if(strstr(atomsmb,"LU") || strstr(atomsmb, "Lu"))
                printf("%0.3f\n", LU);
		else if(strstr(atomsmb,"HF") || strstr(atomsmb, "Hf"))
                printf("%0.3f\n", HF);
		else if(strstr(atomsmb,"TA") || strstr(atomsmb, "Ta"))
                printf("%0.3f\n", TA);
		else if(strstr(atomsmb,"RE") || strstr(atomsmb, "Re"))
                printf("%0.3f\n", RE);
		else if(strstr(atomsmb,"OS") || strstr(atomsmb, "Os"))
                printf("%0.3f\n", OS);
		else if(strstr(atomsmb,"W") && strlen(atomsmb)<2)
                printf("%0.3f\n", W);
		else if(strstr(atomsmb,"IR") || strstr(atomsmb, "Ir"))
                printf("%0.3f\n", IR);
		else if(strstr(atomsmb,"PT") || strstr(atomsmb, "Pt"))
                printf("%0.3f\n", PT);
		else if(strstr(atomsmb,"AU") || strstr(atomsmb, "Au"))
                printf("%0.3f\n", AU);
		else if(strstr(atomsmb,"HG") || strstr(atomsmb, "HG"))
                printf("%0.3f\n", HG);
		else if(strstr(atomsmb,"TL") || strstr(atomsmb, "Tl"))
                printf("%0.3f\n", TL);
		else if(strstr(atomsmb,"PB") || strstr(atomsmb, "Pb"))
                printf("%0.3f\n", PB);
		else if(strstr(atomsmb,"BI") || strstr(atomsmb, "Bi"))
                printf("%0.3f\n", BI);
		else if(strstr(atomsmb,"PO") || strstr(atomsmb, "Po"))
                printf("%0.3f\n", PO);
		else if(strstr(atomsmb,"AT") || strstr(atomsmb, "At"))
                printf("%0.3f\n", AT);
		else if(strstr(atomsmb,"RN") || strstr(atomsmb, "Rn"))
                printf("%0.3f\n", RN);
		else if(strstr(atomsmb,"FR") || strstr(atomsmb, "Fr"))
                printf("%0.3f\n", FR);
		else if(strstr(atomsmb,"RA") || strstr(atomsmb, "Ra"))
                printf("%0.3f\n", RA);
		else if(strstr(atomsmb,"AC") || strstr(atomsmb, "Ac"))
                printf("%0.3f\n", AC);
		else if(strstr(atomsmb,"U") && strlen(atomsmb)<2)
                printf("%0.3f\n", U);
		else if(strstr(atomsmb,"TH") || strstr(atomsmb, "Th"))
                printf("%0.3f\n", TH);
		else if(strstr(atomsmb,"PA") || strstr(atomsmb, "Pa"))
                printf("%0.3f\n", PA);
		else if(strstr(atomsmb,"NP") || strstr(atomsmb, "Np"))
                printf("%0.3f\n", NP);
		else if(strstr(atomsmb,"PU") || strstr(atomsmb, "Pu"))
                printf("%0.3f\n", PU);
		else if(strstr(atomsmb,"AM") || strstr(atomsmb, "Am"))
                printf("%0.3f\n", AM);
		else if(strstr(atomsmb,"CM") || strstr(atomsmb, "Cm"))
                printf("%0.3f\n", CM);
		else if(strstr(atomsmb,"BK") || strstr(atomsmb, "Bk"))
                printf("%0.3f\n", BK);

		else
		printf("0.000\n");
                }
	}
    fclose(fp);
}

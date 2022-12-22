/*
 * Written by Goutam Mukherjee
 * Purpose: Correct the bond order between C-C, C-N, C-H, N-H, O-H and S-H bonds in a molecule.
 * How to run:
 * g++ bond_order_calc.c -o bond_order_calc.exe
 * ./bond_order_calc.exe <Input pdb file> <A concatenate bond order printed by bond_order_CM.exe and bond_order_sdf.exe programmes>
 * If the bond order between two atoms are different by the output of bond_order_CM.exe and bond_order_sdf.exe programmes,
 * then this programme check the bond distance between atoms and guess a bond order for the following bonds present in a molecule:
 *  C-C, C-N, C-H, N-H, O-H and S-H 
 *  Since, the bond order printed by CONNECTMOL and babel programmes sometimes differ betwen these pairs of atoms. Hence, I wrote this programme to crosscheck and print a correct bond order between them if their bond order is differ by both the programmes.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct cyp {    // ligand1
        float x,y,z;
        int r, atomno;
        char  atomname[5];
        char resname[4];

}L;
typedef struct bo {  // Aromatic ring position
        int a1, b1, c1, a2, b2, c2;

}K;
int main(int argc, char *argv[])
	{
	FILE *fp,*fr;
	int pos1, pos2;
	if (argc<3) 
	  {
          printf("                    <Input file-1>                              <Input file-2>\n");
	  printf("./bond_order_calc.exe <PDB fie> <A concatenate bond order printed by bond_order_CM.exe and bond_order_sdf.exe programmes>\n");
	  exit(1);
	  }

	char str[100], s[100];
	int st[300];
	char atom[6];
	L L1 [20000];
	K L2 [20000];
	
	fp=fopen(argv[1],"r");
	fr=fopen(argv[2],"r");

	int counter_ligand=0, counter_ligand2=0;
	int i=0, j=0, len=0;
	while (fgets (str, 100, fp)!=NULL)
        {
		if(strncmp(str,"ATOM",4)==0 || strncmp(str,"HETATM",6)==0)
		{
                		sscanf(str,"%s%d%s%s%d%f%f%f",atom,&L1[counter_ligand].atomno,L1[counter_ligand].atomname\
                               	           ,L1[counter_ligand].resname,&L1[counter_ligand].r,&L1[counter_ligand].x\
                                           ,&L1[counter_ligand].y,&L1[counter_ligand].z);
			//strcpy(st[counter_ligand], L1[counter_ligand].atomname);
			counter_ligand++;
		}
	}
		
		while (fgets (s, 100, fr)!=NULL)
        {
		sscanf(s, "%d %d %d %d %d %d", &L2[counter_ligand2].a1, &L2[counter_ligand2].b1, &L2[counter_ligand2].c1, &L2[counter_ligand2].a2, &L2[counter_ligand2].b2, &L2[counter_ligand2].c2);
		//printf("%d\n", L2[counter_ligand2].c1);
		counter_ligand2++;
	}

		for(i=0; i<counter_ligand2; i++)
		{
			//for(j=0; j<counter_ligand2; j++)
                	//{
				for(len=0; len<counter_ligand; len++)
                		{
					if(L2[i].a1==L2[i].a2 && L2[i].b1==L2[i].b2 && L2[i].c1!=L2[i].c2 && L2[i].c1!=4)
					{
						pos1=L2[i].a1;
						pos2=L2[i].b1;
						 double distance=sqrt((L1[pos1-1].x - L1[pos2-1].x) * (L1[pos1-1].x - L1[pos2-1].x) + (L1[pos1-1].y - L1[pos2-1].y) * (L1[pos1-1].y - L1[pos2-1].y) + (L1[pos1-1].z - L1[pos2-1].z) * (L1[pos1-1].z - L1[pos2-1].z));
						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"C") && distance<1.49)
						st[i]=2;
						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"C") && distance>=1.49)
                                                st[i]=1;

						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"N") && distance>=1.30) //It was 1.28
                                                st[i]=1;
						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"N") && distance<1.30 && distance>=1.19)
                                                st[i]=2;
						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"N") && distance<1.19)
                                                st[i]=3;

						if(strstr(L1[pos1-1].atomname,"N") && strstr(L1[pos2-1].atomname,"C") && distance>=1.28)
                                                st[i]=1;
                                                if(strstr(L1[pos1-1].atomname,"N") && strstr(L1[pos2-1].atomname,"C") && distance<1.28 && distance>=1.19)
                                                st[i]=2;
                                                if(strstr(L1[pos1-1].atomname,"N") && strstr(L1[pos2-1].atomname,"C") && distance<1.19)
                                                st[i]=3;

						if(strstr(L1[pos1-1].atomname,"H") && strstr(L1[pos2-1].atomname,"C"))
                                                st[i]=1;
						if(strstr(L1[pos1-1].atomname,"C") && strstr(L1[pos2-1].atomname,"H"))
                                                st[i]=1;

						if(strstr(L1[pos1-1].atomname,"H") && strstr(L1[pos2-1].atomname,"N"))
                                                st[i]=1;
                                                if(strstr(L1[pos1-1].atomname,"N") && strstr(L1[pos2-1].atomname,"H"))
                                                st[i]=1;

						if(strstr(L1[pos1-1].atomname,"H") && strstr(L1[pos2-1].atomname,"O"))
                                                st[i]=1;
                                                if(strstr(L1[pos1-1].atomname,"O") && strstr(L1[pos2-1].atomname,"H"))
                                                st[i]=1;

						if(strstr(L1[pos1-1].atomname,"H") && strstr(L1[pos2-1].atomname,"S"))
                                                st[i]=1;
                                                if(strstr(L1[pos1-1].atomname,"S") && strstr(L1[pos2-1].atomname,"H"))
                                                st[i]=1;
							
					}
				}
						//printf("%d %d %d\n", L1[pos1-1].atomno, L1[pos2-1].atomno, st[i]);
						printf("%d\n", st[i]);
		}


		fclose(fp);
		fclose(fr);
	}

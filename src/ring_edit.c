/*
 * Written by Goutam Mukherjee
 * Purpose: This programme paste the ring size information to the output of lp2.exe programme. The output of lp2.exe programme is the atom type of an atom in a molecule.
 * How to run:
 * ./ring_edit.exe <Output of lp2.exe> <Output of ring.exe>
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
        char atype[50];

}L;
typedef struct cpr {  // Ligand2
        char ring_size[4];
	int atom_rank=0;

}P;

int main(int argc, char *argv[])
{
        FILE *fp, *fd, *fr;
        char s[100], str[999][50];
	char str1[999][50], str2[999][7];
        char atom[6];
        fp=fopen(argv[1],"r");
        fd=fopen(argv[2],"r");
	  if (argc<3)
          {
          printf("                    <Input file-1>    <Input file-2>\n");
          printf("./ring_edit.exe <Output of lp2.exe> <Output of ring.exe>\n");
          exit(1);
          }
        int counter_ligand=0, counter_ligand2=0, counter_ligand3=0;

        L L1 [20000];
        P L2 [20000];
        vector <string> PDB;

        while (fgets (s, 100, fp)!=NULL)
	{
                if (1==sscanf(s,"%s",L1[counter_ligand].atype))
                counter_ligand++;
        }

        while (fgets (s, 100, fd)!=NULL)
	{
		if (2==sscanf(s,"%d%s", &L2[counter_ligand2].atom_rank, L2[counter_ligand2].ring_size))
                counter_ligand2++;
        }
	
	if(ftell(fd)==0)
        counter_ligand2=0;

        int i=0, j=0, count=0, sum=0;
	for (i=0;i<counter_ligand;i++)
	{
		sum=0;

			for (j=0;j<counter_ligand2;j++)
			{
				//printf("%d\n", L2[j].atom_rank);
						if(i==L2[j].atom_rank-1)
						{
							//strcpy(str[i],L1[i].atype);
							//strcat(str[i],L2[j].ring_size);
							strcat(L1[i].atype,L2[j].ring_size);
							strcpy(str[i],L1[i].atype);
							sum=sum+1;
							//printf("%d\n", L2[j].atom_rank-1);
						}
						if(i!=L2[j].atom_rank-1)
						{
							if(sum==0)
								strcpy(str[i],L1[i].atype);
						}
						///if(i==L2[j].atom_rank-1)
                                                ///{	
							//if(strlen(str[i])==0)
							//{
                                                        	//strcpy(str[i],L1[i].atype);
                                                        	//strcat(str[i],L2[j].ring_size);
								//strcat(L1[i].atype,L2[j].ring_size);
								//strcpy(str[i],L1[i].atype);
                                                        	//sum=sum+1;
							//}
								//if(strlen(str[i])>=3)
								//{
								//strcat(str[i],L2[j].ring_size);
                                                                //sum=sum+1;
								//}
						///}
					
			}
	}
				for (i=0;i<counter_ligand;i++)
					printf("%s\n", str[i]);
				
       
fclose(fp);
fclose(fd);
}


/*
 * Written by Goutam Mukherjee
 * Purpose: It will print the atom rank amd size of the ring in two different columns.
 * Input file, say:
 * 6	  6 9 15 12 7 4 (first column is always as ring size and rest are atom rank)
 * Outout of this programme:
 * 7	6MR
 * 10	6MR
 * 16	6MR
 * 13	6MR
 * 8	6MR
 * 5	6MR
 * How to run:
 * ./ring.exe <Information of ring obtained from RDKit package>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
	{
	FILE *fp,*fw;
	  if (argc<2)
          {
          printf("                           <Input file>                           >Output file\n");
          printf("./ring.exe <Information of ring obtained from RDKit package>\n");
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
		int h;
		int i; 
		//int j;
		//int k;
		//int l;
		//int m;
		//int n;
		//int o;	
		//int p;
		//int q;
		//int r;
		//int s;
		};
		struct format f;
	char str[500];
	fp=fopen(argv[1],"r");
	while(fgets(str,500,fp)!=NULL)
		{
			sscanf(str,"%d%d%d %d%d%d %d%d%d",&f.a, &f.b, &f.c, &f.d, &f.e, &f.f, &f.g, &f.h, &f.i); //&f.j, &f.k, &f.l, &f.m, &f.n, &f.o, &f.p, &f.q, &f.r, &f.s);
			        if(f.a==8)
				printf("%d\t8MR\n%d\t8MR\n%d\t8MR\n%d\t8MR\n%d\t8MR\n%d\t8MR\n%d\t8MR\n%d\t8MR\n",f.b+1, f.c+1, f.d+1, f.e+1, f.f+1, f.g+1, f.h+1, f.i+1);

				if(f.a==7)                     
                                printf("%d\t7MR\n%d\t7MR\n%d\t7MR\n%d\t7MR\n%d\t7MR\n%d\t7MR\n%d\t7MR\n",f.b+1, f.c+1, f.d+1, f.e+1, f.f+1, f.g+1, f.h+1);

				if(f.a==6)  
                                printf("%d\t6MR\n%d\t6MR\n%d\t6MR\n%d\t6MR\n%d\t6MR\n%d\t6MR\n",f.b+1, f.c+1, f.d+1, f.e+1, f.f+1, f.g+1);

				if(f.a==5)
                                printf("%d\t5MR\n%d\t5MR\n%d\t5MR\n%d\t5MR\n%d\t5MR\n",f.b+1, f.c+1, f.d+1, f.e+1, f.f+1);

				if(f.a==4)
                                printf("%d\t4MR\n%d\t4MR\n%d\t4MR\n%d\t4MR\n", f.b+1, f.c+1, f.d+1, f.e+1);

				if(f.a==3)
                                printf("%d\t3MR\n%d\t3MR\n%d\t3MR\n", f.b+1, f.c+1, f.d+1);


		}
fclose(fp);
	}

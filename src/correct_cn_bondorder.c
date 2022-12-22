/*
 * Author: Goutam Mukherjee
 * This code correct the bond order of C-N ( and aromatic)
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

		//Correcting a bond order of carbon atom which contains both double and aromatic bonds
		if(strncmp(final_string[line],"C",1)==0)
                {
                        if(strchr(final_string[line],'4') && strchr(final_string[line],'2') && strstr(final_string[line],"4MR")==NULL)
                        {
                                if((strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4') ||
                                   (strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4') ||
                                   (strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4'))
                                {
                                        b=strstr(final_string[line],"CC2");
                                        if(b)
                                                fill4(b);
                                }
                                else
                                {
                                                b=strchr(final_string[line],'4');
                                                if(b)
                                                {
                                                        fill6(b);
                                                        b=strchr(final_string[line],'4');
                                                        if(b)
                                                                fill6(b);
                                                }
                                }

                        }
                }
			//Correcting C-N bond order
			if(strncmp(final_string[line],"C",1)==0)
			{
				if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4' && strlen(final_string[line])>4)
						{
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4') //&&
									                             //strstr(strings_array[f.c-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL)
							{
								b=strstr(final_string[line],"CN1CN1CN1");
								if(b)
									fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
							}
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4') //&&
													  //strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL)
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"NC1");
								if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4') //&&
													  //strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.c-1],"2")==NULL)
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CN1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							//  	
							//N-C(N)-C
							if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							/*if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }*/
							if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"CC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }

							/*if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }*/
							if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"CC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }

							if(strstr(final_string[line],"CN1CN1CC1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CC1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CC1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CC1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CC1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CC1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"CC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							//  *
                                                        //C-C(N)-C
							if(strstr(final_string[line],"CC1CC1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CC1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CC1CC1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }

							//  *
							//N-C(N)-O
							if(strstr(final_string[line],"CN1CO1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CO1CN1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
                                                        if(strstr(final_string[line],"CN1CO1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CO1CN1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CO1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CO1");
                                                                if(b)
                                                                        fill5(b);
								b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CO1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CO1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CO1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CO1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
								b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							if(strstr(final_string[line],"CO1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CO1CN1CN1");
                                                                if(b)
                                                                        fill12(b);
								b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                        }
							//  *
                                                        //C-C(N)-H/S/O/X
							if(strstr(final_string[line],"CN1") && (strstr(final_string[line],"CH1") || strstr(final_string[line],"CS1") || strstr(final_string[line],"CO1") || strstr(final_string[line],"CF1") || strstr(final_string[line],"Cl1") || strstr(final_string[line],"CB1") || strstr(final_string[line],"CI1")) && strstr(final_string[line],"CC1"))
							{
								if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
								{
									b=strstr(final_string[line],"CN1");
									if(b)
                                                                        	fill5(b);
									b=strstr(strings_array[f.b-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
								}
								if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                                {
                                                                        b=strstr(final_string[line],"CN1");
                                                                        if(b)
                                                                                fill5(b);
									b=strstr(strings_array[f.c-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                                }
								if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                                {
                                                                        b=strstr(final_string[line],"CN1");
                                                                        if(b)
                                                                                fill5(b);
									b=strstr(strings_array[f.d-1],"NC1");
                                                                if(b)
                                                                        fill11(b);
                                                                }
							}

						}
			}
			if(strncmp(final_string[line],"N",1)==0)
                        {
                                if(strstr(final_string[line],"NN1NO1NEG"))
                                {
                                        //if((strings_array[f.c-1],"ON1NEG") || strlen(strings_array[f.c-1])<=4)
					if((strings_array[f.b-1],"ON1NEG") || (strstr(strings_array[f.b-1],"ON1") && strlen(strings_array[f.b-1])<=4))
                                        strcpy(final_string[line],"NO2NN1");
                                }
                        }
			//Correcting a coordinatively unsaturated C-atom by assigining a C-N bond order 2, i.e.; C-N --->C=N only when attached nitrogen atom is trivalent and do not contains any double or aromatic bond.
			/*if(strncmp(final_string[line],"C",1)==0)// && strstr(final_string[line],"CN1CN1CN1")==NULL)
			{
				if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' &&  final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
				{
					if(strstr(final_string[line],"CN1"))
					{
						if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strstr(strings_array[f.b-1],"NH1")==NULL) //A sp2 N-atom shound not be hydrogen added
						{
							b=strstr(final_string[line],"CN1");
							if(b)
								fill5(b);
							 b=strstr(strings_array[f.b-1],"NC1");
							 if(b && strings_array[f.b-1][1]=='C')
                                                                fill5(b);
                                                        if(b && strings_array[f.b-1][4]=='C')
                                                                fill5(b);
                                                        if(b && strings_array[f.b-1][7]=='C')
                                                                fill5(b);
						}
						else if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strstr(strings_array[f.c-1],"NH1")==NULL) //A sp2 N-atom shound not be hydrogen added
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
							b=strstr(strings_array[f.c-1],"NC1");
							if(b && strings_array[f.c-1][1]=='C')
								fill5(b);
							if(b && strings_array[f.c-1][4]=='C')
                                                                fill5(b);
							if(b && strings_array[f.c-1][7]=='C')
                                                                fill5(b);

                                                }
						else if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strstr(strings_array[f.d-1],"NH1")==NULL) //A sp2 N-atom shound not be hydrogen added
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
							b=strstr(strings_array[f.d-1],"NC1");
							if(b && strings_array[f.c-1][1]=='C')
                                                                fill5(b);
                                                        if(b && strings_array[f.c-1][4]=='C')
                                                                fill5(b);
                                                        if(b && strings_array[f.c-1][7]=='C')
                                                                fill5(b);
                                                }
					}
				}
			}*/
			//Convering an aromatic bond order to olefinic bond order when a coordinatively unsaturated nirogen attached with a sp2 aromatic C-atom
			if(strncmp(final_string[line],"C",1)==0)
			{
				if(strstr(final_string[line],"CN1CC4CC4"))
				{
					if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4')// && strstr(strings_array[f.b-1],"6MR")==NULL && strstr(strings_array[f.b-1],"5MR")==NULL)
					{
						b=strstr(final_string[line],"CN1CC4CC4");
						if(b)
							fill10(b);
						b=strstr(strings_array[f.b-1],"NC1");
						if(b)
							fill11(b);
					}
				}
				if(strstr(final_string[line],"CC4CN1CC4"))
                                {
					if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4')// && strstr(strings_array[f.c-1],"6MR")==NULL && strstr(strings_array[f.c-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CC4CN1CC4");
                                                if(b)
                                                        fill8(b);
                                                b=strstr(strings_array[f.c-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CC4CC4CN1"))
                                {
					if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4')// && strstr(strings_array[f.d-1],"6MR")==NULL && strstr(strings_array[f.d-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CC4CC4CN1");
                                                if(b)
                                                        fill9(b);
                                                b=strstr(strings_array[f.d-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				//Convering an aromatic bond order to olefinic bond order when a coordinatively unsaturated nirogen attached with a sp2 aromatic C-atom
				if(strstr(final_string[line],"CN1CN4CC4"))
                                {
                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4')// && strstr(strings_array[f.b-1],"6MR")==NULL && strstr(strings_array[f.b-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN1CN4CC4");
                                                if(b)
                                                        fill10(b);
                                                b=strstr(strings_array[f.b-1],"NC1");
                                                if(b)
                                                        fill11(b);
					}
                                }
				if(strstr(final_string[line],"CN1CC4CN4"))
                                {
                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4')// && strstr(strings_array[f.b-1],"6MR")==NULL && strstr(strings_array[f.b-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN1CC4CN4");
                                                if(b)
                                                        fill10(b);
                                                b=strstr(strings_array[f.b-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CN4CN1CC4"))
                                {
                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4')// && strstr(strings_array[f.c-1],"6MR")==NULL && strstr(strings_array[f.c-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN4CN1CC4");
                                                if(b)
                                                        fill8(b);
                                                b=strstr(strings_array[f.c-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CC4CN1CN4"))
                                {
                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4')// && strstr(strings_array[f.c-1],"6MR")==NULL && strstr(strings_array[f.c-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CC4CN1CN4");
                                                if(b)
                                                        fill8(b);
                                                b=strstr(strings_array[f.c-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CN4CC4CN1"))
                                {
                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4')// && strstr(strings_array[f.d-1],"6MR")==NULL && strstr(strings_array[f.d-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN4CC4CN1");
                                                if(b)
                                                        fill9(b);
                                                b=strstr(strings_array[f.d-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CC4CN4CN1"))
                                {
                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4')// && strstr(strings_array[f.d-1],"6MR")==NULL && strstr(strings_array[f.d-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CC4CN4CN1");
                                                if(b)
                                                        fill9(b);
                                                b=strstr(strings_array[f.d-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				//End
                                if(strstr(final_string[line],"CN1CN4CN4"))
                                {
                                        if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='3' && strings_array[f.b-1][8]!='4')// && strstr(strings_array[f.b-1],"6MR")==NULL && strstr(strings_array[f.b-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN1CN4CN4");
                                                if(b)
                                                        fill10(b);
                                                b=strstr(strings_array[f.b-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
                                if(strstr(final_string[line],"CN4CN1CN4"))
                                {
                                        if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='3' && strings_array[f.c-1][8]!='4')// && strstr(strings_array[f.c-1],"6MR")==NULL && strstr(strings_array[f.c-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN4CN1CN4");
                                                if(b)
                                                        fill8(b);
                                                b=strstr(strings_array[f.c-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }
				if(strstr(final_string[line],"CN4CN4CN1"))
                                {
                                        if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='3' && strings_array[f.d-1][8]!='4')// && strstr(strings_array[f.d-1],"6MR")==NULL && strstr(strings_array[f.d-1],"5MR")==NULL)
                                        {
                                                b=strstr(final_string[line],"CN4CN4CN1");
                                                if(b)
                                                        fill9(b);
                                                b=strstr(strings_array[f.d-1],"NC1");
                                                if(b)
                                                        fill11(b);
                                        }
                                }

			}

		//Correcting coordinatively unsaturated sp3 C-atom which contains atleat a C-C bond
		if(strncmp(final_string[line],"C",1)==0)
		{
			if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
			{
				if(strings_array[f.b-1][0]=='O' && strings_array[f.b-1][5]!='1' && strings_array[f.b-1][5]!='2' && strings_array[f.b-1][5]!='4')
				{
				b=strstr(final_string[line],"CO1");
				if(b)
					fill5(b);
				b=strstr(strings_array[f.b-1],"OC1");
				if(b)
					fill5(b);
				}
				else if(strings_array[f.b-1][0]=='S' && strings_array[f.b-1][5]!='1' && strings_array[f.b-1][5]!='2' && strings_array[f.b-1][5]!='4')
                                {
                                b=strstr(final_string[line],"CS1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.b-1],"SC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.b-1][0]=='N' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CN1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.b-1],"NC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.b-1][0]=='C' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2' && strings_array[f.b-1][11]!='4' && strchr(strings_array[f.b-1],'2')==NULL && strchr(strings_array[f.b-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CC1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.b-1],"CC1");
                                if(b)
                                        fill5(b);
                                }

				else if(strings_array[f.c-1][0]=='O' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4')
                                {
                                b=strstr(final_string[line],"CO1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.c-1],"OC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.c-1][0]=='S' && strings_array[f.c-1][5]!='1' && strings_array[f.c-1][5]!='2' && strings_array[f.c-1][5]!='4')
                                {
                                b=strstr(final_string[line],"CS1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.c-1],"SC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.c-1][0]=='N' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CN1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.c-1],"NC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.c-1][0]=='C' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2' && strings_array[f.c-1][11]!='4' && strchr(strings_array[f.c-1],'2')==NULL && strchr(strings_array[f.c-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CC1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.c-1],"CC1");
                                if(b)
                                        fill5(b);
                                }

				else if(strings_array[f.d-1][0]=='O' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4')
                                {
                                b=strstr(final_string[line],"CO1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.d-1],"OC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.d-1][0]=='S' && strings_array[f.d-1][5]!='1' && strings_array[f.d-1][5]!='2' && strings_array[f.d-1][5]!='4')
                                {
                                b=strstr(final_string[line],"CS1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.d-1],"SC1");
                                if(b)
                                        fill5(b);
                                }
				else if(strings_array[f.d-1][0]=='N' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CN1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.d-1],"NC1");
                                if(b)
                                        fill5(b);
                                }
                                else if(strings_array[f.d-1][0]=='C' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2' && strings_array[f.d-1][11]!='4' && strchr(strings_array[f.d-1],'2')==NULL && strchr(strings_array[f.d-1],'4')==NULL)
                                {
                                b=strstr(final_string[line],"CC1");
                                if(b)
                                        fill5(b);
				b=strstr(strings_array[f.d-1],"CC1");
                                if(b)
                                        fill5(b);
                                }

			}
			//Correcting a bond order of carbon atom which contains both double and aromatic bonds.
			/*if(strchr(final_string[line],'4') && strchr(final_string[line],'2') && strstr(final_string[line],"4MR")==NULL)
			{
				//printf("Found\n");
				b=strchr(final_string[line],'4');
				if(b)
				{
					fill6(b);
					b=strchr(final_string[line],'4');
					if(b)
						fill6(b);
				}
			}*/
		}
		
		//Correcting bond order of a coordinatively unsaturated C-atom by assigining a C-N bond order of 2, i.e.; C-N --->C=N, only when attached nitrogen atom is trivalent and do not contains any double or aromatic bond.
                        if(strncmp(final_string[line],"C",1)==0)
                        {
                                if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' &&  final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
                                {
                                        if(strstr(final_string[line],"CN1"))
                                        {
                                                if(strncmp(strings_array[f.b-1],"N",1)==0 && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='1' && strings_array[f.b-1][11]!='1' && strings_array[f.b-1][11]!='2')
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
                                                        b=strstr(strings_array[f.b-1],"NC1");
                                                         if(b)
                                                                fill5(b);
                                                }
                                                else if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strings_array[f.c-1][11]!='1' && strings_array[f.c-1][11]!='2')
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
                                                        b=strstr(strings_array[f.c-1],"NC1");
                                                        if(b)
                                                                fill5(b);
                                                }
                                                else if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strings_array[f.d-1][11]!='1' && strings_array[f.d-1][11]!='2')
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
                                                        b=strstr(strings_array[f.d-1],"NC1");
                                                        if(b)
                                                                fill5(b);
                                                }
                                        }
                                }
			//Added on 012622 for a atomtype, where, carbon valency was printed as 5 say, CS2CN2CH1 or, CN2CO2CH1 etc.
				if(final_string[line][2]=='2' && final_string[line][5]=='2' && final_string[line][8]=='1' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
				{
					if(strstr(final_string[line],"CO2"))
					{
						if((strings_array[f.b-1],"OC2") && strlen(strings_array[f.b-1])==3)
						{
							b=strstr(final_string[line],"CO2");
							if(b)
								fill4(b);
							b=strstr(strings_array[f.b-1],"OC2");
							if(b)
								fill4(b);
						}
						else if((strings_array[f.c-1],"OC2") && strlen(strings_array[f.c-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CO2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.c-1],"OC2");
                                        	        if(b)
                                        	                fill4(b);
                                        	}
					}

					//
					else if(strstr(final_string[line],"CC2") && strstr(final_string[line],"CO2")==NULL && strstr(final_string[line],"CN2")==NULL && strstr(final_string[line],"CS2")==NULL)
                                        {
                                                if((strings_array[f.b-1],"CC2") && ((strings_array[f.b-1][2]=='2' && strings_array[f.b-1][5]=='2' && strings_array[f.b-1][8]=='1') || 
										   strings_array[f.b-1][2]=='2' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='2' ||
										   strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='2' && strings_array[f.b-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.b-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
						else if((strings_array[f.c-1],"CC2") && ((strings_array[f.c-1][2]=='2' && strings_array[f.c-1][5]=='2' && strings_array[f.c-1][8]=='1') ||
                                                                                   strings_array[f.c-1][2]=='2' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='2' ||
                                                                                   strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='2' && strings_array[f.c-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.c-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }
					
					else if(strstr(final_string[line],"CS2"))
                                	{
                                        	if((strings_array[f.b-1],"SC2") && strlen(strings_array[f.b-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CS2");
                                        	        if(b)
                                                	        fill4(b);
                                                	b=strstr(strings_array[f.b-1],"SC2");
                                                	if(b)
                                                	        fill4(b);
                                        	}
						else if((strings_array[f.c-1],"SC2") && strlen(strings_array[f.c-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CS2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.c-1],"SC2");
                                        	        if(b)
                                        	                fill4(b);
                                        	}
					}
					else if(strstr(final_string[line],"CN2"))
                                	{
                                	        if((strings_array[f.b-1],"NC2") && strlen(strings_array[f.b-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CN2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.b-1],"NC2");
                                	                if(b)
                                	                        fill4(b);
                                	        }
						else if((strings_array[f.c-1],"NC2") && strlen(strings_array[f.c-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CN2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.c-1],"NC2");
                                        	        if(b)
                                                	        fill4(b);
                                        	}
                                	}
				}
				if(final_string[line][2]=='2' && final_string[line][5]=='1' && final_string[line][8]=='2' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
                        	{
                        	        if(strstr(final_string[line],"CO2"))
                        	        {
                        	                if((strings_array[f.b-1],"OC2") && strlen(strings_array[f.b-1])==3)
                        	                {
                        	                        b=strstr(final_string[line],"CO2");
                        	                        if(b)
                        	                                fill4(b);
                        	                        b=strstr(strings_array[f.b-1],"OC2");
                        	                        if(b)
                        	                                fill4(b);
                        	                }
						else if((strings_array[f.d-1],"OC2") && strlen(strings_array[f.d-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CO2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.d-1],"OC2");
                                	                if(b)
                                	                        fill4(b);
                                	        }
                                	}
					//
                                        else if(strstr(final_string[line],"CC2") && strstr(final_string[line],"CO2")==NULL && strstr(final_string[line],"CN2")==NULL && strstr(final_string[line],"CS2")==NULL)
                                        {
                                                if((strings_array[f.b-1],"CC2") && ((strings_array[f.b-1][2]=='2' && strings_array[f.b-1][5]=='2' && strings_array[f.b-1][8]=='1') ||
                                                                                   strings_array[f.b-1][2]=='2' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]=='2' ||
                                                                                   strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='2' && strings_array[f.b-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.b-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
						else if((strings_array[f.d-1],"CC2") && ((strings_array[f.d-1][2]=='2' && strings_array[f.d-1][5]=='2' && strings_array[f.d-1][8]=='1') ||
                                                                                   strings_array[f.d-1][2]=='2' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='2' ||
                                                                                   strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='2' && strings_array[f.d-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.d-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }

                                	else if(strstr(final_string[line],"CS2"))
                                	{
                                	        if((strings_array[f.b-1],"SC2") && strlen(strings_array[f.b-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CS2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.b-1],"SC2");
                                	                if(b)
                                	                        fill4(b);
                                	        }
						else if((strings_array[f.d-1],"SC2") && strlen(strings_array[f.d-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CS2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.d-1],"SC2");
                                	                if(b)
                                	                        fill4(b);
                                	        }
                                	}
                                	else if(strstr(final_string[line],"CN2"))
                                	{
                                	        if((strings_array[f.b-1],"NC2") && strlen(strings_array[f.b-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CN2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.b-1],"NC2");
                                        	        if(b)
                                        	                fill4(b);
                                        	}
						else if((strings_array[f.d-1],"NC2") && strlen(strings_array[f.d-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CN2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.d-1],"NC2");
                                        	        if(b)
                                        	                fill4(b);
                                        	}
                                	}
                        	}
			//
				if(final_string[line][2]=='1' && final_string[line][5]=='2' && final_string[line][8]=='2' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4')
                        	{
                        	        if(strstr(final_string[line],"CO2"))
                        	        {
                        	                if((strings_array[f.d-1],"OC2") && strlen(strings_array[f.d-1])==3)
                        	                {
                        	                        b=strstr(final_string[line],"CO2");
                        	                        if(b)
                        	                                fill4(b);
                        	                        b=strstr(strings_array[f.d-1],"OC2");
                        	                        if(b)
                        	                                fill4(b);
                        	                }
						else if((strings_array[f.c-1],"OC2") && strlen(strings_array[f.c-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CO2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.c-1],"OC2");
                                        	        if(b)
                                                	        fill4(b);
                                       	 	}
                                	}
					//
                                        else if(strstr(final_string[line],"CC2") && strstr(final_string[line],"CO2")==NULL && strstr(final_string[line],"CN2")==NULL && strstr(final_string[line],"CS2")==NULL)
                                        {
                                                if((strings_array[f.c-1],"CC2") && ((strings_array[f.c-1][2]=='2' && strings_array[f.c-1][5]=='2' && strings_array[f.c-1][8]=='1') ||
                                                                                   strings_array[f.c-1][2]=='2' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='2' ||
                                                                                   strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='2' && strings_array[f.c-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.c-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
						else if((strings_array[f.d-1],"CC2") && ((strings_array[f.d-1][2]=='2' && strings_array[f.d-1][5]=='2' && strings_array[f.d-1][8]=='1') ||
                                                                                   strings_array[f.d-1][2]=='2' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='2' ||
                                                                                   strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='2' && strings_array[f.d-1][8]=='2'))
                                                {
                                                        b=strstr(final_string[line],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                        b=strstr(strings_array[f.d-1],"CC2");
                                                        if(b)
                                                                fill4(b);
                                                }
                                        }

                                	else if(strstr(final_string[line],"CS2"))
                                	{
                                        	if((strings_array[f.d-1],"SC2") && strlen(strings_array[f.d-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CS2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.d-1],"SC2");
                                        	        if(b)
                                        	                fill4(b);
                                        	}
						else if((strings_array[f.c-1],"SC2") && strlen(strings_array[f.c-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CS2");
                                        	        if(b)
                                        	                fill4(b);
                                        	        b=strstr(strings_array[f.c-1],"SC2");
                                        	        if(b)
                                                	        fill4(b);
                                        	}
                                	}
                               		else if(strstr(final_string[line],"CN2"))
                                	{
                                	        if((strings_array[f.d-1],"NC2") && strlen(strings_array[f.d-1])==3)
                                	        {
                                	                b=strstr(final_string[line],"CN2");
                                	                if(b)
                                	                        fill4(b);
                                	                b=strstr(strings_array[f.d-1],"NC2");
                                	                if(b)
                                	                        fill4(b);
                                	        }
						else if((strings_array[f.c-1],"NC2") && strlen(strings_array[f.c-1])==3)
                                        	{
                                        	        b=strstr(final_string[line],"CN2");
                                        	        if(b)
                                                	        fill4(b);
                                                	b=strstr(strings_array[f.c-1],"NC2");
                                                	if(b)
                                                        	fill4(b);
                                        	}
                                	}
                       		}

                 	}

                //fprintf(fw,"%s\n",final_string[line]);
		
		

		line++;
	        
              
          }
          for (int k=0; k<line; k++)
                fprintf(fw,"%s\n", final_string[k]); 

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

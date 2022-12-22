/*
 * Written by Goutam Mukherjee, PhD
 * Purpose: This program concatenate a three letter nomenclature at the end of the atomtype printed by lp2.exe programme
 * The list of nomenclaures are given below:
 * ARX: When a halogen atom attached with an aromatic carbon
 * C=C: When a halogen atom attached with a C=C
 * NEG: Negatively charge group
 * POS: Positively charge group
 * EST: When a sp3 oxygen is attached with one carbonyl (C=O) group or, a sp3 Sulfur group is attached with C=S or C=O group
 * DST: When a sp3 oxygen is attached with two carbonyl (C=O) groups
 * DIN: When a sp3 oxygen is attached with two C=N groups
 * OTD: When a ether type oxygen is attached with C=S group
 * ODD: When a ether type oxygen is attached with two C=S groups
 * DON: When a sp3 oxygen is attached with one C=N and one C=O groups
 * ENL: When a alcoholic oxygen atom is attached with C=C group
 * ELN: When a alcoholic oxygen atom is attached with C=N group
 * ENE: When a ether type oxygen is attached with one C=C group
 * DNE: When a ether type oxygen is attached with two C=C groups
 * OCN: When a ether type oxygen is attached with one C=N group
 * DCN: When a ether type oxygen is attached with two C=N groups
 * NTO: sp3 monovalent Oxygen is attached with N=O group
 * CO3: sp3 monovalent Oxygen is attached with Carbonate group
 * AMD: sp3 nitrogen atom when atached with one C=O group
 * DAM: sp3 nitrogen atom when atached with two C=O groups
 * MTD: sp3 nitrogen atom when atached with one C=S group
 * DTD: sp3 nitrogen atom when atached with two C=S groups
 * UER: sp3 nitrogen atom when atached with one C=N group
 * DUR: sp3 nitrogen atom when atached with two C=N groups
 * NYL: sp3 nitrogen atom when atached with one C=C group
 * DYL: sp3 nitrogen atom when atached with two C=C groups
 * BDG: When a Carbon atom is a part of three 6-membered rings/two six membered rings and one five member ring/three five membered ring/thee four membered ring systems (Here I have not considered all the combinations of rings rather taking commonly observed molecules. Say, Carbon atom associated with three four membered rings represent Cubane molecule. Where as I here ignore, Carbon associated with a combination of four and five or, four and six or, four, five and six membered rings. They are not commonly observed molecule)
 * C2S: When a sulfer is attached with a C=S group
 * CJO: When a C=O/C=N/C=S group is attached with C=C group
 * CJC: When a C=C is attached with C=C group
 * CJB: When a aromatic functional group is attached with C=C group
 * CNJ: When a aromatic nitrogen is attached with C=C/C=N/C=O/C=S groups
 * CNO: When a C=O group is attached with C=N group 
 * CNN: When a C=N group is attached with C=N group
 * CNS: When a C=S group is attached with C=N group
 * CNB: When a aromatic fuctional group is attached with C=N group
 * COO: When a C=O group is attached with C=O group
 * COS: When a C=S group is attached with C=O group
 * COB: When a aromatic functional group is attached with C=O group
 * CSS: When a C=S group is attached with C=S group
 * CSB: When a aromatic fuctional group is attached with C=S group
 * NJO: When a Carbon end of C=O group is attached with nitrogen of N=C group
 * NJC: When a Carbon end of C=C group is attached with nitrogen of N=C group
 * NJN: When a carbon end of C=N group is attached nitrogen of with N=C group
 * NJS: When a carbon end of C=S group is attached nitrogen of with N=C group
 * NJB: When a aromatic group is attached nitrogen of with N=C group
 * NNJ: When a nitrogen containing aromatic group is attached nitrogen of with N=C group
 * ARM: Hydrogen attached with aromatic carbon
 * IMD: Hydrogen attached with imidazole nitrogen
 * NOT: A sp2 C-atom which is connected with an aromatic carbon with a double bond
 * AZD: A sp3 N-atom which contains a N-N bond and also attached with a N=N moiety
 * NDZ: A sp2 N-atom which contains a N=N and N-C bonds and attached with adjacent N=N and N-N group (e.g.; N1 of C-N1=N2-N3 moiety)
 
 * How to run:
 * ./lp4.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name> 
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

	char *b, *c;
	FILE *fp,*fr,*fw;
	if (argc<3) {
  	printf("               <Input file-1>                 <Input file-2>       <Output file>\n");
  	printf("./lp4.exe <Output file of ring_edit.exe> <Output file of lp3.exe> <Output file name>\n");
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
		
		//Added on 01.11.22
		if((strncmp(final_string[line],"F",1)==0))
		{
			if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.b-1],"CS4"))
				strcat(final_string[line],"ARX");
		}
		if((strncmp(final_string[line],"l",1)==0))
                {
                        if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.b-1],"CS4"))
                                strcat(final_string[line],"ARX");
                }
		if((strncmp(final_string[line],"B",1)==0))
                {
                        if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.b-1],"CS4"))
                                strcat(final_string[line],"ARX");
                }
		if((strncmp(final_string[line],"I",1)==0))
                {
                        if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.b-1],"CS4"))
                                strcat(final_string[line],"ARX");
                }
		//
		if(strncmp(final_string[line],"F",1)==0 || strncmp(final_string[line],"l",1)==0 || strncmp(final_string[line],"B",1)==0 || strncmp(final_string[line],"I",1)==0)
		{
			if(strstr(strings_array[f.b-1],"CC2"))
				strcat(final_string[line],"C=C");
		}

		if((strncmp(final_string[line],"O",1)==0 && strchr(strings_array[f.a-1],'2')==NULL) || (strncmp(final_string[line],"S",1)==0 && strchr(strings_array[f.a-1],'2')==NULL))
                {
                                if(strlen(final_string[line])==3)
                                strcat(final_string[line],"NEG");
                }

                if(strncmp(final_string[line],"P",1)==0)
		{       	                
			if(strchr(final_string[line],'2')==NULL && strchr(final_string[line],'3')==NULL && strlen(final_string[line])==12)
				strcat(final_string[line],"POS");
	        	//strncat(final_string[line],strings_array[f.b-1],18);          
	        	//strncat(final_string[line],strings_array[f.c-1],18);
                	//strncat(final_string[line],strings_array[f.d-1],18);
			//strncat(final_string[line],strings_array[f.e-1],18);
			//strncat(final_string[line],strings_array[f.f-1],18);
		}
		//strncat(final_string[line],strings_array[f.g-1],18);
		
		if(strncmp(final_string[line],"OC1",3)==0 || strncmp(final_string[line],"OH1OC1",6)==0)
		{
			if(strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.b-1],"CO2CO1CO1")==NULL && 
								 strstr(strings_array[f.b-1],"CO1CO2CO1")==NULL && 
								 strstr(strings_array[f.b-1],"CO1CO1CO2")==NULL &&
								 strstr(strings_array[f.c-1],"CO2")==NULL)
                //strncat(final_string[line],strings_array[f.b-1],18);
		  	strcat(final_string[line],"EST");
			if(strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.c-1],"CO2CO1CO1")==NULL && 
								 strstr(strings_array[f.c-1],"CO1CO2CO1")==NULL && 
								 strstr(strings_array[f.c-1],"CO1CO1CO2")==NULL &&
								 strstr(strings_array[f.b-1],"CO2")==NULL)
		 	 	strcat(final_string[line],"EST");
			if(strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.b-1],"CO2"))
				strcat(final_string[line],"DST");
			if(strstr(strings_array[f.c-1],"CN2") && strstr(strings_array[f.b-1],"CN2"))
                                strcat(final_string[line],"DIN");
			if(strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.b-1],"CN2"))
                                strcat(final_string[line],"DON");
			if(strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.c-1],"CN2"))
                                strcat(final_string[line],"DON");
		}

		//Peroxide acid added on 12.21.21
		if(strncmp(final_string[line],"O",1)==0 && strstr(final_string[line],"OO1"))
		{
			if(strstr(strings_array[f.c-1],"CO2") || strstr(strings_array[f.b-1],"CO2"))
				strcat(final_string[line],"EST");
		}
		/*if(strncmp(final_string[line],"O",1)==0 && strlen(final_string[line])>4)   //Added on 17.04.21
		{
			if(strstr(strings_array[f.b-1],"SO2") || strstr(strings_array[f.c-1],"SO2"))
			strcat(final_string[line],"S=O");
			if(strstr(strings_array[f.b-1],"PO2") || strstr(strings_array[f.c-1],"PO2"))
                        strcat(final_string[line],"P=O");
		}*/

		if(strncmp(final_string[line],"OC1OH1",6)==0 || strncmp(final_string[line],"OH1OC1",6)==0)
		{
			if(strstr(strings_array[f.c-1],"CC2") || strstr(strings_array[f.b-1],"CC2"))
                        strcat(final_string[line],"ENL");
			if(strstr(strings_array[f.c-1],"CN2") || strstr(strings_array[f.b-1],"CN2"))
                        strcat(final_string[line],"ELN");
		}

		if(strncmp(final_string[line],"OC1OC1",6)==0)
                {
                        if((strstr(strings_array[f.c-1],"CC2") && strstr(strings_array[f.b-1],"CC2")==NULL) || 
			   (strstr(strings_array[f.b-1],"CC2") && strstr(strings_array[f.c-1],"CC2")==NULL))
                        	strcat(final_string[line],"ENE");
			if(strstr(strings_array[f.c-1],"CC2") && strstr(strings_array[f.b-1],"CC2"))
				strcat(final_string[line],"DNE");

			if((strstr(strings_array[f.c-1],"CN2") && strstr(strings_array[f.b-1],"CN2")==NULL) ||
                           (strstr(strings_array[f.b-1],"CN2") && strstr(strings_array[f.c-1],"CN2")==NULL))
                                strcat(final_string[line],"OCN");

			//Added on 12.18.21
			if(strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.b-1],"CS2"))
                                strcat(final_string[line],"OTD");
			if(strstr(strings_array[f.c-1],"CS2") && strstr(strings_array[f.b-1],"CS2"))
                                strcat(final_string[line],"ODD");
			//End
			//
                        //if(strstr(strings_array[f.c-1],"CN2") && strstr(strings_array[f.b-1],"CN2"))
                        //strcat(final_string[line],"DCN");
                }

			if(strncmp(final_string[line],"SC1",3)==0 || strncmp(final_string[line],"SH1SC1",6)==0)
                	{
                        	if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.b-1],"CO2"))
                  		strcat(final_string[line],"EST");
                        	if(strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.c-1],"CO2"))
                  		strcat(final_string[line],"EST");
                	}


			if(strncmp(final_string[line],"ON1",3)==0)
			{
                        	if(strstr(strings_array[f.b-1],"NO2"))
                		strcat(final_string[line],"NTO");
                        	
				if(strstr(strings_array[f.c-1],"NO2"))
                		strcat(final_string[line],"NTO");
			}
		
			if(strncmp(final_string[line],"OC1",3)==0)
			{
                        	if(strstr(strings_array[f.b-1],"CO2") && (strstr(strings_array[f.b-1],"CO2CO1CO1") || strstr(strings_array[f.b-1],"CO1CO2CO1") || strstr(strings_array[f.b-1],"CO1CO1CO2")))
				strcat(final_string[line],"CO3");

                        	if(strstr(strings_array[f.c-1],"CO2") && (strstr(strings_array[f.c-1],"CO2CO1CO1") || strstr(strings_array[f.c-1],"CO1CO2CO1") || strstr(strings_array[f.c-1],"CO1CO1CO2")))
                		strcat(final_string[line],"CO3");
			}

			if(strncmp(final_string[line],"N",1)==0)
                        {
				if(strlen(final_string[line])==12 && strstr(final_string[line],"MR")==NULL && strchr(final_string[line],'2')==NULL && strchr(final_string[line],'4')==NULL)
				strcat(final_string[line],"POS"); //sp3(N+) does not part of a ring system

				if(strlen(final_string[line])==15 && strstr(final_string[line],"MR") && strstr(final_string[line],"MR3")==NULL && strstr(final_string[line],"MR4")==NULL &&
				   strstr(final_string[line],"MR5")==NULL && strstr(final_string[line],"MR6")==NULL && strstr(final_string[line],"MR7")==NULL && strstr(final_string[line],"MR8")==NULL &&
				   strchr(final_string[line],'2')==NULL && strchr(final_string[line],'4')==NULL)
                                strcat(final_string[line],"POS"); //sp3(N+) part of a ring system

				if(strlen(final_string[line])==18 && strchr(final_string[line],'2')==NULL && strchr(final_string[line],'4')==NULL && (strstr(final_string[line],"MR3") || strstr(final_string[line],"MR4") || strstr(final_string[line],"MR5") || strstr(final_string[line],"MR6") || strstr(final_string[line],"MR7") || strstr(final_string[line],"MR8")))
				{
					if(strstr(final_string[line],"MR3MR3MR")==NULL && strstr(final_string[line],"MR3MR4MR")==NULL && strstr(final_string[line],"MR3MR5MR")==NULL && strstr(final_string[line],"MR3MR6MR")==NULL && strstr(final_string[line],"MR3MR7MR")==NULL && strstr(final_string[line],"MR3MR8MR")==NULL && 
					  strstr(final_string[line],"MR4MR3MR")==NULL && strstr(final_string[line],"MR4MR4MR")==NULL && strstr(final_string[line],"MR4MR5MR")==NULL && strstr(final_string[line],"MR4MR6MR")==NULL && strstr(final_string[line],"MR4MR7MR")==NULL && strstr(final_string[line],"MR4MR8MR")==NULL &&
					  strstr(final_string[line],"MR5MR3MR")==NULL && strstr(final_string[line],"MR5MR4MR")==NULL && strstr(final_string[line],"MR5MR5MR")==NULL && strstr(final_string[line],"MR5MR6MR")==NULL && strstr(final_string[line],"MR5MR7MR")==NULL && strstr(final_string[line],"MR5MR8MR")==NULL &&
					  strstr(final_string[line],"MR6MR3MR")==NULL && strstr(final_string[line],"MR6MR4MR")==NULL && strstr(final_string[line],"MR6MR5MR")==NULL && strstr(final_string[line],"MR6MR6MR")==NULL && strstr(final_string[line],"MR6MR7MR")==NULL && strstr(final_string[line],"MR6MR8MR")==NULL &&
					  strstr(final_string[line],"MR7MR3MR")==NULL && strstr(final_string[line],"MR7MR4MR")==NULL && strstr(final_string[line],"MR7MR5MR")==NULL && strstr(final_string[line],"MR7MR6MR")==NULL && strstr(final_string[line],"MR7MR7MR")==NULL && strstr(final_string[line],"MR7MR8MR")==NULL &&
					  strstr(final_string[line],"MR8MR3MR")==NULL && strstr(final_string[line],"MR8MR4MR")==NULL && strstr(final_string[line],"MR8MR5MR")==NULL && strstr(final_string[line],"MR8MR6MR")==NULL && strstr(final_string[line],"MR8MR7MR")==NULL && strstr(final_string[line],"MR8MR8MR")==NULL)
					strcat(final_string[line],"POS"); //sp3(N+) part of more than one ring systems
				}
				if(strlen(final_string[line])==21 && strchr(final_string[line],'2')==NULL && strchr(final_string[line],'3')==NULL)
				strcat(final_string[line],"POS");

				//if(strlen(final_string[line])==9 && strchr(final_string[line],'2') && strstr(final_string[line],"MR")==NULL && strchr(final_string[line],'4')==NULL && strstr(final_string[line],"NO2")==NULL) 
                                //strcat(final_string[line],"POS"); //sp2(N+) does not part of a ring system
				
				//if(strlen(final_string[line])==12 && strchr(final_string[line],'2') && strchr(final_string[line],'4')==NULL && strstr(final_string[line],"MR") && strstr(final_string[line],"MR4")==NULL && strstr(final_string[line],"MR5")==NULL && strstr(final_string[line],"MR6")==NULL && strstr(final_string[line],"MR7")==NULL && strstr(final_string[line],"MR8")==NULL && strstr(final_string[line],"NO2")==NULL)  
                                //strcat(final_string[line],"POS"); //sp2(N+) part of a ring system

				//if(strlen(final_string[line])==15 && strchr(final_string[line],'2') && strchr(final_string[line],'4')==NULL && strstr(final_string[line],"NO2")==NULL && (strstr(final_string[line],"MR3") || strstr(final_string[line],"MR4") || strstr(final_string[line],"MR5") || strstr(final_string[line],"MR6") || strstr(final_string[line],"MR7") || strstr(final_string[line],"MR8")))
                                //strcat(final_string[line],"POS"); //sp2(N+) part of more than one ring systems

				//if(strlen(final_string[line])==6 && strchr(final_string[line],'3') && strstr(final_string[line],"MR")==NULL)
                                //strcat(final_string[line],"POS"); //sp3(N+)
				
				//if(strlen(final_string[line])==12 && strchr(final_string[line],'4') && strstr(final_string[line],"6MR"))
                                //strcat(final_string[line],"POS"); //Aromatic-N part of a 6-membered ring system

				//if(strlen(final_string[line])==15 && strchr(final_string[line],'4') && strstr(final_string[line],"6MR") && (strstr(final_string[line],"MR3") || strstr(final_string[line],"MR4") || strstr(final_string[line],"MR5") || strstr(final_string[line],"MR6") || strstr(final_string[line],"MR7") || strstr(final_string[line],"MR8")))
                                //strcat(final_string[line],"POS"); //Aromatic-N part of more than one ring systems

				if(strlen(final_string[line])==6 && strchr(final_string[line],'2')==NULL && 
						                    strchr(final_string[line],'3')==NULL &&
								    strchr(final_string[line],'4')==NULL &&
								    strchr(final_string[line],'5')==NULL &&
								    strchr(final_string[line],'6')==NULL &&
								    strchr(final_string[line],'7')==NULL &&
								    strchr(final_string[line],'8')==NULL &&
								    strchr(final_string[line],'9')==NULL &&
								    strstr(final_string[line],"MR")==NULL)
                                strcat(final_string[line],"NEG");
				if(strlen(final_string[line])==9 && strchr(final_string[line],'2')==NULL &&
                                                                    strchr(final_string[line],'3')==NULL &&
                                                                    strstr(final_string[line],"NC4")==NULL &&
                                                                    strstr(final_string[line],"NN4")==NULL &&
                                                                    strstr(final_string[line],"NO4")==NULL &&
                                                                    strstr(final_string[line],"NS4")==NULL &&
								    strstr(final_string[line],"MR"))
                                strcat(final_string[line],"NEG");

				if((strlen(final_string[line])==9 && strstr(final_string[line],"MR")==NULL) ||
				   (strlen(final_string[line])==12 && strstr(final_string[line],"MR")) ||
				   (strlen(final_string[line])==15 && (strstr(final_string[line],"MR3") || strstr(final_string[line],"MR4") || strstr(final_string[line],"MR5") || strstr(final_string[line],"MR6") || strstr(final_string[line],"MR7"))))
				{
					if(strstr(final_string[line],"NC4")==NULL && strstr(final_string[line],"NN4")==NULL && strstr(final_string[line],"NO4")==NULL && strstr(final_string[line],"NS4")==NULL && strchr(final_string[line],'2')==NULL)
					{
					if((strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.c-1],"CO2")==NULL && strstr(strings_array[f.d-1],"CO2")==NULL) || 
					   (strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.b-1],"CO2")==NULL && strstr(strings_array[f.d-1],"CO2")==NULL) || 
					   (strstr(strings_array[f.d-1],"CO2") && strstr(strings_array[f.b-1],"CO2")==NULL && strstr(strings_array[f.c-1],"CO2")==NULL))
                                	strcat(final_string[line],"AMD");

					if((strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.c-1],"CO2")) ||
					   (strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.d-1],"CO2")) ||
					   (strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.d-1],"CO2")))
					strcat(final_string[line],"DAM");

                                	if((strstr(strings_array[f.b-1],"CS2") && strstr(strings_array[f.c-1],"CS2")==NULL && strstr(strings_array[f.d-1],"CS2")==NULL) ||
                                           (strstr(strings_array[f.c-1],"CS2") && strstr(strings_array[f.b-1],"CS2")==NULL && strstr(strings_array[f.d-1],"CS2")==NULL) ||
                                           (strstr(strings_array[f.d-1],"CS2") && strstr(strings_array[f.b-1],"CS2")==NULL && strstr(strings_array[f.c-1],"CS2")==NULL))
					strcat(final_string[line],"MTD");

					if((strstr(strings_array[f.b-1],"CS2") && strstr(strings_array[f.c-1],"CS2")) ||
                                	   (strstr(strings_array[f.b-1],"CS2") && strstr(strings_array[f.d-1],"CS2")) ||
                                	   (strstr(strings_array[f.c-1],"CS2") && strstr(strings_array[f.d-1],"CS2")))
                                	strcat(final_string[line],"DTD");

                                	if((strstr(strings_array[f.b-1],"CN2") && strlen(strings_array[f.b-1])>7 && strstr(strings_array[f.c-1],"CN2")==NULL && strstr(strings_array[f.d-1],"CN2")==NULL) || //&& strlen(strings_array[f.b-1])>7 was added on 12.24.21
                                           (strstr(strings_array[f.c-1],"CN2") && strlen(strings_array[f.c-1])>7 && strstr(strings_array[f.b-1],"CN2")==NULL && strstr(strings_array[f.d-1],"CN2")==NULL) ||    // && strlen(strings_array[f.c-1])>7 was added on 12.24.21
                                           (strstr(strings_array[f.d-1],"CN2") && strlen(strings_array[f.d-1])>7 && strstr(strings_array[f.b-1],"CN2")==NULL && strstr(strings_array[f.c-1],"CN2")==NULL))	//&& strlen(strings_array[f.d-1])>7 was added on 12.24.21
					strcat(final_string[line],"UER");

					if((strstr(strings_array[f.b-1],"CN2") && strstr(strings_array[f.c-1],"CN2")) ||
                                	   (strstr(strings_array[f.b-1],"CN2") && strstr(strings_array[f.d-1],"CN2")) ||
                                   	   (strstr(strings_array[f.c-1],"CN2") && strstr(strings_array[f.d-1],"CN2")))
                                	strcat(final_string[line],"DUR");

                                        if((strstr(strings_array[f.b-1],"CC2") && strstr(strings_array[f.c-1],"CC2")==NULL && strstr(strings_array[f.d-1],"CC2")==NULL) ||
                                           (strstr(strings_array[f.c-1],"CC2") && strstr(strings_array[f.b-1],"CC2")==NULL && strstr(strings_array[f.d-1],"CC2")==NULL) ||
                                           (strstr(strings_array[f.d-1],"CC2") && strstr(strings_array[f.b-1],"CC2")==NULL && strstr(strings_array[f.c-1],"CC2")==NULL))
					strcat(final_string[line],"NYL");

                                        if((strstr(strings_array[f.b-1],"CC2") && strstr(strings_array[f.c-1],"CC2")) ||
                                           (strstr(strings_array[f.b-1],"CC2") && strstr(strings_array[f.d-1],"CC2")) ||
                                           (strstr(strings_array[f.c-1],"CC2") && strstr(strings_array[f.d-1],"CC2")))
                                        strcat(final_string[line],"DYL");
					}
				}
                        }
			if(strncmp(final_string[line],"C",1)==0)
                        {
				if(strstr(final_string[line],"6MR6MR"))
				{
					if(strstr(strings_array[f.b-1],"6MR6MR6MR") || strstr(strings_array[f.c-1],"6MR6MR6MR") || strstr(strings_array[f.d-1],"6MR6MR6MR") || strstr(strings_array[f.e-1],"6MR6MR6MR"))
						strcat(final_string[line],"BDG");
					if(strstr(strings_array[f.b-1],"6MR5MR6MR") || strstr(strings_array[f.c-1],"6MR5MR6MR") || strstr(strings_array[f.d-1],"6MR5MR6MR") || strstr(strings_array[f.e-1],"6MR5MR6MR"))
                                                strcat(final_string[line],"BDG");
					if(strstr(strings_array[f.b-1],"6MR6MR5MR") || strstr(strings_array[f.c-1],"6MR6MR5MR") || strstr(strings_array[f.d-1],"6MR6MR5MR") || strstr(strings_array[f.e-1],"6MR6MR5MR"))
                                                strcat(final_string[line],"BDG");
					if(strstr(strings_array[f.b-1],"5MR6MR6MR") || strstr(strings_array[f.c-1],"5MR6MR6MR") || strstr(strings_array[f.d-1],"5MR6MR6MR") || strstr(strings_array[f.e-1],"5MR6MR6MR"))
                                                strcat(final_string[line],"BDG");
					if(strstr(strings_array[f.b-1],"5MR5MR5MR") || strstr(strings_array[f.c-1],"5MR5MR5MR") || strstr(strings_array[f.d-1],"5MR5MR5MR") || strstr(strings_array[f.e-1],"5MR5MR5MR"))
                                                strcat(final_string[line],"BDG");

				}
			}

			//Added on 9th September 2021
			//Start
			if(strncmp(final_string[line],"S",1)==0 && ((strlen(final_string[line])<=16 && strlen(final_string[line])>12 && strstr(final_string[line],"MR")) || (strlen(final_string[line])<=13 && strlen(final_string[line])>10 && strstr(final_string[line],"MR")==NULL)))       //SO2(=O)(O)(O); 22.(KL)
                        {
                                if(strstr(final_string[line],"SO1SO1SO1SO1")) 
                                        strcpy(final_string[line],"SO2SO2SO1SO1");

				if(strstr(final_string[line],"SO1SO1SO1") && strstr(final_string[line],"SN1"))
                                        strcpy(final_string[line],"SO2SN1SO2SO1");
				if(strstr(final_string[line],"SO1SO1SO1") && strstr(final_string[line],"SC1"))
                                        strcpy(final_string[line],"SO2SC1SO2SO1");
				
				if(strstr(final_string[line],"SN1SO1SO1") && strstr(final_string[line],"SN1"))
                                        strcpy(final_string[line],"SO2SN1SO2SN1");
                                if(strstr(final_string[line],"SN1SO1SO1") && strstr(final_string[line],"SC1"))
                                        strcpy(final_string[line],"SO2SN1SO2SC1");

				if(strstr(final_string[line],"SC1SO1SO1") && strstr(final_string[line],"SN1"))
                                        strcpy(final_string[line],"SO2SN1SO2SC1");
                                if(strstr(final_string[line],"SC1SO1SO1") && strstr(final_string[line],"SC1"))
                                        strcpy(final_string[line],"SO2SC1SO2SC1");
			
				if(strstr(final_string[line],"SO1SN1SO1") && strstr(final_string[line],"SO1"))
                                        strcpy(final_string[line],"SO2SN1SO2SO1");
                                if(strstr(final_string[line],"SO1SN1SO1") && strstr(final_string[line],"SN1"))
                                        strcpy(final_string[line],"SO2SN1SO2SN1");
				if(strstr(final_string[line],"SO1SN1SO1") && strstr(final_string[line],"SC1"))
                                        strcpy(final_string[line],"SO2SN1SO2SC1");

				if(strstr(final_string[line],"SO1SC1SO1") && strstr(final_string[line],"SO1"))
                                        strcpy(final_string[line],"SO2SC1SO2SO1");
                                if(strstr(final_string[line],"SO1SC1SO1") && strstr(final_string[line],"SN1"))
                                        strcpy(final_string[line],"SO2SC1SO2SN1");
                                if(strstr(final_string[line],"SO1SC1SO1") && strstr(final_string[line],"SC1"))
                                        strcpy(final_string[line],"SO2SC1SO2SC1");
                        }
			if(strncmp(final_string[line],"S",1)==0)
			{
				if(strstr(final_string[line],"SO1SO1SO1SF1"))
					strcpy(final_string[line],"SO2SO2SO1SF1");
				if(strstr(final_string[line],"SO1SO1SO1Sl1"))
                                        strcpy(final_string[line],"SO2SO2SO1Sl1");
				if(strstr(final_string[line],"SO1SO1SO1SB1"))
                                        strcpy(final_string[line],"SO2SO2SO1SB1");
				if(strstr(final_string[line],"SO1SO1SO1SI1"))
                                        strcpy(final_string[line],"SO2SO2SO1SI1");
				if(strstr(final_string[line],"SO1SO1") && strstr(final_string[line],"SN1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
				{
					b=strstr(final_string[line],"SO1");
						if(b)
						{
							fill5(b);
					b=strstr(final_string[line],"SO1");
                                                if(b)
						{
                                                        fill5(b);}}
				}
				if(strstr(final_string[line],"SO1SN1SO1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
                                {
                                        b=strstr(final_string[line],"SO1");
                                                if(b)
						{
                                                        fill5(b);
                                        b=strstr(final_string[line],"SO1");
                                                if(b)
						{
                                                        fill5(b);}}
                                }
				if(strstr(final_string[line],"SO1SC1SO1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
                                {
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);}}
                                }
				if(strstr(final_string[line],"SO1SO1") && strstr(final_string[line],"SC1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
                                {
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);}}
                                }
				if(strstr(final_string[line],"SO1SP1SO1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
                                {
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);}}
                                }
                                if(strstr(final_string[line],"SO1SO1") && strstr(final_string[line],"SP1") && (strstr(final_string[line],"SF1") || strstr(final_string[line],"Sl1") || strstr(final_string[line],"SB1") || strstr(final_string[line],"SI1")))
                                {
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);
                                        b=strstr(final_string[line],"SO1");
                                                if(b){
                                                        fill5(b);}}
                                }
			}
			//Correcting C-N bond order
			/*if(strncmp(final_string[line],"C",1)==0)
			{
				if(final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1' && final_string[line][11]!='1' && final_string[line][11]!='2' && final_string[line][11]!='3' && final_string[line][11]!='4' && strlen(final_string[line])>4)
						{
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
							{
								b=strstr(final_string[line],"CN1CN1CN1");
								if(b)
									fill5(b);
							}
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							//  *	
							//N-C(N)-C
							if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CN1CC1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CC1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CC1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CC1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CC1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }
							//  *
                                                        //C-C(N)-C
							if(strstr(final_string[line],"CC1CC1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CC1CN1CC1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CN1CC1CC1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }

							//  *
							//N-C(N)-O
							if(strstr(final_string[line],"CN1CO1CN1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CO1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
                                                        if(strstr(final_string[line],"CN1CO1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CO1CN1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CO1") && strings_array[f.b-1][2]=='1' && strings_array[f.b-1][5]=='1' && strings_array[f.b-1][8]!='1' && strings_array[f.b-1][8]!='2' && strings_array[f.b-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CO1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CN1CN1CO1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CN1CN1CO1");
                                                                if(b)
                                                                        fill5(b);
                                                        }
							if(strstr(final_string[line],"CO1CN1CN1") && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CO1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
                                                        }
							if(strstr(final_string[line],"CO1CN1CN1") && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                        {
                                                                b=strstr(final_string[line],"CO1CN1CN1");
                                                                if(b)
                                                                        fill7(b);
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
								}
								if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]!='1' && strings_array[f.c-1][8]!='2' && strings_array[f.c-1][8]!='4')
                                                                {
                                                                        b=strstr(final_string[line],"CN1");
                                                                        if(b)
                                                                                fill5(b);
                                                                }
								if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]!='1' && strings_array[f.d-1][8]!='2' && strings_array[f.d-1][8]!='4')
                                                                {
                                                                        b=strstr(final_string[line],"CN1");
                                                                        if(b)
                                                                                fill5(b);
                                                                }
							}

						}
			}*/





			//End
			//Added on 14 December 2021
			if(strncmp(final_string[line],"P",1)==0)
			{
				if(strstr(final_string[line],"PS1") && strchr(final_string[line],'2')==NULL)
				{
					if((strncmp(strings_array[f.b-1],"SP1", 3)==0 && strlen(strings_array[f.b-1])<=4) ||
					   (strncmp(strings_array[f.c-1],"SP1", 3)==0 && strlen(strings_array[f.c-1])<=4) ||
					   (strncmp(strings_array[f.d-1],"SP1", 3)==0 && strlen(strings_array[f.d-1])<=4) ||
					   (strncmp(strings_array[f.e-1],"SP1", 3)==0 && strlen(strings_array[f.e-1])<=4) ||
					   (strncmp(strings_array[f.b-1],"SP1NEG", 6)==0 && strlen(strings_array[f.b-1])<=7) ||
					   (strncmp(strings_array[f.c-1],"SP1NEG", 6)==0 && strlen(strings_array[f.c-1])<=7) ||
					   (strncmp(strings_array[f.d-1],"SP1NEG", 6)==0 && strlen(strings_array[f.d-1])<=7) ||
					   (strncmp(strings_array[f.e-1],"SP1NEG", 6)==0 && strlen(strings_array[f.e-1])<=7))
					{
						b=strstr(final_string[line],"PS1");
						if(b)
							fill(b);
						b=strstr(final_string[line],"POS");
                                                if(b)
                                                        fill2(b);
					}
						
				}
			}
			if(strncmp(final_string[line],"O",1)==0)
			{
				if(strstr(final_string[line],"OC4OC46MR"))
				{
					b=strstr(final_string[line],"OC4OC46MR");
						if(b)
							fill3(b);
				}
			}
			if(strncmp(final_string[line],"C",1)==0)
			{
				if((strstr(final_string[line],"CC4CC4CO46MR6MR") || strstr(final_string[line],"CC4CO4CC46MR6MR") || strstr(final_string[line],"CO4CC4CC46MR6MR")) && strlen(final_string[line])==15)
				  //(strstr(final_string[line],"6MR6MR") && strstr(final_string[line],"CO4") && strstr(final_string[line],"CN4") && strstr(final_string[line],"CC4")))
				{
					b=strstr(final_string[line],"CO4");
					if(b)
						fill4(b);
				}
				
			if(strncmp(final_string[line],"C",1)==0)
                        {
				if(final_string[line][2]=='4' && final_string[line][5]=='4' && final_string[line][8]=='2')
				{
					b=strchr(final_string[line],'2');
					if(b)
						fill6(b);
				}
				if(final_string[line][2]=='2' && final_string[line][5]=='4' && final_string[line][8]=='4')
                                {
                                        b=strchr(final_string[line],'2');
                                        if(b)
                                                fill6(b);
                                }
				if(final_string[line][2]=='4' && final_string[line][5]=='2' && final_string[line][8]=='4')
                                {
                                        b=strchr(final_string[line],'2');
                                        if(b)
                                                fill6(b);
                                }
			}	
				if((strstr(final_string[line],"6MR6MR") && strstr(final_string[line],"CO4") && strstr(final_string[line],"CN4") && strstr(final_string[line],"CC4")) && strlen(final_string[line])==15)
				{
					b=strstr(final_string[line],"CO4");
					if(b)
						fill4(b);
				}
			}
			if(strncmp(final_string[line],"N",1)==0)
			{
				if(strstr(final_string[line],"NO1NO1NO1")) 
				{
					if((strlen(strings_array[f.b-1])<=4 && strlen(strings_array[f.c-1])<=4 && strlen(strings_array[f.d-1])<=4) ||
					   (strlen(strings_array[f.b-1])==6 && strstr(strings_array[f.b-1],"ON1NEG") && strlen(strings_array[f.c-1])==6 && strstr(strings_array[f.c-1],"ON1NEG") && strlen(strings_array[f.d-1])==6 && strstr(strings_array[f.d-1],"ON1NEG")))
					{
						b=strstr(final_string[line],"NO1");
						if(b)
							fill5(b);
						b=strstr(strings_array[f.b-1],"ON1NEG");
							if(b)
								fill5(b);
					}
				}
			}
			if(strncmp(final_string[line],"N",1)==0)
			{
				if(strstr(final_string[line],"NO1NN1NEG"))
				{
					if((strings_array[f.b-1],"ON1NEG") || (strstr(strings_array[f.b-1],"ON1") && strlen(strings_array[f.b-1])<=4))
					strcpy(final_string[line],"NO2NN1");
				}
			}
			//Added condition on 12.24.2021
			if(strncmp(final_string[line],"N",1)==0)
                        {
                                if(strstr(final_string[line],"NO1") && strstr(final_string[line],"NN1") && strstr(final_string[line],"NC1"))
				{
					if(strncmp(strings_array[f.b-1],"O",1)==0 && ((strlen(strings_array[f.b-1])<=4 && strchr(strings_array[f.b-1],'2')==NULL)) || (strlen(strings_array[f.b-1])==6 && strstr(strings_array[f.b-1],"ON1NEG")))
					{
						b=strstr(final_string[line],"NO1");
						if(b)
							fill5(b);
						b=strstr(strings_array[f.b-1],"ON1");
						if(b)
							fill5(b);
					}
					if(strncmp(strings_array[f.c-1],"O",1)==0 && ((strlen(strings_array[f.c-1])<=4 && strchr(strings_array[f.c-1],'2')==NULL)) || (strlen(strings_array[f.c-1])==6 && strstr(strings_array[f.c-1],"ON1NEG")))
                                        {
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.d-1],"O",1)==0 && ((strlen(strings_array[f.d-1])<=4 && strchr(strings_array[f.d-1],'2')==NULL)) || (strlen(strings_array[f.d-1])==6 && strstr(strings_array[f.d-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
				}
				if(strstr(final_string[line],"NO1NC1NC1") || strstr(final_string[line],"NC1NO1NC1") || strstr(final_string[line],"NC1NC1NO1"))
                                {
                                        if(strncmp(strings_array[f.b-1],"O",1)==0 && ((strlen(strings_array[f.b-1])<=4 && strchr(strings_array[f.b-1],'2')==NULL)) || (strlen(strings_array[f.b-1])==6 && strstr(strings_array[f.b-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.b-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.c-1],"O",1)==0 && ((strlen(strings_array[f.c-1])<=4 && strchr(strings_array[f.c-1],'2')==NULL)) || (strlen(strings_array[f.c-1])==6 && strstr(strings_array[f.c-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.d-1],"O",1)==0 && ((strlen(strings_array[f.d-1])<=4 && strchr(strings_array[f.d-1],'2')==NULL)) || (strlen(strings_array[f.d-1])==6 && strstr(strings_array[f.d-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                }
				if(strstr(final_string[line],"NO1NO1NC1") || strstr(final_string[line],"NC1NO1NO1") || strstr(final_string[line],"NO1NC1NO1"))
                                {
                                        if(strncmp(strings_array[f.b-1],"O",1)==0 && ((strlen(strings_array[f.b-1])<=4 && strchr(strings_array[f.b-1],'2')==NULL)) || (strlen(strings_array[f.b-1])==6 && strstr(strings_array[f.b-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.b-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
					if(strncmp(strings_array[f.c-1],"O",1)==0 && ((strlen(strings_array[f.c-1])<=4 && strchr(strings_array[f.c-1],'2')==NULL)) || (strlen(strings_array[f.c-1])==6 && strstr(strings_array[f.c-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.d-1],"O",1)==0 && ((strlen(strings_array[f.d-1])<=4 && strchr(strings_array[f.d-1],'2')==NULL)) || (strlen(strings_array[f.d-1])==6 && strstr(strings_array[f.d-1],"ON1NEG")))
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                }
			}
			//New condition
                        /*if(strncmp(final_string[line],"N",1)==0)
                        {
                                if(strstr(final_string[line],"NO1") && strstr(final_string[line],"NN1") && strstr(final_string[line],"NC1"))
                                {
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
                                        {
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.b-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                }
                                if(strstr(final_string[line],"NO1NC1NC1") || strstr(final_string[line],"NC1NO1NC1") || strstr(final_string[line],"NC1NC1NO1"))
                                {
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.b-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                }
                                if(strstr(final_string[line],"NO1NO1NC1") || strstr(final_string[line],"NC1NO1NO1") || strstr(final_string[line],"NO1NC1NO1"))
                                {
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.b-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.c-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                        if(strncmp(strings_array[f.b-1],"ON1NEG",6)==0 && strlen(strings_array[f.b-1])<=9 && strlen(strings_array[f.b-1])>4)
					{
                                                b=strstr(final_string[line],"NO1");
                                                if(b)
                                                        fill5(b);
                                                b=strstr(strings_array[f.d-1],"ON1");
                                                if(b)
                                                        fill5(b);
                                        }
                                }
                        }*/
		//Condition end
		//Added on 12.24.21 for an Isocyanide group 
		if(strncmp(final_string[line],"CN4",3)==0)
		{
			if(strlen(final_string[line])<=4)
			{
				b=strchr(final_string[line],'4');
				if(b)
					fill10(b);
			}
		}
		
		if(strncmp(final_string[line],"CC4",3)==0)
                {
                        if(strlen(final_string[line])<=4)
			{
                                b=strchr(final_string[line],'4');
				if(b)
					fill10(b);
			}
                }
		
		if(strncmp(final_string[line],"C",1)==0)
                {
                        if(strlen(final_string[line])==6)
			{
				b=strchr(final_string[line],'4');
				if(b)
					fill9(b);
			}
		}

		//
		if(strncmp(final_string[line],"C",1)==0)
                {
                        if(strlen(final_string[line])==6 && strchr(final_string[line],'3')==NULL)
                        {
                                b=strchr(final_string[line],'1');
                                if(b)
                                        fill11(b);
                        }
                }
		
		if(strncmp(final_string[line],"N",1)==0)
		{
			if(strlen(final_string[line])<=7 && strstr(final_string[line],"NC4") && strstr(final_string[line],"MR")==NULL)
			{
				b=strstr(final_string[line],"NC4");
				if(b)
					fill8(b);
			}
		}

		//Condition end
			if(strncmp(final_string[line],"N",1)==0)
                        {
                                if(strstr(final_string[line],"NN1NO1NEG"))
                                {
                                        //if((strings_array[f.c-1],"ON1NEG") || strlen(strings_array[f.c-1])<=4)
					if((strings_array[f.b-1],"ON1NEG") || (strstr(strings_array[f.b-1],"ON1") && strlen(strings_array[f.b-1])<=4))
                                        strcpy(final_string[line],"NO2NN1");
                                }
                        }
			if(strncmp(final_string[line],"C",1)==0)
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
                                                        else if(b && strings_array[f.b-1][4]=='C')
                                                                fill5(b);
                                                        else if(b && strings_array[f.b-1][7]=='C')
                                                                fill5(b);
						}
						if(strncmp(strings_array[f.c-1],"N",1)==0 && strings_array[f.c-1][2]=='1' && strings_array[f.c-1][5]=='1' && strings_array[f.c-1][8]=='1' && strstr(strings_array[f.c-1],"NH1")==NULL) //A sp2 N-atom shound not be hydrogen added
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
							b=strstr(strings_array[f.c-1],"NC1");
							if(b && strings_array[f.c-1][1]=='C')
								fill5(b);
							else if(b && strings_array[f.c-1][4]=='C')
                                                                fill5(b);
							else if(b && strings_array[f.c-1][7]=='C')
                                                                fill5(b);

                                                }
						if(strncmp(strings_array[f.d-1],"N",1)==0 && strings_array[f.d-1][2]=='1' && strings_array[f.d-1][5]=='1' && strings_array[f.d-1][8]=='1' && strstr(strings_array[f.d-1],"NH1")==NULL) //A sp2 N-atom shound not be hydrogen added
                                                {
                                                        b=strstr(final_string[line],"CN1");
                                                        if(b)
                                                                fill5(b);
							b=strstr(strings_array[f.d-1],"NC1");
							if(b && strings_array[f.c-1][1]=='C')
                                                                fill5(b);
                                                        else if(b && strings_array[f.c-1][4]=='C')
                                                                fill5(b);
                                                        else if(b && strings_array[f.c-1][7]=='C')
                                                                fill5(b);
                                                }
					}
				}
			}

			//End of addition					
			if(strncmp(final_string[line],"O",1)==0 && strlen(final_string[line])>4)   //Added on 17.04.21
                	{
                        	if(strstr(strings_array[f.b-1],"SO2") || strstr(strings_array[f.c-1],"SO2"))
                        		strcat(final_string[line],"S=O");
                        	if(strstr(strings_array[f.b-1],"PO2") || strstr(strings_array[f.c-1],"PO2"))
                        		strcat(final_string[line],"P=O");
                	}

			if(strncmp(final_string[line],"N",1)==0 && final_string[line][2]=='1' && final_string[line][5]=='1' && final_string[line][8]=='1')   //Added on 17.04.21
                        {
                                if(strstr(strings_array[f.b-1],"SO2") || strstr(strings_array[f.c-1],"SO2") || strstr(strings_array[f.d-1],"SO2"))
                                        strcat(final_string[line],"S=O");
                                if(strstr(strings_array[f.b-1],"PO2") || strstr(strings_array[f.c-1],"PO2") || strstr(strings_array[f.d-1],"PO2"))
                                        strcat(final_string[line],"P=O");
                        }

			if(strncmp(final_string[line],"C",1)==0)
                        {
                                if(strstr(final_string[line],"4MR4MR"))
                                {
                                        if(strstr(strings_array[f.b-1],"4MR4MR4MR") || strstr(strings_array[f.c-1],"4MR4MR4MR") || strstr(strings_array[f.d-1],"4MR4MR4MR") || strstr(strings_array[f.e-1],"4MR4MR4MR"))
                                                strcat(final_string[line],"BDG");
				}
			}
			
			if(strncmp(final_string[line],"S",1)==0 && strstr(final_string[line],"SC2")==NULL) //strstr(final_string[line],"CS2")==NULL added on 12.18.21
                        {
                                if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.d-1],"CS2"))
                                strcat(final_string[line],"C2S");

				if(strlen(final_string[line])==9 && strchr(final_string[line],'2')==NULL && strstr(final_string[line],"MR")==NULL && strchr(final_string[line],'4')==NULL)
                                strcat(final_string[line],"POS");

				if(strlen(final_string[line])==12 && strchr(final_string[line],'2')==NULL && strstr(final_string[line],"MR") && strchr(final_string[line],'4')==NULL && 
				   strstr(final_string[line],"MR3")==NULL && strstr(final_string[line],"MR4")==NULL && strstr(final_string[line],"MR5")==NULL && strstr(final_string[line],"MR6")==NULL &&  
				   strstr(final_string[line],"MR7")==NULL)
                                strcat(final_string[line],"POS");

				if(strlen(final_string[line])==15 && strchr(final_string[line],'2')==NULL && strchr(final_string[line],'4')==NULL && (strstr(final_string[line],"MR3") ||
				   strstr(final_string[line],"MR4") || strstr(final_string[line],"MR5") || strstr(final_string[line],"MR6") || strstr(final_string[line],"MR7")))
                                strcat(final_string[line],"POS");
			}

			if(strncmp(final_string[line],"C",1)==0 && strlen(final_string[line])>7)
                        {
				if(strstr(final_string[line],"CC2") && strstr(final_string[line],"CC4")==NULL && strstr(final_string[line],"CC5")==NULL &&
                                   strstr(final_string[line],"CN4")==NULL && strstr(final_string[line],"CO4")==NULL && strstr(final_string[line],"CS4")==NULL &&
                                   strstr(final_string[line],"CC6")==NULL && strstr(final_string[line],"CN5")==NULL)
				{
					if(strstr(strings_array[f.b-1],"CO2") || strstr(strings_array[f.c-1],"CO2") || strstr(strings_array[f.d-1],"CO2"))
					strcat(final_string[line],"CJO");
					if(strstr(strings_array[f.b-1],"CN2") || strstr(strings_array[f.c-1],"CN2") || strstr(strings_array[f.d-1],"CN2"))
                                        strcat(final_string[line],"CJO");
					if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.d-1],"CS2"))
                                        strcat(final_string[line],"CJO");
					if((strstr(strings_array[f.b-1],"CC2") && strstr(strings_array[f.c-1],"CC2")) ||
                                           (strstr(strings_array[f.c-1],"CC2") && strstr(strings_array[f.d-1],"CC2")) ||
                                           (strstr(strings_array[f.d-1],"CC2") && strstr(strings_array[f.b-1],"CC2")))
                                        strcat(final_string[line],"CJC");
					//if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.c-1],"CC4") || strstr(strings_array[f.d-1],"CC4"))
                                        //	strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CC4") && (strstr(strings_array[f.c-1],"2") || strstr(strings_array[f.d-1],"2")))
						strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CC4") && (strstr(strings_array[f.c-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");
					if(strstr(strings_array[f.c-1],"CC4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.c-1],"CC4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

					if(strstr(strings_array[f.d-1],"CC4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.c-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.d-1],"CC4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.c-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

					//if(strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.c-1],"CN4") || strstr(strings_array[f.d-1],"CN4"))
                                        //strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CN4") && (strstr(strings_array[f.c-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CN4") && (strstr(strings_array[f.c-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.c-1],"CN4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.c-1],"CN4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.d-1],"CN4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.c-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.d-1],"CN4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.c-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

					//if(strstr(strings_array[f.b-1],"CS4") || strstr(strings_array[f.c-1],"CS4") || strstr(strings_array[f.d-1],"CS4"))
                                        //strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CS4") && (strstr(strings_array[f.c-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CS4") && (strstr(strings_array[f.c-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.c-1],"CS4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.c-1],"CS4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.d-1],"CS4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.c-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.d-1],"CS4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.c-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

					//if(strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.c-1],"CO4") || strstr(strings_array[f.d-1],"CO4"))
                                        //strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CO4") && (strstr(strings_array[f.c-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.b-1],"CO4") && (strstr(strings_array[f.c-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.c-1],"CO4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.d-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.c-1],"CO4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.d-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

                                        if(strstr(strings_array[f.d-1],"CO4") && (strstr(strings_array[f.b-1],"2") || strstr(strings_array[f.c-1],"2")))
                                                strcat(final_string[line],"CJB");
					if(strstr(strings_array[f.d-1],"CO4") && (strstr(strings_array[f.b-1],"2")==NULL && strstr(strings_array[f.c-1],"2")==NULL))
                                                strcat(final_string[line],"NOT");

					if(strstr(strings_array[f.b-1],"NC4") || strstr(strings_array[f.c-1],"NC4") || strstr(strings_array[f.d-1],"NC4"))
                                        strcat(final_string[line],"CNJ");
					if(strstr(strings_array[f.b-1],"NO4") || strstr(strings_array[f.c-1],"NO4") || strstr(strings_array[f.d-1],"NO4"))
                                        strcat(final_string[line],"CNJ");
					if(strstr(strings_array[f.b-1],"NN4") || strstr(strings_array[f.c-1],"NN4") || strstr(strings_array[f.d-1],"NN4"))
                                        strcat(final_string[line],"CNJ");
					if(strstr(strings_array[f.b-1],"NS4") || strstr(strings_array[f.c-1],"NS4") || strstr(strings_array[f.d-1],"NS4"))
                                        strcat(final_string[line],"CNJ");

				}
				if(strstr(final_string[line],"CN2") && strstr(final_string[line],"CC4")==NULL && strstr(final_string[line],"CC5")==NULL &&
				   strstr(final_string[line],"CN4")==NULL && strstr(final_string[line],"CO4")==NULL && strstr(final_string[line],"CS4")==NULL &&
				   strstr(final_string[line],"CC6")==NULL && strstr(final_string[line],"CN2CN2")==NULL)
				{
					if(strstr(strings_array[f.b-1],"CO2") || strstr(strings_array[f.c-1],"CO2") || strstr(strings_array[f.d-1],"CO2"))
                                        strcat(final_string[line],"CNO");
					/*if((strstr(strings_array[f.b-1],"CN2") && strstr(strings_array[f.c-1],"CN2")) || 	
					   (strstr(strings_array[f.c-1],"CN2") && strstr(strings_array[f.d-1],"CN2")) || 
					   (strstr(strings_array[f.d-1],"CN2") && strstr(strings_array[f.b-1],"CN2")))*/
					if(strstr(strings_array[f.b-1],"CN2") || strstr(strings_array[f.c-1],"CN2") || strstr(strings_array[f.d-1],"CN2"))  //Added this condition on 01.12.22
                                        strcat(final_string[line],"CNN");
					if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.d-1],"CS2"))
                                        strcat(final_string[line],"CNS");
					if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.c-1],"CC4") || strstr(strings_array[f.d-1],"CC4"))
                                        strcat(final_string[line],"CNB");
					if(strstr(strings_array[f.b-1],"CC5") || strstr(strings_array[f.c-1],"CC5") || strstr(strings_array[f.d-1],"CC5"))
                                        strcat(final_string[line],"CNB");
					if(strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.c-1],"CN4") || strstr(strings_array[f.d-1],"CN4"))
                                        strcat(final_string[line],"CNB");
					if(strstr(strings_array[f.b-1],"CS4") || strstr(strings_array[f.c-1],"CS4") || strstr(strings_array[f.d-1],"CS4"))
                                        strcat(final_string[line],"CNB");
					if(strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.c-1],"CO4") || strstr(strings_array[f.d-1],"CO4"))
                                        strcat(final_string[line],"CNB");
					if(strstr(strings_array[f.b-1],"NC4") || strstr(strings_array[f.c-1],"NC4") || strstr(strings_array[f.d-1],"NC4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NO4") || strstr(strings_array[f.c-1],"NO4") || strstr(strings_array[f.d-1],"NO4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NN4") || strstr(strings_array[f.c-1],"NN4") || strstr(strings_array[f.d-1],"NN4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NS4") || strstr(strings_array[f.c-1],"NS4") || strstr(strings_array[f.d-1],"NS4"))
                                        strcat(final_string[line],"CNJ");
				}
				if(strstr(final_string[line],"CO2") && strstr(final_string[line],"CC4")==NULL && strstr(final_string[line],"CC5")==NULL &&
                                   strstr(final_string[line],"CN4")==NULL && strstr(final_string[line],"CO4")==NULL && strstr(final_string[line],"CS4")==NULL &&
                                   strstr(final_string[line],"CC6")==NULL && strstr(final_string[line],"CO2CO2")==NULL)
                                {
					/*if((strstr(strings_array[f.b-1],"CO2") && strstr(strings_array[f.c-1],"CO2")) ||
                                           (strstr(strings_array[f.c-1],"CO2") && strstr(strings_array[f.d-1],"CO2")) ||
                                           (strstr(strings_array[f.d-1],"CO2") && strstr(strings_array[f.b-1],"CO2")))*/
					if(strstr(strings_array[f.b-1],"CO2") || strstr(strings_array[f.c-1],"CO2") || strstr(strings_array[f.d-1],"CO2"))  //Added this condition on 01.12.22
                                        strcat(final_string[line],"COO");
					if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.d-1],"CS2"))
                                        strcat(final_string[line],"COS");
					if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.c-1],"CC4") || strstr(strings_array[f.d-1],"CC4"))
                                        strcat(final_string[line],"COB");
                                        if(strstr(strings_array[f.b-1],"CC5") || strstr(strings_array[f.c-1],"CC5") || strstr(strings_array[f.d-1],"CC5"))
                                        strcat(final_string[line],"COB");
                                        if(strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.c-1],"CN4") || strstr(strings_array[f.d-1],"CN4"))
                                        strcat(final_string[line],"COB");
                                        if(strstr(strings_array[f.b-1],"CS4") || strstr(strings_array[f.c-1],"CS4") || strstr(strings_array[f.d-1],"CS4"))
                                        strcat(final_string[line],"COB");
                                        if(strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.c-1],"CO4") || strstr(strings_array[f.d-1],"CO4"))
                                        strcat(final_string[line],"COB");
					if(strstr(strings_array[f.b-1],"NC4") || strstr(strings_array[f.c-1],"NC4") || strstr(strings_array[f.d-1],"NC4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NO4") || strstr(strings_array[f.c-1],"NO4") || strstr(strings_array[f.d-1],"NO4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NN4") || strstr(strings_array[f.c-1],"NN4") || strstr(strings_array[f.d-1],"NN4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NS4") || strstr(strings_array[f.c-1],"NS4") || strstr(strings_array[f.d-1],"NS4"))
                                        strcat(final_string[line],"CNJ");
				}
				if(strstr(final_string[line],"CS2") && strstr(final_string[line],"CC4")==NULL && strstr(final_string[line],"CC5")==NULL &&
                                   strstr(final_string[line],"CN4")==NULL && strstr(final_string[line],"CO4")==NULL && strstr(final_string[line],"CS4")==NULL &&
                                   strstr(final_string[line],"CC6")==NULL && strstr(final_string[line],"CS2CS2")==NULL)
                                {
					/*if((strstr(strings_array[f.b-1],"CS2") && strstr(strings_array[f.c-1],"CS2")) ||
                                           (strstr(strings_array[f.c-1],"CS2") && strstr(strings_array[f.d-1],"CS2")) ||
                                           (strstr(strings_array[f.d-1],"CS2") && strstr(strings_array[f.b-1],"CS2")))*/
					if(strstr(strings_array[f.b-1],"CS2") || strstr(strings_array[f.c-1],"CS2") || strstr(strings_array[f.d-1],"CS2"))  //Added this condition on 01.12.22
                                        strcat(final_string[line],"CSS");
					if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.c-1],"CC4") || strstr(strings_array[f.d-1],"CC4"))
                                        strcat(final_string[line],"CSB");
                                        if(strstr(strings_array[f.b-1],"CC5") || strstr(strings_array[f.c-1],"CC5") || strstr(strings_array[f.d-1],"CC5"))
                                        strcat(final_string[line],"CSB");
                                        if(strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.c-1],"CN4") || strstr(strings_array[f.d-1],"CN4"))
                                        strcat(final_string[line],"CSB");
                                        if(strstr(strings_array[f.b-1],"CS4") || strstr(strings_array[f.c-1],"CS4") || strstr(strings_array[f.d-1],"CS4"))
                                        strcat(final_string[line],"CSB");
                                        if(strstr(strings_array[f.b-1],"CO4") || strstr(strings_array[f.c-1],"CO4") || strstr(strings_array[f.d-1],"CO4"))
                                        strcat(final_string[line],"CSB");
					if(strstr(strings_array[f.b-1],"NC4") || strstr(strings_array[f.c-1],"NC4") || strstr(strings_array[f.d-1],"NC4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NO4") || strstr(strings_array[f.c-1],"NO4") || strstr(strings_array[f.d-1],"NO4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NN4") || strstr(strings_array[f.c-1],"NN4") || strstr(strings_array[f.d-1],"NN4"))
                                        strcat(final_string[line],"CNJ");
                                        if(strstr(strings_array[f.b-1],"NS4") || strstr(strings_array[f.c-1],"NS4") || strstr(strings_array[f.d-1],"NS4"))
                                        strcat(final_string[line],"CNJ");
                                }
			}
			if(strncmp(final_string[line],"N",1)==0)
                        {
				if(strstr(final_string[line],"NC2"))
                                {
					if((strstr(strings_array[f.b-1],"CO2") && strlen(strings_array[f.b-1])>7) || (strstr(strings_array[f.c-1],"CO2") && strlen(strings_array[f.c-1])>7))
						strcat(final_string[line],"NJO");
					if((strstr(strings_array[f.b-1],"CC2") && strlen(strings_array[f.b-1])>7) || (strstr(strings_array[f.c-1],"CC2") && strlen(strings_array[f.c-1])>7))
                                                strcat(final_string[line],"NJC");

					if(strstr(strings_array[f.b-1],"CN2") && strlen(strings_array[f.b-1])>7 && strstr(strings_array[f.c-1],"CN2") && strlen(strings_array[f.c-1])>7)
                                                strcat(final_string[line],"NJN");

					if((strstr(strings_array[f.b-1],"CS2") && strlen(strings_array[f.b-1])>7) || (strstr(strings_array[f.c-1],"CS2") && strlen(strings_array[f.c-1])>7))
                                                strcat(final_string[line],"NJS");
					
					if((strstr(strings_array[f.b-1],"CC4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"CC4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"CC4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NJB");

					if((strstr(strings_array[f.b-1],"CC5") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"CC5") && strstr(strings_array[f.c-1],"CN2")==NULL))
                                                strcat(final_string[line],"NJB");

					if((strstr(strings_array[f.b-1],"CN4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"CN4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"CN4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NJB");

					if((strstr(strings_array[f.b-1],"CO4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"CO4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"CO4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NJB");

					if((strstr(strings_array[f.b-1],"CS4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"CS4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"CS4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NJB");

					if((strstr(strings_array[f.b-1],"NC4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"NC4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"NC4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NNJ");

					if((strstr(strings_array[f.b-1],"NN4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"NN4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"NN4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NNJ");

					if((strstr(strings_array[f.b-1],"NO4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"NO4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"NO4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NNJ");
					
					if((strstr(strings_array[f.b-1],"NS4") && strstr(strings_array[f.b-1],"CN2")==NULL) || (strstr(strings_array[f.c-1],"NS4") && strstr(strings_array[f.c-1],"CN2")==NULL) || (strstr(strings_array[f.d-1],"NS4") && strstr(strings_array[f.d-1],"CN2")==NULL))
                                                strcat(final_string[line],"NNJ");
				}
			}
			if(strncmp(final_string[line],"H",1)==0)
                        {
                        	if(strstr(final_string[line],"HC1"))
                                {
					if(strstr(strings_array[f.b-1],"CC4") || strstr(strings_array[f.b-1],"CN4") || strstr(strings_array[f.b-1],"CS4") || strstr(strings_array[f.b-1],"CO4"))
						strcat(final_string[line],"ARM");
				}
				if(strstr(final_string[line],"HN1"))
                                {
				if(strstr(strings_array[f.b-1],"NC4") || strstr(strings_array[f.b-1],"NN4") || strstr(strings_array[f.b-1],"NS4") || strstr(strings_array[f.b-1],"NO4"))
					strcat(final_string[line],"IMD");
				}
			}
		//Added on 12.25.21 for NN2-NN1 bond
		if(strncmp(final_string[line],"N",1)==0)
		{
			if(strstr(final_string[line],"NN1") && strchr(final_string[line],'2')==NULL && 
			  strstr(final_string[line],"NC4")==NULL && strstr(final_string[line],"NN4")==NULL &&
			  strstr(final_string[line],"NO4")==NULL && strstr(final_string[line],"NS4")==NULL)
			{
				if(strlen(final_string[line])>7)
				{
					if(strstr(strings_array[f.b-1],"NN2") || strstr(strings_array[f.c-1],"NN2") || strstr(strings_array[f.d-1],"NN2"))
						strcat(final_string[line],"AZD");
				}
			}
		}
		// For sp2 N-atom of NN2-NN1 bond
		if(strncmp(final_string[line],"N",1)==0)
		{
			if(strstr(final_string[line],"NN2") && strstr(final_string[line],"NC1") && strstr(final_string[line],"NN1")==NULL)
			{
				if((strstr(strings_array[f.b-1],"NN1") && strstr(strings_array[f.b-1],"NN2")) || 
				   (strstr(strings_array[f.c-1],"NN1") && strstr(strings_array[f.c-1],"NN2")) || 
				   (strstr(strings_array[f.d-1],"NN1") && strstr(strings_array[f.d-1],"NN2")))
					strcat(final_string[line],"NDZ");
			}
		}

		if(strncmp(final_string[line],"S",1)==0)
		{
			if(strstr(final_string[line],"SO2") && strstr(final_string[line],"MR"))
			{
				b=strstr(final_string[line],"SC4");
				if(b)
					fill4(b);
				b=strstr(final_string[line],"SN4");
				if(b)
					fill4(b);
				b=strstr(final_string[line],"SO4");
                                if(b)
                                        fill4(b);
			}
		}
		if(strncmp(final_string[line],"S",1)==0)
                {
                        if(strstr(final_string[line],"SO2") && strstr(final_string[line],"MR"))
                        {
                                b=strstr(final_string[line],"SC4");
                                if(b)
                                        fill4(b);
                                b=strstr(final_string[line],"SN4");
                                if(b)
                                        fill4(b);
                                b=strstr(final_string[line],"SO4");
                                if(b)
                                        fill4(b);
                        }
                }

		//End condition

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
        *(a+i)='3';
      }

void fill9(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='2';
	for(i=3;i<4;i++)
        *(a+i)='2';
      }

void fill10(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='3';
      }

void fill11(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='2';
      }
//End of addition

/*
 * Written by Goutam Mukherjee
 * Purpose: This program compute the formal charge of sp2 nitrogen atom and print the charge if contains >0 formal charge.
 * How to run:
 * ./check_fc_imidazole.exe <Output file of lp44.exe and lp7.exe>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
        FILE *fr;
        char st[4];
        char st1[2], st2[2], st3[2], st4[2];
	int bo1=0, bo2=0, bo3=0, bo4=0, sum=0;
        int line=0;
        int fn1=0;
	int count=0;
	int count1=0;
	char str[100], s[100], s1[100];
        fr=fopen(argv[1],"r");
	if (argc<2) {
	printf("./check_fc_imidazole.exe <Output file of lp44.exe and lp7.exe>\n");
	exit(1);
	}
        while(fgets(str,100,fr)!=NULL)
        {
		sscanf(str,"%s %s", s, s1);
		//sscanf(str,"%s", s);
                st[0]=s[12];
                st[1]=s[13];
                st[2]=s[14];
                st[3]='\0';

                st1[0]=s[2];
                st1[1]='\0';

                st2[0]=s[5];
                st2[1]='\0';

                st3[0]=s[8];
                st3[1]='\0';

                st4[0]=s[11];
                st4[1]='\0';

		bo1=atoi(st1);
		bo2=atoi(st2);
		bo3=atoi(st3);
		bo4=atoi(st4);

		if(bo1!=4 && bo2!=4 && bo3!=4 && bo4!=4)	
		sum=bo1+bo2+bo3+bo4;

		if(strncmp(s,"N",1)==0)
		{
			//if(strlen(s)==9 && strchr(s,'2') && strstr(s,"MR")==NULL && strstr(s,"NO2")==NULL && strchr(s,'3')==NULL && strstr(s,"NH1")==NULL)
                         //       fn1=fn1+1;  //Cationic sp2-(N) does not part of a ring system

			//if(strlen(s)==6 && strchr(st1,'2') && strchr(st2,'2') && strstr(s,"NO2")==NULL && strstr(s,"NN2NN2")==NULL && strstr(s,"MR")==NULL)
                         //       fn1=fn1+1; //Cationic sp-(N) does not part of a ring system

			if(strlen(s)==6 && strchr(s,'3') && strstr(s,"NO2")==NULL && strstr(s,"MR")==NULL)
                                fn1=fn1+1; //Cationic sp-(N) does not part of a ring system

                        /*if(strlen(s)==12 && strchr(s,'2') && strstr(s,"NO2")==NULL && strstr(s,"6MR") && strstr(s,"MR4")==NULL && strstr(s,"MR5")==NULL && strstr(s,"MR6")==NULL && strstr(s,"MR7")==NULL && strstr(s,"MR8")==NULL)
			{
				if(strstr(s1,"NC4NC4NH1")==NULL && strstr(s1,"NC4NH1NC4")==NULL && strstr(s1,"NH1NC4NC4")==NULL && 
				   strstr(s1,"NC4NC4NC1")==NULL && strstr(s1,"NC4NC1NC4")==NULL && strstr(s1,"NC4NC4NO1")==NULL  && 
				   strstr(s1,"NC4NO1NC4")==NULL && strstr(s1,"NC4NC4NN1")==NULL && strstr(s1,"NC4NN1NC4")==NULL  && 
				   strstr(s1,"NC4NC4NS1")==NULL && strstr(s1,"NC4NS1NC4")==NULL && strstr(s1,"NC1NC4NC4")==NULL  && 
				   strstr(s1,"NN1NC4NC4")==NULL && strstr(s1,"NS1NC4NC4")==NULL && strstr(s1,"NO1NC4NC4")==NULL  &&
				   strstr(s1,"NN4NC4")==NULL && strstr(s1,"NC4NN4")==NULL && strstr(s1,"NN4NN4")==NULL)
                                fn1=fn1+1; //Cationic sp2-(N) part of a ring system
			}
			if(strlen(s)==12 && strchr(s,'2') && strstr(s,"NO2")==NULL && strstr(s,"MR") && strstr(s,"6MR")==NULL && strstr(s,"MR4")==NULL && strstr(s,"MR5")==NULL && strstr(s,"MR6")==NULL && strstr(s,"MR7")==NULL && strstr(s,"MR8")==NULL)
			{
				if(strstr(s1,"NC4NC4NH1")==NULL && strstr(s1,"NC4NH1NC4")==NULL && strstr(s1,"NH1NC4NC4")==NULL &&
                                   strstr(s1,"NC4NC4NC1")==NULL && strstr(s1,"NC4NC1NC4")==NULL && strstr(s1,"NC4NC4NO1")==NULL  &&
                                   strstr(s1,"NC4NO1NC4")==NULL && strstr(s1,"NC4NC4NN1")==NULL && strstr(s1,"NC4NN1NC4")==NULL  &&
                                   strstr(s1,"NC4NC4NS1")==NULL && strstr(s1,"NC4NS1NC4")==NULL && strstr(s1,"NC1NC4NC4")==NULL  &&
                                   strstr(s1,"NN1NC4NC4")==NULL && strstr(s1,"NS1NC4NC4")==NULL && strstr(s1,"NO1NC4NC4")==NULL  &&
                                   strstr(s1,"NN4NC4")==NULL && strstr(s1,"NC4NN4")==NULL && strstr(s1,"NN4NN4")==NULL)
					fn1=fn1+1;
			}*/
		}

			if(strncmp(s,"N",1)==0)
			{
				if(strstr(s,"NO2")==NULL && strchr(s,'2') && strlen(s)==9 && strstr(s,"MR")==NULL && strstr(s1,"S=O")==NULL && strstr(s1,"P=O")==NULL && strchr(s1,'2'))
					fn1=fn1+1;
				
				if((strstr(s,"NO2")==NULL && strchr(s,'2') && strlen(s)==12 && strstr(s,"MR") && strstr(s,"MR3")==NULL && strstr(s,"MR4")==NULL && strstr(s,"MR5")==NULL && strstr(s,"MR6")==NULL && strstr(s,"MR7")==NULL && strstr(s1,"S=O")==NULL && strstr(s1,"P=O")==NULL && strchr(s1,'2')) || (strchr(s1,'2') && strlen(s1)==12 && strstr(s1,"NO2")==NULL))
				{
					if(strstr(s1,"ARX")==NULL && strstr(s1,"C=C")==NULL && strstr(s1,"NEG")==NULL && strstr(s1,"POS")==NULL && strstr(s1,"EST")==NULL && strstr(s1,"DST")==NULL &&
					   strstr(s1,"DIN")==NULL && strstr(s1,"OTD")==NULL && strstr(s1,"ODD")==NULL && strstr(s1,"DON")==NULL && strstr(s1,"ENL")==NULL && strstr(s1,"ELN")==NULL &&
					   strstr(s1,"ENE")==NULL && strstr(s1,"DNE")==NULL && strstr(s1,"OCN")==NULL && strstr(s1,"DCN")==NULL && strstr(s1,"NTO")==NULL && strstr(s1,"CO3")==NULL &&
					   strstr(s1,"AMD")==NULL && strstr(s1,"DAM")==NULL && strstr(s1,"MTD")==NULL && strstr(s1,"DTD")==NULL && strstr(s1,"UER")==NULL && strstr(s1,"DUR")==NULL &&
					   strstr(s1,"NYL")==NULL && strstr(s1,"DYL")==NULL && strstr(s1,"BDG")==NULL && strstr(s1,"C2S")==NULL && strstr(s1,"CJO")==NULL && strstr(s1,"CJC")==NULL &&
					   strstr(s1,"CJB")==NULL && strstr(s1,"CNJ")==NULL && strstr(s1,"CNO")==NULL && strstr(s1,"CNN")==NULL && strstr(s1,"CNS")==NULL && strstr(s1,"CNB")==NULL &&
					   strstr(s1,"COO")==NULL && strstr(s1,"COS")==NULL && strstr(s1,"COB")==NULL && strstr(s1,"CSS")==NULL && strstr(s1,"CSB")==NULL && strstr(s1,"NJO")==NULL &&
					   strstr(s1,"NJC")==NULL && strstr(s1,"NJN")==NULL && strstr(s1,"NJS")==NULL && strstr(s1,"NJB")==NULL && strstr(s1,"NNJ")==NULL && strstr(s1,"ARM")==NULL &&
					   strstr(s1,"IMD")==NULL && strstr(s1,"NOT")==NULL && strstr(s1,"AZD")==NULL && strstr(s1,"NDZ")==NULL &&
					   strstr(s,"ARX")==NULL && strstr(s,"C=C")==NULL && strstr(s,"NEG")==NULL && strstr(s,"POS")==NULL && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL && 
					   strstr(s,"DIN")==NULL && strstr(s,"OTD")==NULL && strstr(s,"ODD")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENL")==NULL && strstr(s,"ELN")==NULL && 
					   strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strstr(s,"OCN")==NULL && strstr(s,"DCN")==NULL && strstr(s,"NTO")==NULL && strstr(s,"CO3")==NULL && 
					   strstr(s,"AMD")==NULL && strstr(s,"DAM")==NULL && strstr(s,"MTD")==NULL && strstr(s,"DTD")==NULL && strstr(s,"UER")==NULL && strstr(s,"DUR")==NULL && 
					   strstr(s,"NYL")==NULL && strstr(s,"DYL")==NULL && strstr(s,"BDG")==NULL && strstr(s,"C2S")==NULL && strstr(s,"CJO")==NULL && strstr(s,"CJC")==NULL && 
					   strstr(s,"CJB")==NULL && strstr(s,"CNJ")==NULL && strstr(s,"CNO")==NULL && strstr(s,"CNN")==NULL && strstr(s,"CNS")==NULL && strstr(s,"CNB")==NULL && 
					   strstr(s,"COO")==NULL && strstr(s,"COS")==NULL && strstr(s,"COB")==NULL && strstr(s,"CSS")==NULL && strstr(s,"CSB")==NULL && strstr(s,"NJO")==NULL && 
					   strstr(s,"NJC")==NULL && strstr(s,"NJN")==NULL && strstr(s,"NJS")==NULL && strstr(s,"NJB")==NULL && strstr(s,"NNJ")==NULL && strstr(s,"ARM")==NULL && 
					   strstr(s,"IMD")==NULL && strstr(s,"NOT")==NULL && strstr(s,"AZD")==NULL && strstr(s,"NDZ")==NULL)

					fn1=fn1+1;
				}

				if((strstr(s,"NO2")==NULL && strchr(s,'2') && strstr(s1,"S=O")==NULL && strstr(s1,"P=O")==NULL && strchr(s1,'2') && strlen(s)==15 && (strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7"))) || (strchr(s1,'2') && strlen(s1)==15 && strstr(s1,"NO2")==NULL))
				{
					if(strstr(s1,"ARX")==NULL && strstr(s1,"C=C")==NULL && strstr(s1,"NEG")==NULL && strstr(s1,"POS")==NULL && strstr(s1,"EST")==NULL && strstr(s1,"DST")==NULL &&
                                           strstr(s1,"DIN")==NULL && strstr(s1,"OTD")==NULL && strstr(s1,"ODD")==NULL && strstr(s1,"DON")==NULL && strstr(s1,"ENL")==NULL && strstr(s1,"ELN")==NULL &&
                                           strstr(s1,"ENE")==NULL && strstr(s1,"DNE")==NULL && strstr(s1,"OCN")==NULL && strstr(s1,"DCN")==NULL && strstr(s1,"NTO")==NULL && strstr(s1,"CO3")==NULL &&
                                           strstr(s1,"AMD")==NULL && strstr(s1,"DAM")==NULL && strstr(s1,"MTD")==NULL && strstr(s1,"DTD")==NULL && strstr(s1,"UER")==NULL && strstr(s1,"DUR")==NULL &&
                                           strstr(s1,"NYL")==NULL && strstr(s1,"DYL")==NULL && strstr(s1,"BDG")==NULL && strstr(s1,"C2S")==NULL && strstr(s1,"CJO")==NULL && strstr(s1,"CJC")==NULL &&
                                           strstr(s1,"CJB")==NULL && strstr(s1,"CNJ")==NULL && strstr(s1,"CNO")==NULL && strstr(s1,"CNN")==NULL && strstr(s1,"CNS")==NULL && strstr(s1,"CNB")==NULL &&
                                           strstr(s1,"COO")==NULL && strstr(s1,"COS")==NULL && strstr(s1,"COB")==NULL && strstr(s1,"CSS")==NULL && strstr(s1,"CSB")==NULL && strstr(s1,"NJO")==NULL &&
                                           strstr(s1,"NJC")==NULL && strstr(s1,"NJN")==NULL && strstr(s1,"NJS")==NULL && strstr(s1,"NJB")==NULL && strstr(s1,"NNJ")==NULL && strstr(s1,"ARM")==NULL &&
                                           strstr(s1,"IMD")==NULL && strstr(s1,"NOT")==NULL && strstr(s1,"AZD")==NULL && strstr(s1,"NDZ")==NULL &&
                                           strstr(s,"ARX")==NULL && strstr(s,"C=C")==NULL && strstr(s,"NEG")==NULL && strstr(s,"POS")==NULL && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL &&
                                           strstr(s,"DIN")==NULL && strstr(s,"OTD")==NULL && strstr(s,"ODD")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENL")==NULL && strstr(s,"ELN")==NULL &&
                                           strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strstr(s,"OCN")==NULL && strstr(s,"DCN")==NULL && strstr(s,"NTO")==NULL && strstr(s,"CO3")==NULL &&
                                           strstr(s,"AMD")==NULL && strstr(s,"DAM")==NULL && strstr(s,"MTD")==NULL && strstr(s,"DTD")==NULL && strstr(s,"UER")==NULL && strstr(s,"DUR")==NULL &&
                                           strstr(s,"NYL")==NULL && strstr(s,"DYL")==NULL && strstr(s,"BDG")==NULL && strstr(s,"C2S")==NULL && strstr(s,"CJO")==NULL && strstr(s,"CJC")==NULL &&
                                           strstr(s,"CJB")==NULL && strstr(s,"CNJ")==NULL && strstr(s,"CNO")==NULL && strstr(s,"CNN")==NULL && strstr(s,"CNS")==NULL && strstr(s,"CNB")==NULL &&
                                           strstr(s,"COO")==NULL && strstr(s,"COS")==NULL && strstr(s,"COB")==NULL && strstr(s,"CSS")==NULL && strstr(s,"CSB")==NULL && strstr(s,"NJO")==NULL &&
                                           strstr(s,"NJC")==NULL && strstr(s,"NJN")==NULL && strstr(s,"NJS")==NULL && strstr(s,"NJB")==NULL && strstr(s,"NNJ")==NULL && strstr(s,"ARM")==NULL &&
                                           strstr(s,"IMD")==NULL && strstr(s,"NOT")==NULL && strstr(s,"AZD")==NULL && strstr(s,"NDZ")==NULL)
                                        fn1=fn1+1;
				}
			}

			if(strncmp(s,"N",1)==0 && strlen(s)==12 && strchr(s,'2') && strstr(s,"NO2")==NULL && strstr(s,"MR")==NULL && (strstr(s,"UER") || strstr(s,"DUR") || strstr(s,"NYL") || strstr(s,"DYL")))
                                fn1=fn1+1;

                        //if(strncmp(s,"N",1)==0 && strlen(s)==15 && strchr(s,'2') && strstr(s,"NO2")==NULL && (strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7") || strstr(s,"MR8")))
                        //        fn1=fn1+1;  //Cationic sp2-(N) part of more than one ring systems

		if(strncmp(s,"C",1)==0 && strstr(s,"IMZ") && strstr(s,"NOT")==NULL)// && strstr(s1,"CN4")==NULL)
			fn1=fn1+1;

	//Edited on 12.21.21
/*	if(strncmp(s,"C",1)==0)
	{
		if(strlen(s)<=10 && strlen(s)>6)
		{
			if(strchr(st1,'1') && strchr(st2,'1') && strchr(st3,'1'))
			{
				if(strstr(s,"CN1"))
				fn1=fn1+1;		//Cationic sp2-(N)
			}
		}
		if(strlen(s)>10)
		{
			if(strchr(st1,'1') && strchr(st2,'1') && strchr(st3,'1') && strchr(st4,'1')==NULL && strchr(st4,'2')==NULL && strchr(st4,'3')==NULL && strchr(st4,'4')==NULL)
			{
				if(strstr(s,"CN1"))
					fn1=fn1+1;              //Cationic sp2-(N)
			}
		}
	}*/
}
	//End of addition
		printf("fn0 (Aromatic/sp2/sp-(N)-charge) = %d\n", fn1);
	fclose(fr);
	}

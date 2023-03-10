/*
 * Written by Goutam Mukherjee
 * Purpose: Print functional groups present in a molecule.
 * A list of functional group is found at the following file name: functional_group_info.txt
 * How to run:
 * ./lp8.exe <Output of lp7.exe>
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
void fill(char *);
void fill1(char *);
        char *b;
        FILE *fr;
	if (argc<2) {
  	printf("./lp8.exe <Output of lp7.exe>\n");
  	exit(1);
	}
	char st[4];
	char st1[2], st2[2], st3[2], st4[2];
	int line=0;
	int count=0;
	int fn1=0, fn2=0, fn3=0, fn4=0, fn5=0, fn6=0, fn7=0, fn8=0, fn9=0, f10=0;
	int f11=0, f12=0, f13=0, f14=0, f15=0;
        int f16=0,f17=0,f18=0,f19=0,f20=0,f21=0,f22=0,f23=0,f24=0,f25=0,f26=0,f27=0,f28=0,f29=0,f30=0,f31=0,f32=0,f33=0,f34=0,f35=0,f36=0,f37=0,f38=0,f39=0,f40=0,f41=0,f42=0,f43=0,f44=0,f45=0,f46=0,f47=0,f48=0,f49=0,f50=0,f51=0,f52=0,f53=0,f54=0,f55=0,f56=0,f57=0,f58=0,f59=0,f60=0,f61=0,f62=0,f63=0,f64=0,f65=0,f66=0,f67=0,f68=0,f69=0,f70=0,f71=0,f72=0,f73=0,f74=0,f75=0,f76=0,f77=0,f78=0,f79=0,f80=0,f81=0,f82=0,f83=0,f84=0,f85=0,f86=0,f87=0,f88=0,f89=0,f90=0,f91=0,f92=0,f93=0,f94=0,f95=0,f96=0,f97=0,f98=0,f99=0,f100=0, f101=0, f102=0;
	int f103=0, f104=0;
	int f105=0, f106=0, f107=0, f108=0, f109=0, f110=0, f111=0, f112=0, f113=0, f114=0, f115=0, f116=0, f117=0, f118=0, f119=0, f120=0, f121=0, f122=0, f123=0, f124=0, f125=0, f126=0, f127=0, f128=0, f129=0, f130=0, f131=0, f132=0, f133=0, f134=0, f135=0, f136=0, f137=0, f138=0, f139=0, f140=0, f141=0, f142=0, f143=0, f144=0, f145=0, f146=0, f147=0, f148=0, f149=0, f150=0;
	int f151=0, f152=0, f153=0, f154=0, f155=0, f156=0, f157=0, f158=0, f159=0, f160=0, f161=0, f162=0, f163=0, f164=0, f165=0, f166=0, f167=0, f168=0, f169=0, f170=0, f171=0, f172=0, f173=0, f174=0, f175=0;
	int f176=0, f177=0, f178=0, f179=0, f180=0, f181=0, f182=0, f183=0, f184=0, f185=0, f186=0, f187=0, f188=0, f189=0, f190=0, f191=0, f192=0, f193=0, f194=0, f195=0, f196=0, f197=0, f198=0, f199=0, f200=0, f201=0, f202=0, f203=0, f204=0, f205=0, f206=0, f207=0, f208=0, f209=0, f210=0, f211=0, f212=0, f213=0, f214=0, f215=0, f216=0, f217=0, f218=0, f219=0, f220=0, f221=0, f222=0, f223=0, f224=0, f225=0, f226=0, f227=0, f228=0, f229=0, f230=0, f231=0, f232=0, f233=0, f234=0, f235=0, f236=0, f237=0, f238=0, f239=0, f240=0, f241=0, f242=0, f243=0, f244=0, f245=0, f246=0, f247=0, f248=0, f249=0, f250=0, f251=0, f252=0, f253=0;

	int f254=0, f255=0, f256=0, f257=0, f258=0, f259=0, f260=0, f261=0, f262=0, f263=0, f264=0, f265=0, f266=0, f267=0, f268=0, f269=0, f270=0, f271=0, f272=0, f273=0, f274=0, f275=0, f276=0, f277=0, f278=0, f279=0, f280=0, f281=0, f282=0, f283=0, f284=0, f285=0, f286=0, f287=0, f288=0, f289=0, f290=0, f291=0;

	int f292=0, f293=0, f294=0, f295=0, f296=0, f297=0, f298=0, f299=0, f300=0, f301=0, f302=0, f303=0, f304=0, f305=0, f306=0, f307=0, f308=0, f309=0, f310=0, f311=0, f312=0, f313=0, f314=0, f315=0, f316=0, f317=0, f318=0, f319=0, f320=0, f321=0, f322=0, f323=0, f324=0, f325=0, f326=0, f327=0, f328=0, f329=0, f330=0, f331=0, f332=0, f333=0, f334=0, f335=0, f336=0, f337=0, f338=0, f339=0, f340=0, f341=0, f342=0, f343=0, f344=0, f345=0, f346=0, f347=0, f348=0, f349=0, f350=0, f351=0;

	int f352=0,f353=0,f354=0,f355=0,f356=0,f357=0,f358=0,f359=0,f360=0,f361=0,f362=0,f363=0,f364=0,f365=0,f366=0,f367=0,f368=0,f369=0,f370=0,f371=0,f372=0,f373=0,f374=0,f375=0,f376=0,f377=0,f378=0,f379=0,f380=0,f381=0,f382=0,f383=0,f384=0,f385=0,f386=0,f387=0,f388=0,f389=0,f390=0,f391=0,f392=0,f393=0,f394=0,f395=0,f396=0,f397=0,f398=0,f399=0,f400=0,f401=0,f402=0,f403=0,f404=0,f405=0,f406=0,f407=0,f408=0,f409=0, f410=0, f411=0, f412=0, f413=0, f414=0, f415=0, f416=0, f417=0, f418=0, f419=0, f420=0, f421=0, f422=0, f423=0, f424=0, f425=0, f426=0, f427=0, f428=0, f429=0, f430=0, f431=0, f432=0, f433=0, f434=0, f435=0, f436=0, f437=0, f438=0, f439=0, f440=0, f441=0, f442=0, f443=0, f444=0, f445=0, f446=0, f447=0, f448=0, f449=0, f450=0, f451=0, f452=0, f453=0;

	int f454=0, f455=0, f456=0, f457=0, f458=0, f459=0, f460=0, f461=0, f462=0, f463=0, f464=0, f465=0, f466=0, f467=0, f468=0, f469=0, f470=0, f471=0, f472=0, f473=0, f474=0, f475=0, f476=0, f477=0, f478=0, f479=0, f480=0, f481=0, f482=0, f483=0, f484=0, f485=0, f486=0, f487=0, f488=0, f489=0, f490=0, f491=0, f492=0, f493=0, f494=0, f495=0, f496=0, f497=0, f498=0, f499=0, f500=0, f501=0, f502=0, f503=0, f504=0, f505=0, f506=0, f507=0, f508=0, f509=0, f510=0, f511=0, f512=0;

	char str[100], s[100];
        fr=fopen(argv[1],"r");
	
        while(fgets(str,100,fr)!=NULL)
        {
                sscanf(str,"%s", s);
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
		
		//printf("%s\n", st2);
		if(strstr(s,"CN3") && strncmp(s,"C", 1)==0 && strlen(s)==6)
			fn1=fn1+1; //1.F??

		if(strncmp(s,"O", 1)==0 && strstr(s,"OH1") && strstr(s,"OC1") && strstr(s,"EST")==NULL && strstr(s,"OP1")==NULL && strstr(s,"OS1")==NULL && strstr(s,"ENL")==NULL && strstr(s,"ELN")==NULL)  //Alcohol
                        fn2=fn2+1; //14.ZE(!Q!U!??!??)

		if(strncmp(s,"OC1OC1", 6)==0 && strstr(s,"EST")==NULL && strlen(s)==6 && strstr(s,"OH1")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL) //Ether 14.EE
                        fn3=fn3+1;
		if(strncmp(s,"OC1OC1", 6)==0 && strstr(s,"EST")==NULL && strlen(s)==9 && strstr(s,"OH1")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL) //Ether
                        fn3=fn3+1; //14.EE@Rg6
		//if(strncmp(s,"OC1ON1", 6)==0 && strstr(s,"EST")==NULL && strlen(s)==6 && strstr(s,"OH1")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL) //Ether; 14.JE
                //        fn3=fn3+1;
		//if(strncmp(s,"ON1OC1", 6)==0 && strstr(s,"EST")==NULL && strlen(s)==6 && strstr(s,"OH1")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL) //Ether; 14.JE
                //        fn3=fn3+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OH1OC1") && strstr(s,"EST")) //Acid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OC1OH1") && strstr(s,"EST")) //Acid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OH1OC1") && strstr(s,"DST")) //Acid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OC1OH1") && strstr(s,"DST")) //Acid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		//if(strncmp(s,"O", 1)==0 && strstr(s,"OC1OH1") && strstr(s,"EST")) //Acid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                //        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OH1") && strstr(s,"OP1")) //phosphoricacid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OH1") && strstr(s,"OS1")) //Sulfuricacid-Neutral(OH); 14.??Z/14.QZ/14.UZ
                        fn4=fn4+1;
		if(strncmp(s,"O", 1)==0 && strstr(s,"OC1") && strstr(s,"EST") && strstr(s,"OH1")==NULL && strstr(s,"OO1")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strchr(st1,'1') && strchr(st2,'1') && strstr(s,"DST")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL) //Anhydride-O(sp3); 14.????'
                        fn5=fn5+1;  
		//if(strncmp(s,"O", 1)==0 && strchr(st1,'1') && strchr(st2,'1') && strstr(s,"DST") && strstr(s,"OH1")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL) //Anhydride-O(sp3)
                  //      fn5=fn5+1;
		if(strncmp(s,"S", 1)==0 && strstr(s,"SH1") && strstr(s,"EST")==NULL && strchr(s,'2')==NULL) //Thiol; 22.Z??'(!??!!??)
                        fn6=fn6+1;
		if(strncmp(s,"S", 1)==0 && strstr(s,"SH1") && strstr(s,"EST")) //Thioacid(SH); 22.??Z/22.??Z
                        fn7=fn7+1;
		if(strncmp(s,"S", 1)==0 && strstr(s,"SC1") && strstr(s,"EST")==NULL && strlen(s)==6 && strstr(s,"SH1")==NULL) //Thioether; 22.??'E
                        fn8=fn8+1;
		//if(strncmp(s,"P", 1)==0 && strstr(s,"PN2")) //P=N-containing-molecule; 19.G'
                //        fn9=fn9+1;
		if(strncmp(s,"P", 1)==0 && strstr(s,"PC1PC1PC1") && strlen(s)<=10) //A-Trivalent-Phosphorus-containing-molecule; 18.EEE
                        f70=f70+1;
		if(strncmp(s,"P", 1)==0 && strstr(s,"PC1PC1PC1") && strlen(s)==12 && strstr(s,"MR")) //A-Trivalent-Phosphorus-containing-molecule; 18.EEE
		{
			if(strstr(s,"PH1")==NULL && strstr(s,"PN1")==NULL && strstr(s,"PO1")==NULL && strstr(s,"PS1")==NULL &&
			  strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL && strstr(s,"PI1")==NULL &&
			  strstr(s,"PP1")==NULL && strchr(s,'2')==NULL)
			f70=f70+1;
		}
		if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CH1")) //Aldehyde; 2.KZ; strlen==9 is deleted from the condition on 20.01.2021
			f10=f10+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CH1")) //Thioaldehyde; 2.RZ; strlen==9 is deleted from the condition on 20.01.2021
                        f11=f11+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CH1")==NULL && strstr(s,"CO1")==NULL && strstr(s,"CN1")==NULL && strstr(s,"CF1")==NULL && strstr(s,"Cl1")==NULL && strstr(s,"CB1")==NULL && strstr(s,"CS1")==NULL && strstr(s,"3MR")==NULL &&  strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)  //Ketone
		//	f12=f12+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CH1") && strlen(s)==6 && strstr(s,"CS1")==NULL)  //Thioaldehyde
                //       f13=f13+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CO1") && strlen(s)==9 && stsrtr(s,"CS1")==NULL && stsrtr(s,"CN1")==NULL) //Acid
		//	f14=f14+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CO1") && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && stsrtr(s,"CS1")==NULL) && stsrtr(s,"CN1")==NULL //Acid
                //        f14=f14+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CO1") && strstr(s,"CH1") && strstr(s,"CS1")==NULL) //Thioformicacid; 2.RLZ
                        f15=f15+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CN1") && strlen(s)==9 && strstr(s,"CO1")==NULL && strstr(s,"CS1")==NULL && strstr(s,"CN1CN1")==NULL && strstr(s,"CN1CO2CN1")==NULL) //Amide
		//	f16=f16+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CN1") && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && strstr(s,"CO1")==NULL && strstr(s,"CS1")==NULL && strstr(s,"CN1CN1")==NULL && strstr(s,"CN1CO2CN1")==NULL) //Amide
		//	f16=f16+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CN1") && strstr(s,"CH1") && strstr(s,"CS1")==NULL)	 //Thioformamide; 2.RJZ
			f17=f17+1;
		//if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CN1") && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && strstr(s,"CO1")==NULL && strstr(s,"CS1")==NULL && strstr(s,"CN1CN1")==NULL && strstr(s,"CN1CO2CN1")==NULL) //Thioamide
		//	f17=f17+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"Cl1") && strlen(s)==9) //Acyl chloride; 2.KW
			f18=f18+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"Cl1") && strlen(s)==9) //Thioacetyl chloride; 2.RW
                        f19=f19+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CB1") && strlen(s)==9) //Acetyl bromide; 2.KX
			f20=f20+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CB1") && strlen(s)==9) //Thioacetyl bromide; 2.RX
                        f21=f21+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CF1") && strlen(s)==9) //Acetyl fluoride; 2.KV
                        f22=f22+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CF1") && strlen(s)==9) //Thioacetyl fluoride; 2.RV
                        f23=f23+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CO2") && strstr(s,"CI1") && strlen(s)==9) //Acetyl iodide; 2.KY
                        f24=f24+1;
		if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CI1") && strlen(s)==9) //Thioacetyl iodide; 2.RY
                        f25=f25+1;
		if(strncmp(s, "N", 1)==0 && strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st1,'4')==NULL &&
				            strchr(st1,'5')==NULL && strchr(st1,'6')==NULL && strchr(st1,'7')==NULL &&  //Amine group; 10.????????(!J!??!??)@Rg6/10.??????(!J!??!??)@Rg6
					    strchr(st1,'8')==NULL && strchr(st1,'9')==NULL && strstr(s,"NN1")==NULL &&
					    strstr(s,"NN1")==NULL && strchr(st2,'2')==NULL && strchr(st2,'3')==NULL &&
					    strchr(st2,'4')==NULL && strchr(st2,'5')==NULL && strchr(st2,'6')==NULL &&
					    strchr(st2,'7')==NULL && strchr(st2,'8')==NULL && strchr(st2,'9')==NULL && 
					    strchr(st3,'2')==NULL && strchr(st3,'3')==NULL && strchr(st3,'4')==NULL &&
					    strchr(st3,'5')==NULL && strchr(st3,'6')==NULL && strchr(st3,'7')==NULL &&
					    strchr(st3,'8')==NULL && strchr(st3,'9')==NULL && strstr(s,"AMD")==NULL &&
					    strstr(s,"TMD")==NULL && strstr(s,"UER")==NULL && strstr(s,"DAM")==NULL &&
					    strstr(s,"DTD")==NULL && strstr(s,"DUR")==NULL && strstr(s,"MTD")==NULL &&
					    strstr(s,"NYL")==NULL && strstr(s,"DYL")==NULL && strstr(s,"3MR")==NULL &&
					    strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL &&
					    strstr(s,"S=O")==NULL && strstr(s,"P=O")==NULL)
			f26=f26+1;

		if(strncmp(s,"F", 1)==0 && strstr(s,"ARX"))									//-F group; V
			f27=f27+1;
		if(strncmp(s,"l", 1)==0 && strstr(s,"ARX") )									//-Cl group; W
                        f28=f28+1;
		if(strncmp(s,"B", 1)==0 && strstr(s,"ARX"))									//-Br group; X
                        f29=f29+1;
		if(strncmp(s,"I", 1)==0 && strstr(s,"ARX"))									//-I group; Y
                        f30=f30+1;
		if(strncmp(s, "N", 1)==0 && ((strstr(s,"NO2") && strstr(s,"NO1")) || strstr(s,"NO2NO2")) && strstr(s,"NO2NO1NO1")==NULL && strstr(s,"NO1NO2NO1")==NULL && strstr(s,"NO1NO1NO2")==NULL &&
										       strstr(s,"NO1NO2NO2")==NULL && strstr(s,"NO2NO1NO2")==NULL && strstr(s,"NO2NO2NO1")==NULL &&
										       strstr(s,"NO2NN1")==NULL && strstr(s,"NN1NO2")==NULL && strstr(s,"NN1NC1NO2")==NULL && strstr(s,"NO2NC1NN1")==NULL) //-NO2 group; 8.KL??''
			f31=f31+1;

		if(strncmp(s,"P",1)==0 && ((strlen(s)>=15 && strstr(s,"MR")) || (strlen(s)<=16 && strlen(s)>12 && strstr(s,"POS")) || (strlen(s)<=13 && strlen(s)>10 && strstr(s,"MR")==NULL)))
		{
			if(strstr(s,"PO2") && strstr(s,"PO1") && strstr(s,"PN1")==NULL && 
				          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL && 
					  strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL)  //PO2(O)(O)(O); 18.(KL)
				fn9=fn9+1;
			if(strstr(s,"PS2") && strstr(s,"PO1") && strstr(s,"PN1")==NULL &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL) //PS2(O)(O)(O); 18.(RL)
                		f13=f13+1;
			//Added on 020422
			if(strstr(s,"PO2") && strstr(s,"PO1")==NULL && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL)  //PO2(N)(N)(N); 18.(KJ)
                                f32=f32+1;
                        if(strstr(s,"PS2") && strstr(s,"PO1")==NULL && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL) //PS2(N)(N)(N); 18.(RJ)
                                f33=f33+1;
			//End
			 if(strstr(s,"PO2") && strstr(s,"PO1") && strstr(s,"PN1")==NULL &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PO2(O)(O)(C) / PO2(O)(C)(C); 18.(KLE)
				f34=f34+1;
			if(strstr(s,"PS2") && strstr(s,"PO1") && strstr(s,"PN1")==NULL &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)    //PS2(O)(O)(c) / PS2(O)(C)(c); 18.(RLE)
                	        f35=f35+1;
			if(strstr(s,"PO2") && strstr(s,"PO1") && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL)  //PO2(O)(O)(N) / PO2(O)(N)(N); 18.(KLJ)
        	                f36=f36+1;
			if(strstr(s,"PS2") && strstr(s,"PO1") && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1")==NULL && strstr(s,"PS1")==NULL)  //PS2(O)(O)(N) / PS2(O)(N)(N); 18.(RLJ)
        	                f37=f37+1;
			if(strstr(s,"PO2") && strstr(s,"PO1") && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PO2(O)(C)(N); 18.(KLJE)
				f38=f38+1;
        	        if(strstr(s,"PS2") && strstr(s,"PO1") && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)   //PS2(O)(C)(N); 18.(RLJE)
                	        f39=f39+1;
			if(strstr(s,"PO2") && strstr(s,"PO1")==NULL && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PO2(C)(C)(N) / PO2(C)(N)(N); 18.(KJE)
                                f40=f40+1;
			if(strstr(s,"PS2") && strstr(s,"PO1")==NULL && strstr(s,"PN1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PS2(C)(C)(N) / PS2(C)(N)(N); 18.(RJE)
                                f41=f41+1;
			if(strstr(s,"PO2") && strstr(s,"PO1")==NULL && strstr(s,"PN1")==NULL &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PO2(C)(C)(C); 18.(KE)
                                f42=f42+1;
			if(strstr(s,"PS2") && strstr(s,"PO1")==NULL && strstr(s,"PN1")==NULL &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strstr(s,"PC1") && strstr(s,"PS1")==NULL)     //PS2(C)(C)(C); 18.(RE)
                                f43=f43+1;
			//Added on 12.14.21
			if(strstr(s,"PO2") && strstr(s,"PS1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL)        								//PO2(S)()(); 18.KU
                                f44=f44+1;
			if(strstr(s,"PS2") && strstr(s,"PS1") &&
                                          strstr(s,"PF1")==NULL && strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL &&
                                          strstr(s,"PI1")==NULL)                                                                        //PS2(S)()(); 18.RU
                                f449=f449+1;

			//End
		}
		/*if(strncmp(s,"P",1)==0 && ((strlen(s)>=18 && strstr(s,"MR")) || (strlen(s)<=19 && strlen(s)>15 && strstr(s,"POS")) || (strlen(s)<=16 && strlen(s)>13 && strstr(s,"MR")==NULL)))
		{
			if(strstr(s,"PO2")==NULL && strstr(s,"PS2")==NULL && strstr(s,"PF1")==NULL &&
			  strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL && strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL)		//Rest of the P-containing compounds; 18.??????????
				f44=f44+1;
			if(strstr(s,"PF1") || strstr(s,"Pl1") || strstr(s,"PB1") || strstr(s,"PI1") || strstr(s,"PS1"))			//Rest of the P-containing compounds; 18.X'
				f44=f44+1;
		}
		
		if(strncmp(s,"P",1)==0 && ((strlen(s)<=13 && strlen(s)>10 && strstr(s,"MR")) || (strlen(s)<=10 && strlen(s)>=6 && strstr(s,"MR")==NULL)))
		{
			if(strchr(s,'2')==NULL)// && strstr(s,"PC1PC1")==NULL)
				f449=f449+1;												
		}*/															//Trivalent-P-containing-compound; 18.??????

			if(strncmp(s,"S",1)==0 && ((strlen(s)>=15 && strstr(s,"MR")) || (strlen(s)>=12 && strstr(s,"MR")==NULL)))
                {
			if(strstr(s,"SO2"))
			{
                        	if(strstr(s,"SO1") && strstr(s,"SN1")==NULL &&
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1")==NULL && strstr(s,"SS1")==NULL)  //SO2(=O)(O)(O); 22.(KL)
                           	     f45=f45+1;
				if(strstr(s,"SO1") && strstr(s,"SN1")==NULL &&
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1") && strstr(s,"SS1")==NULL)  //SO2(=O)(C)(O) // 22.(KEL)
                           	     f46=f46+1;
				if(strstr(s,"SO1") && strstr(s,"SN1") &&
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1")==NULL && strstr(s,"SS1")==NULL)  //SO2(=O)(N)(O); 22.(KJL)
                           	     f47=f47+1;
				if(strstr(s,"SO1")==NULL && strstr(s,"SN1") && 
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1") && strstr(s,"SS1")==NULL)  //SO2(=O)(N)(C); 22.(KJE)
                           	     f48=f48+1;
				if(strstr(s,"SO1")==NULL && strstr(s,"SN1")==NULL &&
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1") && strstr(s,"SS1")==NULL)  //SO2(=O)(C)(C); 22.(KE)
                           	     f49=f49+1;
				if(strstr(s,"SO1")==NULL && strstr(s,"SN1") &&
                                          strstr(s,"SF1")==NULL && strstr(s,"Sl1")==NULL && strstr(s,"SB1")==NULL &&
                                          strstr(s,"SI1")==NULL && strstr(s,"SC1")==NULL && strstr(s,"SS1")==NULL)  //SO2(=O)(N)(N); 22.(KJ)
                                	f50=f50+1;
			}
		}
			/*if(strncmp(s,"S",1)==0 && ((strlen(s)<=16 && strlen(s)>12 && strstr(s,"MR")) || (strlen(s)<=13 && strlen(s)>10 && strstr(s,"MR")==NULL)))	//SO2(=O)(O)(O); 22.(KL)
			{
				if(strstr(s,"SO1SO1SO1SO1") || (strstr(s,"SO1SO1SO1") && (strstr(s,"SO1") || strstr(s,"SN1") || strstr(s,"SC1"))) ||
							       (strstr(s,"SO1SN1SO1") && (strstr(s,"SO1") || strstr(s,"SN1") || strstr(s,"SC1"))) ||
							       (strstr(s,"SO1SC1SO1") && (strstr(s,"SO1") || strstr(s,"SN1"))) ||
							       (strstr(s,"SN1SO1SO1") && (strstr(s,"SO1") || strstr(s,"SN1") || strstr(s,"SC1"))) ||
							       (strstr(s,"SC1SO1SO1") && (strstr(s,"SO1") || strstr(s,"SN1"))))
					f45=f45+1;
			}*/

			//if(strncmp(s,"S",1)==0 && ((strlen(s)<=13 && strlen(s)>=11 && strstr(s,"MR")) || (strlen(s)<=13 && strlen(s)>=11 && strstr(s,"POS")) || (strlen(s)<=10 && strlen(s)>=8 && strstr(s,"MR")==NULL && strstr(s,"C2S")==NULL)))   //Rest of the tricoordinated-S-containing compounds which do not contains SO2 moiety; 22.??????(!K)
			if(strncmp(s,"S",1)==0 && strstr(s,"POS"))   //Rest of the tricoordinated-S-containing compounds which do not contains SO2 moiety; 22.??????(!K)
			{
				if(strstr(s,"SO2")==NULL)
					f51=f51+1; 
			}

			
			if(strncmp(s,"C", 1)==0)
			{
				if(strstr(s,"PMe"))  //-CH3 group; 4.ZZZ
				f52=f52+1;
				if(strstr(s,"SMe"))  //-CH2 group; 4.ZZ
				f53=f53+1;   
				if(strstr(s,"TMe"))  //-CH group; 4.Z	
                                f54=f54+1;
				if(strstr(s,"QMe"))  //qMe group; 4.??'??'??'??'
                                f55=f55+1;
			}
			if(strncmp(s,"C",1)==0 && (strstr(s,"CO2CO1CO1") || strstr(s,"CO1CO1CO2") || strstr(s,"CO1CO2CO1")))  //Carbonate group; 2.KLL
				f56=f56+1;
			if(strncmp(s,"C",1)==0 && strstr(s,"CN3") && strstr(s,"CO1"))  //Cyanate group; 1.FL
                                f57=f57+1;
			if(strncmp(s,"C",1)==0 && strstr(s,"CN2") && strstr(s,"CO2"))  //Isocyanate group; 1.G'K
                                f58=f58+1;
			if(strncmp(s,"C",1)==0 && strstr(s,"CN2") && strstr(s,"CS2"))  //Thioisocyanate group; 1.G'R
                                f59=f59+1;
			if(strncmp(s,"C",1)==0 && (strstr(s,"CF1CF1CF1") || strstr(s,"CF1CC1CF1CF1") || strstr(s,"CF1CF1CC1CF1")))  //-CF3 group; 4.VVV
				f60=f60+1;
			if(strncmp(s,"C",1)==0 && (strstr(s,"Cl1Cl1Cl1") || strstr(s,"Cl1CC1Cl1Cl1") || strstr(s,"Cl1Cl1CC1Cl1")))  //-CCl3 group; 4.WWW
                                f61=f61+1;
			if(strncmp(s,"C",1)==0 && (strstr(s,"CB1CB1CB1") || strstr(s,"CB1CC1CB1CB1") || strstr(s,"CB1CB1CC1CB1")))  //-CBr3 group; 4.XXX
                                f62=f62+1;
			if(strncmp(s,"C",1)==0 && strlen(s)>=12)
			{
				if(strstr(s,"CF1CF1CF1")==NULL && strstr(s,"CF1CC1CF1CF1")==NULL && strstr(s,"CF1CF1CC1CF1")==NULL)
				{
					if(strstr(s,"CF1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL &&
					                      strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL)	//-CF/-CF2 group; 4.V
					f63=f63+1;	
				}
			}
			if(strncmp(s,"C",1)==0 && strlen(s)>=12)
                        {
                                if(strstr(s,"Cl1Cl1Cl1")==NULL && strstr(s,"Cl1CC1Cl1Cl1")==NULL && strstr(s,"Cl1Cl1CC1Cl1")==NULL)
                                {
                                        if(strstr(s,"Cl1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL &&
							      strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL)	//-CCl/-CCl2 group; 4.W
                                        f64=f64+1;
                                }
                        }
			if(strncmp(s,"C",1)==0 && strlen(s)>=12)
                        {
                                if(strstr(s,"CB1CB1CB1")==NULL && strstr(s,"CB1CC1CB1CB1")==NULL && strstr(s,"CB1CB1CC1CB1")==NULL)
                                {
                                        if(strstr(s,"CB1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL &&
							      strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL)	//-CBr/-CBr2 group; 4.X
                                        f65=f65+1;
                                }
                        }
			if(strncmp(s,"I",1)==0 && strstr(s,"IC1") && strstr(s,"ARX")==NULL && strstr(s,"C=C")==NULL)	//-CI group; 4.Y
			//if(strncmp(s,"C",1)==0 && strstr(s,"CI1") && strlen(s)==12)
				f66=f66+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2NN2"))							//Azide group; 7.G'G'
				f67=f67+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN3NN1"))							//Azide group; 7.FJ
                                f67=f67+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN1NN3"))							//Azide group; 7.FJ
                                f67=f67+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN1NN2"))							//Azide-type-reactive; 7.G'J
				f67=f67+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2NN1"))							//Azide-type-reactive; 7.G'J
                                f67=f67+1;
			if(strncmp(s,"S",1)==0 && strstr(s,"SO2") && strlen(s)==9)					//Sulfoxide; 22.K???? (Its ring part is there at f475)
				f68=f68+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NC2") && strstr(s,"NO1"))                                   //A special atomtype (C=N-O); 8.B'L
                                f69=f69+1;
			if(strncmp(s,"P",1)==0 && strlen(s)<=10 && strstr(s,"MR")==NULL && (strstr(s,"PF1") || strstr(s,"Pl1") || strstr(s,"PB1") || strstr(s,"PI1"))) //P-X-containing-molecule; 18.X'
                                f70=f70+1;
			if(strncmp(s,"P",1)==0 && strlen(s)==12 && strstr(s,"MR") && (strstr(s,"PF1") || strstr(s,"Pl1") || strstr(s,"PB1") || strstr(s,"PI1"))) //P-X-containing-molecule; 18.X'
                                f70=f70+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NO2") && strstr(s,"NO1")==NULL && strstr(s,"NO2NO2")==NULL &&
			   strstr(s,"NO2NC1NO2")==NULL && strstr(s,"NO2NO1NO2")==NULL && strstr(s,"NO2NS1NO2")==NULL && strstr(s,"NO2NN1")==NULL && strstr(s,"NN1NO2")==NULL &&
			   strstr(s,"NO2NC1NN1")==NULL && strstr(s,"NN1NC1NO2")==NULL)	  				//Nitroso group; 8.K??
				f71=f71+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NC3") && strstr(s,"NC1"))                    	         //Isocyanide group; 7.AE
                                f72=f72+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"OO1") && strstr(s,"EST")==NULL) 							//Peroxide; 14.LL
				f73=f73+1;
			if(strncmp(s,"S",1)==0 && strstr(s,"SS1"))                                                      //Disulfide; 22.SS
                                f74=f74+1;
			//if(strncmp(s,"C",1)==0 && strstr(s,"CS2") && strstr(s,"CS1") && strstr(s,"CN1"))                //A special atomtype (S=C(S)(N)); 2.RUJ; Already taken care at f195
			//	f75=f75+1;
			//Added on1 12.14.21
			if(strncmp(s,"P",1)==0 && ((strlen(s)>=18 && strstr(s,"MR")) || (strlen(s)<=19 && strlen(s)>15 && strstr(s,"POS")) || (strlen(s)<=16 && strlen(s)>13 && strstr(s,"MR")==NULL)))
                	{
                        if(strstr(s,"PO2")==NULL && strstr(s,"PS2")==NULL && strstr(s,"PF1")==NULL &&
                          strstr(s,"Pl1")==NULL && strstr(s,"PB1")==NULL && strstr(s,"PI1")==NULL && strstr(s,"PS1")==NULL && strlen(s)>10)     //Rest of the P-containing compounds; 18.??????????
                                f75=f75+1;
                        if(strstr(s,"PF1") || strstr(s,"Pl1") || strstr(s,"PB1") || strstr(s,"PI1") || strstr(s,"PS1"))                 //Rest of the P-containing compounds; 18.X'
                                f75=f75+1;
                	}
			//End
			//Start of adding on 20.10.2022
			if(strncmp(s,"N",1)==0 && strstr(s,"POS"))                                      //Positively-Charged-sp3(N); 44
                                f477=f477+1;
                        if(strncmp(s,"N",1)==0 && strstr(s,"NEG"))                                      //Negatively-Charged-Nitrogen; 45
				f479=f479+1;
			//End of adding
			if(strncmp(s,"N",1)==0 && strstr(s,"NN1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL && 
					                             strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL &&
								     strstr(s,"AZD")==NULL)	//Hydrazine; 10.HH
				f76=f76+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NO1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL && strchr(s,'2')==NULL)    //N(sp3)-O; 10.L
			{
				b=strstr(s,"NO1");
				if(b)
				{
					fill(b);
                                	f80=f80+1;
				 	b=strstr(s,"NO1");
                                	if(b)
					{
                                        	fill(b);
                                        	f80=f80+1;
						 b=strstr(s,"NO1");
                         		        if(b)
						{
                                        		fill(b);
                                        		f80=f80+1;
						}
					}
				}
			}

			if(strncmp(s,"N",1)==0 && strstr(s,"NS1") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL && strchr(s,'2')==NULL)    //N(sp3)-S; 10.U
			{
				b=strstr(s,"NS1");
				if(b)
				{
					fill(b);
                                	f81=f81+1;
					b=strstr(s,"NS1");
					if(b)
					{
						fill(b);
						f81=f81+1;
						b=strstr(s,"NS1");
						if(b)
						{
							fill(b);
							f81=f81+1;
						}
					}
				}
			}
									
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2") && strstr(s,"NC1") && strstr(s,"NN1")==NULL && strstr(s,"NDZ")==NULL) 	//Diazene; 8.G'E
				f77=f77+1;
			/*if(strncmp(s,"C",1)==0)
			{
				if(strstr(s,"CP2"))
				{
					if(strstr(s,"CC1")) 					     			//C(=P)(C)(); 2.Q'E
						f78=f78+1;
					else
						f79=f79+1;								//Rest-of-the-C(=P)()()-groups; 2.Q'(!E)
				}
			}*/
			//if(strncmp(s,"C",1)==0 && (strstr(s,"CO2CN1CN1") || strstr(s,"CN1CN1CO2") || strstr(s,"CN1CO2CN1")))  //Urea
			//		f80=f80+1;
			//if(strncmp(s,"C",1)==0 && (strstr(s,"CS2CN1CN1") || strstr(s,"CN1CN1CS2") || strstr(s,"CN1CS2CN1")))  //Thiourea
                        //                f81=f81+1;		
			if(strncmp(s,"N",1)==0 && strstr(s,"NN1") && strstr(s,"NO2"))					    //A special atomtype (N-N=O); 8.KJ
					f82=f82+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"5MR") && (strstr(s,"OC4") || strstr(s,"OC5") || strstr(s,"OC6")))		   //Aromatic oxygen, 15
				f83=f83+1;
			if(strncmp(s,"S",1)==0 && strstr(s,"5MR") && (strstr(s,"SC4") || strstr(s,"SC5") || strstr(s,"SC6")))		  //Aromatic sulfur; 23
                                f84=f84+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"MR") && (strstr(s,"NC4") || strstr(s,"NC5") || strstr(s,"NC7")))
			{
				if(strstr(s,"5MR")==NULL && strstr(s,"NN4")==NULL && strstr(s,"NN5")==NULL && strstr(s,"NN6")==NULL) //N(Aromatic)-6-member-ring; 11.D??(!I)@R6
				f85=f85+1;
				if(strstr(s,"5MR") && strstr(s,"NN4")==NULL && (strstr(s,"NH1") || strstr(s,"NS1") || strstr(s,"NC1") || strstr(s,"NO1") || strstr(s,"NN1") || strstr(s,"NP1") || strstr(s,"NF1") || strstr(s,"NB1")|| strstr(s,"NI1") || strstr(s,"Nl1"))) //Pyrrole nitrogen; 11.D????(!I)@R5
				f86=f86+1;
				if((strstr(s,"NN4") || strstr(s,"NN5") || strstr(s,"NN6")) && strstr(s,"5MR")==NULL && strlen(s)<10)	//Pyridazine-nitrogen; 11.DI@R6
				f87=f87+1;	
				if(strstr(s,"5MR") && strstr(s,"6MR")==NULL && strchr(s,'1')==NULL && strchr(s,'2')==NULL)   //Imidazole-nitrogen; 11.D??@R5; strstr(s,"NO4")==NULL and strstr(s,"NS4")==NULL was deleted on 19.10.2022
					f88=f88+1;
			}
			if(strncmp(s,"N",1)==0)
			{
				if(strstr(s,"NN4") && strstr(s,"5MR") && (strstr(s,"NC1") || strstr(s,"NH1") || strstr(s,"NN1") ||
							                  strstr(s,"NO1") || strstr(s,"NS1") || strstr(s,"NP1") ||
									  strstr(s,"Nl1") || strstr(s,"NB1") || strstr(s,"NI1") ||
									  strstr(s,"NF1")))
					f89=f89+1;						//Triazole-nitrogen; 11.I????@R5
					
					if(strstr(s,"6MR") && strstr(s,"NN4") && strstr(s,"NC4") && strstr(s,"5MR"))					
					f411=f411+1;						//N-Pyrrolo[1,2-c]triazine; 11.ID??@R5_6
				
					if((strstr(s,"5MR6MR") || strstr(s,"6MR5MR")) && strchr(st1,'4') && strchr(st2,'4') && strchr(st3,'4') && strstr(s,"NN4")==NULL)
					f412=f412+1;						//Indolizine-N; 11.??????(!II)@R5_6
			}
			if(strncmp(s,"N",1)==0)
			{
				if(strstr(s,"NN4NN4") && strstr(s,"6MR") && strstr(s, "NC4")==NULL)						//1,2,3-Triazine-Nitrogen; 11.II(!D)@R6
					f413=f413+1;				
				if(strstr(s,"NN4NN4") && strstr(s,"5MR") && strstr(s, "NC4")==NULL && strchr(s,'1')==NULL)                     //Tetrazole-Nitrogen; 11.II(!D)@R5
                                        f414=f414+1;
			}
			/*if(strstr(s,"CJO") && strncmp(s,"C",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//Allylic bond adjacent to C=O/C+N/C=S group
				f90=f90+1;
			if(strstr(s,"CJC") && strncmp(s,"C",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//Allylic bond adjacent C=C group
                                f91=f91+1;
			if(strstr(s,"CJB") && strncmp(s,"C",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//Allylic bond adjacent aromatic group
                                f92=f92+1;
			if(strstr(s,"NJO") && strncmp(s,"N",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//N=C-C=O
				f93=f93+1;
			if(strstr(s,"NJC") && strncmp(s,"N",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//N=C-C=C
                                f94=f94+1;
			if(strstr(s,"NJN") && strncmp(s,"N",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)   //N=C-C=N
                                f95=f95+1;
			if(strstr(s,"NJS") && strncmp(s,"C",1)==0 && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//N=C-C=S
				f96=f96+1;*/

			if(strncmp(s,"C",1)==0 && strstr(s,"CC2") && strstr(s,"CJO")==NULL && strstr(s,"CJC")==NULL && 
					          strstr(s,"CJB")==NULL && strstr(s,"CO1")==NULL &&				
						  strstr(s,"CN1")==NULL && strstr(s,"CS1")==NULL && strstr(s,"CJN")==NULL &&	//C=C; 2.????(!L!J!U!??!??!??!??!??)
						  strstr(s,"3MR")==NULL &&
						  strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL &&
						  strstr(s,"7MR")==NULL && strstr(s,"NOT")==NULL && 
						  ((strchr(st1,'2') && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL) ||
						  (strchr(st1,'2')==NULL && strchr(st2,'2') && strchr(st3,'2')==NULL) ||
						  (strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2'))))  				
				f97=f97+1;
			if(strncmp(s,"C",1)==0 && strstr(s,"CC3") && strlen(s)==6)					//C#C; 1.A
				f98=f98+1;

			if(strncmp(s,"C",1)==0 && strstr(st1,"2") && strstr(st2,"2") && strlen(s)==6) //C=C=C 
				f98=f98+1;

			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CN4")) && strstr(s,"BDG") && (strchr(st1,'1') || strchr(st2,'1') || strchr(st3,'1')))
				f99=f99+1;

			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CC5") || strstr(s,"CC8") ||
						   strstr(s,"CC9") || strstr(s,"CN4") || strstr(s,"CN5") ||
					           strstr(s,"CN8") || strstr(s,"CN9") || strstr(s,"CO4") ||             //Benzene-C;  5.??????
						   strstr(s,"CO5") || strstr(s,"CO8") || strstr(s,"CO9") ||
						   strstr(s,"CS4") || strstr(s,"CS5") || strstr(s,"CS8") ||
						   strstr(s,"CS9")) && strlen(s)==12)
			{
					f99=f99+1;
			}
			
			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CC5") || strstr(s,"CC8") ||
                                                   strstr(s,"CC9") || strstr(s,"CN4") || strstr(s,"CN5") ||
                                                   strstr(s,"CN8") || strstr(s,"CN9") || strstr(s,"CO4") ||             //Benzene-C; 5.??????
                                                   strstr(s,"CO5") || strstr(s,"CO8") || strstr(s,"CO9") ||
                                                   strstr(s,"CS4") || strstr(s,"CS5") || strstr(s,"CS8") ||
                                                   strstr(s,"CS9")) && strlen(s)==15)
                        {
                                if(strchr(st1,'1') || strchr(st2,'1') || strchr(st3,'1'))
       						f99=f99+1;
                        }

			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CC5") || strstr(s,"CC8") ||
                                                   strstr(s,"CC9") || strstr(s,"CN4") || strstr(s,"CN5") ||
                                                   strstr(s,"CN8") || strstr(s,"CN9") || strstr(s,"CO4") ||             //Aromatic-Bridge-C; 
                                                   strstr(s,"CO5") || strstr(s,"CO8") || strstr(s,"CO9") ||
                                                   strstr(s,"CS4") || strstr(s,"CS5") || strstr(s,"CS8") ||
                                                   strstr(s,"CS9")) && strlen(s)==15)
			{
				if(strchr(st1,'1')==NULL && strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st2,'1')==NULL && strchr(st2,'2')==NULL && strchr(st2,'3')==NULL && strchr(st3,'1')==NULL && strchr(st3,'2')==NULL && strchr(st3,'3')==NULL)  //5.??????@R6_6/5.??????@R6_5/5.??????@R5_5
                                	f415=f415+1;
			}
			//Newly added on 1 December 2021
			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CC5") || strstr(s,"CC8") ||
                                                   strstr(s,"CC9") || strstr(s,"CN4") || strstr(s,"CN5") ||
                                                   strstr(s,"CN8") || strstr(s,"CN9") || strstr(s,"CO4") ||             //Aromatic-Bridge-C;
                                                   strstr(s,"CO5") || strstr(s,"CO8") || strstr(s,"CO9") ||
                                                   strstr(s,"CS4") || strstr(s,"CS5") || strstr(s,"CS8") ||
                                                   strstr(s,"CS9")) && strlen(s)==18)
                        {
                                if(strchr(st1,'1')==NULL && strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st2,'1')==NULL && strchr(st2,'2')==NULL && strchr(st2,'3')==NULL && strchr(st3,'1')==NULL && strchr(st3,'2')==NULL && strchr(st3,'3')==NULL)  //5.??????@R6_6/5.??????@R6_5/5.??????@R5_5
                                        f415=f415+1;
                        }
			if(strncmp(s,"C",1)==0 && (strstr(s,"CC4") || strstr(s,"CC5") || strstr(s,"CC8") ||
                                                   strstr(s,"CC9") || strstr(s,"CN4") || strstr(s,"CN5") ||
                                                   strstr(s,"CN8") || strstr(s,"CN9") || strstr(s,"CO4") ||             //Aromatic-Bridge-C;
                                                   strstr(s,"CO5") || strstr(s,"CO8") || strstr(s,"CO9") ||
                                                   strstr(s,"CS4") || strstr(s,"CS5") || strstr(s,"CS8") ||
                                                   strstr(s,"CS9")) && strlen(s)==21)
                        {
                                if(strchr(st1,'1')==NULL && strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st2,'1')==NULL && strchr(st2,'2')==NULL && strchr(st2,'3')==NULL && strchr(st3,'1')==NULL && strchr(st3,'2')==NULL && strchr(st3,'3')==NULL)  //5.??????@R6_6/5.??????@R6_5/5.??????@R5_5
                                        f415=f415+1;
                        }
			//End adding
			
			//Commented on 112.19.2021
			/*if(strncmp(s,"C",1)==0)
			{
				if(strchr(st1,'4') && strchr(st2,'4') && strchr(st3,'2'))
                                           f448=f448+1;           
				if(strchr(st1,'2') && strchr(st2,'4') && strchr(st3,'4'))		//Aromatic-Carnobn-contains-double-bonnd; 5.B'
                                           f448=f448+1;
				if(strchr(st1,'4') && strchr(st2,'2') && strchr(st3,'4'))
                                           f448=f448+1;
                        }*/
			if(strncmp(s,"O",1)==0 && strstr(s,"OO1") && strstr(s,"EST"))					//14.??L
				 f448=f448+1;

			if(strncmp(s,"N",1)==0 && strstr(s,"NC4") && strlen(s)==15 && strstr(s,"6MR6MR"))		//Anthracene-N; 11.D????@R6_6, e.g.; Quinolizinium
                                f100=f100+1;
			if(strncmp(s,"C",1)==0 && strstr(s,"CN6") && strlen(s)==12 && strstr(s,"6MR6MR"))              //Anthracene-C
                                f100=f100+1;	
			if(strncmp(s,"C",1)==0 && strstr(s,"CC4CC4CC4") && strlen(s)==18 && strstr(s,"6MR6MR6MR"))    //Phenalene-C; 5.??????@R6_6_6
                                f101=f101+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NO4") && strlen(s)==9)					//Oxadiazole; 11.M??
				f102=f102+1;	
			if(strncmp(s,"N",1)==0 && strstr(s,"NS4") && strlen(s)==9)                                     //Thiadiazole; 11.T??
                        	f103=f103+1;
			//if(strncmp(s,"C",1)==0 && strstr(s,"RTO"))                                                      //Rotatable-bond; ROT
                        //        f104=f104+1;                                                                  

			if(strncmp(s,"C", 1)==0 && strstr(s,"CNJ")==NULL)
			{
				if(strstr(s,"CO2CN1CN1") || strstr(s,"CN1CO2CN1") || strstr(s,"CN1CN1CO2"))  
				{		
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//Diaziridine-3-one/1,3-Diazetidin-2-one; 2.KJJ@R3/2.KJJ@R4
						f105=f105+1;
					if(strstr(s,"5MR"))								//2-Imidazolidone; 2.KJJ@R5
						f106=f106+1;
					if(strstr(s,"6MR"))								//(H4)2(1H)-pyrimidinone; 2.KJJ@R6
                                                f107=f107+1;								
					if(strstr(s,"7MR"))								//C1CCNC(=O)NC1; 2.KJJ@R7
                                                f108=f108+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
						f109=f109+1;								//Urea; 2.KJJ
				}
				if(strstr(s,"CO2") && strstr(s,"CO1") && strstr(s,"CN1"))
				{
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C1NC(=O)O1 2.KNJ@R3/2.KNJ@R4
						f110=f110+1;
					if(strstr(s,"5MR"))								//C1(=O)OCCN1; 2.KNJ@R5
						f111=f111+1;
					if(strstr(s,"6MR"))								//C1(=O)OCCCN1; 2.KNJ@R6
						f112=f112+1;
					if(strstr(s,"7MR"))								//C1(=O)NCCCCO1; 2.KNJ@R7
						f113=f113+1;
					 if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
						f114=f114+1;								//Carbamic-group; 2.KNJ
				}
				
				if(strstr(s,"CO2") && strstr(s,"CC1") && strstr(s,"CN1"))			
				{
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//Lactam-3/4-membered; 
						f115=f115+1;
					if(strstr(s,"5MR")) 								//Lactam-5-membered
						f116=f116+1;
					if(strstr(s,"6MR"))								//Lactam-6-membered
						f117=f117+1;
					if(strstr(s,"7MR"))								//Lactam-7-membered
						f118=f118+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
					f16=f16+1;									//Amide
				}

				if(strstr(s,"CO2") && strstr(s,"CC1") && strstr(s,"CO1"))
				{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))						//Anhydride-3/4-membered
                                                f119=f119+1;
                                        if(strstr(s,"5MR"))								//Anhydride-5-membered
                                                f120=f120+1;
                                        if(strstr(s,"6MR"))								//Anhydride-6-membered
                                                f121=f121+1;
                                        if(strstr(s,"7MR"))								//Anhydride-7-membered
                                                f122=f122+1;
					 if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
					f14=f14+1;									//Acid/Anhydride-C
                        	}

				if(strstr(s,"CO2") && strstr(s,"CS1"))
                                {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //C(=O)(S)-3/4-membered; 2.??U??@R3/2.??U??@R4
                                                f206=f206+1;
                                        if(strstr(s,"5MR"))                                                             //C(=O)(S)-5-membered; 2.??U??@R5
                                                f207=f207+1;
                                        if(strstr(s,"6MR"))                                                             //C(=O)(S)-6-membered; 2.??U??@R6
                                                f208=f208+1;
                                        if(strstr(s,"7MR"))                                                             //C(=O)(S)-7-membered; 2.??U??@R7
                                                f209=f209+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
						f210=f210+1;								//Rest-of-the-C(=O)(S)-groups; 2.??U??@Rg7
                                }
			
				if(strstr(s,"CO2CC1CC1") || strstr(s,"CC1CO2CC1") || strstr(s,"CC1CC1CO2"))
				{
				if(strstr(s,"3MR") || strstr(s,"4MR"))							//Ketone-3/4-membered
                                                f123=f123+1;
                                        if(strstr(s,"5MR"))								//Ketone-5-membered
                                                f124=f124+1;
                                        if(strstr(s,"6MR"))								//Ketone-6-membered
                                                f125=f125+1;
                                        if(strstr(s,"7MR"))								//Ketone-7-membered
                                                f126=f126+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
						f12=f12+1;								//Ketone
                        	}

				/*if(strstr(s,"CC2") && strstr(s,"CO1") && strstr(s,"ENL"))				//Enol-tautomer; 2.B'??
						f127=f127+1;
				if(strstr(s,"CN2") && strstr(s,"CO1") && strstr(s,"ELN"))				//C(=N)OH; 2.G'??
                                                f128=f128+1;*/

				//if(strstr(s,"CS2CN1CN1") || strstr(s,"CN1CS2CN1") || strstr(s,"CN1CN1CS2"))		//Thiourea
				//		f129=f129+1;
			}
			if(strncmp(s,"O", 1)==0 && strstr(s,"OC1") && strstr(s,"OH1") && strstr(s,"ENL"))		//14.??Z
                                        f127=f127+1;
			if(strncmp(s,"O", 1)==0 && strstr(s,"OC1") && strstr(s,"OH1") && strstr(s,"ELN"))		//14.??Z
                                        f128=f128+1;

			if(strncmp(s,"C", 1)==0 && strstr(s,"CNJ"))
                        {
                                if(strstr(s,"CO2CN1CN1") || strstr(s,"CN1CO2CN1") || strstr(s,"CN1CN1CO2"))		//Aromatic-N-C(=O)N; 2.KI'J/2.KI'I'
                           		f454=f454+1;			

                                if(strstr(s,"CO2") && strstr(s,"CO1") && strstr(s,"CN1"))				//Aromatic-N-C(=O)O; 2.KI'N
                               		f455=f455+1;

                                if(strstr(s,"CO2") && strstr(s,"CS1"))							//Aromatic-N-C(=O)S; 2.KI'U
					f456=f456+1;

                                if(strstr(s,"CO2") && strstr(s,"CC1"))							//Aromatic-N-C(=O)C; 2.KI'E
					f457=f457+1;

                                if(strstr(s,"CO2") && strstr(s,"CH1"))							//Aromatic-N-C(=O)H; 2.KI'Z
					f458=f458+1;

                                if(strstr(s,"CN2CN1CN1") || strstr(s,"CN1CN2CN1") || strstr(s,"CN1CN1CN2"))		//Aromatic-N-C(=N)N; 2.G'I'J
                           		f459=f459+1;

                                if(strstr(s,"CN2") && strstr(s,"CO1") && strstr(s,"CN1"))				//Aromatic-N-C(=N)O; 2.G'I'N
                               		f460=f460+1;

                                if(strstr(s,"CN2") && strstr(s,"CS1"))							//Aromatic-N-C(=N)S; 2.G'I'U
					f461=f461+1;

                                if(strstr(s,"CN2") && strstr(s,"CC1"))							//Aromatic-N-C(=N)C; 2.G'I'E
					f462=f462+1;

                                if(strstr(s,"CN2") && strstr(s,"CH1"))							//Aromatic-N-C(=N)H; 2.G'I'Z
					f463=f463+1;

                                if(strstr(s,"CC2CN1CN1") || strstr(s,"CN1CC2CN1") || strstr(s,"CN1CN1CC2"))		//Aromatic-N-C(=C)N; 2.B'I'J
                           		f464=f464+1;

                                if(strstr(s,"CC2") && strstr(s,"CO1") && strstr(s,"CN1"))				//Aromatic-N-C(=C)O' 2.B'I'N
                               		f465=f465+1;

                                if(strstr(s,"CC2") && strstr(s,"CS1"))							//Aromatic-N-C(=C)S; 2.B'I'U
					f466=f466+1;

                                if(strstr(s,"CC2") && strstr(s,"CC1"))							//Aromatic-N-C(=C)C; 2.B'I'E
					f467=f467+1;

                                if(strstr(s,"CC2") && strstr(s,"CH1"))							//Aromatic-N-C(=C)H; 2.B'I'Z
					f468=f468+1;

                                if(strstr(s,"CS2CN1CN1") || strstr(s,"CN1CS2CN1") || strstr(s,"CN1CN1CS2"))		//Aromatic-N-C(=S)N; 2.RI'J
                           		f469=f469+1;

                                if(strstr(s,"CS2") && strstr(s,"CO1") && strstr(s,"CN1"))				//Aromatic-N-C(=S)O; 2.RI'N
                               		f470=f470+1;

                                if(strstr(s,"CS2") && strstr(s,"CS1"))							//Aromatic-N-C(=S)S; 2.RI'U
					f471=f471+1;

                                if(strstr(s,"CS2") && strstr(s,"CC1"))							//Aromatic-N-C(=S)C; 2.RI'E
					f472=f472+1;

                                if(strstr(s,"CS2") && strstr(s,"CH1"))							//Aromatic-N-C(=S)H; 2.RI'Z
					f473=f473+1;
				
				if(strstr(s,"CH1")==NULL && strstr(s,"CO1")==NULL && strstr(s,"CC1")==NULL && strstr(s,"CS1")==NULL &&
				   strstr(s,"CN1CS2CN1")==NULL && strstr(s,"CN1CC2CN1")==NULL && strstr(s,"CN1CN2CN1")==NULL &&			//Aromatic-N-C(=E)-group
				   strstr(s,"CN1CO2CN1")==NULL && strstr(s,"CN1CN1")==NULL)   //2.B'IX/2.B'IQ/2.G'IX/2.G'IQ/2.KIX/2.KIQ/2.RIX/2.RIQ
					f474=f474+1;
			}



				if(strstr(s,"CJO") && strncmp(s,"C",1)==0)
				{
					if(strstr(s,"4MR") || strstr(s,"3MR"))						//C=C-C=O-in-3/4-member-ring; 2.B'??@R3/2.B'??@R3/2.B'??@R3/2.B'??@R4/2.B'??@R4/2.B'??@R4
						f130=f130+1;
					if(strstr(s,"5MR"))								//C=C-C=O-in-5-member-ring; 2.B'??@R5/2.B'??@R5/2.B'??@R5
						f131=f131+1;
					if(strstr(s,"6MR"))								//C=C-C=O-in-6-member-ring; 2.B'??@R6/2.B'??@R6/2.B'??@R6
                                                f132=f132+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f90=f90+1;								//C=C-C=O-Rest; 2.B'??@Rg6/2.B'??@Rg6/2.B'??@Rg6
				}
				if(strstr(s,"CJC") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"4MR") || strstr(s,"3MR"))						//C=C-C=C-in-3/4-member-ring; 2.B'??@R3/2.B'??@R4
                                                f133=f133+1;
                                        if(strstr(s,"5MR"))								//C=C-C=C-in-5-member-ring; 2.B'??@R5
                                                f134=f134+1;
                                        if(strstr(s,"6MR"))								//C=C-C=C-in-6-member-ring; 2.B'??@R6
                                                f135=f135+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f91=f91+1;								//C=C-C=C-Rest; 2.B'??@Rg6
                                }
				if(strstr(s,"CJB") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"4MR") || strstr(s,"3MR"))						//Phenylvinyl-3/4-member-ring; 2.B'??@R3/2.B'??@R4
                                                f136=f136+1;
                                        if(strstr(s,"5MR"))								//Phenylvinyl-5-member-ring; 2.B'??@R5
                                                f137=f137+1;
                                        if(strstr(s,"6MR"))								//Phenylvinyl-6-member-ring; 2.B'??@R6
                                                f138=f138+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f92=f92+1;								//Phenylvinyl-Rest; 2.B'??@Rg6
                                }

				if(strstr(s,"NJO") && strncmp(s,"N",1)==0)						
                                {
					if(strstr(s,"5MR"))								//N=C-C=O-5-member-ring; 8.B'??@R5
						f139=f139+1;
					if(strstr(s,"6MR"))								//N=C-C=O-6-member-ring; 8.B'??@R6
                                                f140=f140+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//N=C-C=O-3/4-member-ring; 8.B'??@R3/8.B'??@R4
						f377=f377+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f93=f93+1;								//N=C-C=O-Rest; 8.B'??@Rg6
				}

				if(strstr(s,"NJC") && strncmp(s,"N",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //N=C-C=C-5-member-ring; 8.B'??@R5
                                                f141=f141+1;
                                        if(strstr(s,"6MR"))                                                             //N=C-C=C-6-member-ring; 8.B'??@R6
                                                f142=f142+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //N=C-C=C-3/4-member-ring; 8.B'??@R3/8.B'??@R4
                                                f378=f378+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f94=f94+1;								//N=C-C=C-Rest; 8.B'??@Rg6
                                }
				
				if(strstr(s,"NJN") && strncmp(s,"N",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //N=C-C=N-5-member-ring; 8.B'??@R5
                                                f143=f143+1;
                                        if(strstr(s,"6MR"))                                                             //N=C-C=N-6-member-ring; 8.B'??@R6
                                                f144=f144+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //N=C-C=N-3/4-member-ring; 8.B'??@R3/8.B'??@R4
                                                f379=f379+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f95=f95+1;								//N=C-C=N-Rest; 8.B'??@Rg6
                                }
				if(strncmp(s,"N",1)==0 && strstr(s,"NJS"))  //It was CNJ
				{
					if(strstr(s,"5MR"))								//N=C-C=S-5-member-ring; 8.B'??@R5
						f145=f145+1;
					if(strstr(s,"6MR"))								//N=C-C=S-6-member-ring; 8.B'??@R6
                                                f146=f146+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //N=C-C=S-3/4-member-ring; 8.B'??@R3/8.B'??@R4
                                                f380=f380+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f147=f147+1;								//N=C-C=S-rest; 8.B'??@Rg6
				}
				if(strncmp(s,"N",1)==0 && strstr(s,"NJB")) //It was CNC
                                {
                                        if(strstr(s,"5MR"))								//N=C-Ph-5-member-ring; 8.B'??@R5
                                                f148=f148+1;
                                        if(strstr(s,"6MR"))								//N=C-Ph-6-member-ring; 8.B'??@R6
                                                f149=f149+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //N=C-Ph-3/4-member-ring; 8.B'??@R3/8.B'??@R4
                                                f381=f381+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f150=f150+1;								//N=C-Ph-rest; 8.B'??@Rg6
                                }

				 if(strncmp(s,"N",1)==0 && strstr(s,"NNJ")) //It was CNC
                                {
                                        if(strstr(s,"5MR"))                                                             //N=C-N(ar)-5-member-ringi; 8.B'I@R5 
                                                f450=f450+1;
                                        if(strstr(s,"6MR"))                                                             //N=C-N(Ar)-6-member-ring; 8.B'I@R6
                                                f451=f451+1;
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //N=C-N(Ar)-3/4-member-ring; 8.B'I@R3/8.B'I@R4
                                                f452=f452+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f453=f453+1;                                                            //N=C-N(Ar)-rest; 8.B'I@Rg6
                                }

				if(strstr(s,"CSS") && strncmp(s,"C",1)==0) //It was CJN
				{
					if(strstr(s,"5MR"))								//C(=S)-C=S-5-member-ring; 2.R??@R5
						f252=f252+1;
					if(strstr(s,"6MR"))								//C(=S)-C=S-6-member-ring; 2.R??@R6
						f253=f253+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=S)-C=S-3/4-member-ring; 2.R??@R3/2.R??@R4
						f382=f382+1;
					if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
						f352=f352+1;								//C(=S)-C=S-Rest; 2.R??@Rg6
				}
				if(strstr(s,"CSB") && strncmp(s,"C",1)==0)
				{
					if(strstr(s,"5MR"))                                                             //C(=S)-Ph-5-member-ring; 2.R??@R5
                                                f353=f353+1;
                                        if(strstr(s,"6MR"))                                                             //C(=S)-Ph-6-member-ring; 2.R??@R6
                                                f354=f354+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //C(=S)-Ph-3/4-member-ring; 2.R??@R3/2.R??@R4
                                                f383=f383+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f355=f355+1;                                                            //C(=S)-Ph-Rest; 2.R??@Rg6
                                }
				if(strstr(s,"CNO") && strncmp(s,"C",1)==0)
                                {
					if(strstr(s,"5MR"))                                                             //C(=N)-C=O-5-member-ring; 2.G'??@R5
                                                f356=f356+1;
                                        if(strstr(s,"6MR"))                                                             //C(=N)-C=O-6-member-ring; 2.G'??@R6
                                                f357=f357+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=N)-C=O-3/4-member-ring; 2.G'??@R3/2.G'??@R5
						f384=f384+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f358=f358+1;                                                            //C(=N)-C=O-Rest; 2.G'??@Rg6
                                }
				if(strstr(s,"CNN") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=N)-C=N-5-member-ring; 2.G'??@R5
                                                f359=f359+1;
                                        if(strstr(s,"6MR"))                                                             //C(=N)-C=N-6-member-ring;2.G'??@R6
                                                f360=f360+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=N)-C=N-3/4-member-ring; 2.G'??@R3/2.G'??@R4
						f385=f385+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f361=f361+1;                                                            //C(=N)-C=N-Rest; 2.G'??@Rg6
                                }
				if(strstr(s,"CNS") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=N)-C=S-5-member-ring; 2.G'??@R5
                                                f362=f362+1;
                                        if(strstr(s,"6MR"))                                                             //C(=N)-C=S-6-member-ring; 2.G'??@R6
                                                f363=f363+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=N)-C=S-3/4-member-ring; 2.G'??@R3/2.G'??@R4
						f386=f386+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f364=f364+1;                                                            //C(=N)-C=S-Rest; 2.G'??@Rg6
				}
				if(strstr(s,"CNB") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=N)-Ph-5-member-ring; 2.G'??@R5
                                                f365=f365+1;
                                        if(strstr(s,"6MR"))                                                             //C(=N)-Ph-6-member-ring; 2.G'??@R6
                                                f366=f366+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=N)-Ph-3/4-member-ring; 2.G'??@R3/2.G'??@R4
						f387=f387+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f367=f367+1;                                                            //C(=N)-Ph-Rest; 2.G'??@Rg6
                                }
				if(strstr(s,"COO") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=O)-C=O-5-member-ring; 2.K??@R5
                                                f368=f368+1;
                                        if(strstr(s,"6MR"))                                                             //C(=O)-C=O-6-member-ring; 2.K??@R6
                                                f369=f369+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=O)-C=O-3/4-member-ring; 2.K??@R3/2.K??@R4
						f388=f388+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f370=f370+1;                                                            //C(=O)-C=O-Rest; 2.K??@Rg6
                                }
				if(strstr(s,"COS") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=O)-C=S-5-member-ring; 2.K??@R5
                                                f371=f371+1;
                                        if(strstr(s,"6MR"))                                                             //C(=O)-C=S-6-member-ring; 2.K??@R6
                                                f372=f372+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //C(=O)-C=S-3/4-member-ring; 2.K??@R3/2.K??@R4
						f389=f389+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f373=f373+1;                                                            //C(=O)-C=S-Rest; 2.K??@Rg6
                                }
				if(strstr(s,"COB") && strncmp(s,"C",1)==0)
                                {
                                        if(strstr(s,"5MR"))                                                             //C(=O)-Ph-5-member-ring; 2.K??@R5
                                                f374=f374+1;
                                        if(strstr(s,"6MR"))                                                             //C(=O)-Ph-6-member-ring; 2.K??@R6
                                                f375=f375+1;
					if(strstr(s,"3MR") || strstr(s,"4MR"))						//C(=O)-Ph-3/4-member-ring; 2.K??@R3/2.K??@R4
						f390=f390+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)
                                                f376=f376+1;                                                            //C(=O)-Ph-Rest; 2.K??@Rg6
                                }

			/*if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CH1")==NULL && strstr(s,"CO1")==NULL && strstr(s,"CN1")==NULL && strstr(s,"CF1")==NULL && strstr(s,"Cl1")==NULL && strstr(s,"CB1")==NULL)
			{
				if(strstr(s,"3MR"))									//Thioketone-3/4-member-ring
					f151=f151+1;
				if(strstr(s,"4MR"))
                                        f151=f151+1;
				if(strstr(s,"5MR"))									//Thioketone-5-member-ring
                                        f152=f152+1;
				if(strstr(s,"6MR"))									//Thioketone-6-member-ring
                                        f153=f153+1;
				if(strlen(s)==12 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL)	//Thioketone-rest
                                        f154=f154+1;
			}
			if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CN1"))
			{
				if(strstr(s,"3MR") || strstr(s,"4MR"))							//Thioamide-3/4-member-ring
					f155=f155+1;
				if(strstr(s,"5MR"))									//Thioamide-5-member-ring
					f156=f156+1;
				if(strstr(s,"6MR"))									//Thioamide-5-member-ring
                                        f157=f157+1;
				if(strlen(s)==12 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL) //Thioamide-rest
					f158=f158+1;
			}*/

			if(strncmp(s,"N", 1)==0 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && strstr(s,"NH1") && strlen(s)>=9)
			{
				if(strstr(s,"NYLAMD")==NULL && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLMTD")==NULL &&
				   strstr(s,"MTDNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"UERNYL")==NULL &&
				   strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"AMDUER")==NULL &&
				   strstr(s,"UERAMD")==NULL && strstr(s,"UERMTD")==NULL && strstr(s,"MTDUER")==NULL)
				{
					if(strstr(s,"NYL"))								//Amine(NH)-Conjugation-One-Vinyl; 10.Z????@Rg7
						f151=f151+1;
					if(strstr(s,"DYL"))								//Amine(NH)-Conjugation-Two-Vinyl; 10.Z????@Rg7
                                        	f152=f152+1;				
					if(strstr(s,"AMD"))								//Amide(NH); 10.Z????@Rg7
						f159=f159+1;								
					if(strstr(s,"DAM"))								//Di-Amide(NH); 10.Z????@Rg7
                                        	f160=f160+1;
					if(strstr(s,"MTD"))								//Thioamide(NH); 10.Z????
                                        	f161=f161+1;
					if(strstr(s,"DTD"))                                                             //Di-Thioamide(NH); 10.????Z@Rg7
                                        	f340=f340+1;
					if(strstr(s,"UER"))                                                             //Amidine(NH); 10.????Z@Rg7
                                        	f341=f341+1;
					if(strstr(s,"DUR"))                                                             //Di-Amidine(NH); 10.????Z@Rg7
                                        	f342=f342+1;
				}
			}
			if(strncmp(s,"N", 1)==0 && strstr(s,"NH1") && strlen(s)>=15)
                        {
				if(strstr(s,"NYLAMD") || strstr(s,"AMDNYL"))						//Amine(NH)-Conjugation-Amide-Vinyl; 10.Z????
					f153=f153+1;
				if(strstr(s,"NYLMTD") || strstr(s,"MTDNYL"))						//Amine(NH)-Conjugation-Thioamide-Vinyl; 10.Z????
					f154=f154+1;
				if(strstr(s,"NYLUER") || strstr(s,"UERNYL"))						//Amine(NH)-Conjugation-Imine-Vinyl; 10.Z????
					f155=f155+1;
				if(strstr(s,"AMDMTD") || strstr(s,"MTDAMD"))						//Amine(NH)-Conjugation-Amide-Thioamide; 10.Z????
					f156=f156+1;
				if(strstr(s,"AMDUER") || strstr(s,"UERAMD"))                                            //Amine(NH)-Conjugation-Amide-Imine; 10.Z????
					f157=f157+1;
				if(strstr(s,"MTDUER") || strstr(s,"UERMTD"))						//Amine(NH)-Conjugation-Thioamide-Imine; 10.Z????
					f158=f158+1;
			}
			/*if(strstr(s,"CC2") && strstr(s,"CO1") && strstr(s,"ENL")==NULL)                         //(C)O-C-C=C; 2.B'L(!??)
                                     f162=f162+1;
                        if(strstr(s,"CN2") && strstr(s,"CO1") && strstr(s,"ELN")==NULL)                         //(C)O-C-C=N; 2.G'L(!??)
                                     f163=f163+1;*/
			if(strncmp(s,"O",1)==0 && strstr(s,"ENE") && strstr(s,"MR")==NULL)
				     f162=f162+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"DNE") && strstr(s,"MR")==NULL)
                                     f163=f163+1;

			/*if(strncmp(s,"C",1)==0)
			{
				if(strchr(st1,'2')==NULL && strchr(st1,'3')==NULL && strchr(st1,'4')==NULL && 
				   strchr(st2,'2')==NULL && strchr(st2,'3')==NULL && strchr(st2,'4')==NULL && 
				   strchr(st3,'2')==NULL && strchr(st3,'3')==NULL && strchr(st3,'4')==NULL &&
				   strchr(st4,'1')==NULL && strchr(st4,'2')==NULL && strchr(st4,'3')==NULL && strchr(st4,'4')==NULL)*/
				   /*strchr(st2,'4')==NULL && strchr(st2,'5')==NULL && strchr(st2,'6')==NULL && 
				   strchr(st2,'8')==NULL && strchr(st2,'9')==NULL && strchr(st3,'2')==NULL && 
				   strchr(st3,'3')==NULL && strchr(st3,'4')==NULL && strchr(st3,'5')==NULL && 
				   strchr(st3,'6')==NULL && strchr(st3,'8')==NULL && strchr(st3,'9')==NULL &&
				   strchr(st4,'1')==NULL && strchr(st4,'2')==NULL && strchr(st4,'3')==NULL && strchr(st4,'4')==NULL)*/
				{
					//if(strstr(s,"MR")==NULL && strlen(s)==9 && strstr(s,"CC1CN1CN1")==NULL && strstr(s,"CP1")==NULL &&
					/*if(strstr(s,"CC1CN1CN1")==NULL && strstr(s,"CP1")==NULL &&
					   strstr(s,"CN1CC1CN1")==NULL && strstr(s,"CN1CN1CC1")==NULL &&
					   strstr(s,"CS1CN1CN1")==NULL && strstr(s,"CN1CS1CN1")==NULL && strstr(s,"CN1CN1CS1")==NULL &&
					   strstr(s,"CO1CN1CN1")==NULL && strstr(s,"CN1CO1CN1")==NULL && strstr(s,"CN1CN1CO1")==NULL &&
					   strstr(s,"CN1CN1CN1")==NULL && strstr(s,"CN1CN1CN1")==NULL && strstr(s,"CN1CN1CN1")==NULL)*/		   //C-valency-not-satisfiedi; 44
					//f164=f164+1;
					//if(strstr(s,"MR") && strlen(s)==12 && strstr(s,"CC1CN1CN1")==NULL && strstr(s,"CP1")==NULL &&
					  //strstr(s,"CN1CC1CN1")==NULL && strstr(s,"CN1CN1CC1")==NULL &&
					  //strstr(s,"CS1CN1CN1")==NULL && strstr(s,"CN1CS1CN1")==NULL && strstr(s,"CN1CN1CS1")==NULL &&
					  //strstr(s,"CO1CN1CN1")==NULL && strstr(s,"CN1CO1CN1")==NULL && strstr(s,"CN1CN1CO1")==NULL &&
					  //strstr(s,"CN1CN1CN1")==NULL && strstr(s,"CN1CN1CN1")==NULL && strstr(s,"CN1CN1CN1")==NULL)		  //C-valency-not-satisfied; 43
					//f164=f164+1;
				}
				/*if(strstr(st1,"2") || strstr(st2,"2") || strstr(st4,"2") || 
				   strstr(st1,"3") || strstr(st2,"3") || strstr(st4,"3") ||
				   strstr(st1,"4") || strstr(st2,"4") || strstr(st4,"4") ||
				   strstr(st1,"5") || strstr(st2,"5") || strstr(st4,"5") ||
				   strstr(st1,"6") || strstr(st2,"6") || strstr(st4,"6") ||
				   strstr(st1,"8") || strstr(st2,"8") || strstr(st4,"8") ||
				   strstr(st1,"9") || strstr(st2,"9") || strstr(st4,"9"))
				{
					if(strstr(s,"MR")==NULL && strlen(s)==6)				//C-valency-not-satisfied
					f164=f164+1;
					if(strstr(s,"MR") && strlen(s)==9)					//C-valency-not-satisfied
					f164=f164+1;
				}*/
			//}
			if(strncmp(s,"F",1)==0 || strncmp(s,"l",1)==0 || strncmp(s,"B",1)==0 ||strncmp(s,"I",1)==0)
			{
				if(strstr(s,"C=C"))
					f164=f164+1;								//Halogen-Olefinic bond
			}
			if(strncmp(s,"S",1)==0)
			{
				if(strstr(s,"SO2") && strlen(s)==12 && strstr(s,"MR")) 				//Sulfoxide; 22.K????@R
					f475=f475+1;
				//if(strstr(s,"SO2") && strlen(s)==9 && strstr(s,"MR")==NULL)			//Sulfoxide; 22.K????
                                //        f475=f475+1;
				if(strstr(s,"2")==NULL && strstr(s,"SO1") && strstr(s,"SC1"))			//S(sp3)-O; 22.EN(!K)
					f476=f476+1;
				if(strstr(s,"2")==NULL && strstr(s,"SN1") && strstr(s,"SC1"))			//S(sp3)-N; 22.EJ(!K)
                                        f476=f476+1;
			}
				//if(strstr(s,"SO2")==NULL && strstr(s,"SC2") && ((strlen(s)>3 && strstr(s,"MR")==NULL) || (strlen(s)>6 && strstr(s,"MR"))))			//Reactive-S-groupsi; 24.KB'/24.R/24.E/23@(!R5)
				//	f165=f165+1;
				//if(strstr(s,"SO2")==NULL && strstr(s,"SN1") && strstr(s,"SC2")) //24.KB'/24.R/24.E/23@(!R5)
                                //        f165=f165+1;	
				//if(strstr(s,"SO2")==NULL && strstr(s,"SS1") && strstr(s,"SC2")) //24.KB'/24.R/24.E/23@(!R5)
                                //        f165=f165+1;
				//if(strstr(s,"SO2")==NULL && strstr(s,"SP1") && strstr(s,"SC2")) //24.KB'/24.R/24.E/23@(!R5)
                                //        f165=f165+1;
                               //if(strstr(s,"SS2")) //24.KB'/24.R/24.E/23@(!R5)
				//       f165=f165+1;
			       //if(strstr(s,"SC1") && strlen(s)==3) //24.KB'/24.R/24.E/23@(!R5)
			       //       f165=f165+1;
			       //if(strstr(s,"SC1") && strlen(s)==6 && strstr(s,"MR")) //24.KB'/24.R/24.E/23@(!R5)
                               //        f165=f165+1;
			       //if((strstr(s,"SC6") || strstr(s,"SC8") || strstr(s,"SC4") || strstr(s,"SC5")) && strstr(s,"5MR")==NULL)//24.KB'/24.R/24.E/23@(!R5)
                               //        f165=f165+1;
			       //if((strstr(s,"SN6") || strstr(s,"SC8") || strstr(s,"SN4") || strstr(s,"SN5")) && strstr(s,"5MR")==NULL) //24.KB'/24.R/24.E/23@(!R5)
                               //        f165=f165+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL) 
			{
				if(strstr(s,"OCN") && strstr(s, "DON")==NULL)
					f165=f165+1;
				if(strstr(s,"DIN"))
					f166=f166+1;
			}

			//if(strncmp(s,"N",1)==0 && (strstr(s,"NC6") || strstr(s,"NC8") || strstr(s,"NC9")))			//Reactive-Aromatic-N
			//	f166=f166+1;
			//if(strncmp(s,"SC2",3)==0)											//S=C-group; 21.B'
			//	f166=f166+1;
                        if(strncmp(s,"N",1)==0 && strstr(s,"5MR")==NULL && (strstr(s,"NC4NC4NO2") || strstr(s,"NC4NO2NC4") || strstr(s,"NO2NC4NC4")))	//N-oxide; 11.????L@(!R5)
				f167=f167+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"5MR")==NULL && (strstr(s,"NC4NC4NO1") || strstr(s,"NC4NO1NC4") || strstr(s,"NO1NC4NC4")))     //N-oxide; 11.????L@(!R5)
                                f167=f167+1;
			if(strncmp(s, "N", 1)==0 && (strstr(s,"NO2NO1NO1") || strstr(s,"NO1NO2NO1") || strstr(s,"NO1NO1NO2")))   //-NO3-group; 8.KLL
				f168=f168+1;
			if(strncmp(s, "N", 1)==0 && (strstr(s,"NO1NO2NO2") || strstr(s,"NO2NO1NO2") || strstr(s,"NO2NO2NO1")))   //-NO3-group; 8.KLL
                                f168=f168+1;
			//if(strncmp(s, "N", 1)==0 && (strstr(s,"NO1NO1NO1")))  							 //-NO3-group; 8.KLL
                        //        f168=f168+1;

			//if(strncmp(s, "P", 1)==0 && strstr(s,"PN2"))								//-PN2-group; 20.G'
			if(strncmp(s, "S", 1)==0 && strstr(s,"SO2") && (strstr(s,"Sl1") || strstr(s,"SF1") || strstr(s,"SB1") || strstr(s,"SI1")))  //SO2-X bond
				f169=f169+1;

			if(strncmp(s,"N", 1)==0) 
			{
				if(strstr(s,"AMD")==NULL && strstr(s,"DAM")==NULL && strstr(s,"MTD")==NULL && strstr(s,"DTD")==NULL && strstr(s,"UER")==NULL && 
			   strstr(s,"DUR")==NULL && strstr(s,"NYL")==NULL && strstr(s,"DYL")==NULL && strstr(s,"NN1")==NULL && strstr(s,"S=O")==NULL && strstr(s,"NN1")==NULL && 
			   strchr(st1,'2')==NULL && strchr(st2,'2')==NULL && strchr(st3,'2')==NULL && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL && strstr(s,"P=O")==NULL)
				{
					if(strstr(s,"3MR"))										//Amine-3-member-ring; 10.????????(!J!??!??)@R3/10.??????(!J!??!??)@R3
						f170=f170+1;
					if(strstr(s,"4MR"))                          		                                        //Amine-4-member-ring; 10.????????(!J!??!??)@R4/10.??????(!J!??!??)@R4
                                		f171=f171+1;
					if(strstr(s,"5MR"))                                                                             //Amine-5-member-ring; 10.????????(!J!??!??)@R5/10.??????(!J!??!??)@R5
                                	        f175=f175+1;
					if(strstr(s,"6MR"))                                                                             //Amine-6-member-ring; 10.????????(!J!??!??)@R6/10.??????(!J!??!??)@R6
                                	        f409=f409+1;
				}
			}
			if(strncmp(s,"O", 1)==0 && strstr(s,"3MR") && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strstr(s,"S=O")==NULL && strstr(s,"P=O")==NULL)     //Epoxide-3-member-ring;  14.??'??'@R3
                                f172=f172+1;
                        if(strncmp(s,"O", 1)==0 && strstr(s,"4MR") && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strstr(s,"S=O")==NULL && strstr(s,"P=O")==NULL)     //Epoxide-4-member-ring; 14.??'??'@R4
                                f173=f173+1;
			if(strncmp(s,"O", 1)==0 && strstr(s,"5MR") && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strstr(s,"S=O")==NULL && strstr(s,"P=O")==NULL)    //Epoxide-5-member-ring; 14.??'??'@R5
                                f391=f391+1;
			if(strncmp(s,"O", 1)==0 && strstr(s,"6MR") && strstr(s,"EST")==NULL && strstr(s,"DST")==NULL && strstr(s,"OCN")==NULL && strstr(s,"ODD")==NULL && strstr(s,"OTD")==NULL && strstr(s,"DIN")==NULL && strstr(s,"DON")==NULL && strstr(s,"ENE")==NULL && strstr(s,"DNE")==NULL && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strstr(s,"S=O")==NULL && strstr(s,"P=O")==NULL)     //Epoxide-6-member-ring; 14.??'??'@R6
                                f392=f392+1;
			if(strncmp(s,"O", 1)==0)
			{
				if(strstr(s,"EST") && strstr(s, "DON")==NULL)		//DON condition was added on 12.15.21
				{
					if(strstr(s,"3MR"))				//Ester-O-3-member-ring; 14.??E@R3/14.??Z@R3
						f393=f393+1;
					if(strstr(s,"4MR"))				//Ester-O-4-member-ring; 14.??E@R4/14.??Z@R4
                                                f394=f394+1;
					if(strstr(s,"5MR"))				//Ester-O-5-member-ring; 14.??E@R5/14.??Z@R5
                                                f395=f395+1;
					if(strstr(s,"6MR"))				//Ester-O-6-member-ring; 14.??E@R6/14.??Z@R6
                                                f396=f396+1;
				}
				if(strstr(s,"DST"))
                                {
                                        if(strstr(s,"3MR"))				//Di-Ester-O-3-member-ring; 14.????@R3
                                                f397=f397+1;
                                        if(strstr(s,"4MR"))				//Di-Ester-O-4-member-ring; 14.????@R4
                                                f398=f398+1;
                                        if(strstr(s,"5MR"))				//Di-Ester-O-5-member-ring; 14.????@R5
                                                f399=f399+1;
                                        if(strstr(s,"6MR"))				//Di-Ester-O-6-member-ring; 14.????@R6
                                                f400=f400+1;
                                }
				if(strstr(s,"OCN") && strstr(s, "DON")==NULL)		//DON condition was added on 12.15.21
                                {
                                        if(strstr(s,"3MR"))				//(C=N)Ester-O-3-member-ring; 14.??E@R3/14.??Z@R3
                                                f401=f401+1;
                                        if(strstr(s,"4MR"))				//(C=N)Ester-O-4-member-ring; 14.??E@R4/14.??Z@R4		
                                                f402=f402+1;
                                        if(strstr(s,"5MR"))				//(C=N)Ester-O-5-member-ring; 14.??E@R5/14.??Z@R5
                                                f403=f403+1;
                                        if(strstr(s,"6MR"))				//(C=N)Ester-O-6-member-ring; 14.??E@R6/14.??Z@R6
                                                f404=f404+1;
                                }
				if(strstr(s,"DIN"))
                                {
                                        if(strstr(s,"3MR"))				//(C=N)2Ester-O-3-member-ring; 14.????@R3
                                                f405=f405+1;
                                        if(strstr(s,"4MR"))				//(C=N)2Ester-O-4-member-ring; 14.????@R4
                                                f406=f406+1;
                                        if(strstr(s,"5MR"))				//(C=N)2Ester-O-5-member-ring; 14.????@R5
                                                f407=f407+1;
                                        if(strstr(s,"6MR"))				//(C=N)2Ester-O-6-member-ring; 14.????@R6
                                                f408=f408+1;
                                }
				if(strstr(s,"ENE"))
                                {
                                        if(strstr(s,"3MR"))                             //-O-C=C-in-3-member-ring; 14.??E@R3 
                                                f440=f440+1;
                                        if(strstr(s,"4MR"))                             //-O-C=C-in-4-member-ring; 14.??E@R4
                                                f441=f441+1;
                                        if(strstr(s,"5MR"))                             //-O-C=C-in-5-member-ring; 14.??E@R5
                                                f442=f442+1;
                                        if(strstr(s,"6MR"))                             //-O-C=C-in-6-member-ring; 14.??E@R6
                                                f443=f443+1;
                                }
				if(strstr(s,"DNE"))
                                {
                                        if(strstr(s,"3MR"))                             //C=C-O-C=C-in-3-member-ring; 14.????@R3
                                                f444=f444+1;
                                        if(strstr(s,"4MR"))                             //C=C-O-C=C-in-4-member-ring; 14.????@R4
                                                f445=f445+1;
                                        if(strstr(s,"5MR"))                             //C=C-O-C=C-in-5-member-ring; 14.????@R5
                                                f446=f446+1;
                                        if(strstr(s,"6MR"))                             //C=C-O-C=C-in-6-member-ring; 14.????@R6
                                                f447=f447+1;
                                }
			}
			if(strchr(st1,'4')==NULL && strchr(st1,'2')==NULL && strchr(st1,'6')==NULL && strchr(st1,'8')==NULL && strchr(st1,'9')==NULL &&
                           strchr(st2,'4')==NULL && strchr(st2,'2')==NULL && strchr(st2,'6')==NULL && strchr(st2,'8')==NULL && strchr(st2,'9')==NULL &&
                           strchr(st3,'4')==NULL && strchr(st3,'2')==NULL && strchr(st3,'6')==NULL && strchr(st3,'8')==NULL && strchr(st3,'9')==NULL)
			{
				if(strncmp(s,"S", 1)==0 && strstr(s,"3MR") && strstr(s,"EST")==NULL)                                    //Thioether(S)-3-member-ring; 22.??'??'@R3
                                	f78=f78+1;
                        	if(strncmp(s,"S", 1)==0 && strstr(s,"4MR") && strstr(s,"EST")==NULL)                                    //Thioether(S)-4-member-ring; 22.??'??'@R4
                                	f79=f79+1;
				if(strncmp(s,"S", 1)==0 && strstr(s,"5MR") && strstr(s,"EST")==NULL)                                    //Thioether(S)-5-member-ring; 22.??'??'@R5
                                        f104=f104+1;
				if(strncmp(s,"S", 1)==0 && strstr(s,"6MR") && strstr(s,"EST")==NULL)                                    //Thioether(S)-6-member-ring; 22.??'??'@R6
                                        f174=f174+1;
			}
			//THis part is replaced by amine containing functional group...
			/*	if(strncmp(s,"S", 1)==0 && strstr(s,"5MR") && strstr(s,"EST")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL)   //Thioether(S)-5-and-higher-member-ring; 22.??'??'(!??!??)@R5
                                	f409=f409+1;
				if(strncmp(s,"S", 1)==0 && strstr(s,"6MR") && strstr(s,"EST")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL)   //Thioether(S)-5-and-higher-member-ring; 22.??'??'(!??!??)@R6
                               		f409=f409+1;
				if(strncmp(s,"S", 1)==0 && strstr(s,"7MR") && strstr(s,"EST")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL)   //Thioether(S)-5-and-higher-member-ring; 22.??'??'(!??!??)@R7
                                	f409=f409+1;
				if(strncmp(s,"S", 1)==0 && strstr(s,"8MR") && strstr(s,"EST")==NULL && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL)   //Thioether(S)-5-and-higher-member-ring; 22.??'??'(!??!??)@R8
                                	f409=f409+1;
			}*/


			 if(strncmp(s,"C", 1)==0 && strstr(s,"CS2") && strstr(s,"CNJ")==NULL)   //CNJ condition was added on 12.19.21
			 {
			 	if(strstr(s,"CO1") && strstr(s,"CN1"))
                                {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(N)(O)-3/4-member-ring; 2.RNJ@R3/2.RNJ@R4
                                                f176=f176+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(N)(O)-5-member-ring; 2.RNJ@R5
                                                f177=f177+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(N)(O)-6-member-ring; 2.RNJ@R6
                                                f178=f178+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(N)(O)-7-member-ring; 2.RNJ@R7
                                                f179=f179+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f180=f180+1;                                                            //Rest-of-the-CS2(N)(O)-groups; 2.RNJ@Rg7
				}
				
				if(strstr(s,"CO1CO1") || strstr(s,"CO1CS2CO1"))
                               	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(O)(O)-3/4-member-ring; 2.RNN@R3/2.RNN@R4
                                                f181=f181+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(O)(O)-5-member-ring; 2.RNN@R5
                                                f182=f182+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(O)(O)-6-member-ring; 2.RNN@R6
                                                f183=f183+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(O)(O)-7-member-ring; 2.RNN@R7
                                                f184=f184+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f185=f185+1;                                                            //Rest-of-the-CS2(O)(O)-groups; 2.RNN@Rg7
                               	}

				if(strstr(s,"CN1CN1") || strstr(s,"CN1CS2CN1"))
                               	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(N)(N)-3/4-member-ring; 2.RJJ@R3/2.RJJ@R4
                                                f186=f186+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(N)(N)-5-member-ring; 2.RJJ@R5
                                                f187=f187+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(N)(N)-6-member-ring; 2.RJJ@R6
                                                f188=f188+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(N)(N)-7-member-ring; 2.RJJ@R7
                                                f189=f189+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f190=f190+1;                                                            //Rest-of-the-CS2(N)(N)-groups; 2.RJJ@Rg7
                               	}

				
				if(strstr(s,"CS1"))
                                {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2()(S)-3/4-member-ring; 2.RU??@R3/2.RU??@R4
                                                f191=f191+1;
                                        if(strstr(s,"5MR"))                                                             //CS2()(S)-5-member-ring; 2.RU??@R5
                                                f192=f192+1;
                                        if(strstr(s,"6MR"))                                                             //CS2()(S)-6-member-ring; 2.RU??@R6
                                                f193=f193+1;
                                        if(strstr(s,"7MR"))                                                             //CS2()(S)-7-member-ring; 2.RU??@R7
                                                f194=f194+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f195=f195+1;								//Rest-ot-the-CS2()(S)-groups; 2.RU??@Rg7
				}

				if(strstr(s,"CC1") && strstr(s,"CN1"))
				{
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(C)(N)-3/4-member-ring; 2.RJE@R3/2.RJE@R4
                                                f196=f196+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(C)(N)-5-member-ring; 2.RJE@R5
                                                f197=f197+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(C)(N)-6-member-ring; 2.RJE@R6
                                                f198=f198+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(C)(N)-7-member-ring; 2.RJE@R7
                                                f199=f199+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f200=f200+1;								//Rest-ot-the-CS2(C)(N)-groups; 2.RJE@Rg7
                                }
				
				if(strstr(s,"CC1") && strstr(s,"CO1"))
                                {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(C)(O)-3/4-member-ring; 2.RNE@R3/2.RNE@R4
                                                f201=f201+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(C)(O)-5-member-ring; 2.RNE@R5
                                                f202=f202+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(C)(O)-6-member-ring; 2.RNE@R6
                                                f203=f203+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(C)(O)-7-member-ring; 2.RNE@R7
                                                f204=f204+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f205=f205+1;                                                            //Rest-ot-the-CS2(C)(O)-groups; 2.RNE@Rg7
                                }
				
				if(strstr(s,"CS2CC1CC1") || strstr(s,"CC1CS2CC1") || strstr(s,"CC1CC1CS2"))
				{
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CS2(C)(C)-3/4-member-ring; 2.REE@R3/2.REE@R4
                                                f211=f211+1;
                                        if(strstr(s,"5MR"))                                                             //CS2(C)(C)-5-member-ring; 2.REE@R5
                                                f212=f212+1;
                                        if(strstr(s,"6MR"))                                                             //CS2(C)(C)-6-member-ring; 2.REE@R6
                                                f213=f213+1;
                                        if(strstr(s,"7MR"))                                                             //CS2(C)(C)-7-member-ring; 2.REE@R7
                                                f214=f214+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f215=f215+1;								//Rest-ot-the-CS2(C)(C)-groups; 2.REE@Rg7
				}

			 }

			 	if(strncmp(s,"C", 1)==0 && strstr(s,"CN2"))
			 	{
			 		if(strstr(s,"CO1") && strstr(s,"CN1"))
                                	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(N)(O)-3/4-member-ring; 2.G'NJ@R3/2.G'NJ@R4
                                                f216=f216+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(N)(O)-5-member-ring; 2.G'NJ@R5
                                                f217=f217+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(N)(O)-6-member-ring; 2.G'NJ@R6
                                                f218=f218+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(N)(O)-7-member-ring; 2.G'NJ@R7
                                                f219=f219+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f220=f220+1;                                                            //Rest-of-the-CN2(N)(O)-groups; 2.G'NJ@Rg7
					}

					if(strstr(s,"CO1CO1") || strstr(s,"CO1CN2CO1"))
                                	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(O)(O)-3/4-member-ring; 2.G'NN@R3/2.G'NN@R4
                                                f221=f221+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(O)(O)-5-member-ring; 2.G'NN@R5
                                                f222=f222+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(O)(O)-6-member-ring; 2.G'NN@R6
                                                f223=f223+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(O)(O)-7-member-ring; 2.G'NN@R7
                                                f224=f224+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f225=f225+1;                                                            //Rest-of-the-CN2(O)(O)-groups; 2.G'NN@Rg7
                                	}

					if((strstr(s,"CN1CN1") || strstr(s,"CN1CN2CN1")) && strstr(s,"CNJ")==NULL)
                                	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(N)(N)-3/4-member-ring; 2.G'JJ@R3/2.G'JJ@R4
                                                f226=f226+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(N)(N)-5-member-ring; 2.G'JJ@R5
                                                f227=f227+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(N)(N)-6-member-ring; 2.G'JJ@R6
                                                f228=f228+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(N)(N)-7-member-ring; 2.G'JJ@R7
                                                f229=f229+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f230=f230+1;                                                            //Rest-of-the-CN2(N)(N)-groups; 2.G'JJ@Rg7
                                	}


					if(strstr(s,"CS1") && strstr(s,"CNJ")==NULL)
                        	        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(S)()-3/4-member-ring; 2.G'U??@R3/2.G'U??@R4
                                                f231=f231+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(S)()-5-member-ring; 2.G'U??@R5
                                                f232=f232+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(S)()-6-member-ring; 2.G'U??@R6
                                                f233=f233+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(S)()-7-member-ring; 2.G'U??@R7
                                                f234=f234+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f235=f235+1;								//Rest-ot-the-CN2(S)()-groups; 2.G'U??@Rg7
					}

					if((strstr(s,"CC1") && strstr(s,"CN1")) && strstr(s,"CNJ")==NULL)
					{
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(C)(N)-3/4-member-ring; 2.G'EJ@R3/2.G'EJ@R4
                                                f236=f236+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(C)(N)-5-member-ring; 2.G'EJ@R5
                                                f237=f237+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(C)(N)-6-member-ring; 2.G'EJ@R6
                                                f238=f238+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(C)(N)-7-member-ring; 2.G'EJ@R7
                                                f239=f239+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f240=f240+1;								//Rest-ot-the-CN2(C)(N)-groups; 2.G'EJ@Rg7
                                	}

					if(strstr(s,"CC1") && strstr(s,"CO1"))
                                	{
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(C)(O)-3/4-member-ring; 2.G'EN@R3/2.G'EN@R4
                                                f241=f241+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(C)(O)-5-member-ring; 2.G'EN@R5
                                                f242=f242+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(C)(O)-6-member-ring; 2.G'EN@R6
                                                f243=f243+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(C)(O)-7-member-ring; 2.G'EN@R7
                                                f244=f244+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f245=f245+1;                                                            //Rest-ot-the-CN2(C)(O)-groups; 2.G'EN@Rg7
                                	}

					if(strstr(s,"CN2CC1CC1") || strstr(s,"CC1CN2CC1") || strstr(s,"CC1CC1CN2"))
					{
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CN2(C)(C)-3/4-member-ring; 2.G'EE@R3/2.G'EE@R4
                                                f246=f246+1;
                                        if(strstr(s,"5MR"))                                                             //CN2(C)(C)-5-member-ring; 2.G'EE@R5
                                                f247=f247+1;
                                        if(strstr(s,"6MR"))                                                             //CN2(C)(C)-6-member-ring; 2.G'EE@R6
                                                f248=f248+1;
                                        if(strstr(s,"7MR"))                                                             //CN2(C)(C)-7-member-ring; 2.G'EE@R7
                                                f249=f249+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f250=f250+1;								//Rest-ot-the-CN2(C)(C)-groups; 2.G'EE@Rg7
					}

			 	}
				
				if(strncmp(s,"C", 1)==0 && strstr(s,"CC2") && strstr(s,"CNJ")==NULL)  //CNJ condition was added on 12.19.21
                                {
                                        if(strstr(s,"CO1") && strstr(s,"CN1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(N)(O)-3/4-member-ring; 2.B'NJ@R3/2.B'NJ@R4
                                                f254=f254+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(N)(O)-5-member-ring; 2.B'NJ@R5
                                                f255=f255+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(N)(O)-6-member-ring; 2.B'NJ@R6
                                                f256=f256+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(N)(O)-7-member-ring; 2.B'NJ@R7
                                                f257=f257+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f258=f258+1;                                                            //Rest-of-the-CC2(N)(O)-groups; 2.B'NJ@Rg7
                                        }

                                        if(strstr(s,"CO1CO1") || strstr(s,"CO1CC2CO1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(O)(O)-3/4-member-ring; 2.B'NN@R3/2.B'NN@R4
                                                f259=f259+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(O)(O)-5-member-ring; 2.B'NN@R5
                                                f260=f260+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(O)(O)-6-member-ring; 2.B'NN@R6
                                                f261=f261+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(O)(O)-7-member-ring; 2.B'NN@R7
                                                f262=f262+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f263=f263+1;                                                            //Rest-of-the-CC2(O)(O)-groups; 2.B'NN@Rg7
                                        }

                                        if(strstr(s,"CN1CN1") || strstr(s,"CN1CC2CN1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(N)(N)-3/4-member-ring; 2.B'JJ@R3/2.B'JJ@R4
                                                f264=f264+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(N)(N)-5-member-ring; 2.B'JJ@R5
                                                f265=f265+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(N)(N)-6-member-ring; 2.B'JJ@R6
                                                f266=f266+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(N)(N)-7-member-ring; 2.B'JJ@R7
                                                f267=f267+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f268=f268+1;                                                            //Rest-of-the-CC2(N)(N)-groups; 2.B'JJ@Rg7
                                        }
					
					if(strstr(s,"CS1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(S)()-3/4-member-ring; 2.B'U??@R3/2.B'U??@R4
                                                f269=f269+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(S)()-5-member-ring; 2.B'U??@R5
                                                f270=f270+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(S)()-6-member-ring; 2.B'U??@R6
                                                f271=f271+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(S)()-7-member-ring; 2.B'U??@R7
                                                f272=f272+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f273=f273+1;                                                            //Rest-ot-the-CC2(S)()-groups; 2.B'U??@Rg7
                                        }

                                        if(strstr(s,"CC1") && strstr(s,"CN1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(C)(N)-3/4-member-ring; 2.B'EJ@R3/2.B'EJ@R4
                                                f274=f274+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(C)(N)-5-member-ring; 2.B'EJ@R5
                                                f275=f275+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(C)(N)-6-member-ring; 2.B'EJ@R6
                                                f276=f276+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(C)(N)-7-member-ring; 2.B'EJ@R7
                                                f277=f277+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f278=f278+1;                                                            //Rest-ot-the-CC2(C)(N)-groups; 2.B'EJ@Rg7
                                        }

                                        if(strstr(s,"CC1") && strstr(s,"CO1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(C)(O)-3/4-member-ring; 2.B'EN@R3/2.B'EN@R4
                                                f279=f279+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(C)(O)-5-member-ring; 2.B'EN@R5
                                                f280=f280+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(C)(O)-6-member-ring; 2.B'EN@R6
                                                f281=f281+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(C)(O)-7-member-ring; 2.B'EN@R7
                                                f282=f282+1;
                                        if(strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL)
                                                f283=f283+1;                                                            //Rest-ot-the-CC2(C)(O)-groups; 2.B'EN@Rg7
                                        }

					if(strstr(s,"CH1") && strstr(s,"CC1"))
                                        {
                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(C)(H)-3/4-member-ring; 2.B'ZE@R3/2.B'ZE@R4
                                                f284=f284+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(C)(H)-5-member-ring; 2.B'ZE@R5
                                                f285=f285+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(C)(H)-6-member-ring; 2.B'ZE@R6
                                                f286=f286+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(C)(H)-7-member-ring; 2.B'ZE@R7
                                                f287=f287+1;
                                        }

					if(strstr(s,"CC2CC1CC1") || strstr(s,"CC1CC2CC1") || strstr(s,"CC1CC1CC2"))
					{
					if(strstr(s,"3MR") || strstr(s,"4MR"))                                          //CC2(C)(C)-3/4-member-ring; 2.B'EE@R3/2.B'EE@R4
                                                f288=f288+1;
                                        if(strstr(s,"5MR"))                                                             //CC2(C)(C)-5-member-ring; 2.B'EE@R5
                                                f289=f289+1;
                                        if(strstr(s,"6MR"))                                                             //CC2(C)(C)-6-member-ring; 2.B'EE@R6
                                                f290=f290+1;
                                        if(strstr(s,"7MR"))                                                             //CC2(C)(C)-7-member-ring; 2.B'EE@R7
                                                f291=f291+1;
                                        }
				}

				if((strstr(s,"CN2")) && strstr(s,"CH1") && strstr(s,"CS1")==NULL)	//C(=N)(H)(); 2.G'Z(!U)/2.RZ(!U)
					f251=f251+1;

				if(strncmp(s,"N",1)==0)
				{
					if(strstr(s,"NH1"))
					{
						if(strstr(s,"AMD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL)
						{
							if(strstr(s,"3MR") || strstr(s,"4MR"))				//Amide(NH)-3/4-member-ring; 10.??Z??@R3/10.??Z??@R4
								f292=f292+1;
							if(strstr(s,"5MR"))						//Amide(NH)-5-member-ring; 10.??Z??@R5
								f293=f293+1;
							if(strstr(s,"6MR"))						//Amide(NH)-6-member-ring; 10.??Z??@R6
                                                                f294=f294+1;
							if(strstr(s,"7MR"))						//Amide(NH)-7-member-ring; 10.??Z??@R7
                                                                f295=f295+1;
						}
						if(strstr(s,"DAM"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-Amide(NH)-3/4-member-ring; 10.????Z@R3/10.????Z@R4
                                                                f296=f296+1;
                                                        if(strstr(s,"5MR"))						//Di-Amide(NH)-5-member-ring; 10.????Z@R5
                                                                f297=f297+1;
                                                        if(strstr(s,"6MR"))						//Di-Amide(NH)-6-member-ring; 10.????Z@R6
                                                                f298=f298+1;
                                                        if(strstr(s,"7MR"))						//Di-Amide(NH)-7-member-ring; 10.????Z@R7
                                                                f299=f299+1;
                                                }
						if(strstr(s,"MTD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Thioamide(NH)-3/4-member-ring; 10.??Z??@R3/10.??Z??@R4
                                                                f300=f300+1;
                                                        if(strstr(s,"5MR"))						//Thioamide(NH)-5-member-ring; 10.??Z??@R5
                                                                f301=f301+1;
                                                        if(strstr(s,"6MR"))						//Thioamide(NH)-6-member-ring; 10.??Z??@R6
                                                                f302=f302+1;
                                                        if(strstr(s,"7MR"))						//Thioamide(NH)-7-member-ring; 10.??Z??@R7
                                                                f303=f303+1;
                                                }
						if(strstr(s,"DTD"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-thioamide(NH)-3/4-member-ring; 10.????Z@R3/10.????Z@R4
                                                                f304=f304+1;
                                                        if(strstr(s,"5MR"))						//Di-Thioamide(NH)-5-member-ring; 10.????Z@R5
                                                                f305=f305+1;
                                                        if(strstr(s,"6MR"))						//Di-Thioamide(NH)-6-member-ring; 10.????Z@R6
                                                                f306=f306+1;
                                                        if(strstr(s,"7MR"))						//Di-Thioamide(NH)-7-member-ring; 10.????Z@R7
                                                                f307=f307+1;
                                                }
						if(strstr(s,"UER") && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Amidine(NH)-3/4-member-ring; 10.??Z??@R3/10.??Z??@R4
                                                                f308=f308+1;
                                                        if(strstr(s,"5MR"))						//Amidine(NH)-5-member-ring; 10.??Z??@R5
                                                                f309=f309+1;
                                                        if(strstr(s,"6MR"))						//Amidine(NH)-6-member-ring; 10.??Z??@R6
                                                                f310=f310+1;
                                                        if(strstr(s,"7MR"))						//Amidine(NH)-7-member-ring; 10.??Z??@R7
                                                                f311=f311+1;
                                                }
						if(strstr(s,"DUR"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-amidine(NH)-3/4-member-ring; 10.????Z@R3/10.????Z@R4
                                                                f312=f312+1;
                                                        if(strstr(s,"5MR"))						//Di-amidine(NH)-5-member-ring; 10.????Z@R5
                                                                f313=f313+1;
                                                        if(strstr(s,"6MR"))						//Di-amidine(NH)-6-member-ring; 10.????Z@R6
                                                                f314=f314+1;
                                                        if(strstr(s,"7MR"))						//Di-amidine(NH)-7-member-ring; 10.????Z@R7
                                                                f315=f315+1;
                                                }
						if(strstr(s,"NYL") && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                          //Amine-Conjugation-One-Vinyl-3/4-member-ring; 10.??Z??@R3/10.??Z??@R4
                                                                f416=f416+1;
                                                        if(strstr(s,"5MR"))                                             //Amine-Conjugation-One-Vinyl-5-member-ring; 10.??Z??@R5
                                                                f417=f417+1;
                                                        if(strstr(s,"6MR"))                                             //Amine-Conjugation-One-Vinyl-6-member-ring; 10.??Z??@R6
                                                                f418=f418+1;
                                                        if(strstr(s,"7MR"))                                             //Amine-Conjugation-One-Vinyl-7-member-ring; 10.??Z??@R7
                                                                f419=f419+1;
                                                }
						if(strstr(s,"DYL"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                          //Amine-Conjugation-Two-Vinyl-3/4-member-ring; 10.????Z@R3/10.????Z@R4
                                                                f420=f420+1;
                                                        if(strstr(s,"5MR"))                                             //Amine-Conjugation-Two-Vinyl-5-member-ring; 10.????Z@R5
                                                                f421=f421+1;
                                                        if(strstr(s,"6MR"))                                             //Amine-Conjugation-Two-Vinyl-6-member-ring; 10.????Z@R6
                                                                f422=f422+1;
                                                        if(strstr(s,"7MR"))                                             //Amine-Conjugation-Two-Vinyl-7-member-ring; 10.????Z@R7
                                                                f423=f423+1;
                                                }
					}
					if(strstr(s,"NH1")==NULL && strstr(s,"MR3")==NULL && strstr(s,"MR4")==NULL && strstr(s,"MR5")==NULL && strstr(s,"MR6")==NULL && strstr(s,"MR7")==NULL)
                                        {
                                                if(strstr(s,"AMD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Amide(N)-3/4-member-ring; 10.????'??'@R3/10.????'??'@R4
                                                                f316=f316+1;
                                                        if(strstr(s,"5MR"))						//Amide(N)-5-member-ring; 10.????'??'@R5
                                                                f317=f317+1;
                                                        if(strstr(s,"6MR"))						//Amide(N)-6-member-ring; 10.????'??'@R6
                                                                f318=f318+1;
                                                        if(strstr(s,"7MR"))						//Amide(N)-7-member-ring; 10.????'??'@R7
                                                                f319=f319+1;
                                                }
                                                if(strstr(s,"DAM"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-Amide(N)-3/4-member-ring; 10.??????'@R3/10.??????'@R4
                                                                f320=f320+1;
                                                        if(strstr(s,"5MR"))						//Di-Amide(N)-5-member-ring; 10.??????'@R5
                                                                f321=f321+1;
                                                        if(strstr(s,"6MR"))						//Di-Amide(N)-6-member-ring; 10.??????'@R6
                                                                f322=f322+1;
                                                        if(strstr(s,"7MR"))						//Di-Amide(N)-7-member-ring; 10.??????'@R7
                                                                f323=f323+1;
                                                }
                                                if(strstr(s,"MTD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Thioamide(N)-3/4-member-ring; 10.????'??'@R3/10.????'??'@R4
                                                                f324=f324+1;
                                                        if(strstr(s,"5MR"))						//Thioamide(N)-5-member-ring; 10.????'??'@R5
                                                                f325=f325+1;
                                                        if(strstr(s,"6MR"))						//Thioamide(N)-6-member-ring;10.????'??'@R6
                                                                f326=f326+1;
                                                        if(strstr(s,"7MR"))						//Thioamide(N)-7-member-ring; 10.????'??'@R7
                                                                f327=f327+1;
                                                }
						if(strstr(s,"DTD"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-thioamide(N)-3/4-member-ring; 10.??????'@R3/10.??????'@R4
                                                                f328=f328+1;
                                                        if(strstr(s,"5MR"))						//Di-Thioamide(N)-5-member-ring; 10.??????'@R5
                                                                f329=f329+1;
                                                        if(strstr(s,"6MR"))						//Di-Thioamide(N)-6-member-ring; 10.??????'@R6
                                                                f330=f330+1;
                                                        if(strstr(s,"7MR"))						//Di-Thioamide(N)-7-member-ring; 10.??????'@R7
                                                                f331=f331+1;
                                                }
                                                if(strstr(s,"UER") && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Amidine(N)-3/4-member-ring; 10.????'??'@R3/10.????'??'@R4
                                                                f332=f332+1;
                                                        if(strstr(s,"5MR"))						//Amidine(N)-5-member-ring; 10.????'??'@R5
                                                                f333=f333+1;
                                                        if(strstr(s,"6MR"))						//Amidine(N)-6-member-ring; 10.????'??'@R6
                                                                f334=f334+1;
                                                        if(strstr(s,"7MR"))						//Amidine(N)-7-member-ring; 10.????'??'@R7
                                                                f335=f335+1;
                                                }
                                                if(strstr(s,"DUR"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))				//Di-amidine(N)-3/4-member-ring; 10.??????'@R3/10.??????'@R4
                                                                f336=f336+1;
                                                        if(strstr(s,"5MR"))						//Di-amidine(N)-5-member-ring; 10.??????'@R5
                                                                f337=f337+1;
                                                        if(strstr(s,"6MR"))						//Di-amidine(N)-6-member-ring; 10.??????'@R6
                                                                f338=f338+1;
                                                        if(strstr(s,"7MR"))						//Di-amidine(N)-7-member-ring; 10.??????'@R7
                                                                f339=f339+1;
                                                }
						if(strstr(s,"NYL") && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL)
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                          //Amine-Conjugation-One-Vinyl-3/4-member-ring; 10.????'??'@R3/10.????'??'@R4
                                                                f424=f424+1;
                                                        if(strstr(s,"5MR"))                                             //Amine-Conjugation-One-Vinyl-5-member-ring; 10.????'??'@R5
                                                                f425=f425+1;
                                                        if(strstr(s,"6MR"))                                             //Amine-Conjugation-One-Vinyl-6-member-ring; 10.????'??'@R6
                                                                f426=f426+1;
                                                        if(strstr(s,"7MR"))                                             //Amine-Conjugation-One-Vinyl-7-member-ring; 10.????'??'@R7
                                                                f427=f427+1;
                                                }
                                                if(strstr(s,"DYL"))
                                                {
                                                        if(strstr(s,"3MR") || strstr(s,"4MR"))                          //Amine-Conjugation-Two-Vinyl-3/4-member-ring; 10.??????'@R3/10.??????'@R4
                                                                f428=f428+1;
                                                        if(strstr(s,"5MR"))                                             //Amine-Conjugation-Two-Vinyl-5-member-ring; 10.??????'@R5
                                                                f429=f429+1;
                                                        if(strstr(s,"6MR"))                                             //Amine-Conjugation-Two-Vinyl-6-member-ring; 10.??????'@R6
                                                                f430=f430+1;
                                                        if(strstr(s,"7MR"))                                             //Amine-Conjugation-Two-Vinyl-7-member-ring; 10.??????'@R7
                                                                f431=f431+1;
                                                }
                                        }
				}
				/*if(strncmp(s,"N", 1)==0 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && strstr(s,"NH1")==NULL)
                        {
                                if(strstr(s,"AMD"))                                                             //Amide
                                        f343=f343+1;
                                if(strstr(s,"DAM"))                                                             //Di-Amide
                                        f344=f344+1;
                                if(strstr(s,"MTD"))                                                             //Thioamide
                                        f345=f345+1;
                                if(strstr(s,"DTD"))                                                             //Di-Thioamide
                                        f346=f346+1;
                                if(strstr(s,"UER"))                                                             //Amidine
                                        f347=f347+1;
                                if(strstr(s,"DUR"))                                                             //Di-Amidine
                                        f348=f348+1;
                        }*/
				if(strncmp(s,"N", 1)==0 && strstr(s,"3MR")==NULL && strstr(s,"4MR")==NULL && strstr(s,"5MR")==NULL && strstr(s,"6MR")==NULL && strstr(s,"7MR")==NULL && strstr(s,"NH1")==NULL && strlen(s)>=9)
                        {
                                if(strstr(s,"NYLAMD")==NULL && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLMTD")==NULL &&
                                   strstr(s,"MTDNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"UERNYL")==NULL &&
                                   strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"AMDUER")==NULL &&
                                   strstr(s,"UERAMD")==NULL && strstr(s,"UERMTD")==NULL && strstr(s,"MTDUER")==NULL)
                                {
                                        if(strstr(s,"NYL"))                                                             //Amine-Conjugation-One-Vinyl; 10.????'??'@Rg7
                                                f432=f432+1;
                                        if(strstr(s,"DYL"))                                                             //Amine-Conjugation-Two-Vinyl; 10.??????'@Rg7
                                                f433=f433+1;
                                        if(strstr(s,"AMD"))                                                             //Amide; 10.????'??'@Rg7
                                                f343=f343+1;
                                        if(strstr(s,"DAM"))                                                             //Di-Amide; 10.??????'@Rg7
                                                f344=f344+1;
                                        if(strstr(s,"MTD"))                                                             //Thioamide; 10.????'??'@Rg7
                                                f345=f345+1;
                                        if(strstr(s,"DTD"))                                                             //Di-Thioamide; 10.??????'@Rg7
                                                f346=f346+1;
                                        if(strstr(s,"UER"))                                                             //Amidine; 10.????'??'@Rg7
                                                f347=f347+1;
                                        if(strstr(s,"DUR"))                                                             //Di-Amidine; 10.??????'@Rg7
                                                f348=f348+1;
                                }
			}
				if(strncmp(s,"N", 1)==0 && strstr(s,"NH1")==NULL && strlen(s)>=15)
                        {
                                if(strstr(s,"NYLAMD") || strstr(s,"AMDNYL"))                                            //Amine-Conjugation-Amide-Vinyl; 10.??????'@Rg7
                                        f434=f434+1;
                                if(strstr(s,"NYLMTD") || strstr(s,"MTDNYL"))                                            //Amine-Conjugation-Thioamide-Vinyl; 10.??????'@Rg7
                                        f435=f435+1;
                                if(strstr(s,"NYLUER") || strstr(s,"UERNYL"))                                            //Amine-Conjugation-Imine-Vinyl; 10.??????'@Rg7
                                        f436=f436+1;
                                if(strstr(s,"AMDMTD") || strstr(s,"MTDAMD"))                                            //Amine-Conjugation-Amide-Thioamide; 10.??????'@Rg7
                                        f437=f437+1;
                                if(strstr(s,"AMDUER") || strstr(s,"UERAMD"))                                            //Amine-Conjugation-Amide-Imine; 10.??????'@Rg7
                                        f438=f438+1;
                                if(strstr(s,"MTDUER") || strstr(s,"UERMTD"))                                            //Amine-Conjugation-Thioamide-Imine; 10.??????'@Rg7
                                        f439=f439+1;
                        }
			if(strncmp(s,"N", 1)==0 && strstr(s,"NH1")==NULL)
			{
				if(strstr(s,"AMD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL)
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))  
						f497=f497+1;  //Amide(N)-fused-3/4-member-ring; 10.????'??'@R3_R/10.????'??'@R4_R
					if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f498=f498+1; //Amide(N)-fused-5/6/7-member-ring; 10.????'??'@R5_5/10.????'??'@R6_6/10.????'??'@R7_7/10.????'??'@R5_6/10.????'??'@R5_7/10.????'??'@R6_7
				}

				if(strstr(s,"DAM"))
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f499=f499+1; //Diamide(N)-fused-3/4-member-ring; 10.??????'@R3_R/10.??????'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f500=f500+1; //Diamide(N)-fused-5/6/7-member-ring; 10.??????'@R5_5/10.??????'@R6_6/10.??????'@R7_7/10.??????'@R5_6/10.??????'@R5_7/10.??????'@R6_7
                                }

				if(strstr(s,"MTD") && strstr(s,"AMDMTD")==NULL && strstr(s,"MTDAMD")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f501=f501+1; //Thioamide(N)-fused-3/4-member-ring; 10.????'??'@R3_R/10.????'??'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f502=f502+1; //Thioamide(N)-fused-5/6/7-member-ring; 10.????'??'@R5_5/10.????'??'@R6_6/10.????'??'@R7_7/10.????'??'@R5_6/10.????'??'@R5_7/10.????'??'@R6_7
                                }

				if(strstr(s,"DTD"))
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f503=f503+1; //Dithioamide(N)-fused-3/4-member-ring; 10.??????'@R3_R/10.??????'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f504=f504+1; //Dithioamide(N)-fused-5/6/7-member-ring; 10.??????'@R5_5/10.??????'@R6_6/10.??????'@R7_7/10.??????'@R5_6/10.??????'@R5_7/10.??????'@R6_7
                                }

				if(strstr(s,"UER") && strstr(s,"AMDUER")==NULL && strstr(s,"UERAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDUER")==NULL && strstr(s,"UERMTD")==NULL)
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f505=f505+1; //Amidine(N)-fused-3/4-member-ring; 10.????'??'@R3_R/10.????'??'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f506=f506+1; //Amidine(N)-fused-5/6/7-member-ring; 10.????'??'@R5_5/10.????'??'@R6_6/10.????'??'@R7_7/10.????'??'@R5_6/10.????'??'@R5_7/10.????'??'@R6_7
                                }

				if(strstr(s,"DUR"))
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f507=f507+1; //Urea(N)-fused-3/4-member-ring; 10.??????'@R3_R/10.??????'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f508=f508+1; //Urea(N)-fused-5/6/7-member-ring; 10.??????'@R5_5/10.??????'@R6_6/10.??????'@R7_7/10.??????'@R5_6/10.??????'@R5_7/10.??????'@R6_7
                                }

				if(strstr(s,"NYL") && strstr(s,"AMDNYL")==NULL && strstr(s,"NYLAMD")==NULL && strstr(s,"UERNYL")==NULL && strstr(s,"NYLUER")==NULL && strstr(s,"MTDNYL")==NULL && strstr(s,"NYLMTD")==NULL)
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f509=f509+1; //VinylAmine(N)-fused-3/4-member-ring; 10.????'??'@R3_R/10.????'??'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f510=f510+1; //VinylAmine(N)-fused-5/6/7-member-ring; 10.????'??'@R5_5/10.????'??'@R6_6/10.????'??'@R7_7/10.????'??'@R5_6/10.????'??'@R5_7/10.????'??'@R6_7
                                }

				if(strstr(s,"DYL"))
				{
					if(strstr(s,"MR3") || strstr(s,"MR4") || strstr(s,"3MR5") || strstr(s,"3MR6") || strstr(s,"3MR7") || strstr(s,"4MR5") || strstr(s,"4MR6") || strstr(s,"4MR7"))
                                                f511=f511+1; //Di-vinylAmine(N)-fused-3/4-member-ring; 10.??????'@R3_R/10.??????'@R4_R
                                        if((strstr(s,"MR5") || strstr(s,"MR6") || strstr(s,"MR7")) && strstr(s,"3MR5")==NULL && strstr(s,"3MR6")==NULL && strstr(s,"3MR7")==NULL && strstr(s,"4MR5")==NULL && strstr(s,"4MR6")==NULL && strstr(s,"4MR7")==NULL)
                                                f512=f512+1; //Di-vinylAmine(N)-fused-5/6/7-member-ring; 10.??????'@R5_5/10.??????'@R6_6/10.??????'@R7_7/10.??????'@R5_6/10.??????'@R5_7/10.??????'@R6_7
                                }
			}


			if(strncmp(s,"O",1)==0 && strstr(s,"DST") && strstr(s, "3MR")==NULL && strstr(s, "4MR")==NULL && strstr(s, "5MR")==NULL && strstr(s, "6MR")==NULL) //O=C-O-C=O; 14.????@Rg6
				f349=f349+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"ODD")) //S=C-O-C=S; 14.????
                                f350=f350+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"DON"))                                                //O=C-O-C=N; 14.????
                                f351=f351+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"OTD")) //S=C-O-C; 14.??E
				f410=f410+1;
			/*if(strncmp(s,"N",1)==0 && strstr(s,"NC2") && strstr(s,"NC1") && strstr(s,"NO1"))
				f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NC2") && strstr(s,"NC1") && strstr(s,"NO2")) //8.B'EN/8.B'KE/8.G'EN/8.G'KE/8.B'JN/8.B'JK/8.G'JN/8G'JK
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2") && strstr(s,"NC1") && strstr(s,"NO1"))
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2") && strstr(s,"NC1") && strstr(s,"NO2"))	//Uncommon-N-containing compound
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NC2") && strstr(s,"NN1") && strstr(s,"NO1"))
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NC2") && strstr(s,"NN1") && strstr(s,"NO2"))
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2") && strstr(s,"NN1") && strstr(s,"NO1"))
                                f410=f410+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"NN2") && strstr(s,"NN1") && strstr(s,"NO2"))
                                f410=f410+1;*/

			//Commented on 20.10.2022
			//if(strncmp(s,"N",1)==0 && strstr(s,"POS"))					//Positively-Charged-sp3(N); 44
                        //        f477=f477+1;
			//if(strncmp(s,"N",1)==0 && strstr(s,"NEG"))					//Negatively-Charged-Nitrogen; 45
                        //	f479=f479+1;
			//	End of commenting
			if(strncmp(s,"O",1)==0 && strstr(s,"OC1EST") && strlen(s)<=7)			//Negatively-Charged-Oxygen; 46
                                f478=f478+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"OC1EST") && strlen(s)<=10 && strstr(s,"NEG")) //Negatively-Charged-Oxygen; 46
                                f478=f478+1;
			if(strncmp(s,"O",1)==0 && strstr(s,"OC1NEGEST") && strlen(s)<=10) 		//Negatively-Charged-Oxygen; 46
                                f478=f478+1;
			if(strncmp(s,"O",1)==0 && strlen(s)<=7 && strchr(s,'2')==NULL && strstr(s,"NEG"))//Negatively-Charged-Oxygen; 46
                                f478=f478+1;
			if(strncmp(s,"O",1)==0 && strlen(s)<=4 && strchr(s,'2')==NULL)			//Negatively-Charged-Oxygen; 47 
                                f478=f478+1;
			if(strncmp(s,"S",1)==0 && strlen(s)<=4 && strchr(s,'2')==NULL)                  //Negatively-Charged-Sulfur; 45 
                                f479=f479+1;
			if(strncmp(s,"S",1)==0 && strlen(s)<=7 && strchr(s,'2')==NULL && strstr(s,"NEG"))//Negatively-Charged-Sulfur; 45
                                f479=f479+1;
			if(strstr(s,"SC1NEGESTC2S") && strlen(s)==12)					//Negatively-Charged-Sulfur; This condition was added on 19.10.2022
				f479=f479+1;
			//if(strncmp(s,"N",1)==0 && strstr(s,"NO2") && strstr(s,"NO1") && strlen(s)<=10)	//Nitro-group
			//	f479=f479+1;
			if(strncmp(s,"N",1)==0 && strstr(s,"6MR"))
			{
			   if(strstr(s,"NC4NC4NH1") || strstr(s,"NC4NH1NC4") || strstr(s,"NH1NC4NC4") || strstr(s,"NC4NC4NC1") || strstr(s,"NC4NC1NC4") || strstr(s,"NC4NC4NO1") || strstr(s,"NC4NO1NC4") ||
			      strstr(s,"NC4NC4NN1") || strstr(s,"NC4NN1NC4") || strstr(s,"NC4NC4NS1") || strstr(s,"NC4NS1NC4") || strstr(s,"NC1NC4NC4") || strstr(s,"NN1NC4NC4") || strstr(s,"NS1NC4NC4") || strstr(s,"NO1NC4NC4"))
				f480=f480+1;		//Pyridinium-N; 11.??????(!Q!X)@R6
			   if(strstr(s,"NN4") && strstr(s,"NC4") && (strstr(s,"NH1") || strstr(s,"NC1") || strstr(s,"NO1") && strstr(s,"NN1") || strstr(s,"NS1")))
				f480=f480+1;
			}

			if(strncmp(s,"HC1",3)==0 && strstr(s,"ARM"))		//Aromatic-CH; 30.D
				f481=f481+1;
			if(strncmp(s,"HC1",3)==0 && strstr(s,"ARM")==NULL)	//Aliphatic-CH; 30.E(!D)
                                f482=f482+1;
			if(strncmp(s,"HN1",3)==0 && strstr(s,"IMD"))		//Aromatic-NH; 30.I
                                f483=f483+1;
			if(strncmp(s,"HN1",3)==0 && strstr(s,"IMD")==NULL)	//Aliphatic-NH; 30.J(!I)
                                f484=f484+1;
			if(strncmp(s,"HO1",3)==0)				//-OH; 30.N
                                f485=f485+1;
			if(strncmp(s,"HS1",3)==0)				//-SH; 30.U
                                f486=f486+1;
			
			if(strstr(s,"4MR4MR4MR") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL) //Cubane; 32@R4_4_4
				f487=f487+1;
			if(strstr(s,"6MR6MR6MR") && strchr(s,'4')==NULL)					//Fused-6-6-6; 32(!??)@R6_6_6
                                f488=f488+1;
			//if(strstr(s,"6MR6MR6MR") && strchr(st1,'4') && strchr(st2,'4') && strchr(st3,'4')) //Fused-6-6-6-Aromatic; 33@R6_6_6
                        //        f489=f489+1;
			if(strstr(s,"6MR6MR") && strstr(s,"5MR") && strchr(s,'4')==NULL)		   //Fused-6-6-5; 32(!??)@R6_6_5
				f489=f489+1;
			if(strstr(s,"6MR5MR6MR") && strchr(s,'4')==NULL)				   //Fused-6-6-5; 32(!??)@R6_6_5
                                f489=f489+1;
			if(strstr(s,"5MR5MR") && strstr(s,"6MR") && strchr(s,'4')==NULL)		   //Fused-5-5-6; 32(!??)@R5_5_6
                                f490=f490+1;
			if(strstr(s,"5MR6MR5MR") && strchr(s,'4')==NULL)				   //Fused-5-5-6; 32(!??)@R5_5_6
                                f490=f490+1;
			if(strstr(s,"5MR") && strstr(s,"6MR") && strstr(s,"7MR") && strchr(s,'4')==NULL)   //Fused-5-6-7; 32(!??)@R5_6_7
				f491=f491+1;
			if(strstr(s,"6MR6MR") && strstr(s,"7MR") && strchr(s,'4')==NULL)		   //Fused-6-6-7; 32(!??)@R6_6_7
                                f492=f492+1;
                        if(strstr(s,"6MR7MR6MR") && strchr(s,'4')==NULL)				   //Fused-6-6-7; 32(!??)@R6_6_7
                                f492=f492+1;
			if(strstr(s,"5MR5MR") && strstr(s,"7MR") && strchr(s,'4')==NULL)		   //Fused-5-5-7; 32(!??)@R5_5_7
                                f493=f493+1;
                        if(strstr(s,"5MR7MR5MR") && strchr(s,'4')==NULL)				   //Fused-5-5-7; 32(!??)@R5_5_7
                                f493=f493+1;
			if(strstr(s,"5MR5MR5MR") && strchr(s,'4')==NULL)            			   //Fused-5-5-5; 32(!??)@R5_5_5
                                f494=f494+1;
			if(strstr(s,"6MR4MR") || strstr(s,"4MR6MR") || strstr(s,"6MR3MR") || strstr(s,"3MR6MR"))
			{
				if(strstr(s,"6MR4MR3")==NULL && strstr(s,"6MR4MR4")==NULL && strstr(s,"6MR4MR5")==NULL &&
				   strstr(s,"6MR4MR6")==NULL && strstr(s,"6MR4MR7")==NULL && strstr(s,"6MR4MR8")==NULL &&
				   strstr(s,"4MR6MR3")==NULL && strstr(s,"4MR6MR4")==NULL && strstr(s,"4MR6MR5")==NULL &&
				   strstr(s,"4MR6MR6")==NULL && strstr(s,"4MR6MR7")==NULL && strstr(s,"4MR6MR8")==NULL &&
				   strstr(s,"6MR3MR3")==NULL && strstr(s,"6MR3MR4")==NULL && strstr(s,"6MR3MR5")==NULL &&
				   strstr(s,"6MR3MR6")==NULL && strstr(s,"6MR3MR7")==NULL && strstr(s,"6MR3MR8")==NULL &&
				   strstr(s,"3MR6MR3")==NULL && strstr(s,"3MR6MR4")==NULL && strstr(s,"3MR6MR5")==NULL &&
				   strstr(s,"3MR6MR6")==NULL && strstr(s,"3MR6MR7")==NULL && strstr(s,"3MR6MR8")==NULL &&
				   strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL)
				f495=f495+1;								//Fused 6-3 or 6-4 rings; 32(!??)@R6_3/32(!??)@R6_4
			}
			if(strstr(s,"5MR3MR") || strstr(s,"3MR5MR") || strstr(s,"5MR4MR") || strstr(s,"4MR5MR"))
			{
				if(strstr(s,"5MR4MR3")==NULL && strstr(s,"5MR4MR4")==NULL && strstr(s,"5MR4MR5")==NULL &&
                                   strstr(s,"5MR4MR6")==NULL && strstr(s,"5MR4MR7")==NULL && strstr(s,"5MR4MR8")==NULL &&
                                   strstr(s,"4MR5MR3")==NULL && strstr(s,"4MR5MR4")==NULL && strstr(s,"4MR5MR5")==NULL &&
                                   strstr(s,"4MR5MR6")==NULL && strstr(s,"4MR5MR7")==NULL && strstr(s,"4MR5MR8")==NULL &&
                                   strstr(s,"5MR3MR3")==NULL && strstr(s,"5MR3MR4")==NULL && strstr(s,"5MR3MR5")==NULL &&
                                   strstr(s,"5MR3MR6")==NULL && strstr(s,"5MR3MR7")==NULL && strstr(s,"5MR3MR8")==NULL &&
                                   strstr(s,"3MR5MR3")==NULL && strstr(s,"3MR5MR4")==NULL && strstr(s,"3MR5MR5")==NULL &&
                                   strstr(s,"3MR5MR6")==NULL && strstr(s,"3MR5MR7")==NULL && strstr(s,"3MR5MR8")==NULL &&
				   strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL)
                                f496=f496+1;								//Fused 5-3 or 5-4 rings; 32(!??)@R5_3/32(!??)@R5_4
			}

			//if(strstr(s,"4MR4MR") && strstr(s,"5MR") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL)  //Fused-4-4-5; 32(!??)@R4_4_5
                        //        f496=f496+1;
                        //if(strstr(s,"4MR5MR4MR") && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL)                  //Fused-4-4-5; 32(!??)@R4_4_5
                        //        f496=f496+1;
			/*if(strncmp(s,"N",1)==0 && strchr(st1,'4')==NULL && strchr(st2,'4')==NULL && strchr(st3,'4')==NULL && strlen(s)>9)
			{
				b=strstr(s,"MR");
				if(b)
				{
					fill1(b);
					f496=f496+1;
					b=strstr(s,"MR");
					if(b)
					{
						fill1(b);
						f496=f496+1;
						b=strstr(s,"MR");
						if(b)
						{
							fill1(b);
							f496=f496+1;
						}
					}
				}
			}
			if(f496==3)
				count=count+1;*/

		line++;
	}
printf("f1 (Cyanide) = %d\n",fn1);
printf("f2 (Alcohol) = %d\n",fn2);
printf("f3 (Ether) = %d\n",fn3);
printf("f4 (Acid-Neutral(OH)) = %d\n",fn4);
printf("f5 (Anhydride-O(sp3)) = %d\n",fn5);
printf("f6 (Thiol) = %d\n",fn6);
printf("f7 (Thioacid(SH)) = %d\n",fn7);
printf("f8 (Thioether) = %d\n",fn8);
printf("f9 (PO2(O)(O)(O)) = %d\n",fn9);
printf("f10 (Aldehyde) = %d\n",f10);
printf("f11 (Thioaldehyde-in-ring) = %d\n",f11);
printf("f12 (Ketone) = %d\n",f12);
printf("f13 (PS2(O)(O)(O)) = %d\n",f13);
printf("f14 (Acid/Anhydride-C) = %d\n",f14);
printf("f15 (Thioformicacid) = %d\n",f15);
printf("f16 (Amide) = %d\n",f16);
printf("f17 (Thioformamide) = %d\n",f17);
printf("f18 (Acyl-chloride) = %d\n",f18);
printf("f19 (Thioacetyl-chloride) = %d\n",f19);
printf("f20 (Acetyl-bromide) = %d\n",f20);
printf("f21 (Thioacetyl-bromide) = %d\n",f21);
printf("f22 (Acetyl-fluoride) = %d\n",f22);
printf("f23 (Thioacetyl-fluoride) = %d\n",f23);
printf("f24 (Acetyl-iodide) = %d\n",f24);
printf("f25 (Thioacetyl-iodide) = %d\n",f25);
printf("f26 (Amine) = %d\n",f26);
printf("f27 (-F) = %d\n",f27);
printf("f28 (-Cl) = %d\n",f28);
printf("f29 (-Br) = %d\n",f29);
printf("f30 (-I) = %d\n",f30);
printf("f31 (-NO2); = %d\n",f31);
printf("f32 (PO2(N)(N)(N)) = %d\n",f32);
printf("f33 (PS2(N)(N)(N)) = %d\n",f33);
printf("f34 (PO2(O)(O)(C)/PO2(O)(C)(C)) = %d\n",f34);
printf("f35 (PS2(O)(O)(c)/PS2(O)(C)(c)) = %d\n",f35);
printf("f36 (PO2(O)(O)(N)/PO2(O)(N)(N)) = %d\n",f36);
printf("f37 (PS2(O)(O)(N)/PS2(O)(N)(N)) = %d\n",f37);
printf("f38 (PO2(O)(C)(N)) = %d\n",f38);
printf("f39 (PS2(O)(C)(N)) = %d\n",f39);
printf("f40 (PO2(C)(C)(N)/PO2(C)(N)(N)) = %d\n",f40);
printf("f41 (PS2(C)(C)(N)/PS2(C)(N)(N)) = %d\n",f41);
printf("f42 (PO2(C)(C)(C)) = %d\n",f42);
printf("f43 (PS2(C)(C)(C)) = %d\n",f43);
printf("f44 (PO2(S)()()) = %d\n",f44);
printf("f45 (SO2(=O)(O)(O)) = %d\n",f45);
printf("f46 (SO2(=O)(C)(O)) = %d\n",f46);
printf("f47 (SO2(=O)(N)(O)) = %d\n",f47);
printf("f48 (SO2(=O)(N)(C)) = %d\n",f48);
printf("f49 (SO2(=O)(C)(C)) = %d\n",f49);
printf("f50 (SO2(=O)(N)(N)) = %d\n",f50);
printf("f51 (Rest-of-the-tricoordinated-S-containing-compounds-which-do-not-contains-SO2-moiety) = %d\n",f51);
printf("f52 (-CH3) = %d\n",f52);
printf("f53 (-CH2) = %d\n",f53);
printf("f54 (-CH) = %d\n",f54);
printf("f55 (qMe) = %d\n",f55);
printf("f56 (Carbonate) = %d\n",f56);
printf("f57 (Cyanate) = %d\n",f57);
printf("f58 (Isocyanate) = %d\n",f58);
printf("f59 (Thioisocyanate) = %d\n",f59);
printf("f60 (-CF3); = %d\n",f60);
printf("f61 (-CCl3); = %d\n",f61);
printf("f62 (-CBr3); = %d\n",f62);
printf("f63 (-CF/-CF2); = %d\n",f63);
printf("f64 (-CCl/-CCl2); = %d\n",f64);
printf("f65 (-CBr/-CBr2); = %d\n",f65);
printf("f66 (-C-I) = %d\n",f66);
printf("f67 (Adize) = %d\n",f67);
printf("f68 (Sulfoxide) = %d\n",f68);
printf("f69 (-C=N-OH/-C=N-OC) = %d\n",f69);
printf("f70 (P-X-containing-molecule) = %d\n",f70);
printf("f71 (Nitroso) = %d\n",f71);
printf("f72 (Isocyanide) = %d\n",f72);
if(f73%2==0)
	printf("f73 (Peroxide) = %d\n",f73/2);
if(f73%2==1 && f73>0)
	printf("f73 (Peroxide) = %d\n",1+f73/2);
if(f74%2==0)
	printf("f74 (Disulfide) = %d\n",f74/2);
if(f74%2==1 && f74>0)
	printf("f74 (Disulfide) = %d\n",1+f74/2);
printf("f75 (Pentavalent-P) = %d\n",f75);
if(f76%2==0)
	printf("f76 (Hydrazine) = %d\n",f76/2);
if(f76%2==1 && f76>0)
	printf("f76 (Hydrazine) = %d\n",f76/2+1);
if(f77%2==0)
	printf("f77 (Diazene) = %d\n",f77/2);
if(f77%2==1 && f77>0)
	printf("f77 (Diazene) = %d\n",f77/2+1);
printf("f78 (Thioether-3-membered-ring) = %d\n",f78);
printf("f79 (Thioether-4-membered-ring) = %d\n",f79);
printf("f80 (N(sp3)-O) = %d\n",f80);
printf("f81 (N(sp3)-S) = %d\n",f81);
printf("f82 (N-N=O) = %d\n",f82);
printf("f83 (Aromatic-oxygen) = %d\n",f83);
printf("f84 (Aromatic-sulfur) = %d\n",f84);
printf("f85 (N(Aromatic)-6-member-ring) = %d\n",f85);
printf("f86 (Pyrrole-nitrogen) = %d\n",f86);
printf("f87 (Pyridazine-nitrogen) = %d\n",f87);
printf("f88 (Imidazole-nitrogen) = %d\n",f88);
printf("f89 (Triazole-nitrogen) = %d\n",f89);
printf("f90 (C=C-C=O-Rest) = %d\n",f90);
printf("f91 (C=C-C=C-Rest) = %d\n",f91);
printf("f92 (Phenylvinyl-Rest) = %d\n",f92);
printf("f93 (N=C-C=O-Rest) = %d\n",f93);
printf("f94 (N=C-C=C-Rest) = %d\n",f94);
printf("f95 (N=C-C=N-Rest) = %d\n",f95);
//printf("f96 (C=N-C=O) = %d\n",f96); //It should be //N=C-C=S
printf("f97 (C=C) = %d\n",f97);
if(f98%2==0)
	printf("f98 (C#C) = %d\n",f98/2);
if(f98%2==1 && f98>0)
	printf("f98 (C#C) = %d\n",1+f98/2);
printf("f99 (Benzene-C) = %d\n",f99);
printf("f100 (Anthracene-N) = %d\n",f100);
printf("f101 (Phenalene-C) = %d\n",f101);
printf("f102 (Oxadiazol) = %d\n",f102);
printf("f103 (Thiadiazole) = %d\n",f103);
printf("f104 (Thioether-5-membered-ring) = %d\n", f104);
printf("f105 (Diazetidin-2-one) = %d\n",f105);
printf("f106 (2-Imidazolide) = %d\n",f106);
printf("f107 ((H4)2(1H)-pyrimidinone) = %d\n",f107);
printf("f108 (C1CCNC(=O)NC1) = %d\n",f108);
printf("f109 (Urea) = %d\n",f109);
printf("f110 (C1NC(=O)O1) = %d\n",f110);
printf("f111 (C1(=O)OCCN1) = %d\n",f111);
printf("f112 (C1(=O)OCCCN1) = %d\n",f112);
printf("f113 (C1(=O)NCCCCO1) = %d\n",f113);
printf("f114 (Carbamic-group) = %d\n",f114);
printf("f115 (Lactam-3/4-membered) = %d\n",f115);
printf("f116 (Lactam-5-membered) = %d\n",f116);
printf("f117 (Lactam-6-membered) = %d\n",f117);
printf("f118 (Lactam-7-membered) = %d\n",f118);
printf("f119 (Anhydride-3/4-membered) = %d\n",f119);
printf("f120 (Anhydride-5-membered) = %d\n",f120);
printf("f121 (Anhydride-6-membered) = %d\n",f121);
printf("f122 (Anhydride-7-membered) = %d\n",f122);
printf("f123 (Ketone-3/4-membered) = %d\n",f123);
printf("f124 (Ketone-5-membered) = %d\n",f124);
printf("f125 (Ketone-6-membered) = %d\n",f125);
printf("f126 (Ketone-7-membered) = %d\n",f126);
printf("f127 (Enol-tautomer) = %d\n",f127);
printf("f128 (C(=O)N) = %d\n",f128);
//printf("f129 (Thiourea) = %d\n",f129);
printf("f130 (C=C-C=O-in-3/4-member-ring) = %d\n",f130);
printf("f131 (C=C-C=O-in-5-member-ring) = %d\n",f131);
printf("f132 (C=C-C=O(/=N/=S)-in-6-member-ring) = %d\n",f132);
printf("f133 (C=C-C=C-in-3/4-member-ring) = %d\n",f133);
printf("f134 (C=C-C=C-in-5-member-ring) = %d\n",f134);
printf("f135 (C=C-C=C-in-6-member-ring) = %d\n",f135);
printf("f136 (Phenylvinyl-3/4-member-ring) = %d\n",f136);
printf("f137 (Phenylvinyl-5-member-ring) = %d\n",f137);
printf("f138 (Phenylvinyl-6-member-ring) = %d\n",f138);
printf("f139 (N=C-C=O-5-member-ring) = %d\n",f139);
printf("f140 (N=C-C=O-6-member-ring) = %d\n",f140);
printf("f141 (N=C-C=C-5-member-ring) = %d\n",f141);
printf("f142 (N=C-C=C-6-member-ring) = %d\n",f142);
printf("f143 (N=C-C=N-5-member-ring) = %d\n",f143);
printf("f144 (N=C-C=N-6-member-ring) = %d\n",f144);
printf("f145 (N=C-C=S-5-member-ring) = %d\n",f145);
printf("f146 (N=C-C=S-6-member-ring) = %d\n",f146);
printf("f147 (N=C-C=S-rest) = %d\n",f147);
printf("f148 (N=C-Ph-5-member-ring) = %d\n",f148);
printf("f149 (N=C-Ph-6-member-ring) = %d\n",f149);
printf("f150 (N=C-Ph-rest) = %d\n",f150);
printf("f151 (Amine(NH)-Conjugation-One-Vinyl) = %d\n", f151);
printf("f152 (Amine(NH)-Conjugation-Two-Vinyl) = %d\n", f152);
printf("f153 (Amine(NH)-Conjugation-Amide-Vinyl) = %d\n", f153);
printf("f154 (Amine(NH)-Conjugation-Thioamide-Vinyl) = %d\n", f154);
printf("f155 (Amine(NH)-Conjugation-Imine-Vinyl) = %d\n", f155);
printf("f156 (Amine(NH)-Conjugation-Amide-Thioamide) = %d\n", f156);
printf("f157 (Amine(NH)-Conjugation-Amide-Imine) = %d\n", f157);
printf("f158 (Amine(NH)-Conjugation-Thioamide-Imine) = %d\n", f158);
printf("f159 (Amide(NH)) = %d\n",f159);
printf("f160 (Di-Amide(NH)) = %d\n",f160);
printf("f161 (Thioamide(NH)) = %d\n",f161);
printf("f162 (O-vinyl) = %d\n",f162);
printf("f163 (vinyl-O-vinyl) = %d\n",f163);
printf("f164 (Halogen-Olefinic) = %d\n",f164);
printf("f165 (O-Imine) = %d\n",f165);
printf("f166 (Imine-O-Imine) = %d\n",f166);
printf("f167 (N-oxide) = %d\n",f167);
printf("f168 (-NO3-group) = %d\n",f168);
printf("f169 (SO2-X-bond) = %d\n",f169);
printf("f170 (Amine-in-3-member-ring) = %d\n",f170);
printf("f171 (Amine-in-4-member-ring) = %d\n",f171);
printf("f172 (Epoxide-3-member-ring) = %d\n",f172);
printf("f173 (Epoxide-4-member-ring) = %d\n",f173);
printf("f174 (Thioether-6-member-ring) = %d\n",f174);
printf("f175 (Amine-5-member-ring) = %d\n",f175);
printf("f176 (CS2(N)(O)-3/4-member-ring) = %d\n",f176);
printf("f177 (CS2(N)(O)-5-member-ring) = %d\n",f177);
printf("f178 (CS2(N)(O)-6-member-ring) = %d\n",f178);
printf("f179 (CS2(N)(O)-7-member-ring) = %d\n",f179);
printf("f180 (Rest-of-the-CS2(N)(O)-groups) = %d\n",f180);
printf("f181 (CS2(O)(O)-3/4-member-ring) = %d\n",f181);
printf("f182 (CS2(O)(O)-5-member-ring) = %d\n",f182);
printf("f183 (CS2(O)(O)-6-member-ring) = %d\n",f183);
printf("f184 (CS2(O)(O)-7-member-ring) = %d\n",f184);
printf("f185 (Rest-of-the-CS2(O)(O)-groups) = %d\n",f185);
printf("f186 (CS2(N)(N)-3/4-member-ring) = %d\n",f186);
printf("f187 (CS2(N)(N)-5-member-ring) = %d\n",f187);
printf("f188 (CS2(N)(N)-6-member-ring) = %d\n",f188);
printf("f189 (CS2(N)(N)-7-member-ring) = %d\n",f189);
printf("f190 (Rest-of-the-CS2(N)(N)-groups) = %d\n",f190);
printf("f191 (CS2()(S)-3/4-member-ring) = %d\n",f191);
printf("f192 (CS2()(S)-5-member-ring) = %d\n",f192);
printf("f193 (CS2()(S)-6-member-ring) = %d\n",f193);
printf("f194 (CS2()(S)-7-member-ring) = %d\n",f194);
printf("f195 (Rest-ot-the-CS2()(S)-groups) = %d\n",f195);
printf("f196 (CS2(C)(N)-3/4-member-ring) = %d\n",f196);
printf("f197 (CS2(C)(N)-5-member-ring) = %d\n",f197);
printf("f198 (CS2(C)(N)-6-member-ring) = %d\n",f198);
printf("f199 (CS2(C)(N)-7-member-ring) = %d\n",f199);
printf("f200 (Rest-ot-the-CS2(C)(N)-groups) = %d\n",f200);
printf("f201 (CS2(C)(O)-3/4-member-ring) = %d\n",f201);
printf("f202 (CS2(C)(O)-5-member-ring) = %d\n",f202);
printf("f203 (CS2(C)(O)-6-member-ring) = %d\n",f203);
printf("f204 (CS2(C)(O)-7-member-ring) = %d\n",f204);
printf("f205 (Rest-ot-the-CS2(C)(O)-groups) = %d\n",f205);
printf("f206 (C(=O)(S)-3/4-membered) = %d\n",f206);
printf("f207 (C(=O)(S)-5-membered) = %d\n",f207);
printf("f208 (C(=O)(S)-6-membered) = %d\n",f208);
printf("f209 (C(=O)(S)-7-membered) = %d\n",f209);
printf("f210 (Rest-of-the-C(=O)(S)-groups) = %d\n",f210);
printf("f211 (CS2(C)(C)-3/4-member-ring) = %d\n",f211);
printf("f212 (CS2(C)(C)-5-member-ring) = %d\n",f212);
printf("f213 (CS2(C)(C)-6-member-ring) = %d\n",f213);
printf("f214 (CS2(C)(C)-7-member-ring) = %d\n",f214);
printf("f215 (Rest-ot-the-CS2(C)(C)-groups) = %d\n",f215);
printf("f216 (CN2(N)(O)-3/4-member-ring) = %d\n",f216);
printf("f217 (CN2(N)(O)-5-member-ring) = %d\n",f217);
printf("f218 (CN2(N)(O)-6-member-ring) = %d\n",f218);
printf("f219 (CN2(N)(O)-7-member-ring) = %d\n",f219);
printf("f220 (Rest-of-the-CN2(N)(O)-groups) = %d\n",f220);
printf("f221 (CN2(O)(O)-3/4-member-ring) = %d\n",f221);
printf("f222 (CN2(O)(O)-5-member-ring) = %d\n",f222);
printf("f223 (CN2(O)(O)-6-member-ring) = %d\n",f223);
printf("f224 (CN2(O)(O)-7-member-ring) = %d\n",f224);
printf("f225 (Rest-of-the-CN2(O)(O)-groups) = %d\n",f225);
printf("f226 (CN2(N)(N)-3/4-member-ring) = %d\n",f226);
printf("f227 (CN2(N)(N)-5-member-ring) = %d\n",f227);
printf("f228 (CN2(N)(N)-6-member-ring) = %d\n",f228);
printf("f229 (CN2(N)(N)-7-member-ring) = %d\n",f229);
printf("f230 (Rest-of-the-CN2(N)(N)-groups) = %d\n",f230);
printf("f231 (CN2(S)()-3/4-member-ring) = %d\n",f231);
printf("f232 (CN2(S)()-5-member-ring) = %d\n",f232);
printf("f233 (CN2(S)()-6-member-ring) = %d\n",f233);
printf("f234 (CN2(S)()-7-member-ring) = %d\n",f234);
printf("f235 (Rest-ot-the-CN2(S)()-groups) = %d\n",f235);
printf("f236 (CN2(C)(N)-3/4-member-ring) = %d\n",f236);
printf("f237 (CN2(C)(N)-5-member-ring) = %d\n",f237);
printf("f238 (CN2(C)(N)-6-member-ring) = %d\n",f238);
printf("f239 (CN2(C)(N)-7-member-ring) = %d\n",f239);
printf("f240 (Rest-ot-the-CN2(C)(N)-groups) = %d\n",f240);
printf("f241 (CN2(C)(O)-3/4-member-ring) = %d\n",f241);
printf("f242 (CN2(C)(O)-5-member-ring) = %d\n",f242);
printf("f243 (CN2(C)(O)-6-member-ring) = %d\n",f243);
printf("f244 (CN2(C)(O)-7-member-ring) = %d\n",f244);
printf("f245 (Rest-ot-the-CN2(C)(O)-groups) = %d\n",f245);
printf("f246 (CN2(C)(C)-3/4-member-ring) = %d\n",f246);
printf("f247 (CN2(C)(C)-5-member-ring) = %d\n",f247);
printf("f248 (CN2(C)(C)-6-member-ring) = %d\n",f248);
printf("f249 (CN2(C)(C)-7-member-ring) = %d\n",f249);
printf("f250 (Rest-ot-the-CN2(C)(C)-groups) = %d\n",f250);
printf("f251 (C(=N)(H)()) = %d\n",f251);
printf("f252 (C(=S)-C=S-5-member-ring) = %d\n",f252);
printf("f253 (C(=S)-C=S-6-member-ring) = %d\n",f253);
printf("f254 (CC2(N)(O)-3/4-member-ring) = %d\n",f254);
printf("f255 (CC2(N)(O)-5-member-ring) = %d\n",f255);
printf("f256 (CCC2(N)(O)-6-member-ring) = %d\n",f256);
printf("f257 (CC2(N)(O)-7-member-ring) = %d\n",f257);
printf("f258 (Rest-of-the-CC2(N)(O)-groups) = %d\n",f258);
printf("f259 (CC2(O)(O)-3/4-member-ring) = %d\n",f259);
printf("f260 (CC2(O)(O)-5-member-ring) = %d\n",f260);
printf("f261 (CC2(O)(O)-6-member-ring) = %d\n",f261);
printf("f262 (CC2(O)(O)-7-member-ring) = %d\n",f262);
printf("f263 (Rest-of-the-CC2(O)(O)-groups) = %d\n",f263);
printf("f264 (CC2(N)(N)-3/4-member-ring) = %d\n",f264);
printf("f265 (CC2(N)(N)-5-member-ring) = %d\n",f265);
printf("f266 (CC2(N)(N)-6-member-ring) = %d\n",f266);
printf("f267 (CC2(N)(N)-7-member-ring) = %d\n",f267);
printf("f268 (Rest-of-the-CC2(N)(N)-groups) = %d\n",f268);
printf("f269 (CC2(S)()-3/4-member-ring) = %d\n",f269);
printf("f270 (CC2(S)()-5-member-ring) = %d\n",f270);
printf("f271 (CC2(S)()-6-member-ring) = %d\n",f271);
printf("f272 (CC2(S)()-7-member-ring) = %d\n",f272);
printf("f273 (Rest-ot-the-CC2(S)()-groups) = %d\n",f273);
printf("f274 (CC2(C)(N)-3/4-member-ring) = %d\n",f274);
printf("f275 (CC2(C)(N)-5-member-ring) = %d\n",f275);
printf("f276 (CC2(C)(N)-6-member-ring) = %d\n",f276);
printf("f277 (CC2(C)(N)-7-member-ring) = %d\n",f277);
printf("f278 (Rest-ot-the-CC2(C)(N)-groups) = %d\n",f278);
printf("f279 (CC2(C)(O)-3/4-member-ring) = %d\n",f279);
printf("f280 (CC2(C)(O)-5-member-ring) = %d\n",f280);
printf("f281 (CC2(C)(O)-6-member-ring) = %d\n",f281);
printf("f282 (CC2(C)(O)-7-member-ring) = %d\n",f282);
printf("f283 (Rest-ot-the-CC2(C)(O)-groups) = %d\n",f283);
printf("f284 (CC2(C)(H)-3/4-member-ring) = %d\n",f284);
printf("f285 (CC2(C)(H)-5-member-ring) = %d\n",f285);
printf("f286 (CC2(C)(H)-6-member-ring) = %d\n",f286);
printf("f287 (CC2(C)(H)-7-member-ring) = %d\n",f287);
printf("f288 (CC2(C)(C)-3/4-member-ring) = %d\n",f288);
printf("f289 (CC2(C)(C)-5-member-ring) = %d\n",f289);
printf("f290 (CC2(C)(C)-6-member-ring) = %d\n",f290);
printf("f291 (CC2(C)(C)-7-member-ring) = %d\n",f291);
printf("f292 (Amide(NH)-3/4-member-ring) = %d\n",f292);
printf("f293 (Amide(NH)-5-member-ring) = %d\n",f293);
printf("f294 (Amide(NH)-6-member-ring) = %d\n",f294);
printf("f295 (Amide(NH)-7-member-ring) = %d\n",f295);
printf("f296 (Di-Amide(NH)-3/4-member-ring) = %d\n",f296);
printf("f297 (Di-Amide(NH)-5-member-ring) = %d\n",f297);
printf("f298 (Di-Amide(NH)-6-member-ring) = %d\n",f298);
printf("f299 (Di-Amide(NH)-7-member-ring) = %d\n",f299);
printf("f300 (Thioamide(NH)-3/4-member-ring) = %d\n",f300);
printf("f301 (Thioamide(NH)-5-member-ring) = %d\n",f301);
printf("f302 (Thioamide(NH)-6-member-ring) = %d\n",f302);
printf("f303 (Thioamide(NH)-7-member-ring) = %d\n",f303);
printf("f304 (Di-thioamide(NH)-3/4-member-ring) = %d\n",f304);
printf("f305 (Di-Thioamide(NH)-5-member-ring) = %d\n",f305);
printf("f306 (Di-Thioamide(NH)-6-member-ring) = %d\n",f306);
printf("f307 (Di-Thioamide(NH)-7-member-ring) = %d\n",f307);
printf("f308 (Amidine(NH)-3/4-member-ring) = %d\n",f308);
printf("f309 (Amidine(NH)-5-member-ring) = %d\n",f309);
printf("f310 (Amidine(NH)-6-member-ring) = %d\n",f310);
printf("f311 (Amidine(NH)-7-member-ring) = %d\n",f311);
printf("f312 (Di-amidine(NH)-3/4-member-ring) = %d\n",f312);
printf("f313 (Di-amidine(NH)-5-member-ring) = %d\n",f313);
printf("f314 (Di-amidine(NH)-6-member-ring) = %d\n",f314);
printf("f315 (Di-amidine(NH)-7-member-ring) = %d\n",f315);
printf("f316 (Amide(N)-3/4-member-ring) = %d\n",f316);
printf("f317 (Amide(N)-5-member-ring) = %d\n",f317);
printf("f318 (Amide(N)-6-member-ring) = %d\n",f318);
printf("f319 (Amide(N)-7-member-ring) = %d\n",f319);
printf("f320 (Di-Amide(N)-3/4-member-ring) = %d\n",f320);
printf("f321 (Di-Amide(N)-5-member-ring) = %d\n",f321);
printf("f322 (Di-Amide(N)-6-member-ring) = %d\n",f322);
printf("f323 (Di-Amide(N)-7-member-ring) = %d\n",f323);
printf("f324 (Thioamide(N)-3/4-member-ring) = %d\n",f324);
printf("f325 (Thioamide(N)-5-member-ring) = %d\n",f325);
printf("f326 (Thioamide(N)-6-member-ring) = %d\n",f326);
printf("f327 (Thioamide(N)-7-member-ring) = %d\n",f327);
printf("f328 (Di-thioamide(N)-3/4-member-ring) = %d\n",f328);
printf("f329 (Di-Thioamide(N)-5-member-ring) = %d\n",f329);
printf("f330 (Di-Thioamide(N)-6-member-ring) = %d\n",f330);
printf("f331 (Di-Thioamide(N)-7-member-ring) = %d\n",f331);
printf("f332 (Amidine(N)-3/4-member-ring) = %d\n",f332);
printf("f333 (Amidine(N)-5-member-ring) = %d\n",f333);
printf("f334 (Amidine(N)-6-member-ring) = %d\n",f334);
printf("f335 (Amidine(N)-7-member-ring) = %d\n",f335);
printf("f336 (Di-Amidine(N)-3/4-member-ring) = %d\n",f336);
printf("f337 (Di-Amidine(N)-5-member-ring) = %d\n",f337);
printf("f338 (Di-Amidine(N)-6-member-ring) = %d\n",f338);
printf("f339 (Di-Amidine(N)-7-member-ring) = %d\n",f339);
printf("f340 (Di-Thioamide(NH)) = %d\n",f340);
printf("f341 (Amidine(NH)) = %d\n",f341);
printf("f342 (Di-Amidine(NH)) = %d\n",f342);
printf("f343 (Amide) = %d\n",f343);
printf("f344 (Di-Amide) = %d\n",f344);
printf("f345 (Thioamide) = %d\n",f345);
printf("f346 (Di-Thioamide) = %d\n",f346);
printf("f347 (Amidine) = %d\n",f347);
printf("f348 (Di-Amidine) = %d\n",f348);
printf("f349 (O=C-O-C=O) = %d\n",f349);
printf("f350 (S=C-O-C=S) = %d\n",f350);
printf("f351 (O=C-O-C=N) = %d\n",f351);
printf("f352 (C(=S)-C=S-Rest) = %d\n",f352);
printf("f353 (C(=S)-Ph-5-member-ring) = %d\n",f353);
printf("f354 (C(=S)-Ph-6-member-ring) = %d\n",f354);
printf("f355 (C(=S)-Ph-Rest) = %d\n",f355);
printf("f356 (C(=N)-C=O-5-member-ring) = %d\n",f356);
printf("f357 (C(=N)-C=O-6-member-ring) = %d\n",f357);
printf("f358 (C(=N)-C=O-Rest) = %d\n",f358);
printf("f359 (C(=N)-C=N-5-member-ring) = %d\n",f359);
printf("f360 (C(=N)-C=N-6-member-ring) = %d\n",f360);
printf("f361 (C(=N)-C=N-Rest) = %d\n",f361);
printf("f362 (C(=N)-C=S-5-member-ring) = %d\n",f362);
printf("f363 (C(=N)-C=S-6-member-ring) = %d\n",f363);
printf("f364 (C(=N)-C=S-Rest) = %d\n",f364);
printf("f365 (C(=N)-Ph-5-member-ring) = %d\n",f365);
printf("f366 (C(=N)-Ph-6-member-ring) = %d\n",f366);
printf("f367 (C(=N)-Ph-Rest) = %d\n",f367);
printf("f368 (C(=O)-C=O-5-member-ring) = %d\n",f368);
printf("f369 (C(=O)-C=O-6-member-ring) = %d\n",f369);
printf("f370 (C(=O)-C=O-Rest) = %d\n",f370);
printf("f371 (C(=O)-C=S-5-member-ring) = %d\n",f371);
printf("f372 (C(=O)-C=S-6-member-ring) = %d\n",f372);
printf("f373 (C(=O)-C=S-Rest) = %d\n",f373);
printf("f374 (C(=O)-Ph-5-member-ring) = %d\n",f374);
printf("f375 (C(=O)-Ph-6-member-ring) = %d\n",f375);
printf("f376 (C(=O)-Ph-Rest) = %d\n",f376);
printf("f377 (N=C-C=O-3/4-member-ring) = %d\n",f377);
printf("f378 (N=C-C=C-3/4-member-ring) = %d\n",f378);
printf("f379 (N=C-C=N-3/4-member-ring) = %d\n",f379);
printf("f380 (N=C-C=S-3/4-member-ring) = %d\n",f380);
printf("f381 (N=C-Ph-3/4-member-ring) = %d\n",f381);
printf("f382 (C(=S)-C=S-3/4-member-ring) = %d\n",f382);
printf("f383 (C(=S)-Ph-3/4-member-ring) = %d\n",f383);
printf("f384 (C(=N)-C=O-3/4-member-ring) = %d\n",f384);
printf("f385 (C(=N)-C=N-3/4-member-ring) = %d\n",f385);
printf("f386 (C(=N)-C=S-3/4-member-ring) = %d\n",f386);
printf("f387 (C(=N)-Ph-3/4-member-ring) = %d\n",f387);
printf("f388 (C(=O)-C=O-3/4-member-ring) = %d\n",f388);
printf("f389 (C(=O)-C=S-3/4-member-ring) = %d\n",f389);
printf("f390 (C(=O)-Ph-3/4-member-ring) = %d\n",f390);
printf("f391 (Epoxide-5-member-ring) = %d\n",f391);
printf("f392 (Epoxide-6-member-ring) = %d\n",f392);
printf("f393 (Ester-O-3-member-ring) = %d\n",f393);
printf("f394 (Ester-O-4-member-ring) = %d\n",f394);
printf("f395 (Ester-O-5-member-ring) = %d\n",f395);
printf("f396 (Ester-O-6-member-ring) = %d\n",f396);
printf("f397 (Di-Ester-O-3-member-ring) = %d\n",f397);
printf("f398 (Di-Ester-O-4-member-ring) = %d\n",f398);
printf("f399 (Di-Ester-O-5-member-ring) = %d\n",f399);
printf("f400 (Di-Ester-O-6-member-ring) = %d\n",f400);
printf("f401 ((C=N)Ester-O-3-member-ring) = %d\n",f401);
printf("f402 ((C=N)Ester-O-4-member-ring) = %d\n",f402);
printf("f403 ((C=N)Ester-O-5-member-ring) = %d\n",f403);
printf("f404 ((C=N)Ester-O-6-member-ring) = %d\n",f404);
printf("f405 ((C=N)2Ester-O-3-member-ring) = %d\n",f405);
printf("f406 ((C=N)2Ester-O-4-member-ring) = %d\n",f406);
printf("f407 ((C=N)2Ester-O-5-member-ring) = %d\n",f407);
printf("f408 ((C=N)2Ester-O-6-member-ring) = %d\n",f408);
printf("f409 (Amine-6-member-ring) = %d\n",f409);
printf("f410 (S=C-O-C) = %d\n", f410);
printf("f411 (N-Pyrrolo[1,2-c]triazine) = %d\n", f411);
printf("f412 (Indolizine-N) = %d\n", f412);
printf("f413 (1,2,3-Triazine-Nitrogen) = %d\n", f413);
printf("f414 (Tetrazole-Nitrogen) = %d\n", f414);
printf("f415 (Aromatic-Bridge-C) = %d\n", f415);
printf("f416 (Amine(NH)-Conjugation-One-Vinyl-3/4-member-ring) = %d\n",f416);
printf("f417 (Amine(NH)-Conjugation-One-Vinyl-5-member-ring) = %d\n",f417);
printf("f418 (Amine(NH)-Conjugation-One-Vinyl-6-member-ring) = %d\n",f418);
printf("f419 (Amine(NH)-Conjugation-One-Vinyl-7-member-ring) = %d\n",f419);
printf("f420 (Amine(NH)-Conjugation-Two-Vinyl-3/4-member-ring) = %d\n",f420);
printf("f421 (Amine(NH)-Conjugation-Two-Vinyl-5-member-ring) = %d\n",f421);
printf("f422 (Amine(NH)-Conjugation-Two-Vinyl-6-member-ring) = %d\n",f422);
printf("f423 (Amine(NH)-Conjugation-Two-Vinyl-7-member-ring) = %d\n",f423);
printf("f424 (Amine(N)-Conjugation-One-Vinyl-3/4-member-ring) = %d\n",f424);
printf("f425 (Amine(N)-Conjugation-One-Vinyl-5-member-ring) = %d\n",f425);
printf("f426 (Amine(N)-Conjugation-One-Vinyl-6-member-ring) = %d\n",f426);
printf("f427 (Amine(N)-Conjugation-One-Vinyl-7-member-ring) = %d\n",f427);
printf("f428 (Amine(N)-Conjugation-Two-Vinyl-3/4-member-ring) = %d\n",f428);
printf("f429 (Amine(N)-Conjugation-Two-Vinyl-5-member-ring) = %d\n",f429);
printf("f430 (Amine(N)-Conjugation-Two-Vinyl-6-member-ring) = %d\n",f430);
printf("f431 (Amine(N)-Conjugation-Two-Vinyl-7-member-ring) = %d\n",f431);
printf("f432 (Amine-Conjugation-One-Vinyl) = %d\n",f432);
printf("f433 (Amine-Conjugation-Two-Vinyl) = %d\n",f433);
printf("f434 (Amine-Conjugation-Amide-Vinyl) = %d\n",f434);
printf("f435 (Amine-Conjugation-Thioamide-Vinyl) = %d\n",f435);
printf("f436 (Amine-Conjugation-Imine-Vinyl) = %d\n",f436);
printf("f437 (Amine-Conjugation-Amide-Thioamide) = %d\n",f437);
printf("f438 (Amine-Conjugation-Amide-Imine) = %d\n",f438);
printf("f439 (Amine-Conjugation-Thioamide-Imine) = %d\n",f439);
printf("f440 (-O-C=C-in-3-member-ring) = %d\n",f440);
printf("f441 (-O-C=C-in-4-member-ring) = %d\n",f441);
printf("f442 (-O-C=C-in-5-member-ring) = %d\n",f442);
printf("f443 (-O-C=C-in-6-member-ring) = %d\n",f443);
printf("f444 (C=C-O-C=C-in-3-member-ring) = %d\n",f444);
printf("f445 (C=C-O-C=C-in-4-member-ring) = %d\n",f445);
printf("f446 (C=C-O-C=C-in-5-member-ring) = %d\n",f446);
printf("f447 (C=C-O-C=C-in-6-member-ring) = %d\n",f447);
if(f448%2==0)
	printf("f448 (Peracid)) = %d\n",f448/2);
if(f448%2==1 && f448>1)
	printf("f448 (Peracid)) = %d\n",f448/2+1);
printf("f449 (PS2(S)()()) = %d\n",f449);
printf("f450 ((Ar)N-N=C-5-member-ring) = %d\n",f450);
printf("f451 ((Ar)N-N=C-6-member-ring) = %d\n",f451);
printf("f452 ((Ar)N-N=C-3/4-member-ring) = %d\n",f452);
printf("f453 ((Ar)N-N=C-rest) = %d\n",f453);
printf("f454 (Aromatic-N-C(=O)N) = %d\n",f454);
printf("f455 (Aromatic-N-C(=O)O) = %d\n",f455);
printf("f456 (Aromatic-N-C(=O)S) = %d\n",f456);
printf("f457 (Aromatic-N-C(=O)C) = %d\n",f457);
printf("f458 (Aromatic-N-C(=O)H) = %d\n",f458);
printf("f459 (Aromatic-N-C(=N)N) = %d\n",f459);
printf("f460 (Aromatic-N-C(=N)O) = %d\n",f460);
printf("f461 (Aromatic-N-C(=N)S) = %d\n",f461);
printf("f462 (Aromatic-N-C(=N)C) = %d\n",f462);
printf("f463 (Aromatic-N-C(=N)H) = %d\n",f463);
printf("f464 (Aromatic-N-C(=C)N) = %d\n",f464);
printf("f465 (Aromatic-N-C(=C)O) = %d\n",f465);
printf("f466 (Aromatic-N-C(=C)S) = %d\n",f466);
printf("f467 (Aromatic-N-C(=C)C) = %d\n",f467);
printf("f468 (Aromatic-N-C(=C)H) = %d\n",f468);
printf("f469 (Aromatic-N-C(=S)N) = %d\n",f469);
printf("f470 (Aromatic-N-C(=S)O) = %d\n",f470);
printf("f471 (Aromatic-N-C(=S)S) = %d\n",f471);
printf("f472 (Aromatic-N-C(=S)C) = %d\n",f472);
printf("f473 (Aromatic-N-C(=S)H) = %d\n",f473);
printf("f474 (Aromatic-N-C(=E)-group) = %d\n",f474);
printf("f475 (Sulfoxide) = %d\n",f475);
printf("f476 (S(sp3)-O/N) = %d\n",f476);
printf("f477 (Positively-Charged-(sp3)N) = %d\n",f477);
printf("f478 (Anionic-Oxygen) = %d\n",f478);
printf("f479 (Negatively-Charged-N/S) = %d\n",f479);
printf("f480 (Pyridinium-N) = %d\n",f480);
printf("f481 (Aromatic-CH) = %d\n",f481);
printf("f482 (Aliphatic-CH) = %d\n",f482);
printf("f483 (Aromatic-NH) = %d\n",f483);
printf("f484 (Aliphatic-NH) = %d\n",f484);
printf("f485 (-OH) = %d\n",f485);
printf("f486 (-SH) = %d\n",f486);
printf("f487 (Cubane) = %d\n",f487/8);
printf("f488 (Fused-6-6-6) = %d\n",f488);
printf("f489 (Fused-6-6-5) = %d\n",f489);
printf("f490 (Fused-5-5-6) = %d\n",f490);
printf("f491 (Fused-5-6-7) = %d\n",f491);
printf("f492 (Fused-6-6-7) = %d\n",f492);
printf("f493 (Fused-5-5-7) = %d\n",f493);
printf("f494 (Fused-5-5-5) = %d\n",f494);
printf("f495 (Fused-6-3/4) = %d\n",f495);
printf("f496 (Fused-5-3/4) = %d\n",f496);

printf("f497 (Amide(N)-fused-3/4-member-ring) = %d\n",f497);
printf("f498 (Amide(N)-fused-5/6/7-member-ring) = %d\n",f498);
printf("f499 (Diamide(N)-fused-3/4-member-ring) = %d\n",f499);
printf("f500 (Diamide(N)-fused-5/6/7-member-ring) = %d\n",f500);
printf("f501 (Thioamide(N)-fused-3/4-member-ring) = %d\n",f501);
printf("f502 (Thioamide(N)-fused-5/6/7-member-ring) = %d\n",f502);
printf("f503 (Dithioamide(N)-fused-3/4-member-ring) = %d\n",f503);
printf("f504 (Dithioamide(N)-fused-5/6/7-member-ring) = %d\n",f504);
printf("f505 (Amidine(N)-fused-3/4-member-ring) = %d\n",f505);
printf("f506 (Amidine(N)-fused-5/6/7-member-ring) = %d\n",f506);
printf("f507 (Urea(N)-fused-3/4-member-ring) = %d\n",f507);
printf("f508 (Urea(N)-fused-5/6/7-member-ring) = %d\n",f508);
printf("f509 (VinylAmine(N)-fused-3/4-member-ring) = %d\n",f509);
printf("f510 (VinylAmine(N)-fused-5/6/7-member-ring) = %d\n",f510);
printf("f511 (Di-vinylAmine(N)-fused-3/4-member-ring) = %d\n",f511);
printf("f512 (Di-vinylAmine(N)-fused-5/6/7-member-ring) = %d\n",f512);

fclose(fr);
}

//Added on 16 December 2021
void fill(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='p';
        for(i=1;i<2;i++)
        *(a+i)='p';
        for(i=2;i<3;i++)
        *(a+i)='p';
      }
void fill1(char *a)
      {
        int i=0;
        for(i=0;i<1;i++)
        *(a+i)='p';
	for(i=1;i<2;i++)
	*(a+i)='p';
      }

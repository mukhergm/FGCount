#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc, char *argv[])
{
        FILE *fr;
        int sum=0;
	float mw=0, logp=0, mr=0, wi=0;
        char str[100];
        fr=fopen(argv[1],"r");
        while(fgets(str,100,fr)!=NULL)
        {
		sscanf(str,"%f %f %f %f", &mw, &logp, &mr, &wi);
		if(mw>0 && mr>0)
		sum=sum+1;
	}
	printf("%d\n", sum);
	fclose(fr);
}

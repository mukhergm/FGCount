/*
 * This is a part of RASPD+ code (https://github.com/HITS-MCM/RASPDplus)
 * Written by Goutam Mukherjee
 * Purpose: This program will arrange the atoms present in pdb file. It first print carbon atoms corresponding line from a pdb file then, nitrogen, oxygen and followed S, P, halogens and H atoms. 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
FILE *fp,*fw;
if (argc<2) {
  printf("./pdbarrange.exe <Input file> <Output file>\n");
  exit(1);
}
float a,b,c;
float sum=0,sum1=0.0,sum2=0.0,sum3=0.0,dist,s1,s2,s3,d1,d2,d3,dipole_moment;
char s[100],sc[1000][100],sn[1000][100],so[1000][100],ss[1000][100],sp[1000][100],sf[1000][100],scl[1000][100],sb[1000][100],sh[1000][100],si[1000][100],st[1000][100], sg[1000][100];
char sm[1000][100], sa[1000][100], sz[1000][100], sr[1000][100], sw[1000][100], sk[1000][100];
char strings[10];
//char atom[10],atom1[10];
float x1,y1,z1,x2,y2,z2,mx=0,my=0,mz=0;
float m;
int cc=0,nn=0,oo=0,su=0,pp=0,ff=0,clcl=0,br=0,ii=0,hh=0;
int tt=0, gg=0, mm=0, aa=0, zz=0, rr=0, ww=0, kk=0;
int xx=0,ac[1000],an[1000],ao[1000],as[1000],ap[1000],af[1000],acl[1000],ab[1000],ai[1000],ah[1000];
int at[1000], ag[1000], am[1000], aaa[1000], az[1000], ar[1000], aw[1000], ak[1000];
char atom[10],t[6],d[6],ATM[6]="ATOM";
char c1[10],c2[10],c3[10];
int atomno,r;
float x,y,z,h,e,g;
char atomsymbol;
fp=fopen(argv[1],"r");
fw=fopen(argv[2],"w");

	if (fw==NULL)
        {
        printf("pdbarrange.exe: Cannot write output. No output file name is given\n");
        exit(1);
        }

int l=1;
while(fgets(s,100,fp)!=NULL)

{
int len=strlen(s);
sscanf(s,"%s%d%s%s%d%f%f%f%f%f%f",atom,&atomno,t,d,&r,&x2,&y2,&z2,&h,&e,&g);
//sscanf(s,"%s%d%s",atom,&atomno,t);
if(t[0]!=1 && t[0]!=2 && t[0]!=3 && t[0]!=4 && t[0]!=5 && t[0]!=6 && t[0]!=7 && t[0]!=8 && t[0]!=9 && t[0]!=0)
{
if(t[0]=='C'&& t[1]!='l' && t[1]!='L')
{
cc=cc+1;
ac[cc]=l;
strncpy(sc[cc],s,len-1);
}
else if (t[0]=='N')
{
nn=nn+1;
an[nn]=l;
strncpy(sn[nn],s,len-1);
}
else if (t[0]=='O')
{
oo=oo+1;
ao[oo]=l;
strncpy(so[oo],s,len-1);
}
else if (t[0]=='S')
{
su=su+1;
as[su]=l;
strncpy(ss[su],s,len-1);
}
else if (t[0]=='H')
{
hh=hh+1;
ah[hh]=l;
strncpy(sh[hh],s,len-1);
}
if(t[0]=='C'&&t[1]=='l')
{
clcl=clcl+1;
acl[clcl]=l;
strncpy(scl[clcl],s,len-1);
}
if(t[0]=='C'&&t[1]=='L')
{
clcl=clcl+1;
acl[clcl]=l;
strncpy(scl[clcl],s,len-1);
}
else if (t[0]=='P')
{
pp=pp+1;
ap[pp]=l;
strncpy(sp[pp],s,len-1);
}
else if (t[0]=='F')
{
ff=ff+1;
af[ff]=l;
strncpy(sf[ff],s,len-1);
}
else if (t[0]=='B')
{
br=br+1;
ab[br]=l;
strncpy(sb[br],s,len-1);
}
//Newly added start
else if (t[0]=='T')
{
tt=tt+1;
at[tt]=l;
strncpy(st[tt],s,len-1);
}

else if (t[0]=='K')
{
kk=kk+1;
ak[kk]=l;
strncpy(sk[kk],s,len-1);
}

else if (t[0]=='G')
{
gg=gg+1;
ag[gg]=l;
strncpy(sg[gg],s,len-1);
}

else if (t[0]=='M')
{
mm=mm+1;
am[mm]=l;
strncpy(sm[mm],s,len-1);
}

else if (t[0]=='A')
{
aa=aa+1;
aaa[aa]=l;
strncpy(sa[aa],s,len-1);
}

else if (t[0]=='Z')
{
zz=zz+1;
az[zz]=l;
strncpy(sz[zz],s,len-1);
}

else if (t[0]=='R')
{
rr=rr+1;
ar[rr]=l;
strncpy(sr[rr],s,len-1);
}

else if (t[0]=='W')
{
ww=ww+1;
aw[ww]=l;
strncpy(sw[ww],s,len-1);
}
//Newly added end
else if (t[0]=='I')
{
ii=ii+1;
ai[ii]=l;
strncpy(si[ii],s,len-1);
}
l++;
}

if(t[0]==1 || t[0]==2 || t[0]==3 || t[0]==4 || t[0]==5 || t[0]==6 || t[0]==7 || t[0]==8 || t[0]==9 || t[0]==0)
{
if(t[1]=='C'&& t[2]!='l' && t[2]!='L')
{
cc=cc+1;
ac[cc]=l;
strncpy(sc[cc],s,len-1);
}
else if (t[1]=='N')
{
nn=nn+1;
an[nn]=l;
strncpy(sn[nn],s,len-1);
}
else if (t[1]=='O')
{
oo=oo+1;
ao[oo]=l;
strncpy(so[oo],s,len-1);
}
else if (t[1]=='S')
{
su=su+1;
as[su]=l;
strncpy(ss[su],s,len-1);
}
else if (t[1]=='H')
{
hh=hh+1;
ah[hh]=l;
strncpy(sh[hh],s,len-1);
}
if(t[1]=='C'&&t[2]=='l')
{
clcl=clcl+1;
acl[clcl]=l;
strncpy(scl[clcl],s,len-1);
}
if(t[1]=='C'&&t[2]=='L')
{
clcl=clcl+1;
acl[clcl]=l;
strncpy(scl[clcl],s,len-1);
}
else if (t[1]=='P')
{
pp=pp+1;
ap[pp]=l;
strncpy(sp[pp],s,len-1);
}
else if (t[1]=='F')
{
ff=ff+1;
af[ff]=l;
strncpy(sf[ff],s,len-1);
}
else if (t[1]=='B')
{
br=br+1;
ab[br]=l;
strncpy(sb[br],s,len-1);
}
//Newly added start
else if (t[1]=='T')
{
tt=tt+1;
at[tt]=l;
strncpy(st[tt],s,len-1);
}

else if (t[1]=='K')
{
kk=kk+1;
ak[kk]=l;
strncpy(sk[kk],s,len-1);
}

else if (t[1]=='G')
{
gg=gg+1;
ag[gg]=l;
strncpy(sg[gg],s,len-1);
}

else if (t[1]=='M')
{
mm=mm+1;
am[mm]=l;
strncpy(sm[mm],s,len-1);
}

else if (t[1]=='A')
{
aa=aa+1;
aaa[aa]=l;
strncpy(sa[aa],s,len-1);
}

else if (t[1]=='Z')
{
zz=zz+1;
az[zz]=l;
strncpy(sz[zz],s,len-1);
}

else if (t[1]=='R')
{
rr=rr+1;
ar[rr]=l;
strncpy(sr[rr],s,len-1);
}

else if (t[1]=='W')
{
ww=ww+1;
aw[ww]=l;
strncpy(sw[ww],s,len-1);
}
//Newly added end

else if (t[1]=='I')
{
ii=ii+1;
ai[ii]=l;
strncpy(si[ii],s,len-1);
}
l++;
}
}
for(xx=1;xx<=cc;xx++)
{
printf("%s\n",sc[xx]);
fprintf(fw,"%d\n",ac[xx]);
}
for(xx=1;xx<=nn;xx++)
{
printf("%s\n",sn[xx]);
fprintf(fw,"%d\n",an[xx]);
}
for(xx=1;xx<=oo;xx++)
{
printf("%s\n",so[xx]);
fprintf(fw,"%d\n",ao[xx]);
}
for(xx=1;xx<=su;xx++)
{
printf("%s\n",ss[xx]);
fprintf(fw,"%d\n",as[xx]);
}
for(xx=1;xx<=pp;xx++)
{
printf("%s\n",sp[xx]);
fprintf(fw,"%d\n",ap[xx]);
}
for(xx=1;xx<=ff;xx++)
{
printf("%s\n",sf[xx]);
fprintf(fw,"%d\n",af[xx]);
}
for(xx=1;xx<=clcl;xx++)
{
printf("%s\n",scl[xx]);
fprintf(fw,"%d\n",acl[xx]);
}
for(xx=1;xx<=br;xx++)
{
printf("%s\n",sb[xx]);
fprintf(fw,"%d\n",ab[xx]);
}
for(xx=1;xx<=ii;xx++)
{
printf("%s\n",si[xx]);
fprintf(fw,"%d\n",ai[xx]);
}
//Newly added start
for(xx=1;xx<=tt;xx++)
{
printf("%s\n",st[xx]);
fprintf(fw,"%d\n",at[xx]);
}
for(xx=1;xx<=gg;xx++)
{
printf("%s\n",sg[xx]);
fprintf(fw,"%d\n",ag[xx]);
}
for(xx=1;xx<=mm;xx++)
{
printf("%s\n",sm[xx]);
fprintf(fw,"%d\n",am[xx]);
}
for(xx=1;xx<=aa;xx++)
{
printf("%s\n",sa[xx]);
fprintf(fw,"%d\n",aaa[xx]);
}
for(xx=1;xx<=zz;xx++)
{
printf("%s\n",sz[xx]);
fprintf(fw,"%d\n",az[xx]);
}
for(xx=1;xx<=rr;xx++)
{
printf("%s\n",sr[xx]);
fprintf(fw,"%d\n",ar[xx]);
}
for(xx=1;xx<=ww;xx++)
{
printf("%s\n",sw[xx]);
fprintf(fw,"%d\n",aw[xx]);
}
for(xx=1;xx<=kk;xx++)
{
printf("%s\n",sk[xx]);
fprintf(fw,"%d\n",ak[xx]);
}
//Newly added end
for(xx=1;xx<=hh;xx++)
{
printf("%s\n",sh[xx]);
fprintf(fw,"%d\n",ah[xx]);
}

fclose(fp);
}

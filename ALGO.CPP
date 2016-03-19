#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void naive(char t[50],char p[50]);
void knap(int v[],int w[],int n,int t);
void knap1(int v[],int w[],int n,int t);
void act_sel(int s[],int f[],int ni);
int main()
{
 int v[10],w[10],ni,t,i;
int va[10],wa[10],na,ta,ia;
int s[10],f[10],n,j,temp;

char txt[50],pattern[50];
printf("\nEnter number of flights that are able to come to air port :");
 scanf("%d",&ni);
 for(i=1;i<=ni;i++)
 {
  printf("\nenter aravil time and depature  time of flight %d:",i);
  scanf("%d%d",&s[i],&f[i]);
 }
 for(i=1;i<=ni;i++)
 {
	 for(j=i+1;j<=ni;j++)
  {
   if(s[i]>s[j])
   {
    temp=s[i];
	s[i]=s[j];
s[j]=temp;
temp=f[i];
f[i]=f[j];
f[j]=temp;
	}
 }
 }
 for(i=1;i<=ni;i++)
 {
  printf("\naravil time  and depature time of flight  %d:%d %d",i,s[i],f[i]);
 }

act_sel(s,f,ni);
 printf("\nenter the number of goods items :");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("\nenter the value of the good and weight of good %d:",i);
  scanf("%d%d",&v[i],&w[i]);
 }
 printf("\nEnter the total capacity of the goods that can accomdate :");
 scanf("%d",&t);

knap(v,w,n,t);


printf("\nenter the number of passengers booked ticket:");
 scanf("%d",&na);
 for(ia=1;ia<=na;ia++)
 {
  printf("\n value is the passanger who booked first given higher value \n"); 
  printf("\nenter the value and weight of passengers %d:",ia);
  scanf("%d%d",&va[i],&wa[i]);
 }
 printf("\nEnter the total weight of passengers that can accomdate :");
 scanf("%d",&ta);
knap1(va,wa,na,ta);
printf("\n if the passanger name is found in the name that found in the visa passanger can travel \n");
printf("\nenter the text that are in the visa");
scanf("%s",txt);
printf("\nenter the passangername:");
scanf("%s",pattern);
naive(txt,pattern);
 getch();
}
void knap(int v[],int w[],int n,int t)
{
 int i,j,max,c[20][20];
 max=w[1];
 for(i=2;i<=n;i++)
 {
  if(w[i]>max)
  max=w[i];
 }
 for(i=0;i<=n;i++)
 c[i][0]=0;
 for(j=0;j<=t;j++)
 c[0][j]=0;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=t;j++)
  {
   if(j-w[i]<0)
   c[i][j]=c[i-1][j];
   else if(j-w[i]>=0)
   {
    if(c[i-1][j]>(v[i]+c[i-1][j-w[i]]))
    {
     c[i][j]=c[i-1][j];
    }
    else
    c[i][j]=c[i-1][j-w[i]]+v[i];
   }
  }
 }
 i=n;
 j=t;
 printf("\ngoods that are included in the flight are :\n");
 while(i>0 && j>0)
 {
  if(c[i][j]!=c[i-1][j])
  {
   printf("%d\n",i);
   j=j-w[i];
  }
  i=i-1;
 }
}
void knap1(int v[],int w[],int n,int t)
{
 int i,j,max,c[20][20];
 max=w[1];
 for(i=2;i<=n;i++)
 {
  if(w[i]>max)
  max=w[i];
 }
 for(i=0;i<=n;i++)
 c[i][0]=0;
 for(j=0;j<=t;j++)
 c[0][j]=0;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=t;j++)
  {
   if(j-w[i]<0)
   c[i][j]=c[i-1][j];
   else if(j-w[i]>=0)
   {
    if(c[i-1][j]>(v[i]+c[i-1][j-w[i]]))
    {
     c[i][j]=c[i-1][j];
    }
    else
    c[i][j]=c[i-1][j-w[i]]+v[i];
   }
  }
 }
 i=n;
 j=t;
 printf("\npassangers who able to travel in flight  are  :\n");
 while(i>0 && j>0)
 {
  if(c[i][j]!=c[i-1][j])
  {
   printf("%d\n",i);
   j=j-w[i];
  }
  i=i-1;
 }
}

void naive(char t[50],char p[50])
{
 int n,m,i,j;
 n=strlen(t);
 m=strlen(p);
 for(i=0;i<=n-m;i++)
 {
  j=0;
  while(j<m && t[i+j]==p[j])
   j++;
   if(j==m)
   {
    printf("\nValid\nShift=%d",i);
    printf("\n visa received with the ticket so the passanger can travel \n");
   }
   else
   printf("\nInvalid");
  }
 }

void act_sel(int s[],int f[],int ni)
{
 int b[10],i,m,j=1;
 b[1]=1;
 i=1;
 for(m=2;m<=ni;m++)
 {
  if(s[m]>=f[i])
  {
   j++;
   b[j]=m;
   i=m;
  }
 }

  printf("\n the flight that are to arive in the station are \n");
 for(i=1;i<=j;i++)
 {
                   
  printf(" flight %d\n",b[i]);
 }
}

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
 int p,e,i,d,n=0,s;
 while(scanf("%d %d %d %d",&p,&e,&i,&d)!=EOF)
 {
  n++;
  if(p==-1&&e==-1&&i==-1&&d==-1)
   break;
  s=(5544*p+14421*e+1288*i-d)%(23*28*33);
  if(s<=0)
   printf("Case %d: the next triple peak occurs in %d days.\n",n,21252-d);
  else
   printf("Case %d: the next triple peak occurs in %d days.\n",n,s);
 }
 system("pause");
 return 0;
}
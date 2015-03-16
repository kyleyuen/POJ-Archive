#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*满足题意的两个字符串比较，相等的长度等于短的或长度减1*/
int cmp(string a,string b)
{
    int s=0;
    string t;
    if(a.size()>b.size())
    {t=a;a=b;b=t;}
    if(a.size()<b.size())
    {
        s=0;
        for(int f=0;f<b.size()&&s<a.size();f++)
            if(a[s]==b[f]) s++;
        if(s==a.size())
            return true;

    }
    else if(a.size()==b.size())
    {
        s=0;
        for(int r=0;r<a.size();r++)
           if(a[r]==b[r]) s++;// 注意此处是a[r]不是a[s]
        if(s==a.size()-1)
           return true;

    }
    return false;

}

int main()
{
    char s[20];
    int n,size=0;
    string v,a[10010],b[10010];
    while(scanf("%s",s)!=EOF)
    {
         if(!strcmp(s,"#")) break;
            b[size].assign(s);//s赋值到b[size];
            a[size++].assign(s);
    }
    sort(a,a+size);
    while(scanf("%s",s)!=EOF)
    {
        if(!strcmp(s,"#")) break;
        v.assign(s);
        n=v.size();
        if(binary_search(a,a+size,v))
        {printf("%s is correct\n",v.c_str());continue;}//c_str()把string类转换成const char*

        printf("%s: ",v.c_str());
        for(int f=0;f<size;f++)
        {
            if(b[f].size()<n-1||b[f].size()>n+1)
               continue;
            if(cmp(b[f],v))
              printf("%s ",b[f].c_str());
            }
        printf("\n");
    }
    return 0;
}
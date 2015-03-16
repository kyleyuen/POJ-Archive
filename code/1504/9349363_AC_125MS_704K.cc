#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	int a,b;
	char s1[13],s2[13];
	scanf("%d%d",&a,&b);
	sprintf(s1,"%d",a);
	sprintf(s2,"%d",b);
	reverse(s1,s1+strlen(s1));
	reverse(s2,s2+strlen(s2));
	sscanf(s1,"%d",&a);
	sscanf(s2,"%d",&b);
	sprintf(s1,"%d",a+b);
	reverse(s1,s1+strlen(s1));
	sscanf(s1,"%d",&a);
	printf("%d\n",a);
}

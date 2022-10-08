#include<bits/stdc++.h>
using namespace std;
long long Myfunction(long long n)
{
	long long ans=0;
	long long j;
	if (n==1)
        return 1;
    ans = n;
    if (n%2==0){
		ans-=ans/2;
		while (n%2==0) n/=2;
    }
    for (j=3; j*j<=n; j+=2){
		if (n%j==0){
			ans-=ans/j;
			while (n%j==0) n/=j;
		}
	}
	if (n>1)
        ans -= ans/n;
	return ans;
}
int main()
{
    int T;
    while(scanf("%d",&T)&&T)
    {
        printf("%lld\n",Myfunction(T));
    }
    return 0;
}

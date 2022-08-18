#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;

vector<bool> composite(MAX + 7, false);
vector<long long> primes;

void generatePrimes(int N) /// O(Nlog(log(N)))
{
    composite[1] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (composite[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                composite[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (composite[i] == 0)
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    generatePrimes(MAX);
    int T;
    int ca = 1;
    scanf("%d",&T);
    while(T--)
    {
        long long a;
        scanf("%lld",&a);
        int cnt = 0;
        long long b=0;
        for(long long i=0;primes[i] <= a/2; i++)
        {
            b = a-primes[i];
            if(!composite[primes[i]]&& !composite[b])
            {
                cnt++;
            }
        }
        printf("Case %d: %lld\n",ca,cnt);
        ca++;
    }
     return 0;
}

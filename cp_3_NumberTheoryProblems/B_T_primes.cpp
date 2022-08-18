#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

vector<bool> composite(MAX + 1, false);
void generatePrimes(int N) /// O(Nlog(log(N)))
{
    vector<int> primes;
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
    long long sr;
    scanf("%d",&T);
    while(T--)
    {
        long long a;
        scanf("%I64d",&a);
        sr = sqrt(a);

        if((sr * sr == a) && (a > 1) && (composite[sr] != true))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
     return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

int divs[MAX+1];
void divisorCount(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            divs[j]++;
        }
    }
}

int main()
{
    divisorCount(MAX);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        int x = __gcd(a ,b);
        int totalCommonDivisors = (int)divs[x];
        printf("%d\n", totalCommonDivisors);
    }
     return 0;
}

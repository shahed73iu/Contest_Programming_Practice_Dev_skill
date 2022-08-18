#include <bits/stdc++.h>
using namespace std;
const int N = 99998953;

vector<bool> composite(N + 7, false);

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
    int s = 1;
    printf("2\n");
    for (int i = 3; i <= N; i++)
    {
        if (composite[i] == 0)
        {

            s++;
            if(s%100==1)
            {
                printf("%lld\n",i);
            }
        }
    }
}
int main()
{
    generatePrimes(N);

     return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;

vector<int> primes;
vector<bool> composite(MAX + 1, false);

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
    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
    {
        if (composite[i] == 0)
        {
            primes.push_back(i);
        }
    }
}

bool isPrimeNumber(long long n){
   if (n <= 1)
      return false;
   if (n <= 3)
   return true;
   if (n % 2 == 0 || n % 3 == 0)
      return false;
   for (long long i = 5; i * i <= n; i = i + 6)
   if (n % i == 0 || n % (i + 2) == 0)
   return false;
   return true;
}

int main()
{
    generatePrimes(MAX);

    //freopen("out.txt","w",stdout);
    long long N;
    while (cin >> N)
    {
        if (N == 0)
            return 0;
        long long ans = N;
        long long limit = N;
        if (isPrimeNumber(N) == true)
            ans = N - 1;
        else
        {
            bool flag = false;
            for (int i = 0; i <= limit; i++)
            {
                if (N % primes[i] == 0)
                {
                    while(N % primes[i] == 0){
                        N /= primes[i];
                        if(flag == false){
                            ans -= (ans / primes[i]);
//                            if (primes[i] < N && isPrimeNumber(N) == true)
//                            {
//                                ans -= (ans / N);
//                            }
                            flag = true;
                        }
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

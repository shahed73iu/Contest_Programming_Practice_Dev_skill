#include <bits/stdc++.h>
using namespace std;
#define Max_S 1000005
#define Base 29
#define Mod 1000000007

long long h[Max_S], po[Max_S];
void generatePrefixHash(string &s)
{
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        h[i] = ((h[i - 1] * Base) + s[i]) % Mod;
    }
    po[0] = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        po[i] = (po[i - 1] * Base) % Mod;
    }
}
long long getHash(int L, int R)
{
    if (L == 0)
        return h[R];
    return (h[R] - (h[L - 1] * po[R - L + 1] % Mod) + Mod) % Mod;
}
long long generateHash(string &s2)
{
    long long H = 0;
    for (auto c : s2)
    {
        H = ((H * Base) + c) % Mod;
    }
    return H;
}

int main() // First Problem
{
    string s1, s2;
    cin >> s1 >> s2;
    generatePrefixHash(s1);
    long long hashOfS2 = generateHash(s2);

    for (int i = 0; i + s2.size() <= s1.size(); i++)
    {
        if (getHash(i, i + s2.size() - 1) == hashOfS2)
        {
            cout << i << "\n";
        }
    }

    return 0;
}
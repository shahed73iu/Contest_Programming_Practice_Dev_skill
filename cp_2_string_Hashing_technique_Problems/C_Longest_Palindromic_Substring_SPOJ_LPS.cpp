#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 50;
const int Base = 129;

vector<long long> generateExponents(int N)
{
    vector<long long> po(N + 1, 1);
    for (int i = 1; i <= N; i++)
    {
        po[i] = (po[i - 1] * Base) % Mod;
    }
    return po;
}

vector<long long> generatePrefixHash(string &s)
{
    vector<long long> H(s.size(), 0);
    H[0] = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        H[i] = ((H[i - 1] * Base) + s[i]) % Mod;
    }
    return H;
}
long long getRangeHash(int L, int R, vector<long long> &H, vector<long long> &po)
{
    if (!L)
        return H[R];
    return ((H[R] - (H[L - 1] * po[R - L + 1] % Mod) + Mod) % Mod);
}
bool existPalindrom(int len, vector<long long> &sH, vector<long long> &rsh, vector<long long> &po)
{
    int N = sH.size();

    for (int i = 0; i + len <= N; i++)
    {
        int l1 = i;
        int r1 = i + len - 1;
        int r2 = N - 1 - l1;
        int l_test = N - 1 - r1;
        int l2 = r2 - r1 + l1;
        if (getRangeHash(l1, r1, sH, po) == getRangeHash(l2, r2, rsh, po))
        {
            return true;
        }
    }
    return false;
}

int CustomSearch(int l, int r, int parity, vector<long long> &sH, vector<long long> &rsh, vector<long long> &po)
{
    int mid;
    while (l < r)
    {
        mid = l + (r - l + 1) / 2;

        if ((mid & 1) != parity)
        {
            mid++;
        }
        if (existPalindrom(mid, sH, rsh, po))
            l = mid;
        else
            r = mid - 2;
    }
    return l;
}

int main()
{
    string rs, s;
    int N;
    cin >> N >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    vector<long long> sH = generatePrefixHash(s);
    vector<long long> rsH = generatePrefixHash(rs);
    vector<long long> po = generateExponents(s.size());

    int b1 = CustomSearch(0, N, 0, sH, rsH, po);
    int b2 = CustomSearch(0, N, 1, sH, rsH, po);

    printf("%d\n", max(b1, b2));
    return 0;
}
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
    int existPalindrom(vector<long long> &sH, vector<long long> &rsh, vector<long long> &po)
    {
        int N = sH.size();
        int MaxIndex = 1;
        int cnt = 0;

        for (int i = 0; i <= N; i++)
        {
            long long rvs = getRangeHash(0, i, rsh, po);
            long long str = getRangeHash(N-1-i, N-1, sH, po);
            if (rvs == str)
            {
                cnt = N-1-i;
                MaxIndex = (MaxIndex,cnt);
            }
        }
        return MaxIndex;
    }


    int main()
    {
        string rs, s;
        int T;
        cin>> T;
        for (int i = 1; i <= T; i++)
        {
            cin>> s;
            int N = s.size();
            rs = s;
            reverse(rs.begin(), rs.end());
            vector<long long> rsH = generatePrefixHash(rs);
            vector<long long> sH = generatePrefixHash(s);
            vector<long long> po = generateExponents(s.size());
            int index = existPalindrom(sH, rsH, po);
            printf("Case %d: %d\n",i, index+N);
        }

        return 0;
    }
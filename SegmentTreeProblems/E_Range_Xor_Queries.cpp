#include <bits/stdc++.h>
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2+1, en, nd+nd+1
using namespace std;

const int MAX = 200010;
long long tree[4 * MAX], arr[MAX];

void buildTree(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd]= arr[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd] = tree[nd+nd] ^ tree[nd+nd+1];

}

long long getXorSum(int st, int en, int nd, int L, int R)
{
    if(en<L || R < st) return 0;
    if(L<=st && en<=R) return tree[nd];
    return (getXorSum(left,L,R) ^ getXorSum(right,L,R));
}

int main()
{
    int n, L, R, q;
    scanf("%d %d",&n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    buildTree(0, n - 1, 1);
    while(q--)
    {

        scanf("%d %d",&L, &R);
        --L,--R;
        printf("%lld\n",getXorSum(0, n - 1, 1, L, R));

    }
    return 0;
}



//https://vjudge.net/contest/515215#status/shahed_is/-/0/

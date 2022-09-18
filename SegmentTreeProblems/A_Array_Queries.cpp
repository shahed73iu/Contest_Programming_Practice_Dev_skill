#include <bits/stdc++.h>
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2+1, en, nd+nd+1
using namespace std;

const int MAX = 100010;
int tree[4 * MAX], arr[MAX];

void buildTree(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd]= arr[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd] = min(tree[nd+nd], tree[nd+nd+1]);

}

int getMin(int st, int en, int nd, int L, int R)
{
    if(en<L || R < st) return INT_MAX/2;
    if(L<=st && en<=R) return tree[nd];
    return min(getMin(left,L,R), getMin(right,L,R));
}

int main()
{
    int n, L, R, q,T, cs=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n, &q);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i = 0; i< 4*n; i++) tree[i] = INT_MAX;
        buildTree(0, n - 1, 1);
        printf("Case %d:\n",cs++);
        while(q--)
        {

            scanf("%d %d",&L, &R);
            --L, --R;
            printf("%d\n",getMin(0, n - 1, 1, L, R));
        }
    }
    return 0;
}

//https://vjudge.net/contest/515215#status/shahed_is/-/0/
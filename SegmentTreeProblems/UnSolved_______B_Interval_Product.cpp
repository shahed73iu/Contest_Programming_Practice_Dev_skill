#include <bits/stdc++.h>
#include<string.h>
#include<cstring>

#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
using namespace std;

const int MAX = 200010;
long long tree[4 * MAX], arr[MAX];

void buildTree(int st, int en, int nd)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd] = tree[nd + nd] * tree[nd + nd + 1];
}

long long getProduct(int st, int en, int nd, int L, int R)
{
    if (en < L || R < st)
        return 0;
    if (L <= st && en <= R)
        return tree[nd];
    return (getProduct(left, L, R) + getProduct(right, L, R));
}
void pointUpdate(int st, int en, int nd, int idx, long long v)
{
    if (en < idx || idx < st)
        return;
    if (st == en)
    {
        tree[nd] = v;
        return;
    }
    pointUpdate(left, idx, v);
    pointUpdate(right, idx, v);
    tree[nd] = tree[nd + nd] * tree[nd + nd + 1];
}

int main()
{
    freopen("output.txt","w",stdout);
    int n, L, R, p;
    char command = 'C';
    char product = 'P';
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // for(int i = 0; i< 4*n; i++) tree[i] = 0;
    buildTree(0, n - 1, 1);
    string ans = "";
    for (int i = 1; i <= p; i++)
    {
        char type;
        scanf(" %c", &type);
        if (type == command)
        {
            int k, v;
            scanf("%d %d", &k, &v);
            --k;
            pointUpdate(0, n - 1, 1, k, v);
        }
        else if (type == product)
        {
            scanf("%d %d", &L, &R);
            --L, --R;
            int res = getProduct(0, n - 1, 1, L, R);
            if(res > 0) {
                ans = ans + "+";
            }
            else if( res < 0){
                ans = ans + "-";
            }
            else{
                ans = ans + "0";
            }
        }
    }
    cout<<ans<< "\n";
    return 0;
}

//https://vjudge.net/contest/515215#problem/B
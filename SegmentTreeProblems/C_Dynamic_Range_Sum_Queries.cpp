#include <bits/stdc++.h>
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2+1, en, nd+nd+1
using namespace std;

const int MAX = 200010;
long long tree[4 * MAX], arr[MAX];

void buildTree(int st, int en, int nd)
{
    if(st == en){
        tree[nd]= arr[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd] = tree[nd+nd]+ tree[nd+nd+1];

}

long long getSum(int st, int en, int nd, int L, int R)
{
    if(en<L || R < st) return 0;
    if(L<=st && en<=R) return tree[nd];
    return (getSum(left,L,R) + getSum(right,L,R));
}
void pointUpdate(int st, int en, int nd, int idx, long long v)
{
    if(en< idx || idx < st) return;
    if(st==en)
    {
        tree[nd] = v;
        return;
    }
    pointUpdate(left,idx,v);
    pointUpdate(right,idx,v);
    tree[nd] = tree[nd+nd] + tree[nd+nd+1];
}

int main()
{
  int n, L, R, q, type;
  scanf("%d %d",&n, &q);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&arr[i]);
  }
  //for(int i = 0; i< 4*n; i++) tree[i] = 0;
  buildTree(0, n - 1, 1);
  while(q--)
  {
    scanf("%d",&type);
    if(type == 1)
    {
        int k;
        long long u;
        scanf("%d %lld",&k, &u);
        --k;
        pointUpdate(0,n-1,1,k,u);
    }
    else if(type == 2)
    {
        scanf("%d %d",&L, &R);
        --L,--R;
        printf("%lld\n",getSum(0, n - 1, 1, L, R));
    }
  }
  return 0;
}

//https://vjudge.net/contest/515215#status/shahed_is/-/0/
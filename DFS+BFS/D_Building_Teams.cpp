#include<bits/stdc++.h>
using namespace std;

///https://cses.fi/problemset/result/4806703/


const int MAX = 200000;
vector<int> gr[MAX+10];
bool vis[MAX+10];
int col[MAX+10];

void dfs(int u, int clr, bool &status)
{
    vis[u] = 1;
    col[u] = clr;
    for(auto v : gr[u])
    {
        if(!vis[v])
        {
            if(clr == 1) dfs(v, 2, status);
            else dfs(v, 1, status);
            if(!status)return;
        }
        if(col[u] == col[v])
        {
            status = false;
            return;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    bool status = true;
    for(int k=1;k<=n; k++)
    {
        if(!vis[k])
        {
            dfs(k,1,status);
            if(!status) break;
        }
    }

    if(!status) printf("IMPOSSIBLE\n");
    else
    {
        printf("%d",col[1]);
        for(int i = 2; i<=n; i++)
        {
            printf(" %d",col[i]);
        }
        printf("\n");
    }

    return 0;
}

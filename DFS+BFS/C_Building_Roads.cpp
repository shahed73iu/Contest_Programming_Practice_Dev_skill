#include<bits/stdc++.h>
using namespace std;

///Problem Link :  https://cses.fi/problemset/task/1666

const int MAX = 200000;
vector<int> gr[MAX+10];
bool vis[MAX+10];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : gr[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i= 0; i< m; i++)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<int> result;
    for(int k=1;k<=n; k++)
    {
        if(!vis[k])
        {
            dfs(k);
            result.push_back(k);
        }
    }
    printf("%d\n",result.size()-1);
    for(int l=0; l < result.size()-1 ;l++)
    {
        printf("%d %d\n",result[l],result[l+1]);
    }
    return 0;
}

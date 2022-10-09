#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> gr[MAX+10];
bool vis[MAX+10];

void dfs(int u)
{
    vis[u] = 1;
    cout << "Visited " << u << "\n";
    getchar();
    for(auto v : gr[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    cout<< "Completed " << u << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i= 0; i< m; i++)
    {
        int u, v;
        cin>> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    getchar();

    dfs(1);

    return 0;
}

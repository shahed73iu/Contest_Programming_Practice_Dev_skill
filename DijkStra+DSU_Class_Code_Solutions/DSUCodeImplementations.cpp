#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int pr[MAX+5];

int FindLeader(int u)
{
    if(u == pr[u]) return u;
    return pr[u] = FindLeader(pr[u]);
}
void connectNode(int u, int v)
{
    int leaderOf_U = FindLeader(u);
    int leaderOf_V = FindLeader(v);
    pr[leaderOf_U] = leaderOf_V;
}

int main()
{
    int n, q;
    cin >> n;
    for(int i = 1; i <=n; i++) pr[i] = i;
    cin >> q;
    while(q--)
    {
        int type , u, v;
        cin >> type >> u >> v;
        if(type == 1) // connect_Node
        {
            connectNode(u,v);
        }
        else if(type == 2) //is_Connected
        {
            u = FindLeader(u);
            v = FindLeader(v);
            if(u == v) puts("Yes");
            else puts("No");
        }
    }
}

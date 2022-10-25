#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;
const int INF = INT_MAX/2;
vector<pair<long long, int>> E[MAX + 10];
///long long D[MAX + 5]; // if Taking Array;

vector<long long> generateShortestPath(int src, int n)
{
    ///for(int i = 1; i<=n; i++) D[i] = INF; //if Taking Array;
    vector<long long> D(n+1, INF);
    priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>> > pQ;

    pQ.push({0,src});
    while(!pQ.empty())
    {
        auto p = pQ.top();
        pQ.pop();
        int u = p.second, d = p.first;

    }

}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i= 0; i<m; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        E[a].push_back({c,b}); ///(dist, node)
    }
    auto D = generateShortestPath(1,n); /// Apply DijkStra Algorithm
    for(int i = 1; i<=n; i++)
    {
        printf("%lld ",D[i]);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
vector<int> gr[MAX + 5];

int main()
{
    int node, edge, a, b;
    cin >> node >> edge;
    for(int i= 0; i< edge; i++)
    {
        ///a, b; a-------b
        cin>> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int n=0; n<node; n++)
    {
        cout<< n << " : ";
        for(auto u : gr[n])
        {
            cout<< u << " ";
        }
        cout << "\n";
    }
    return 0;
}



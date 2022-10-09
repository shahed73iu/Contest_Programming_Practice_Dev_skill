#include<bits/stdc++.h>
using namespace std;

///https://cses.fi/problemset/result/4777921/

///https://www.youtube.com/watch?v=QxY16bI37oc  >>---> Directional array Video Ref

const int MAX = 1000;

char gr_array[MAX+10][MAX+10];
bool vis[MAX+10][MAX+10];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;

bool isValid(int x, int y)
{
     if(x >= 0 && x < n && y >= 0 && y < m && gr_array[x][y] == '.') return true;
     return false;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int mvX = x + dx[i];
        int mvY = y + dy[i];

        if(isValid(mvX,mvY) && !vis[mvX][mvY])
        {
            dfs(mvX,mvY);
        }
    }
}

int main()
{
    int countComponent = 0;
    scanf("%d %d",&n,&m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            scanf(" %c",&gr_array[i][j]);
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int l=0; l<m; l++)
        {
            if(gr_array[k][l] == '.' && !vis[k][l])
            {
                dfs(k,l);
                countComponent++;
            }
        }
    }
    printf("%d\n",countComponent);
    return 0;
}

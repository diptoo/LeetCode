#include<iostream>
using namespace std;
int row, col;
char grid[100][100];
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};
bool visited[100][100];

bool isValid(int x, int y)
{
    if(x < 0 || y < 0 || x == row || y == col) return false;
    if(visited[x][y] || grid[x][y] == '0') return false;

    return true;
}

void dfs(int srcX, int srcY)
{
    visited[srcX][srcY] = true;

    for (int i = 0; i < 4; i++)
    {
        int u = srcX + dx[i];
        int v = srcY + dy[i];

        if(isValid(u, v))
        {
            dfs(u, v);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout) ;
   #endif


    cin>>row>>col;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>grid[i][j];   
        }
    }
    
    int res = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(grid[i][j] == '1' && !visited[i][j])
            {
                res++;
                dfs(i, j);
            }   
        }
    }
    cout<<res<<endl;
}
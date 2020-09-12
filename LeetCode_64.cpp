#include<iostream>
using namespace std;
#define ARRAY_SIZE 500

int dx[2] = {0, 1};
int dy[2] = {1, 0};
bool visited[ARRAY_SIZE][ARRAY_SIZE];
int cell_cost[ARRAY_SIZE][ARRAY_SIZE];
int dp[ARRAY_SIZE][ARRAY_SIZE];
int row, col;

bool isValid(int x, int y)
{
    if(x < 0 || x == row || y < 0 || y == col) return false;
    //if(visited[x][y]) return false;
    return true;
}

int dfs(int x, int y, int destX, int destY)
{
    if(x == destX && y == destY) return cell_cost[destX][destY];
    if(dp[x][y] != -1) return dp[x][y];

    int miny = 1e9 + 5;

    for (int i = 0; i < 2; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if(isValid(u,v))
        {
            int res = dfs(u, v, destX, destY) + cell_cost[x][y];
            if(res < miny) miny = res;
        }
    }

    dp[x][y] = miny;
    return dp[x][y];
}

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout) ;
   #endif


    cin>>row>>col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>cell_cost[i][j];   
            dp[i][j] = -1;
        }
    }
    
    cout<<dfs(0, 0, row - 1, col - 1)<<endl;

}
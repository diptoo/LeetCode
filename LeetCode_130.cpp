#include<iostream>
#include<vector>
using namespace std;
#define ARRAY_SIZE 500

int dx[]={1,-1,0,0}; 
int dy[]={0,0,1,-1};
char grid[ARRAY_SIZE][ARRAY_SIZE];
bool visited[ARRAY_SIZE][ARRAY_SIZE];
int row, col;
vector<pair<int, int> > valid_indices;

bool isValid(int x, int y)
{
    if(x < 0 || x == row || y < 0 || y == col) return false;
    if(grid[x][y] != 'o' || visited[x][y]) return false;
    return true;
}

bool isnot_border(int x, int y)
{
    if(grid[x][y] == 'o' && (x == row - 1 || y == col - 1 || x == 0 || y == 0)) return false;
    return true;
}

bool dfs1(int x, int y)
{
    //grid[x][y] = 'y';
    if(!isnot_border(x, y)) return false;
    visited[x][y] = true;
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if(isValid(u,v))
        {
            bool valid = dfs1(u, v);
            if(!valid) {
                flag = false;
            }
        }
    }
    return flag;
}

void dfs2(int x, int y)
{
    visited[x][y] = true;
    grid[x][y] = 'x';

    for (int i = 0; i < 4; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];

        if(isValid(u,v))
        {
            dfs2(u, v);
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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>grid[i][j];   
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(isValid(i, j) && isnot_border(i,j))
            {
                bool res = dfs1(i, j);
                if(res) {
                    cout<<i<<" "<<j<<endl;
                    valid_indices.push_back(make_pair(i, j));
                }
            }   
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            visited[i][j] = false;
        }
    }
    

    for (int i = 0; i < valid_indices.size(); i++)
    {
        int x = valid_indices[i].first;
        int y = valid_indices[i].second;

        dfs2(x, y);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<grid[i][j];   
        }
        cout<<endl;
    }
}
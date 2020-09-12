#include<iostream>
#include<vector>
using namespace std;

int src, dest, k, sum = 0, cnt = 0;
bool visited[100001];
int dp[200][200];
int weight[400][400];
vector<int> arr[400];

int dfs(int from, int to, int k)
{
    cout<<"from "<<from<<" to "<<to<<" K "<<k<<endl;
    if(to == dest) return 0;
    if(k < 0) return 1e5 + 9;
    if(dp[to][k] != -1) return dp[to][k];
    visited[to] = true;

    int miny = 1e5 + 9;
    for (int i = 0; i < arr[to].size(); i++)
    {
        int child = arr[to][i];
        // if(!visited[child])
        // {
            int res = dfs(to, child, --k) + weight[to][child];
            k++;
            cout<<"To "<<to<<" Child "<<child<<" Res "<<res<<endl;
            if(res < miny)
            {
                miny = res;
            }
        // }
        // else return dp[child] + weight[to][child];
    }

    dp[to][k] = miny;
    cout<<"DP of "<<to<<" = "<<miny<<endl;
    return dp[to][k];
}

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout) ;
   #endif

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            dp[i][j] = -1;
        }
    }
    

    
    int node, edge;
    cin>>node>>edge;
    for (int i = 0; i < edge; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        arr[a].push_back(b);
        //arr[b].push_back(a);

        weight[a][b] = w;
        //weight[b][a] = w;
    }
    cin>>src>>dest>>k;
    int res = dfs(-1, src, k);
    if(res >= 1e5+9) cout<<-1<<endl;
    else cout<<res<<endl;
}
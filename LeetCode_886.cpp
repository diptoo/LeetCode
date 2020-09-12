#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int colr, vector<int> arr[], bool *visited, bool *colored)
{
    visited[node] = true;
    colored[node] = colr;

    for (int i = 0; i < arr[node].size(); i++)
    {
        int child = arr[node][i];

        if(!visited[child])
        {
            bool res = dfs(child, colr ^ 1, arr, visited, colored);
            if(!res) return false;
        }
        else if(colored[node] == colored[child])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout) ;
   #endif

    int node, edge;
    cin>>node>>edge;
    vector<int>arr[node + 1];
    bool visited[node + 1];
    bool colored[node + 1];

    memset(visited, false, sizeof(visited));
    memset(colored, false, sizeof(visited));

    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bool flag = true;

    for (int i = 1; i <= node; i++)
    {
        if(!visited[i])
        {
            flag = dfs(i, 1, arr, visited, colored);
            if(!flag) break;
        }
    }

    if(!flag) cout<<"false"<<endl;
    else cout<<"true"<<endl;
}
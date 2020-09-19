#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;
#define ARRAY_SIZE 5001   
#define INF 1000000007
#define ll long long
#define endl '\n'
void fast_io()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout) ;
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

int main()
{
    fast_io();

    vector<vector<int> > intervals(3, vector<int>(2, 0));

    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            intervals[i][j] = i + j;
        }
    }

    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            cout<<intervals[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> tempInterval = intervals[1];

    cout<<tempInterval[0]<<endl;
    cout<<tempInterval[1]<<endl;

    vector<vector<int> > temp;
    cout<<temp.size()<<endl;
}
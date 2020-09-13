#include<iostream>
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
    
    int n, nums[10001]; 
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int l = 0, m = 0,h = n - 1;
        
    while(m <= h)
    {
        if(nums[m] == 0)
        {
            swap(nums[m], nums[l]);
            l++;
            m++;
        }
        else if(nums[m] == 1)
        {
            m++;
        }
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    
}
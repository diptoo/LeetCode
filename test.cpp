#include<iostream>
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
    //fast_io();
    
    int n;
    cin>>n;
    cout<<n * 2<<endl;
}
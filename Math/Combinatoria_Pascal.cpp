#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define vll vector<ll>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("popcnt")
const ll MOD=1e9;
const int INF=1234567890;
const ll MAX=100003;
const double epsi=0.0000001;ll pascal[5005][5005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    pascal[0][0]=1;
    for(int i=1;i<=5000;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)pascal[i][j]=1;
            else
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%MOD;            
        }
    }
    int n,k;
    cout<<pascal[n][k]<<endl;
    

    return 0;
}
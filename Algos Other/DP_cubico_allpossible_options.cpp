#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define vll vector<ll>
using namespace std;
const ll MOD=1000000007;
const int INF=1234567890;
const ll MAX=100003;
const int tam =1000;
const double epsi=0.0000001;
double dp[tam][tam];
double pcero[tam][tam];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;//dp[indice k a mirar][cantidad tomados];
    vector<double > p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++){
        dp[0][i]=p[i];
        pcero[0][i]=1-p[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1.0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j+1;k<n;k++){
                double curr=dp[i][j]*(1-p[k])+pcero[i][j]*p[k];
                if(curr>dp[i+1][k]){
                    dp[i+1][k]=curr;
                    pcero[i+1][k]=pcero[i][j]*(1-p[k]);
                }
            }
        }
    }
    double ans=-1.0;
    for(int i=0;i<n;i++)
    for(int j=i;j<n;j++){
        ans=max(ans,dp[i][j]);
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;


    return 0;
}
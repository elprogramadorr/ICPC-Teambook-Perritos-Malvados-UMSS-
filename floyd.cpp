#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
//salida rapida "\n"
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ma[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int l=0;l<=n;l++){
            ma[i][l]=100000;
            if(i==l){
                ma[i][l]=0;
            }
        }
    }
    int a,b,x;
    for(int i=0;i<m;i++){
        cin>>a>>b>>x;
        ma[a][b]=min(ma[a][b],x);
        ma[b][a]=min(ma[a][b],x);
    }
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<n;l++){
            cout<<i<<"  "<<l<<"  "<<ma[i][l]<<endl;
        }
    }

    return 0;
}

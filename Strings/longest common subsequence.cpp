#include<bits/stdc++.h>
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
//DECIMALES fixed<<sp(n)<<x<<endl;
//gcd(a,b)= ax + by
//lCB x&-x
using namespace std;

int main()
{
    string s,ss;
    cin>>s>>ss;
    int n=s.size(),m=ss.size();
    int M[n+1][m+1];
    for(int i=0;i<=n;i++){
        M[i][0]=0;
    }
    for(int l=0;l<=m;l++){
        M[0][l]=0;
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            if(s[i-1]==ss[l-1]){
                M[i][l]=1+M[i-1][l-1];
            }else{
                M[i][l]=max(M[i-1][l],M[i][l-1]);
            }
        }
    }
    cout<<M[n][m]<<endl;

    return 0;
}

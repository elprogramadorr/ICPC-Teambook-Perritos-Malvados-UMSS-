#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
using namespace std;
const ll MOD=1e9+7;
struct Matrix{
    ll a[2][2];
    Matrix operator *(Matrix A){
        Matrix res = {{{0ll,0ll},{0ll,0ll}}};
        for(int i=0;i<2;i++){
            for(int l=0;l<2;l++){
                for(int j=0;j<2;j++){
                    res.a[i][l]+=a[i][j]*A.a[j][l];
                    res.a[i][l]%=MOD;
                }
            }
        }
        return res;
    }
};
Matrix pou(Matrix a,ll n){
    if(n==0){
        return Matrix{{{1,0},{0,1}}};
    }
    if(n%2)return a*pou(a,n-1);
    Matrix res=pou(a,n/2);
    return res*res;
}
int main()
{
    ll n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    Matrix aux=pou(Matrix{{{0ll,1ll},{1ll,1ll}}},n-1);
    cout<<aux.a[1][1]<<endl;
    return 0;
}
//https://codeforces.com/gym/102644/problem/C
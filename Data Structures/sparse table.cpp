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
//lSB x&-x
using namespace std;

int ST[20][10000];
int query(int b,int e){
    int len=(e-b+1);
    int pot=__lg(len);
    return max(ST[pot][b],ST[pot][e-(1<<pot)+1]);
}
int main()
{
    //numero mas grande en un arreglo 
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        ST[0][i]=x;
    }
    for(int i=1;i<=__lg(n);i++){
        for(int l=0;l<n;l++){
            if(l+(1<<i)-1>=n){
                break;
            }
            ST[i][l]=max(ST[i-1][l],ST[i-1][l+(1<<(i-1))]);
        }
    }
    cout<<query(0,2)<<endl;
    cout<<query(2,3)<<endl;
    

    return 0;
}

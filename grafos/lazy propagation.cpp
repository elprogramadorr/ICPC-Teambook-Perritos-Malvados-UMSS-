
#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
//"\n"
// PROBLEMA   https://codeforces.com/problemset/problem/1208/D
using namespace std;
const int tam=2*1e5;
const ll INF = 1e16;
ll T[4*tam];
ll lazy[4*tam];
vll v;
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    lazy[nodo]=0;
    if(e==b){
        T[nodo]=v[b];
        return;
    }
    init(L,b,mid);init(R,mid+1,e);
    T[nodo]=min(T[L],T[R]);
}
void update(int nodo, int b, int e, int izq, int der, ll ad){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b>=izq && e<=der){
        lazy[nodo]+=ad;
        T[nodo]+=ad;
        return;
    }
    if(der<=mid){
        update(L,b,mid,izq,der,ad);
        T[nodo]=min(T[L],T[R]);
        return;
    }
    if(izq>=mid+1){
        update(R,mid+1,e,izq,der,ad);
        T[nodo]=min(T[L],T[R]);
        return;
    }
    update(R,mid+1,e,izq,der,ad);
    update(L,b,mid,izq,der,ad);
    T[nodo]=min(T[L],T[R]);
}
int query(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        return b;
    }
    lazy[L]+=lazy[nodo];
    lazy[R]+=lazy[nodo];
    T[L]+=lazy[nodo];
    T[R]+=lazy[nodo];
    lazy[nodo]=0;
    ll res;
    if(T[R]==0){
        res=query(R,mid+1,e);
    }else{
        res=query(L,b,mid);
    }
    T[nodo]=min(T[L],T[R]);
    return res;
}
int main()
{
    ll n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    init(0,0,n-1);
    vll res(n);
    //cout<<T[0]<<" "<<T[1]<<" "<<T[2]<<endl;
    for(int i=1;i<=n;i++){
        int l0=query(0,0,n-1);
        //cout<<"found  "<<l0<<endl;
        res[l0]=i;
        update(0,0,n-1,l0,l0,INF);
        update(0,0,n-1,l0,n-1,-i);
        //cout<<"min  "<<T[0]<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}

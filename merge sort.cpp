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
//https://oj.uz/problem/view/COCI21_in solo para subtask 2
using namespace std;
const int tam =50000;
vi T[4*tam];
vi v;
int cant=0;
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        T[nodo].pb(v[b]);
        return;
    }
    init(L,b,mid);init(R,mid+1,e);
    T[nodo].resize(T[L].size()+T[R].size());
    merge(T[L].begin(),T[L].end(),T[R].begin(),T[R].end(),T[nodo].begin());
}
void query(int nodo, int b, int e, int izq, int der, int h){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b>=izq && e<=der){
        int pos=T[nodo].size();
        int B=0,E=T[nodo].size()-1;
        while(B<=E){
            int MID=(B+E)/2;
            if(T[nodo][MID]>=h){
                pos=MID;
                E=MID-1;
            }else{
                B=MID+1;
            }
        }
        cant+=T[nodo].size()-pos;
        return;
    }
    if(der<=mid){
        query(L,b,mid,izq,der,h);
        return;
    }
    if(izq>=mid+1){
        query(R,mid+1,e,izq,der,h);
        return;
    }
    query(L,b,mid,izq,der,h);query(R,mid+1,e,izq,der,h);
}
int main()
{
    int n,q,x;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    } 
    init(0,0,n-1);    
    int a,b;
    while(q--){
        cin>>a>>b;
        a--;b--;
        int iz=0,de=200005;
        int res=0;
        while(iz<=de){
            int mid=(iz+de)/2;
            cant=0;
            query(0,0,n-1,a,b,mid);
            if(cant>=mid){
                res=mid;
                iz=mid+1;
            }else{
                de=mid-1;
            }
        }
        cout<<res<<endl;
    }
    
    
    return 0;
}



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

using namespace std;
vi P;
int _find(int x){
    if(P[x]==x){
        return x;
    }
    return P[x]=_find(P[x]);
}
int _union(int x,int y,int peso){
    x=_find(x);
    y=_find(y);
    if(x==y){
        return 0;
    }else{
        P[x]=y;
        return peso;
    }
}
int main()
{
    vector<pair<int,pair<int,int> > >v;
    int n,m,a,b,x;
    cin>>n>>m;
   //n -> nodos   m->aristas
    for(int i=0;i<=n;i++){
        P.pb(i);
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>x;
        v.pb(mp(x,mp(a,b)));
    }
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0;i<m;i++){
        int aux=res;
        cout<<v[i].S.F<<" "<<v[i].S.S<<endl;
        res+=_union(v[i].S.F,v[i].S.S,v[i].F);
        cout<<res-aux<<endl;
    }
    cout<<res<<endl;
    return 0;
}

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
//"\n"
//gcd(a,b)= ax + by
//lCB x&-x
//__builtin_popcount(x)
using namespace std;
const int tam=300005;
vi G[tam];
vi G1[tam];
int scc=0;
int grupo[tam];
int m;
vector<bool>vis;
vi v;
int neg(int x){
    if(x<=m)return x+m;
    return x-m;
}
void add(int a, int b){
    G[a].pb(b);
    G1[b].pb(a);    
}
void dfs0(int nodo){
    vis[nodo]=1;
    for(auto it : G[nodo]){
        if(!vis[it])dfs0(it);
    }
    v.pb(nodo);
}
void dfs1(int nodo){
    grupo[nodo]=scc;
    vis[nodo]=1;
    for(auto it : G1[nodo]){
        if(!vis[it])dfs1(it);
    }
}

int main()
{
    //res[i]=grupo[i]>grupo[-i]
    int n,a,b;
    cin>>n>>m;
    vis.assign(2*m+2,false);
    char c1,c2;
    for(int i=0;i<n;i++){
        cin>>c1;
        cin>>a;
        if(c1=='-')a+=m;
        cin>>c2;
        cin>>b;
        if(c2=='-')b+=m;
        add(neg(a),b);
        add(neg(b),a);
    }
    for(int i=1;i<=2*m;i++){
        if(!vis[i])dfs0(i);
    }
    vis.assign(2*m+2,false);
    vector<bool> res(m+1);
    for(int i=v.size()-1;i>=0;i--){
        if(!vis[v[i]]){
            dfs1(v[i]);
            scc++;
        }
    }
    for(int i=1;i<=m;i++){
        if(grupo[i]==grupo[i+m]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        res[i]=grupo[i]>grupo[i+m];
    }
    for(int i=1;i<=m;i++){
        if(res[i]){
            cout<<"+ ";
        }else{
            cout<<"- ";
        }
    }
    
    return 0;
}
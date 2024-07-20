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
//__builtin_popcount(x)
// a+b=2*(a&b) + (a^b)
using namespace std;
const int tam=100005;
set<int>G[tam];
vi res;
void go(int nodo){
    while(G[nodo].size()>0){
        auto it = G[nodo].begin();
        G[nodo].erase(it);
        go(*it);
    }
    res.pb(nodo);
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vi in(n+1,0);
    vi out(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].insert(b);
        out[a]++;in[b]++;
    }
    int be=-1;
    int en=-1;
    int cant=0;
    for(int i=1;i<=n;i++){
        if(in[i]==out[i]){
            cant++;continue;
        }
        if(out[i]-1==in[i]){
            be=i;
            continue;
        }
        if(in[i]-1==out[i]){
            en=i;
            continue;
        }
    }
    go(1);
    if(be!=1 or en!=n or cant!= n-2 or res.size()-1 != m){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    reverse(res.begin(),res.end());
    if(res.back()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" "; 
    }
    return 0;
}

//https://cses.fi/problemset/task/1693/
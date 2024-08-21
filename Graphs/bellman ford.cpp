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
//set.erase(it) - ersases the element present at the required index//auto it = s.find(element)
//set.find(element) - iterator pointing to the given element if it is present else return pointer pointing to set.end()
//set.lower_bound(element) - iterator pointing to element greater than or equal to the given element
//set.upper_bound(element) - iterator pointing to element greater than the given element
// | ^
//__builtin_popcount(x)
using namespace std;
const ll INF=1e16;
vector<vll>G;
vector<bool>vis;
void dfs(ll u){
    vis[u]=true;
    for(auto it : G[u]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main()
{
    ll n,m,a,b,w;
    cin>>n>>m;
    G.assign(n+1,vll());
    vector<pair<ll,pair<ll,ll> > >E;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        G[a].pb(b);
        E.pb({a,{b,w}});
    }
    //cout<<E.size()<<endl;
    vll dis(n+1,-INF);
    dis[1]=0;
    for(int i=1;i<n;i++){
        for(int l=0;l<m;l++){
            a=E[l].F;b=E[l].S.F;w=E[l].S.S;
            dis[b]=max(dis[b],dis[a]+w);
        }
    }    
    for(int i=1;i<n;i++){
        for(int l=0;l<m;l++){
            a=E[l].F;b=E[l].S.F;w=E[l].S.S;
            if(dis[b]<dis[a]+w){
                vis.assign(n+1,false);
                dfs(1);
                //cout<<"empiezo dfs   "<<b<<endl;
                if(vis[b]){
                    vis.assign(n+1,false);
                    dfs(b);
                    if(vis[n]){
                        cout<<-1<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(dis[n]<=-INF){
        cout<<-1<<endl;
    }else{
        cout<<dis[n]<<endl;
    }
    return 0;
}
// la vida es dura pero mas dura mi verdura
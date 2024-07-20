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
vector<vi>G;
vi vis;
int nodo;
vi p(1e6);
void dfs(int u){
    if(nodo!=-1)return;
    vis[u]=1;
    for(auto it : G[u]){
        if(nodo!=-1)return;
        //es importante poner este if antes si no se entraria en todas obvio
        if(vis[it]==1){
            nodo=it;
            p[it]=u;
            return;
        }
        if(vis[it]==0){
            p[it]=u;
            dfs(it);
        }
        
    }
    vis[u]=2;
}
int main()
{
    //la idea es colorear los nodos de tres formas blanco si no fué visitado nunca, gris si esta siendo procesado y negro si ya fué procesado
    //habra ciclo si el hijo de un nodo es gris pq significa que de alguna forma llegué a este nodo "empezando de ese"
    int n,m,a,b;
    cin>>n>>m;
    G.assign(n+1,vi());
    vis.assign(n+1,0);
    //0 blanco
    //1 gris
    //2 negro
    for(int i=0;i<m;i++){ 
        cin>>a>>b;
        G[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        nodo=-1;
        if(vis[i]==0){
            p[i]=-1;
            dfs(i);
        }
        if(nodo!=-1){
            vi res;
            res.pb(nodo);
            int v=p[nodo];
            while(v!=nodo){
                res.pb(v);
                v=p[v];
            }
            res.pb(nodo);
            cout<<res.size()<<endl;
            reverse(res.begin(),res.end());
            //lo vuelteo para que este en orden XD
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
            return 0;
        }

    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
//la vida es dura pero mas dura mi verdura

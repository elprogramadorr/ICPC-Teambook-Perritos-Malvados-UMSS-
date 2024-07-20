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
vector<vector<pair<int,int> > >G;
vector<int>peso;
vector<bool>vis;
void dijkstra(int nodo){
    priority_queue<pair<int,int> >q;
    q.push(mp(0,nodo));
    peso[nodo]=0;
    while(q.size()>0){
        int u=q.top().S;
        q.pop();
        if(vis[u]==true){
            continue;
        }
        vis[u]=true;
        for(int i=0;i<G[u].size();i++){
            int hijo=G[u][i].F;
            if(peso[u]+G[u][i].S<peso[hijo]){
                peso[hijo]=peso[u]+G[u][i].S;
                q.push(mp(-peso[hijo],hijo));
            }
        }
    }
}
int main()
{
    int t,x,y,z,r,c,p,n;
    cin>>t;
    while(t--){
        cin>>n>>r>>c>>p;
        G.assign(n+1,vector<pair<int,int> >());
        //aristas grafo dirigido
        for(int i=0;i<r;i++){
            cin>>x>>y>>z;
            G[x].pb(mp(y,z));
        }
        peso.assign(n,10000000);
        vis.assign(n,false);
        dijkstra(p);
        //distancia minima de p a x...
        for(int i=0;i<c;i++){
            cin>>x;
            if(vis[x]==false){
                cout<<"No Es Posible"<<endl;
                continue;
            }
            cout<<peso[x]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
//https://pastebin.com/kV4Heyii
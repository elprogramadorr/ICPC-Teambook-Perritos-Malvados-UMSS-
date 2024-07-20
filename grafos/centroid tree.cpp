#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
using namespace std;
const int tam=1e5+5;
vi G[tam];
int depth[tam];
int n,m,dp[tam][22];
int sz[tam];
bool vis[tam];
int ans[tam];
int padre[tam];
//todo sobre lca
void dfs(int nodo, int ant, int d){
    depth[nodo]=d;
    dp[nodo][0]=ant;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        dfs(it,nodo,d+1);
    }
}
void init(){
    memset(dp,-1,sizeof(dp));
    dfs(1,-1,0);
    for(int i=1;i<20;i++){
        for(int l=1;l<=n;l++){
            if(dp[l][i-1]==-1)continue;
            dp[l][i]=dp[dp[l][i-1]][i-1];
        }
    }
}
int LCA(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    for(int i=19;i>=0;i--){
        if(dp[b][i]==-1)continue;
        if(depth[dp[b][i]]>=depth[a]){
            b=dp[b][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];b=dp[b][i];
        }
    }
    return dp[a][0];
}
int dis(int a, int b){
    return depth[a]+depth[b]-2*depth[LCA(a,b)];
}
//centroid!
void initsz(int nodo, int ant){
    sz[nodo]=1;
    for(auto it : G[nodo]){
        if(it==ant or vis[it])continue;
        initsz(it,nodo);
        sz[nodo]+=sz[it];
    }
}
int centroid(int nodo, int ant, int desired){
    for(auto it : G[nodo]){
        if(it==ant or vis[it])continue;
        if(sz[it]>=desired)return centroid(it,nodo,desired);
    }
    return nodo;
}
void solve(int nodo, int ant){
    initsz(nodo,ant);
    int centro=centroid(nodo,ant,sz[nodo]/2);
    padre[centro]=ant;
    vis[centro]=1;
    for(auto it : G[centro]){
        if(!vis[it])solve(it,centro);
    }
}
//queries y updates

int query(int nodo){
    int res=1e9;
    int curr=nodo;
    while(curr!=-1){
        assert(dis(curr,nodo)>=0);
        res=min(res,dis(curr,nodo)+ans[curr]);
        curr=padre[curr];
    }
    return res;
}
void update(int nodo){
    int curr=nodo;
    while(curr!=-1){
        assert(dis(curr,nodo)>=0);
        ans[curr]=min(ans[curr],dis(curr,nodo));
        curr=padre[curr];
    }
}

int main(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        G[x].pb(y);G[y].pb(x);
    }
    for(int i=1;i<=n;i++)ans[i]=1e9;
    init();
    solve(1,-1);
    update(1);
    int q;
    while(m--){
        cin>>q>>x;
        if(q==1){
            update(x);
        }else{
            cout<<query(x)<<endl;
        }
    }
    
    return 0;
}
//https://codeforces.com/contest/342/problem/E
//hallar el nodo rojo más cerca y pintar un nodo de rojo
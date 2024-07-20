z|#include<bits/stdc++.h>
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
const int tam=200005;
vi G[tam];
int sz[tam];
bool vis[tam];
int cant[tam];
int max_depth;
ll res=0;
int n,k;
int centroid(int nodo, int ant, int desired){
   for(auto it : G[nodo]){
       if(it==ant or vis[it])continue;
       if(sz[it]>=desired)return centroid(it,nodo,desired);
    }
    return nodo; 
}
void initsz(int nodo, int ant){
    sz[nodo]=1;
    for(auto it : G[nodo]){
        if(it==ant or vis[it])continue;
        initsz(it,nodo);
        sz[nodo]+=sz[it];
    }
}
void update(int nodo, int ant,int depth){
    cant[depth]++;
    for(auto it : G[nodo]){
        if(it==ant or vis[it])continue;
        update(it,nodo,depth+1);
    }
}
void cal(int nodo,int ant, int depth){
    if(depth>k)return;
    max_depth=max(max_depth,depth);
    res+=cant[k-depth];
    for(auto it : G[nodo]){
        if(it==ant or vis[it])continue;
        cal(it,nodo,depth+1);
    }
}
void solve(int nodo){
    //aqui le paso cualquier nodo del subarbol 
    initsz(nodo,-1);
    cant[0]=1;
    max_depth=0;
    int centro=centroid(nodo,-1,sz[nodo]/2);
    vis[centro]=1;
    for(auto it : G[centro]){
        if(vis[it])continue;
        cal(it,centro,1);
        update(it,centro,1);   
    }
    for(int i=0;i<=max_depth+2;i++)cant[i]=0;//Esto es super importante si no TLE
    for(auto it : G[centro]){
        if(!vis[it])solve(it);
    }
}
int main(){
    fast
    cin>>n>>k;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        G[b].pb(a);
        G[a].pb(b);
    }
    solve(1);
    cout<<res<<endl;

    
    return 0;
}
//Given a tree of n nodes, your task is to count the number of distinct paths that consist of exactly k edges.
//https://cses.fi/problemset/task/2080/

#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define ii pair<int,int>
#define S second
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("popcnt")
int n;
int m;
const int tam=20000;
vector<pair<int,ii> >E;//son las aristas
vector<vi>G;
int matcha[tam];
int matchb[tam];
vi unmatch;
vi dis;
bool bfs(){
    queue<int>q;
    dis.assign(n+1,0);
    for(auto it : unmatch){
        dis[it]=1;
        q.push(it);
    }
    bool ok=false;
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        for(auto it : G[nodo]){
            if(!matchb[it]){
                ok=1;
                continue;
            }
            if(dis[matchb[it]])continue;
            dis[matchb[it]]=dis[nodo]+1;
            q.push(matchb[it]);
        }
    }
    return ok;
}
bool dfs(int nodo,int w){
    for(auto it : G[nodo]){
        if(!matchb[it]){
            matchb[it]=nodo;
            matcha[nodo]=it;
            return true;
        }
    }
    for(auto it : G[nodo]){
        if(dis[matchb[it]]==w+1){
            dis[matchb[it]]=-1;
            if(dfs(matchb[it],w+1)){
                matchb[it]=nodo;
                matcha[nodo]=it;
                return true;
            }
        }
    }
    return false;
}

bool check(int x){
    memset(matcha,0,sizeof(matcha));
    memset(matchb,0,sizeof(matchb));
    unmatch.clear();
    for(int i=1;i<=n;i++)unmatch.pb(i);
    G.assign(n+1,vi());
    int cant=0;
    for(int i=0;i<m;i++){
        int a=E[i].F,b=E[i].S.F,c=E[i].S.S;
        if(c<=x){
            G[a].pb(b);
        }
    }
    //ya esta creado el grafito
    while(bfs()){
        //cout<<"lo nuestro se rompio y rompi la foto"<<endl;
        for(int i=0;i<unmatch.size();i++){
            if(dfs(unmatch[i],1)){
                swap(unmatch[i],unmatch.back());
                unmatch.pop_back();
                cant++;

            }     
        }
    }
    return cant==n;    
}
int main()
{

    fast
    int a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        E.pb({a,{b,c}});
    }
    b=1;
    int e=1e9,res=-1;
    while(b<=e){
        int mid=(b+e)/2;
        if(check(mid)){
            e=mid-1;
            res=mid;
        }else{
            b=mid+1;
        }
    }
    cout<<res<<endl;
    
    return 0;
}
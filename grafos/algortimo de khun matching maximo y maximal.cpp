#include<bits/stdc++.h>
//#include <chrono>
//#include <thread>
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
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//algoritmo de khun para grafos bipartitos  O(nm)
const int tam=100;
vi G[tam];
bool vis[tam];
int pareja[tam];
bool dfs(int nodo){
    if(vis[nodo])return false;
    vis[nodo]=1;
    for(auto it : G[nodo]){
        if(pareja[it]==-1){//llego a un nodo si emparejar
            pareja[it]=nodo;
            return true;
        }
        if(dfs(pareja[it])){
            pareja[it]=nodo;//cambio de color rojo con azul 
            return true;
        }
    }
    return false;
}
int main()
{
    int m,a,b;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;//de izquierda a derecha
        G[a].pb(b);
    }
    memset(pareja,-1,sizeof(pareja));
    int res=0;
    for(int i=0;i<4;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i))res++;
    }
    cout<<res<<endl;
    
    
    
    return 0;
}

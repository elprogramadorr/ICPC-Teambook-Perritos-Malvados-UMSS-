#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int tam=100005;
int sz[tam],color[tam],cant[tam];
vi G[tam],vec[tam];
ll res[tam],out[tam];
int n,a,b;
void init(int nodo, int ant){
    sz[nodo]=1;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        init(it,nodo);
        sz[nodo]+=sz[it];
    }
}

void update(int &mayorcant, int nodo, int x){//x quito o pongo
    res[cant[color[nodo]]]-=color[nodo];
    cant[color[nodo]]+=x;
    res[cant[color[nodo]]]+=color[nodo];
    mayorcant=max(mayorcant,cant[color[nodo]]);
}
int dfs(int nodo, int ant, bool es){//devuelvo el mayor
    int gordo=-1;
    int mx=-1;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        if(sz[it]>mx){
            mx=sz[it];
            gordo=it;
        }
    }
    for(auto it : G[nodo]){
        if(it==ant)continue;
        if(it!=gordo)dfs(it,nodo,0);
    }
    int mayorcant=0;
    if(gordo!=-1){
        mayorcant=dfs(gordo,nodo,1);
        swap(vec[nodo],vec[gordo]);
    }
    vec[nodo].pb(nodo);
    update(mayorcant,nodo,1);
    for(auto it : G[nodo]){
        if(it==ant)continue;
        for(auto hijo : vec[it]){
            update(mayorcant,hijo,1);
            vec[nodo].pb(hijo);
        }
    }
    out[nodo]=res[mayorcant];
    if(es==false){
        for(auto hijo : vec[nodo]){
            update(mayorcant,hijo,-1);
        }
    }
    return mayorcant;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>color[i];
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    init(1,-1);
    dfs(1,-1,0);
    for(int i=1;i<=n;i++){
        cout<<out[i]<<" "; 
    }
    return 0;
}
//me permite calcular cuantos nodos cumplen cierta propiedad en subarbol
//O(nlogn)
//en este calculo el color mas recurrente en cada subarbol y sumo los colores maximos
//https://codeforces.com/contest/600/problem/E

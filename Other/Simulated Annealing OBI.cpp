#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
#include <ctime>
#include <random>
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define int long long
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi G;
int n,m;
vi resi;
int costo(vi &curr){
    resi.clear();
    vi Gcurr=G;
    vi nuevo;
    int precio=0;
    vi noAportan;
    for(auto it : curr){
        bool completo=true;
        for(int l=1;l<=n;l++){
            int cant=__builtin_popcountll(Gcurr[l]);
            if(cant<n-1){
                completo=false;
                break;
            }
        }
        if(completo){
            nuevo.pb(it);
            continue;
        }
        // it presenta sus amigos a todos sus amigos
        bool sirve=false;
        for(int l=1;l<=n;l++){
            if((1<<l)&Gcurr[it]){
                // entonces l es amigo de it
                if((Gcurr[l]|Gcurr[it])!=Gcurr[l]){
                    // entonces it aporta
                    sirve=true;
                }
                Gcurr[l]|=Gcurr[it];
            }
        }
        if(sirve){
            nuevo.pb(it);
            resi.pb(it);
            precio++;
        }else{
            noAportan.pb(it);
        }       
    }
    for(auto it : noAportan){
        nuevo.pb(it);
    }
    curr=nuevo;
    return precio;
}

signed main(){
    fastIO;
    cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    G.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a]|=(1<<b);
        G[b]|=(1<<a);
    }
    // una respuesta es un permutacion
    vi pref;
    for(int i=1;i<=n;i++)pref.pb(i);
    shuffle(pref.begin(),pref.end(),rng);
    int res=costo(pref);
    vi respuesta=resi;
    double tempereatura=1e6;
    while(clock() / (double) CLOCKS_PER_SEC <= 0.975749){
        int a=uniform_int_distribution<int>(0,n-1)(rng);
        int b=uniform_int_distribution<int>(0,n-2)(rng);
        if(a==b){
            b++;
            if(b==n)b=0;
        }
        vi next=pref;
        swap(next[a],next[b]);// funcion vecino
        int nextCosto=costo(next);
        if(nextCosto<res){
            res=nextCosto;
            respuesta=resi;
            pref=next;        
        }else{
            double proba=exp((res-nextCosto)/tempereatura);
            double r=uniform_real_distribution<double>(0,1)(rng);
            if(r<proba){
                res=nextCosto;
                respuesta=resi;
                pref=next;
            }
        }
        tempereatura*=0.9999;
    }

    cout<<res<<endl;
    for(auto it : respuesta)cout<<it<<" ";
    return 0;
}

// Cuando quieran minimizar o maximizar algo(permutacion, subsequncias, etc)

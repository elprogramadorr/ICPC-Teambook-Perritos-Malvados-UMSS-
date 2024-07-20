#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define jumanji ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
using namespace std;
const int tam=100005;
ll pref[tam];
ll res[tam];
int tami;
vector<pair<pair<int,int>,int> >Q;//{{izq,der},id}

bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.F.F/tami!=b.F.F/tami){
        return a.F.F/tami<b.F.F/tami;
    }
    return a.F.S<b.F.S;
}
int main(){
    jumanji
    int n,q,x,izq,der,k;
    cin>>n>>k;
    tami=sqrt(n)+1;
    for(int i=1;i<=n;i++){
        cin>>pref[i];
    }
    int y;
    for(int i=1;i<=n;i++){
        cin>>y;
        x=pref[i];
        pref[i]=y;
        if(x==2){
            pref[i]*=-1;
        }
        pref[i]+=pref[i-1];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>izq>>der;
        izq--;
        Q.pb({{izq,der},i});
    }
    sort(Q.begin(),Q.end(),comp);
    unordered_map<ll,int>cant;
    int L=0,R=-1;
    ll respuesta=0;
    for(int i=0;i<q;i++){
        int izq=Q[i].F.F;
        int der=Q[i].F.S;
        int ind=Q[i].S;
        while(L>izq){
            respuesta+=cant[pref[L-1]+k];
            cant[pref[L-1]]++;
            L--;
        }
        while(R<der){
            respuesta+=cant[pref[R+1]-k];
            cant[pref[R+1]]++;
            R++;
        }
        while(R>der){
            cant[pref[R]]--;
            respuesta-=cant[pref[R]-k];
            R--;
        }
        while(L<izq){
            cant[pref[L]]--;
            respuesta-=cant[pref[L]+k];
            L++;
        }
        res[ind]=respuesta;
    }
    for(int i=1;i<=q;i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}  

// https://codeforces.com/contest/877/problem/F
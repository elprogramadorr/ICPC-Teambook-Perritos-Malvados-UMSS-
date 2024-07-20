#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define jumanji ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
using namespace std;
//heavy light decomposition
const int tam=200005;
int v[tam];
int bigchild[tam],padre[tam],depth[tam];
int sz[tam],id[tam],tp[tam];
int T[4*tam];
vi G[tam];
int n;
int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, T[lo++]);
		if (hi & 1) rb = max(rb, T[--hi]);
	}
	return max(ra, rb);
}
void update(int idx, int val) {
	T[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) T[idx] = max(T[2 * idx], T[2 * idx + 1]);
}
void dfs_size(int nodo, int ant){
    sz[nodo]=1;
    int big=-1;
    int who=-1;
    padre[nodo]=ant;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        depth[it]=depth[nodo]+1;
        dfs_size(it,nodo);
        sz[nodo]+=sz[it];
        if(sz[it]>big){
            big=sz[it];
            who=it;
        }
    }
    bigchild[nodo]=who;
}
int num=0;
void dfs_hld(int nodo, int ant, int top){
    id[nodo]=num++;
    tp[nodo]=top;
    if(bigchild[nodo]!=-1){
        dfs_hld(bigchild[nodo],nodo,top);
    }
    for(auto it : G[nodo]){
        if(it==ant || it==bigchild[nodo])continue;
        dfs_hld(it,nodo,it);
    }
}
int queryPath(int a, int b){
    int res=0;
    while(tp[a]!=tp[b]){
        if(depth[tp[a]]<depth[tp[b]])swap(a,b);
        res=max(res,query(id[tp[a]],id[a]));
        a=padre[tp[a]];
    }
    if(depth[a]>depth[b])swap(a,b);
    res=max(res,query(id[a],id[b]));
    return res;
}
int main()
{
    jumanji
    int c,q,a,b;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs_size(1,0);
    dfs_hld(1,0,1);
    for(int i=1;i<=n;i++){
        update(id[i],v[i]);
    }
    while(q--){
        cin>>c;
        cin>>a>>b;
        if(c==1){
            update(id[a],b);
        }else{
            printf("%d ", queryPath(a,b));
        }
    }
    return 0;
}  

// hallar maximo en un camino con updates
// https://cses.fi/problemset/task/2134/
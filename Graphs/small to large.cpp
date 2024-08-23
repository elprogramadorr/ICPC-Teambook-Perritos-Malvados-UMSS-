const int tam=200005;
int a[tam];
vi G[tam];
int f[tam];
set<int> F[tam];
//small to large dfs
void _find(int nodo, int ant){
    f[nodo]=a[nodo];
    if(ant!=-1)f[nodo]^=f[ant];
    for(auto it : G[nodo]){
        if(it!=ant){
            _find(it,nodo);
        }
    }
}
int res=0;
void dfs(int nodo, int ant){
    bool flag=false;
    F[nodo].insert(f[nodo]);
    for(auto it : G[nodo]){
        if(it==ant)continue;
        dfs(it,nodo);
        if(sz(F[nodo])<sz(F[it]))swap(F[nodo],F[it]);
        for(auto it2 : F[it]){
            if(F[nodo].count(a[nodo] ^ it2))flag=true;
        }
        for(auto it2 : F[it]){
            F[nodo].insert(it2);
        }
        F[it].clear();
    }
    if(flag){
        res++;
        F[nodo].clear();
    }
}
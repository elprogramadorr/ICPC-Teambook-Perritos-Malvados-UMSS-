const int tam=200005;
int depth[tam];
int dp[20][tam];
vi G[tam];
int n;
 
void dfs(int nodo, int ant, int d){
    depth[nodo]=d;
    dp[0][nodo]=ant;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        dfs(it,nodo,d+1);
    }
}
 
void initLCA(){
    memset(dp,-1,sizeof(dp));
    dfs(1,-1,0);
    for(int i=1;i<20;i++){
        for(int v=1;v<=n;v++){
            if(dp[i-1][v]!=-1){
                dp[i][v]=dp[i-1][dp[i-1][v]];
            }
        }
    }
}
 
int LCA(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    int dif=depth[b]-depth[a];
    for(int i=19;i>=0;i--){
        if(dif&(1<<i))b=dp[i][b];
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    }
    return dp[0][a];
}

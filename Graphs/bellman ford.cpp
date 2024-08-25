const ll INF=1e16;
vector<vll>G;
vector<bool>vis;
void dfs(ll u){
    vis[u]=true;
    for(auto it : G[u]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main()
{
    
    return 0;
}
// la vida es dura pero mas dura mi verdura
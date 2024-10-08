vector<vi> G;
vi vis, arc;
vector<bool> check;
int num=0;
void dfs(int nodo, int ant){
  num++;
  vis[nodo]=arc[nodo]=num;
  int hijos=0;
  for(auto it : G[nodo]){
    if(ant==it)continue;
    if(vis[it]){
      // si ya fue visitado entonces es un puente hacia "atras"
      arc[nodo]=min(arc[nodo],vis[it]);
    }else{
      hijos++;
      dfs(it,nodo);
      arc[nodo]=min(arc[nodo],arc[it]);// para ver si su padre de nodo es punto, por la pila recursiva
      if(ant!=-1 && arc[it]>=vis[nodo]){
        // entra al if si el puente mayor esta debajo del nodo
        check[nodo]=1;
      }
    }
  }
  if(ant==-1 && hijos>1){
    // esto no cuenta los vecinos, si no los "subconjuntos" que une la raiz
    check[nodo]=1;
  }
}
int main()
{
  int n, m, a, b;
  cin >> n >> m;
  arc.resize(n+1); vis.resize(n+1);
  check.assign(n+1, false);
  G.assign(n+1, vi());
  for(int i=0; i<m; i++){
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }
  dfs(1, -1);
  for(int i=1; i<=n; i++){
    cout << check[i] << " ";
  }
  return 0;
}

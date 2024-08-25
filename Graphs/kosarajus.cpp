const int tam = 200005;
vi G[tam], G1[tam];
vector<bool> vis;
vi v;
int scc = 0;

void dfs0(int nodo) {
  vis[nodo] = 1;
  for (auto it : G[nodo]) {
    if (!vis[it]) dfs0(it);
  }
  v.pb(nodo);
}

void dfs1(int nodo) {
  vis[nodo] = 1;
  for (auto it : G1[nodo]) {
    if (!vis[it]) dfs1(it);
  }
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a].pb(b);
    G1[b].pb(a);
  }
  vis.assign(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs0(i);   
  }
  reverse(v.begin(), v.end());
  vis.assign(n + 1, false);
  for (int i = 0; i < n; i++) {
    if (!vis[v[i]]) {
      scc++;
      dfs1(v[i]);
    }
  }    
  return 0;
}

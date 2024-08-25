// index-1
#define pii pair<int, int>
#define pid pair<int, double>
#define endl '\n'
#define x first
#define y second
#define que priority_queue<int, vector<int>, greater<int>>

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, R, dn, dfn[N], mi[21][N];
vector<int> e[N];

int get(int x, int y) {
  return (dfn[x] < dfn[y] ? x : y);
}

void dfs(int id, int f) {
  mi[0][dfn[id] = ++dn] = f;
  for (auto it : e[id])
    if (it != f)
      dfs(it, id);
}

int lca(int u, int v) {
  if (u == v) return u;
  if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
  int d = __lg(v - u++);
  return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}

void solve() {
  cin >> n >> m;
  R = 1;
  for (int i = 2; i <= n; i++) {
    int u; cin >> u;
    u++;
    e[u].emplace_back(i);
    e[i].emplace_back(u);
  }
  dfs(R, 0);
  for (int i = 1; i <= __lg(n); i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i) - 1]);
    }
  }

  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    u++, v++;
    int ans = lca(u, v) - 1;
    cout << ans << endl;
  }
}

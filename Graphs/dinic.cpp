/*
O(V^2 * E)
O(E * sqrt(V)) para unit capacity

Nota.- cuando te pide algo como que la suma no sean primos, se modela como grafo bipartito de (pares,impares)
*/

struct edge {
  int v, cap, inv, flow;
};

struct Dinic {
  int n, s, t;
  vector<int> lvl;
  vector<vector<edge>> g;

  Dinic(int n) : n(n), lvl(n), g(n) {}

  void add_edge(int u, int v, int c) {
    g[u].push_back({v, c, (int)g[v].size(), 0});
    g[v].push_back({u, 0, (int)g[u].size() - 1, 0});
  }

  bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<int> q;
    lvl[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto& e : g[u]) {
        if (e.cap > 0 && lvl[e.v] == -1) {
          lvl[e.v] = lvl[u] + 1;
          q.push(e.v);
        }
      }
    }
    return lvl[t] != -1;
  }

  int dfs(int u, int nf) {
    if (u == t) return nf;
    int res = 0;
    for (auto& e : g[u]) {
      if (e.cap > 0 && lvl[e.v] == lvl[u] + 1) {
        int tf = dfs(e.v, min(nf, e.cap));
        if (tf > 0) {
          e.cap -= tf;
          g[e.v][e.inv].cap += tf;
          e.flow += tf;
          g[e.v][e.inv].flow -= tf;
          res += tf;
          nf -= tf;
          if (nf == 0) break;
        }
      }
    }
    return res > 0 ? res : (lvl[u] = -1, 0);
  }

  int max_flow(int so, int si) {
    s = so; t = si;
    int res = 0;
    while (bfs()) res += dfs(s, INT_MAX);
    return res;
  }

  vector<pair<int, int>> min_cut() {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto& e : g[u]) {
        if (e.cap > 0 && !vis[e.v]) {
          vis[e.v] = true;
          q.push(e.v);
        }
      }
    }

    vector<pair<int, int>> res;
    for (int u = 0; u < n; u++) {
      if (vis[u]) {
        for (auto& e : g[u]) {
          if (!vis[e.v] && e.flow > 0) {
            // res.push_back({u, e.v}); corto entre (u, e.v)
            // puedes añadir un indice al struct edge para saber el indice de arista e.ind
          }
        }
      }
    }
    return res;
  }

  vi minimum_vertex_cover(vi &left_nodes, vi &right_nodes) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto& e : g[u]) {
        if (e.cap > 0 && !vis[e.v]) {
          vis[e.v] = true;
          q.push(e.v);
        }
      }
    }

    vi res;
    for (int u : left_nodes) if (!vis[u]) res.push_back(u); // Left side vertices not reachable
    for (int u : right_nodes) if (vis[u]) res.push_back(u); // Right side vertices reachable
    return res;
  }
};

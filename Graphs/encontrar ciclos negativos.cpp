const ll INF = 1e16;

int main() {
  ll n, m, a, b, w;
  cin >> n >> m;
  vector<pair<ll, pair<ll, ll> > > E;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    E.pb({a, {b, w}});
  }
  vll dis(n + 1, INF);
  dis[1] = 0;
  bool ok;
  vi p(n + 1, -1);
  int in = 0;
  for (int i = 0; i < n; i++) {
    ok = true;
    for (int l = 0; l < m; l++) {
      int a = E[l].F, b = E[l].S.F;
      w = E[l].S.S;
      if (dis[b] > dis[a] + w) {
        ok = false;
        dis[b] = dis[a] + w;
        p[b] = a;
        in = b;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    in = p[in];
  }
  // Este for para encontrar un ciclo porque tal vez estoy en la rama
  if (ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    vi res;
    int u = in;
    while (1) {
      if (u == in && res.size() > 1) break;
      res.pb(u);
      u = p[u];
    }
    res.pb(in);
    for (int i = res.size() - 1; i >= 0; i--) {
      cout << res[i] << " ";
    }
  }
  return 0;
}

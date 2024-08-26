// algoritmo de khun para grafos bipartitos  O(nm)
const int tam = 100;
vi G[tam]; // pueden tener mismo indices nodos de distintos grupos
bool vis[tam];
int pareja[tam];// pareja de los nodos de la derecha

bool khun(int nodo) {
  if (vis[nodo]) return false;
  vis[nodo] = 1;
  for (auto it : G[nodo]) {
    if (pareja[it] == -1 || khun(pareja[it])) {
      pareja[it] = nodo;
      return true;
    }
  }
  return false;
}

int main() {
  int m, a, b;  
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b; // de izquierda a derecha
    G[a].pb(b);
  }
  memset(pareja, -1, sizeof(pareja));
  int match = 0;
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis)); // no olvidar
    if (khun(i)) match++; // camino aumentante
  }
  return 0;
}

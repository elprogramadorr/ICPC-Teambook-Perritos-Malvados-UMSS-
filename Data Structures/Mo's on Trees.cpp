// Si en el rango un nodo aparece dos veces entonces no se toma en cuenta (se cancela)
// Para una query en camino [u,v], IN[u]<=IN[v]
// Si LCA(u,v) = u -> Rango Query [IN[u],IN[v]]
// Si No -> Rango Query [OUT[u],IN[v]] + [IN[LCA],IN[LCA]] (o sea falta considerar el LCA)
 
// Cuando las consultas son sobre las aristas
// Si LCA(u,v) = u -> Rango Query [IN[u]+1,IN[v]]
// Si No -> Rango Query [OUT[u],IN[v]]

const int tam = 100005;
vector<pair<int, int>> G[tam];
int dp[20][tam];// esto para LCA
int tiempo = -1;
int IN[tam];// tiempo de entrada
int OUT[tam];// tiempo de salida
int A[3*tam];// los nodos en orden del dfs
int depth[tam];
int valor[tam];// valor del nodo/arista

void dfs(int nodo, int ant, int llega, int d) {
    depth[nodo] = d+1;
    dp[0][nodo] = ant;
    valor[nodo] = llega;
    IN[nodo] = ++tiempo;
    A[IN[nodo]] = nodo;
    for (auto it : G[nodo]) {
        int v = it.first;
        int val = it.second;
        if (v == ant) continue;
        dfs(v, nodo, val, d+1);
    }
    OUT[nodo] = ++tiempo;
    A[OUT[nodo]] = nodo;
}

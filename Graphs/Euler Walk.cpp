/*
La entrada es un vector (dest, index global de la arista) en dirigidos 
para grafos no dirigidos las aristas de ida y vuelta tienen el mismo index global.
Retorna un vector de nodos en el Eulerian path/cycle
con src como nodo inicial. Si no hay solucion, retorna un vector vacio.

Para obtener indices de aristas, anhadir .second a s y ret o usar mapa.
Para ver si existe respuesta, ver si ret.size() == nedges + 1
Para ver si existe camino euleriano con (start, end) tambien ver si ans.back() == end 

Un grafo dirigido tiene un camino euleriano si:

Tiene exactamente un vertice con outDegree - inDegree = 1
Tiene exactamente un vertice con inDegree - outDegree = 1
Todos los demas vertices tienen inDegree = outDegree
El recorrido empieza en el vertice con outDegree - inDegree = 1 
Correr desde este nodo y no necesito verficar lo demas (si no hay tal nodo correr desde uno con grado de salida > 0)

Nota.- Volverlo global D,its,eu si corres varias veces (para cada componente conexa)
Time complexity: O(V + E)
*/
vi eulerWalk(vector<vector<pii>> &gr, int nedges, int src = 1) {
  int n = gr.size();
  vi D(n), its(n), eu(nedges), ret, s = {src}; // cambiar eu a mapa<int,bool> si las aristas no son [0,nedges]
  D[src]++; // para permitir Euler Paths, no solo ciclos
  while (!s.empty()) {
    int x = s.back(), y, e, &it = its[x], end = gr[x].size();
    if (it == end) {
      ret.pb(x);
      s.pop_back();
      continue;
    }
    tie(y, e) = gr[x][it++];
    if (!eu[e]) {
      D[x]--, D[y]++;
      s.pb(y);
      eu[e] = 1;
    }
  }
  for (int x : D) if (x < 0 || ret.size() != nedges + 1) return {};
  return {ret.rbegin(), ret.rend()};
}

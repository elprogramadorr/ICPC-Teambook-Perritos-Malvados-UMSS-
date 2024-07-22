/*
La entrada es un vector (dest, index global de la arista), para grafos no dirigidos
las aristas de ida y vuelta tienen el mismo index global. Reorna un vector de nodos en el Eulerian path/cycle
con src como nodo inicial. Si no hay solucion, retorna un vector vacio.

Para obtener indices de aristas, añadir .second a s y ret o usar mapa.
Para ver si existe respuesta, ver si ret.size() == nedges + 1
Para ver si existe camino euleriano con (start, end) también ver si ans.back() == end 

Un grafo dirigido tiene un camino euleriano si:

Tiene exactamente un vértice con out-degree − in-degree = 1
Tiene exactamente un vértice con in-degree − out-degree = 1
Todos los demás vértices tienen in-degree = out-degree
El recorrido empieza en el vértice con out-degree − in-degree = 1 
Correr desde este nodo y no necesito verficar lo demás (si no hay tal nodo correr desde uno con grado de salida > 0)

Time complexity: O(V + E)
*/
vi eulerWalk(vector<vector<pii>> &gr, int nedges, int src = 1){
    int n = gr.size();
    vi D(n), its(n), eu(nedges), ret, s = {src};
    D[src]++; // para permitir Euler Paths, no solo ciclos
    while (!s.empty()){
        int x = s.back(), y, e, &it = its[x], end = gr[x].size();
        if (it == end){
            ret.pb(x);
            s.pop_back();
            continue;
        }
        tie(y, e) = gr[x][it++];
        if (!eu[e]){
            D[x]--, D[y]++;
            s.pb(y);
            eu[e] = 1;
        }
    }
    for(int x : D) if(x < 0 || ret.size() != nedges + 1) return {};
    return {ret.rbegin(), ret.rend()};
}
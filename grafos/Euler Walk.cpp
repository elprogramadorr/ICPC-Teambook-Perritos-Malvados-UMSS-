#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
using namespace std;
vector<vector<pii>> G;
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
vector<pair<int,int>> eulerWalk(vector<vector<pii>> &gr, int nedges, int src = 1){
    int n = gr.size();
    vi D(n), its(n), eu(nedges); 
    vector<pair<int,int>> s = {{src, -1}};
    vector<pair<int,int>> ret;
    D[src]++; // para permitir Euler Paths, no solo ciclos
    while (!s.empty()){
        int x = s.back().first, y, e, &it = its[x], end = gr[x].size();
        if (it == end){
            ret.pb(s.back());
            s.pop_back();
            continue;
        }
        tie(y, e) = gr[x][it++];
        if (!eu[e]){
            D[x]--, D[y]++;
            s.emplace_back(y, e);
            eu[e] = 1;
        }
    }
    for(int x : D) if(x < 0 || ret.size() != nedges + 1) return {};
    return {ret.rbegin(), ret.rend()};
}
int main(){
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        G.resize(n+1);
        vi deg(n+1,0);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
            G[a].pb({b,i});
        }
        int start=-1;
        int cant=0;
        for(int i=0;i<n;i++){
            if(deg[i]&1){
                cant++;
                start=i;
            }
        }
        
        vector<pair<int,int>> ans=eulerWalk(G,m,2);
        if(ans.size()==m+1){
            cout<<"Yes"<<"\n";
            for(auto x:ans){
                cout<<x.first<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"No"<<"\n";
        }

        
        
    }
    return 0;
}

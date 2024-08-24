// si es grafo con aristas multiples (a,b) , (a,b)
// entonces usar una mapa de pares y si una arista aparece dos veces no puede ser puente
const int tam=2e5+5;
set<pair<int, int>> st; // puente arista entre (a, b)
vi G[tam];
int arc[tam], IN[tam];
int tiempo=0;
void dfs(int nodo, int ant){
  tiempo++;
  IN[nodo] = arc[nodo] = tiempo;
  for(auto it : G[nodo]){
    if(it == ant) continue;
    if(IN[it]){
      arc[nodo] = min(arc[nodo], IN[it]);
    } else {
      dfs(it, nodo);
      arc[nodo] = min(arc[nodo], arc[it]);
      if(arc[it] > IN[nodo]){
        st.insert({nodo, it});
      }
    }
  }
}

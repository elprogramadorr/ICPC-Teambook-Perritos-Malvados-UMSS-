// solo funciona para undirected
void dfs(int nodo, int ant){
  id[nodo]=nodo;
  for(auto it : G[nodo]){
    if(it==ant)continue;
    if(id[it]){
      if(id[it]==it){
        id[nodo]=it;
      }
    }else{
      dfs(it,nodo);
      if(id[it]!=it)id[nodo]=id[it];
    }
  }
}
// Notas.- Cuando formo el suffix tree inverso
// cuando quiero ver cuantas veces aparece un nodo en un string s, entonces hago caminar en el aho corasick y en cada paso chequedar suffix links si llegan
// a veces se puede armar el suffix tree y luego con euler tour y st puedo ver cuantas veces se toco este nodo

struct vertex {
  map<char,int> next,go;
  int p,link;
  char pch;
  vector<int> leaf; // se puede cambiar por int, en ese caso int leaf y leaf(0) en constructor
  vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
  t.clear();t.pb(vertex());
}
void add_string(string s, int id){
  int v=0;
  for(char c:s){
    if(!t[v].next.count(c)){
      t[v].next[c]=t.size();
      t.pb(vertex(v,c));
    }
    v=t[v].next[c];
  }
  t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
  if(t[v].link<0)
    if(!v||!t[v].p)t[v].link=0;
    else t[v].link=go(get_link(t[v].p),t[v].pch);
  return t[v].link;
}
int go(int v, char c){
  if(!t[v].go.count(c))
    if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
    else t[v].go[c]=v==0?0:go(get_link(v),c);
  return t[v].go[c];
}

const int tam=500005;
int P[tam];
int sz[tam];
stack<int> st; 
int scc;
int _find(int x) {
	while(P[x]!=x)x=P[x];
	return x; 
}
void _union(int u, int v) {
	u=_find(u);v=_find(v); 
	if(u==v)return;
	if(sz[u]>sz[v])swap(u,v); 
	P[u]=v; 
	sz[v]+=sz[u];
	scc--; 
	st.push(u); 
}
void rollback(int t) {
	while(st.size()>t) {
		int u=st.top();st.pop(); 
		sz[P[u]]-=sz[u]; 
		P[u]=u;scc++;
	}
}
// para sacar checkpoint int CP = st.size()
// para rollback rollback(CP)
// al inicio scc=n y sz[i]=1
// https://codeforces.com/problemset/problem/891/C

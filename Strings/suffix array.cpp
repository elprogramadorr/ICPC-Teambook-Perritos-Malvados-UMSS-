#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define S second
#define F first
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct SuffixArray{
    string s;
    vi sa,lcp,rank;
    void init(int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim));
        rank.resize(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
    } 
	int st[(1<<20)][20];// ojo con esto al testear	
	void initST(){
		int n = sz(lcp);
		for(int i=0;i<n;i++)st[i][0] = lcp[i];
		for(int j=0;j<20;j++){
			for(int i=0;i+(1<<j)<=n;i++){
				st[i][j+1] = min(st[i][j],st[i+(1<<j)][j]);
			}
		}
	}
	int RMQ(int izq, int der){
		int k = 31 - __builtin_clz(der-izq+1);
		return min(st[izq][k],st[der-(1<<k)+1][k]);
	}
	int getLCP(int izq, int der){
		if(izq==der)return sz(s)-izq;
		izq=rank[izq],der=rank[der];
		if(izq>der)swap(izq,der);
		return RMQ(izq+1,der);
	}
};
// compare substring A and B
bool cmp(pair<int,int>A, pair<int,int> B){
	int Q=SA.getLCP(A.first,B.first);
	if(Q>=min(A.S-A.F+1,B.S-B.F+1)){
		if(A.S-A.F==B.S-B.F)return A.F<B.F;
		return A.S-A.F<B.S-B.F;
	}
	return SA.rank[A.F]<SA.rank[B.F];
}
//      012345  6
//      ababba  #
// sa   = 6 5 0 2 4 1 3
// lcp  = 0 0 1 2 0 2 1
// rank = 2 5 3 6 4 1    posicion del sufixx i en el sa
// lcp[i] = lcp(sa[i],sa[i-1])
signed main(){
    string s;
    cin>>s;
    SuffixArray sa;
    sa.s=s;
    sa.init();
    return 0;
}

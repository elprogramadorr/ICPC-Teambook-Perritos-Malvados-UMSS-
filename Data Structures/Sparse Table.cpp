// Time complexity: O(n log n)
int ST[20][500005];// log2(MAXN) = 20
void init(vi &a){
	int n = a.size();
	for(int i=0;i<n;i++) ST[0][i] = a[i];
	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j+(1<<i)<=n;j++){
			ST[i][j] = min(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
		}
	}
}
// index-0
int query(int l, int r){
	int len = r-l+1;
	int pot = __lg(len);
	return min(ST[pot][l],ST[pot][r-(1<<pot)+1]);
}

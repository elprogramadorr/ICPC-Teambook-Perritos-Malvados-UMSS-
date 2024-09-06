const int alpha = 400; 
struct suffix_array { // s MUST not have 0 value
  vector<int> sa, rank, lcp;
  suffix_array(string s) {
    s.push_back('$'); // always add something less to input, so it stays in pos 0
    int n = s.size(), mx = max(alpha, n)+2;
    vector<int> a(n), a1(n), c(n+1), c1(n+1), head(mx), cnt(mx);
    rank = lcp = a;
    for(int i = 0; i < n; i++) c[i] = s[i], a[i] = i, cnt[ c[i] ]++;
    for(int i = 0; i < mx-1; i++) head[i+1] = head[i] + cnt[i];
    for(int k = 0; k < n; k = max(1ll, k<<1)) {
      for(int i = 0; i < n; i++) {
        int j = (a[i] - k + n) % n;
        a1[ head[ c[j] ]++ ] = j;
      }
      swap(a1, a);
      for(int i = 0, x = a[0], y, col = 0; i < n; i++, x = a[i], y = a[i-1]) {
        c1[x] = (i && c[x] == c[y] && c[x+k] == c[y+k]) ? col : ++col;
        if(!i || c1[x] != c1[y]) head[col] = i;
      }
      swap(c1, c);
      if(c[ a[n-1] ] == n) break;
    }
    swap(sa, a);
    for(int i = 0; i < n; i++) rank[ sa[i] ] = i;
    for(int i = 0, k = 0, j; i < n; lcp[ rank[i++] ] = k) { /// lcp[i, i+1]
      if(rank[i] == n-1) continue;
      for(k = max(0ll, k-1), j = sa[ rank[i]+1 ]; s[i+k] == s[j+k]; k++);
    }
  }
  int& operator[] ( int i ){ return sa[i]; }
};

//      012345  6
//      ababba  $
//      5. a
//      0. ababba
//      2. abba
//      4. ba
//      1. babba
//      3. bba
// sa   = 5 0 2 4 1 3
// lcp  = 0 1 2 0 2 1 0
// rank = 2 5 3 6 4 1 0   posicion del sufixx i en el sa
// lcp[i] = lcp(sa[i],sa[i-1])

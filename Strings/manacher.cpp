// f = 1 para pares, 0 impar
//a a a a a a
//1 2 3 3 2 1   f = 0 impar
//0 1 2 3 2 1   f = 1 par
void manacher(string &s, int f, vi &d){
    int l=0, r=-1, n=s.size();
    d.assign(n,0);
    for(int i=0; i<n; i++){
        int k=(i>r? (1-f) : min(d[l+r-i+ f], r-i+f)) + f;
        while(i+k-f<n && i-k>=0 && s[i+k-f]==s[i-k]) ++k;
        d[i] = k - f; --k;
        if(i+k-f > r) l=i-k, r=i+k-f;
    }
}

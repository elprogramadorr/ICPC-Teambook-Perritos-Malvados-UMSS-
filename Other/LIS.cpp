int LIS(vi &a){
    vi v;
    for(int i=0;i<a.size();i++){
        auto it = lower_bound(v.begin(),v.end(),a[i]); // cambiar a upper_bound para LNDS
        if(it==v.end()){
            v.pb(a[i]); // v.size() es LIS que termina en a[i]
        }else{
            *it = a[i]; // it-v.begin()+1 es LIS que termina en a[i]
        } 
    }
    return v.size();
}

// retornar los indices del LIS (index-0)
vi LIS2(vi v) {
    int n = v.size();
    vi dp; dp.pb(-1e9);
    vi curr(n);
    for (int i = 0; i < n; i++) {
        int izq = 0, der = dp.size() - 1;
        int pos = dp.size(); // Posición por defecto es al final
        while (izq <= der) {
            int mid = (izq + der)/2;
            if (dp[mid] >= v[i]) { // LNDS if(dp[mid]<=v[i])
                pos = mid; // LNDS pos = mid + 1;
                der = mid - 1; // LNDS izq = mid + 1;
            } else {
                izq = mid + 1; // LNDS der = mid - 1;
            }
        }
        curr[i] = pos;
        if (pos == dp.size()) {
            dp.push_back(v[i]);
        } else {
            dp[pos] = v[i];
        }
    }
    vi ans;
    int x=dp.size()-1;
    for (int i = n - 1; i >= 0; i--) {
        if (curr[i] == x) {
            ans.pb(i);
            x--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

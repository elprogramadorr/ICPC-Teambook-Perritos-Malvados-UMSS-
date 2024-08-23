for (int i = 1; i <= n; i++) {
    cin>>valor[i];
    ind.pb(valor[i]);
}   
sort(ind.begin(), ind.end());
for (int i = 1; i <= n; i++) {
    valor[i] = lower_bound(ind.begin(), ind.end(), valor[i]) - ind.begin() + 1;
}

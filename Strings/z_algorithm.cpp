// TIme: O(|s|)
// Maximum length of a substring that begins at position i and is a prefix of the string.
// a b a a b c a
// 0 0 1 2 0 0 1
vi z_function(string s){
    int n=s.size();
    vi z(n);
    int x=0,y=0;
    for(int i=1;i<n;i++){
        z[i]=max(0ll,min(z[i-x],y-i+1));
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            x=i;
            y=i+z[i];
            z[i]++;
        }
    }
    return z;
}

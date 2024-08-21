
const int tam=8005;
const ll INF=1e17;
ll locura[tam];
ll pref[tam];
ll dp[805][tam];
ll riesgo(int l, int r){
    if(l>r)return 0;
    return (pref[r]-pref[l-1])*(r-l+1); 
}
//solve dp retorna k
ll solvedp(int g,int pos, int izq, int der){
    dp[g][pos]=INF;
    int k;
    for(int i=izq;i<=der;i++){
       ll curr=dp[g-1][i]+riesgo(i+1,pos);
       if(curr<dp[g][pos]){
           dp[g][pos]=curr;
           k=i;
       }
    }
    return k;
}
void solve(int g,int l, int r, int izq, int der){
    if(l>r)return;
    if(l==r){
        solvedp(g,l,izq,der);
        return;
    }
    int mid=(l+r)/2;
    int k=solvedp(g,mid,izq,der);
    solve(g,mid+1,r,k,der);
    solve(g,l,mid-1,izq,k);
}
int main(){
    //puedo aplicar D&C pq la transicion es dp[G][i]=dp[G-1][algo] + C(G,i)
    //la funcion no es decreciente nunca respecto a k
    //algo de G,i <= algo de G,i+1
    int L,G,x;
    cin>>L>>G;
    if(G>L)G=L;
    for(int i=1;i<=L;i++){
        cin>>locura[i];
        pref[i]=pref[i-1]+locura[i];
    }
    for(int i=1;i<=L;i++){
        dp[1][i]=riesgo(1,i);//caso base cuando solo tomo un guardia 
    }
    for(int i=2;i<=G;i++){
        solve(i,1,L,1,L);
    }
    cout<<dp[G][L]<<endl;
    
    return 0;
}
//https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
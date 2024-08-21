#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("popcnt")
const int tam=100005;
ll a[tam];
ll cnt[tam];
const ll INF=1e16;
ll dp[25][tam];//G y pos
ll TOT=0;
int L=1,R;
void add(int x){TOT+=cnt[x]++;}
void del(int x){TOT-=--cnt[x];}
ll query(int l,int r){
	while(L>l) add(a[--L]);
	while(R<r) add(a[++R]);
	while(L<l) del(a[L++]);
	while(R>r) del(a[R--]);
	return TOT;
}
int solvedp(int g,int pos, int izq, int der){
    int k=0;
    dp[g][pos]=INF;
    for(int i=izq;i<=min(der,pos-1);i++){
        ll curr=dp[g-1][i]+query(i+1,pos);
        if(curr<dp[g][pos]){
            dp[g][pos]=curr;
            k=i;
        }
    }
    return k;
}
void solve(int g,int l, int r, int izq, int der){
    if(l>r)return;
    int mid=(l+r)/2;
    int k=solvedp(g,mid,izq,der);
    solve(g,l,mid-1,izq,k);
    solve(g,mid+1,r,k,der);
}
int main(){
    fast
    fast
    ll n,k;
    cin>>n>>k;
    ll acum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        acum+=cnt[a[i]];cnt[a[i]]++;
        dp[1][i]=acum;
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=2;i<=k;i++){
        solve(i,1,n,1,n);
    }
    cout<<dp[k][n]<<endl;

    
    
    return 0;
}
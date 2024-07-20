#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;
//gcd(a,b)= ax + by
//lCB x&-x
//set.erase(it) - ersases the element present at the required index//auto it = s.find(element)
//set.find(element) - iterator pointing to the given element if it is present else return pointer pointing to set.end()
//set.lower_bound(element) - iterator pointing to element greater than or equal to the given element
//set.upper_bound(element) - iterator pointing to element greater than the given element
// | ^
using namespace std;
const int MOD=1e9+7;
const int MAXN=2e5+5;
ll fact[int(2e5+5)];
void init(){
    fact[0]=1;
    for(int i=1;i<int(2e5+5);i++){
        fact[i]=(fact[i-1]%MOD * i % MOD)%MOD;
    }
}
ll fpow(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res % MOD * x % MOD) % MOD;
        x = (x % MOD * x % MOD) % MOD;
        y >>= 1;
    }
    return res;
}
ll inv(ll a)
{
    return fpow(a, MOD - 2);
}
 
ll ncr(int n,int r){
    if(n<r){
        return 0;
    }
    ll ans=fact[n];
    ans=(ans%MOD*inv(fact[n-r])%MOD)%MOD;
    ans=(ans%MOD*inv(fact[r])%MOD)%MOD;
    return ans;
}
int main()
{
    fast
    init();
    ll t,n,k,m,x;
    cin>>t;
    vll cnt;
    while(t--){
        cin>>n>>m>>k;
        cnt.assign(n+5,0);
        for(int i=0;i<n;i++){
            cin>>x;
            cnt[x]++;
        }
        for(int i=1;i<=n;i++){
            cnt[i]+=cnt[i-1];
        }
        ll res=0;
        for(int i=1;i<=n;i++){
            if(!cnt[i])continue;
            ll r=i+k;
            r=min(r,n);
            int have=cnt[r]-cnt[i-1];
            res=(res+ncr(have,m))%MOD;
            have=cnt[r]-cnt[i];
            res=(res-ncr(have,m)+MOD)%MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
// la vida es dura pero mas dura mi verdura



// este precalculando
const int tam=2e5+10;
const int MOD=998244353;
const int N=tam;
ll fac[N], rev[N], revfac[N];

void init(){
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    rev[1] = 1;
    for(int i = 2; i < N; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
    revfac[0] = 1;
    for(int i = 1; i < N; i++) revfac[i] = revfac[i - 1] * rev[i] % MOD;
}
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * revfac[m] % MOD * revfac[n - m] % MOD;
}

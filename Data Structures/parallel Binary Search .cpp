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
//__builtin_popcount(x)
using namespace std;
const int tam=300030;
const ll INF=1e16;
unsigned long long T[2*tam];
ll n,m,k;
vector<vll>G;
ll E[tam];
ll res[tam];
vector<pair<pair<ll,ll>,ll > >Q;//estas son las queries
void update(int pos, int val){
    while(pos<=m){
        T[pos]+=val;
        pos+=(pos&-pos);
    }
}
ll query(ll pos){
   unsigned long long res=0;
   while(pos>0){
       res+=T[pos];
       pos-=(pos&-pos);
   } 
   return res;
}
 
void parallel(ll b,ll e, vll q){
    if(q.size()==0 or e<b)return ;
    ll mid=(b+e)/2;
    //memset(T,0,sizeof T);
    for(int i=b;i<=mid;i++){
        ll l=Q[i].F.F,r=Q[i].F.S,val=Q[i].S;
        update(l,val);
        if(r<l){
            update(1,val);
            update(m+1,-val);
        }
        update(r+1,-val);
    }      
    vll A,B;
    for(int i=0;i<q.size();i++){
        ll sum=0ll;
        for(auto it : G[q[i]]){
            sum+=query(it);
            if (sum >= 1e10) break;
        }
        if(sum>=E[q[i]]){
            A.pb(q[i]);
            res[q[i]]=min(res[q[i]],mid+1);
        }else{
            B.pb(q[i]);
        }
    }
    parallel(mid+1,e,B);
    for(int i=b;i<=mid;i++){
        int l=Q[i].F.F,r=Q[i].F.S,val=-Q[i].S;
        update(l,val);
        if(r<l){
            update(1,val);
            update(m+1,-val);
        }
        update(r+1,-val);
    }  
    parallel(b,mid-1,A);
}
int main()
{
    fast
    ll x;
    cin>>n>>m;
    G.assign(n+1,vll());
    for(int i=1;i<=m;i++){
        cin>>x;
        G[x].pb(i);
    }  
    for(int i=1;i<=n;i++){
        cin>>E[i];
    }
    ll l,r,val;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>l>>r>>val;
        Q.pb({{l,r},val});
    }
    vll aux;
    for(int i=0;i<=n;i++)res[i]=k+1;
    for(int i=1;i<=n;i++)aux.pb(i);
    parallel(0,k-1,aux);
    for(int i=1;i<=n;i++){
        if(res[i]==k+1){
            cout<<"NIE"<<"\n";
        }else{
            cout<<res[i]<<"\n";
        }
    }        
    return 0;
}

//parallel binary search 
//https://oj.uz/problem/view/POI11_met
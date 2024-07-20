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
const ll INF=1e16;
int main()
{
    ll n,m,a,b,w;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll> > >E;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        E.pb({a,{b,w}});
    }
    vll dis(n+1,INF);
    dis[1]=0;
    bool ok;
    vi p(n+1,-1);
    int in=0;
    for(int i=0;i<n;i++){
        ok=true;
        for(int l=0;l<m;l++){
            int a=E[l].F,b=E[l].S.F;w=E[l].S.S;
            if(dis[b]>dis[a]+w){
                ok=false;
                dis[b]=dis[a]+w;
                p[b]=a;
                in=b;
            }
        }
    }
    for(int i=0;i<n;i++){
        in=p[in];
    }
    //este for para econtrar un cilo pq tal vez estoy en la rama 
    if(ok){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        vi res;
        int u=in;
        while(1){
            if(u==in && res.size()>1)break;
            res.pb(u);
            u=p[u];
        }
        res.pb(in);
        for(int i=res.size()-1;i>=0;i--){
            cout<<res[i]<<" ";
        }
    }

    
    return 0;
}
// la vida es dura pero mas dura mi verdura
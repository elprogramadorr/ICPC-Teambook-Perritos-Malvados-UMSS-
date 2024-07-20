
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
const int tam=1005;
int depth[tam];
int n;
int dp[tam][20];
vector<vi>G;
void init(int nodo, int p , int d){
    depth[nodo]=d;
    dp[nodo][0]=p;
    for(auto it : G[nodo]){
        if(it!=p){
            init(it,nodo,d+1);
        }
    }
}
void initLCA(){
    for(int i=0;i<tam;i++){
        for(int l=0;l<20;l++){
            dp[i][l]=-1;
        }
    }
    init(1,-1,0);
    for(int pot=1;pot<20;pot++){
        for(int v=1;v<=n;v++){
            if(dp[v][pot-1]==-1)continue;
            dp[v][pot]=dp[dp[v][pot-1]][pot-1];
        }
    }
}
int LCA(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    int dif=depth[b]-depth[a];
    for(int i=19;i>=0;i--){
        if(dif&(1<<i)){
            b=dp[b][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];b=dp[b][i];
        }
    }
    return dp[a][0];
}
int main()
{
    int t,a,b,m,caso=0;
    cin>>t;
    while(t--){
        caso++;
        cin>>n;
        G.assign(n+1,vi());
        for(int i=1;i<=n;i++){
            cin>>m;
            for(int l=0;l<m;l++){
                cin>>a;
                G[i].pb(a);
                G[a].pb(i);
            }
        }
        initLCA();
        int q;
        cin>>q;
        cout<<"Case "<<caso<<':'<<endl;
        while(q--){
            cin>>a>>b;
            cout<<LCA(a,b)<<endl;
        }

    }
    
    
    return 0;
}

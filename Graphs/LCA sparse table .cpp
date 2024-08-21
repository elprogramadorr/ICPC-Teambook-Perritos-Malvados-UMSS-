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
using namespace std;
vector<pair<int,int> >v;
vector<vi>G;
vi dp;
pair<int,int> T[20][100000];
map<int,int>pos;
void dfs(int nodo, int padre){
    dp[nodo]=dp[padre]+1;
    v.pb({nodo,dp[nodo]});
    for(int i=0;i<G[nodo].size();i++){
        int hijo=G[nodo][i];
        if(hijo!=padre){
            dfs(hijo,nodo);
            v.pb({nodo,dp[nodo]});
        }
    }
}
int query(int b,int e){
    b=pos[b];e=pos[e];
    if(e<b){
        swap(e,b);
    }
    int len=e-b+1;
    int pot=__lg(len);
    if(T[pot][b].F<T[pot][e-(1<<pot)+1].F){
        return T[pot][b].S;
    }else{
        return T[pot][e-(1<<pot)+1].S;
    }
    //return min(T[pot][b],T[pot][e-(1<<pot)+1]);
}
int main()
{
    int x,t,n,m;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        pos.clear();
        cin>>n;
        G.assign(n,vi());dp.resize(n);
        for(int i=0;i<n;i++){
            cin>>m;
            for(int l=0;l<m;l++){
                cin>>x;
                G[i].pb(x-1);
                G[x-1].pb(i);
            }
        }
        dp[0]=0;
        dfs(0,0);
        for(int i=0;i<v.size();i++){
            T[0][i].F=v[i].S;pos[v[i].F]=i;
            T[0][i].S=v[i].F;
        }
        for(int i=1;i<=__lg(v.size());i++){
            for(int l=0;l<v.size();l++){
                if(l+(1<<i)-1>=v.size()){
                    break;
                }
                if(T[i-1][l].F<T[i-1][l+(1<<(i-1))].F){
                    T[i][l].S=T[i-1][l].S;
                }else{
                    T[i][l].S=T[i-1][l+(1<<(i-1))].S;
                }
                T[i][l].F=min(T[i-1][l].F,T[i-1][l+(1<<(i-1))].F);
            }
        }
        /*for(int i=0;i<v.size();i++){
            cout<<v[i].F<<" ";
        }cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i].S<<" ";
        }*/
        cout<<endl;
        int q,a,b;
        cin>>q;
        cout<<"Case "<<ca<<':'<<endl;
        while(q--){
            cin>>a>>b;
            cout<<query(a-1,b-1)+1<<endl;
        }
    }

    return 0;
}
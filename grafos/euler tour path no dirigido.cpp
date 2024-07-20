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
//"\n"
//__builtin_popcount(x)
// a+b=2*(a&b) + (a^b)
using namespace std;
const int tam=100005;
int n,m;
set<int> G[tam]; //el indice de la arista
vi res;
int vis=0;
bool check(){
    for(int i=1;i<=n;i++){
        if(G[i].size()%2){
            return false;
        }
    }
    return true;
}
void go(int nodo){
    while(G[nodo].size()){
        vis++;
        int to=*G[nodo].begin();
        G[nodo].erase(G[nodo].begin());
        auto it=G[to].find(nodo);
        G[to].erase(it);
        go(to);
    }
    res.pb(nodo);
}

int main(){
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].insert(b);G[b].insert(a);
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    go(1);
    if(vis!=m){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    


    
    return 0;
}
// Los niños tambien son personas
//https://cses.fi/problemset/task/1691/

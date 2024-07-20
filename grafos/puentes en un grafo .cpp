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
set<pair<int,int> >st;
vi arc,vis;
vector<vi>G;
int num=0;
void dfs(int nodo, int ant){
    num++;
    vis[nodo]=arc[nodo]=num;
    for(auto it : G[nodo]){
        if(it==ant)continue;
        if(vis[it]){
            arc[nodo]=min(arc[nodo],vis[it]);
        }else{
            dfs(it,nodo);
            arc[nodo]=min(arc[nodo],arc[it]);
            if(arc[it]>vis[nodo]){//no se pone mayor o igual por el primer if tcs si hay un puente hacia nodo es de más abajo
                st.insert({nodo,it});
            }
        }
    }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    arc.resize(n+1);vis.resize(n+1);
    G.assign(n+1,vi());
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(1,-1);
    cout<<st.size()<<endl;
    for(auto it : st){
        cout<<it.F<<" "<<it.S<<endl; 
    }



/*
11 14
1 2
2 3
3 9
9 1
9 4
4 10
10 6
6 7
7 4
10 7
7 11
7 8
8 5
7 5
*/  
    return 0;
}
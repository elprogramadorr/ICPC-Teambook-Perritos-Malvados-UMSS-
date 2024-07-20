
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
//la idea es convertir el grafo en un arbol donde cada nodo sea un conjunto
//en cada conjunto puedo ir de un nodo a otro pasando por la arista que quiero, checar descomposicion por orejas
vector<vi>G,G2,MG;//grafo normal, grafo sin puentes, grafo entre colores
int num=0;
vi vis,arc;
set<pair<int,int> >st;//puentes
set<pair<int,int> >rosa;//aristas con rosas
vi color;//color de cada nodo
vector<bool>check;// este color puede conseguir una rosa ?
int C=0;
void dfs(int nodo){
    color[nodo]=C;
    for(auto it : G2[nodo]){
        if(rosa.find({nodo,it})!=rosa.end()){
                //si hay alguna rosa en este conjunto siempre es posible tomarla y sesguir pq no hay puentes
                check[C]=true;
        } 
        if(st.find({nodo,it})!=st.end()){
            continue;
        }
        if(color[it]==-1){
            dfs(it);
            
        }
    }
}
set<pair<int,int> >ROSA;//rosas que hay en puentes que unen colores
void cal(int nodo, int padre){
    for(auto it : MG[nodo]){
        if(it==padre)continue;
        check[it]=(check[nodo] or check[it]);//si ya consegui la rosa le paso 
        if(ROSA.find({nodo,it})!=ROSA.end()){
            //si en el puente hay rosa tcs messirve
            check[it]=true;
        }
        cal(it,nodo);
    }
}
void tarjan(int nodo, int padre){
    num++;
    vis[nodo]=arc[nodo]=num;
    for(auto it : G[nodo]){
        if(it==padre)continue;
        if(vis[it]){
            arc[nodo]=min(arc[nodo],vis[it]);
        }else{
            tarjan(it,nodo);
            arc[nodo]=min(arc[nodo],arc[it]);
            if(arc[it]>vis[nodo]){
                st.insert({nodo,it});
                st.insert({it,nodo});
            }
        }
    }
}
int main()
{
    int n,m,a,b,c;
    cin>>n>>m;
    vector<pair<pair<int,int>,int> >E;color.assign(n+2,-1);
    arc.resize(n+1);vis.assign(n+1,0);
    G.assign(n+1,vi());G2.assign(n+1,vi());MG.assign(n+1,vi());
    check.assign(n+1,false);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(c==1){
            rosa.insert({a,b});rosa.insert({b,a});
        }
        G[a].pb(b);G[b].pb(a);
        E.pb({{a,b},c});
    }
    tarjan(1,-1);
    for(int i=0;i<m;i++){
        a=E[i].F.F,b=E[i].F.S,c=E[i].S;
        if(st.find({a,b})==st.end() && st.find({b,a})==st.end()){
           //entro solo si no es un puente
           G2[a].pb(b);G2[b].pb(a);
        }
    }
    //este forsito para colorear los nodos
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            C++;
            dfs(i);
        }
    }
    //este forsito para unir colores con puentes :)
    for(auto it : st){
        a=color[it.F],b=color[it.S];//me interesa el color no el nodo siempre se conectan entre diferentes colores
        if(rosa.find({it.F,it.S})!=rosa.end()){
            ROSA.insert({a,b});ROSA.insert({b,a});
        }  
        MG[a].pb(b);
    }    
    int X,Y;
    cin>>X>>Y;
    cal(color[X],-1);//en un arbol solo hay un camino entre dos nodos
    if(check[color[Y]]){
        //si se puede conseguir la rosa 
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
//https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/sankets-girlfriend-1/
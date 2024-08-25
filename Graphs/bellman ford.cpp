const int INF=1e18;
const int tam=2505;
vi G[tam];
vector<pair<pair<int,int>,int >> E; // (a->b, w)
int n,m;
bool cicloNegativo[tam];
void bellmanFord(int source){
    vi dist(n+1,INF);
    dist[source]=0;
    for(int i=0;i<n-1;i++){
        for(auto e:E){
            int a=e.first.first;
            int b=e.first.second;
            int w=e.second;
            if(dist[a]!=INF && dist[b]>dist[a]+w){
                dist[b]=dist[a]+w;
            }
        }
    }
    for(auto e:E){
        int a=e.first.first;
        int b=e.first.second;
        int w=e.second;
        if(dist[a]!=INF && dist[b]>dist[a]+w){
            cicloNegativo[b]=true;// b esta en un ciclo negativo
            // marca al menos un nodo de cada ciclo negativo
        }
    }
}

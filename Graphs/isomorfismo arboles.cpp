#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define S second
#define F first
using namespace std;
struct Tree{
  int n;
  vi sz;
  vector<vi>G;
  vi centroids;
  vector<vi>level;
  vi prev;
  Tree(int x){
    n=x;
    sz.resize(x+1);
    G.assign(n+1,vi());
    prev.resize(n+1);
  }
  void addEdge(int a, int b){
    G[a].pb(b);G[b].pb(a);
  }
  void centroid(int nodo, int ant){
    bool ok=1;
    for(auto it : G[nodo]){
      if(it==ant)continue;
      if(sz[it]>n/2){
        ok=false;
      }
      centroid(it,nodo);
    }
    int atras=n-sz[nodo];
    if(atras>n/2)ok=false;
    if(ok)centroids.pb(nodo);
  }
  void initsz(int nodo, int ant){
    sz[nodo]=1;
    for(auto it : G[nodo]){
      if(it!=ant){
        initsz(it,nodo);
        sz[nodo]+=sz[it];
      }
    }
  }
  void initLevels(int nodo){
    level.clear();
    vi aux;aux.pb(nodo);
    int pos=0;
    level.pb(aux);
    prev[nodo]=-1;
    while(true){
      aux.clear();
      for(auto it : level[pos]){
        for(auto j : G[it]){
          //cout<<"apagare la luz  "<<j<<endl;
          if(j==prev[it])continue;
          aux.pb(j);
          prev[j]=it;
        }
      }
      if(aux.size()==0)break;
      level.pb(aux);
      pos++;
    }
  }
};
bool check(Tree A, int a, Tree B, int b){
  A.initLevels(a);B.initLevels(b);
  if(A.level.size()!=B.level.size())return false;
  int hashA[A.n+5];
  int hashB[A.n+5];//hash del subarbol rooteado en i

  vector<vi>EA,EB;//le paso los hash de todos los hijos de i me 
                  //servirá para formar el hash del subarbol i  
  EA.resize(A.n+1);EB.resize(A.n+1);
  
  for(int h=A.level.size()-1;h>=0;h--){
    map<vi,int>ind;
    for(auto it : A.level[h]){
      sort(EA[it].begin(),EA[it].end());
      ind[EA[it]]=0;
    }
    for(auto it : B.level[h]){
      sort(EB[it].begin(),EB[it].end());
      ind[EB[it]]=0;
    }
    
    int num=0;
    for(auto it : ind){
      it.S=num;
      ind[it.F]=num;
      num++;
    }
    //paso a sus padres
    for(auto it : A.level[h]){
      hashA[it]=ind[EA[it]];
      
      if(h>0)EA[A.prev[it]].pb(hashA[it]);
    }
    for(auto it : B.level[h]){
      hashB[it]=ind[EB[it]];
      if(h>0)EB[B.prev[it]].pb(hashB[it]);
    }
  }
  return hashA[a]==hashB[b];
}
bool isomorphic(Tree A, Tree B){
  A.initsz(1,-1);B.initsz(1,-1);
  A.centroid(1,-1);B.centroid(1,-1);
  vi CA=A.centroids,CB=B.centroids;
  if(CA.size()!=CB.size())return false;
  for(int i=0;i<CB.size();i++){
    if(check(A,CA[0],B,CB[i])){
      return true;
    }
  }
  return false;
}
int main() {
  int t,n,a,b;
  cin>>t;
  while(t--){
    cin>>n;
    Tree A(n);
    Tree B(n);
    for(int i=1;i<n;i++){
      cin>>a>>b;
      A.addEdge(a,b);
    }
    for(int i=1;i<n;i++){
      cin>>a>>b;
      B.addEdge(a,b);
    }
    if(isomorphic(A,B)){
      cout<<"YES"<<"\n";
    }else{
      cout<<"NO"<<"\n";
    }
  }
}
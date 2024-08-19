// Complexity: O(|N+Q|*sqrt(|N|)*|meter/quitar|)
// Requiere meter(), quitar()

vector<pair<pair<int,int>,int> >Q;// {{izq,der},id}
int tami = 300; // o sqrt(n)+1
bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.F.F/tami!=b.F.F/tami){
        return a.F.F/tami<b.F.F/tami;
    }
    return a.F.S<b.F.S;
}
// main
sort(Q.begin(),Q.end(),comp);
int L=0,R=-1;
int respuesta=0;
for(int i=0;i<q;i++){
    int izq=Q[i].F.F;
    int der=Q[i].F.S;
    int ind=Q[i].S;
    while(L>izq)meter(--L);
    while(R<der)meter(++R);
    while(R>der)quitar(R--);
    while(L<izq)quitar(L++);
    res[ind]=respuesta;
}

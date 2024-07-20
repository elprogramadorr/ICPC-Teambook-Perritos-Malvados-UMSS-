
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
vi v;
vector<pair<pair<int,int>,pair<int,int> > >T(4000000);// prefijo, sufijo, suma, mayor
void init(int nodo, int b, int e){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b==e){
        T[nodo]={{v[b],v[b]},{v[b],v[b]}};
        return;
    }
    init(L,b,mid);init(R,mid+1,e);
    int prefa=T[L].F.F,prefb=T[R].F.F;
    int sufa=T[L].F.S,sufb=T[R].F.S;
    int suma=T[L].S.F,sumb=T[R].S.F;
    int ma=T[L].S.S,mb=T[R].S.S;
    T[nodo].F.F=max(prefa,suma+prefb);
    T[nodo].F.S=max(sumb+sufa,sufb);
    T[nodo].S.F=suma+sumb;
    T[nodo].S.S=max({ma,mb,sufa+prefb});
}
pair<pair<int,int>,pair<int,int> >query(int nodo, int b, int e, int izq, int der){
    int L=2*nodo+1,R=L+1,mid=(b+e)/2;
    if(b>=izq && e<=der){
        return T[nodo];
    }
    if(der<=mid){
        return query(L,b,mid,izq,der);
    }
    if(izq>=mid+1){
        return query(R,mid+1,e,izq,der);
    }
    pair<pair<int,int>,pair<int,int> >A=query(L,b,mid,izq,der);
    pair<pair<int,int>,pair<int,int> >B=query(R,mid+1,e,izq,der);
    pair<pair<int,int>,pair<int,int> >C;
    C.F.F=max(A.F.F,A.S.F+B.F.F);//meto el prefijo
    C.F.S=max(B.S.F+A.F.S,B.F.S);//meto el sufijo
    C.S.F=A.S.F+B.S.F;//la sumita, guapa
    C.S.S=max({A.S.S,B.S.S,A.F.S+B.F.F});
    return C;    
}
int main()
{
    int m,l,r,n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    init(0,0,n-1);
    cin>>m;
    while(m--){
        cin>>l>>r;l--;r--;
        pair<pair<int,int>,pair<int,int> >A=query(0,0,n-1,l,r);
        cout<<A.S.S<<endl;
    }
    
    return 0;
}
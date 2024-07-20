#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
vi v;
const int tam=1000005;
int E[tam];
int version=1;
int nuevi=1;
struct st{
   st * izq;
   st * der;
   int val;
};

st * P[tam];
st * init(int b, int e){
   int mid=(b+e)/2;
   st * nuevo= new st;
   if(b==e){
      nuevo->val=v[b];
      return nuevo;
   }
   st * A = init(b,mid);
   st * B = init(mid+1 ,e);
   nuevo->val=A->val + B->val;
   nuevo->izq=A;
   nuevo->der=B;
   return nuevo;
}

st * update(st * nodo, int b, int e, int pos, int valor){
   int mid=(b+e)/2;
   st * nuevo = new st;
   nuevo->izq=nodo->izq;
   nuevo->der=nodo->der;
   nuevo->val=nodo->val;
   if(b==e){
      nuevo->val=valor;
      return nuevo;
   }
   if(pos<=mid){
      nuevo->izq=update(nodo->izq,b,mid,pos,valor);
   }else{
      nuevo->der=update(nodo->der,mid+1,e,pos,valor);
   }
   nuevo->val=nuevo->izq->val + nuevo->der->val;
   return nuevo;
}
int query(st * nodo, int b, int e, int izq, int der){
   int mid=(b+e)/2;
   //cout<<b<<"  "<<e<<endl;
   if(b>=izq && e<=der){
      //cout<<"entro  "<<nodo->val<<endl;
      return nodo->val;
   }
   if(der<=mid){
      return query(nodo->izq,b,mid,izq,der);
   }else{
      if(izq>=mid+1){
         return query(nodo->der,mid+1,e,izq,der);
      }else{
         return query(nodo->der,mid+1,e,izq,der)+query(nodo->izq,b,mid,izq,der);
      }
   }
}

signed main()
{

   int n,q,x,k,c,a,b;
   cin>>n>>q;
   for(int i=0;i<n;i++){
      cin>>x;
      v.pb(x);
   }
   P[1]=init(0,n-1);
   E[1]=1;
   while(q--){
      cin>>c;
      if(c==1){
         cin>>k>>a>>x;
         version++;
         P[version]=update(P[E[k]],0,n-1,a-1,x);
         E[k]=version;
         continue;
      }
      if(c==2){
         cin>>k>>a>>b;
         cout<<query(P[E[k]],0,n-1,a-1,b-1)<<"\n";
         //cout<<endl;
         continue;
      }
      if(c==3){
         cin>>k;
         version++;
         nuevi++;
         E[nuevi]=version;
         st * nuevo = new st;
         nuevo->val=P[E[k]]->val;
         nuevo->izq=P[E[k]]->izq;
         nuevo->der=P[E[k]]->der;
         P[version]=nuevo;
         continue;
      }

   }
   
   return 0;
}

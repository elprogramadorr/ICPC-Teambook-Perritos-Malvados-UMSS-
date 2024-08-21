#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#define vi vector<int>
#define ll long long
#define F first
#define S second
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int res=0;
const int tam=300005;
bool responder[tam];
vector<pair<int,int> > G[4*tam];
int P[tam];
int sz[tam];
int _find(int x){
	if(x==P[x])return x;
	return _find(P[x]);
}

void push(int nodo, int b, int e, int izq, int der, int A, int B){
	int L=2*nodo+1,R=L+1,mid=(b+e)/2;
	if(b>der || e<izq)return;
	if(b>=izq && e<=der){
		G[nodo].pb({A,B});
		return;
	}
	push(L,b,mid,izq,der,A,B);
	push(R,mid+1,e,izq,der,A,B);
}
vi respuestas;

void go(int nodo, int b, int e){
	int L=2*nodo+1,R=L+1,mid=(b+e)/2;
	
	// aqui meto cambios
	vector<int> changes; // los vertices que eran representantes de su componente y dejan de serlo
    vector<pair<int,int> >change2;   
	
	for(auto it : G[nodo]) {
		int pap1 = _find(it.F), pap2 = _find(it.S);
		if(sz[pap1] < sz[pap2])
			swap(pap1, pap2);
		if(pap1 != pap2) {
			changes.push_back(pap2);
			change2.pb({pap1,sz[pap1]});
			P[pap2] = pap1;
			sz[pap1] = sz[pap1]+sz[pap2];
		}
	}

	res -= changes.size();
	

	if(b==e){
		// importante que no este arriba
		if(responder[b])respuestas.pb(res);
	}else{
		go(L,b,mid);
		go(R,mid+1,e);
	}

	// deshacemos los cambios
	for(int x: changes)
		P[x] = x;
	for(auto it : change2)
		sz[it.F] = it.S;
	res += changes.size();

}
int main() {
	FIFO;
	int n,q,a,b;
	cin>>n>>q;
	res=n;
	for(int i=1;i<=n;i++){
		P[i]=i;
		sz[i]=1;// ojo aqui xd
	}

	char c;
	map<pair<int,int>,int> abierto;
	for(int i=1;i<=q;i++){
		cin>>c;
		if(c=='?'){
			responder[i]=true;
			continue;
		}
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(c=='+'){
			abierto[{a,b}]=i;
		}else{
			int izq=abierto[{a,b}];
			push(0,1,q,izq,i,a,b);
			abierto.erase({a,b});
		}
	}
	for(auto it : abierto){
		int a=it.F.F,b=it.F.S,izq=it.S;
		push(0,1,q,izq,q,a,b);
	}
	if(q==0)return 0;
	go(0,1,q);
	for(auto it : respuestas){
		cout<<it<<"\n";
	}

	
	return 0;
}

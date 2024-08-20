#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define vi vector<int>
#define pb push_back
using namespace std;
// suma en rango
vi v;
struct ST{
	int N;
	vi T;
	void init(int n){
		N=n;
		T.assign(4*N, 0);
	}
	void build(int nodo, int b, int e){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]=v[b];
			return;
		}
		build(L, b, mid);
		build(R, mid+1, e);
		T[nodo]=T[L]+T[R];
	}
	void update(int nodo, int b, int e, int pos, int val){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b==e){
			T[nodo]=val;
			return;
		}
		if(pos<=mid)update(L, b, mid, pos, val);
		else update(R, mid+1, e, pos, val);
		T[nodo]=T[L]+T[R];
	}
	int query(int nodo, int b, int e, int izq, int der){
		int mid=(b+e)/2,L=nodo*2+1,R=L+1;
		if(b>=izq && e<=der)return T[nodo];
		if(der<=mid){
			return query(L, b, mid, izq, der);
		}
		if(izq>mid){
			return query(R, mid+1, e, izq, der);
		}
		return query(L, b, mid, izq, der)+query(R, mid+1, e, izq, der);
	}
};

int main(){
	ST tree;
	tree.init(3);
	v.pb(1);v.pb(2);v.pb(3);
	tree.build(0, 0, 2);
	return 0;
}

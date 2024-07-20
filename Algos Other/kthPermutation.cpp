#include <vector>
#include <iostream>
#include <set>
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
using namespace std;

int _find(ll &k,ll n){
    if(n==1)return 0;
    n--;
    int ind;
    ll n2=n;
    while(k>=n2&&n>1) {
        n2*=(n-1);
        n--;
    }
    ind=k/n2;
    k%=n2;
    return ind;
}
vi kthPermutation(ll n, ll k){
    vi Ans;
    set<int>st;
    for (int i=1;i<=n;i++)st.insert(i);
    auto it=st.begin();
    k--;
    for(int i=0;i<n;i++) {
        int index=_find(k,n-i);
        advance(it,index);
        Ans.pb(*it);
        st.erase(it);
        it=st.begin();
    }
    return Ans;
}

int main(){
    vi res;
    res=kthPermutation(4, 2);
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    return 0;
}

//https://codeforces.com/contest/1443/problem/E

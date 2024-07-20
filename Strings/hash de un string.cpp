#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second

//"\n"
using namespace std;
const ll p=31;//si es con mayusculas tcs 53, esto es un primo mayor al ascii mayor
const ll MOD=1e9+9;//este siempre mi rey
//a=1, b=2, c=3, ...
ll H(string s){
    int n=s.size();
    ll res=0;
    ll pot=1;
    for(int i=0;i<n;i++){
        ll x=s[i]-'a'+1;   
        res=(res+x*pot)%MOD;
        pot=(pot*p)%MOD;
    }
    return res;
}
int main()
{
    string s="rhtidafd";
    cout<<H(s)<<endl;
    return 0;
}

//https://codeforces.com/contest/911/problem/D
//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1021
//abcd
//122110
//fcdf
//182689
//rhtidafd

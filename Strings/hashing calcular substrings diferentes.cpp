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
//algoritmo para calcular la cantidad de substrings diferentes
using namespace std;

int f(string s){
    int n=s.size();
    int MOD=1e9+9;
    int p=31;
    ll P[n+1];
    ll pot=1;
    ll h[n+1];//hashing de substr 1....i
    h[0]=0;
    for(int i=0;i<n;i++){
        P[i]=pot;
        int x=s[i]-'a'+1;
        h[i+1]=(h[i]+x*pot)%MOD;
        pot=(pot*p)%MOD;
    }
    
    int res=0;
    for(int i=1;i<=n;i++){
        set<int>st;
        for(int l=0;l+i<=n;l++){
            int curr=(h[l+i]-h[l]+MOD)%MOD;//devuelve hashing (l+1,....,l+i)
            curr=(curr*P[n-l-1])%MOD;//igualo a potencia de n-1
            st.insert(curr);
        }
        res+=st.size();
    }
    return res;
}

int main()
{   
    string s;
    cin>>s;
    cout<<f(s)<<endl;
    
    return 0;
}

//https://codeforces.com/contest/911/problem/D
//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1021


#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define vll vector<ll>
using namespace std;
const ll MOD=1000000007;
const int INF=1234567890;
const ll MAX=100003;
ll fact[5000005];
void init(){
   fact[0]=1;
   for(int i=1;i<=5000000;i++){
      fact[i]=(fact[i-1]*i)%MOD;
   }
}
ll Pou(int a, int n){
   if(n==0)return 1;
   if(n%2==0){
      ll A=Pou(a,n/2);
      return (A*A)%MOD;
   }else{
      ll A=Pou(a,n/2);
      A=(A*A)%MOD;
      return (A*a)%MOD;
   }
}
ll nck(int n, int k){
   ll res=(fact[n]*Pou((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
   return res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    
    return 0;
}
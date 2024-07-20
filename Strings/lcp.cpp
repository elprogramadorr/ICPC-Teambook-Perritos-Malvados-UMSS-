#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define vll vector<long long>
#define mp make_pair
using namespace std;

int main(){
    //suffix array primer intento 
    string s;
    cin>>s;s.pb(char(36));
    vector<pair<char,int> >a;//caracter e indice
    int n=s.size();
    for(int i=0;i<n;i++){
        a.pb({s[i],i});
    }
    sort(a.begin(),a.end());
    vi p;//p son los indices en ordenados, la respuesta
    for(int i=0;i<n;i++)p.pb(a[i].S);
    int c[n];
    c[p[0]]=0;//c[i] es la posicion de s[i] si ordeno  los sufijos
    for(int i=1;i<n;i++){
        if(a[i].F==a[i-1].F){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    int k=1;//es el tamaño curr
    while(k <n){
        vector<pair<pair<int,int>,int> >A;//valores de las dos mitades e indice
        for(int i=0;i<n;i++){
            A.pb({{c[i],c[(i+k)%n]},i});
        }
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++){
            p[i]=A[i].S;
        }
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(A[i].F==A[i-1].F){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        k*=2;
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
        //cout<<p[i]<<"  "<<s.substr(p[i],n-p[i])<<endl;
    }
    cout<<endl;

    vi lcp(n);
    k=0;
    for(int i=0;i<n-1;i++){
        int pi=c[i];
        int j=p[pi-1];
        while(s[i+k]==s[j+k])k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }
    for(int i=1;i<n;i++){
        cout<<lcp[i]<<" ";
    }
    
    return 0;
}
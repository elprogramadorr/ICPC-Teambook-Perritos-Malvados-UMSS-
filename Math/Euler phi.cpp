#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <bits/stdc++.h>
// #define lcm(a,b) (a/__gcd(a,b))*b
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
using namespace std;
const int tam=1e5+5;
int phi[tam];
const int MOD=1e9+7;

void init(){
    for(int i=1;i<tam;i++){
        phi[i]=i;
    }
    for(int i=2;i<tam;i++){
        if(phi[i]==i){
            for(int j=i;j<tam;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }    
}

int gcd(int a,int b){
    // euclides
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

int main()
{
    init();
    cout<<phi[5]<<endl;// 4
    cout<<phi[6]<<endl;// 2
    return 0;
}  
//phi(n)= cantidad de numeros menores a n que son coprimos con n
//https://codeforces.com/contest/1717/problem/E
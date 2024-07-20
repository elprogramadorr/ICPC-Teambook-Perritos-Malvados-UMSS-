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
using namespace std;
const int tam=200005;
int mou[tam];
//0 si es divisible por algun cuadrado
//1 si esta libre de cuadrados y tiene un numero par de factores primos
//-1 libre de cuadrados y tiene un numero impar de factores primos
//si quiero contar solo los que tiene gcd 1
int check(int num){
    if(num==1)return 1;
    int cant=0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            cant++;
            num/=i;
            if(num%i==0){
                return 0;
            }
        }
    }
    if(num>1)cant++;
    if(cant%2){
        return -1;
    }
    return 1;
}
void init(){
    for(int i=1;i<tam;i++){
        mou[i]=check(i);
    }
}
int main()
{
    init();
    for(int i=1;i<=10;i++){
        cout<<mou[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
//si quiero que el gcd edl arreglo sea 1 tcs tengo que restarle todos que sean multiplos de 2,3,..... y le sumo 6 ... pq se repiten
//FACILITO
//si m es el mayor numero de mi arreglo tcs res[m]=cal(m), res[m-1]=cal(m-1)-sumatoria(cal(multiplos(m-1) )
//cal(m)=crear la respuesta con multiplos de m
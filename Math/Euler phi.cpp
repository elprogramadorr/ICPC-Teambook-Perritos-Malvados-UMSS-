/*
phi(n)= cantidad de numeros menores a n que son coprimos con n
phi(5) = 4, phi(6)=2

Time complexity: < O(N (log N))
*/

const int tam=1e5+5;
int phi[tam];
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

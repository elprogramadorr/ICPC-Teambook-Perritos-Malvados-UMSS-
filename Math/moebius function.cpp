// 0 si es divisible por algun cuadrado
// 1 si esta libre de cuadrados y tiene un numero par de factores primos
// -1 libre de cuadrados y tiene un numero impar de factores primos
// si quiero contar solo los que tiene gcd 1
const int tam=200005;
int mou[tam];
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
// si quiero que el gcd del arreglo sea 1 tcs tengo que restarle todos que sean multiplos de 2,3,..... y le sumo 6 ... pq se repiten
// FACILITO
// si m es el mayor numero de mi arreglo tcs res[m]=cal(m), res[m-1]=cal(m-1)-sumatoria(cal(multiplos(m-1)))
// cal(m)=crear la respuesta con multiplos de m

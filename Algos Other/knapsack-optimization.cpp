bitset<100001> posi;
posi[0] = 1;
for (int t : comps) posi |= posi << t;
for (int i = 1; i <= n; ++i) cout << posi[i];

// cuando suma maxima es tam = 2e5
// entonces la cantidad de numeros diferentes es sqrt(2e5)
// lo que hago es dejar como maximo 2 repeticiones en cada valor
// entonces cada dos i's le paso uno a 2*i y me queda solo sqrt(n) numeros
// ya que cada i solo aparece maximo 2 veces

for(int i=1;i<tam;i++){
  if(cant[i]>=3){
    int mv=cant[i]/2;
    if(cant[i]%2==0)mv--;
    cant[i]-=mv*2;
    cant[2*i]+=mv;
  }
}

bitset<tam> dp;
dp[0]=1;
for(int i=1;i<tam;i++){// importante empezar en 1
  for(int l=0;l<cant[i];l++){
    dp|=dp<<i;
  }
}

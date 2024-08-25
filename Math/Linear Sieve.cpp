// Time : O(n)
// lp[i] menor primo que divide a i
const int tam=10000000;
vector<int>primes;
vector<int>lp(tam+1);
void linear_sieve(){
  for(int i=2;i<tam;i++){
    if(lp[i]==0){
      lp[i]=i;
      primes.pb(i);
    }
    for(int l=0;i * primes[l]<tam;l++){
      lp[i*primes[l]]=primes[l];
      if(i%primes[l]==0)break;
    }        
  }
}

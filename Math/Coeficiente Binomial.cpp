const int MOD=998244353;
ll fact[5005];
void init(){
   fact[0]=1;
   for(int i=1;i<=5000;i++){
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
   if(n<k)return 0;  
   ll res=(fact[n]*Pou((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
   return res;
}

// lineal cuando n es muy grande y k pequenho

ll nckLineal(int n, int k){
    if(n<k)return 0;
    ll res=1;
    for(int i=0;i<k;i++){
        res=(res*(n-i))%MOD;
        res=(res*Pou(i+1,MOD-2))%MOD;
    }
    return res;
}

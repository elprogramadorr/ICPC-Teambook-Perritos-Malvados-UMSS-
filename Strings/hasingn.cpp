const int tam=1000005;
const int p=31;
const int MOD=1e9+9;
ll H[tam];
ll P[tam];
ll n,m;
string a,b;
void init(){
   P[0]=1;
   for(int i=1;i<=n;i++){
      P[i]=(p*P[i-1])%MOD;
   }
   for(int i=0;i<n;i++){
      ll val=a[i]-'a'+1;
      if(i){
         H[i]=(H[i-1]+val*P[i])%MOD;
      }else{
         H[i]=(P[i]*val)%MOD;
      }
   }
}
int main(){
   while(cin>>m){

   cin>>b>>a;
   n=a.size();
   if(m>n){cout<<endl;continue;}
   init();
   ll A=0,B=0;
   for(int i=0;i<m;i++){
      int val=b[i]-'a'+1;
      B=(B+val*P[i])%MOD;
   }
   B=(B*P[n])%MOD;
   for(int i=0;i<n;i++){

      if(i+m>n)break;
      A=H[i+m-1];
      if(i)A=(A-H[i-1]+MOD)%MOD;
      A=(A*P[n-i])%MOD;
      if(A==B)cout<<i<<endl;
      //cout<<A<<" "<<B<<endl;
   }

   }

   return 0;
}
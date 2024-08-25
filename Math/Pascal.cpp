ll pascal[5005][5005];
pascal[0][0]=1;
for(int i=1;i<=5000;i++){
  for(int j=0;j<=i;j++){
    if(j==0 || j==i)pascal[i][j]=1;
    else
    pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%MOD;            
  }
}
int n,k;
cout<<pascal[n][k]<<endl;

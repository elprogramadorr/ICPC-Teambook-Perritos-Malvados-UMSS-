ll M[505][505];
for(int i=0;i<=504;i++){
  for(int l=0;l<=504;l++){
    M[i][l]=1e18;
    if(i==l)M[i][l]=0;
  }
}
for(int i=0;i<m;i++){
  cin>>a>>b>>c;
  M[a][b]=min(M[a][b],c);
  M[b][a]=min(M[b][a],c);
}
for(int i=1;i<=n;i++){
  for(int l=1;l<=n;l++){
    for(int j=1;j<=n;j++){
      M[l][j]=min(M[l][j],M[l][i]+M[i][j]);
    }
  }
}

// The number of 1's (or any other nonzero digit) required to write all integers [0, 10^n-1)
// a(n) = n*10^(n-1). 
// 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000
int a(int n){
  int pot=n;
  for(int i=1;i<=n-1;i++){
    pot*=10;
  }
  return pot;
}
int pot2(int x, int n){
	if(n==-1)return 0;
  int pot=1;
	for(int i=1;i<=n;i++){
		pot*=x;
	}
	return pot;
}
// contar cuantos 1's entre 0 y x
int contar(int x){
	string s=to_string(x);
	int n=s.size();
	int res=0;
	int acum=0;
	for(int i=0;i<n;i++){
		int ant=s[i]-'0';
		if(ant==0)continue;
		res+=a(n-i-1) * ant;
		int cuantos=ant * pot2(10,n-i-1);
		res+= acum * cuantos;
		if(ant>1)res+=pot2(10,n-i-1);
		if(ant==1)acum++;
	}
	res+=acum;
	return res;
}
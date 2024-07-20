const int tam=1e7+5;
int small[tam];
void criba(){
	for(int i=2;i<tam;i++){
		if(small[i]==0){
			for(int l=i;l<tam;l+=i){
				if(small[l]==0)small[l]=i;
			}
		}
	}
}
vi factorizar(int x){ // primos en orden ascendente 2,2,5,7...
	vi ans;
	while(x>1){
		ans.pb(small[x]);
		x/=small[x];
	}
	return ans;
}

// lower_bound on the prefix sum array
int kth(int k){
	int pos=0;
	for(int i=20;i>=0;i--){
		if(pos+(1<<i)<tam && T[pos+(1<<i)]<k){
			k-=T[pos+(1<<i)];
			pos+=(1<<i);
		}
	}
	return pos+1;
}

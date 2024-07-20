ll div_ceil(ll a, ll b, bool ceil){
	ll ans = abs(a/b);
	bool pos = (a<0)==(b<0);
	if(a%b and pos==ceil) ans++;
	if(!pos) ans*=-1;
	return ans;
}
// |x|+|y| es minimo y x es minimo 
ll gcd_ext(ll a, ll b, ll &xo, ll &yo){
	if(b==0){
		xo = 1, yo = 0;
		return a;
	}
	ll x1, y1;
	ll g = gcd_ext(b,a%b,x1,y1);
	xo = y1;
	yo = x1-(a/b)*y1;
	return g;
}
//sol return (y) for b in ax + by = c 
//sol retorna minimo x + y creo
ll sol(ll a, ll b, ll c){
	ll xo, yo;
	ll g = gcd_ext(a,b,xo,yo);
	assert(c%g==0);
	a/=g,b/=g,c/=g;
	xo*=c,yo*=c;
	ll k;
	if(a>0) k = div_ceil(1-yo,a,1);
	else k = div_ceil(1-yo,a,0);
	return yo+k*a;
}

bool check(int a, int b, int c){
    if(a==0)return c%b==0;
    if(b==0)return c%a==0;
    return (abs(c)%__gcd(abs(a),abs(b)))==0;
}

// https://codeforces.com/gym/104337 (Problem I)

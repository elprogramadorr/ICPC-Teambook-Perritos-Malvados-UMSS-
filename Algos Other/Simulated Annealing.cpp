#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long double
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point{
    ll x,y;
    bool operator == (Point b) { return x == b.x && y == b.y; }
    bool operator != (Point b) { return !(*this == b); }
    bool operator < (const Point &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const Point &o) const { return y > o.y || (y == o.y && x > o.x); }
};
Point operator +(const Point &A, const Point &B) { return {A.x+B.x, A.y+B.y};}
Point operator -(const Point &A, const Point &B) { return {A.x-B.x, A.y-B.y};}
Point operator *(const Point &A, const ll &K) { return {A.x*K, A.y*K};}
ll dot(const Point &A, const Point &B) { return A.x*B.x + A.y*B.y; }
ll cross(const Point &A, const Point &B) { return A.x*B.y - A.y*B.x; }
ll turn(const Point &A, const Point &B, const Point &C) { return cross(B-A,C-A); }
ll dist2(const Point &A, const Point &B) { return dot(A-B,A-B); }

int n;
vector<Point> P; 
vi peso;

double calcularMagnitud(const Point &p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

ll costo(Point x) {
    ll res=0;
    for(int i=0;i<n;i++){
        res+=sqrt((P[i].x-x.x)*(P[i].x-x.x)+(P[i].y-x.y)*(P[i].y-x.y))*peso[i];
    }
    return res;
}

signed main()
{
    FIFO;    
    cin>>n;
    for(int i=0;i<n;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        P.pb({x,y});
        peso.pb(w);
    }
    cout<<fixed<<setprecision(3);
    
    ll tempereatura=1000;
    Point res;
    res.x = uniform_real_distribution<double>(-1000,1000)(rng);
    res.y = uniform_real_distribution<double>(-1000,1000)(rng);
    ll respuesta=costo(res);
    // cout<<costo({-23028.0752575625, 23636.2571347542})<<endl;
    // return 0;
    vector<ll> T;
    while(clock() / (double) CLOCKS_PER_SEC <= 0.975749){
        Point nuevo = res;
        ll randi = uniform_real_distribution<double>(-1000,1000)(rng);
        nuevo.x += randi * tempereatura;
        randi = uniform_real_distribution<double>(-1000,1000)(rng);
        nuevo.y += randi * tempereatura;
        // cout<<nuevo.x<<" "<<nuevo.y<<" "<<costo(nuevo)<<"\n";
        ll nuevo_costo = costo(nuevo);
        if(nuevo_costo < respuesta){
            res = nuevo;
            respuesta = nuevo_costo;
        }
        else{
			double DELTA = abs(respuesta - nuevo_costo);
            double prob = exp(DELTA / tempereatura);
            if(prob < uniform_real_distribution<double>(0,1)(rng)){
				res = nuevo;
				respuesta = nuevo_costo;
			}
        }
        T.pb(tempereatura);
        tempereatura*=0.9999;
    }

    cout<<res.x<<" "<<res.y<<"\n";
    
    return 0;
}

// https://www.luogu.com.cn/problem/P1337

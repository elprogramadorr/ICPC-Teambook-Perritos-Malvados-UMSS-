#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIFO ios::sync_with_stdio(0); cin.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    ll x, y;
    bool operator == (Point b) { return x == b.x && y == b.y; }
    bool operator != (Point b) { return !(*this == b); }
    bool operator < (const Point &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const Point &o) const { return y > o.y || (y == o.y && x > o.x); }
};

Point operator +(const Point &A, const Point &B) { return {A.x + B.x, A.y + B.y}; }
Point operator -(const Point &A, const Point &B) { return {A.x - B.x, A.y - B.y}; }
Point operator *(const Point &A, const ll &K) { return {A.x * K, A.y * K}; }
ll dot(const Point &A, const Point &B) { return A.x * B.x + A.y * B.y; }
ll cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
ll turn(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
ll dist2(const Point &A, const Point &B) { return dot(A - B, A - B); }

template<typename T>
T uniform(T a, T b) {
    return uniform_real_distribution<T>(a, b)(rng);
}

int n;
vector<Point> P;
vector<ll> peso;

ll costo(Point x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += sqrt((P[i].x - x.x) * (P[i].x - x.x) + (P[i].y - x.y) * (P[i].y - x.y)) * peso[i];
    }
    return res;
}

Point simulated_annealing() {
    double temperatura = 1000;
    Point res = {uniform(-1000.0, 1000.0), uniform(-1000.0, 1000.0)};
    ll mejor_costo = costo(res);

    while (clock() / (double) CLOCKS_PER_SEC <= 0.975) {
        Point nuevo = res;
        nuevo.x += uniform(-1000.0, 1000.0) * temperatura;
        nuevo.y += uniform(-1000.0, 1000.0) * temperatura;
        
        ll nuevo_costo = costo(nuevo);
        if (nuevo_costo < mejor_costo) {
            res = nuevo;
            mejor_costo = nuevo_costo;
        } else {
            double delta = abs(mejor_costo - nuevo_costo);
            double prob = exp(-delta / temperatura);
            if (prob > uniform(0.0, 1.0)) {
                res = nuevo;
                mejor_costo = nuevo_costo;
            }
        }
        temperatura *= 0.9999;
    }
    return res;
}

signed main() {
    FIFO;
    cin >> n;
    P.resize(n);
    peso.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y >> peso[i];
    }
    
    cout << fixed << setprecision(3);
    
    Point mejor = simulated_annealing();
    for (int i = 0; i < 5; i++) { // Ejecutamos SA varias veces
        Point candidato = simulated_annealing();
        if (costo(candidato) < costo(mejor)) {
            mejor = candidato;
        }
    }
    
    cout << mejor.x << " " << mejor.y << "\n";
    return 0;
}

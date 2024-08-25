struct Point {
  ll x, y;
  // Operadores para comparacion
  bool operator == (Point b) { return x == b.x && y == b.y; }
  bool operator != (Point b) { return !(*this == b); }
  bool operator < (const Point &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const Point &o) const { return y > o.y || (y == o.y && x > o.x); }
};
// Operadores aritmeticos
Point operator +(const Point &A, const Point &B) { return {A.x + B.x, A.y + B.y}; }
Point operator -(const Point &A, const Point &B) { return {A.x - B.x, A.y - B.y}; }
Point operator *(const Point &A, const ll &K) { return {A.x * K, A.y * K}; }
ll dot(const Point &A, const Point &B) { return A.x * B.x + A.y * B.y; }
ll cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
ll turn(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
ll dist2(const Point &A, const Point &B) { return dot(A - B, A - B); }
// Calcula la envoltura convexa de un conjunto de puntos
vector<Point> convex_hull(vector<Point> p) {
  if (p.size() <= 1) return p; // Envoltura convexa trivial para <= 2 puntos
  
  sort(p.begin(), p.end());
  vector<Point> ch;
  ch.reserve(p.size() + 1);
  
  for (int i = 0; i < 2; i++) {
    int start = ch.size();
    for (auto &a : p) {
      // Si se necesitan puntos colineales, usa < y primero elimina puntos repetidos en p
      while (ch.size() >= start + 2 && turn(ch[ch.size() - 2], ch.back(), a) <= 0)
        ch.pop_back();
      ch.push_back(a);
    }
    ch.pop_back();
    reverse(p.begin(), p.end());
  }
  
  if (ch.size() == 2 && ch[0] == ch[1]) ch.pop_back();
  
  return ch;
}

// Calcula el angulo entre dos vectores en grados
double angle(Point a, Point b) {
  double aV = sqrt(dot(a, a));
  double bV = sqrt(dot(b, b));
  double resRad = acos(dot(a, b) / (aV * bV)); // Radianes
  double resDeg = resRad * 180.0 / acos(-1);
  return resDeg;
}

// Calcula la altura desde un punto a una linea formada por dos puntos
double calcular_H(Point a, Point b, Point P) {
  // (a, b) * H = area del paralelogramo
  double area = abs(cross(P - a, b - a));
  double disAB = sqrt(dist2(a, b));
  double H = area / disAB;
  return H;
}

// Verifica la interseccion entre dos segmentos de linea
bool check_segment_intersection(Point a1, Point a2, Point b1, Point b2) {
  // Caso paralelo
  if (cross(a2 - a1, b2 - b1) == 0) {
    if (turn(a1, a2, b1) == 0) {
      for (int i = 0; i < 2; i++) {
        if (max(a1.x, a2.x) < min(b1.x, b2.x) || max(a1.y, a2.y) < min(b1.y, b2.y)) {
          return false;
        }
        swap(a1, b1);
        swap(a2, b2);
      }
      return true;
    }
    return false;
  }
  
  // Caso no paralelo
  for (int i = 0; i < 2; i++) {
    ll s1 = turn(a1, a2, b1);
    ll s2 = turn(a1, a2, b2);
    if ((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0)) {
      return false;
    }
    swap(a1, b1);
    swap(a2, b2);
  }
  
  return true;
}

// Calcula el area doble de un poligono (la suma de areas de triangulos)
int doble_area(vector<Point> &p) {
  int n = p.size();
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += cross(p[i], p[(i + 1) % n]);
  }
  return abs(res);
}

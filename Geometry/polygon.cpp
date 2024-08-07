// ver si punto esta en un ccw poligono convexo, O(log n)
enum {OUT, ON, IN};
int E0 = 0;
int point_in_convex_polygon( const vector < Point > &pol, const Point &p ) {
  int low = 1, high = pol.size() - 1;
  while( high - low > 1 ) {
    int mid = ( low + high ) / 2;
    if( turn( pol[0], pol[mid], p ) >= -E0 ) low = mid;
    else high = mid;
  }
  if( turn( pol[0], pol[low], p ) < -E0 ) return OUT;
  if( turn( pol[low], pol[high], p ) < -E0 ) return OUT;
  if( turn( pol[high], pol[0], p ) < -E0 ) return OUT;

  if( low == 1 && turn( pol[0], pol[low], p ) <= E0 ) return ON;
  if( turn( pol[low], pol[high], p ) <= E0 ) return ON;
  if( high == (int) pol.size() -1 && turn( pol[high], pol[0], p ) <= E0 ) return ON;
  return IN;
}


// punto en poligono cualquiera
bool pointlineintersect(Point P1, Point P2, Point P3) {
    if (cross(P2 - P1, P3 - P1) != 0) return false;
    return (min(P2.x, P3.x) <= P1.x && P1.x <= max(P2.x, P3.x))
        && (min(P2.y, P3.y) <= P1.y && P1.y <= max(P2.y, P3.y));
}
int point_in_polygon(vector<Point> &pol, Point P) {
    int cnt = 0;
    bool boundary = false;
    int N = pol.size();
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        if (pointlineintersect(P, pol[i], pol[j])) {
            boundary = true;
            break;
        }
        if (pol[i].y <= P.y && P.y < pol[j].y && cross(pol[j] - pol[i], P - pol[i]) < 0) cnt++;
        else if (pol[j].y <= P.y && P.y < pol[i].y && cross(pol[i] - pol[j], P - pol[j]) < 0) cnt++;
    }
    if (boundary) return ON;
    return (cnt & 1) ? IN : OUT;
}

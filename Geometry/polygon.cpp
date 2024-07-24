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

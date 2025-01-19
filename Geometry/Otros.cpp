// linea recta eq: ax + by = 0  

pair<pair<int,int>,int> stand(Point A, Point B){
    int a = A.y - B.y;
    int b = A.x - B.x;
    int c = A.y*B.x - B.y*A.x;
    
    int G=__gcd(abs(a),__gcd(abs(b),abs(c)));
    a/=G;
    b/=G;
    c/=G;
    if(a<0 || (a==0 && b<0)){
        a*=-1;
        b*=-1;
        c*=-1;
    }
    return {{a,b},c};
}

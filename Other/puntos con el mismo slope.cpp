int dx=X-x;
int dy=Y-y;
int g=__gcd(abs(dx),abs(dy));
pair<ii,int> meto={{x,y},h};
if(dx<0 || (dx==0 && dy<0)){
        dx=-dx;
        dy=-dy;
}
dx/=g;
dy/=g;
M[{dx,dy}].pb(meto);




int dx=X-x;
int dy=Y-y;
int g=__gcd(abs(dx),abs(dy));
pair<ii,int> meto={{x,y},h};
dx/=g;
dy/=g;
M[{dx,dy}].pb(meto);
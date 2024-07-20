bool up(Point a){
    return a.y > 0 || (a.y == 0 && a.x >= 0);
}
bool cmp(Point a, Point b){
    if (up(a) != up(b)) return up(a) > up(b);
        return cross(a, b) > 0;
}

// this starts from the half line 𝑥≤0, 𝑦=0 
int group(Point a){
    if(a.y<0)return -1;
    if(a.y==0 && a.x>=0)return 0;
    return 1;
}
bool cmp(Point a, Point b){
    if(group(a)==group(b))return cross(a,b)>0;
    return group(a)<group(b);
}

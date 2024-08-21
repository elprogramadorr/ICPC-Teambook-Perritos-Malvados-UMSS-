void build_tree( int cur , int l , int r )
{
     if( l==r )
     {
            tree[cur].clear();
            tree[cur].push_back( a[ l ] );
            return ;
     }
     int mid = l+(r-l)/2;
     build_tree(2*cur+1 , l , mid );
     build_tree(2*cur+2 , mid+1 , r );
     //tree[cur].clear();
     tree[cur].resize(tree[2*cur+1].size() + tree[2*cur+2].size());
     merge(tree[2*cur+1].begin(), tree[2*cur+1].end(), tree[2*cur+2].begin(), tree[2*cur+2].end(), tree[cur].begin());
}
int query( int cur, int l, int r, int x, int y, int k)
{
       if( r < x || l > y )return 0;
      if( x<=l && r<=y )return  lower_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      int mid=l+(r-l)/2;
     return query(2*cur+1,l,mid,x,y,k)+query(2*cur+2,mid+1,r,x,y,k);
}
#include<bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
//"\n"
//__builtin_popcount(x)
// a+b=2*(a&b) + (a^b)
using namespace std;
const int tam=1005;
int n,q;
int T[tam][tam];
void update(int x, int y, int val){
    x++;y++;
    for(;x<tam;x+=x&-x){
        for(int l=y;l<tam;l+=l&-l)T[x][l]+=val;
    }
}
int query(int x, int y){
    x++;y++;
    int res=0;
    for(;x>0;x-=x&-x){
        for(int l=y;l>0;l-=l&-l)res+=T[x][l];
    }
    return res;
}
int main()
{
    cin>>n>>q;
    string s;
    vector<string>M;
    for(int i=0;i<n;i++){
        cin>>s;
        M.pb(s);
        for(int l=0;l<n;l++){
            if(s[l]=='*'){
                update(i,l,1);
            }
        }
    }
    while(q--){
        int c,x1,x2,y1,y2;
        cin>>c;
        if(c==1){
            cin>>x1>>y1;
            x1--;y1--;
            if(M[x1][y1]=='*'){
                M[x1][y1]='.';
                update(x1,y1,-1);
            }else{
                M[x1][y1]='*';
                update(x1,y1,1);
            }
        }else{
            cin>>x1>>y1>>x2>>y2;
            x1--;y1--;x2--;y2--;
            cout<<query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1)<<endl;
        }
    }
    
    return 0;
}
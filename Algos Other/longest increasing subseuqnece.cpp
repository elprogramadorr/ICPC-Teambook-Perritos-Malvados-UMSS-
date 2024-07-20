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
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;
//gcd(a,b)= ax + by
//lCB x&-x
//set.erase(it) - ersases the element present at the required index//auto it = s.find(element)
//set.find(element) - iterator pointing to the given element if it is present else return pointer pointing to set.end()
//set.lower_bound(element) - iterator pointing to element greater than or equal to the given element
//set.upper_bound(element) - iterator pointing to element greater than the given element
// | ^
//__builtin_popcount(x)
using namespace std;
 O(n log n)
 
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    vll d(n+2,1e9);//pongo a todos como infinito que sería como la "peor" situacióm para cada estado
    d[0]=-1e9;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int b=1,e=n;
        while(b<=e){
            int mid=(b+e)/2;
            if(a[i]<d[mid] && a[i]>d[mid-1]){
                d[mid]=a[i];
 
                break;
            }
            if(d[mid]>a[i]){
                e=mid-1;
            }else{
                b=mid+1;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(d[i]!=1e9)res=i;
    }
    cout<<res<<endl;
    return 0;
}

//implementacion chevere
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vll vector<ll>
#define F first
#define S second
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//"\n" __builtin_popcount
using namespace std;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")


int  main(){
   int n,x;
   n=v.size();
   multiset<int>st;
   for(int i=0;i<n;i++){
      x=v[i];
      auto it=st.lower_bound(x);
      if(it==st.end()){
         st.insert(x);
      }else{
         st.erase(it);
         st.insert(x);
      }
   }
   cout<<st.size()<<endl;
   
   return 0;
}
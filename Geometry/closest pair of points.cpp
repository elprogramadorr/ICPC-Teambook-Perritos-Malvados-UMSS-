#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define jumanji ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
#define int long long
#define x first
#define y second
using namespace std;
long long dist2(pair<int, int> a, pair<int, int> b) {
	return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}
pair<int, int> closest_pair(vector<pair<int, int>> a) {
	int n = a.size();
	assert(n >= 2);
	vector<pair<pair<int, int>, int>> p(n);
	for (int i = 0; i < n; i++) p[i] = {a[i], i};
	sort(p.begin(), p.end());
	int l = 0, r = 2;
	long long ans = dist2(p[0].x, p[1].x);
	pair<int, int> ret = {p[0].y, p[1].y};
	while (r < n) {
		while (l < r && 1LL * (p[r].x.x - p[l].x.x) * (p[r].x.x - p[l].x.x) >= ans) l++;
		for (int i = l; i < r; i++) {
			long long nw = dist2(p[i].x, p[r].x);
			if (nw < ans) {
				ans = nw;
				ret = {p[i].y, p[r].y};
			}
		}
		r++;
	}
	return ret;
}
signed main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >E(n);
    vi pref(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        pref[i]=x;
        if(i)pref[i]+=pref[i-1];
        E[i]={i,pref[i]};
    }
    pair<int,int> res=closest_pair(E);
    int a=res.F,b=res.S;
    cout<<(E[a].F-E[b].F)*(E[a].F-E[b].F)+(pref[b]-pref[a])*(pref[b]-pref[a])<<endl;
    return 0;
}
// https://codeforces.com/contest/429/problem/D
/*
Retorna indices (index 0) de los puntos mas cercanos.
Time: O (n log n)
*/
long long dist2(pair<int, int> a, pair<int, int> b) {
    return 1LL * (a.F - b.F) * (a.F - b.F) + 1LL * (a.S - b.S) * (a.S - b.S);
}

pair<int, int> closest_pair(vector<pair<int, int>> a) {
    int n = a.size();
    assert(n >= 2);
    vector<pair<pair<int, int>, int>> p(n);
    for (int i = 0; i < n; i++) p[i] = {a[i], i};
    sort(p.begin(), p.end());
    int l = 0, r = 2;
    long long ans = dist2(p[0].F, p[1].F);
    pair<int, int> ret = {p[0].S, p[1].S};
    while (r < n) {
        while (l < r && 1LL * (p[r].F.F - p[l].F.F) * (p[r].F.F - p[l].F.F) >= ans) l++;
        for (int i = l; i < r; i++) {
            long long nw = dist2(p[i].F, p[r].F);
            if (nw < ans) {
                ans = nw;
                ret = {p[i].S, p[r].S};
            }
        }
        r++;
    }
    return ret;
}
struct RB_DSU_Parity {
    vector<pair<int, int>> P;
    vi sz, st;
    vector<bool> bipart;
    int scc, conflict;

    void init(int n) {
        P.resize(n+1); sz.assign(n+1,1); bipart.assign(n+1, true);
        iota(P.begin(), P.end(), 0); scc = n; conflict = 0;
    }

    pair<int, int> find(int a) {
        if (P[a].first == a) return P[a];
        auto p = find(P[a].first);
        return {p.first, p.second ^ P[a].second};
    }

    void _union(int a, int b) {
        auto pa = find(a), pb = find(b);
        int ra = pa.first, rb = pb.first;
        if (ra == rb) {
            if (pa.second == pb.second) conflict++, bipart[ra] = false, st.push_back(-ra);
            return;
        }
        if (sz[ra] < sz[rb]) swap(ra, rb), swap(pa, pb);
        P[rb] = {ra, pa.second ^ pb.second ^ 1};
        sz[ra] += sz[rb];
        bipart[ra] = bipart[ra] && bipart[rb];
        st.push_back(rb); scc--;
    }

    void rollback(int t) {
        while (st.size() > t) {
            int u = st.back(); st.pop_back();
            if (u < 0) conflict--, bipart[-u] = true;
            else {
                sz[P[u].first] -= sz[u];
                P[u] = {u, 0}; scc++;
            }
        }
    }

    bool is_bipartite() { return !conflict; } // Grafo general
    bool is_bipartite(int a) { return bipart[find(a).first]; } // Conjunto conexo específico
};
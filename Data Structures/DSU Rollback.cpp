/*
Para sacar checkpoint int CP = st.size()
Para rollback rollback(CP)
LLamar a init(n) al inicio

Note.- index 1 de los nodos, cuidado con los indices de las aristas al hacer Dynamic Connectivity 
dynamic connectivity se realiza sobre los indices de las queries simulando el paso del tiempo
y las aristas viven en ciertos rangos de tiempo (se simula con dfs y segment tree)

Time Complexity: O(log(n)) para find y union
*/

struct RB_DSU {
    vi P;
    vi sz;
    stack<int> st;
    int scc;

    void init(int n) {
        P.resize(n+1);
        sz.resize(n+1, 1);
        scc = n;
        for (int i = 1; i <= n; i++) P[i] = i;
    }
    
    int _find(int a) {
        if (P[a] == a)
            return a;
        return _find(P[a]);
    }

    void _union(int a, int b) {
        a = _find(a);
        b = _find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        P[a] = b;
        sz[b] += sz[a];
        scc--;
        st.push(a);
    }

    void rollback(int t) {
        while (st.size() > t) {
            int a = st.top();
            st.pop();
            sz[P[a]] -= sz[a];
            P[a] = a;
            scc++;
        }
    }
};
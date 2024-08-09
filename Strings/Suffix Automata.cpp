/*
Automata tiene 2*|s| nodos
sa[nodo].cnt = cantidad de matcheos de este nodo, es decir cantidad de substrings matcheados hasta nodo
para calcular cantidad de strings que se pueden llehar desde un nodo hacer una dp
dp[nodo] = sa[nodo].cnt + dp[hijo_s]
R = sa[nodo].len = substring mas grande matcheado (camino mas largo)
L = sa.sa[sa.sa[nodo].link].len+1; es el camino mas corto desde 0 hasta nodo. desde cero hasta nodo hay substrings de sz [L,R] cada camino matchea un substring distinto.

Todos los substrings hasta nodo/estado tienen la misma cantidad de ocurrencias en el string sa[nodo].cnt

Todos los strings correspondientes a un nodo son sufijos distintos del substring len.

El nodo inicial del SA es 0 y te mueves con sa[nodo].nxt[c] solo si sa[nodo].nxt.count(c)
*/

struct suffix_automaton {
    struct node {
        int len, link, cnt, first_pos; bool end; /// cnt is endpos size, first_pos is minimum of endpos
        map<char, int> next;
    };
    vector<node> sa;
    int last;
    suffix_automaton() {}
    suffix_automaton(string &s) {
        sa.reserve(s.size()*2);
        last = add_node();
        sa[last].len = sa[last].cnt = sa[last].first_pos = sa[last].end = 0;
        sa[last].link = -1;
        for(char c : s) sa_append(c);
        mark_suffixes();
        build_cnt();
    }
    int add_node() {
        sa.push_back({});
        return sa.size()-1;
    }
    void mark_suffixes() {
        ///t0 is not suffix
        for(int cur = last; cur; cur = sa[cur].link)
            sa[cur].end = 1;
    }
    /// This is O(N*log(N)). Can be done O(N) by doing dfs and counting paths to terminal nodes. a veces no es necesario el cnt
    void build_cnt() {
        vector<int> order(sa.size()-1);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(), [&](int a, int b) { return sa[a].len > sa[b].len; });
        for(auto &i : order) sa[ sa[i].link ].cnt += sa[i].cnt;
        sa[0].cnt = 0; /// t0 is empty string 
    }
    void sa_append(char c) {
        int cur = add_node();
        sa[cur].len = sa[last].len + 1;
        sa[cur].end = 0; sa[cur].cnt = 1;
        sa[cur].first_pos = sa[cur].len-1;
        int p = last;
        while(p != -1 && !sa[p].next[c] ){
            sa[p].next[c] = cur;
            p = sa[p].link;
        }
        if(p == -1) sa[cur].link = 0;
        else {
            int q = sa[p].next[c];
            if(sa[q].len == sa[p].len+1) sa[cur].link = q;
            else {
                int clone = add_node();
                sa[clone] = sa[q];
                sa[clone].len = sa[p].len+1;
                sa[clone].cnt = 0;
                sa[q].link = sa[cur].link = clone;
                while(p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
            }
        }
        last = cur;
    }
    node& operator[](int i) { return sa[i]; }
};

// Node *T = new Node; 
// query(T, 0, top, 0, top);  top = 1e9 e.g.
// update(T, 0, top, y1, y2);
struct Node {
    int valor;
    int lazy;
    Node *L, *R;
    Node() : valor(0), lazy(0), L(NULL), R(NULL) {}
    void propagate(int b, int e) {
        if (lazy == 0) return;
        lazy = 0;
        valor = (e - b + 1) - valor;
        if (b == e) return;
        if (!L) L = new Node();
        if (!R) R = new Node();
        L->lazy ^= 1;
        R->lazy ^= 1;

        // esta vaina no es necesaria solo cuando da MLE
        if (L && L->lazy == 0 && L->valor == 0) {
            delete L;
            L = NULL;
        }
        if (R && R->lazy == 0 && R->valor == 0) {
            delete R;
            R = NULL;
        }
    }
};

void update(Node *nodo, int b, int e, int izq, int der) {
    nodo->propagate(b, e);
    if (b > der || e < izq) return;
    if (b >= izq && e <= der) {
        nodo->lazy ^= 1;
        nodo->propagate(b, e);
        return;
    }
    int mid = (b + e) / 2;
    if (!nodo->L) nodo->L = new Node();
    if (!nodo->R) nodo->R = new Node();
    update(nodo->L, b, mid, izq, der);
    update(nodo->R, mid + 1, e, izq, der);
    nodo->valor = nodo->L->valor + nodo->R->valor;
}

int query(Node *nodo, int b, int e, int izq, int der) {
    if (b > der || e < izq) return 0;
    nodo->propagate(b, e);
    if (b >= izq && e <= der) return nodo->valor;
    int mid = (b + e) / 2;
    return query(nodo->L, b, mid, izq, der) + query(nodo->R, mid + 1, e, izq, der);
}

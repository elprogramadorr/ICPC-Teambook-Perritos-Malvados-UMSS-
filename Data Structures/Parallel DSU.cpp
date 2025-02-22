// Para establecer que dos substrings/subarreglos son iguales
// Mantener conjuntos las posiciones que obligatoriamente tienen que ser iguales
// para s[p1, p1+1, ..., p1+len-1] = s[p2, p2+1, ..., p2+len-1]
// es qeuivalente a hacer _union(p1, p2), _union(p1+1, p2+2) ...
// Nota .- Para problemas de palindromos puedes concatenar el reverse del string al final
// index-0

struct DSU {
    vi P;
    void init(int N) {
        P.resize(N+2);
        for(int i=0;i<=N+1;i++)P[i]=i;
    }
    int _find(int nodo) {
        if(P[nodo]==nodo)return nodo;
        return P[nodo]=_find(P[nodo]);
    }
    void _union(int a, int b) {
        a=_find(a); b=_find(b);
        P[b]=a;// para palindromos (primera mitad padres)
    }
};

int n; // tamanio del string
DSU nivel[22];

// s[p1, p1+1, ..., p1+len-1] = s[p2, p2+1, ..., p2+len-1]
void equal(int p1, int p2, int len){// para definir dos substrings iguales
    int k=0;
    while((1<<(k+1))<=len) k++;
    nivel[k]._union(p1, p2);
    nivel[k]._union(p1+len-(1<<k), p2+len-(1<<k));
}

void build(){// no olvidar llamar
    for(int k=20;k>=1;k--){
        for(int i=0;i<=n-(1<<k);i++){
            int j = nivel[k]._find(i);
            nivel[k-1]._union(i, j);
            nivel[k-1]._union(i+(1<<(k-1)), j+(1<<(k-1)));
        }
    }
}

int inv(int pos){// para palindromos
    return n - 1 - pos;
}

// main
for(int i=0;i<=20;i++){
    nivel[i].init(n);
}
for(int i=0;i<ns;i++){// para palindromos
    equal(i, inv(i), 1);
}

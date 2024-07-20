// nodo 0 es el nodo inicial, significa que no matcheo nada
// nodo s.size() es el nodo final, significa que matcheo todo
const int MAXN = 1e5 + 5, alpha = 26;
const char L = 'A'; // ojo aqui es el elemento más bajo del alfabeto
int go[MAXN][alpha]; // go[i][j] = a donde vuelvo si estoy en i y pongo una j
void build(string &s) {
    int lps = 0;
    go[0][s[0]-L] = 1;
    int n = s.size();
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < alpha; j++) go[i][j] = go[lps][j];
        if (i < n) {
            go[i][s[i]-L] = i + 1;
            lps = go[lps][s[i]-L];
        }
    }
}

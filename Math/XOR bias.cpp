// una representacion minima (no redundante) de los numeros en terminos de combinaciones XOR
// se pueden formar 2 ^ (bias.size()) numeros distintos con el xor de algun subconjunto

vi get_bias(vi v){
    vi res;
    for(auto num : v){
        for(auto it2 : res){
            num=min(num,num^it2);
        }
        if(num) res.pb(num);
    }
    return res;
}
 
vi _merge(vi A, vi B){
    vi res = A;
    for(auto num : B){
        for(auto it2 : res){
            num=min(num,num^it2);
        }
        if(num) res.pb(num);
    }
    return res;
}

// chequear si se puede formar el numero x con xor de algunos elementos de basi
bool check(vi &basi, int x){
    for(auto it : basi){
        x=min(x,x^it);
    }
    return x==0;
}

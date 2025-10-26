#include <bits/stdc++.h>

using namespace std;

/* exponenciacao modular rapida
decompoe o expoente na base 2. Eleva os resultados intermediarios ao quadrado (bases)
e atualiza o resultado só quando a instancia atual da base corresponder a uma potencia de 2
do expoente
*/ 
long long modPot(long long mod, long long base, long long pot) {
    __int128_t b = base % mod; // assumira os valores de (base%mod) elevado a potencias de 2
    __int128_t result = 1; 
    for (long long int i = pot; i > 0; i = i>>1) {
        if (i%2) {//pot atual é impar (bit final é 1)
            result = (result*b) % mod; //result * base vai construir a potencia final que queremos
        }
        b = (b*b) % mod; //atualiza a base para a potencia seeguinte de 2
    }

    return result;
}

long long proximoPrimo(long long n) {    
    long long p = n;
    while (true) {
        p++;
        if (p <= 1) continue;  
        if (p <= 3) return p; //2 e 3

        if (p % 2 == 0 || p % 3 == 0) continue; 

        bool ehPrimo = true;
        for (int i = 5; (long long)i*i <= p; i += 6) { //pula multiplos de 2 e 3
            if (p % i == 0) {//verifica numeros da forma 6i + 5 
                ehPrimo = false;
                break;
            }
            if ( p % (i+2) == 0) { //verifica numeros da forma 6i + 1 
                ehPrimo = false;
                break;
            }
        }

        if (ehPrimo) return p;
    }
    return -1;
}

int main () {
    long long n, t; cin >> n >> t;
    long long p = proximoPrimo(n);
    //pelo pequeno teorema de fermat temos:
    // a = t^(p-2)
    long long saida = modPot(p, t, p-2);
    cout << saida << endl;     
}
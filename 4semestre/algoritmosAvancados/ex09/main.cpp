#include <bits/stdc++.h>

using namespace std;

const int MIN = -99999999;

void resolver_fase() {
    
}

int main() {

    int x; // Número de fases
    cin >> x;
    
    // Roda a solução para cada fase
    while (x--) {
        int diamantes, n;
        cin >> diamantes >> n;

        vector<int> valores(n);
        for (int i = 0; i < n; ++i) { //le valoes
            cin >> valores[i];
        }
        
        int dp[n+1][3]; //dp[i][] representa o n de diamantes ao final do dia i-1
        for (int i = 0; i <= n; i++) { //prenche a dp
            dp[i][0] = MIN;
            dp[i][1] = MIN;
            dp[i][2] = MIN;
        }
        // estados:
        // 0 livre sem passe
        // 1 livre com passe
        // 2 descanso obrigatorio

        dp[0][0] = diamantes; //dia inicial

        //itera pelos dias
        for (int i = 1; i <= n; ++i) {
            // custo/ganho para o dia atual (i-1)
            int valor_dia = valores[i - 1];

            //terminar o dia livre sem passe, maximo entre:
            //estar livre e nao fazer nada
            //descanso obrigatorio 
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            
            //termina o dia livre com passe, maximo entre:
            //estar livre e com passe e nao fazer nada
            // comprar o passe (desperdicando os diamantes na casa i-1) 
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - valor_dia);

            //terminar o o dia com descanso obrigatorio:
            //é necessario garimpar no dia i-1 -> gera lucro 
            dp[i][2] = dp[i - 1][1] + valor_dia;
        }

        //resposta é dada pelo maior numero de diamantes ao final do ultimo dia representado por um dos 3 estados
        int resposta = max({dp[n][0], dp[n][1], dp[n][2]});

        cout << resposta << endl;
    }
}
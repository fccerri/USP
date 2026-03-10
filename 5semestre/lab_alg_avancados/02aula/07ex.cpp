#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    vector<pair<int, int>> tarefas; //first = inicio, second = fim
    for (int i = 0; i < n ; i++) {
        int inicio, fim; cin >> inicio >> fim;
        tarefas.push_back({inicio, fim});
    }

    sort(tarefas.begin(), tarefas.end(), //ordena com base no inicio
    [](const pair<int, int> esquerda, const pair<int, int> direita) {
            return esquerda.first < direita.first;
        });

    long int horario = 0, pontos = 0;
    for (int i = 0 ; i < n; i++) {
        horario += tarefas[i].first; //atualiza os horarios
        pontos += (tarefas[i].second - horario); //contabiliza os pontos
    }

    cout << pontos;
}

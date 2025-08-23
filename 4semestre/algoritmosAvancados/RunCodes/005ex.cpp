#include <functional>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

const double R = 6371;

using namespace std;

struct jogador{
    string nome;
    double latitude;
    double longitude;
    double distancia;
    int id;

    bool operator > (jogador j) const{
        if (this->distancia == j.distancia)
            return this->id > j.id; //garante ordenacao na ordem de entradad
        return this->distancia > j.distancia;
    }

    jogador(int id) : nome(""), latitude(0.0f), longitude(0.0f), distancia(0.0f), id(id) {}

    double haversine (jogador base) {
        double latOrigemRad = this->latitude * M_PI / 180.0;
        double lonOrigemRad = this->longitude * M_PI / 180.0;
        double latDestinoRad = base.latitude * M_PI / 180.0;
        double lonDestinoRad = base.longitude * M_PI / 180.0;

        double dLat = latDestinoRad - latOrigemRad;
        double dLon = lonDestinoRad - lonOrigemRad;

        double part1 = sin(dLat / 2);
        double part2 = sin(dLon / 2);

        double a = part1 * part1 + cos(latOrigemRad) * cos(latDestinoRad) * part2 * part2;

        double d = 2 * R * asin(sqrt(a));

        this->distancia = d;
        return d;
    }

};


int main () {
    int m; 
    jogador base(-1);
    cin >> m >> base.latitude >> base.longitude;

    priority_queue<jogador,vector<jogador>, greater<jogador>> jogadores;

    for (int i = 0; i < m; i++) {
        jogador j(i);
        cin >> j.nome >> j.latitude >> j.longitude;
        j.haversine(base); //calcula a distancia

        jogadores.push(j); //insere na heap 
        printf("> [AVISO] MELHOR PALPITE: %.3fkm\n", jogadores.top().distancia);

    }

    //printa o ranking
    printf("\nRANKING\n-------\n");
    for (int i = 1; !jogadores.empty(); i++) {
        jogador j = jogadores.top();
        jogadores.pop();
        
        printf("%2d. %-20s : %6.3f km", i, j.nome.c_str(), j.distancia);

        if (j.distancia < 0.050f) {
            printf(" [FANTASTICO]\n");
        } else {
            printf("\n");
        }
    }
}
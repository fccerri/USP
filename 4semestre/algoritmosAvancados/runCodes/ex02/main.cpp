#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dia {
    string data; //DD/MM/AAAA
    double ganho;

    dia(): data(""), ganho(0.00) {}; //construtor

    static bool comparaValor (dia a, dia b) { //metodo estatico para comparar dias por ganho
        return a.ganho > b.ganho; //ordena de ordem crescente
    }

    // const & evita copias desnecessarias
    static bool comparaData (const dia &a, const dia &b)  { //metodo estatico para comparar dias por data
        string data_a, data_b;
        data_a = a.data.substr(6, 4) + a.data.substr(3, 2) + a.data.substr(0, 2);
        data_b = b.data.substr(6, 4) + b.data.substr(3, 2) + b.data.substr(0, 2);
        //ordena de ordem decrescente
        return data_a < data_b; //compara as data priorizando A > M > D
    }

};

struct conjunto {
    vector<dia> dias;
    double soma;
    int tam;

    conjunto(): tam(0), soma(0) {}

    void adicionaDia (dia d) {
        dias.push_back(d);
        tam++;
        soma += d.ganho;
    }

    conjunto determinaSubconjunto() {
        conjunto subconjunto;
        vector<dia> aux = this->dias; 
        double soma_parcial = this->soma;
        //ordena os dias por valor de ordem crescente
        sort(aux.begin(), aux.end(), dia::comparaValor);

        //loop enquanto o subconjunto nao estiver completo
        for (int i =0; i < tam && subconjunto.soma < soma_parcial; i++) {
            subconjunto.adicionaDia(aux[i]); //add dia no subconjunto
            soma_parcial -= aux[i].ganho;
        }

        //ordena o subconjunto pelas datas de ordem decrescente
        sort(subconjunto.dias.begin(), subconjunto.dias.end(), dia::comparaData);

        return subconjunto;
    }

    void printaSubconjunto(int tamConjunto /*tam do conjunto pai*/) {
    int qtd_dias = this->tam;
        
        //imprime qtd de dias
        printf("%d %s (", qtd_dias, (qtd_dias == 1 ? "dia" : "dias"));
        
        //imprime datas cronologicamente
        for (int i = 0; i < qtd_dias; i++) {
            if (i > 0) printf(", ");
            printf("%s", dias[i].data.c_str());
        }
        
    
        printf(") | soma=%.2f | %.2f%% dos dias totais\n", this->soma, (qtd_dias * 100.0) / tamConjunto);
    }
};

int main () {
    int m; cin >> m;
    while (m--) {
        int n; cin >> n;
        conjunto principal, subconjunto;
        for (int i = 0; i < n; i++) {
            dia d; cin >> d.data >> d.ganho;
            principal.adicionaDia(d); //add dia no conjunto principal
        }

        subconjunto = principal.determinaSubconjunto(); //determina o subconjunto

        subconjunto.printaSubconjunto(principal.tam);
    }
}
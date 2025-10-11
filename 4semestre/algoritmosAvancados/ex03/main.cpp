#include <bits/stdc++.h>

using namespace std;


struct solicitacao {
    int cliente;
    int carro;
    int entrada;
    int saida;

    solicitacao (int cliente, string hrRetirada, string hrDevolucao, int carro) {
        this->cliente = cliente;
        this->carro = carro;
        entrada = converterParaMinutos(hrRetirada);
        saida = converterParaMinutos(hrDevolucao);

    };
    
    int converterParaMinutos(string hora) {
        size_t pos = hora.find(':');
        int h = stoi(hora.substr(0, pos));
        int m = stoi(hora.substr(pos + 1));
        return h * 60 + m;
    }

    bool operator<(const solicitacao s) {
        if (this->saida != s.saida) return this->saida < s.saida; // ordena por saida
        if (this->entrada != s.entrada) return this->entrada < s.entrada;// desempara por entrada
        if (this->cliente != s.cliente) return this->cliente < s.cliente; //desempata por id

        return true; //evita warning
    }

};
struct manager {
    map<int, vector<solicitacao>> modelos;

    void addSolicitacao(solicitacao s) {
        modelos[s.carro].push_back(s);
    }

    string opera(int n) {
        vector<string> resultados;

         for (int id = 1; id <= n; id++) {
            vector<solicitacao>& solicitacoes = modelos[id];

            ///ordena solicitacoes
            sort(solicitacoes.begin(), solicitacoes.end());

            vector<int> clientesAtendidos;
            int ultimaSaida = -1;
            
            for (auto& s : solicitacoes) {
                if (s.entrada >= ultimaSaida) {

                    clientesAtendidos.push_back(s.cliente);
                    ultimaSaida = s.saida;
                }
            }

            
            // formata o resultado
            stringstream resultado;
            resultado << id << ": " << clientesAtendidos.size();
            if (!clientesAtendidos.empty()) {
                resultado << " = ";
                for (size_t i = 0; i < clientesAtendidos.size(); i++) {
                    if (i > 0) resultado << ", ";
                    resultado << clientesAtendidos[i];
                }
            }
            resultados.push_back(resultado.str());
        }
        
        //junta os resultados
        stringstream saidaFinal;
        for (size_t i = 0; i < resultados.size(); i++) {
            if (i > 0) saidaFinal << " | ";
            saidaFinal << resultados[i];
        }
        
        return saidaFinal.str();
    }
};



int main () {
    int x; cin >> x;

    while (x--) {
        int n, m; cin >> n >> m;
        manager g;
        for (int i = 0; i < m; i++) {
            int idCliente, idModelo;
            string hrRetirada, hrDevolucao;
            
            cin >> idCliente >> hrRetirada >> hrDevolucao >> idModelo;
            
            solicitacao s(idCliente, hrRetirada, hrDevolucao, idModelo);
            g.addSolicitacao(s);
        }

        cout << g.opera(n);
        if (x != 0) cout << endl;
    }
    

}

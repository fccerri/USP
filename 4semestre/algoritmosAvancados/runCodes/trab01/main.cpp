#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct no {
    char c; //caracter do no 
    no *filhos[26];
    bool ehFim; //fim de uma palavra

    no (char c = '\0') {
        this->c = c;
        this->ehFim = false;
        for (auto& f : filhos) 
            f = nullptr;
    }
};

struct Trie {
    no *raiz;
    vector<string> encontradas; //palavras encontradas

    Trie () {raiz = new no;}

    ~Trie() { //destrutor
        deletaTrie(raiz);
    }

    void deletaTrie(no* atual) {
        if (atual == nullptr) { //caso base
            return;
        }

        for (int i = 0; i < 26; i++) { //percorre todos os filhos 
            if (atual->filhos[i] != nullptr) {
                deletaTrie(atual->filhos[i]);
            }
        }

        //deleta o no atual
        delete atual;
    }

    void addPalavra(string p) {
        no *atual = raiz;

        for (int i = 0; i < p.size(); i ++) {
            int idx = p[i] - 'A'; //determina o indice da letra atual
            
            if (atual->filhos[idx] == nullptr) { //se a proxima letra nao existir
                atual->filhos[idx] = new no(p[i]); //cria um novo no
   
            }
            
            atual = atual->filhos[idx]; //conecta o novo no 

        }

        atual->ehFim = true; //marca o final da palavra
    }

    void busca(string p) {
        no *atual = raiz;

        for (int i = 0; i < p.size(); i ++) {
            int idx = p[i] - 'A'; //determina o indice da letra atual
            atual = atual->filhos[idx]; //recebe proximo no
            if (atual != nullptr) { //enquanto existir elementos nesse caminho
                if (p[i] == atual->c) {
                    if (atual->ehFim) //se for uma palavra
                        encontradas.push_back(p.substr(0,i+1)); //passa a string encontrada

                }
            }
            else //nao existem mais palavaras para encontrar;
                return; 
                

        }

    }

    void printaEncontradas() {
        sort(encontradas.begin(), encontradas.end());

        cout << encontradas.size() << endl;
        for (auto s :encontradas)
            cout << s << endl;
    }
};

int main () {
    int L, C; cin >> L >> C;
    char matriz[50][50];
    
    for (int i = 0; i < L; ++i) { //le a entrada
        for (int j = 0; j < C; ++j) {
            cin >> matriz[i][j];
        }
    }

    Trie T; string temp;
    int D; cin >> D;
    for (int i = 0; i < D; i++) { //le a entrada
        cin >> temp;
        // cout << temp << endl;
        T.addPalavra(temp);     
    }


    // arrays auxiliares com todas as combinacoes de direcoes
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // percorre todas as celulas da matriz
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            ///percorre as oito direcoes
            for (int k = 0; k < 8; ++k) {
                string aux = "";
                int nLinha = i; //nova linha
                int nColuna = j; //nova coluna

                // continua ate o final da matriz
                while (nLinha >= 0 && nLinha < L && nColuna >= 0 && nColuna < C) {
                    aux += matriz[nLinha][nColuna];

                    //move para a proxima direcao
                    nLinha += dx[k];
                    nColuna += dy[k];
                }
                T.busca(aux); //busca palavras e add em T.encontradas
            }
        }
    }

    T.printaEncontradas();

    return 0;
}

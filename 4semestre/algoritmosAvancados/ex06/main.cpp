#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct no {
    double e;
    double v;

    static double orientacao(no a, no b, no c) {
        return (b.e - a.e)*(c.v - a.v) - (b.v - a.v)*(c.e - a.e);
    }

     bool operator < (const no &n) const {
        if (e == n.e)
            return v < n.v;
        return e < n.e;
    }

    bool operator==(no o) const {
        return e == o.e && v == o.v;
    }

};

struct fecho {
    vector<no> nos;

    void printaFecho(int caso, const vector<no>& fecho) {
        cout << "Caso " << caso << ":\n";
        cout << "Tamanho do colar: " << fecho.size() << "\n";
        cout << "Pedras ancestrais: ";
        for (size_t i = 0; i < fecho.size(); i++) {
            cout << "(" << fixed << setprecision(4) << fecho[i].e
                 << "," << fixed << setprecision(4) << fecho[i].v << ")";
            if (i + 1 < fecho.size()) cout << ",";
        }
        cout << "\n\n";
    }

    vector<no> fechoConvexo() {
        sort(nos.begin(), nos.end());

        return fechoRecursivo(nos);
    }

    private:
        vector<no> fechoRecursivo(vector<no> f) {
            if (f.size() <= 3) { //caso base
                if (f.size() <= 2) return f;

                double area = no::orientacao(f[0], f[1], f[2]);

                if (area < 0) swap(f[1], f[2]); // garante sentido anti-horario

                return f;
            }

            int meio = f.size() / 2;
            vector<no> esquerda(f.begin(), f.begin() + meio);
            vector<no> direita(f.begin() + meio, f.end());

            vector<no> conjuntoEsq = fechoRecursivo(esquerda);
            vector<no> conjuntoDir = fechoRecursivo(direita);

            return combina(conjuntoEsq, conjuntoDir); //combina os fechos
        }

        vector<no> combina(vector<no>& A, vector<no>& B) {
            //concatena os pontos
            vector<no> pts = A;
            pts.insert(pts.end(), B.begin(), B.end());
            
            //ordena 
            sort(pts.begin(), pts.end());
                        
            if (pts.size() <= 2) return pts;
            
            // vrifica colinearidade
            bool todosColineares = true;
            for (int i = 2; i < pts.size(); i++) {
                if (fabs(no::orientacao(pts[0], pts[1], pts[i])) > 0) {
                    todosColineares = false;
                    break;
                }
            }
            
            // se todos colineares, retorna todos os pontos na ordem
            if (todosColineares) {
                return pts;
            }
            
            vector<no> lower, upper;
            
            // tangente inferior
            for (auto p : pts) {
                while (lower.size() >= 2 && no::orientacao(lower[lower.size()-2], lower[lower.size()-1], p) < 0)
                    lower.pop_back();
                lower.push_back(p);
            }
            
            // tangente superior
            for (int i = pts.size()-1; i >= 0; i--) {
                auto p = pts[i];
                while (upper.size() >= 2 && no::orientacao(upper[upper.size()-2], upper[upper.size()-1], p) < 0)
                    upper.pop_back();
                upper.push_back(p);
            }
            
            // evita duplicacao
            lower.pop_back();
            upper.pop_back();
            
            lower.insert(lower.end(), upper.begin(), upper.end());
            
            return lower;
        }

};

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        fecho f;
        for (int j = 0; j < n; j++) {
            no n; cin >> n.e >> n.v;
            f.nos.push_back(n);
        }

        vector<no> resultado = f.fechoConvexo();

        int start = 0; //acha o menor no do fecho para impressao
        for (int k = 1; k < resultado.size(); k++) {
            if (resultado[k] < resultado[start]) start = k;
        }

        //desloca o menor no para o inicio do vetor
        rotate(resultado.begin(), resultado.begin() + start, resultado.end());

        f.printaFecho(i, resultado);
    }
}
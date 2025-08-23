#include <iostream>
#include <map>

using namespace std;

struct produto {
	string codigo;
	float preco;
};

struct loja {
	map<string, produto> estoque;

	void cadastrar_produto(produto p) {
		if (this->estoque.count(p.codigo) == 0)
			this->estoque[p.codigo] = p;
		else
			cout << "Produto com código " << p.codigo << " já cadastrado." << endl;
	}

	float checar_produto(produto p) { //retorna o valor do produto
		if (this->estoque.count(p.codigo) == 0) 
			cout << "Produto com código " << p.codigo << " não cadastrado." << endl;
		else
			return this->estoque[p.codigo].preco;

		return 0;
	}

};

int main() {
	loja louja;
	int n; cin >> n;
	while (n--) {
		produto p; cin >> p.codigo >> p.preco;
		louja.cadastrar_produto(p);
	}

	int m;
	float precoTotal = 0, peso = 0;
	while (1) {
    	cin >> m;
    	if (m == -1) break;  // criterio de parada

    	precoTotal = 0;
    	for (int i = 0; i < m; i++) {
    	    produto p; cin >> p.codigo >> peso;
    	    precoTotal += peso*louja.checar_produto(p); 
    	}

    	printf("R$%.2f\n", precoTotal);
	}

}


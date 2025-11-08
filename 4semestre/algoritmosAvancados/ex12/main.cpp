#include <bits/stdc++.h>

using namespace std;

struct aresta {
    int u;
    int v;
    int cost;

    bool operator < (aresta b) {
        return this->cost < b.cost;
    }
};

int minCost;

struct DSU {
    map<int, int> sets;
    int numberOfSets;

    DSU(int n) {
        for (int i = 1; i <= n; i++) {
            sets[i] = i;
        }
        numberOfSets = n;
    }

    int find(int a) {
        if (sets[a] == a) {
            return a;
        }
        return sets[a] = find(sets[a]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find (b);
        if (rootA != rootB) {
            sets[rootA] = rootB;
            numberOfSets--;
        }
    }

    vector<aresta> solve(vector<aresta> bridges) {
        vector<aresta> mst; int previousCost = -1;
        for (auto &a : bridges) {
            if (previousCost == a.cost) {
                minCost= -1;
                return mst;
            }
            if (find(a.u) != find(a.v)) {
                unite(a.u, a.v);
                minCost += a.cost;
                mst.push_back(a);
            }
            previousCost = a.cost;
        }

        return mst;
    }
};

int main () {
    int x; cin >> x;
    while (x--) {
        int n, m; cin >> n >> m;
        DSU d(n); vector<aresta> bridges;
        for (int i = 0; i < m; i++) {
            aresta a; cin >> a.u >> a.v >> a.cost;
            bridges.push_back(a);
    
        }

        

        sort(bridges.begin(), bridges.end());
        minCost = 0;
        vector<aresta> mst = d.solve(bridges);

        if (minCost == -1) {
            cout << "Esse nao e o caminho correto para a Cidade Perdida de Z." << endl << endl;
            continue;
        };
        if (mst.size() != n - 1) {
            cout << "O vale nao pode ser completamente atravessado." << endl << endl;
            continue;
        }

        cout << "Custo minimo: " << minCost << endl;
        cout << "Pontes reconstruidas:" << endl;
        for (auto &a: mst) {
            cout << a.u << " - " << a.v << endl;
        }
        cout << endl;
    }
}
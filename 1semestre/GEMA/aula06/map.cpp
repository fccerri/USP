#include <bits/stdc++.h>
using namespace std;

int main () {

    map < string, double> mapa;

    unordored_map < string, double> mapa1; //menos custoso em O(1), mas pode dar merda

    mapa["joao"] = 9.5; //se ja existir substitui, se nao cria

    for (auto it = mapa.begin(); it != mapa.end(); it++) {
        string key = (*it).first;
        double val = (*it).second
    }
}
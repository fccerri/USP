#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a>b;
}


int main () {

    vector<int> v = {1, 5, 3, 70, 2};

    sort(v.begin(), v.end()); //ordena de ordem crescente

    sort(v.begin(), v.end(), cmp); //ordena de ordem decrescnete

}
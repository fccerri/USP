#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m; cin >> n >> m ;
    unordered_map<string, string> servidores; 
    string ip, server, comando;

    while (n--){
        cin >> server >> ip;
        servidores[ip] =  server; //guarda o servido no map com key ip
    }

    while (m--){
        cin >> comando >> ip;
        ip.pop_back(); //trata o ip
        string s = servidores[ip]; //procura o server pelo ip
        cout << comando << " " << ip << "; #" << s << endl; 
    }
}

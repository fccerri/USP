#include <iostream>
#include <unordered_map>

using namespace std;

struct pessoa {
    int pai_id;
    int mae_id;
    bool diabetes; //1 = sim; 0 = nao

    pessoa(): pai_id(-1), mae_id(-1), diabetes(0) {}; //construtor

};

int main (){
    int x; cin >> x;
    while (x--) {
        int n; cin >> n;

        unordered_map<int, pessoa> familia;
        pessoa p; p.diabetes = 0;

        int id;
        string tmp;
        for ( int i = 0; i < n; i++) { //insere
            cin >> id >> tmp >> p.pai_id >> p.mae_id;

            p.diabetes = (tmp.front() == 's'); 

            familia[id] = p;
        }
        
        int count = 0;
        for (auto pair : familia) {
            p = pair.second;

            if (p.diabetes) { //se a pessoa tem diabetes
                
                bool pai_diabetes = false;
                bool mae_diabetes = false;

                if (familia.count(p.pai_id) > 0) { //se o pai existe checa se ele tem diabetes
                    pai_diabetes = familia.at(p.pai_id).diabetes;
                }

                if (familia.count(p.mae_id) > 0) { //se a mae existe checa se ele tem diabetes
                    mae_diabetes = familia.at(p.mae_id).diabetes;
                }

                //checa se a diabetes eh hereditaria
                if (pai_diabetes || mae_diabetes) {
                    count++;
                }
            }    

        }
        cout << count << endl;
    }

}
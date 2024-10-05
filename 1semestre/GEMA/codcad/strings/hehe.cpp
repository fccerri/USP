    #include <bits/stdc++.h>
    using namespace std;

    int main () {
        string s, vogais;
        int verificador=0;
        cin >> s;

        for (int i=0;i<s.size(); i++) {
            if (s[i]=='a') {
                vogais.push_back('a');
            }
            else if (s[i]=='e') {
                vogais.push_back('e');
            }
            else if (s[i]=='i') {
                vogais.push_back('i');
            }
            else if (s[i]=='o') {
                vogais.push_back('o');
            }
            else if (s[i]=='u') {
                vogais.push_back('u');
            }
        }

        for (int x=0;x<vogais.size();x++) {
            if (vogais[x]==vogais[vogais.size()-x-1]){
                verificador++;
            
                
            }

        }
       
    
        if (verificador==vogais.size()){
            cout << "S";

        }
        else {
            cout << "N";
        }
        return 0;
    }
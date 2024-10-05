#include <bits/stdc++.h>
using namespace std;
        

int main (void) {
    long long int total, n;
    vector<int> v1;
    vector<int> v2;
    set<int> s1;
    cin >> n; 

    total = (n+n*n)/2;

    if (total%2==1) {
        cout << "NO\n";
        return 0; 
    }

    while (n!=0){
        v1.push_back(n--);
        if (n==0) break;
        v2.push_back(n--);
        if (n==0) break;
        v2.push_back(n--);
        if (n==0) break;
        v1.push_back(n--);
        if (n==0) break;
        
    }

    

    cout << "YES\n";

    cout << v1.size() <<"\n"; //set"1"
    
    for (int i=v1.size()-1; i>=0; i--) { 
        cout << v1[i] << " ";
    }


    cout << "\n" << v2.size() << "\n"; //set"2" - arrumar essa merda

    for (int i=v2.size()-1; i>=0; i--) { 
            cout << v2[i] << " ";
        }



    return 0;
}

// while (total%i==0) { 
//         menorDiv2 = total/i; //acha o menor numero da soma dividida por 2^n
//         if (i!=2){
//             v1.push_back(menorDiv2); //coloca no vet
//             s1.insert(menorDiv2);
//         }
            

//         i*=2;
//     }

//     v1.push_back(menorDiv2/2+1);
//     v1.push_back(menorDiv2/2); //cria os dois menores numeros do set1

//     for (int i=1; i<=n-v1.size(); i++) { //cria o set2
//         if (s1.find(i)==s1.end())
//         v2[i-1] = i;
//     }
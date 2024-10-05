#include <bits/stdc++.h> 
using namespace std;

int main () {
    int n, ent[10000], saida[10000], dist=-1;

    cin >> n;
    
    for (int i=0; i<n;i++) {
        cin >> ent[i];
    }


    for (int i=0; i<n;i++) {

        if (ent[i]==0){            
        saida[i] = 0;
        dist = 0;}

        else if (dist!=-1){

            saida[i] = ++dist;   
        }

        else saida[i] = 9;

        if (dist>9) saida[i] = 9;}

    dist = -1;

    for (int i=n-1; i>-1;i--) {

        if (ent[i]==0){            
        dist = 0;}

        else if (saida[i]>1+dist){

            if (dist!=-1) {
                dist++;
                saida[i] = dist; 
            }
                  

           if (dist>9) {
                dist++;
                saida[i] = 9; 
            }
        }
        
    }

    for (int i=0; i<n;i++) { 
        
        if (i<n-1)
        cout << saida[i] << " ";

        else cout << saida[i];
    }


    return 0;
}


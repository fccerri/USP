    #include <bits/stdc++.h>
    using namespace std;

    int main () {
        int n, s;
        cin >> n;

        int vet[n];

        for (int v=0;v<n;v++) cin >> vet[v];
        
        if (vet[0]==1) s=1;
        else s=0;

        for (int i=1;i<n;i++) {
            if (vet[i]) s++;
            
            if (i>3) s-=vet[i-3];

            cout << s << "\n"; 
            
        
        }
        s-=vet[n-3];
        cout << s << "\n";
        

        return 0;
    }
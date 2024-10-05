    #include <bits/stdc++.h>
    using namespace std;

    int main () {
        int t,n=0;
        string s, verdade;
        cin >> t;

        while (t--) {
    
            verdade = "";

            cin >> n;
            cin >> s;

            for (int i=0;i<n;i++) {
                if (i>0) {
                    verdade.push_back('.');
                }

                verdade.push_back(s[i]);

                i++;

                verdade.push_back(s[i]);

                
                if (i+2>n) break;

                else if (!(s[i+2]=='a') and !(s[i+2]=='e')) {
                    i++;
                    verdade.push_back(s[i]);
                     
                }

            }

            cout << verdade << "\n";

        }

        return 0;
    }

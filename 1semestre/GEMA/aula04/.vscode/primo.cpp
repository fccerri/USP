#include <iostream>

using namespace std;

bool eh_primo(int x){
    for (int i=2; i<(x/2);i++) {
        if (x%i==0) return false; }
	if (x==1) return false;
    return true;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x))
		cout << "S" << "\n";
	else
		cout << "N" << "\n";
	
}
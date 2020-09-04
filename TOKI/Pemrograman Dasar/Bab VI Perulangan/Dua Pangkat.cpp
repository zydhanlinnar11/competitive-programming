#include <iostream>
using namespace std;

int main() {
	int n;
    cin>>n;
    while (n) {
        if(n & 1 && n != 1) {
            cout<<"bukan\n";
            return 0;
        }
        n >>= 1;
    }
    cout<<"ya\n";
	return 0;
}
#include <iostream>
using namespace std;

int josh(int n, int k) {
    if (n == 1) return 1;
    else return (josh(n - 1, k) + k-1) % n + 1;
}

int main() {
    int n;
    cin>>n;
    cout<<josh(n + 1, n + 1)<<'\n';
}
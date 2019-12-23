#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int t, a, b;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(b > a) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(gcd(a, b) == 1) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}
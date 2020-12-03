#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull am(int n) {
    if(n == 1)
        return 1ULL;
    return 1 + am(n / 2) + am(n / 2 + ((n & 1) ? 1 : 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<am(n)<<'\n';
    return 0;
}
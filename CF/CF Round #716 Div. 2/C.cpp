#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ll n;
    cin>>n;
    
    set<int> bilangan;

    int res = 1;
    for(int i=1; i<n; i++)
        if(gcd(n, i) == 1) {
            bilangan.insert(i);
            res = (int)(((long long)res * i) % n);
        }

    if(res != 1) bilangan.erase(res);

    cout<<bilangan.size()<<'\n';
    for(auto i = bilangan.begin(); i != bilangan.end(); i++)
        cout<<*i<<(i != bilangan.end() ? ' ' : '\n');

    return 0;
}
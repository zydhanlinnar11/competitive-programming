#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned n;
    ull d, terbeli = 0;
    cin>>n>>d;
    pair<ull, ull> daftar[n]; // list coklat dan bebek
    for(auto &i : daftar)
        cin>>i.first>>i.second;
    sort(daftar, daftar + n);
    for(auto i : daftar) {
        if(d == 0 || d < i.first)
            break;
        ull belibrp = min(i.second, d / i.first);
        terbeli += belibrp; // beli sebutuhnya/semampunya
        d -= i.first * belibrp;
    }
    cout<<terbeli<<'\n';
    return 0;
}
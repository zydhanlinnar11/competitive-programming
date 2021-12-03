#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int ada[1000001];

int main() {
    // #ifdef ZYD_WSL
    // freopen("/home/zydhanlinnar11/CP/CF/tc/input/input06.txt", "r", stdin);
    // #endif
    ll n, m;
    cin>>n>>m;
    ll res = 0;
    while(m--) {
        int tmp;
        cin>>tmp;
        ada[tmp] = true;
    }
    for(int i=1; i<=n; i++) {
        if(ada[i]) continue;
        ll lt = (1LL << (ll)(log2(i))); 
        res += i - lt;
    }
    cout<<res * 2<<"\n";
}
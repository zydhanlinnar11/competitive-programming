#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned us;
typedef pair<int, int> pii;
#define unset unordered_set
#define unmap unordered_map
#define mpair make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll a, b, c, pa, pb;
        cin>>a>>b>>c;
        if(a >= c)
            pa = -1;
        else pa = 1;
        if((a * b) <= c)
            pb = -1;
        else pb = b;
        cout<<pa<<' '<<pb<<'\n';
    }
    return 0;
}
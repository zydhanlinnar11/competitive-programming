#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned us;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define unset unordered_set
#define unmap unordered_map
#define mpair make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll x, y, n;
        cin>>x>>y>>n;
        n = (n - y) / x;
        cout<<(y + (x * n))<<'\n';
    }
    return 0;
}
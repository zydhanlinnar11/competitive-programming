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
        ll n, k, tmp, maxval = 0;
        map<ll, ll> addon;
        cin>>n>>k;
        for(ll i=0; i<n; i++) {
            cin>>tmp;
            if(tmp % k == 0)
                continue;
            ll kurang = (((tmp / k) + 1) * k) - tmp;
            auto curr = addon.find(kurang);
            if(curr == addon.end()) {
                addon.insert(mpair(kurang, 1));
                maxval = max(kurang + 1, maxval);
            } else {
                curr->second++;
                maxval = max(curr->first + ((curr->second - 1) * k) + 1, maxval);
            }
        }
        cout<<maxval<<'\n';
    }
    return 0;
}
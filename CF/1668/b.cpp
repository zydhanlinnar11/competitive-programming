#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, m;
    cin>>n>>m;

    multiset<ll, greater<ll>> want;
    for(int i=0; i<n; i++) {
        ll tmp;
        cin>>tmp;
        want.insert(tmp);
    }

    if (n > m) {
        cout<<"NO\n";
        return;
    }
    deque<pll> dq;
    dq.push_back(mp(*want.begin(), *want.begin()));
    want.erase(want.begin());
    while(!want.empty()) {
        auto currVal = *want.begin();
        want.erase(want.begin());
        ll lDiff = dq.front().first - currVal;
        ll rDiff = dq.back().second - currVal;

        if (lDiff < rDiff) {
            pll fr = dq.front();
            fr.first = max(currVal, fr.first);
            dq.pop_front();
            dq.push_front(fr);
            dq.push_front(mp(currVal, fr.first));
            continue;
        }
        pll bc = dq.back();
        bc.second = max(currVal, bc.second);
        dq.pop_back();
        dq.push_back(bc);
        dq.push_back(mp(bc.second, currVal));
    }
    pll bc = dq.back();
    bc.second = max(dq.front().first, bc.second);
    dq.pop_back();
    dq.push_back(bc);
    ll res = n;
    while(!dq.empty()) {
        res += dq.front().second;
        dq.pop_front();
    }
    cout<<(res > m ? "NO" : "YES")<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1668/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1668/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
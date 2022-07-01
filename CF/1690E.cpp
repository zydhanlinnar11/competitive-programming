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
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline ll getAns(multiset<pll> &arr, queue<pll> &sisa, ll k, ll target) {
    ll ans = 0;
    while(!arr.empty()) {
        auto l = arr.begin();
        auto r = arr.lower_bound({target - l->first, l->second + 1});
        if(r == arr.end() || (l->second + r->second) % k != 0) {
            sisa.push(*l);
            arr.erase(l);
            continue;
        }
        ans += (l->second + r->second) / k;
        arr.erase(l);
        arr.erase(r);
    }
    // if(l == r) {
    //     sisa.insert(arr[l]);
    // }
    return ans;
}

inline void prog() {
    int n, k;
    cin>>n>>k;
    ll ans = 0;
    vl arr;
    for(int i=0; i<n; i++) {
        ll tmp;
        cin>>tmp;
        ans += tmp / k;
        if(tmp % k != 0) arr.push_back(tmp % k);
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        ll sum = arr[l] + arr[r];
        if(sum < k) l++;
        else if(sum >= k) {
            ans++; l++, r--;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
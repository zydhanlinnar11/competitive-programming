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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    vector<pii> arr(n + 1);
    vector<bool> ikut(n + 1, false);
    set<pair<pii, int>> ttp, ttp2;
    for(int i=1; i<=n; i++) cin>>arr[i].first>>arr[i].second;
    for(int i=1; i<=n; i++) {
        bool masuk = ((int)ttp.size() <= arr[i].second);
        bool ganti = (int)ttp.size() == (arr[i].second + 1);
        ikut[i] = masuk | ganti;
        if(ganti || masuk)
            ttp.insert(mp(arr[i], i));
        if(ganti) {
            ikut[ttp.begin()->second] = false;
            ttp.erase(ttp.begin());
        }
    }

    for(int i=n; i>=1; i--) {
        if(ikut[i]) {
            bool masuk = ((int)ttp2.size() <= arr[i].first);
            auto now = mp(mp(arr[i].second, arr[i].first), i);
            if(masuk)
                ttp2.insert(now);
        }
    }
    cout<<ttp2.size()<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
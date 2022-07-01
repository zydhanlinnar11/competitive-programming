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

inline void prog() {
    int n; cin>>n;
    vl arr;
    multiset<ll> ms;
    bool adanol = false;
    int poscount = 0, negcount = 0;
    for(auto i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(tmp != 0 || !adanol) {
            if(tmp == 0) adanol = true;
            ms.insert(tmp);
            arr.push_back(tmp);
            poscount += (tmp > 0);
            negcount += (tmp < 0);
        }
    }
    // auto mn = min_element(arr.begin(), arr.end());
    // auto mx = max_element(arr.begin(), arr.end());
    // if(*mn == *mx && *mn == 0) {
    //     cout<<"YES\n";
    //     return;
    // }
    if(poscount >= 3 || negcount >= 3) {
        cout<<"NO\n";
        return;
    }
    // poscount < 3 && negcount < 3
    // pos + neg ada maks 4, ada 0 satu
    // if(ms.find(0) != ms.end()) {
    //     ms.erase(0);
    //     ms.insert(0);
    // }
    // arr.clear();
    // for(auto &i: ms) {
    //     arr.push_back(i);
    // }
    n = (int)arr.size();
    // if(n == 2 && ((arr[0] == 0 && arr[1] > 0) || (arr[0] < 0 && arr[1] == 0))) {
    //     cout<<"NO\n";
    //     return;
    // }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                auto sum = arr[i] + arr[j] + arr[k];
                if(ms.find(sum) == ms.end()) {
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1698/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1698/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
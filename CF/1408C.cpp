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
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, l;
    cin>>n>>l;
    vi arr(n);
    for(auto &i: arr)
        cin>>i;
    arr.insert(arr.begin(), 0);
    arr.push_back(l);
    vector<vector<long double>> times(2, vector<long double>(n+2, 0));
    int spd = 1;
    for(int i=1; i<=n+1; i++)
        times[0][i] = times[0][i-1] + (long double)(arr[i] - arr[i - 1]) / spd++;
    spd = 1;
    for(int i=n; i>=0; i--)
        times[1][i] = times[1][i+1] + (long double)(arr[i + 1] - arr[i]) / spd++;
    long double lo = 0, hi = l;
    while((hi - lo) > 1e-7) {
        auto mid = lo + (hi - lo) / 2;
        if(mid > times[0].back() || mid > times[1].front()) {
            hi = mid;
            continue;
        }
        int spd1 = 1;
        long double pos1 = 0, diff1 = 0;
        for(int i=0; i<n+1; i++) {
            if(times[0][i + 1] > mid) {
                spd1 = i + 1;
                pos1 = arr[i];
                diff1 = mid - times[0][i];
                break;
            }
        }
        int spd2 = 1;
        long double pos2 = l, diff2 = 0;
        for(int i=n+1; i>0; i--) {
            if(times[1][i - 1] > mid) {
                spd2 = n - i + 2;
                pos2 = arr[i];
                diff2 = mid - times[1][i];
                break;
            }
        }
        pos1 += spd1 * diff1;
        pos2 -= spd2 * diff2;
        if(pos1 > pos2) {
            hi = mid;
        } else if(pos1 < pos2) {
            lo = mid;
        } else {
            break;
        }
    }
    cout<<setprecision(12)<<fixed<<lo + (hi - lo) / 2<<"\n";
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
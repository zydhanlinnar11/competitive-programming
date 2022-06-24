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
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<pl> vll; 
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int m; cin>>m;
    vll arr;
    while(true) {
        ll l, r;
        cin>>l>>r;
        if(l == 0 && r == 0) break;
        arr.push_back({l, -r});
    }
    sort(arr.begin(), arr.end());
    ll covered = 0;
    vll ans;
    bool possible = true;
    for(unsigned i=0; i<arr.size(); i++) {
        auto [start, end] = arr[i];
        end = -end;
        if(covered >= m) break;
        if(end <= covered) continue;
        if(start > covered) {
            possible = false;
            break;
        }
        int longestCoverageIdx = i, j = i;
        while(j < (int)arr.size() && arr[j].first <= covered) {
            if(-arr[longestCoverageIdx].second < -arr[j].second) {
                longestCoverageIdx = j;
            }
            j++;
        }
        auto [start2, end2] = arr[longestCoverageIdx];
        end2 = -end2;
        ans.push_back({start2, end2});
        covered = end2;
    }
    if(!possible || covered < m) cout<<"0\n";
    else {
        cout<<ans.size()<<"\n";
        for(auto [l, r]: ans) 
            cout<<l<<" "<<r<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) {
        prog();
        if(t) cout<<"\n";
    }
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
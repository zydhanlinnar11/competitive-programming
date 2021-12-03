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

inline int digit(int n) {
    return log10(n) + 1;
}

inline void prog() {
    vi x(2), p(2);
    cin>>x[0]>>p[0]>>x[1]>>p[1];
    int mn = *min_element(p.begin(), p.end());
    p[0] -= mn, p[1] -= mn;
    if(p[0] > p[1]) {
        if(digit(x[0]) + p[0] > digit(x[1])) {
            cout<<">\n";
            return;
        }
    } else {
        if(digit(x[1]) + p[1] > digit(x[0])) {
            cout<<"<\n";
            return;
        }
    }
    x[0] *= (int)pow(10, p[0]);
    x[1] *= (int)pow(10, p[1]);
    if(x[0] < x[1]) cout<<"<\n";
    else if(x[0] > x[1]) cout<<">\n";
    else cout<<"=\n";
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
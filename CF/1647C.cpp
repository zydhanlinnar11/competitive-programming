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
    int n, m; cin>>n>>m;
    vs matrix(n); for(auto &row: matrix) cin>>row;
    vector<pair<pii, pii>> ans;
    if(m > 1) {
        for(int i=0; i<n; i++) {
            auto &row = matrix[i];
            if(row[0] == '0' && row[1] == '1') {
                ans.push_back({{i, 0}, {i, 1}});
                matrix[i][0] = '0';
                matrix[i][1] = '0';
            }
        }
    }
    if(n > 1) {
        for(int i=0; i<m; i++) {
            if(matrix[0][i] == '0' && matrix[1][i] == '1') {
                ans.push_back({{0, i}, {1, i}});
                matrix[0][i] = '0';
                matrix[1][i] = '0';
            }
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i - 1][j] == '0' && matrix[i][j] == '1') {
                ans.push_back({{i - 1, j}, {i, j}});
                matrix[i][j] = '0';
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][j - 1] == '0' && matrix[i][j] == '1') {
                ans.push_back({{i, j - 1}, {i, j}});
                matrix[i][j] = '0';
            }
        }
    }
    auto can = (matrix == vs(n, string(m, '0')));
    if(!can) cout<<"-1\n";
    else {
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for(auto &i: ans) {
            auto &[a, b] = i;
            cout<<a.first + 1<<" "<<a.second + 1<<" "<<b.first + 1<<" "<<b.second + 1<<"\n";
        }
    }
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
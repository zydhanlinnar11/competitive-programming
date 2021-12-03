#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
#define FORINC(i, a, n) for(int i=a; i<n; i++)
#define FORDEC(i, a, n) for(int i=n - 1; i>=a; i--)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007
time_point<system_clock> chrono_time_start, chrono_time_end;

ll modmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll modpow (ll a, ll b) {
    a %= MOD;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}

ll comb(ll n, ll k, vi &factorial) {
    ll nk = n - k;
    k = modpow(factorial[k], MOD - 2);
    nk = modpow(factorial[nk], MOD - 2);
    return modmul(modmul(factorial[n], k), nk);
}

void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}

inline int getSum(vi2d &preSum, int y, int x, int y_end, int x_end) {
    return preSum[y_end][x_end] - preSum[y_end][x - 1] - preSum[y - 1][x_end] + preSum[y - 1][x - 1];
}

inline void prog() {
    // chrono_time_start = system_clock::now();
    int n, m, ans = INT_MAX;
    cin>>n>>m;
    vi2d cnt1(n + 1, vi(m + 1, 0));
    for(int i=0; i<n; i++) {
        string tmp;
        cin>>tmp;
        for(int j=0; j<m; j++) {
            cnt1[i + 1][j + 1] = tmp[j] - '0' + cnt1[i][j + 1] + cnt1[i + 1][j] - cnt1[i][j];
        }
    }
    for(int i=1; i<=n-4; i++) {
        for(int j=1; j<=m-3; j++) {
            for(int k=i+4; k<=n; k++) {
                for(int l=j+3; l<=m; l++) {
                    int tmpAns = getSum(cnt1, i + 1, j + 1, k - 1, l - 1) + (((k - i) + (l - j) - 2) << 1)
                    - getSum(cnt1, i, j + 1, i, l - 1) - getSum(cnt1, k, j + 1, k, l - 1)
                    - getSum(cnt1, i + 1, j, k - 1, j) - getSum(cnt1, i + 1, l, k - 1, l);
                    if(tmpAns < ans) ans = tmpAns;
                }
            }
        }
    }
    cout<<ans<<'\n';
    // chrono_time_end = system_clock::now();
    // duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) prog();
    return 0;
}
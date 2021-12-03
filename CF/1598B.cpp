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
    vector<vi> arr(n, vi(5));
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            int a=0, b=0, t = 0;
            for(int k=0; k<n; k++) {
                if(arr[k][i] == arr[k][j] && arr[k][j] == 0) {
                    t=1;
                    break;
                }
                if(arr[k][i] == arr[k][j] && arr[k][j] == 0) continue;
                a += arr[k][i];
                b += arr[k][j];
            }
            if(!t && a >= n / 2 && b >= n / 2) {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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
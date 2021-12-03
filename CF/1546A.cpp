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
    int n, sumA = 0,  sumB = 0;
    cin>>n;
    vi A(n), B(n);
    for(int i=0; i<n; i++) {
        cin>>A[i];
        sumA += A[i];
    }
    for(int i=0; i<n; i++) {
        cin>>B[i];
        sumB += B[i];
    }
    if(sumA != sumB) {
        cout<<"-1\n";
        return;
    }
    vector<pii> ans;
    for(int i=0; i<n-1; i++) {
        if(A[i] < B[i]) {
            for(int j=i+1; j<n; j++) {
                int diff = abs(A[i] - B[i]);
                if(A[j] > B[j]) {
                    int tmp = min(diff, A[j] - B[j]);
                    if(tmp == 0) continue;
                    A[i] += tmp;
                    A[j] -= tmp;
                    for(int k=0; k<tmp; k++) {
                        ans.push_back(mp(j+1, i+1));
                        // cout<<j+1<<" "<<i+1<<"\n";
                    }
                }
            }
        } else if(A[i] > B[i]) {
            for(int j=i+1; j<n; j++) {
                int diff = abs(A[i] - B[i]);
                if(A[j] < B[j]) {
                    int tmp = min(diff, B[j] - A[j]);
                    if(tmp == 0) continue;
                    A[j] += tmp;
                    A[i] -= tmp;
                    for(int k=0; k<tmp; k++) {
                        ans.push_back(mp(i+1, j+1));
                        // cout<<i+1<<" "<<j+1<<"\n";
                    }
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i: ans) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
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
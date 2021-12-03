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
#define MAX_FACT 200001
#define MOD 1000000007
vector<ll> fct(MAX_FACT, 1);

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

int findmin(stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    int minimum = INT_MAX;
    if (s1.empty() || s2.empty()) 
        minimum = s1.empty() ? s2.top().second : s1.top().second;
    else minimum = min(s1.top().second, s2.top().second);
    return minimum;
}

void addElem(stack<pair<int, int>> &s1, int new_element) {
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
}

void remove(stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    if (s2.empty()) {
        while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
        }
    }
    int remove_element = s2.top().first;
    s2.pop();
}

inline void prog() {
    int n, q, d;
    cin>>n>>q;
    vi arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<q; i++) {
        stack<pair<int, int>> s1, s2;
        cin>>d;
        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
            if(j < d) {
                addElem(s1, -arr[j]);
                continue;
            }
            ans = min(ans, -findmin(s1, s2));
            remove(s1, s2);
            addElem(s1, -arr[j]);
        }
        ans = min(ans, -findmin(s1, s2));
        cout<<ans<<"\n";
    }
}

int main() {
    for(int i=1; i<MAX_FACT; i++)
        fct[i] = modmul(fct[i - 1], i);
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
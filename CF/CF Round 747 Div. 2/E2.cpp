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

inline ll modpow (ll a, ll b, ll mod = MOD) {
    a %= mod;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}

inline ll perm(ll n, ll k, vector<ll> &factorial, ll mod = MOD) {
    if(n < k)
        swap(n, k);
    ll nk = n - k;
    if(nk < 0) return 1;
    k = modpow(factorial[k], mod - 2);
    nk = modpow(factorial[nk], mod - 2);
    return modmul(factorial[n], nk);
}

inline ll comb(ll n, ll k, vector<ll> &factorial, ll mod = MOD) {
    return modmul(perm(n, k, factorial, mod), modpow(factorial[k], mod - 2));
}

inline void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}

inline void eraseFromOpt(map<int, set<char>> &availColor, map<char, char> &forbidden, char what_char, int idx) {
    if(availColor.find(idx) == availColor.end()) availColor[idx] = set<char>({'w', 'y', 'b', 'g', 'o', 'r'});
    if(availColor[idx].find(what_char) != availColor[idx].end()) availColor[idx].erase(what_char);
    if(availColor[idx].find(forbidden[what_char]) != availColor[idx].end()) availColor[idx].erase(forbidden[what_char]);
}

inline void prog() {
    int n, k;
    cin>>n;
    cin>>k;
    map<char, char> forbidden;
    ll maxnode = pow(2, n) - 1;
    forbidden['w'] = 'y';
    forbidden['y'] = 'w';
    forbidden['g'] = 'b';
    forbidden['b'] = 'g';
    forbidden['r'] = 'o';
    forbidden['o'] = 'r';
    map<int, char> color;
    for(int i=0; i<k; i++) {
        int tmp; string clr;
        cin>>tmp>>clr;
        color[tmp] = clr[0];
    }
    ll ans = 1;
    map<int, set<char>> availColor;
    set<int> precoloredNode;
    for(auto &i: color) {
        precoloredNode.insert(i.first);
        int parent = i.first / 2, l = i.first * 2, r = l + 1;
        if(parent > 0) {
            eraseFromOpt(availColor, forbidden, i.second, parent);
        }
        if(r <= maxnode) {
            eraseFromOpt(availColor, forbidden, i.second, l);
            eraseFromOpt(availColor, forbidden, i.second, r);
        }
    }
    for(auto &i: availColor) {
        // Habis dibabat atau gaada di set yang diperbolehkan
        int precolored = color.find(i.first) != color.end();
        if(i.second.size() == 0U
            || (precolored && i.second.find(color[i.first]) == i.second.end())) {
            ans *= 0;
            break;
        }
        // Precolored
        precoloredNode.insert(i.first);
        if(precolored) {
            continue;
        }
        ans = modmul(ans, i.second.size());
    }
    cout<<(k == 0 ? modmul(6, modpow(4, pow(2, n) - 2)) : modmul(ans, modpow(4, pow(2, n) - precoloredNode.size() - 1)))<<'\n';
}

int main() {
    for(int i=1; i<MAX_FACT; i++)
        fct[i] = modmul(fct[i - 1], i);
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}
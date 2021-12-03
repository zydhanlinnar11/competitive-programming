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

class SegTree {
protected:
    vector<long long> t;
private:
    int treeType;

    // v : currpos, tl, tr: tree left, tree right
    void build(vector<long long> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            if(treeType == SegTree::MAX_TYPE)
                t[v] = max(t[v*2], t[v*2+1]);
            else if(treeType == SegTree::MIN_TYPE)
                t[v] = min(t[v*2], t[v*2+1]);
            else if(treeType == SegTree::SUM_TYPE)
                t[v] = t[v*2] + t[v*2+1];
        }
    }
public:
    static const int SUM_TYPE = 0;
    static const int MIN_TYPE = 1;
    static const int MAX_TYPE = 2;

    SegTree(int n, vector<long long> &arr, int type) {
        if(type != SUM_TYPE && type != MIN_TYPE && type != MAX_TYPE)
            throw invalid_argument("Wrong treeType in input");
        treeType = type;
        if(treeType == SegTree::MAX_TYPE)
            t = vector<long long>((int)4*n, INT_MIN);
        else if(treeType == SegTree::MIN_TYPE)
            t = vector<long long>((int)4*n, INT_MAX);
        else if(treeType == SegTree::SUM_TYPE)
            t = vector<long long>((int)4*n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            if(treeType == SegTree::MAX_TYPE)
                t[v] = max(t[v*2], t[v*2+1]);
            else if(treeType == SegTree::MIN_TYPE)
                t[v] = min(t[v*2], t[v*2+1]);
            else if(treeType == SegTree::SUM_TYPE)
                t[v] = t[v*2] + t[v*2+1];
        }
    }
};

class MaxSegTree: public SegTree {
public:
    MaxSegTree(int n, vector<long long> &arr): SegTree(n, arr, SegTree::MAX_TYPE) {
    };

    int getFirst(int v, int lv, int rv, int l, int r, int x) {
        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r) {
            if(t[v] <= x) return -1;
            while(lv != rv) {
                int mid = lv + (rv-lv)/2;
                if(t[2*v] > x) {
                    v = 2*v;
                    rv = mid;
                }else {
                    v = 2*v+1;
                    lv = mid+1;
                }
            }
            return lv;
        }

        int mid = lv + (rv-lv)/2;
        int rs = getFirst(2*v, lv, mid, l, r, x);
        if(rs != -1) return rs;
        return getFirst(2*v+1, mid+1, rv, l ,r, x);
    }
};

inline void prog() {
    int n, m;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        arr[i] = -arr[i] + 1;
    }
    cin>>m;
    MaxSegTree segTree = MaxSegTree(n, arr);
    set<int> bought;
    for(int i=0; i<m; i++) {
        int tmp;
        cin>>tmp;
        auto p = segTree.getFirst(1, 0, n - 1, 0, n - 1, -tmp);
        if(p != -1) {
            segTree.update(1, 0, n - 1, p, -tmp);
            bought.insert(p);
        }
    }
    cout<<bought.size()<<"\n";
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
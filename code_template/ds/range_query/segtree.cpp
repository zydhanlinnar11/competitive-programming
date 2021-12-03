// int n, t[4*MAXN];
#include <algorithm>
#include <vector>
#include <climits>
#include <stdexcept>
using namespace std;

// OOP
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

    SegTree() {};

    SegTree(int n, vector<long long> &arr, int type) {
        if(type != SUM_TYPE && type != MIN_TYPE && type != MAX_TYPE)
            throw invalid_argument("Wrong treeType in input");
        this->treeType = type;
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
    MaxSegTree() {};

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

    long long getMax(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(
            getMax(v*2, tl, tm, l, min(r, tm)),
            getMax(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
    }
};

class MinSegTree: public SegTree {
public:
    MinSegTree() {};

    MinSegTree(int n, vector<long long> &arr): SegTree(n, arr, SegTree::MIN_TYPE) {
    };

    long long getMin(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(
            getMin(v*2, tl, tm, l, min(r, tm)),
            getMin(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
    }
};

class SumSegTree: public SegTree {
public:
    SumSegTree() {};

    SumSegTree(int n, vector<long long> &arr): SegTree(n, arr, SegTree::SUM_TYPE) {
    };

    long long getSum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return getSum(v*2, tl, tm, l, min(r, tm))
            + getSum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};

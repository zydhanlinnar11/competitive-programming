#include <bits/stdc++.h>
using namespace std;
int n, q, d;
typedef struct lll {
    int val, index;
    bool operator <(const lll &bla) const {return val < bla.val;};
}member;
member arr[100000];
int binsearch(int val) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(arr[mid].val > val)
            right = mid - 1;
        else if(arr[mid].val < val)
            left = mid + 1;
        else {
            if(mid == 0)
                return arr[0].index;
            else if(arr[mid - 1].val < val)
                return arr[mid].index;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i].val;
        arr[i].index = i;
    }
    stable_sort(arr, arr + n);
    cin>>q;
    while(q--) {
        cin>>d;
        cout<<binsearch(d)<<'\n';
    }
    return 0;
}
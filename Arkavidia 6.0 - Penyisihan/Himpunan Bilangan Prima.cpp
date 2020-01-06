#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, h[100000], k, indexx = 0, generated[320000];

void generate(ll depth, ll before) {
    if(depth >= n) {
        if(before == 1) return;
        generated[indexx] = before;
        indexx++;
    } else {
        ll i=0, val;
        while((val = (before * (pow(h[depth], i)))) <= k) {
            generate(depth + 1, val);
            i++;
        }
    }
}

ll binsearch(ll val) {
    ll left = 0, right = (indexx - 1);
    while(left <= right) {
        ll mid = left + ((right - left) >> 1);
        if(generated[mid] > val)
            right = mid - 1;
        else if(generated[mid] < val)
            left = mid + 1;
        else {
            if(mid == 0) return 0;
            if(generated[mid - 1] < val) return mid;
            else right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n;i++)
        cin>>h[i];
    cin>>k;
    generate(0, 1);
    sort(generated, generated + indexx);
    for(int i=0; i<indexx ;i++)
        cout<<generated[i]<<endl;
    cout<<(binsearch(k) + 1)<<endl;
    return 0;
}
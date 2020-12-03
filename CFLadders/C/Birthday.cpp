#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    if(n == 2) {
        int a, b;
        cin>>a>>b;
        cout<<a<<' '<<b<<'\n';
    } else {
        vector<ll> arr(n, 0);
        for(auto &i : arr)
            cin>>i;
        sort(arr.begin(), arr.end());
        ll left = arr[0], right = arr[1], mid = arr[n - 1];
        ll maxdiffleft = mid - left, maxdiffright = mid - right;
        queue<ll> lefttomid;
        stack<ll> midtoright;
        for(int i=2; i<(n - 1); i++) {
            ll diffleft = max(arr[i] - left, mid - arr[i]);
            ll diffright = max(arr[i] - right, mid - arr[i]);
            if(max(diffleft, maxdiffright) <= max(maxdiffleft, diffright)) {
                lefttomid.push(arr[i]);
                left = arr[i];
                maxdiffleft = diffleft;
            } else {
                midtoright.push(arr[i]);
                right = arr[i];
                maxdiffright = diffright;
            }
        }
        cout<<arr[0];
        while(!lefttomid.empty()) {
            cout<<' '<<lefttomid.front();
            lefttomid.pop();
        }
        cout<<' '<<mid;
        while(!midtoright.empty()) {
            cout<<' '<<midtoright.top();
            midtoright.pop();
        }
        cout<<' '<<arr[1]<<'\n';
    }
    return 0;
}
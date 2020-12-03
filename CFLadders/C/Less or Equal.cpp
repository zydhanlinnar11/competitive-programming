#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, res = 0;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for(int &i : arr)
        cin>>i;
    sort(arr.begin(), arr.end());
    if(k == 0) {
        cout<<((arr[0] > 1) ? (arr[0] - 1) : -1)<<'\n';
        exit(0);
    }
    for(int i=0; i<n; i++) {
        res++;
        if(res == k) {
            if(i == (n - 1) || arr[i] != arr[i + 1]) {
                cout<<arr[i];
            } else cout<<"-1\n";
            exit(0);
        }
    }
    return 0;
}
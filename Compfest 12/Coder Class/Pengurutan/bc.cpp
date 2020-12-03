#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    int arr[n];
    for(auto &i : arr)
        cin>>i;
    sort(arr, arr+n);
    while(q--) {
        int que;
        cin>>que;
        cout<<arr[--que]<<'\n';
    }
    return 0;
}